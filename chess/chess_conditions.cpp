#include "chess_conditions.h"

ChessConditions::ChessConditions(Clients* pClientsList, ChessStatus* pStatus)
{
    _pClientsList = pClientsList;
    _pStatus = pStatus;
}

bool ChessConditions::isClientRequestCanBeAccepted(QString QStrMsg, Client* pSender,
                                                   GAME_STATUS GS)
{
    clientRequest r;

    if (requestTypeFromQStr(QStrMsg, SHOW_ERRORS) == RT_NONE) return false;

    r.type = requestTypeFromQStr(QStrMsg, SHOW_ERRORS);
    r.param = this->extractParameterIfTypeIsInProperFormat(r.type, QStrMsg);

    if (!this->isRequestAppropriateToGameStatus(r.type, GS)) return false;
    if (!this->isSenderAppropriate(pSender, r.type)) return false;
    if (!this->isThereAnySpecialConditionBeenMet(pSender, r)) return false;

    return true;
}

QString ChessConditions::extractParameterIfTypeIsInProperFormat(REQUEST_TYPE Type,
                                                                QString QStrMsg)
{
    QString QStrParam;
    if (this->isRequestAParameterType(Type))
    {
        QStrParam = QStrMsg.mid(requestTypeAsQStr(Type).length() + 1);

        qDebug() << "ChessConditions::extractParameterIfTypeIsInProperFormat(): "
                    "extracted param =" << QStrParam;

        clientRequest r;
        r.type = Type;
        r.param = QStrParam;
        if (this->isRequestParameterInProperFormat(r)) return QStrParam;
        else return "";
    }
    else return "";
}

bool ChessConditions::isRequestAParameterType(REQUEST_TYPE Type, bool bErrorLog /*= false*/)
{
    switch(Type)
    {
    case RT_MOVE:
    case RT_SIT_ON:
    case RT_IM:
    case RT_PROMOTE_TO:
        return true;
    default:
        if (bErrorLog)
            qDebug() << "ERROR: ChessConditions::isRequestAParameterType(): unknown "
                        "REQUEST_TYPE:" << requestTypeAsQStr(Type);

        return false;
    }
}

bool ChessConditions::isRequestParameterInProperFormat(clientRequest request)
{
    bool bReturn = false;

    switch(request.type)
    {
    case RT_MOVE:
        if (ChessStatus::isMoveInProperFormat(request.param, SHOW_ERRORS))
            bReturn = true;
        else bReturn = false;
        break;
    case RT_SIT_ON:
        if (playerTypeFromQStr(request.param) != PT_WHITE &&
                playerTypeFromQStr(request.param) != PT_BLACK)
            bReturn = false;
        else bReturn = true;
        break;
    case RT_IM:
        if (request.param.isEmpty())
            bReturn = false;
        else bReturn = true;
        break;
    case RT_PROMOTE_TO:
        if (ChessStatus::isSignProperPromotionType(request.param))
            bReturn = true;
        else bReturn = false;
        break;
    default:
        qDebug() << "ERROR: ChessConditions::isRequestParameterInProperFormat(): unknown "
                    "request.type:" << requestTypeAsQStr(request.type);
    }

    if (!bReturn)
        qDebug() << "ERROR: ChessConditions::isRequestParameterInProperFormat(): requirements"
                    " not met (==false) in:" << requestTypeAsQStr(request.type);

    return bReturn;
}


bool ChessConditions::isRequestAppropriateToGameStatus(REQUEST_TYPE Type, GAME_STATUS Status)
{
    switch(Type)
    {
    case RT_NONE:
        qDebug() << "ERROR: ChessConditions::isRequestAppropriateToGameStatus(): Type = RT_NONE";
        return false;
    case RT_NEW_GAME: return Status == GS_TURN_NONE_WAITING_FOR_START_CONFIRMS ? true : false;
    case RT_MOVE: return whoseTurnFromGameStatus(Status) != NO_TURN ? true : false;
    case RT_GIVE_UP: return whoseTurnFromGameStatus(Status) != NO_TURN ? true : false;
    case RT_SIT_ON: return Status == GS_TURN_NONE_WAITING_FOR_PLAYERS ? true : false;
    case RT_STAND_UP: return whoseTurnFromGameStatus(Status) == NO_TURN ? true : false;
    case RT_PROMOTE_TO:
        if (Status == GS_TURN_WHITE_PROMOTE || Status == GS_TURN_BLACK_PROMOTE) return true;
        else return false;
    //todo: let clients to be queued, while game is off, but waiting for players to start game
    case RT_QUEUE_ME: return whoseTurnFromGameStatus(Status) != NO_TURN ? true : false;
    default: return true;
    }
}

bool ChessConditions::isSenderAppropriate(Client* pSender, REQUEST_TYPE Type)
{
    if (!_pClientsList->isClientInList(*pSender, SHOW_ERRORS)) return false;

    bool bLogged = _pClientsList->isClientLoggedIn(*pSender);
    bool bSittingOnChair = _pClientsList->isClientAPlayer(*pSender);
    bool bInQueue = _pClientsList->isClientInQueue(*pSender);

    bool bSuccess = false;
    switch(Type)
    {
    case RT_NONE:
        qDebug() << "ERROR: ChessConditions::isSenderAppropriate(): Type = RT_NONE";
        bSuccess = false;
        break;
    case RT_NEW_GAME:
    case RT_MOVE:
    case RT_GIVE_UP:
    case RT_STAND_UP:
    case RT_PROMOTE_TO:
        if (bSittingOnChair && !bInQueue) bSuccess = true;
        else bSuccess = false;
        break;
    case RT_SIT_ON:
    case RT_QUEUE_ME:
        if (bLogged && !bSittingOnChair && !bInQueue) bSuccess = true;
        else bSuccess = false;
        break;
    case RT_LEAVE_QUEUE:
        if (bLogged && !bSittingOnChair && bInQueue) bSuccess = true;
        else bSuccess = false;
        break;
    case RT_GET_TABLE_DATA:
    case RT_IM:
    case RT_CLIENT_LEFT:
        bSuccess = true;
        break;
    default:
        qDebug() << "ERROR: ChessConditions::isSenderAppropriate(): unknown REQUEST TYPE =" << Type;
        bSuccess = false;
    }

    if (!bSuccess)
    {
        qDebug() << "ERROR: ChessConditions::isSenderAppropriate(): Type = " << requestTypeAsQStr(Type)
                 << ". bLogged =" << bLogged << ", bSittingOnChair =" << bSittingOnChair
                 << ", bInQueue =" << bInQueue;
    }

    return bSuccess;
}

bool ChessConditions::isThereAnySpecialConditionBeenMet(Client* pSender, clientRequest request)
{
    switch(request.type)
    {
    case RT_NONE:
        qDebug() << "ERROR: ChessConditions::isThereAnySpecialConditionBeenMet(): "
                    "Type = RT_NONE";
        return false;
    case RT_MOVE:
    case RT_PROMOTE_TO:
        if ((pSender->type == PT_WHITE && _pStatus->getWhoseTurn() == WHITE_TURN) ||
                (pSender->type == PT_BLACK && _pStatus->getWhoseTurn() == BLACK_TURN))
            return true;
        else return false;
    case RT_SIT_ON:
    {
        PLAYER_TYPE PlayerChair = playerTypeFromQStr(request.param);
        if (_pClientsList->isPlayerChairEmpty(PlayerChair) &&
                !_pClientsList->isClientAPlayer(*pSender))
            return true;
        else return false;
    }
    case RT_IM: //name == empty || name = actual
        if (pSender->name.isEmpty() || _pClientsList->getClientName(*pSender) == request.param)
            return true;
        else return false;
    case RT_QUEUE_ME:
        if (_pClientsList->isGameTableOccupied())
            return true;
        else return false;
    case RT_LEAVE_QUEUE:
        if (_pClientsList->isClientInQueue(*pSender))
            return true;
        else return false;
    case RT_CLIENT_LEFT:
        if (_pClientsList->isClientInList(*pSender, SHOW_ERRORS))
            return true;
        else return false;
    default: return true;
    }
}
