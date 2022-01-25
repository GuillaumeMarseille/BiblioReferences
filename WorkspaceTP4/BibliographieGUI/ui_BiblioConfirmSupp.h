/********************************************************************************
** Form generated from reading UI file 'BiblioConfirmSupp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOCONFIRMSUPP_H
#define UI_BIBLIOCONFIRMSUPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BiblioConfirmSupp
{
public:
    QPushButton *supprimer;
    QPushButton *annuler;
    QLabel *label;

    void setupUi(QDialog *BiblioConfirmSupp)
    {
        if (BiblioConfirmSupp->objectName().isEmpty())
            BiblioConfirmSupp->setObjectName(QString::fromUtf8("BiblioConfirmSupp"));
        BiblioConfirmSupp->resize(350, 148);
        supprimer = new QPushButton(BiblioConfirmSupp);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        supprimer->setGeometry(QRect(70, 90, 90, 28));
        annuler = new QPushButton(BiblioConfirmSupp);
        annuler->setObjectName(QString::fromUtf8("annuler"));
        annuler->setGeometry(QRect(190, 90, 90, 28));
        label = new QLabel(BiblioConfirmSupp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 271, 16));

        retranslateUi(BiblioConfirmSupp);
        QObject::connect(annuler, SIGNAL(clicked()), BiblioConfirmSupp, SLOT(close()));

        QMetaObject::connectSlotsByName(BiblioConfirmSupp);
    } // setupUi

    void retranslateUi(QDialog *BiblioConfirmSupp)
    {
        BiblioConfirmSupp->setWindowTitle(QApplication::translate("BiblioConfirmSupp", "BiblioConfirmSupp", nullptr));
        supprimer->setText(QApplication::translate("BiblioConfirmSupp", "Oui", nullptr));
        annuler->setText(QApplication::translate("BiblioConfirmSupp", "Non", nullptr));
        label->setText(QApplication::translate("BiblioConfirmSupp", "Voulez-vous vraiment supprimer la r\303\251f\303\251rence?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BiblioConfirmSupp: public Ui_BiblioConfirmSupp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOCONFIRMSUPP_H
