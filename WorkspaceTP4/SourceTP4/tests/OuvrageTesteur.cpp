/**
 * \file OuvrageTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Ouvrage
 * \author Guillaume Marseille
 * \version 0.1
 * \date 2021-10-31
 */


#include <gtest/gtest.h>
#include "Ouvrage.h"
#include "ContratException.h"
using namespace biblio;


/**
 * \brief Test du constructeur avec paramètres de
 * Ouvrage::Ouvrage (const string& p_auteurs,
 *                   const string& p_titre,
 *                   const int& p_annee,
 *                   const string& p_identifiant,
 *                   const string& p_editeur,
 *                   const string& p_ville)
 *
 *        cas valide :
 *          Création d'un ouvrage valide : ParametresValides
 *
 *        cas invalides :
 *        	editeur invalide : ParametreEditeurInvalide,
 *        	ville invalide : ParametreVilleInvalide,
 *        	identidiant (ISBN) invalide : ParametreIdentifiantInvalide
 */

TEST (Ouvrage, ParametresValides)
{
  Ouvrage ouvrageTest ("Charles Talleyrand", "Livre chouette", 1789,
                       "ISBN 978-0-545-01022-1", "Maison chouette", "Saigon");
  ASSERT_EQ ("Maison chouette", ouvrageTest.reqEditeur ());
  ASSERT_EQ ("Saigon", ouvrageTest.reqVille ());
  ASSERT_EQ ("ISBN 978-0-545-01022-1", ouvrageTest.reqIdentifiant ());
}

// editeur invalide


TEST (Ouvrage, ParametreEditeurInvalide)
{

  ASSERT_THROW (Ouvrage o1 ("Charles Talleyrand", "Livre chouette",
                            1789, "ISBN 978-0-545-01022-1", "Maison -chouette",
                            "Saigon"), PreconditionException);
}

// ville invalide


TEST (Ouvrage, ParametreVilleInvalide)
{

  ASSERT_THROW (Ouvrage o2 ("Charles Talleyrand", "Livre chouette",
                            1789, "ISBN 978-0-545-01022-1", "Maison chouette",
                            "Ho  Chi  Minh"), PreconditionException);
}

// identifiant invalide


TEST (Ouvrage, ParametreIdentifiantInvalide)
{

  ASSERT_THROW (Ouvrage o2 ("Charles Talleyrand", "Livre chouette",
                            1789, "ISSN 1467-8640", "Maison chouette",
                            "Saigon"), PreconditionException);
}

/**
 * \class OuvrageFixture
 * \brief Fixture pour les tests sur un Ouvrage
 */

class OuvrageFixture : public ::testing::Test
{

public:


  OuvrageFixture () :
  f_ouvrageTest ("Charles Talleyrand", "Livre chouette",
                 1789, "ISBN 978-0-545-01022-1", "Maison chouette",
                 "Saigon") { }
  ;

  Ouvrage f_ouvrageTest;
} ;


/**
 * \brief Test de la méthode string Ouvrage::reqEditeur () const
 *  cas valide reqEditeur: Création d'ouvrage valide et test de l'editeur.
 *  cas invalide Aucun d'identifié
 */
TEST_F (OuvrageFixture, reqEditeur)
{
  ASSERT_EQ ("Maison chouette", f_ouvrageTest.reqEditeur ());
}


/**
 * \brief Test de la méthode string Ouvrage::reqVille () const
 *  cas valide reqVille: Création d'ouvrage valide et test de la ville.
 *  cas invalide Aucun d'identifié
 */
TEST_F (OuvrageFixture, reqVille)
{
  ASSERT_EQ ("Saigon", f_ouvrageTest.reqVille ());
}


/**
 * \brief Test de la méthode string Ouvrage::reqIdentifiant () const
 *  cas valide reqIdentifiant: Création d'ouvrage valide et test de l'identifiant
 *  cas invalide Aucun d'identifié
 */
TEST_F (OuvrageFixture, reqIdentifiant)
{
  ASSERT_EQ ("ISBN 978-0-545-01022-1", f_ouvrageTest.reqIdentifiant ());
}


/**
 * \brief Test de la méthode string Ouvrage::reqReferenceFormate () const
 *  cas valide reqReferenceFormate: Création d'ouvrage valide et test de
 *  l'ouvrage  formate.
 *  cas invalide Aucun d'identifié
 */
TEST_F (OuvrageFixture, reqReferenceFormate)
{
  ASSERT_EQ ("Charles Talleyrand. Livre chouette. Saigon : "
             "Maison chouette, 1789. ISBN 978-0-545-01022-1.",
             f_ouvrageTest.reqReferenceFormate ());
}


/**
 * \brief Test de la méthode string Ouvrage::clone () const
 *  cas valide cloneValide: Création d'un clone d'ouvrage valide et test
 *  de ses attributs.
 *  cas invalide Aucun d'identifié
 */
TEST_F (OuvrageFixture, cloneValide)
{
  Reference* monClone = f_ouvrageTest.clone ();

  Ouvrage* monOuvrage = dynamic_cast <Ouvrage*> (monClone);

  EXPECT_EQ (monOuvrage->reqAuteurs (), f_ouvrageTest.reqAuteurs ()) ;
  EXPECT_EQ (monOuvrage->reqTitre (), f_ouvrageTest.reqTitre ()) ;
  EXPECT_EQ (monOuvrage->reqAnnee (), f_ouvrageTest.reqAnnee ()) ;
  EXPECT_EQ (monOuvrage->reqIdentifiant (), f_ouvrageTest.reqIdentifiant ()) ;
  EXPECT_EQ (monOuvrage->reqEditeur (), f_ouvrageTest.reqEditeur ());
  EXPECT_EQ (monOuvrage->reqVille (), f_ouvrageTest.reqVille ());

  delete monClone ;

}