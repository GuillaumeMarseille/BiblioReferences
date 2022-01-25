/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */
#ifndef _BIBLIOSUPPRIMEINTERFACE_H
#define _BIBLIOSUPPRIMEINTERFACE_H

#include "ui_BiblioSupprimeInterface.h"

/**
 * \class BiblioSupprimeInterface
 * \brief Classe permettant d'instancier la fenetre
 * pour supprimer une reference.
 */
class BiblioSupprimeInterface : public QDialog
{
  Q_OBJECT
public:
  BiblioSupprimeInterface ();
  virtual ~BiblioSupprimeInterface ();

  QString reqIdentifiant ()const;

private slots:
  void valideInfoIdentifiant ();
  //void dialogConfirmSupp ();

private:
  Ui::BiblioSupprimeInterface widget;
};

#endif /* _BIBLIOSUPPRIMEINTERFACE_H */
