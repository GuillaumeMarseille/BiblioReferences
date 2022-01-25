/**
 * \file validationFormat.h
 * \brief Prototype du fichier validationFormat.
 * \author Guillaume Marseille.
 * \version 1.0
 * \date 12 novembre 2021
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include <string>
#include <array>
namespace util
{
  bool validerFormatNom (const std::string & p_nom);
  bool validerCodeIssn (const std::string & p_issn);
  bool validerCodeIsbn (const std::string & p_isbn);
  bool chaineEstNumerique (const std::string & p_chaine);
  bool dernierChiffreValide (const std::string & p_chaineNum);
  void extraireEntiersIsbn (std::array<std::string, 4>& p_tabEntiers,
                            const std::string & p_partieVariable);
  bool verifierLongueurIsbn (const std::array<std::string, 4>& p_tabEntiers);

  void convertirStrInt (const std::array<std::string, 4>& p_tabStr,
                        std::array<int, 4>& p_tabInt);
  bool verifierValeursIsbn (const std::array<int, 4> p_tabIntEntiers);
  bool verifierDernierChiffreIsbn (const std::string & p_partieCalcul);

  bool nonVide (const std::string & p_chaine);
  bool superieurAZero (const int & p_nombre);
  char typeCode (const std::string & p_code);
  bool validerIssnOuIsbn (const std::string & p_code);
}
#endif /* VALIDATIONFORMAT_H */

