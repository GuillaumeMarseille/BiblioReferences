/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 5 décembre 2021, 20:21
 */

#include <QApplication>
#include "BibliographieInterface.h"


int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  BibliographieInterface fenetrePrincipale;
  fenetrePrincipale.show ();

  return app.exec ();
}
