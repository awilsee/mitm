/****************************************************************************
** Meta object code from reading C++ file 'mitm.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MitM/mitm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mitm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MitM[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      19,    5,    5,    5, 0x0a,
      40,    5,    5,    5, 0x0a,
      53,    5,    5,    5, 0x0a,
      66,    5,    5,    5, 0x0a,
      85,    5,    5,    5, 0x0a,
     107,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MitM[] = {
    "MitM\0\0checkInput()\0transceiverPressed()\0"
    "btsPressed()\0bscPressed()\0wiresharkPressed()\0"
    "sipConnectorPressed()\0sqlBrowserPressed()\0"
};

void MitM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MitM *_t = static_cast<MitM *>(_o);
        switch (_id) {
        case 0: _t->checkInput(); break;
        case 1: _t->transceiverPressed(); break;
        case 2: _t->btsPressed(); break;
        case 3: _t->bscPressed(); break;
        case 4: _t->wiresharkPressed(); break;
        case 5: _t->sipConnectorPressed(); break;
        case 6: _t->sqlBrowserPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MitM::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MitM::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MitM,
      qt_meta_data_MitM, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MitM::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MitM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MitM::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MitM))
        return static_cast<void*>(const_cast< MitM*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MitM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
