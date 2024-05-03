/****************************************************************************
** Meta object code from reading C++ file 'workers.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../workers.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWorkersENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWorkersENDCLASS = QtMocHelpers::stringData(
    "Workers",
    "dance",
    "",
    "move",
    "danceUtil"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWorkersENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[8];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWorkersENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWorkersENDCLASS_t qt_meta_stringdata_CLASSWorkersENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Workers"
        QT_MOC_LITERAL(8, 5),  // "dance"
        QT_MOC_LITERAL(14, 0),  // ""
        QT_MOC_LITERAL(15, 4),  // "move"
        QT_MOC_LITERAL(20, 9)   // "danceUtil"
    },
    "Workers",
    "dance",
    "",
    "move",
    "danceUtil"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWorkersENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Workers::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSWorkersENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWorkersENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWorkersENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Workers, std::true_type>,
        // method 'dance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'danceUtil'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Workers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Workers *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dance(); break;
        case 1: _t->move(); break;
        case 2: _t->danceUtil(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Workers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Workers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWorkersENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Workers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
