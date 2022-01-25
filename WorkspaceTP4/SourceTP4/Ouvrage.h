/**
 * \file Ouvrage.h
 * \brief Prototype de la classe Ouvrage.
 * \author Guillaume Marseille.
 * \version 1.0
 * \date 12 novembre 2021
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H
#include <string>
#include "Reference.h"

/**
 * \class Ouvrage
 * \brief Classe permettant d'instancier des objets de type Ouvrage.
 * <p>
 *      On y repertori les attributs suivants:
 * m_editeur: le nom de l'editeur. <p>
 * m_ville: la ville d'edition. <p>
 * m_identifiant: le code ISBN de l'ouvrage <p>
 * \invariant m_editeur et m_ville doivent être dans un format valide.
 * Verifiable avec la fonction util::validerFormatNom ()
 * m_identifiant doit egalement etre valide et sera verifier par la fonction
 * bool util::validerCodeIsbn (const string& p_isbn).
 */

namespace biblio
{

  class Ouvrage : public Reference
  {
  public:
    Ouvrage (const std::string& p_auteurs,
             const std::string& p_titre,
             const int p_annee,
             const std::string& p_identifiant,
             const std::string& p_editeur,
             const std::string& p_ville);


    std::string reqEditeur () const;
    std::string reqVille () const;
    std::string reqIdentifiant () const;

    virtual Reference* clone () const;

    virtual std::string reqReferenceFormate () const;


  private:
    std::string m_identifiant;
    std::string m_editeur;
    std::string m_ville;

    void verifieInvariant () const;

  };
}

#endif /* OUVRAGE_H */

