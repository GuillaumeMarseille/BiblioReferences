/**
 * \file JournalTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Journal
 * \author Guillaume Marseille
 * \version 0.1
 * \date 2021-10-31
 */


#include <gtest/gtest.h>
#include "Journal.h"
#include "ContratException.h"
using namespace biblio;


/**
 * \brief Test du constructeur avec paramètres de
 *Journal::Journal (const std::string& p_auteurs,
 *                  const std::string& p_titre,
 *                  const int p_annee,
 *                  const std::string& p_identifiant,
 *                  const std::string& p_nomJournal,
 *                  const int p_volume,
 *                  const int p_numero,
 *                  const int p_page)
 *
 *        cas valide :
 *          Création d'un journal valide : ParametresValides
 *
 *        cas invalides :
 *        	nom de journal invalide : ParametreNomJournalInvalide,
 *        	identidiant (ISSN) invalide : ParametreIdentifiantInvalide
 */

TEST (Journal, ParametresValides)
{
  Journal journalTest ("Hart", "A survey of source code management tools"
                       " for programming courses", 2009, "ISSN 1937-4771",
                       "Journal of Computing Sciences", 24, 6, 113);
  ASSERT_EQ ("Hart. A survey of source code management tools for programming "
             "courses. Journal of Computing Sciences, vol. 24, no. 6, pp. 113, "
             "2009. ISSN 1937-4771.", journalTest.reqReferenceFormate ());
}

// nom de journal invalide (vide)


TEST (Jounral, ParametreNomJournalInvalide)
{

  ASSERT_THROW (Journal j1 ("Hart", "A survey of source code management tools"
                            " for programming courses", 2009, "ISSN 1937-4771",
                            "", 24, 6, 113),
                PreconditionException);
}

// identifiant invalide


TEST (Jounral, ParametreIdentifiantInvalide)
{

  ASSERT_THROW (Journal j2 ("Hart", "A survey of source code management tools"
                            " for programming courses", 2009, "ISBN 1937-4771",
                            "Journal of Computing Sciences", 24, 6, 113),
                PreconditionException);
}

/**
 * \class JournalFixture
 * \brief Fixture pour les tests sur un Journal
 */

class JournalFixture : public ::testing::Test
{

public:


  JournalFixture () :
  f_journalTest ("Hart", "A survey of source code management tools"
                 " for programming courses", 2009, "ISSN 1937-4771",
                 "Journal of Computing Sciences", 24, 6, 113) { }
  ;

  Journal f_journalTest;
} ;


/**
 * \brief Test de la methode string Journal::reqNomJournal () const
 *  cas valide reqNomJournal: Création d'un journal valide et test du nom du
 * journal.
 *  cas invalide Aucun d'identifie
 */
TEST_F (JournalFixture, reqNomJournal)
{
  ASSERT_EQ ("Journal of Computing Sciences", f_journalTest.reqNomJournal ());
}


/**
 * \brief Test de la methode string Journal::reqVolume () const
 *  cas valide reqVolume: Création d'un journal valide et test du volume.
 *  cas invalide Aucun d'identifie
 */
TEST_F (JournalFixture, reqVolume)
{
  ASSERT_EQ (24, f_journalTest.reqVolume ());
}


/**
 * \brief Test de la methode string Journal::reqNumero () const
 *  cas valide reqNumero: Création d'un journal valide et test du numero.
 *  cas invalide Aucun d'identifie
 */
TEST_F (JournalFixture, reqNumero)
{
  ASSERT_EQ (6, f_journalTest.reqNumero ());
}


/**
 * \brief Test de la methode string Journal::reqPage () const
 *  cas valide reqPage: Création d'un journal valide et test de la page.
 *  cas invalide Aucun d'identifie
 */
TEST_F (JournalFixture, reqPage)
{
  ASSERT_EQ (113, f_journalTest.reqPage ());
}


/**
 * \brief Test de la méthode string Journal::reqIdentifiant () const
 *  cas valide reqIdentifiant: Création d'un journal valide et test de
 * l'identifiant
 *  cas invalide Aucun d'identifié
 */
TEST_F (JournalFixture, reqIdentifiant)
{
  ASSERT_EQ ("ISSN 1937-4771", f_journalTest.reqIdentifiant ());
}


/**
 * \brief Test de la méthode string Journal::reqReferenceFormate () const
 *  cas valide reqReferenceFormate: Création d'un journal valide et test
 *  du journal  formate.
 *  cas invalide Aucun d'identifié
 */
TEST_F (JournalFixture, reqReferenceFormate)
{
  ASSERT_EQ ("Hart. A survey of source code management tools for programming "
             "courses. Journal of Computing Sciences, vol. 24, no. 6, pp. 113, "
             "2009. ISSN 1937-4771.",
             f_journalTest.reqReferenceFormate ());
}


/**
 * \brief Test de la méthode string Journal::clone () const
 *  cas valide cloneValide: Création d'un clone de journal valide et test
 *  des attributs.
 *  cas invalide Aucun d'identifié
 */
TEST_F (JournalFixture, cloneValide)
{
  Reference* monClone = f_journalTest.clone ();

  Journal* monJournal = dynamic_cast <Journal*> (monClone);

  EXPECT_EQ (monJournal->reqAuteurs (), f_journalTest.reqAuteurs ()) ;
  EXPECT_EQ (monJournal->reqTitre (), f_journalTest.reqTitre ()) ;
  EXPECT_EQ (monJournal->reqAnnee (), f_journalTest.reqAnnee ()) ;
  EXPECT_EQ (monJournal->reqIdentifiant (), f_journalTest.reqIdentifiant ()) ;
  EXPECT_EQ (monJournal->reqNomJournal (), f_journalTest.reqNomJournal ());
  EXPECT_EQ (monJournal->reqVolume (), f_journalTest.reqVolume ());
  EXPECT_EQ (monJournal->reqNumero (), f_journalTest.reqNumero ());
  EXPECT_EQ (monJournal->reqPage (), f_journalTest.reqPage ());

  delete monClone ;

}