/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#ifndef _BIBLIOJOURNALINTERFACE_H
#define _BIBLIOJOURNALINTERFACE_H

#include "ui_BiblioJournalInterface.h"

/**
 * \class BiblioJournalInterface
 * \brief Classe permettant d'instancier la fenetre pour ajouter un journal.
 */

class BiblioJournalInterface : public QDialog
{
  Q_OBJECT
public:
  BiblioJournalInterface ();
  virtual ~BiblioJournalInterface ();

  QString reqTitre ()const;
  QString reqAuteur ()const;
  int reqAnnee ()const;
  QString reqIssn ()const;
  QString reqNomJournal ()const;
  int reqVolume ()const;
  int reqNumero ()const;
  int reqPage ()const;

private slots:
  bool validerTitre ();
  bool validerAuteur ();
  bool validerIssn ();
  bool validerNomJournal ();
  void validerEntrees ();

private:
  Ui::BiblioJournalInterface widget;
};

#endif /* _BIBLIOJOURNALINTERFACE_H */
