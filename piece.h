#ifndef PIECE_H
#define PIECE_H

#pragma once

#include "QDebug"
#include "QString"
#include "vars/players_types.h"
#include "vars/posotion_on_board.h"

enum PIECE_TYPE
{
    P_ERROR = 'e',
    P_PAWN = 'p',
    P_ROOK = 'r',
    P_KNIGHT = 'n',
    P_BISHOP = 'b',
    P_KING = 'k',
    P_QUEEN = 'q'
};

class Piece
{
private:
    short _sPieceID;
    PIECE_TYPE _PieceType;
    PLAYER_TYPE _PieceColor;
    short _sStartFieldID;

public:
    Piece(short sPieceID);
    ~Piece();

    bool operator ==(const class Piece& p) { return _sPieceID == p.getNr(); }

    static constexpr double dMaxPieceHeight = 50.f;

    static bool isInRange(short sPieceNr);
    static PLAYER_TYPE Color(char chFENSign);
    static PLAYER_TYPE Color(short sPieceNr);
    static PIECE_TYPE Type(char chFENSign);
    static PIECE_TYPE Type(short sPieceNr);
    static QString name(short sPieceNr);
    static short nr(PosOnBoard pieceLines);
    static short startFieldNr(short sPieceNr);
    static PosOnBoard startFieldPos(short sPieceNr);

    short getNr() const { return _sPieceID; }
    PIECE_TYPE getType() const { return _PieceType; }
    PLAYER_TYPE getColor() const { return _PieceColor; }
    QString getName() const { return Piece::name(_sPieceID); }
    short getStartFieldNr() const { return _sStartFieldID; }
    PosOnBoard getStartFieldPos() const { return Piece::startFieldPos(_sPieceID); }
};

#endif // PIECE_H
