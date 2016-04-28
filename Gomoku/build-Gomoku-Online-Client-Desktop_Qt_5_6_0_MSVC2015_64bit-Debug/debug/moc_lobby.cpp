/****************************************************************************
** Meta object code from reading C++ file 'lobby.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/lobby.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lobby.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_lobby_t {
    QByteArrayData data[12];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lobby_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lobby_t qt_meta_stringdata_lobby = {
    {
QT_MOC_LITERAL(0, 0, 5), // "lobby"
QT_MOC_LITERAL(1, 6, 13), // "populate_room"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "data"
QT_MOC_LITERAL(4, 26, 7), // "do_show"
QT_MOC_LITERAL(5, 34, 7), // "do_hide"
QT_MOC_LITERAL(6, 42, 7), // "on_join"
QT_MOC_LITERAL(7, 50, 3), // "rid"
QT_MOC_LITERAL(8, 54, 27), // "on_buttonCreateRoom_clicked"
QT_MOC_LITERAL(9, 82, 25), // "on_buttonJoinRoom_clicked"
QT_MOC_LITERAL(10, 108, 28), // "on_buttonRefreshRoom_clicked"
QT_MOC_LITERAL(11, 137, 25) // "on_buttonSpectate_clicked"

    },
    "lobby\0populate_room\0\0data\0do_show\0"
    "do_hide\0on_join\0rid\0on_buttonCreateRoom_clicked\0"
    "on_buttonJoinRoom_clicked\0"
    "on_buttonRefreshRoom_clicked\0"
    "on_buttonSpectate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lobby[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lobby::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lobby *_t = static_cast<lobby *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->populate_room((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 1: _t->do_show(); break;
        case 2: _t->do_hide(); break;
        case 3: _t->on_join((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_buttonCreateRoom_clicked(); break;
        case 5: _t->on_buttonJoinRoom_clicked(); break;
        case 6: _t->on_buttonRefreshRoom_clicked(); break;
        case 7: _t->on_buttonSpectate_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject lobby::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_lobby.data,
      qt_meta_data_lobby,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lobby::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lobby::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lobby.stringdata0))
        return static_cast<void*>(const_cast< lobby*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int lobby::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
