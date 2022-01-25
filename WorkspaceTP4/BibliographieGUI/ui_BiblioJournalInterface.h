/********************************************************************************
** Form generated from reading UI file 'BiblioJournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOJOURNALINTERFACE_H
#define UI_BIBLIOJOURNALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BiblioJournalInterface
{
public:
    QPushButton *confirmerButton;
    QFrame *frameEntrees;
    QLabel *titreJournal;
    QLabel *auteurJournal;
    QLabel *anneeJournal;
    QLabel *volumeJournal;
    QLabel *numeroJournal;
    QLabel *pageJournal;
    QLineEdit *lineTitreJournal;
    QLineEdit *lineAuteurJournal;
    QSpinBox *spinBoxAnneeJournal;
    QSpinBox *spinBoxNumero;
    QSpinBox *spinBoxVolume;
    QSpinBox *spinBoxPage;
    QLabel *label;
    QLineEdit *lineNomJournal;
    QLabel *anneeJournal_2;
    QLineEdit *lineIssnJournal;
    QPushButton *annulerButton;

    void setupUi(QDialog *BiblioJournalInterface)
    {
        if (BiblioJournalInterface->objectName().isEmpty())
            BiblioJournalInterface->setObjectName(QString::fromUtf8("BiblioJournalInterface"));
        BiblioJournalInterface->resize(476, 404);
        confirmerButton = new QPushButton(BiblioJournalInterface);
        confirmerButton->setObjectName(QString::fromUtf8("confirmerButton"));
        confirmerButton->setGeometry(QRect(360, 350, 90, 28));
        frameEntrees = new QFrame(BiblioJournalInterface);
        frameEntrees->setObjectName(QString::fromUtf8("frameEntrees"));
        frameEntrees->setGeometry(QRect(20, 20, 431, 321));
        frameEntrees->setFrameShape(QFrame::StyledPanel);
        frameEntrees->setFrameShadow(QFrame::Raised);
        titreJournal = new QLabel(frameEntrees);
        titreJournal->setObjectName(QString::fromUtf8("titreJournal"));
        titreJournal->setGeometry(QRect(10, 20, 131, 16));
        auteurJournal = new QLabel(frameEntrees);
        auteurJournal->setObjectName(QString::fromUtf8("auteurJournal"));
        auteurJournal->setGeometry(QRect(10, 50, 58, 16));
        anneeJournal = new QLabel(frameEntrees);
        anneeJournal->setObjectName(QString::fromUtf8("anneeJournal"));
        anneeJournal->setGeometry(QRect(10, 80, 101, 21));
        volumeJournal = new QLabel(frameEntrees);
        volumeJournal->setObjectName(QString::fromUtf8("volumeJournal"));
        volumeJournal->setGeometry(QRect(10, 210, 58, 16));
        numeroJournal = new QLabel(frameEntrees);
        numeroJournal->setObjectName(QString::fromUtf8("numeroJournal"));
        numeroJournal->setGeometry(QRect(10, 240, 58, 16));
        pageJournal = new QLabel(frameEntrees);
        pageJournal->setObjectName(QString::fromUtf8("pageJournal"));
        pageJournal->setGeometry(QRect(10, 270, 58, 16));
        lineTitreJournal = new QLineEdit(frameEntrees);
        lineTitreJournal->setObjectName(QString::fromUtf8("lineTitreJournal"));
        lineTitreJournal->setGeometry(QRect(220, 20, 113, 28));
        lineAuteurJournal = new QLineEdit(frameEntrees);
        lineAuteurJournal->setObjectName(QString::fromUtf8("lineAuteurJournal"));
        lineAuteurJournal->setGeometry(QRect(220, 50, 113, 28));
        spinBoxAnneeJournal = new QSpinBox(frameEntrees);
        spinBoxAnneeJournal->setObjectName(QString::fromUtf8("spinBoxAnneeJournal"));
        spinBoxAnneeJournal->setGeometry(QRect(220, 80, 111, 26));
        spinBoxAnneeJournal->setMaximum(2050);
        spinBoxAnneeJournal->setValue(2000);
        spinBoxNumero = new QSpinBox(frameEntrees);
        spinBoxNumero->setObjectName(QString::fromUtf8("spinBoxNumero"));
        spinBoxNumero->setGeometry(QRect(220, 240, 111, 26));
        spinBoxNumero->setMaximum(5000);
        spinBoxNumero->setValue(1);
        spinBoxVolume = new QSpinBox(frameEntrees);
        spinBoxVolume->setObjectName(QString::fromUtf8("spinBoxVolume"));
        spinBoxVolume->setGeometry(QRect(220, 210, 111, 26));
        spinBoxVolume->setMaximum(5000);
        spinBoxVolume->setValue(1);
        spinBoxPage = new QSpinBox(frameEntrees);
        spinBoxPage->setObjectName(QString::fromUtf8("spinBoxPage"));
        spinBoxPage->setGeometry(QRect(220, 270, 111, 26));
        spinBoxPage->setMaximum(5000);
        spinBoxPage->setValue(1);
        label = new QLabel(frameEntrees);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 180, 101, 16));
        lineNomJournal = new QLineEdit(frameEntrees);
        lineNomJournal->setObjectName(QString::fromUtf8("lineNomJournal"));
        lineNomJournal->setGeometry(QRect(220, 180, 113, 28));
        anneeJournal_2 = new QLabel(frameEntrees);
        anneeJournal_2->setObjectName(QString::fromUtf8("anneeJournal_2"));
        anneeJournal_2->setGeometry(QRect(10, 110, 101, 21));
        lineIssnJournal = new QLineEdit(frameEntrees);
        lineIssnJournal->setObjectName(QString::fromUtf8("lineIssnJournal"));
        lineIssnJournal->setGeometry(QRect(220, 110, 113, 28));
        annulerButton = new QPushButton(BiblioJournalInterface);
        annulerButton->setObjectName(QString::fromUtf8("annulerButton"));
        annulerButton->setGeometry(QRect(30, 350, 90, 28));

        retranslateUi(BiblioJournalInterface);
        QObject::connect(annulerButton, SIGNAL(clicked()), BiblioJournalInterface, SLOT(close()));
        QObject::connect(confirmerButton, SIGNAL(clicked()), BiblioJournalInterface, SLOT(validerEntrees()));

        QMetaObject::connectSlotsByName(BiblioJournalInterface);
    } // setupUi

    void retranslateUi(QDialog *BiblioJournalInterface)
    {
        BiblioJournalInterface->setWindowTitle(QApplication::translate("BiblioJournalInterface", "BiblioJournalInterface", nullptr));
        confirmerButton->setText(QApplication::translate("BiblioJournalInterface", "Confirmer", nullptr));
        titreJournal->setText(QApplication::translate("BiblioJournalInterface", "Titre de la reference: ", nullptr));
        auteurJournal->setText(QApplication::translate("BiblioJournalInterface", "Auteur: ", nullptr));
        anneeJournal->setText(QApplication::translate("BiblioJournalInterface", "Annee d'edition: ", nullptr));
        volumeJournal->setText(QApplication::translate("BiblioJournalInterface", "Volume: ", nullptr));
        numeroJournal->setText(QApplication::translate("BiblioJournalInterface", "Numero: ", nullptr));
        pageJournal->setText(QApplication::translate("BiblioJournalInterface", "Page: ", nullptr));
        label->setText(QApplication::translate("BiblioJournalInterface", "Nom du journal: ", nullptr));
        anneeJournal_2->setText(QApplication::translate("BiblioJournalInterface", "Code ISSN: ", nullptr));
        annulerButton->setText(QApplication::translate("BiblioJournalInterface", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BiblioJournalInterface: public Ui_BiblioJournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOJOURNALINTERFACE_H
