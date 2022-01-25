/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#include "BiblioJournalInterface.h"
#include "validationFormat.h"
#include "QMessageBox"


/**
 * \brief Constructeur de la classe BiblioJournalInterface.
 * \class BiblioJournalInterface
 */
BiblioJournalInterface::BiblioJournalInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe BiblioJournalInterface.
 */
BiblioJournalInterface::~BiblioJournalInterface () { }


/**
 * \brief Permet d'accceder au titre de la reference en lecture.
 * \return Retourne le titre de la reference.
 */
QString
BiblioJournalInterface::reqTitre ()const
{
  return widget.lineTitreJournal->text ();
}


/**
 * \brief Permet d'accceder au nom de l'auteur de la reference en lecture.
 * \return Retourne le nom de l'auteur de la reference.
 */
QString
BiblioJournalInterface::reqAuteur ()const
{
  return widget.lineAuteurJournal->text ();
}


/**
 * \brief Permet d'accceder a l'annee d'edition de la reference en lecture.
 * \return Retourne l'annee d'edition  de la reference.
 */
int
BiblioJournalInterface::reqAnnee ()const
{
  return widget.spinBoxAnneeJournal->value ();
}


/**
 * \brief Permet d'accceder au code ISSN du journal en lecture.
 * \return Retourne le code ISSN du journal.
 */
QString
BiblioJournalInterface::reqIssn ()const
{
  return widget.lineIssnJournal->text ();
}


/**
 * \brief Permet d'accceder au nom du journal en lecture.
 * \return Retourne le nom du journal.
 */
QString
BiblioJournalInterface::reqNomJournal ()const
{
  return widget.lineNomJournal->text ();
}


/**
 * \brief Permet d'accceder au volume du journal en lecture.
 * \return Retourne le volume du journal.
 */
int
BiblioJournalInterface::reqVolume ()const
{
  return widget.spinBoxVolume->value ();
}


/**
 * \brief Permet d'accceder au numero du journal en lecture.
 * \return Retourne le numero du journal.
 */
int
BiblioJournalInterface::reqNumero ()const
{
  return widget.spinBoxNumero->value ();
}


/**
 * \brief Permet d'accceder a la page du journal en lecture.
 * \return Retourne la page du journal.
 */
int
BiblioJournalInterface::reqPage ()const
{
  return widget.spinBoxPage->value ();
}


/**
 * \brief methode pour valider le titre.
 * \return Retourne vrai si le titre est invalide, faux sinon.
 */
bool
BiblioJournalInterface::validerTitre ()
{
  if (reqTitre ().isEmpty ())
    {
      QString messageTitreVide ("Le titre ne doit pas être vide.");
      QMessageBox::information (this, "TITRE MANQUANT", messageTitreVide);
      return true;
    }
  return false;
}


/**
 * \brief methode pour valider le nom de l'auteur.
 * \return Retourne vrai si le nom de l'auteur est invalide, faux sinon.
 */
bool
BiblioJournalInterface::validerAuteur ()
{
  QString qs = reqAuteur ();

  std::string nomAuteur = qs.toStdString ();

  if (!(util::validerFormatNom (nomAuteur)))
    {
      QString messageNomAuteurInvalide ("Le nom de l'auteur est invalide "
                                        "(sauf si c'est un enfant d'Elon Musk).");
      QMessageBox::information (this, "NOM INVALIDE", messageNomAuteurInvalide);
      return true;
    }
  return false;
}


/**
 * \brief methode pour valider le code ISSN.
 * \return Retourne vrai si le code ISSN est invalide, faux sinon.
 */
bool
BiblioJournalInterface::validerIssn ()
{
  QString qs = reqIssn ();

  std::string issn = qs.toStdString ();

  if (!(util::validerCodeIssn (issn)))
    {
      QString messageISSNInvalide ("Le code ISSN est invalide.");
      QMessageBox::information (this, "ISSN INVALIDE", messageISSNInvalide);
      return true;
    }
  return false;
}


/**
 * \brief methode pour valider le nom du journal.
 * \return Retourne vrai si le nom du journal est invalide, faux sinon.
 */
bool
BiblioJournalInterface::validerNomJournal ()
{
  QString qs = reqNomJournal ();

  std::string nomJournal = qs.toStdString ();

  if (!(util::validerCodeIssn (issn)))
    {
      QString messageNomJournalInvalide ("Veuillez entrer un nom de journal.");
      QMessageBox::information (this, "NOM JOURNAL VIDE", messageNomJournalInvalide);
      return true;
    }
  return false;
}


/**
 * \brief methode qui regroupe tous les validations a faire avant de
 * pouvoir confirmer l'ajout d'un journal.
 */
void
BiblioJournalInterface::validerEntrees ()
{
  if (validerTitre ())
    {
      return;
    };
  if (validerAuteur ())
    {
      return;
    };
  if (validerIssn ())
    {
      return;
    };
  if (validerNomJournal ())
    {
      return;
    };
  accept ();
}