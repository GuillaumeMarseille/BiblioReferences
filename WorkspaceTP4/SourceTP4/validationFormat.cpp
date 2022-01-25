
/* *
 * \file: validation.cpp
 * \brief Ce fichier contient l'implantation des fonctions de validations.
 * \author: Guillaume Marseille.
 *  * \version 1.0
 * \date 2 octobre 2021, 15:29
 */



#include "validationFormat.h"

using namespace std;


bool
util::validerFormatNom (const string& p_nom)
{
  bool valide = true;
  string tiretDouble = "--";
  string espaceDouble = "  ";
  string tiretEspace = "- ";
  string espaceTiret = " -";

  for (int i = 0; i < p_nom.size (); i++)
    {
      char lettre = p_nom[i];


      if (isalpha (lettre) == 0)
        {
          if (lettre != '-')
            {
              if (lettre != ' ')
                {
                  valide = false;
                }
            }
        }

      if (p_nom.find (tiretDouble) != string::npos)
        {
          valide = false;
        }
      else if (p_nom.find (espaceDouble) != string::npos)
        {
          valide = false;
        }
      else if (p_nom.find (tiretEspace) != string::npos)
        {
          valide = false;
        }
      else if (p_nom.find (espaceTiret) != string::npos)
        {
          valide = false;
        }
    }
  return valide;
}


bool
util::validerCodeIssn (const string& p_issn)
{
  bool valide = false;

  if (p_issn.length () == 14)
    {
      int i = 0;
      string issn = "";
      string pNum = "";
      char tiret = '.';
      string dNum = "";

      for (i = 0; i < 5; i++)
        {
          issn += p_issn[i];
        }
      for (i = 5; i < 9; i++ )
        {
          pNum += p_issn[i];
        }
      for (i = 10; i < 14; i++ )
        {
          dNum += p_issn[i];
        }
      tiret = p_issn[9];

      string numCombine = pNum + dNum;

      if (issn == "ISSN " && tiret == '-')
        {
          if (chaineEstNumerique (numCombine))
            {
              if (dernierChiffreValide (numCombine))
                {
                  valide = true;
                }
            }
        }
    }

  return valide;
}


bool
util::validerCodeIsbn (const string& p_isbn)
{
  bool valide = false;
  string partieFixe = "";
  string partieVariable = "";
  string partieCalcul = "";
  array<string, 4> tabEntiersVariablesStr;
  array<int, 4> tabEntiersVariablesInt;
  int i = 0;

  if (p_isbn.size () == 22)
    {
      for (i = 0; i < 9; i++)
        {
          partieFixe += p_isbn[i];
        }
      if (partieFixe == "ISBN 978-" or partieFixe == "ISBN 979-")
        {
          for (i = 9; i < 22; i++)
            {
              partieVariable += p_isbn[i];
            }
          extraireEntiersIsbn (tabEntiersVariablesStr, partieVariable);

          {
            if (verifierLongueurIsbn (tabEntiersVariablesStr))
              {
                convertirStrInt (tabEntiersVariablesStr, tabEntiersVariablesInt);
                if (verifierValeursIsbn (tabEntiersVariablesInt))
                  {
                    if (partieFixe == "ISBN 978-")
                      {
                        partieCalcul = "978";
                      }
                    else
                      {
                        partieCalcul == "979";
                      }
                    for (i = 0; i < tabEntiersVariablesStr.size (); i++)
                      {
                        partieCalcul += tabEntiersVariablesStr[i];
                      }
                    if (verifierDernierChiffreIsbn (partieCalcul))
                      {
                        valide = true;
                      }
                  }
              }
          }
        }
    }

  return valide;
}


bool
util::chaineEstNumerique (const string& p_chaineNum)
{
  bool entier = true;
  int i = 0;
  for (i = 0; i < p_chaineNum.size () - 1; i++ )
    {
      if (!isdigit (p_chaineNum[i]))
        {


          entier = false;
        }
    }

  return entier;
}


bool
util::dernierChiffreValide (const string& p_chaineNum)
{

  int i = 0;
  int j = 8;
  int k = 0;
  int esperance = 0;
  int dernierChiffre = p_chaineNum[7] - '0';
  int resultat = 0;
  int restant = 0;
  bool valide = true;

  for (i = 0; i < 7; i++)
    {
      k = p_chaineNum[i] - '0';
      esperance += k * j;
      j--;

    }
  restant = esperance % 11;

  resultat = 11 - restant;

  if (restant == 0)
    {
      if (dernierChiffre != 0)
        {
          valide = false;
        }
    }


  else if (resultat == 10)
    {
      if (dernierChiffre != 40)
        {
          valide = false;
        }

    }
  else if (resultat != dernierChiffre)
    {
      valide = false;
    }


  return valide;
}


void
util::extraireEntiersIsbn (array<string, 4>& p_tabEntiers, const string& p_tabPartieVariable)
{
  int i = 0;
  int e = 0;

  for (i = 0; i < 4; i++)
    {
      while (isdigit (p_tabPartieVariable[e]))
        {
          p_tabEntiers[i] += p_tabPartieVariable[e];
          e++;
        }
      e++;
    }
}


bool
util::verifierLongueurIsbn (const array<string, 4>& p_tabStrEntiers)
{
  bool valide = false;
  int e0 = p_tabStrEntiers[0].size ();
  int e1 = p_tabStrEntiers[1].size ();
  int e2 = p_tabStrEntiers[2].size ();
  int e3 = p_tabStrEntiers[3].size ();

  if (0 < e0 <= 5
      && 0 < e1 <= 7
      && 0 < e2 <= 6
      && e3 == 1
      && e0 + e1 + e2 + e3 == 10)
    {
      valide = true;
    }


  return valide;
}


void
util::convertirStrInt (const array<string, 4>& p_tabStr, array<int, 4>& p_tabInt)
{
  int i = 0;
  for (i = 0; i < 4; i++)
    {
      p_tabInt[i] = stoi (p_tabStr[i]);
    }
}


bool
util::verifierValeursIsbn (const array<int, 4> p_tabIntEntiers)
{
  bool valide = false;
  int domaine = p_tabIntEntiers[0];
  if ((0 <= domaine && domaine <= 5)
      || (domaine == 7)
      || (600 <= domaine && domaine <= 649)
      || (80 <= domaine && domaine <= 94)
      || (950 <= domaine && domaine <= 989)
      || (9900 <= domaine && domaine <= 9980)
      || (99900 <= domaine && domaine <= 99999))
    {
      valide = true;
    }
  // possibilite de verifier les autres chiffres dans le future.
  return valide;
}


bool
util::verifierDernierChiffreIsbn (const string& p_partieCalcul)
{
  bool valide = false;
  int i = 0;
  int k = 0;
  int calcul = 0;
  int resultat = 0;
  string chaine = p_partieCalcul;
  int dernierChiffre = chaine.back () - '0';

  for (i = 0; i < chaine.size () - 1; i++)
    {
      k = chaine[i] - '0';
      if (i % 2 == 0)
        {
          calcul += k;
        }
      else
        {
          calcul += 3 * k;
        }

    }
  resultat = 10 - calcul % 10;
  if (resultat == 0 && 0 == dernierChiffre)
    {
      valide = true;
    }
  else if (resultat == dernierChiffre)
    {
      valide = true;
    }
  return valide;
}


bool
util::nonVide (const std::string & p_chaine)
{
  return (!p_chaine.empty ());
}


bool
util::superieurAZero (const int & p_nombre)
{
  return (p_nombre > 0);
}


char
util::typeCode (const std::string & p_code)
{
  char code;
  if (p_code[2] == 'S')
    {
      code = 'S';
    }

  else if (p_code[2] == 'B')
    {
      code = 'B';
    }
  else
    {
      code = 'E';
    }

  return code;
}


bool
util::validerIssnOuIsbn (const std::string &p_code)
{
  bool valide = false;
  char code = util::typeCode (p_code);

  if (code == 'S')
    {
      if (util::validerCodeIssn (p_code))
        {
          valide = true;
        }

    }
  else if (code == 'B')
    {
      if (util::validerCodeIsbn (p_code))
        {
          valide = true;
        }
    }
  return valide;
}