
/* *
 * \file: Reference.cpp
 * \brief Ce fichier contient l'implantation du constructeur de la classe
 *      Reference ainsi que celle de ses methodes.
 * \author: Guillaume Marseille.
 *  * \version 1.0
 * \date 2 octobre 2021, 15:29
 */


#include "Reference.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <sstream>
using namespace std;
namespace biblio
{


  /**
   * \brief Constructeur de la classe Reference.
   *    Cette classe prend les parametres suivants:
   * \class Reference
   * \param[in] p_auteurs l'auteur du livre
   * \param[in] p_titre le titre du livre
   * \param[in] p_annee l'annee d'edition
   * \param[in] p_identifiant le code (ISBN ou ISSN) du livre
   * \pre p_auteurs, p_titre, p_annee et p_identifiant doivent etre valides, tel
   * que decrit par les invariants dans le prototype de la classe.
   * \post l'objet construit a été initialisé à partir des valeurs passés en
   *  paramètres
   */

  Reference::Reference (const string& p_auteurs,
                        const string& p_titre,
                        const int p_annee,
                        const string& p_identifiant) :
  m_auteurs (p_auteurs), m_titre (p_titre),
  m_annee (p_annee), m_identifiant (p_identifiant)
  {
    PRECONDITION (util::validerFormatNom (p_auteurs));
    PRECONDITION (util::nonVide (p_titre));
    PRECONDITION (util::superieurAZero (p_annee));
    PRECONDITION (util::validerIssnOuIsbn (p_identifiant));

    POSTCONDITION (reqAuteurs () == m_auteurs);
    POSTCONDITION (reqTitre () == m_titre);
    POSTCONDITION (reqAnnee () == m_annee);
    POSTCONDITION (reqIdentifiant () == m_identifiant);

    INVARIANTS ();
  }


  /**
   * \brief Permet d'accceder a l'attribut m_auteurs en lecture.
   * \return Retourne le nom de l'auteur.
   */
  string
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_titre en lecture.
   * \return Retourne le titre du livre.
   */
  string
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_annee en lecture.
   * \return Retourne l'annee d'edition.
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_identifiant en lecture.
   * \return Retourne l'idendifiant du livre.
   */
  string
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Permet d'accceder aux l'attributs m_titre,
   *     m_annee et m_identifiant en lecture.
   * \return Retourne le titre du livre, l'annee d'edition
   *    et l'idendifiant du livre en string.
   */
  string
  Reference::reqReferenceFormate () const
  {
    ostringstream os_freq_format;

    os_freq_format
            << Reference::reqAuteurs ()
            << ". "
            << Reference::reqTitre () << ". ";

    return os_freq_format.str ();
  }


  /**
   * \brief Assigne une annee d'edition a l'objet courant.
   * \param[in] p_annee est une entier qui represente l'annee d'edition du livre.
   * \pre p_annee doit etre superieur a 0.
   * \post l'objet courant a été correctement assigne.
   */
  void
  Reference::asgAnnee (int p_annee)
  {
    PRECONDITION (util::superieurAZero (p_annee));

    m_annee = p_annee;

    POSTCONDITION (reqAnnee () == m_annee);
    INVARIANTS ();
  }


  /**
   * \brief surcharge de l'operateur ==
   * \param[in] p_reference a comparer a la reference courante.
   * \return un booleen indiquant si les deux references sont egales
   *        ou non en comparant chaque attribut de la classe.
   */
  bool Reference::operator== (const Reference & p_reference) const
  {
    return m_auteurs == p_reference.m_auteurs
            && m_titre == p_reference.m_titre
            && m_annee == p_reference.m_annee
            && m_identifiant == p_reference.m_identifiant;
  }


  /**
   * \brief Teste les invariants de la classe Reference. Donc s'assure que
   * tous les attributs sont valides.
   */
  void
  Reference::verifieInvariant () const
  {
    INVARIANT (util::validerFormatNom (m_auteurs));
    INVARIANT (util::nonVide (m_titre));
    INVARIANT (util::superieurAZero (m_annee));
    INVARIANT (util::validerIssnOuIsbn (m_identifiant));
  }
}