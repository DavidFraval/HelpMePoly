/****************************************************************************
* Fichier: Etudiant.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: Impl�mentation de la classe Etudiant
****************************************************************************/
#include <iostream>
#include "Etudiant.h"
#include <string>

using namespace std;

// Un constructeur par d�faut qui initialise en plus l�attribut Ecole � la cha�ne vide
Etudiant::Etudiant() : Abonne(), ecole_("")
{

}


// Un constructeur par param�tres qui initialise les attributs selon les param�tres.
Etudiant::Etudiant(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, const std::string& ecole)
	: Abonne(matricule, nom, prenom, age), ecole_(ecole)
{

}

// Le destructeur pour cette classe.
Etudiant::~Etudiant()
{

}


// Les m�thodes d�acc�s et de modification du nouvel attribut
string Etudiant::obtenirEcole() const
{
	return ecole_;
}

void Etudiant::modifierEcole(const std::string& ecole){
	ecole_ = ecole;
}



// Une red�finition de la m�thode pour obtenir le nombre d�emprunts, en tenant compte du
// fait qu�un �tudiant � une limite d�emprunt 2 fois plus �lev�e qu�un abonn� classique
unsigned int Etudiant::obtenirLimiteEmprunts() const
{    
	return Abonne::obtenirLimiteEmprunts()*2;
}


// L�op�rateur << , qui affiche les informations de l��tudiant, tel que pr�sent� dans l�exemple
// � la fin du document.Il doit utiliser l�op�rateur << de la classe de base
ostream& operator<<(ostream& out, const Etudiant& etudiant){
	out << (Abonne)etudiant << "Ecole de provenance : " << etudiant.ecole_ << "; Limite d'emprunts : " << etudiant.obtenirLimiteEmprunts() << endl;   //Etudiant est un abonne
	return out;
}