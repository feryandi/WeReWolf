/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/game.h"
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
    QByteArrayData data[19];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_t qt_meta_stringdata_game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "game"
QT_MOC_LITERAL(1, 5, 12), // "on_closegame"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 16), // "populate_players"
QT_MOC_LITERAL(4, 36, 4), // "data"
QT_MOC_LITERAL(5, 41, 14), // "populate_board"
QT_MOC_LITERAL(6, 56, 7), // "do_show"
QT_MOC_LITERAL(7, 64, 3), // "rid"
QT_MOC_LITERAL(8, 68, 7), // "do_hide"
QT_MOC_LITERAL(9, 76, 12), // "do_startgame"
QT_MOC_LITERAL(10, 89, 13), // "do_updategame"
QT_MOC_LITERAL(11, 103, 12), // "do_highlight"
QT_MOC_LITERAL(12, 116, 17), // "on_game_destroyed"
QT_MOC_LITERAL(13, 134, 21), // "on_buttonPlay_clicked"
QT_MOC_LITERAL(14, 156, 25), // "on_tableBoard_cellClicked"
QT_MOC_LITERAL(15, 182, 3), // "row"
QT_MOC_LITERAL(16, 186, 6), // "column"
QT_MOC_LITERAL(17, 193, 7), // "do_chat"
QT_MOC_LITERAL(18, 201, 21) // "on_buttonChat_clicked"

    },
    "game\0on_closegame\0\0populate_players\0"
    "data\0populate_board\0do_show\0rid\0do_hide\0"
    "do_startgame\0do_updategame\0do_highlight\0"
    "on_game_destroyed\0on_buttonPlay_clicked\0"
    "on_tableBoard_cellClicked\0row\0column\0"
    "do_chat\0on_buttonChat_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       8,    0,   89,    2, 0x08 /* Private */,
       9,    0,   90,    2, 0x08 /* Private */,
      10,    1,   91,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    2,   99,    2, 0x08 /* Private */,
      17,    1,  104,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonArray,    4,
    QMetaType::Void, QMetaType::QJsonArray,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void,

       0        // eod
};

void game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        game *_t = static_cast<game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_closegame(); break;
        case 1: _t->populate_players((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 2: _t->populate_board((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 3: _t->do_show((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->do_hide(); break;
        case 5: _t->do_startgame(); break;
        case 6: _t->do_updategame((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 7: _t->do_highlight((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 8: _t->on_game_destroyed(); break;
        case 9: _t->on_buttonPlay_clicked(); break;
        case 10: _t->on_tableBoard_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->do_chat((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 12: _t->on_buttonChat_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (game::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&game::on_closegame)) {
                *result = 0;
                return;
            }
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void game::on_closegame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
