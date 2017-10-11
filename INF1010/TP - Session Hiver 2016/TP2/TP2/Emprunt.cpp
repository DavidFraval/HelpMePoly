/****************************************************************************
* Fichier: Emprunt.cpp
* Auteur: PolySensei & Associates
* Date: 4 f�vrier 2016
* Mise a jour : 6 f�vrier 2016
* Description: Impl�mentation de la classe Emprunt
****************************************************************************/
#include <iostream>
#include "Emprunt.h"

using namespace std;

Emprunt::Emprunt(string matricule, Livre *livre, unsigned int date)
	: matricule_(matricule), livre_(livre), dateRetour_(date)
{

}
/****************************************************************************
* Fonction:	Emprunt::~Emprunt
* Description: Destructeur
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
Emprunt::~Emprunt()
{
}

string Emprunt::obtenirMatricule() const
{
	return matricule_;
}

Livre* Emprunt::obtenirLivre() const
{
	return livre_;
}

unsigned int Emprunt::obtenirDateRetour() const
{
	return dateRetour_;
}

void Emprunt::modifierMatricule(const string &matricule)
{
	matricule_ = matricule;
}

void Emprunt::modifierLivre(Livre* livre)
{
	livre_ = livre;
}

void Emprunt::modifierDateRetour(unsigned int date)
{
	dateRetour_ = date;
}


/// __________ TP2 _____________

/*Un op�rateur << (remplace la m�thode d�affichage), qui affiche le matricule de l�abonn�, puis appelle l�op�rateur << de son Livre; tel que pr�sent� dans l�exemple � la fin du document.*/
ostream& operator<< (ostream& out, const Emprunt& unEmprunt){

	out << "Usager #" << unEmprunt.matricule_
		<< ". Livre " << *unEmprunt.livre_ << endl
		<< "Retour prevu : " << unEmprunt.dateRetour_;
	return out;
}
