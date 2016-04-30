/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WeReWolf-Client/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_game_t {
    QByteArrayData data[13];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_t qt_meta_stringdata_game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "game"
QT_MOC_LITERAL(1, 5, 8), // "do_start"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 19), // "do_wait_until_start"
QT_MOC_LITERAL(4, 35, 19), // "do_populate_players"
QT_MOC_LITERAL(5, 55, 11), // "do_set_rule"
QT_MOC_LITERAL(6, 67, 7), // "message"
QT_MOC_LITERAL(7, 75, 21), // "on_buttonVote_clicked"
QT_MOC_LITERAL(8, 97, 19), // "do_proposal_prepare"
QT_MOC_LITERAL(9, 117, 12), // "QHostAddress"
QT_MOC_LITERAL(10, 130, 9), // "sender_ip"
QT_MOC_LITERAL(11, 140, 11), // "sender_port"
QT_MOC_LITERAL(12, 152, 18) // "do_proposal_accept"

    },
    "game\0do_start\0\0do_wait_until_start\0"
    "do_populate_players\0do_set_rule\0message\0"
    "on_buttonVote_clicked\0do_proposal_prepare\0"
    "QHostAddress\0sender_ip\0sender_port\0"
    "do_proposal_accept"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    3,   56,    2, 0x08 /* Private */,
      12,    3,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject, 0x80000000 | 9, QMetaType::UShort,    6,   10,   11,
    QMetaType::Void, QMetaType::QJsonObject, 0x80000000 | 9, QMetaType::UShort,    6,   10,   11,

       0        // eod
};

void game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        game *_t = static_cast<game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->do_start(); break;
        case 1: _t->do_wait_until_start(); break;
        case 2: _t->do_populate_players(); break;
        case 3: _t->do_set_rule((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->on_buttonVote_clicked(); break;
        case 5: _t->do_proposal_prepare((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 6: _t->do_proposal_accept((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject game::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_game.data,
      qt_meta_data_game,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_game.stringdata0))
        return static_cast<void*>(const_cast< game*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
