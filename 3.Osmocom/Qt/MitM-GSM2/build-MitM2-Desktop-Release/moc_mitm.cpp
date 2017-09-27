/****************************************************************************
** Meta object code from reading C++ file 'mitm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MitM2/mitm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mitm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MitM_t {
    QByteArrayData data[15];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MitM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MitM_t qt_meta_stringdata_MitM = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MitM"
QT_MOC_LITERAL(1, 5, 10), // "checkInput"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 18), // "transceiverPressed"
QT_MOC_LITERAL(4, 36, 10), // "btsPressed"
QT_MOC_LITERAL(5, 47, 10), // "bscPressed"
QT_MOC_LITERAL(6, 58, 16), // "wiresharkPressed"
QT_MOC_LITERAL(7, 75, 19), // "sipConnectorPressed"
QT_MOC_LITERAL(8, 95, 17), // "sqlBrowserPressed"
QT_MOC_LITERAL(9, 113, 18), // "pcapSipDumpPressed"
QT_MOC_LITERAL(10, 132, 12), // "slot1Pressed"
QT_MOC_LITERAL(11, 145, 12), // "slot2Pressed"
QT_MOC_LITERAL(12, 158, 12), // "slot3Pressed"
QT_MOC_LITERAL(13, 171, 12), // "slot4Pressed"
QT_MOC_LITERAL(14, 184, 12) // "slot5Pressed"

    },
    "MitM\0checkInput\0\0transceiverPressed\0"
    "btsPressed\0bscPressed\0wiresharkPressed\0"
    "sipConnectorPressed\0sqlBrowserPressed\0"
    "pcapSipDumpPressed\0slot1Pressed\0"
    "slot2Pressed\0slot3Pressed\0slot4Pressed\0"
    "slot5Pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MitM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MitM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MitM *_t = static_cast<MitM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkInput(); break;
        case 1: _t->transceiverPressed(); break;
        case 2: _t->btsPressed(); break;
        case 3: _t->bscPressed(); break;
        case 4: _t->wiresharkPressed(); break;
        case 5: _t->sipConnectorPressed(); break;
        case 6: _t->sqlBrowserPressed(); break;
        case 7: _t->pcapSipDumpPressed(); break;
        case 8: _t->slot1Pressed(); break;
        case 9: _t->slot2Pressed(); break;
        case 10: _t->slot3Pressed(); break;
        case 11: _t->slot4Pressed(); break;
        case 12: _t->slot5Pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MitM::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MitM.data,
      qt_meta_data_MitM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MitM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MitM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MitM.stringdata0))
        return static_cast<void*>(const_cast< MitM*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MitM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
