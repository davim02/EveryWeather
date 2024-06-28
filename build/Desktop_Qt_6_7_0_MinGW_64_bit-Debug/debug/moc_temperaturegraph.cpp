/****************************************************************************
** Meta object code from reading C++ file 'temperaturegraph.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../View/GraphRenderer/temperaturegraph.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'temperaturegraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSTemperatureGraphENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTemperatureGraphENDCLASS = QtMocHelpers::stringData(
    "TemperatureGraph"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTemperatureGraphENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject TemperatureGraph::staticMetaObject = { {
    QMetaObject::SuperData::link<QChart::staticMetaObject>(),
    qt_meta_stringdata_CLASSTemperatureGraphENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTemperatureGraphENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTemperatureGraphENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TemperatureGraph, std::true_type>
    >,
    nullptr
} };

void TemperatureGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *TemperatureGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TemperatureGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTemperatureGraphENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QChart::qt_metacast(_clname);
}

int TemperatureGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QChart::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
