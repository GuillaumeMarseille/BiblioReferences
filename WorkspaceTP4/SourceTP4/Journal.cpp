
/* *
 * \file:   Journal.cpp
 * \class Journal
 * \brief
 * \author: Guillaume Marseille
 * \date 29 octobre 2021, 13:43
 */


#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>
using namespace std;

namespace biblio
{


  /**
   * \brief Constructeur de la classe Journal.
   *    Cette classe prend les parametres suivants:
   * \class Journal
   * \param[in] p_auteurs le nom de l'auteur de la reference.
   * \param[in] p_titre le titre de la reference.
   * \param[in] p_annee l'annee d'edition de la reference.
   * \param[in] p_identifiant le code ISSN du journal
   * \param[in] p_nomJournal le nom du journal.
   * \param[in] p_volume le volume du livre.
   * \param[in] p_numero le numero ou commence la reference dans le journal.
   * \param[in] p_page la page ou commence la reference dans le journal.
   * \pre p_identifiant doit etre un code ISSN valide. La fonction
   * util::validerCodeIssn () permet de verifier sa validite.
   * \pre p_nomJournal doit etre non vide la fonction
   * bool util::nonVide (const std::string & p_chaine) permet de le verifie.
   * \post l'objet construit a été initialisé à partir des valeurs passés en
   *  paramètres.
   */
  Journal::Journal (const std::string& p_auteurs,
                    const std::string& p_titre,
                    const int p_annee,
                    const std::string& p_identifiant,
                    const std::string& p_nomJournal,
                    const int p_volume,
                    const int p_numero,
                    const int p_page) :
  Reference::Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_identifiant (p_identifiant),
  m_nomJournal (p_nomJournal),
  m_volume (p_volume),
  m_numero (p_numero),
  m_page (p_page)
  {
    PRECONDITION (util::validerCodeIssn (p_identifiant));
    PRECONDITION (util::nonVide (p_nomJournal));

    POSTCONDITION (reqIdentifiant () == m_identifiant);
    POSTCONDITION (reqNomJournal () == m_nomJournal);
    POSTCONDITION (reqVolume () == m_volume);
    POSTCONDITION (reqNumero () == m_numero);
    POSTCONDITION (reqPage () == m_page);

    INVARIANTS ();
  }


  /**
   * \brief Permet d'accceder a l'attribut m_nomJournal en lecture.
   * \return Retourne le nom du journal.
   */
  string
  Journal::reqNomJournal () const
  {
    return m_nomJournal;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_volume en lecture.
   * \return Retourne le volume du journal.
   */
  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_numero en lecture.
   * \return Retourne le numero ou commence la reference dans le journal.
   */
  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_page en lecture.
   * \return Retourne la page ou commence la reference dans le journal.
   */
  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /**
   * \brief Permet d'accceder a l'attribut m_identifiant en lecture.
   * \return Retourne l'idendifiant du journal.
   */
  string
  Journal::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Methode augmentee de la classe Reference.
   *
   * Permet d'accceder aux l'attributs m_nomJournal,
   * m_volume, m_numero, m_page et m_identifiant  et aux attributs
   * m_auteur, m_titre et m_annee, en lecture.
   *
   * \return Retourne une chaine de caracteres formate contenant tous les
   * attributs d'un journal.
   */
  string
  Journal::reqReferenceFormate () const
  {
    ostringstream os_freq_format;

    os_freq_format
            << reqAuteurs () << ". "
            << reqTitre () << ". "
            << reqNomJournal () << ", vol. "
            << reqVolume () << ", no. "
            << reqNumero () << ", pp. "
            << reqPage () << ", "
            << reqAnnee () << ". "
            << reqIdentifiant () << ".";

    return os_freq_format.str ();
  }


  /**
   * \brief Teste les invariants de la classe Journal.
   */
  void
  Journal::verifieInvariant () const
  {
    INVARIANT (util::validerCodeIssn (m_identifiant));
    INVARIANT (util::nonVide (m_nomJournal));
  }


  /**
   * \brief Permet de faire une copie allouée sur le monceau de l'objet courant.
   */
  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }
}