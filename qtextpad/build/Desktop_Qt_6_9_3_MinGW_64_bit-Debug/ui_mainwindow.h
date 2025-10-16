/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrer_sous;
    QAction *actionFermer;
    QAction *actionQuitter;
    QAction *actionCouper;
    QAction *actionCopier;
    QAction *actionColler;
    QAction *actionS_lectionner_tout;
    QAction *actionD_faire;
    QAction *actionRefaire;
    QAction *actionEnregistrer;
    QAction *actionToto;
    QAction *actionR_gler_la_police;
    QAction *actionSe_rendre_a_la_ligne;
    QAction *actionRechercher;
    QAction *actionRechercher_suivant;
    QAction *actionRemplacer;
    QAction *actionAfficher_les_num_ros_de_lignes;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuDocuments_r_cents;
    QMenu *menuEdition;
    QMenu *menuPr_f_rences;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(488, 300);
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName("actionNouveau");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-new")));
        actionNouveau->setIcon(icon);
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName("actionOuvrir");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("document-open")));
        actionOuvrir->setIcon(icon1);
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName("actionEnregistrer_sous");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("document-save-as")));
        actionEnregistrer_sous->setIcon(icon2);
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName("actionFermer");
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName("actionQuitter");
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        actionQuitter->setIcon(icon3);
        actionCouper = new QAction(MainWindow);
        actionCouper->setObjectName("actionCouper");
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("edit-cut")));
        actionCouper->setIcon(icon4);
        actionCopier = new QAction(MainWindow);
        actionCopier->setObjectName("actionCopier");
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("edit-copy")));
        actionCopier->setIcon(icon5);
        actionColler = new QAction(MainWindow);
        actionColler->setObjectName("actionColler");
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("edit-paste")));
        actionColler->setIcon(icon6);
        actionS_lectionner_tout = new QAction(MainWindow);
        actionS_lectionner_tout->setObjectName("actionS_lectionner_tout");
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("edit-select-all")));
        actionS_lectionner_tout->setIcon(icon7);
        actionD_faire = new QAction(MainWindow);
        actionD_faire->setObjectName("actionD_faire");
        QIcon icon8(QIcon::fromTheme(QString::fromUtf8("edit-undo")));
        actionD_faire->setIcon(icon8);
        actionRefaire = new QAction(MainWindow);
        actionRefaire->setObjectName("actionRefaire");
        QIcon icon9(QIcon::fromTheme(QString::fromUtf8("edit-redo")));
        actionRefaire->setIcon(icon9);
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName("actionEnregistrer");
        QIcon icon10(QIcon::fromTheme(QString::fromUtf8("document-save")));
        actionEnregistrer->setIcon(icon10);
        actionToto = new QAction(MainWindow);
        actionToto->setObjectName("actionToto");
        actionR_gler_la_police = new QAction(MainWindow);
        actionR_gler_la_police->setObjectName("actionR_gler_la_police");
        actionR_gler_la_police->setCheckable(true);
        QIcon icon11(QIcon::fromTheme(QIcon::ThemeIcon::ToolsCheckSpelling));
        actionR_gler_la_police->setIcon(icon11);
        actionSe_rendre_a_la_ligne = new QAction(MainWindow);
        actionSe_rendre_a_la_ligne->setObjectName("actionSe_rendre_a_la_ligne");
        QIcon icon12(QIcon::fromTheme(QIcon::ThemeIcon::ObjectRotateLeft));
        actionSe_rendre_a_la_ligne->setIcon(icon12);
        actionRechercher = new QAction(MainWindow);
        actionRechercher->setObjectName("actionRechercher");
        QIcon icon13(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        actionRechercher->setIcon(icon13);
        actionRechercher_suivant = new QAction(MainWindow);
        actionRechercher_suivant->setObjectName("actionRechercher_suivant");
        QIcon icon14(QIcon::fromTheme(QIcon::ThemeIcon::GoNext));
        actionRechercher_suivant->setIcon(icon14);
        actionRemplacer = new QAction(MainWindow);
        actionRemplacer->setObjectName("actionRemplacer");
        actionAfficher_les_num_ros_de_lignes = new QAction(MainWindow);
        actionAfficher_les_num_ros_de_lignes->setObjectName("actionAfficher_les_num_ros_de_lignes");
        actionAfficher_les_num_ros_de_lignes->setCheckable(true);
        actionAfficher_les_num_ros_de_lignes->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 488, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName("menuFichier");
        menuDocuments_r_cents = new QMenu(menuFichier);
        menuDocuments_r_cents->setObjectName("menuDocuments_r_cents");
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName("menuEdition");
        menuPr_f_rences = new QMenu(menuBar);
        menuPr_f_rences->setObjectName("menuPr_f_rences");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuPr_f_rences->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionFermer);
        menuFichier->addSeparator();
        menuFichier->addAction(menuDocuments_r_cents->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionD_faire);
        menuEdition->addAction(actionRefaire);
        menuEdition->addSeparator();
        menuEdition->addAction(actionCouper);
        menuEdition->addAction(actionCopier);
        menuEdition->addAction(actionColler);
        menuEdition->addAction(actionS_lectionner_tout);
        menuEdition->addSeparator();
        menuEdition->addAction(actionSe_rendre_a_la_ligne);
        menuEdition->addAction(actionRechercher);
        menuEdition->addAction(actionRechercher_suivant);
        menuEdition->addAction(actionRemplacer);
        menuPr_f_rences->addAction(actionR_gler_la_police);
        menuPr_f_rences->addAction(actionAfficher_les_num_ros_de_lignes);
        mainToolBar->addAction(actionNouveau);
        mainToolBar->addAction(actionOuvrir);
        mainToolBar->addAction(actionEnregistrer);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCouper);
        mainToolBar->addAction(actionCopier);
        mainToolBar->addAction(actionColler);
        mainToolBar->addAction(actionS_lectionner_tout);
        mainToolBar->addAction(actionD_faire);
        mainToolBar->addAction(actionRefaire);
        mainToolBar->addAction(actionRechercher);
        mainToolBar->addAction(actionRechercher_suivant);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QTextPad", nullptr));
        actionNouveau->setText(QCoreApplication::translate("MainWindow", "Nouveau", nullptr));
#if QT_CONFIG(shortcut)
        actionNouveau->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOuvrir->setText(QCoreApplication::translate("MainWindow", "Ouvrir", nullptr));
#if QT_CONFIG(shortcut)
        actionOuvrir->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnregistrer_sous->setText(QCoreApplication::translate("MainWindow", "Enregistrer sous ...", nullptr));
        actionFermer->setText(QCoreApplication::translate("MainWindow", "Fermer", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCouper->setText(QCoreApplication::translate("MainWindow", "Couper", nullptr));
#if QT_CONFIG(shortcut)
        actionCouper->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopier->setText(QCoreApplication::translate("MainWindow", "Copier", nullptr));
#if QT_CONFIG(shortcut)
        actionCopier->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionColler->setText(QCoreApplication::translate("MainWindow", "Coller", nullptr));
#if QT_CONFIG(shortcut)
        actionColler->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionS_lectionner_tout->setText(QCoreApplication::translate("MainWindow", "S\303\251lectionner tout", nullptr));
#if QT_CONFIG(shortcut)
        actionS_lectionner_tout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionD_faire->setText(QCoreApplication::translate("MainWindow", "D\303\251faire", nullptr));
#if QT_CONFIG(shortcut)
        actionD_faire->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRefaire->setText(QCoreApplication::translate("MainWindow", "Refaire", nullptr));
#if QT_CONFIG(shortcut)
        actionRefaire->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnregistrer->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
#if QT_CONFIG(shortcut)
        actionEnregistrer->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionToto->setText(QCoreApplication::translate("MainWindow", "toto", nullptr));
        actionR_gler_la_police->setText(QCoreApplication::translate("MainWindow", "R\303\251gler la police", nullptr));
        actionSe_rendre_a_la_ligne->setText(QCoreApplication::translate("MainWindow", "Se rendre a la ligne", nullptr));
        actionRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        actionRechercher_suivant->setText(QCoreApplication::translate("MainWindow", "Rechercher suivant", nullptr));
        actionRemplacer->setText(QCoreApplication::translate("MainWindow", "Remplacer", nullptr));
        actionAfficher_les_num_ros_de_lignes->setText(QCoreApplication::translate("MainWindow", "Afficher les num\303\251ros de lignes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuDocuments_r_cents->setTitle(QCoreApplication::translate("MainWindow", "Documents r\303\251cents", nullptr));
        menuEdition->setTitle(QCoreApplication::translate("MainWindow", "Edition", nullptr));
        menuPr_f_rences->setTitle(QCoreApplication::translate("MainWindow", "Pr\303\251f\303\251rences", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
