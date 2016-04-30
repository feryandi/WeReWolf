/****************************************************************************
** Meta object code from reading C++ file 'handler_server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WeReWolf-Client/handler_server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handler_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_handler_server_t {
    QByteArrayData data[13];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_handler_server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_handler_server_t qt_meta_stringdata_handler_server = {
    {
QT_MOC_LITERAL(0, 0, 14), // "handler_server"
QT_MOC_LITERAL(1, 15, 16), // "on_fail_or_error"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "on_login"
QT_MOC_LITERAL(4, 42, 8), // "on_ready"
QT_MOC_LITERAL(5, 51, 14), // "on_get_clients"
QT_MOC_LITERAL(6, 66, 8), // "on_start"
QT_MOC_LITERAL(7, 75, 15), // "on_change_phase"
QT_MOC_LITERAL(8, 91, 15), // "statusConnected"
QT_MOC_LITERAL(9, 107, 18), // "statusDisconnected"
QT_MOC_LITERAL(10, 126, 15), // "sendMessageJSON"
QT_MOC_LITERAL(11, 142, 7), // "message"
QT_MOC_LITERAL(12, 150, 11) // "readMessage"

    },
    "handler_server\0on_fail_or_error\0\0"
    "on_login\0on_ready\0on_get_clients\0"
    "on_start\0on_change_phase\0statusConnected\0"
    "statusDisconnected\0sendMessageJSON\0"
    "message\0readMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_handler_server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,
       4,    0,   68,    2, 0x06 /* Public */,
       5,    0,   69,    2, 0x06 /* Public */,
       6,    0,   70,    2, 0x06 /* Public */,
       7,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   74,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void,

       0        // eod
};

void handler_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        handler_server *_t = static_cast<handler_server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_fail_or_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_login(); break;
        case 2: _t->on_ready(); break;
        case 3: _t->on_get_clients(); break;
        case 4: _t->on_start(); break;
        case 5: _t->on_change_phase((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 6: _t->statusConnected(); break;
        case 7: _t->statusDisconnected(); break;
        case 8: _t->sendMessageJSON((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 9: _t->readMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (handler_server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handler_server::on_fail_or_error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (handler_server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handler_server::on_login)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (handler_server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handler_server::on_ready)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (handler_server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handler_server::on_get_clients)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (handler_server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handler_server::on_start)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (handler_server::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handler_server::on_change_phase)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject handler_server::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_handler_server.data,
      qt_meta_data_handler_server,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *handler_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *handler_server::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_handler_server.stringdata0))
        return static_cast<void*>(const_cast< handler_server*>(this));
    return QObject::qt_metacast(_clname);
}

int handler_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void handler_server::on_fail_or_error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void handler_server::on_login()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void handler_server::on_ready()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void handler_server::on_get_clients()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void handler_server::on_start()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void handler_server::on_change_phase(QJsonObject _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
