/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGameENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGameENDCLASS = QtMocHelpers::stringData(
    "Game",
    "handleStartButton",
    "",
    "handleSoundSettingsButton",
    "handlePauseButton",
    "handleQuitButton",
    "handleHelpButton",
    "formTroops",
    "moveTroops",
    "updateTimer",
    "showShopWindow",
    "showPauseMenu",
    "spawnBoosters"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[5];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[18];
    char stringdata5[17];
    char stringdata6[17];
    char stringdata7[11];
    char stringdata8[11];
    char stringdata9[12];
    char stringdata10[15];
    char stringdata11[14];
    char stringdata12[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameENDCLASS_t qt_meta_stringdata_CLASSGameENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "Game"
        QT_MOC_LITERAL(5, 17),  // "handleStartButton"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 25),  // "handleSoundSettingsButton"
        QT_MOC_LITERAL(50, 17),  // "handlePauseButton"
        QT_MOC_LITERAL(68, 16),  // "handleQuitButton"
        QT_MOC_LITERAL(85, 16),  // "handleHelpButton"
        QT_MOC_LITERAL(102, 10),  // "formTroops"
        QT_MOC_LITERAL(113, 10),  // "moveTroops"
        QT_MOC_LITERAL(124, 11),  // "updateTimer"
        QT_MOC_LITERAL(136, 14),  // "showShopWindow"
        QT_MOC_LITERAL(151, 13),  // "showPauseMenu"
        QT_MOC_LITERAL(165, 13)   // "spawnBoosters"
    },
    "Game",
    "handleStartButton",
    "",
    "handleSoundSettingsButton",
    "handlePauseButton",
    "handleQuitButton",
    "handleHelpButton",
    "formTroops",
    "moveTroops",
    "updateTimer",
    "showShopWindow",
    "showPauseMenu",
    "spawnBoosters"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGameENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject Game::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Game, std::true_type>,
        // method 'handleStartButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSoundSettingsButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePauseButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleQuitButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleHelpButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'formTroops'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveTroops'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showShopWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showPauseMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'spawnBoosters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleStartButton(); break;
        case 1: _t->handleSoundSettingsButton(); break;
        case 2: _t->handlePauseButton(); break;
        case 3: _t->handleQuitButton(); break;
        case 4: _t->handleHelpButton(); break;
        case 5: _t->formTroops(); break;
        case 6: _t->moveTroops(); break;
        case 7: _t->updateTimer(); break;
        case 8: _t->showShopWindow(); break;
        case 9: _t->showPauseMenu(); break;
        case 10: _t->spawnBoosters(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
