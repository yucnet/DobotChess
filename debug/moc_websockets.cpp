/****************************************************************************
** Meta object code from reading C++ file 'websockets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../websockets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websockets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Websockets_t {
    QByteArrayData data[18];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Websockets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Websockets_t qt_meta_stringdata_Websockets = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Websockets"
QT_MOC_LITERAL(1, 11, 16), // "addTextToConsole"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "LOG"
QT_MOC_LITERAL(4, 33, 24), // "MsgFromWebsocketsToChess"
QT_MOC_LITERAL(5, 58, 21), // "QStrMsgFromWebsockets"
QT_MOC_LITERAL(6, 80, 18), // "setBoardDataLabels"
QT_MOC_LITERAL(7, 99, 17), // "BOARD_DATA_LABELS"
QT_MOC_LITERAL(8, 117, 18), // "socketDisconnected"
QT_MOC_LITERAL(9, 136, 11), // "receivedMsg"
QT_MOC_LITERAL(10, 148, 19), // "QS_WbstMsgToProcess"
QT_MOC_LITERAL(11, 168, 15), // "onNewConnection"
QT_MOC_LITERAL(12, 184, 29), // "msgFromChessboardToWebsockets"
QT_MOC_LITERAL(13, 214, 9), // "QStrWsMsg"
QT_MOC_LITERAL(14, 224, 18), // "sendTableDataToWeb"
QT_MOC_LITERAL(15, 243, 11), // "QWebSocket*"
QT_MOC_LITERAL(16, 255, 7), // "pClient"
QT_MOC_LITERAL(17, 263, 13) // "bCheckPlayers"

    },
    "Websockets\0addTextToConsole\0\0LOG\0"
    "MsgFromWebsocketsToChess\0QStrMsgFromWebsockets\0"
    "setBoardDataLabels\0BOARD_DATA_LABELS\0"
    "socketDisconnected\0receivedMsg\0"
    "QS_WbstMsgToProcess\0onNewConnection\0"
    "msgFromChessboardToWebsockets\0QStrWsMsg\0"
    "sendTableDataToWeb\0QWebSocket*\0pClient\0"
    "bCheckPlayers"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Websockets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       4,    1,   64,    2, 0x06 /* Public */,
       6,    2,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   72,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      14,    2,   80,    2, 0x0a /* Public */,
      14,    1,   85,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Bool,   16,   17,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void Websockets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Websockets *_t = static_cast<Websockets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addTextToConsole((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< LOG(*)>(_a[2]))); break;
        case 1: _t->MsgFromWebsocketsToChess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setBoardDataLabels((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< BOARD_DATA_LABELS(*)>(_a[2]))); break;
        case 3: _t->socketDisconnected(); break;
        case 4: _t->receivedMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onNewConnection(); break;
        case 6: _t->msgFromChessboardToWebsockets((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendTableDataToWeb((*reinterpret_cast< QWebSocket*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->sendTableDataToWeb((*reinterpret_cast< QWebSocket*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWebSocket* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWebSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Websockets::*_t)(QString , LOG );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Websockets::addTextToConsole)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Websockets::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Websockets::MsgFromWebsocketsToChess)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Websockets::*_t)(QString , BOARD_DATA_LABELS );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Websockets::setBoardDataLabels)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Websockets::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Websockets.data,
      qt_meta_data_Websockets,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Websockets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Websockets::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Websockets.stringdata0))
        return static_cast<void*>(const_cast< Websockets*>(this));
    return QObject::qt_metacast(_clname);
}

int Websockets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Websockets::addTextToConsole(QString _t1, LOG _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Websockets::MsgFromWebsocketsToChess(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Websockets::setBoardDataLabels(QString _t1, BOARD_DATA_LABELS _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
