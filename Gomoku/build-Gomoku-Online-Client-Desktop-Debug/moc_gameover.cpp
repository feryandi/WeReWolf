/****************************************************************************
** Meta object code from reading C++ file 'gameover.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/gameover.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameover.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gameover_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameover_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameover_t qt_meta_stringdata_gameover = {
    {
QT_MOC_LITERAL(0, 0, 8), // "gameover"
QT_MOC_LITERAL(1, 9, 17), // "on_deletegameover"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "on_closegame"
QT_MOC_LITERAL(4, 41, 19), // "on_buttonOK_clicked"
QT_MOC_LITERAL(5, 61, 7), // "do_show"
QT_MOC_LITERAL(6, 69, 4), // "data"
QT_MOC_LITERAL(7, 74, 9) // "do_delete"

    },
    "gameover\0on_deletegameover\0\0on_closegame\0"
    "on_buttonOK_clicked\0do_show\0data\0"
    "do_delete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameover[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    6,
    QMetaType::Void,

       0        // eod
};

void gameover::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameover *_t = static_cast<gameover *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_deletegameover(); break;
        case 1: _t->on_closegame(); break;
        case 2: _t->on_buttonOK_clicked(); break;
        case 3: _t->do_show((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->do_delete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gameover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameover::on_deletegameover)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (gameover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameover::on_closegame)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject gameover::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_gameover.data,
      qt_meta_data_gameover,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gameover::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameover::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gameover.stringdata0))
        return static_cast<void*>(const_cast< gameover*>(this));
    return QDialog::qt_metacast(_clname);
}

int gameover::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void gameover::on_deletegameover()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void gameover::on_closegame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
