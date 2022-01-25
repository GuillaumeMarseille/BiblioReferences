
/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#include "BiblioOuvrageInterface.h"
#include "validationFormat.h"
#include "Ouvrage.h"
#include "QMessageBox"


/**
 * \brief Constructeur de la classe BiblioOuvrageInterface.
 * \class BiblioOuvrageInterface
 */
BiblioOuvrageInterface::BiblioOuvrageInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe BiblioOuvrageInterface.
 */
BiblioOuvrageInterface::~BiblioOuvrageInterface () { }


/**
 * \brief Permet d'accceder au titre de la reference en lecture.
 * \return Retourne le titre de la reference.
 */
QString
BiblioOuvrageInterface::reqTitre ()const
{
  return widget.titreOuvrage->text ();
}


/**
 * \brief Permet d'accceder au nom de l'auteur de la reference en lecture.
 * \return Retourne le nom de l'auteur de la reference.
 */
QString
BiblioOuvrageInterface::reqAuteurs ()const
{
  return widget.auteurs->text ();
}


/**
 * \brief Permet d'accceder a l'annee d'edition de la reference en lecture.
 * \return Retourne l'annee d'edition  de la reference.
 */
int
BiblioOuvrageInterface::reqAnnee ()const
{
  return widget.annee->value ();
}


/**
 * \brief Permet d'accceder au code ISBN de l'ouvrage en lecture.
 * \return Retourne le code ISBN de l'ouvrage.
 */
QString
BiblioOuvrageInterface::reqIdentifiant ()const
{
  return widget.identifiant->text ();
}


/**
 * \brief Permet d'accceder au nom de l'editeur de l'ouvrage en lecture.
 * \return Retourne le nom de l'editeur de l'ouvrage.
 */
QString
BiblioOuvrageInterface::reqEditeur ()const
{
  return widget.editeur->text ();
}


/**
 * \brief Permet d'accceder a la ville d'edition de l'ouvrage en lecture.
 * \return Retourne la ville d'edition de l'ouvrage.
 */
QString
BiblioOuvrageInterface::reqVille ()const
{
  return widget.ville->text ();
}


/**
 * \brief methode pour valider le titre.
 * \return Retourne vrai si le titre est invalide, faux sinon.
 */
bool
BiblioOuvrageInterface::validerTitre ()
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
BiblioOuvrageInterface::validerAuteur ()
{
  QString qs = reqAuteurs ();

  std::string nomAuteur = qs.toStdString ();

  if (!(util::validerFormatNom (nomAuteur)))
    {
      QString messageNomAuteurInvalide ("Le nom de l'auteur est invalide ");
      QMessageBox::information (this, "NOM INVALIDE", messageNomAuteurInvalide);
      return true;
    }
  return false;
}


/**
 * \brief methode pour valider le code ISBN.
 * \return Retourne vrai si le code ISBN est invalide, faux sinon.
 */
bool
BiblioOuvrageInterface::validerIsbn ()
{
  QString qs = reqIdentifiant ();

  std::string isbn = qs.toStdString ();

  if (!(util::validerCodeIsbn (isbn)))
    {
      QString messageISBNInvalide ("Le code ISBN est invalide.");
      QMessageBox::information (this, "ISSN INVALIDE", messageISBNInvalide);
      return true;
    }
  return false;
}


/**
 * \brief methode pour valider le nom de l'editeur.
 * \return Retourne vrai si le nom de l'editeur est vide, faux sinon.
 */
bool
BiblioOuvrageInterface::validerEditeur ()
{
  QString qs = reqEditeur ();

  std::string editeur = qs.toStdString ();

  if (!(util::validerFormatNom (editeur)))
    {
      QString messageEditeurVide ("Le nom de l'éditeur n'est pas valide.");
      QMessageBox::information (this, "ÉDITEUR INVALIDE", messageEditeurVide);
      return true;
    }
  return false;
}


/**
 * \brief methode pour valider le nom de la ville d'edition.
 * \return Retourne vrai si le nom de la ville d'edition est vide, faux sinon.
 */
bool
BiblioOuvrageInterface::validerVille ()
{
  QString qs = reqVille ();

  std::string ville = qs.toStdString ();

  if (!(util::validerFormatNom (ville)))
    {
      QString messageVilleVide ("Le nom de la Ville est invalide.");
      QMessageBox::information (this, "VILLE INVALIDE", messageVilleVide);
      return true;
    }
  return false;
}


/**
 * \brief methode qui regroupe tous les validations a faire avant de
 * pouvoir confirmer l'ajout d'un ouvrage.
 */
void
BiblioOuvrageInterface::valideInfoOuvrage ()
{
  if (validerTitre ())
    {
      return;
    }
  if (validerAuteur ())
    {
      return;
    }
  if (reqAnnee () <= 0)
    {
      QString messageAnneeValide ("L'année doit être supérieur à 0.");
      QMessageBox::information (this, "ANNÉE INVALIDE", messageAnneeValide);
      return;
    }
  if (validerIsbn ())
    {
      return;
    }
  if (validerEditeur ())
    {
      return;
    }
  if (validerVille ())
    {
      return;
    }
  accept ();
}