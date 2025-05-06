/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSButtonDelegateENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSButtonDelegateENDCLASS = QtMocHelpers::stringData(
    "ButtonDelegate",
    "deleteButtonClicked",
    "",
    "QModelIndex",
    "index",
    "editButtonClicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSButtonDelegateENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,
       5,    1,   29,    2, 0x06,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject ButtonDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_CLASSButtonDelegateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSButtonDelegateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSButtonDelegateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ButtonDelegate, std::true_type>,
        // method 'deleteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'editButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
    >,
    nullptr
} };

void ButtonDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ButtonDelegate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deleteButtonClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->editButtonClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ButtonDelegate::*)(const QModelIndex & );
            if (_t _q_method = &ButtonDelegate::deleteButtonClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ButtonDelegate::*)(const QModelIndex & );
            if (_t _q_method = &ButtonDelegate::editButtonClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ButtonDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ButtonDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSButtonDelegateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int ButtonDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ButtonDelegate::deleteButtonClicked(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ButtonDelegate::editButtonClicked(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSEditEmployeeDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSEditEmployeeDialogENDCLASS = QtMocHelpers::stringData(
    "EditEmployeeDialog",
    "on_saveButton_clicked",
    "",
    "on_cancelButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEditEmployeeDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    1 /* Private */,
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EditEmployeeDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSEditEmployeeDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEditEmployeeDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEditEmployeeDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EditEmployeeDialog, std::true_type>,
        // method 'on_saveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EditEmployeeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditEmployeeDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_saveButton_clicked(); break;
        case 1: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *EditEmployeeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditEmployeeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEditEmployeeDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EditEmployeeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_updateRDV_clicked",
    "",
    "on_addRDV_clicked",
    "on_suppRDV_clicked",
    "on_tab_affichageRDV_clicked",
    "QModelIndex",
    "index",
    "on_pushButton_ajouterEMP_clicked",
    "onDeleteButtonClicked",
    "onEditButtonClicked",
    "on_lineEditEMP_textChanged",
    "arg1",
    "on_dispoSortButton_clicked",
    "on_emailSortButton_clicked",
    "on_telephoneSortButton_clicked",
    "on_pdfButtonEMP_clicked",
    "on_statbuttonEMP_clicked",
    "on_logoutButton_clicked",
    "handleSerialData",
    "on_pushButton_ajouter_2c_clicked",
    "on_pushButton_supprimer_2c_clicked",
    "on_pushButton_modifier_2c_clicked",
    "on_tableView_2c_clicked",
    "on_pushButton_search_mod_2c_clicked",
    "on_pushButton_pdf_2c_clicked",
    "on_rechercher_2c_textChanged",
    "text",
    "on_trier_nom_2c_clicked",
    "on_trier_date_2c_clicked",
    "on_trier_type_2c_clicked",
    "on_pushbutton_6c_clicked",
    "on_pushButton_confirmer_res_clicked",
    "on_pushButton_supprimerr_res_clicked",
    "on_pushButton_modifier_res_clicked",
    "on_pushButton_confirmermodification_res_clicked",
    "on_qrCodeButton_clicked",
    "on_statbutton_res_clicked",
    "on_quantite_2_clicked",
    "on_type_2_clicked",
    "on_rechercher_textChanged",
    "on_pdfButton_res_clicked",
    "on_pushButton_envoyer_res_clicked",
    "on_pushButton_ajouter_clicked",
    "on_pushButton_supprimer_clicked",
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
    "reply",
    "on_rechercherRDV_textChanged",
    "on_pdfRDV_clicked",
    "on_modeRDV_2_clicked",
    "on_dateRDV_2_clicked",
    "on_statbuttonRDV_clicked",
    "checkUpcomingRdvNotification",
    "updateRdvButton",
    "on_btnRdvJour_clicked",
    "on_calander_rdv_clicked",
    "date",
    "on_calenderierRDV_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  374,    2, 0x08,    1 /* Private */,
       3,    0,  375,    2, 0x08,    2 /* Private */,
       4,    0,  376,    2, 0x08,    3 /* Private */,
       5,    1,  377,    2, 0x08,    4 /* Private */,
       8,    0,  380,    2, 0x08,    6 /* Private */,
       9,    1,  381,    2, 0x08,    7 /* Private */,
      10,    1,  384,    2, 0x08,    9 /* Private */,
      11,    1,  387,    2, 0x08,   11 /* Private */,
      13,    0,  390,    2, 0x08,   13 /* Private */,
      14,    0,  391,    2, 0x08,   14 /* Private */,
      15,    0,  392,    2, 0x08,   15 /* Private */,
      16,    0,  393,    2, 0x08,   16 /* Private */,
      17,    0,  394,    2, 0x08,   17 /* Private */,
      18,    0,  395,    2, 0x08,   18 /* Private */,
      19,    0,  396,    2, 0x08,   19 /* Private */,
      20,    0,  397,    2, 0x08,   20 /* Private */,
      21,    0,  398,    2, 0x08,   21 /* Private */,
      22,    0,  399,    2, 0x08,   22 /* Private */,
      23,    1,  400,    2, 0x08,   23 /* Private */,
      24,    0,  403,    2, 0x08,   25 /* Private */,
      25,    0,  404,    2, 0x08,   26 /* Private */,
      26,    1,  405,    2, 0x08,   27 /* Private */,
      28,    0,  408,    2, 0x08,   29 /* Private */,
      29,    0,  409,    2, 0x08,   30 /* Private */,
      30,    0,  410,    2, 0x08,   31 /* Private */,
      31,    0,  411,    2, 0x08,   32 /* Private */,
      32,    0,  412,    2, 0x08,   33 /* Private */,
      33,    0,  413,    2, 0x08,   34 /* Private */,
      34,    0,  414,    2, 0x08,   35 /* Private */,
      35,    0,  415,    2, 0x08,   36 /* Private */,
      36,    0,  416,    2, 0x08,   37 /* Private */,
      37,    0,  417,    2, 0x08,   38 /* Private */,
      38,    0,  418,    2, 0x08,   39 /* Private */,
      39,    0,  419,    2, 0x08,   40 /* Private */,
      40,    1,  420,    2, 0x08,   41 /* Private */,
      41,    0,  423,    2, 0x08,   43 /* Private */,
      42,    0,  424,    2, 0x08,   44 /* Private */,
      43,    0,  425,    2, 0x08,   45 /* Private */,
      44,    1,  426,    2, 0x08,   46 /* Private */,
      45,    1,  429,    2, 0x08,   48 /* Private */,
      46,    0,  432,    2, 0x08,   50 /* Private */,
      47,    0,  433,    2, 0x08,   51 /* Private */,
      48,    0,  434,    2, 0x08,   52 /* Private */,
      49,    1,  435,    2, 0x08,   53 /* Private */,
      52,    0,  438,    2, 0x08,   55 /* Private */,
      53,    0,  439,    2, 0x08,   56 /* Private */,
      54,    0,  440,    2, 0x08,   57 /* Private */,
      55,    0,  441,    2, 0x08,   58 /* Private */,
      56,    0,  442,    2, 0x08,   59 /* Private */,
      57,    1,  443,    2, 0x08,   60 /* Private */,
      60,    1,  446,    2, 0x08,   62 /* Private */,
      61,    0,  449,    2, 0x08,   64 /* Private */,
      62,    0,  450,    2, 0x08,   65 /* Private */,
      63,    0,  451,    2, 0x08,   66 /* Private */,
      64,    0,  452,    2, 0x08,   67 /* Private */,
      65,    0,  453,    2, 0x08,   68 /* Private */,
      66,    0,  454,    2, 0x08,   69 /* Private */,
      67,    0,  455,    2, 0x08,   70 /* Private */,
      68,    1,  456,    2, 0x08,   71 /* Private */,
      70,    0,  459,    2, 0x08,   73 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,   12,
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
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
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
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 58,   59,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   69,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_updateRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_suppRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tab_affichageRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_pushButton_ajouterEMP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'onEditButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_lineEditEMP_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_dispoSortButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_emailSortButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_telephoneSortButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdfButtonEMP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statbuttonEMP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_logoutButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSerialData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_ajouter_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimer_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_modifier_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_pushButton_search_mod_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_pdf_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rechercher_2c_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_trier_nom_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trier_date_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trier_type_2c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushbutton_6c_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_confirmer_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimerr_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_modifier_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_confirmermodification_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_qrCodeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statbutton_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_quantite_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_type_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rechercher_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pdfButton_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_envoyer_res_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'on_rechercherRDV_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pdfRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modeRDV_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_dateRDV_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statbuttonRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkUpcomingRdvNotification'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateRdvButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRdvJour_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_calander_rdv_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>,
        // method 'on_calenderierRDV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_updateRDV_clicked(); break;
        case 1: _t->on_addRDV_clicked(); break;
        case 2: _t->on_suppRDV_clicked(); break;
        case 3: _t->on_tab_affichageRDV_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 4: _t->on_pushButton_ajouterEMP_clicked(); break;
        case 5: _t->onDeleteButtonClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->onEditButtonClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 7: _t->on_lineEditEMP_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->on_dispoSortButton_clicked(); break;
        case 9: _t->on_emailSortButton_clicked(); break;
        case 10: _t->on_telephoneSortButton_clicked(); break;
        case 11: _t->on_pdfButtonEMP_clicked(); break;
        case 12: _t->on_statbuttonEMP_clicked(); break;
        case 13: _t->on_logoutButton_clicked(); break;
        case 14: _t->handleSerialData(); break;
        case 15: _t->on_pushButton_ajouter_2c_clicked(); break;
        case 16: _t->on_pushButton_supprimer_2c_clicked(); break;
        case 17: _t->on_pushButton_modifier_2c_clicked(); break;
        case 18: _t->on_tableView_2c_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 19: _t->on_pushButton_search_mod_2c_clicked(); break;
        case 20: _t->on_pushButton_pdf_2c_clicked(); break;
        case 21: _t->on_rechercher_2c_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->on_trier_nom_2c_clicked(); break;
        case 23: _t->on_trier_date_2c_clicked(); break;
        case 24: _t->on_trier_type_2c_clicked(); break;
        case 25: _t->on_pushbutton_6c_clicked(); break;
        case 26: _t->on_pushButton_confirmer_res_clicked(); break;
        case 27: _t->on_pushButton_supprimerr_res_clicked(); break;
        case 28: _t->on_pushButton_modifier_res_clicked(); break;
        case 29: _t->on_pushButton_confirmermodification_res_clicked(); break;
        case 30: _t->on_qrCodeButton_clicked(); break;
        case 31: _t->on_statbutton_res_clicked(); break;
        case 32: _t->on_quantite_2_clicked(); break;
        case 33: _t->on_type_2_clicked(); break;
        case 34: _t->on_rechercher_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->on_pdfButton_res_clicked(); break;
        case 36: _t->on_pushButton_envoyer_res_clicked(); break;
        case 37: _t->on_pushButton_ajouter_clicked(); break;
        case 38: _t->on_pushButton_supprimer_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 39: _t->on_pushButton_modifier_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 40: _t->on_pushButton_search_clicked(); break;
        case 41: _t->on_pushButton_pdf_clicked(); break;
        case 42: _t->generateStatistiques(); break;
        case 43: _t->drawStatistiquesChart((*reinterpret_cast< std::add_pointer_t<QMap<QString,double>>>(_a[1]))); break;
        case 44: _t->on_pushButton_up_clicked(); break;
        case 45: _t->on_pushButton_down_clicked(); break;
        case 46: _t->openChatbot(); break;
        case 47: _t->on_pushButton_statistiques_clicked(); break;
        case 48: _t->handleSendMessage(); break;
        case 49: _t->handleNetworkReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 50: _t->on_rechercherRDV_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: _t->on_pdfRDV_clicked(); break;
        case 52: _t->on_modeRDV_2_clicked(); break;
        case 53: _t->on_dateRDV_2_clicked(); break;
        case 54: _t->on_statbuttonRDV_clicked(); break;
        case 55: _t->checkUpcomingRdvNotification(); break;
        case 56: _t->updateRdvButton(); break;
        case 57: _t->on_btnRdvJour_clicked(); break;
        case 58: _t->on_calander_rdv_clicked((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 59: _t->on_calenderierRDV_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 49:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    }
    return _id;
}
QT_WARNING_POP
