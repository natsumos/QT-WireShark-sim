/****************************************************************************
** Meta object code from reading C++ file 'arpcheatthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../arpcheatthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arpcheatthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArpCheatThread_t {
    QByteArrayData data[14];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArpCheatThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArpCheatThread_t qt_meta_stringdata_ArpCheatThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ArpCheatThread"
QT_MOC_LITERAL(1, 15, 10), // "sendLogMsg"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "msg"
QT_MOC_LITERAL(4, 31, 12), // "getCheatInfo"
QT_MOC_LITERAL(5, 44, 7), // "pcap_t*"
QT_MOC_LITERAL(6, 52, 8), // "adhandle"
QT_MOC_LITERAL(7, 61, 7), // "u_char*"
QT_MOC_LITERAL(8, 69, 7), // "selfmac"
QT_MOC_LITERAL(9, 77, 6), // "u_long"
QT_MOC_LITERAL(10, 84, 6), // "destip"
QT_MOC_LITERAL(11, 91, 7), // "destmac"
QT_MOC_LITERAL(12, 99, 6), // "gateip"
QT_MOC_LITERAL(13, 106, 7) // "gatemac"

    },
    "ArpCheatThread\0sendLogMsg\0\0msg\0"
    "getCheatInfo\0pcap_t*\0adhandle\0u_char*\0"
    "selfmac\0u_long\0destip\0destmac\0gateip\0"
    "gatemac"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArpCheatThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    6,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9, 0x80000000 | 7, 0x80000000 | 9, 0x80000000 | 7,    6,    8,   10,   11,   12,   13,

       0        // eod
};

void ArpCheatThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArpCheatThread *_t = static_cast<ArpCheatThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getCheatInfo((*reinterpret_cast< pcap_t*(*)>(_a[1])),(*reinterpret_cast< u_char*(*)>(_a[2])),(*reinterpret_cast< u_long(*)>(_a[3])),(*reinterpret_cast< u_char*(*)>(_a[4])),(*reinterpret_cast< u_long(*)>(_a[5])),(*reinterpret_cast< u_char*(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ArpCheatThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArpCheatThread::sendLogMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ArpCheatThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ArpCheatThread.data,
      qt_meta_data_ArpCheatThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ArpCheatThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArpCheatThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArpCheatThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ArpCheatThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ArpCheatThread::sendLogMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
