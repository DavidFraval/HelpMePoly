/****************************************************************************
* Fichier: Emprunt.cpp
* Auteur: PolySensei & Associates
* Date: 22 f�vrier 2016
* Mise a jour : 3 mars 2016
* Description: Impl�mentation de la classe Emprunt
****************************************************************************/
#include <iostream>
#include "Emprunt.h"

using namespace std;


Emprunt::~Emprunt()
{

}

string Emprunt::obtenirMatricule() const
{
	return matricule_;
}



unsigned int Emprunt::obtenirDateRetour() const
{
	return dateRetour_;
}

void Emprunt::modifierMatricule(const string &matricule)
{
	matricule_ = matricule;
}

void Emprunt::modifierDateRetour(unsigned int date)
{
	dateRetour_ = date;
}




/// TP4


// Un constructeur par param�tre qui prend un matricule(string), un ObjetEmpruntable et une date(entier positif).
// Ce constructeur va remplacer les constructeurs par param�tre des TP pr�c�dents.
Emprunt::Emprunt(const std::string& matricule, ObjetEmpruntable* objEmprunt, unsigned int dateRetour)
	: matricule_(matricule), objEmprunt_(objEmprunt), dateRetour_(dateRetour) 
{

}


// Les m�thodes d�acc�s et de modification du nouvel attribut. obtenirObjEmprunt(), modifierObjEmprunt().
ObjetEmpruntable* Emprunt::obtenirObjEmprunt() const 
{
	return objEmprunt_;
}

void Emprunt::modifierObjEmprunt(ObjetEmpruntable* objEmprunt)
{
	objEmprunt_ = objEmprunt;
}


// Un op�rateur << , qui affiche le matricule de l�abonn�, affiche le nom de la classe de l�objet, puis appelle 
// l�op�rateur << de l�objet empruntable appropri�; tel que pr�sent� dans l�exemple � la fin du document.
std::ostream& operator<<(std::ostream& out, const Emprunt& emprunt){

	out << "Usager #" << emprunt.matricule_
		<< ". " << emprunt.objEmprunt_->obtenirNomClasse() << ". ";
	emprunt.objEmprunt_->afficherObjetEmpruntable(out);
	out << "Retour prevu : " << emprunt.dateRetour_ << endl;
	
	return out;
}
