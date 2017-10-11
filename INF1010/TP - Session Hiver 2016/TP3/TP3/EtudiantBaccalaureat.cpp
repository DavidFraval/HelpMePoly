/****************************************************************************
* Fichier: EtudiantBaccalaureat.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: Impl�mentation de la classe EtudiantBaccalaureat
****************************************************************************/
#include <iostream>
#include "Etudiant.h"
#include "EtudiantBaccalaureat.h"

using namespace std;


// Un constructeur prenant en param�tre un matricule, un nom, un pr�nom et un �ge et qui
// initialise l�attribut Ecole � � Polytechnique Montreal �.
EtudiantBaccalaureat::EtudiantBaccalaureat(const std::string & matricule, const std::string & nom, const std::string & prenom, unsigned int age)
	: Etudiant(matricule, nom, prenom, age, "Polytechnique Montreal")
{

}


EtudiantBaccalaureat::~EtudiantBaccalaureat()
{

}


// Une red�finition de la m�thode pour obtenir le nombre d�emprunts, en tenant compte du
// fait qu�un �tudiant au baccalaur�at � une limite d�emprunts 2 fois plus �lev� qu�un
// �tudiant classique
unsigned int EtudiantBaccalaureat::obtenirLimiteEmprunts() const
{    
	return Etudiant::obtenirLimiteEmprunts()*2;
}
