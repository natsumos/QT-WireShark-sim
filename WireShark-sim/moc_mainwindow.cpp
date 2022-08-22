/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_startBtn_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "updateTableWidget"
QT_MOC_LITERAL(4, 50, 7), // "timestr"
QT_MOC_LITERAL(5, 58, 6), // "srcMac"
QT_MOC_LITERAL(6, 65, 7), // "destMac"
QT_MOC_LITERAL(7, 73, 3), // "len"
QT_MOC_LITERAL(8, 77, 9), // "protoType"
QT_MOC_LITERAL(9, 87, 5), // "srcIP"
QT_MOC_LITERAL(10, 93, 5), // "dstIP"
QT_MOC_LITERAL(11, 99, 20), // "on_finishBtn_clicked"
QT_MOC_LITERAL(12, 120, 13), // "showProtoTree"
QT_MOC_LITERAL(13, 134, 3), // "row"
QT_MOC_LITERAL(14, 138, 6), // "column"
QT_MOC_LITERAL(15, 145, 8), // "slotopen"
QT_MOC_LITERAL(16, 154, 8), // "slotsave"
QT_MOC_LITERAL(17, 163, 9), // "slotCheat"
QT_MOC_LITERAL(18, 173, 19) // "on_clearBtn_clicked"

    },
    "MainWindow\0on_startBtn_clicked\0\0"
    "updateTableWidget\0timestr\0srcMac\0"
    "destMac\0len\0protoType\0srcIP\0dstIP\0"
    "on_finishBtn_clicked\0showProtoTree\0"
    "row\0column\0slotopen\0slotsave\0slotCheat\0"
    "on_clearBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    7,   55,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    2,   71,    2, 0x08 /* Private */,
      15,    0,   76,    2, 0x08 /* Private */,
      16,    0,   77,    2, 0x08 /* Private */,
      17,    0,   78,    2, 0x08 /* Private */,
      18,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_startBtn_clicked(); break;
        case 1: _t->updateTableWidget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 2: _t->on_finishBtn_clicked(); break;
        case 3: _t->showProtoTree((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slotopen(); break;
        case 5: _t->slotsave(); break;
        case 6: _t->slotCheat(); break;
        case 7: _t->on_clearBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
