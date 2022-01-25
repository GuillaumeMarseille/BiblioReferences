/**
 * \file ReferenceTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Reference
 * \author Guillaume Marseille
 * \version 0.1
 * \date 2021-10-31
 */


#include <gtest/gtest.h>
#include "Reference.h"
#include "ContratException.h"
using namespace biblio;

/**
 * \class ReferenceDerivee
 *
 * \Brief Cette classe sert seulement à tester certaines méthodes de notre
 * classe abstraite Reference.
 * <p>
 * On va donc "implémenter" les deux méthodes virtuelles pures de Reference
 * afin d'avoir une classe instantiable.
 *
 */
class ReferenceDerivee : public Reference
{

public:


  ReferenceDerivee (const std::string& p_auteurs,
                    const std::string& p_titre,
                    const int& p_annee,
                    const std::string& p_identifiant) :
  Reference (p_auteurs, p_titre, p_annee, p_identifiant) { }


  std::string
  reqReferenceFormate () const override
  {
    return Reference::reqReferenceFormate () ;
  }


  Reference*
  clone () const override
  {
    return nullptr ;
  }
} ;


/**
 * \brief Test du constructeur avec paramètres de Reference::Reference
 * (const string& p_auteurs, const string& p_titre,
 *                     const int& p_annee, const string& p_identifiant)
 *
 *        cas valide :
 *          Création d'une reference valide : ParametresValides
 *
 *        cas invalides :
 *        	auteur invalide : ParametreAuteurInvalide,
 *        	tire invalide : ParametreTitreInvalide,
 *        	annee invalide : ParametreAnneeInvalide,
 *        	identidiant (ISSN ou ISBN) invalide : ParametreIdentifiantInvalide
 */

TEST (ReferenceDerivee, ParametresValides)
{
  ReferenceDerivee referenceTest ("Charles Talleyrand", "Livre chouette", 1789, "ISSN 1467-8640");
  ASSERT_EQ ("Charles Talleyrand", referenceTest.reqAuteurs ());
  ASSERT_EQ ("Livre chouette", referenceTest.reqTitre ());
  ASSERT_EQ (1789, referenceTest.reqAnnee ());
  ASSERT_EQ ("ISSN 1467-8640", referenceTest.reqIdentifiant ());
}

// auteur invalide


TEST (ReferenceDerivee, ParametreAuteurInvalide)
{

  ASSERT_THROW (ReferenceDerivee r1 ("Charles--Talleyrand", "Livre chouette",
                                     1789, "ISSN 1467-8640"), PreconditionException);
}
// titre invalide


TEST (ReferenceDerivee, ParametreTitreInvalide)
{
  ASSERT_THROW (ReferenceDerivee r2 ("Charles Talleyrand", "",
                                     1789, "ISSN 1467-8640"), PreconditionException);
}
// annee invalide


TEST (ReferenceDerivee, ParametreAnneeInvalide)
{
  ASSERT_THROW (ReferenceDerivee r3 ("Charles Talleyrand", "Livre chouette",
                                     -1789, "ISSN 1467-8640"), PreconditionException);
}
// identifiant invalide


TEST (ReferenceDerivee, ParametreIdentifiantInvalide)
{
  ASSERT_THROW (ReferenceDerivee r4 ("Charles Talleyrand", "Livre chouette",
                                     1789, "ISSN 1467-8645"), PreconditionException);

}

/**
 * \class ReferenceStringStringIntString
 * \brief Fixture pour les tests sur une Reference
 */

class ReferenceStringStringIntString : public ::testing::Test
{

public:


  ReferenceStringStringIntString () :
  f_referenceTest ("Scott Lynch", "The Lies of Locke Lamora", 2006,
                   "ISBN 978-0-306-40615-7") { }
  ;

  ReferenceDerivee f_referenceTest;
} ;


/**
 * \brief Test de la méthode void Reference::asgAnnee (int p_annee)
 *     	cas valide
 *     		AsgAnneeValide: Assigner une annee valide.
 *   	cas invalide
 *        	AsgAnneeZero : annee = 0
 *              AsgAnneNegative : annee negative
 */

//Annee valide


TEST_F (ReferenceStringStringIntString, AsgAnneeValide)
{
  f_referenceTest.asgAnnee (2001);
  ASSERT_EQ (2001, f_referenceTest.reqAnnee ());
}

//Annee invalide a 0


TEST_F (ReferenceStringStringIntString, AsgAnneeZero)
{
  ASSERT_THROW (f_referenceTest.asgAnnee (0), PreconditionException);
}

//Annee invalide car negative


TEST_F (ReferenceStringStringIntString, AsgAnneNegative)
{
  ASSERT_THROW (f_referenceTest.asgAnnee (-123), PreconditionException);
}


/**
 * \brief Test de la méthode string Reference::reqAuteurs () const
 *  cas valide reqAuteurs: Création reference valide connue et test de l'auteur.
 *  cas invalide Aucun d'identifié
 */
TEST_F (ReferenceStringStringIntString, reqAuteurs)
{
  ASSERT_EQ ("Scott Lynch", f_referenceTest.reqAuteurs ());
}


/**
 * \brief Test de la méthode string Reference::reqTitre () const
 *  cas valide reqTitre: Création reference valide connue et test du titre.
 *  cas invalide Aucun d'identifié
 */
TEST_F (ReferenceStringStringIntString, reqTitre)
{
  ASSERT_EQ ("The Lies of Locke Lamora", f_referenceTest.reqTitre ());
}


/**
 * \brief Test de la méthode int Reference::reqAnnee () const
 *  cas valide reqAnnee: Création reference valide connue et test de l'annee.
 *  cas invalide Aucun d'identifié
 */
TEST_F (ReferenceStringStringIntString, reqAnnee)
{
  ASSERT_EQ (2006, f_referenceTest.reqAnnee ());
}


/**
 * \brief Test de la méthode string Reference::reqReferenceFormate () const
 *  cas valide reqReferenceFormate: Création reference valide connue et test de
 *  la reference formate.
 *  cas invalide Aucun d'identifié
 */
TEST_F (ReferenceStringStringIntString, reqReferenceFormate)
{
  ASSERT_EQ ("Scott Lynch. The Lies of Locke Lamora. ", f_referenceTest.reqReferenceFormate ());
}

/**
 * \class DeuxReferences
 * \brief Fixture pour les comparaisons sur deux references.
 */

class DeuxReferences : public ::testing::Test
{

public:


  DeuxReferences () :
  f_referenceTest1 ("Scott Lynch", "The Lies of Locke Lamora", 2006,
                    "ISBN 978-0-306-40615-7"),
  f_referenceTest2 ("Robert Paulson", "Le livre", 1983, "ISSN 1467-8640") { }
  ;

  ReferenceDerivee f_referenceTest1;
  ReferenceDerivee f_referenceTest2;
} ;


/**
 * \brief  Test de la méthode bool Reference::operator== (const Reference &p_reference) const
 *        cas valide:
 *   		OperatorEgalEgalVrai1: 	References indentique à elle-même.
 *              OperatorEgalEgalVrai2: 	References indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Refenreces différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F (DeuxReferences, OperatorEgalEgalVrai1)
{
  ASSERT_EQ (f_referenceTest1, f_referenceTest1);
}


TEST_F (DeuxReferences, OperatorEgalEgalVrai2)
{
  ASSERT_TRUE (f_referenceTest1 == f_referenceTest1);
}


TEST_F (DeuxReferences, OperatorEgalEgalFaux)
{
  ASSERT_FALSE (f_referenceTest1 == f_referenceTest2);
}