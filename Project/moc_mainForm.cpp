/****************************************************************************
** Meta object code from reading C++ file 'mainForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainForm_t {
    QByteArrayData data[7];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainForm_t qt_meta_stringdata_mainForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mainForm"
QT_MOC_LITERAL(1, 9, 27), // "on_actionAdd_List_triggered"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 26), // "on_actionAdd_Die_triggered"
QT_MOC_LITERAL(4, 65, 38), // "on_actionRemove_Random_Event_..."
QT_MOC_LITERAL(5, 104, 27), // "on_actionSimulate_triggered"
QT_MOC_LITERAL(6, 132, 30) // "on_eventID_currentIndexChanged"

    },
    "mainForm\0on_actionAdd_List_triggered\0"
    "\0on_actionAdd_Die_triggered\0"
    "on_actionRemove_Random_Event_triggered\0"
    "on_actionSimulate_triggered\0"
    "on_eventID_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void mainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainForm *_t = static_cast<mainForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAdd_List_triggered(); break;
        case 1: _t->on_actionAdd_Die_triggered(); break;
        case 2: _t->on_actionRemove_Random_Event_triggered(); break;
        case 3: _t->on_actionSimulate_triggered(); break;
        case 4: _t->on_eventID_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainForm.data,
      qt_meta_data_mainForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainForm.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
