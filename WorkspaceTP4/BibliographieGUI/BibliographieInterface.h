/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#ifndef _BIBLIOGRAPHIEINTERFACE_H
#define _BIBLIOGRAPHIEINTERFACE_H

#include "ui_BibliographieInterface.h"
#include "Bibliographie.h"
#include <vector>
#include <string>

/**
 * \class BibliographieInterface
 * \brief Classe permettant d'instancier la fenetre pricipale de gestion d'une
 * bibliographie.
 */
class BibliographieInterface : public QMainWindow
{
  Q_OBJECT
public:
  BibliographieInterface ();
  virtual ~BibliographieInterface ();

  void ajouteReferenceOuvrage (const std::string& p_auteurs,
                               const std::string& p_titre,
                               const int p_annee,
                               const std::string& p_identifiant,
                               const std::string& p_editeur,
                               const std::string& p_ville);

private slots:
  void dialogOuvrage ();
  void dialogSupprime ();
  void dialogJournal ();


private:
  Ui::BibliographieInterface widget;
};

#endif /* _BIBLIOGRAPHIEINTERFACE_H */
