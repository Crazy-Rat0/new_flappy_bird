/****************************************************************************
** Meta object code from reading C++ file 'viewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../new_flappy_bird/viewmodel/viewmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_viewmodel_t {
    QByteArrayData data[10];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_viewmodel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_viewmodel_t qt_meta_stringdata_viewmodel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "viewmodel"
QT_MOC_LITERAL(1, 10, 11), // "gameUpdated"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "gameOver"
QT_MOC_LITERAL(4, 32, 17), // "birdIsDeadChanged"
QT_MOC_LITERAL(5, 50, 12), // "birdXChanged"
QT_MOC_LITERAL(6, 63, 12), // "birdYChanged"
QT_MOC_LITERAL(7, 76, 13), // "birdY2Changed"
QT_MOC_LITERAL(8, 90, 10), // "updateGame"
QT_MOC_LITERAL(9, 101, 5) // "onFly"

    },
    "viewmodel\0gameUpdated\0\0gameOver\0"
    "birdIsDeadChanged\0birdXChanged\0"
    "birdYChanged\0birdY2Changed\0updateGame\0"
    "onFly"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_viewmodel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void viewmodel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<viewmodel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameUpdated(); break;
        case 1: _t->gameOver(); break;
        case 2: _t->birdIsDeadChanged(); break;
        case 3: _t->birdXChanged(); break;
        case 4: _t->birdYChanged(); break;
        case 5: _t->birdY2Changed(); break;
        case 6: _t->updateGame(); break;
        case 7: _t->onFly(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (viewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&viewmodel::gameUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (viewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&viewmodel::gameOver)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (viewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&viewmodel::birdIsDeadChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (viewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&viewmodel::birdXChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (viewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&viewmodel::birdYChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (viewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&viewmodel::birdY2Changed)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject viewmodel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_viewmodel.data,
    qt_meta_data_viewmodel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *viewmodel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *viewmodel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_viewmodel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int viewmodel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void viewmodel::gameUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void viewmodel::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void viewmodel::birdIsDeadChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void viewmodel::birdXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void viewmodel::birdYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void viewmodel::birdY2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE