

/* *
 * \file:   Ouvrage.cpp
 * \class Ouvrage
 * \brief
 * \author: Guillaume Marseille
 * \date 29 octobre 2021, 11:58
 */



#include "ContratException.h"
#include "validationFormat.h"
#include "Ouvrage.h"
#include <sstream>
using namespace std;

namespace biblio
{


  /**
   * \brief Constructeur de la classe Ouvrage.
   *    Cette classe prend les parametres suivants:
   * \param[in] p_auteurs le nom de l'auteur de la reference.
   * \param[in] p_titre le titre de la reference.
   * \param[in] p_annee l'annee d'edition de la reference.
   * \param[in] p_editeur le nom de l'editeur de l'ouvrage.
   * \param[in] p_ville le nom de la ville d'edition de l'ouvrage.
   * \param[in] p_identifiant le code ISBN de l'ouvrage et de la reference.
   * \pre p_editeur et p_ville doivent etre des noms valides. La fonction
   * util::validerFormatNom() permet de verifier leur validite.
   * \pre p_identifiant doit etre un code ISBN valide. La fonction
   * util::validerCodeIsbn () permet de verifier sa validite.
   * \post l'objet construit a été initialisé à partir
   * des valeurs passés en paramètres.
   */
  Ouvrage::Ouvrage (const string& p_auteurs,
                    const string& p_titre,
                    const int p_annee,
                    const string& p_identifiant,
                    const string& p_editeur,
                    const string& p_ville) :
  Reference::Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_identifiant (p_identifiant),
  m_editeur (p_editeur),
  m_ville (p_ville)

  {
    PRECONDITION (util::validerFormatNom (p_editeur));
    PRECONDITION (util::validerFormatNom (p_ville));
    PRECONDITION (util::validerCodeIsbn (p_identifiant));

    POSTCONDITION (reqEditeur () == m_editeur);
    POSTCONDITION (reqVille () == m_ville);
    POSTCONDITION (reqIdentifiant () == m_identifiant);

    INVARIANTS ();
  }


  /**
   * \brief Permet d'accceder a l'attribut m_editeur en lecture.
   * \return Retourne le nom de l'editeur.
   */
  string
  Ouvrage::reqEditeur () const
  {
    return m_editeur;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_ville en lecture.
   * \return Retourne le nom de la ville.
   */
  string
  Ouvrage::reqVille () const
  {
    return m_ville;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_identifiant en lecture.
   * \return Retourne l'idendifiant de l'ouvrage.
   */
  string
  Ouvrage::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Augmente la meme methode de la classe mere.
   * Permet d'accceder aux attributs m_editeur,
   * m_ville et m_identifiant en lecture et de formater une chaine de
   * caracteres contenant ces attributs, precedes de ceux de de la
   * methode Reference::reqReferenceFormate () const.
   * \return Retourne Reference::reqReferenceFormate () const
   *  suivi de la ville d'edition, l'editeur, l'annee d'edition
   * et le code ISBN, en string.
   */
  string
  Ouvrage::reqReferenceFormate () const
  {
    ostringstream os_freq_format;

    os_freq_format
            << Reference::reqReferenceFormate ()
            << reqVille ()
            << " : "
            << reqEditeur ()
            << ", "
            << Reference::reqAnnee ()
            << ". "
            << reqIdentifiant ()
            << ".";

    return os_freq_format.str ();
  }


  /**
   * \brief Teste les invariants de la classe Ouvrage. Donc s'assure que
   * tous les attributs sont valides.
   */
  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (util::validerFormatNom (m_editeur));
    INVARIANT (util::validerFormatNom (m_ville));
    INVARIANT (util::validerCodeIsbn (m_identifiant));
  }


  /**
   * \brief Permet de faire une copie allouée sur le monceau de l'objet courant.
   */
  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this);
  }
}