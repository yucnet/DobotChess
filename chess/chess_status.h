#ifndef CHESS_STATUS_H
#define CHESS_STATUS_H

#pragma once
#include "chess/vars/sequence_types.h"
#include "chess/vars/end_of_game_types.h"
#include "chess/vars/turn_types.h"
#include "chessboard.h"
#include "client.h"
#include "piece_controller.h"

class ChessStatus: public QObject
{
    Q_OBJECT
    friend class Chess;

private:
    Chessboard* _pBoardMain;
    Clients* _pClientsList;
    PieceController* _pPieceController;

    END_TYPE _FENGameState;
    WHOSE_TURN _WhoseTurn;
    QString _QStrCastlings;
    QString _QStrEnpassant;
    QStringList _legalMoves;
    QStringList _historyMoves;
    PosFromTo _PosMove;
    SEQUENCE_TYPE _MoveType;

    WHOSE_TURN whoseTurn(QString QStrWhoseTurn);

public:
    ChessStatus(PieceController* pPieceController, Chessboard* pBoardMain,
                Clients* pClientsList);
    ~ChessStatus() {}

    void saveStatusData(QString QStrStatus);
    void resetStatusData();

    void promotePawn(PosOnBoard posOfPawnToPromote, QString QStrPromoType);
    //todo: make setters as "friend" for chess class? check for this
    void setGameStatus(QString QStrStatus) { _FENGameState = FENGameState(QStrStatus); }
    void setWhoseTurn(WHOSE_TURN Turn) { _WhoseTurn = Turn; }
    void setMove(QString QStrMove);
    void setMoveType(SEQUENCE_TYPE Type) { _MoveType = Type; }
    void setLegalMoves(QString QStrMsg);
    void setLegalMoves(QStringList moves);
    void setHistoryMoves(QString QStrMsg);
    void setHistoryMoves(QStringList moves);

    void clearMove() { _PosMove.clear(); }
    void clearLegalMoves();
    void clearHistoryMoves();

    static bool isMovePromotion(QString QStrMove, bool bErrorLog = false);
    static bool isMoveInProperFormat(QString QStrMove, bool bErrorLog = false);
    static bool isSignProperPromotionType(QString QStrSign, bool bErrorLog = false);

    SEQUENCE_TYPE findMoveType(QString QStrMove);
    bool isMoveLegal(QString QStrMove) { return _legalMoves.contains(QStrMove)? true : false; }
    bool isMoveARequestForPromotion(QString QStrMove) { return _legalMoves.contains(QStrMove + "q")? true : false; }
    bool isMoveRemoving(QString QStrMoveToTest);
    bool isMoveCastling(QString QStrMoveToTest);
    bool isMoveEnpassant(QString QStrMoveToTest);

    END_TYPE getFENGameState() const { return _FENGameState; }
    WHOSE_TURN getWhoseTurn() const { return _WhoseTurn; }
    PosFromTo getMove() const { return _PosMove; }
    SEQUENCE_TYPE getMoveType() const { return _MoveType; }
    QStringList getLegalMoves() const { return _legalMoves; }
    QStringList getHistoryMoves() const { return _historyMoves; }
    QString getHistoryMovesAsQStr() const { return _historyMoves.join(" "); }
    QString getCastlings() const { return _QStrCastlings; }
    QString getEnpassant() const { return _QStrEnpassant; }
    PLAYER_TYPE getActivePlayerType();

signals:
    void setBoardDataLabel(QString, BOARD_DATA_LABEL);
    void showLegalMoves(QStringList);
    void showHistoryMoves(QStringList);
};

#endif // CHESS_STATUS_H
