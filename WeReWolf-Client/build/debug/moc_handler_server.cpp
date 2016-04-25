/****************************************************************************
** Meta object code from reading C++ file 'handler_server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../handler_server.h"
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
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_handler_server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_handler_server_t qt_meta_stringdata_handler_server = {
    {
QT_MOC_LITERAL(0, 0, 14), // "handler_server"
QT_MOC_LITERAL(1, 15, 15), // "statusConnected"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "statusDisconnected"
QT_MOC_LITERAL(4, 51, 11), // "readMessage"
QT_MOC_LITERAL(5, 63, 15), // "sendMessageJSON"
QT_MOC_LITERAL(6, 79, 7) // "message"

    },
    "handler_server\0statusConnected\0\0"
    "statusDisconnected\0readMessage\0"
    "sendMessageJSON\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_handler_server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    6,

       0        // eod
};

void handler_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        handler_server *_t = static_cast<handler_server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusConnected(); break;
        case 1: _t->statusDisconnected(); break;
        case 2: _t->readMessage(); break;
        case 3: _t->sendMessageJSON((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
