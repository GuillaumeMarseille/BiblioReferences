/********************************************************************************
** Form generated from reading UI file 'BiblioOuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOOUVRAGEINTERFACE_H
#define UI_BIBLIOOUVRAGEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BiblioOuvrageInterface
{
public:
    QPushButton *ok;
    QPushButton *annuler;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *titreOuvrage;
    QLineEdit *auteurs;
    QLabel *label_3;
    QSpinBox *annee;
    QLabel *label_4;
    QLineEdit *identifiant;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *editeur;
    QLineEdit *ville;

    void setupUi(QDialog *BiblioOuvrageInterface)
    {
        if (BiblioOuvrageInterface->objectName().isEmpty())
            BiblioOuvrageInterface->setObjectName(QString::fromUtf8("BiblioOuvrageInterface"));
        BiblioOuvrageInterface->resize(489, 405);
        ok = new QPushButton(BiblioOuvrageInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(120, 330, 90, 28));
        annuler = new QPushButton(BiblioOuvrageInterface);
        annuler->setObjectName(QString::fromUtf8("annuler"));
        annuler->setGeometry(QRect(270, 330, 90, 28));
        label = new QLabel(BiblioOuvrageInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 111, 16));
        label_2 = new QLabel(BiblioOuvrageInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 58, 16));
        titreOuvrage = new QLineEdit(BiblioOuvrageInterface);
        titreOuvrage->setObjectName(QString::fromUtf8("titreOuvrage"));
        titreOuvrage->setGeometry(QRect(200, 20, 271, 28));
        auteurs = new QLineEdit(BiblioOuvrageInterface);
        auteurs->setObjectName(QString::fromUtf8("auteurs"));
        auteurs->setGeometry(QRect(200, 70, 271, 28));
        label_3 = new QLabel(BiblioOuvrageInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 130, 121, 16));
        annee = new QSpinBox(BiblioOuvrageInterface);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setGeometry(QRect(200, 120, 101, 26));
        annee->setMinimum(1700);
        annee->setMaximum(2050);
        annee->setValue(2000);
        label_4 = new QLabel(BiblioOuvrageInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 180, 141, 16));
        identifiant = new QLineEdit(BiblioOuvrageInterface);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(200, 170, 271, 28));
        label_5 = new QLabel(BiblioOuvrageInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 230, 58, 16));
        label_6 = new QLabel(BiblioOuvrageInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 280, 121, 16));
        editeur = new QLineEdit(BiblioOuvrageInterface);
        editeur->setObjectName(QString::fromUtf8("editeur"));
        editeur->setGeometry(QRect(200, 220, 271, 28));
        ville = new QLineEdit(BiblioOuvrageInterface);
        ville->setObjectName(QString::fromUtf8("ville"));
        ville->setGeometry(QRect(200, 270, 113, 28));

        retranslateUi(BiblioOuvrageInterface);
        QObject::connect(ok, SIGNAL(clicked()), BiblioOuvrageInterface, SLOT(valideInfoOuvrage()));
        QObject::connect(annuler, SIGNAL(clicked()), BiblioOuvrageInterface, SLOT(close()));

        QMetaObject::connectSlotsByName(BiblioOuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *BiblioOuvrageInterface)
    {
        BiblioOuvrageInterface->setWindowTitle(QApplication::translate("BiblioOuvrageInterface", "BiblioOuvrageInterface", nullptr));
        ok->setText(QApplication::translate("BiblioOuvrageInterface", "Ok", nullptr));
        annuler->setText(QApplication::translate("BiblioOuvrageInterface", "Annuler", nullptr));
        label->setText(QApplication::translate("BiblioOuvrageInterface", "Titre de l'ouvrage :", nullptr));
        label_2->setText(QApplication::translate("BiblioOuvrageInterface", "Auteurs :", nullptr));
        label_3->setText(QApplication::translate("BiblioOuvrageInterface", "Ann\303\251e de parution :", nullptr));
        label_4->setText(QApplication::translate("BiblioOuvrageInterface", "Num\303\251ro d'identifiant :", nullptr));
        label_5->setText(QApplication::translate("BiblioOuvrageInterface", "\303\211diteur :", nullptr));
        label_6->setText(QApplication::translate("BiblioOuvrageInterface", "Ville d'\303\251dition :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BiblioOuvrageInterface: public Ui_BiblioOuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOOUVRAGEINTERFACE_H
