/**
 * \file BibliographieTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Bibliographie
 * \author Guillaume Marseille
 * \version 0.1
 * \date 2021-10-31
 */


#include <gtest/gtest.h>
#include "ContratException.h"
#include "Bibliographie.h"
#include "Reference.h"
#include "Journal.h"
#include "Ouvrage.h"
#include "ReferenceException.h"
#include <sstream>
using namespace biblio;
using namespace std;


/**
 * \brief Test du constructeur avec paramètres de
Bibliographie::Bibliographie (const string &p_nomBibliographie)
 *
 *        cas valide :
 *          Création d'une bibliographie valide : ParametresValides
 *
 *        cas invalides :
 *          Aucun.
 */



TEST (Bibliographie, ParametresConstructeurValides)
{
  Bibliographie bibTest ("Biblio cool");

  ostringstream os_biblio_format;
  os_biblio_format
          << bibTest.reqNomBibliographie () << endl;
  os_biblio_format << "===============================" << endl;

  ASSERT_EQ (os_biblio_format.str (), bibTest.reqBibliographieFormate ());
}

// Test de reqNomBibliographie


TEST (Bibliographie, reqNomBibliographie)
{
  Bibliographie bibTest ("Biblio cool");
  ASSERT_EQ ("Biblio cool", bibTest.reqNomBibliographie ());
}
//Fixture pour les test sur biblio

class BiblioFixture : public ::testing::Test
{

public:


  BiblioFixture () :
  f_bibFixture ("bibFix") { };


  Bibliographie f_bibFixture;
} ;

Journal
journalTest ("Hart", "A survey of source code management tools"
             " for programming courses", 2009, "ISSN 1937-4771",
             "Journal of Computing Sciences", 24, 6, 113);

//Test de ajouterReference


TEST_F (BiblioFixture, ajouterReference)
{
  f_bibFixture.ajouterReference (journalTest);

  ostringstream testAjouter;
  testAjouter << "bibFix" << endl;
  testAjouter << "===============================" << endl;
  testAjouter << "[1] Hart. A survey of source code management tools for "
          "programming courses. Journal of Computing Sciences, vol. 24, no. 6, "
          "pp. 113, 2009. ISSN 1937-4771." << endl;

  ASSERT_EQ (testAjouter.str (), f_bibFixture.reqBibliographieFormate ());

}

//Test de ajouterReference avec une reference deja presente.


TEST_F (BiblioFixture, ajouterReferenceDejaPresente)
{
  f_bibFixture.ajouterReference (journalTest);
  ASSERT_THROW (f_bibFixture.ajouterReference (journalTest),
                ReferenceDejaPresenteException);
}

//Test de supprimerReference


TEST_F (BiblioFixture, supprimerReference)
{
  f_bibFixture.ajouterReference (journalTest);
  f_bibFixture.supprimerReference ("ISSN 1937-4771");

  ASSERT_EQ (f_bibFixture.reqBibliographieFormate (),
             "bibFix\n===============================\n");
}

//Test de supprimerReference lorsque la reference n'existe pas


TEST_F (BiblioFixture, supprimerReferenceAbsente)
{
  f_bibFixture.ajouterReference (journalTest);

  ASSERT_THROW (f_bibFixture.supprimerReference ("ISSN 1337-4242"), ReferenceAbsenteException);
}
//Test de reqBibliographieFormate
Ouvrage ouvrageTest ("Charles Talleyrand", "Livre chouette", 1789,
                     "ISBN 978-0-545-01022-1", "Maison chouette", "Saigon");


TEST_F (BiblioFixture, reqBibliographieFormate)
{
  f_bibFixture.ajouterReference (journalTest);
  f_bibFixture.ajouterReference (ouvrageTest);

  ostringstream testFormat;
  testFormat << "bibFix" << endl;
  testFormat << "===============================" << endl;
  testFormat << "[1] Hart. A survey of source code management tools for "
          "programming courses. Journal of Computing Sciences, vol. 24, no. 6, "
          "pp. 113, 2009. ISSN 1937-4771." << endl;
  testFormat << "[2] Charles Talleyrand. Livre chouette. Saigon : "
          "Maison chouette, 1789. ISBN 978-0-545-01022-1." << endl;

  ASSERT_EQ (testFormat.str (), f_bibFixture.reqBibliographieFormate ());

}

//Test du constructeur de copies profondes de Bibliographie


TEST_F (BiblioFixture, copieProfondeBiblio)
{
  f_bibFixture.ajouterReference (journalTest);
  f_bibFixture.ajouterReference (ouvrageTest);

  Bibliographie bibCopie (f_bibFixture);

  ASSERT_EQ (f_bibFixture.reqBibliographieFormate (),
             bibCopie.reqBibliographieFormate ());
}

//Fixture de 3 biblio

class TroisBiblio : public ::testing::Test
{

public:


  TroisBiblio () :
  f_bibFixture1 ("bibFix1"),
  f_bibFixture2 ("bibFix2"),
  f_bibFixture3 ("bibFix3") { }
  ;

  Bibliographie f_bibFixture1;
  Bibliographie f_bibFixture2;
  Bibliographie f_bibFixture3;
} ;
//Test de l'operateur d'assignation de Bibliographie avec 2 biblio


TEST_F (TroisBiblio, operateur2Assignation)
{
  f_bibFixture1.ajouterReference (journalTest);
  f_bibFixture2.ajouterReference (ouvrageTest);

  f_bibFixture2 = f_bibFixture1;

  ASSERT_EQ (f_bibFixture1.reqBibliographieFormate (),
             f_bibFixture2.reqBibliographieFormate ());
}

//Test de l'operateur d'assignation de Bibliographie avec 3 biblio


TEST_F (TroisBiblio, operateur3Assignation)
{
  f_bibFixture1.ajouterReference (journalTest);
  f_bibFixture2.ajouterReference (ouvrageTest);
  f_bibFixture3;

  f_bibFixture3 = f_bibFixture2 = f_bibFixture1;

  ASSERT_EQ (f_bibFixture1.reqBibliographieFormate (),
             f_bibFixture3.reqBibliographieFormate ());
}