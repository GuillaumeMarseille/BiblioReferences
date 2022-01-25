
/* *
 * \file: Bibliographie.cpp
 * \brief Ce fichier contient l'implantation de la classe Bibliographie
 * \author: Guillaume Marseille.
 * \version 1.0
 * \date 15 novembre 2021, 15:29
 */

#include "Reference.h"
#include "ContratException.h"
#include "validationFormat.h"
#include "Bibliographie.h"
#include "ReferenceException.h"
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;
namespace biblio
{


  /**
   * \brief Constructeur de la classe Bibliographie.
   *    Cette classe prend leparametre suivant:
   * \class Bibliographie
   * \param[in] p_nomBibliographie.
   * \post l'objet construit a été initialisé à partir de la valeur passée en
   *  paramètre.
   */
  Bibliographie::Bibliographie (const string &p_nomBibliographie) :
  m_nomBibliographie (p_nomBibliographie)
  {
    POSTCONDITION (reqNomBibliographie () == m_nomBibliographie);
  }


  /**
   * \brief Permet d'accceder a l'attribut m_nomBibliographie en lecture.
   * \return Retourne le nom de la bibliographie.
   */
  std::string
  Bibliographie::reqNomBibliographie () const
  {
    return m_nomBibliographie;
  }


  /**
   * \brief Ajoute une reference au vecteur de l'objet courant.
   * \param[in] p_nomBibliographie
   * \post la reference ajoutee est bien celle passee en parametre.
   */

  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {
    if (referenceEstDejaPresente (p_nouvelleReference))
      {
        ostringstream os;
        os << "Erreur doublon: "
                << p_nouvelleReference.reqReferenceFormate ();
        throw ReferenceDejaPresenteException (os.str ());
      }

    else
      {
        m_vReferences.push_back (p_nouvelleReference.clone ());
      }

    POSTCONDITION ((*m_vReferences.back ()).reqReferenceFormate () ==
                   p_nouvelleReference.reqReferenceFormate ());
  }


  /**
   * \brief Permet de parcourir le vecteur de references
   * pour acceder a leur attributs en lecture.
   * \return Retourne une string formate contenant tous les references du vecteur.
   */
  std::string
  Bibliographie::reqBibliographieFormate () const
  {
    ostringstream os_biblio_format;
    os_biblio_format
            << this->reqNomBibliographie () << endl;
    os_biblio_format << "===============================" << endl;

    int i = 1;
    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it != m_vReferences.end (); it++, i++)
      {


        os_biblio_format << "[" << i << "] " << (*it)->reqReferenceFormate () << endl;
      }

    return os_biblio_format.str ();
  }


  /**
   * \brief Permet de parcourir le vecteur de references et
   * de verifier si la reference est deja dans le vecteur.
   * \return Retourne True si une reference ayant le meme identifiant est deja
   * dans le vecteur. False sinon.
   *\param[in] const biblio::Reference& p_reference, la reference.
   */
  bool
  Bibliographie::referenceEstDejaPresente (const biblio::Reference& p_reference) const
  {
    bool estPresent = false;

    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it != m_vReferences.end (); it++)
      {
        if (p_reference == *(*it))
          {

            estPresent = true;
          }
      }
    return estPresent;
  }


  /**
   * \pre le vecteur qui recoit la copy est vide.
   * \brief Verifie si le vecteur m_vReferences est vide et fait
   * une copy profonde du vecteur passe en parametre.
   * \post les 2 vecteurs on strictement les memes elements.
   */
  void
  Bibliographie::copierVecteur (const Bibliographie& p_original)
  {
    PRECONDITION (m_vReferences.empty ());
    if (m_vReferences.empty ())
      {
        vector<Reference*>::const_iterator it;
        for (it = p_original.m_vReferences.begin (); it != p_original.m_vReferences.end (); it++)
          {


            this->ajouterReference (*(*it));
          }
      }
    POSTCONDITION (this->reqBibliographieFormate () == p_original.reqBibliographieFormate ());
  }


  /**
   * \brief Libere la memoire allouee aux pointeurs dans le vecteur sur le
   * monceau et vide le vecteur.
   * \post Verifie que le vecteur est vide.
   */
  void
  Bibliographie::videVecteur ()
  {
    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it != m_vReferences.end (); it++)
      {
        delete *it;
      }
    m_vReferences.clear ();
    POSTCONDITION (m_vReferences.size () == 0);
  }


  /**
   * \brief Destructeur de Bibliographie. Fait appel a la fonction videVecteur
   * pour liberer la memoire qu'occupe le contenu des pointeurs dans le vecteur.
   */
  Bibliographie::~Bibliographie ()
  {

    videVecteur ();
  }


  /**
   * \brief Constructeur de copie profonde Bibliographie.
   * \post Verifie que les 2 copies on le meme nom. (Le vecteur est verifie par
   * la fonction copieVecteur()).
   */
  Bibliographie::Bibliographie (const Bibliographie& p_original)
  {


    m_nomBibliographie = p_original.reqNomBibliographie ();
    this->copierVecteur (p_original);
    POSTCONDITION (m_nomBibliographie == p_original.m_nomBibliographie);
  }


  /**
   * \brief Operateur d'assignation. Permet de faire une copie profonde lors
   * de l'assignation d'une bibliographie a une autre.
   * \return Retourne la copie profonde du vecteur pour l'assignation multiple.
   * \post Verifie que les 2 copies on le meme nom. (Le vecteur est verifie par
   * la fonction copieVecteur()).
   */
  const Bibliographie& Bibliographie::operator= (const Bibliographie &p_rhs)
  {
    if (this != &p_rhs)
      {
        m_nomBibliographie = p_rhs.reqNomBibliographie ();
        this->videVecteur ();
        this->copierVecteur (p_rhs);
        POSTCONDITION (m_nomBibliographie == p_rhs.m_nomBibliographie);
      }

    return *this;
  }


  /**
   * \brief Methode pour supprimer une reference dans le vecteur.
   * \post La reference ne doit plus etre presente
   */

  void
  Bibliographie::supprimerReference (const string& p_identifiant)
  {

    size_t nbReferencesInitial = m_vReferences.size ();

    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it != m_vReferences.end (); )
      {
        if (p_identifiant == (*it)->reqIdentifiant ())
          {
            delete *it;
            it = m_vReferences.erase (it);
          }
        else
          {
            it++;
          }
      }
    if (m_vReferences.size () == nbReferencesInitial)
      {
        throw ReferenceAbsenteException ("Réference inexistante dans cette bibliographie.");
      }
    POSTCONDITION (!(referenceEstDejaPresenteIdentifiant (p_identifiant)));
  }


  /**
   * \brief Permet de parcourir le vecteur de references et
   * de verifier si la reference est deja dans le vecteur.
   * \return Retourne True si une reference ayant le meme identifiant est deja
   * dans le vecteur. False sinon.
   * \param[in] const std::string& p_identifiant, l'identifiant de la reference.
   */
  bool
  Bibliographie::referenceEstDejaPresenteIdentifiant  (const std::string& p_identifiant) const
  {
    bool estPresent = false;

    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it != m_vReferences.end (); it++)
      {
        if (p_identifiant == (*it)->reqIdentifiant ())
          {
            estPresent = true;
          }
      }
    return estPresent;
  }

}




