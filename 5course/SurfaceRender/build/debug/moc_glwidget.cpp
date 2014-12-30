/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SurfaceRender/glwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLWidget_t {
    QByteArrayData data[19];
    char stringdata[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GLWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GLWidget_t qt_meta_stringdata_GLWidget = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 10),
QT_MOC_LITERAL(4, 32, 10),
QT_MOC_LITERAL(5, 43, 7),
QT_MOC_LITERAL(6, 51, 7),
QT_MOC_LITERAL(7, 59, 7),
QT_MOC_LITERAL(8, 67, 11),
QT_MOC_LITERAL(9, 79, 11),
QT_MOC_LITERAL(10, 91, 13),
QT_MOC_LITERAL(11, 105, 13),
QT_MOC_LITERAL(12, 119, 18),
QT_MOC_LITERAL(13, 138, 9),
QT_MOC_LITERAL(14, 148, 11),
QT_MOC_LITERAL(15, 160, 2),
QT_MOC_LITERAL(16, 163, 2),
QT_MOC_LITERAL(17, 166, 2),
QT_MOC_LITERAL(18, 169, 4)
    },
    "GLWidget\0translateX\0\0translateY\0"
    "translateZ\0rotateX\0rotateY\0rotateZ\0"
    "projectionA\0projectionF\0parabolaParam\0"
    "changeSurface\0showNormalsForFace\0"
    "editCurve\0buildNormal\0p1\0p2\0p3\0surf\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLWidget[] = {

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
       1,    1,   79,    2, 0x0a,
       3,    1,   82,    2, 0x0a,
       4,    1,   85,    2, 0x0a,
       5,    1,   88,    2, 0x0a,
       6,    1,   91,    2, 0x0a,
       7,    1,   94,    2, 0x0a,
       8,    1,   97,    2, 0x0a,
       9,    1,  100,    2, 0x0a,
      10,    1,  103,    2, 0x0a,
      11,    1,  106,    2, 0x0a,
      12,    1,  109,    2, 0x0a,
      13,    0,  112,    2, 0x0a,
      14,    4,  113,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector4D, QMetaType::QVector4D, QMetaType::QVector4D, QMetaType::Int,   15,   16,   17,   18,

       0        // eod
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLWidget *_t = static_cast<GLWidget *>(_o);
        switch (_id) {
        case 0: _t->translateX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->translateY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->translateZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->rotateX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->rotateY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->rotateZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->projectionA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->projectionF((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->parabolaParam((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->changeSurface((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showNormalsForFace((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->editCurve(); break;
        case 12: _t->buildNormal((*reinterpret_cast< const QVector4D(*)>(_a[1])),(*reinterpret_cast< const QVector4D(*)>(_a[2])),(*reinterpret_cast< const QVector4D(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget.data,
      qt_meta_data_GLWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget.stringdata))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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
