/********************************************************************************
** Form generated from reading UI file 'BiblioSupprimeInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOSUPPRIMEINTERFACE_H
#define UI_BIBLIOSUPPRIMEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BiblioSupprimeInterface
{
public:
    QPushButton *supprimer;
    QPushButton *annuler;
    QLabel *label;
    QLineEdit *identifiant;

    void setupUi(QDialog *BiblioSupprimeInterface)
    {
        if (BiblioSupprimeInterface->objectName().isEmpty())
            BiblioSupprimeInterface->setObjectName(QString::fromUtf8("BiblioSupprimeInterface"));
        BiblioSupprimeInterface->resize(578, 185);
        supprimer = new QPushButton(BiblioSupprimeInterface);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        supprimer->setGeometry(QRect(190, 120, 90, 28));
        annuler = new QPushButton(BiblioSupprimeInterface);
        annuler->setObjectName(QString::fromUtf8("annuler"));
        annuler->setGeometry(QRect(340, 120, 90, 28));
        label = new QLabel(BiblioSupprimeInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 271, 16));
        identifiant = new QLineEdit(BiblioSupprimeInterface);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(280, 50, 251, 28));

        retranslateUi(BiblioSupprimeInterface);
        QObject::connect(annuler, SIGNAL(clicked()), BiblioSupprimeInterface, SLOT(close()));
        QObject::connect(supprimer, SIGNAL(clicked()), BiblioSupprimeInterface, SLOT(valideInfoIdentifiant()));

        QMetaObject::connectSlotsByName(BiblioSupprimeInterface);
    } // setupUi

    void retranslateUi(QDialog *BiblioSupprimeInterface)
    {
        BiblioSupprimeInterface->setWindowTitle(QApplication::translate("BiblioSupprimeInterface", "BiblioSupprimeInterface", nullptr));
        supprimer->setText(QApplication::translate("BiblioSupprimeInterface", "Supprimer", nullptr));
        annuler->setText(QApplication::translate("BiblioSupprimeInterface", "Annuler", nullptr));
        label->setText(QApplication::translate("BiblioSupprimeInterface", "Entrez le num\303\251ro d'identifiant \303\240 supprimer :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BiblioSupprimeInterface: public Ui_BiblioSupprimeInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOSUPPRIMEINTERFACE_H
