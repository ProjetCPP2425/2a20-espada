/****************************************************************************
** Meta object code from reading C++ file 'projet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../projet.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSProjetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSProjetENDCLASS = QtMocHelpers::stringData(
    "Projet",
    "on_pushButton_ajouter_clicked",
    "",
    "on_pushButton_supprimer_clicked",
    "QModelIndex",
    "index",
    "on_pushButton_modifier_clicked",
    "on_pushButton_search_clicked",
    "on_pushButton_pdf_clicked",
    "generateStatistiques",
    "drawStatistiquesChart",
    "QMap<QString,double>",
    "statusPercentages",
    "on_pushButton_up_clicked",
    "on_pushButton_down_clicked",
    "openChatbot",
    "on_pushButton_statistiques_clicked",
    "handleSendMessage",
    "handleNetworkReply",
    "QNetworkReply*",
    "reply"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSProjetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    1,   93,    2, 0x08,    2 /* Private */,
       6,    1,   96,    2, 0x08,    4 /* Private */,
       7,    0,   99,    2, 0x08,    6 /* Private */,
       8,    0,  100,    2, 0x08,    7 /* Private */,
       9,    0,  101,    2, 0x08,    8 /* Private */,
      10,    1,  102,    2, 0x08,    9 /* Private */,
      13,    0,  105,    2, 0x08,   11 /* Private */,
      14,    0,  106,    2, 0x08,   12 /* Private */,
      15,    0,  107,    2, 0x08,   13 /* Private */,
      16,    0,  108,    2, 0x08,   14 /* Private */,
      17,    0,  109,    2, 0x08,   15 /* Private */,
      18,    1,  110,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

Q_CONSTINIT const QMetaObject Projet::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSProjetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSProjetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSProjetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Projet, std::true_type>,
        // method 'on_pushButton_ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_pushButton_modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_pushButton_search_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_pdf_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateStatistiques'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawStatistiquesChart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QString,double> &, std::false_type>,
        // method 'on_pushButton_up_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_down_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openChatbot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_statistiques_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleNetworkReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>
    >,
    nullptr
} };

void Projet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Projet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_ajouter_clicked(); break;
        case 1: _t->on_pushButton_supprimer_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_pushButton_modifier_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->on_pushButton_search_clicked(); break;
        case 4: _t->on_pushButton_pdf_clicked(); break;
        case 5: _t->generateStatistiques(); break;
        case 6: _t->drawStatistiquesChart((*reinterpret_cast< std::add_pointer_t<QMap<QString,double>>>(_a[1]))); break;
        case 7: _t->on_pushButton_up_clicked(); break;
        case 8: _t->on_pushButton_down_clicked(); break;
        case 9: _t->openChatbot(); break;
        case 10: _t->on_pushButton_statistiques_clicked(); break;
        case 11: _t->handleSendMessage(); break;
        case 12: _t->handleNetworkReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Projet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Projet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSProjetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Projet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
