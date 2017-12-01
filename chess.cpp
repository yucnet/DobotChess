#include "chess.h"


Chess::Chess() {} //czysto wirtualne klasy muszą mieć pusty konstruktor

Chess::Chess(Dobot *pDobot, Chessboard *pChessboard, Chessboard2 *pChessboardMain, Chessboard2 *pChessboardRemoved, TCPMsgs *pTCPMsgs)
{
    _pTCPMsgs = pTCPMsgs;
    _pDobot = pDobot;
    _pChessboard = pChessboard;
    _pChessboardMain = pChessboardMain;
    _pChessboardRemoved = pChessboardRemoved;

    _pTimers = new ChessTimers;
    _pMovements = new ChessMovements;

    for (int i=1; i>=32; ++i)
        *_pPiece[i] = new Piece(i);
}

void Chess::promoteToWhat(QString moveForFuturePromote)
{
    //todo: ogarnac gdzies czyszczenie tej zmiennej po wszystkim i sprawdzanie czy nie probuje...
    //...uzywac gdzies tej zmiennej pustej
    _pChessboard->QStrFuturePromote = moveForFuturePromote;

    _pChessboard->switchPlayersTimers();
    this->SendDataToPlayer("moveOk " + moveForFuturePromote + " " +
                           _pChessboard->getStrWhoseTurn() + " promote");
}

void Chess::GameStarted()
{
    qDebug() << "Sending 'newOk' to player";
    this->addTextToConsole("newGame\n", LOG_CORE);

    _pChessboard->resetGameTimers();
    _pChessboard->startGameTimer();

    this->SendDataToPlayer("newOk");
}

void Chess::BadMove(QString msg)
{
    this->SendDataToPlayer("badMove " + msg + " " + _pChessboard->getStrWhoseTurn());
}

void Chess::EndOfGame(QString msg)
{
    END_TYPE ETWhoWon;
    if (msg.left(3) == "1-0") ETWhoWon = ET_WHIE_WON;
    else if (msg.left(3) == "0-1") ETWhoWon = ET_BLACK_WON;
    else if (msg.left(7) == "1/2-1/2") ETWhoWon = ET_DRAW;
    else
    {
        qDebug() << "ERROR: Chess::EndOfGame: unknown arg val =" << msg;
        return;
    }

    //todo: ta funkcja bedzie gdzie indziej, dostepna rowniez dla arduino
    _pWebsockets->endOfGame(ETWhoWon); //todo: odpalam endOfGame() w endOfGame(). robi to syf

    //todo: troche dziwnie to tu jest że pobieram z obiektu websocket dane by mu je zaraz przesłać
    this->SendDataToPlayer("moveOk " + _pChessboard->getPiecieFromTo() + " nt " + endTypeAsQstr(ETWhoWon)
                           + " " + _pWebsockets->getTableDataAsJSON()); //todo: json przeniesc
    //todo: wysyłam wiadomość na websockety trochę nie z poziomu websocketów (czy większość informacji...
    //...leci od websocketów? sprawdzić, jeżeli tak to zobaczyć czy da się wysyłanie każdego rodzaju inforacji...
    //...upchać w websocketach dla porządku i czy jest taka potrzeba
    //todo: wygląda na to że funkcja resetu załącza się jeszcze zanim odpowiedź poleci na stronę,
    //przez co trzeba czekać aż resetowanie się zakończy zanim gracze się dowiedzą że nastąpił koniec gry
    this->reset();
}

//todo: po reorganizacji klas niech ta funkcja przyjmuje struktury. najlepiej bylobyh ja podzielic na 2
void Chess::listMovesForDobot(SEQUENCE_TYPE Type, LETTER pieceFromLetter, DIGIT pieceFromDigit,
                              LETTER pieceToLetter, DIGIT pieceToDigit)
{
    //jeżeli nie podano skąd i/lub dokąd ramię ma się przemieścić, to jest to ruch ramienia z aktualnego pola szachownicy nad którym ono wisi
    if (pieceFromLetter == L_X) pieceFromLetter = _pChessboard->PieceFrom.Letter;
    if (pieceFromDigit == D_X) pieceFromDigit = _pChessboard->PieceFrom.Digit;
    if (pieceToLetter == L_X) pieceToLetter = _pChessboard->PieceTo.Letter;
    if (pieceToDigit == D_X) pieceToDigit = _pChessboard->PieceTo.Digit;

    qDebug() << "Chess::listMovesForDobot: Type =" << sequenceTypeAsQstr(Type) <<
                ", from" << pieceLetterPosAsQStr(pieceFromLetter) << pieceFromDigit + 1 <<
                "to" << pieceLetterPosAsQStr(pieceToLetter) << pieceToDigit + 1;

    if (Type == ST_REMOVING) //TODO: zapakować to jakoś w wymowną funkcję, albo dodać do innej części kodu. albo zmienic system usuwania bierek
    {
        //przy usuwaniu bierka "from" to ta która w każdym innym ruchu jest jako "to",...
        //...bez tego będzie chciał usuwać bierkę "from"
        pieceFromLetter = pieceToLetter;
        pieceFromDigit = pieceToDigit;
    }

    //todo: mozliwe ze cale przjscia typu goToSafeRemovedField beda zbedne jezeli kaze dobotowi...
    //...isc ruchami kolistymi na przegubach
    if (Type == ST_RESTORE && pieceToLetter <= L_C)
    {
        this->goToSafeRemovedField((DIGIT)pieceToDigit, Type);
    }

    //todo: przesunąć wyświetlanie wszystkich komunikatów do czasu rzeczywistego
    _pDobot->gripperState(DM_OPEN, Type);
    _pDobot->pieceFromTo(DM_FROM, pieceFromLetter, pieceFromDigit, Type);
    _pDobot->armUpDown(DM_DOWN, DM_FROM, Type);
    _pDobot->gripperState(DM_CLOSE, Type);
    _pDobot->wait(400, Type);
    _pDobot->armUpDown(DM_UP, DM_FROM, Type);
    _pChessboard->pieceStateChanged(DM_FROM, pieceFromLetter, pieceFromDigit, Type);

    if (Type == ST_RESTORE && pieceToLetter <= L_C)
    {
        this->goToSafeRemovedField((DIGIT)pieceToDigit, Type);
    }
    PositionOnBoard PieceTo; //todo: znowu mieszanie i dublowanie zmiennych
    PieceTo.Letter = pieceToLetter;
    PieceTo.Digit = pieceToDigit;
    short sPieceNrOnFieldTo = _pChessboard->getPieceOnBoardAsNr(B_MAIN, PieceTo);
    if (Type == ST_REMOVING && pieceToLetter <= L_C)
    {
        this->goToSafeRemovedField(_pChessboard->fieldNrToPositionOnBoard(sPieceNrOnFieldTo).Digit, Type);
    }

    _pDobot->pieceFromTo(DM_TO, pieceToLetter, pieceToDigit, Type);
    _pDobot->armUpDown(DM_DOWN, DM_TO, Type);
    _pDobot->gripperState(DM_OPEN, Type);
    _pDobot->wait(400, Type);
    _pDobot->armUpDown(DM_UP, DM_TO, Type);
    _pChessboard->pieceStateChanged(DM_TO, pieceToLetter, pieceToDigit, Type);

    if (Type == ST_REMOVING && pieceToLetter <= L_C)
    {
        this->goToSafeRemovedField(_pChessboard->fieldNrToPositionOnBoard(sPieceNrOnFieldTo).Digit, Type);
    } //po zbiciu ramię może zostać nad zbitymi polami
    else if (Type != ST_REMOVING) _pDobot->setRetreatIndex(_pDobot->getCoreQueuedCmdIndex());
}

void Chess::legalOk(QString msg) //todo: nazwy tych funkcji 'ok' nie mówią co robią
{
    QStringList legalMoves = msg.split(QRegExp("\\s"));
    if (!legalMoves.isEmpty()) legalMoves.removeFirst(); //remove "ok"
    if (!legalMoves.isEmpty()) legalMoves.removeFirst(); //remove np. "20"

    if (!legalMoves.isEmpty())
    {
        QString QStrLastLegalMove = legalMoves.last();
        QStrLastLegalMove = QStrLastLegalMove.simplified();
        QStrLastLegalMove = QStrLastLegalMove.replace( " ", "" ); //remove np. "\n"
        legalMoves.last() = QStrLastLegalMove;
    }
    _pChessboard->setLegalMoves(legalMoves);
}

void Chess::historyOk(QString msg)
{
    QStringList historyMoves = msg.split(QRegExp("\\s"));
    if (!historyMoves.isEmpty()) historyMoves.removeFirst(); //remove "ok"
    if (!historyMoves.isEmpty()) historyMoves.removeFirst(); //remove np. "20"

    if (!historyMoves.isEmpty()) //whipe CR, LF, spacebars etc
    {
        QString QStrLastHistoryMove = historyMoves.last();
        QStrLastHistoryMove = QStrLastHistoryMove.simplified();
        QStrLastHistoryMove = QStrLastHistoryMove.replace( " ", "" ); //remove np. "\n"
        historyMoves.last() = QStrLastHistoryMove;
    }

    _pChessboard->setHistoryMoves(historyMoves);
}

void Chess::wrongTcpAnswer(QString msgType, QString respond)
{
    qDebug() << "ERROR: IgorBot::wrongTcpAnswer(): unknown tcpRespond = " <<
                respond << "for tcpMsgType = " << msgType;
}

void Chess::resetPiecePositions()
{
    if (!this->compareArrays(_pChessboard->m_asBoardMain, _pChessboard->m_anBoardStart))
        //jeżeli bierki stoją na szachownicy nieruszone, to nie ma potrzeby ich odstawiać
    {
        bool  bArraysEqual; //warunek wyjścia z poniższej pętli do..for
        bool isChessboardInvariable; //do sprawdzania czy pętla do..for się nie zacieła

        do //wertuj w kółko planszę przestawiając bierki, dopóki...
            //...szachownica nie wróci do stanu pierwotnego/startowego.
        {
            //aktualnie sprawdzane pole szachownicy
            for (int nCheckingField = 1; nCheckingField <= 64; nCheckingField++)
            {
                int nPieceNrOnCheckingField = _pChessboard->getPieceOnBoardAsNr(B_MAIN, nCheckingField);
                int nPieceStartPosOfCheckingField = _pChessboard->getPieceOnBoardAsNr(B_START, nCheckingField);
                short sCheckingFieldsStartingPieceNr = this->findInitialFieldOfGivenPiece(nPieceNrOnCheckingField);

                bool bIsStartPieceOnRemovedFieldOfCheckingField = _pChessboard->getPieceOnBoardAsNr(B_REMOVED, nPieceStartPosOfCheckingField);

                if (nPieceNrOnCheckingField == 0 //jeżeli na sprawdzanym polu nie ma żadnej bierki...
                        && (_pChessboard->fieldNrToPositionOnBoard(nCheckingField).Digit <= D_2  //...a coś tam powinno być
                            || _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Digit >= D_7))

                {
                    //sprawdź najpierw po numerze bierki czy leży ona na swoim zbitym miejscu na polu zbitych bierek
                    if(bIsStartPieceOnRemovedFieldOfCheckingField) //jeżeli na polu zbitych jest bierka, która startowo stoi na aktualnie sprawdzanym polu
                    {
                        short sStartPieceOnRemovedFieldOfCheckingField = _pChessboard->getPieceOnBoardAsNr(B_REMOVED, nPieceStartPosOfCheckingField);
                        this->listMovesForDobot(ST_RESTORE, //przenieś bierkę z pól zbitych bierek na oryginalne pole bierki na szachownicy
                                                _pChessboard->fieldNrToPositionOnBoard(sStartPieceOnRemovedFieldOfCheckingField).Letter,
                                                _pChessboard->fieldNrToPositionOnBoard(sStartPieceOnRemovedFieldOfCheckingField).Digit,
                                                _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Letter,
                                                _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Digit);
                    }
                    else //jeżeli nie ma bierki na polu zbitych bierek, to leży ona gdzieś na szachownicy to ...
                    {
                        for (int nField = 1; nField <= 64; nField++) //...przewertuj szachownicę w jej poszukiwaniu
                        {
                            if (nPieceStartPosOfCheckingField == _pChessboard->getPieceOnBoardAsNr(B_MAIN, nField)
                                    && nCheckingField != nField)
                                //jeżeli na tym wertowanym poluszachownicy jest bierka której szukamy ale nie może to być
                                // oryginalna pozycja bierki (musi być na obcym polu startowym)
                            { //to przenieś ją na swoje pierwotne/startowe pole na szachownicy
                                this->listMovesForDobot(ST_REGULAR,
                                                        _pChessboard->fieldNrToPositionOnBoard(nField).Letter,
                                                        _pChessboard->fieldNrToPositionOnBoard(nField).Digit,
                                                        _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Letter,
                                                        _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Digit);
                            }
                        }
                    }
                }
                //natomiast jeżeli na sprawdzanym polu jest bierka, która nie znajdowała się tam podczas startu gry...
                //...to trzeba sprawdzić czy oryginalne pole tej bierki nie jest zajęte i tam ją odstawić
                else if (nPieceNrOnCheckingField != 0 && //jeżeli jakaś bierka na pewno tam jest
                         nPieceStartPosOfCheckingField != nPieceNrOnCheckingField) // i nie to bierka która jest tam orygnalnie
                {
                    short sPieceNrOnStartPosOfPieceOnCheckingField = _pChessboard->getPieceOnBoardAsNr(B_MAIN, sCheckingFieldsStartingPieceNr);

                    if (sPieceNrOnStartPosOfPieceOnCheckingField == 0) //czy startowe pole bierki jest puste, by tam można było ją odstawić
                    {
                        this->listMovesForDobot(ST_REGULAR,
                                                _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Letter,
                                                _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Digit,
                                                _pChessboard->fieldNrToPositionOnBoard(sCheckingFieldsStartingPieceNr).Letter,
                                                _pChessboard->fieldNrToPositionOnBoard(sCheckingFieldsStartingPieceNr).Digit);
                    }
                    else //jeżeli startowe pole bierki na polu sprawdzanym jest zajęte przez inną bierkę
                    {
                        //pole startowe bierki która jest na polu startowym bierki aktualnie sprawdzanej
                        int nStartNrOf2ndPieceOn1stPieceStartPos = _pChessboard->getPieceOnBoardAsNr(B_START, sPieceNrOnStartPosOfPieceOnCheckingField);

                        if (nStartNrOf2ndPieceOn1stPieceStartPos == nCheckingField) //jeżeli pole docelowe bierki, która znajduje...
                            //...się na polu aktualnie sprawdzanym jest zajętę przez bierkę, której pole startowe znajduje sie na polu aktualnie...
                            //...sprawdzanym (2 takie bierki, których pola startowe są zajęte przez siebie nawzajem- bardzo rzadki przypadek)
                        {
                            //to przenieś ją na chwilę na jej miejsce na obszarze bierek zbitych.
                            //todo: zrobić funkcję z 1 argumentem która wyczai łapaną bierkę i odstawi ją na swoje pole
                            this->listMovesForDobot(ST_REMOVING,
                                                    _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Letter,
                                                    _pChessboard->fieldNrToPositionOnBoard(nCheckingField).Digit,
                                                    _pChessboard->fieldNrToPositionOnBoard(nPieceNrOnCheckingField).Letter,
                                                    _pChessboard->fieldNrToPositionOnBoard(nPieceNrOnCheckingField).Digit);
                        }
                        else qDebug() << "Chess::resetPiecePositions(): nStartNrOf2ndPieceOn1stPieceStartPos:" <<
                                         nStartNrOf2ndPieceOn1stPieceStartPos << "!= nCheckingField:" << nCheckingField;
                    }
                    //everything else: jeżeli oryginalne pole bierki na polu sprawdzanym też jest zajęte, a nie...
                    //...jest to bierka, której pozycja startowa to pole aktualnie sprawdzaneto niech pętla wykona...
                    //...się jeszcze raz, a wtedy układ bierek się na pewno zmieni i będzie dało się dalej coś przestawiać.
                }
                //else: jeśli żadna opcja nie wystąpiła, tzn. że na danym polu leży prawidłowa/startowa bierka...
                //...albo bierki nie da się odstawić, to sprawdź kolejne pole
            }

            //sprawdzanie czy ustawienie bierek na szachownicy jest ostateczne, tj. takie same jak na...
            //...starcie. Jeżeli którakolwiek bierka nie znajduje się na swoim startowym polu, to stan...
            //...rozmieszczenia bierek na szachownicy nie jest ostateczny.
            bArraysEqual = this->compareArrays(_pChessboard->m_asBoardMain,
                                                       _pChessboard->m_anBoardStart);

            if (!bArraysEqual) //jeżeli plansza jest w stanie startowym, to można nie robić reszty...
                //...poleceń i wyskoczyć z pętli
            {
                //sprawdzanie czy ustawienie bierek zmieniło się od ostatniego przejścia przez pętlę...
                //...przestawiającą bierki. Jeżeli jest różnica od ostatniego razu, to zapamiętaj że...
                //...tak jest. Pozwoli to sprawdzać czy pętla do..for nie zacięła się, a co za tym...
                //...idzie- spradzane jest czy odstawianie bierek na planszę się nie zacieło.
                isChessboardInvariable = this->compareArrays(_pChessboard->m_asBoardMain,
                                                                     _pChessboard->m_asBoardTemp);

                //jeżeli aktualne przewertowane planszy w poszukiwaniu bierek do odstawienia...
                //...spowodowało przemieszczenie się jakiejś bierki, to zapamiętaj rozmieszczenie...
                //...bierek na szachownicy do sprawdzania tego warunku w kolejnym przejściu pętli.
                if (!isChessboardInvariable)
                {
                    memcpy(_pChessboard->m_asBoardTemp, _pChessboard->m_asBoardMain,
                           sizeof(_pChessboard->m_asBoardMain));
                }
                else
                {
                    qDebug() << "ERROR: Chess::resetPiecePositions() stuck- shouldn't be possible. isChessboardInvariable ="
                             << isChessboardInvariable;
                    bArraysEqual = true; //wyjdź z pętli, bo inaczej program się tutaj zatnie
                }
            }
            else qDebug() << "Chess::resetPiecePositions(): pieces are on start positions. end of loop";
        }
        //wertuj w kółko planszę przestawiając bierki, dopóki
        //...szachownica nie wróci do stanu pierwotnego/startowego.
        while (!bArraysEqual); //wykonuj pętlę dopóki warunek jest prawdziwy

        qDebug() << "End of: Chess::resetPiecePositions()";
    }
    qDebug() << "Chess::resetBoardCompleted(): imaginary start board and real board are equal";
    this->resetBoardCompleted();
}

void Chess::handleMove(QString move)
{
    qDebug() << "Chess::handleMove =" << move;
    _pChessboard->findBoardPos(move);

    _pChessboard->setMoveType(this->findMoveType(move));
    qDebug() << "move type =" << sequenceTypeAsQstr(_pChessboard->getMoveType());

    switch(_pChessboard->getMoveType())
    {
    case ST_PROMOTE_TO_WHAT:
        this->PromoteToWhat(move);
        break;
    case ST_ENPASSANT:
        this->enpassantMovingSequence();
        this->MoveTcpPiece("move " + move);
        break;
    case ST_CASTLING:
        this->castlingMovingSequence();
        this->MoveTcpPiece("move " + move);
        break;
    case ST_REMOVING:
        //todo: wygodniej byłoby podzielić ruchy na połówki zamiast zawsze próbować wykonywać 2 sekwencje
        this->listMovesForDobot(ST_REMOVING);
        this->listMovesForDobot(ST_REGULAR);
        this->MoveTcpPiece("move " + move);
        break;
    case ST_REGULAR:
        this->listMovesForDobot(ST_REGULAR); //TODO: to wygląda jakby to robił dobot wszystko, ten ruch tj.
        this->MoveTcpPiece("move " + move);
        break;
    case ST_BADMOVE:
        this->BadMove(move);
        break;
    case ST_NONE:
    default:
        qDebug() << "ERROR: Chess::handleMove: wrong MoveType :" << _pChessboard->getMoveType();
        break;
    }
}

//todo: jezeli movements beda dziedziczone, to to powinno byc wewnatrz tamtej klasy
void Chess::movePieceWithManipulator(Chessboard2* pRealBoard, PositionOnBoard FieldPos,
                                              VERTICAL_MOVE vertMove = VM_NONE)
{
    if (pRealBoard->getBoardType() != B_MAIN && pRealBoard->getBoardType() != B_REMOVED)
    {
        qDebug() << "ERROR: Chess::movePieceWithManipulator: board isnt real. board ="
                 << boardTypeAsQstr(pRealBoard->getBoardType());
        return;
    }

    //todo: zpaisz id przedmiotu w chwytaku
    //todo: zabierz/wstaw przedmiot z szachownicy + sprawdzenia
    Point3D xyz = pRealBoard->getFieldLocation3D(Field::nr(FieldPos));
    _pDobot->doMoveSequence(xyz, vertMove);
}

SEQUENCE_TYPE Chess::findMoveType(QString QStrMove)
{
    if (this->getLegalMoves().contains(QStrMove + "q")) return ST_PROMOTE_TO_WHAT; //todo: this?
    else if (this->getLegalMoves().contains(QStrMove)) //todo: this?
    {
        if (this->isMoveEnpassant(QStrMove)) return ST_ENPASSANT;
        else if (this->isMoveCastling(QStrMove)) return ST_CASTLING;
        else if (this->isMoveRemoving()) return ST_REMOVING;
        else return ST_REGULAR;
    }
    else return ST_BADMOVE;
}

bool Chess::compareArrays(short nArray1[][8], short nArray2[][8])
{
    for (short i=0; i<8; i++)
    {
        for (short j=0; j<8; j++)
        {
            if (nArray1[i][j] != nArray2[i][j])
                return false;
        }
    }
    return true;
}
