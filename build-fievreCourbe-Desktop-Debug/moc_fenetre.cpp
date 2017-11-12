/****************************************************************************
** Meta object code from reading C++ file 'fenetre.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fievreCourbe/fenetre.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Fenetre[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   19,    8,    8, 0x0a,
      49,   47,    8,    8, 0x0a,
      69,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Fenetre[] = {
    "Fenetre\0\0sizeMax()\0largeur\0"
    "changerLargeur(int)\0h\0changerHauteur(int)\0"
    "openBox()\0"
};

void Fenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Fenetre *_t = static_cast<Fenetre *>(_o);
        switch (_id) {
        case 0: _t->sizeMax(); break;
        case 1: _t->changerLargeur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changerHauteur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->openBox(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Fenetre::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Fenetre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Fenetre,
      qt_meta_data_Fenetre, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Fenetre::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Fenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Fenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Fenetre))
        return static_cast<void*>(const_cast< Fenetre*>(this));
    return QWidget::qt_metacast(_clname);
}

int Fenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Fenetre::sizeMax()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
