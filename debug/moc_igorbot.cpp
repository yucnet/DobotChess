/****************************************************************************
** Meta object code from reading C++ file 'igorbot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../igorbot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'igorbot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IgorBot_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IgorBot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IgorBot_t qt_meta_stringdata_IgorBot = {
    {
QT_MOC_LITERAL(0, 0, 7), // "IgorBot"
QT_MOC_LITERAL(1, 8, 18), // "checkMsgForChenard"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "msg"
QT_MOC_LITERAL(4, 32, 19), // "checkMsgFromChenard"
QT_MOC_LITERAL(5, 52, 10), // "tcpMsgType"
QT_MOC_LITERAL(6, 63, 10), // "tcpRespond"
QT_MOC_LITERAL(7, 74, 10) // "EnemyStart"

    },
    "IgorBot\0checkMsgForChenard\0\0msg\0"
    "checkMsgFromChenard\0tcpMsgType\0"
    "tcpRespond\0EnemyStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IgorBot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    2,   32,    2, 0x0a /* Public */,
       7,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,

       0        // eod
};

void IgorBot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IgorBot *_t = static_cast<IgorBot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkMsgForChenard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->checkMsgFromChenard((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->EnemyStart(); break;
        default: ;
        }
    }
}

const QMetaObject IgorBot::staticMetaObject = {
    { &Chess::staticMetaObject, qt_meta_stringdata_IgorBot.data,
      qt_meta_data_IgorBot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IgorBot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IgorBot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IgorBot.stringdata0))
        return static_cast<void*>(const_cast< IgorBot*>(this));
    return Chess::qt_metacast(_clname);
}

int IgorBot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
