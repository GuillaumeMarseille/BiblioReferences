/**
 * \file Journal.h
 * \brief Prototype de la classe Journal.
 * \author Guillaume Marseille.
 * \version 1.0
 * \date 12 novembre 2021
 */

#ifndef JOURNAL_H
#define JOURNAL_H
#include <string>
#include "Reference.h"
/**
 * \class Journal
 * \brief Classe permettant d'instancier des objets de type Journal.
 *      On y repertori les attributs suivants: <p>
 * m_identifiant le code ISSN de l'ouvrage. <p>
 * m_nomJournal le nom du journal. <p>
 * m_volume le volume ou commence la reference publiee dans le journal. <p>
 * m_numero le numero ou commence la reference publiee dans le journal. <p>
 * m_page la page ou commence la reference publiee dans le journal. <p>
 * \invariant m_identifiant doit etre un identifiant valide ISSN, on peut le
 * verifier avec la methode bool util::validerCodeIssn (const string& p_issn).
 * \invariant m_nomJournal doit etre non vide on le verifie avec la methode
 * bool util::nonVide (const std::string & p_chaine).
 */
namespace biblio
{

  class Journal : public Reference
  {
  public:
    Journal (const std::string& p_auteurs,
             const std::string& p_titre,
             const int p_annee,
             const std::string& p_identifiant,
             const std::string& p_nomJournal,
             const int p_volume,
             const int p_numero,
             const int p_page);


    std::string reqNomJournal () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;
    std::string reqIdentifiant () const;

    virtual std::string reqReferenceFormate () const;

    virtual Reference* clone () const;



  private:
    std::string m_identifiant;
    std::string m_nomJournal;
    int m_volume;
    int m_numero;
    int m_page;

    void verifieInvariant () const;


  };
}

#endif /* JOURNAL_H */

