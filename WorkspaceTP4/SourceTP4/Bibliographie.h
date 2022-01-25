/**
 * \file Bibliographie.h
 * \brief Prototype de la classe Bibliographie.
 * \author Guillaume Marseille.
 * \version 1.0
 * \date 12 novembre 2021
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H
#include <string>
#include <vector>
#include "Reference.h"

/**
 * \class Bibliographie
 * \brief Classe permettant de faire la gestion des references.<p>
 * Ses attributs sont les suivants: <p>
 * m_nomBibliographie le nom de la bibliographie. p
 * m_vReferences un vecteur contenant tous les pointeurs de references. <p>
 */
namespace biblio
{

  class Bibliographie
  {
  public:
    Bibliographie (const std::string &p_nomBibliographie);
    std::string reqNomBibliographie () const;
    void ajouterReference (const Reference& p_nouvelleReference);
    std::string reqBibliographieFormate () const;
    void supprimerReference (const std::string& p_identifiant);

    //Modification pour classe Coplien
    ~Bibliographie ();
    Bibliographie (const Bibliographie& p_original);
    const Bibliographie& operator= (const Bibliographie& p_biblio);



  private:
    std::string m_nomBibliographie;
    std::vector<biblio::Reference*> m_vReferences;
    //methodes utilitaires
    void copierVecteur (const Bibliographie& source);
    void videVecteur ();
    bool referenceEstDejaPresenteIdentifiant (const std::string& p_identifiant) const;
    bool referenceEstDejaPresente (const biblio::Reference& p_reference) const;

  };
}

#endif /* BIBLIOGRAPHIE_H */

