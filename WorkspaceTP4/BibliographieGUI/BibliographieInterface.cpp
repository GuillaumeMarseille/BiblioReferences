/*
 * \file BiblioOuvrageInterface.cpp
 * \author: Guillaume Marseille et Vincent St-Pierre
 * \date on 6 décembre 2021, 10:49
 */

#include "BibliographieInterface.h"
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "BiblioOuvrageInterface.h"
#include "BiblioSupprimeInterface.h"
#include "BiblioJournalInterface.h"
#include "ReferenceException.h"
#include <QMessageBox>


using namespace biblio;
using namespace std;


/**
 * \brief Constructeur de la classe BibliographieInterface.
 * \class BibliographieInterface
 */
BibliographieInterface::BibliographieInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe BiblioJournalInterface.
 */
BibliographieInterface::~BibliographieInterface () { }


biblio::Bibliographie bibDepart ("Biblio1");


/**
 * \brief Methode qui gere l'ajout d'ouvrage.
 */
void
BibliographieInterface::dialogOuvrage ()
{
  BiblioOuvrageInterface Ouvrage;
  if (Ouvrage.exec ())
    {
      biblio::Ouvrage referenceOuvrage (Ouvrage.reqAuteurs ().toStdString (),
                                        Ouvrage.reqTitre ().toStdString (),
                                        Ouvrage.reqAnnee (),
                                        Ouvrage.reqIdentifiant ().toStdString (),
                                        Ouvrage.reqEditeur ().toStdString (),
                                        Ouvrage.reqVille ().toStdString ());
      try
        {
          bibDepart.ajouterReference (referenceOuvrage);
        }
      catch (ReferenceException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
        }

    }

  widget.affichage->setText (bibDepart.reqBibliographieFormate ().c_str ());
}


/**
 * \brief Methode qui gere la supression de references.
 */
void
BibliographieInterface::dialogSupprime ()
{
  BiblioSupprimeInterface Supprime;
  if (Supprime.exec ())
    {
      try
        {
          bibDepart.supprimerReference (Supprime.reqIdentifiant ().toStdString ());
        }
      catch (ReferenceException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
        }
    }
  widget.affichage->setText (bibDepart.reqBibliographieFormate ().c_str ());
}


/**
 * \brief Methode qui gere l'ajout de journal.
 */
void
BibliographieInterface::dialogJournal ()
{
  BiblioJournalInterface Journal;
  if (Journal.exec ())
    {
      {
        biblio::Journal referenceJournal (Journal.reqAuteur ().toStdString (),
                                          Journal.reqTitre ().toStdString (),
                                          Journal.reqAnnee (),
                                          Journal.reqIssn ().toStdString (),
                                          Journal.reqNomJournal ().toStdString (),
                                          Journal.reqVolume (),
                                          Journal.reqNumero (),
                                          Journal.reqPage ());
        try
          {
            bibDepart.ajouterReference (referenceJournal);
          }
        catch (ReferenceException& e)
          {
            QString message = (e.what ());
            QMessageBox::information (this, "ERREUR", message);
          }

      }
      widget.affichage->setText (bibDepart.reqBibliographieFormate ().c_str ());
    }
}