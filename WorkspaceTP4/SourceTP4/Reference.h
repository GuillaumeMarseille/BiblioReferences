/**
 * \file Reference.h
 * \brief Prototype de la classe Reference.
 * \author Guillaume Marseille.
 * \version 1.0
 * \date 2 octobre 2021
 */
#ifndef REFERENCE_H
#define REFERENCE_H
#include <string>

/**
 * \class Reference
 * \brief Classe permettant d'instancier des objets de type Reference.
 *      On y repertori les attributs suivants: <p>
 * m_auteurs l'auteur du livre <p>
 * m_titre le titre du livre <p>
 * m_annee l'annee d'edition <p>
 * m_identifiant le code (ISBN ou ISSN) du livre <p>
 * \invariant m_auteur doit être dans un format valide. Verifiable avec la
 * methode bool validerFormatNom (const string& p_nom).
 * \invariant m_titre doit etre non vide.
 * \invariant m_annee doit etre superieur a 0.
 * \invariant m_identifiant doit etre un code ISSN ou ISBN valide. Verifiable
 * avec la methode   validerCodeIssn (const string& p_issn)  pour ISSN ou
 * bool validerCodeIsbn (const string& p_isbn) pour ISBN.
 */

namespace biblio
{

  class Reference
  {
  public:
    Reference (const std::string& p_auteurs,
               const std::string& p_titre,
               const int p_annee,
               const std::string& p_identifiant);


    std::string reqAuteurs () const;
    std::string reqTitre () const;
    int reqAnnee () const;
    std::string reqIdentifiant () const;

    virtual std::string reqReferenceFormate () const;

    void asgAnnee (int p_annee);

    bool operator== (const Reference& p_reference) const;

    virtual Reference* clone () const = 0;

    virtual
    ~Reference () { };

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
    void verifieInvariant () const;



  };
}

#endif /* REFERENCE_H */

