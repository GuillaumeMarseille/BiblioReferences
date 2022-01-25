/********************************************************************************
** Form generated from reading UI file 'BibliographieInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOGRAPHIEINTERFACE_H
#define UI_BIBLIOGRAPHIEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BibliographieInterface
{
public:
    QAction *actionSupprimer_une_R_f_rence;
    QAction *actionOuvrage;
    QAction *actionJournal;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu_Principale;
    QMenu *menuAjouter_R_f_rence;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BibliographieInterface)
    {
        if (BibliographieInterface->objectName().isEmpty())
            BibliographieInterface->setObjectName(QString::fromUtf8("BibliographieInterface"));
        BibliographieInterface->resize(834, 614);
        actionSupprimer_une_R_f_rence = new QAction(BibliographieInterface);
        actionSupprimer_une_R_f_rence->setObjectName(QString::fromUtf8("actionSupprimer_une_R_f_rence"));
        actionOuvrage = new QAction(BibliographieInterface);
        actionOuvrage->setObjectName(QString::fromUtf8("actionOuvrage"));
        actionJournal = new QAction(BibliographieInterface);
        actionJournal->setObjectName(QString::fromUtf8("actionJournal"));
        actionQuitter = new QAction(BibliographieInterface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(BibliographieInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(0, 0, 1161, 811));
        BibliographieInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BibliographieInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 834, 22));
        menuMenu_Principale = new QMenu(menubar);
        menuMenu_Principale->setObjectName(QString::fromUtf8("menuMenu_Principale"));
        menuAjouter_R_f_rence = new QMenu(menuMenu_Principale);
        menuAjouter_R_f_rence->setObjectName(QString::fromUtf8("menuAjouter_R_f_rence"));
        BibliographieInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(BibliographieInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BibliographieInterface->setStatusBar(statusbar);

        menubar->addAction(menuMenu_Principale->menuAction());
        menuMenu_Principale->addAction(menuAjouter_R_f_rence->menuAction());
        menuMenu_Principale->addAction(actionSupprimer_une_R_f_rence);
        menuMenu_Principale->addAction(actionQuitter);
        menuAjouter_R_f_rence->addAction(actionOuvrage);
        menuAjouter_R_f_rence->addAction(actionJournal);

        retranslateUi(BibliographieInterface);
        QObject::connect(actionQuitter, SIGNAL(triggered()), BibliographieInterface, SLOT(close()));
        QObject::connect(actionOuvrage, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogOuvrage()));
        QObject::connect(actionSupprimer_une_R_f_rence, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogSupprime()));
        QObject::connect(actionJournal, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogJournal()));

        QMetaObject::connectSlotsByName(BibliographieInterface);
    } // setupUi

    void retranslateUi(QMainWindow *BibliographieInterface)
    {
        BibliographieInterface->setWindowTitle(QApplication::translate("BibliographieInterface", "BibliographieInterface", nullptr));
        actionSupprimer_une_R_f_rence->setText(QApplication::translate("BibliographieInterface", "Supprimer une R\303\251f\303\251rence", nullptr));
        actionOuvrage->setText(QApplication::translate("BibliographieInterface", "Ouvrage", nullptr));
        actionJournal->setText(QApplication::translate("BibliographieInterface", "Journal", nullptr));
        actionQuitter->setText(QApplication::translate("BibliographieInterface", "Quitter", nullptr));
        menuMenu_Principale->setTitle(QApplication::translate("BibliographieInterface", "Op\303\251rations", nullptr));
        menuAjouter_R_f_rence->setTitle(QApplication::translate("BibliographieInterface", "Ajouter R\303\251f\303\251rence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BibliographieInterface: public Ui_BibliographieInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOGRAPHIEINTERFACE_H
