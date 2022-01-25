
/* *
 * \file:main.cpp
 * \brief Programme interactif minimaliste
 * pour interagir avec la classe Reference.
 * \author: Guillaume Marseille
 * \date 10 octobre 2021, 13:10
 */

#include <iostream>
#include <string>

using namespace std;
#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "Bibliographie.h"
#include "ReferenceException.h"


/*
 *
 */
int
main ()
{
  try
    {
      //*********TEST A EFFACER********

      biblio::Journal journalTest ("Hart", "A survey of source code management tools"
                                   " for programming courses", 2009, "ISSN 1937-4771",
                                   "Journal of Computing Sciences", 24, 6, 113);

      biblio::Ouvrage ouvrageTest ("Charles Talleyrand", "Livre chouette", 1789,
                                   "ISBN 978-0-545-01022-1", "Maison chouette", "Saigon");

      biblio::Bibliographie bibTest ("okidou");

      bibTest.ajouterReference (journalTest);
      bibTest.ajouterReference (ouvrageTest);
      bibTest.ajouterReference (ouvrageTest);
      bibTest.supprimerReference ("123");
      cout << bibTest.reqBibliographieFormate ();

      biblio::Bibliographie bibski ("test");

      bibski = bibTest;






      //*********TEST A EFFACER********

      //Attributs Ouvrage
      string auteurO;
      string titreO;
      int anneeO;
      string identifiantO;
      string editeur;
      string ville;

      //Attributs Journal
      string auteur;
      string titre;
      int annee;
      string identifiant;
      string nomJournal;
      int volume;
      int numero;
      int page;

      //Variables uilitaires
      char buffer[256];

      //Saisie des donnees pour l'ouvrage
      cout << "Bienvenue dans l'outil de gestion de references bibliographiques" << endl;
      cout << "================================================================" << endl;
      cout << "-------------------------------------------------------" << endl;
      cout << "Ajoutez un ouvrage" << endl;
      cout << "-------------------------------------------------------" << endl;

      do
        {
          cout << "Entrez un nom d'auteur valide: " << endl;

          cin.getline (buffer, 256);
          auteurO = buffer;
        }
      while (!util::validerFormatNom (auteurO));

      do
        {
          cout << "Entrez le tire de la reference: " << endl;
          cin.getline (buffer, 256);
          titreO = buffer;
        }
      while (titreO.empty ());

      do
        {
          cout << "Entrez la ville: " << endl;
          cin.getline (buffer, 256);
          ville = buffer;
        }
      while (!util::validerFormatNom (ville));

      do
        {
          cout << "Entrez la maison d'edition: " << endl;
          cin.getline (buffer, 256);
          editeur = buffer;
        }
      while (!util::validerFormatNom (editeur));

      do
        {
          cout << "Entrez l'annee d'edition: " << endl;
          cin >> anneeO;
          if (cin.fail ())
            {
              cin.clear ();
              cin.ignore ();
            }
        }
      while (anneeO < 1);

      cin.ignore ();

      do
        {
          cout << "Entrez l'identifiant valide de l'ouvrage (ISBN): " << endl;
          cin.getline (buffer, 256);
          identifiantO = buffer;
        }
      while (!util::validerCodeIsbn (identifiantO));






      //Saisie des donnees pour le Journal
      cout << "-------------------------------------------------------" << endl;
      cout << "Ajoutez une référence de type article de journal" << endl;
      cout << "-------------------------------------------------------" << endl;
      do
        {
          cout << "Entrez un nom d'auteur valide: " << endl;

          cin.getline (buffer, 256);
          auteur = buffer;
        }
      while (!util::validerFormatNom (auteur));

      do
        {
          cout << "Entrez le titre de la reference: " << endl;
          cin.getline (buffer, 256);
          titre = buffer;
        }
      while (titre.empty ());

      do
        {
          cout << "Entrez le nom de la revue dans laquelle a été publiée la référence : " << endl;
          cin.getline (buffer, 256);
          nomJournal = buffer;

        }
      while (nomJournal.empty ());

      cout << "Entrez le volume: " << endl;
      cin >> volume;
      cout << "Entrez le numero: " << endl;
      cin >> numero;
      cout << "Entrez la page où commence la référence : " << endl;
      cin >> page;

      cin.ignore ();

      do
        {
          cout << "Entrez l'annee d'edition: " << endl;
          cin >> annee;
          if (cin.fail ())
            {
              cin.clear ();
              cin.ignore ();
            }
        }
      while (annee < 1);

      cin.ignore ();

      do
        {
          cout << "Entrez l'identifiant valide du journal (ISSN): " << endl;
          cin.getline (buffer, 256);
          identifiant = buffer;
        }
      while (!util::validerCodeIssn (identifiant));

      cout << "Références bibliographiques enregistrées :" << endl;

      //Creation de la bibliographie et affichage

      biblio::Bibliographie bibExemple ("Bibliographie TP3");

      biblio::Ouvrage ouvrageExemple (auteurO, titreO, anneeO, identifiantO, editeur, ville);

      biblio::Journal journalExemple (auteur, titre, annee, identifiant, nomJournal, volume, numero, page);

      bibExemple.ajouterReference (ouvrageExemple);

      bibExemple.ajouterReference (journalExemple);

      cout << bibExemple.reqBibliographieFormate ();

    }

  catch (ContratException& e)
    {
      cout << e.reqTexteException () << endl;
    }
  catch (ReferenceException& e)
    {
      cout << e.what () << endl;
    }

  return 0;
}

