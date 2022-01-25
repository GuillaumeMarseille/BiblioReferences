/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#ifndef _BIBLIOOUVRAGEINTERFACE_H
#define _BIBLIOOUVRAGEINTERFACE_H

#include "ui_BiblioOuvrageInterface.h"

/**
 * \class BiblioOuvrageInterface
 * \brief Classe permettant d'instancier la fenetre pour ajouter un ouvrage.
 */

class BiblioOuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  BiblioOuvrageInterface ();
  virtual ~BiblioOuvrageInterface ();

  QString reqTitre ()const;
  QString reqAuteurs ()const;
  int reqAnnee ()const;
  QString reqIdentifiant ()const;
  QString reqEditeur ()const;
  QString reqVille ()const;

private slots:
  bool validerTitre ();
  bool validerAuteur ();
  bool validerIsbn ();
  bool validerEditeur ();
  bool validerVille ();
  void valideInfoOuvrage ();

private:
  Ui::BiblioOuvrageInterface widget;

};

#endif /* _BIBLIOOUVRAGEINTERFACE_H */
