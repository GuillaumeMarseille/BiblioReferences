/* *
 * \file: ReferenceException.cpp
 * \class ReferenceException
 * \brief prototype de la classe ReferenceException
 * \author: Guillaume Marseille
 * \date 1 decembre 2021, 11:58
 */
#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \class ReferenceException
 * \brief Classe permettant de gerer les exceptions lors de la gestions
 * d'une bibliographie. Prend la raison de l'erreur en parametre.
 */

class ReferenceException : public std::runtime_error
{
public:

  ReferenceException (const std::string& p_raison);
};

/**
 * \class ReferenceDejaPresenteException
 * \brief Classe d'erreur pour la gestion de doublons.
 * Prend la raison de l'erreur en parametre.
 */

class ReferenceDejaPresenteException : public ReferenceException
{
public:

  ReferenceDejaPresenteException (const std::string& p_raison);
};

/**
 * \class ReferenceAbsenteException
 * \brief Classe d'erreur qui survient lorsqu'on tente de supprimer une
 * reference inexistante.
 * Prend la raison de l'erreur en parametre.
 */

class ReferenceAbsenteException : public ReferenceException
{
public:

  ReferenceAbsenteException (const std::string& p_raison);
};

#endif /* REFERENCEEXCEPTION_H */

