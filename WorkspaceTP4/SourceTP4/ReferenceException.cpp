
/*
 * \file: ReferenceException.cpp
 * \class ReferenceException
 * \brief Implantation de la classe ReferenceException et de ses héritiers
 * \author: Guillaume Marseille
 * \date 1 decembre 2021, 11:58
 */

#include "ReferenceException.h"

using namespace std;


/**
 * \brief Constructeur de ReferenceException
 * \class  ReferenceException
 * \param[in] string p_raison, la raison de l'erreur.
 */

ReferenceException::ReferenceException (const string& p_raison) : runtime_error (p_raison) { }


/**
 * \brief Constructeur de ReferenceDejaPresenteException
 * \class  ReferenceDejaPresenteException (qui herite de ReferenceException)
 * \param[in] string p_raison, la raison de l'erreur.
 */



ReferenceDejaPresenteException::ReferenceDejaPresenteException (const string& p_raison) : ReferenceException (p_raison) { }


/**
 * \brief Constructeur de ReferenceAbsenteException
 * \class  ReferenceAbsenteException (qui herite de ReferenceException)
 * \param[in] string p_raison, la raison de l'erreur.
 */


ReferenceAbsenteException::ReferenceAbsenteException (const string& p_raison) : ReferenceException (p_raison) { }
