/****************************************************************************
** Meta object code from reading C++ file 'webchess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../webchess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webchess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebChess_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebChess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebChess_t qt_meta_stringdata_WebChess = {
    {
QT_MOC_LITERAL(0, 0, 8), // "WebChess"
QT_MOC_LITERAL(1, 9, 16), // "addTextToConsole"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "LOG"
QT_MOC_LITERAL(4, 31, 19), // "checkMsgFromChenard"
QT_MOC_LITERAL(5, 51, 10), // "tcpMsgType"
QT_MOC_LITERAL(6, 62, 10), // "tcpRespond"
QT_MOC_LITERAL(7, 73, 18), // "checkMsgForChenard"
QT_MOC_LITERAL(8, 92, 9) // "msgFromWs"

    },
    "WebChess\0addTextToConsole\0\0LOG\0"
    "checkMsgFromChenard\0tcpMsgType\0"
    "tcpRespond\0checkMsgForChenard\0msgFromWs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebChess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   34,    2, 0x0a /* Public */,
       7,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void WebChess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebChess *_t = static_cast<WebChess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addTextToConsole((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< LOG(*)>(_a[2]))); break;
        case 1: _t->checkMsgFromChenard((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->checkMsgForChenard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebChess::*_t)(QString , LOG );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebChess::addTextToConsole)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WebChess::staticMetaObject = {
    { &Chess::staticMetaObject, qt_meta_stringdata_WebChess.data,
      qt_meta_data_WebChess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebChess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebChess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebChess.stringdata0))
        return static_cast<void*>(const_cast< WebChess*>(this));
    return Chess::qt_metacast(_clname);
}

int WebChess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Chess::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WebChess::addTextToConsole(QString _t1, LOG _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
