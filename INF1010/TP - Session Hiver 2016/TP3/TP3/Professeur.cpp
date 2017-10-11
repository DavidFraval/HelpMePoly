/****************************************************************************
* Fichier: Professeur.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: Impl�mentation de la classe Professeur
****************************************************************************/
#include <iostream>
#include "Professeur.h"

using namespace std;

// Un constructeur par d�faut.
Professeur::Professeur(){

}

// Un constructeur par param�tres qui initialise les attributs en fonction des param�tres.
Professeur::Professeur(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, std::vector<std::string> vecEcoles)
	: Abonne(matricule, nom, prenom, age), vecEcoles_(vecEcoles)
{

}

// Le destructeur pour cette classe.
Professeur::~Professeur()
{

}

// La m�thode d�acc�s au nouvel attribut.
vector<string> Professeur::obtenirVecEcoles() const
{
	return vecEcoles_;
}


// Une m�thode ajouterEcole() qui prend en param�tre un string, et l�ajoute au vecteur.
void Professeur::ajouterEcole(const std::string& ecole)
{
	vecEcoles_.push_back(ecole);
}


// Une m�thode retirerEcole () qui prend en param�tre un string. La m�thode enl�ve
// l��cole associ�e � ce string du vecteur.La m�thode retourne un bool�en true si l��cole
// est retir�e et false sinon.
bool Professeur::retirerEcole(const std::string& ecole)
{
	bool estRetire = false;
	for (unsigned int i = 0; i < vecEcoles_.size(); i++){
		if ((vecEcoles_[i] == ecole) && (!estRetire)){
			estRetire = true;
			vecEcoles_[i] = vecEcoles_[vecEcoles_.size() - 1];
			vecEcoles_.pop_back();
		}
	}
	return estRetire;
}


// La red�finition de la m�thode obtenir limiteEmprunts() en tenant compte du fait qu�un
// enseignant peut emprunter un nombre limit� de livre d�finie comme suit limiteEmprunt
// = nombre Ecole x limite Emprunt Classique
unsigned int Professeur::obtenirLimiteEmprunts() const
{
	return vecEcoles_.size() * Abonne::obtenirLimiteEmprunts();
}


// L�op�rateur << , qui affiche les informations du Professeur, tel que pr�sent� dans
// l�exemple � la fin du document. Il doit appeler l�op�rateur << de la classe Abonne.
std::ostream& operator<<(std::ostream& out, const Professeur& professeur){
	out << (Abonne)professeur
		<< "Limite d'emprunts : " << professeur.obtenirLimiteEmprunts() << endl
		<< "LISTE DES ECOLES : ";
	for (unsigned int i = 0; i < professeur.vecEcoles_.size(); i++){
		out << professeur.vecEcoles_[i] << "; ";
	}
	out << endl;

	return out;
}