/****************************************************************************
** Meta object code from reading C++ file 'arpcheatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../arpcheatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arpcheatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArpCheatDialog_t {
    QByteArrayData data[17];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArpCheatDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArpCheatDialog_t qt_meta_stringdata_ArpCheatDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ArpCheatDialog"
QT_MOC_LITERAL(1, 15, 12), // "setCheatInfo"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "pcap_t*"
QT_MOC_LITERAL(4, 37, 8), // "adhandle"
QT_MOC_LITERAL(5, 46, 7), // "u_char*"
QT_MOC_LITERAL(6, 54, 7), // "selfmac"
QT_MOC_LITERAL(7, 62, 6), // "u_long"
QT_MOC_LITERAL(8, 69, 11), // "deli_destip"
QT_MOC_LITERAL(9, 81, 12), // "deli_destmac"
QT_MOC_LITERAL(10, 94, 11), // "deli_gateip"
QT_MOC_LITERAL(11, 106, 12), // "deli_gatemac"
QT_MOC_LITERAL(12, 119, 19), // "on_startBtn_clicked"
QT_MOC_LITERAL(13, 139, 18), // "on_stopBtn_clicked"
QT_MOC_LITERAL(14, 158, 14), // "slotUpdateEdit"
QT_MOC_LITERAL(15, 173, 3), // "msg"
QT_MOC_LITERAL(16, 177, 15) // "slotUpdateEdit1"

    },
    "ArpCheatDialog\0setCheatInfo\0\0pcap_t*\0"
    "adhandle\0u_char*\0selfmac\0u_long\0"
    "deli_destip\0deli_destmac\0deli_gateip\0"
    "deli_gatemac\0on_startBtn_clicked\0"
    "on_stopBtn_clicked\0slotUpdateEdit\0msg\0"
    "slotUpdateEdit1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArpCheatDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   52,    2, 0x08 /* Private */,
      13,    0,   53,    2, 0x08 /* Private */,
      14,    1,   54,    2, 0x08 /* Private */,
      16,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 5,    4,    6,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void ArpCheatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArpCheatDialog *_t = static_cast<ArpCheatDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCheatInfo((*reinterpret_cast< pcap_t*(*)>(_a[1])),(*reinterpret_cast< u_char*(*)>(_a[2])),(*reinterpret_cast< u_long(*)>(_a[3])),(*reinterpret_cast< u_char*(*)>(_a[4])),(*reinterpret_cast< u_long(*)>(_a[5])),(*reinterpret_cast< u_char*(*)>(_a[6]))); break;
        case 1: _t->on_startBtn_clicked(); break;
        case 2: _t->on_stopBtn_clicked(); break;
        case 3: _t->slotUpdateEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotUpdateEdit1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ArpCheatDialog::*_t)(pcap_t * , u_char * , u_long , u_char * , u_long , u_char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArpCheatDialog::setCheatInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ArpCheatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ArpCheatDialog.data,
      qt_meta_data_ArpCheatDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ArpCheatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArpCheatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArpCheatDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ArpCheatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ArpCheatDialog::setCheatInfo(pcap_t * _t1, u_char * _t2, u_long _t3, u_char * _t4, u_long _t5, u_char * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
