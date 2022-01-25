/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#include "BiblioSupprimeInterface.h"
#include "QMessageBox"


/**
 * \brief Constructeur de la classe BiblioSupprimeInterface.
 * \class BiblioSupprimeInterface
 */
BiblioSupprimeInterface::BiblioSupprimeInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe BiblioSupprimeInterface.
 */
BiblioSupprimeInterface::~BiblioSupprimeInterface () { }


/**
 * \brief Permet d'accceder a l'identifiant de la reference en lecture.
 * \return Retourne l'identifiant de la reference.
 */
QString
BiblioSupprimeInterface::reqIdentifiant ()const
{
  return widget.identifiant->text ();
}


/**
 * \brief Methode verifiant s'assure que l'identifiant est present et
 * le supprime si c'est le cas. En plus d'un message de confirmation.
 */
void
BiblioSupprimeInterface::valideInfoIdentifiant ()
{
  if (reqIdentifiant ().isEmpty ())
    {
      QString messageIdentifiantVide ("Le numéro d'identifiant ne doit pas être vide.");
      QMessageBox::information (this, "IDENTIFIANT MANQUANT", messageIdentifiantVide);
      return;
    }
  QMessageBox::StandardButton reponse;
  reponse = QMessageBox::question (this, "Confirmation de suppression de la référence", "Voulez-vous vraiment supprimer la référence?",
                                   QMessageBox::Yes | QMessageBox::No);
  if (reponse == QMessageBox::No)
    {
      return;
    }
  accept ();
}