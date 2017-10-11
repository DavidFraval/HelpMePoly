/****************************************************************************
* Fichier: Abonne.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: Impl�mentation de la classe Abonne
****************************************************************************/
#include <iostream>
#include "Abonne.h"

using namespace std;

Abonne::Abonne()
	:age_(0), limiteEmprunts_(LIMITE_EMPRUNTS)
{

}

Abonne::Abonne(const std::string & matricule, const std::string & nom, const std::string & prenom, unsigned int age) 
	: matricule_(matricule), nom_(nom), prenom_(prenom), age_(age), limiteEmprunts_(LIMITE_EMPRUNTS)
{

}

Abonne::~Abonne()
{

}

string Abonne::obtenirMatricule() const
{
	return matricule_;
}

string Abonne::obtenirNom() const
{
	return nom_;
}

string Abonne::obtenirPrenom() const
{
	return prenom_;
}

unsigned int Abonne::obtenirAge() const
{
	return age_;
}

std::vector<Emprunt*> Abonne::obtenirEmprunts() const
{
	return vecEmprunts_;
}

void Abonne::modifierMatricule(const string& matricule)
{
	matricule_ = matricule;
}

void Abonne::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Abonne::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Abonne::modifierAge(unsigned int age)
{
	age_ = age;
}

void Abonne::ajouterEmprunt(Emprunt * emprunt)
{
	vecEmprunts_.push_back(emprunt);
}

unsigned int Abonne::obtenirNombreEmprunte() const
{
	return vecEmprunts_.size();
}


ostream & operator<<(ostream & o, const Abonne & abonne)
{
	// Affichage des informations de base
	o << abonne.prenom_ << ", " <<
		abonne.nom_ << ". " <<
		abonne.age_ << " ans. #" <<
		abonne.matricule_ << endl;

	o << "LISTE DE LIVRES :" << endl;

	// Affichage de la liste de objetEmpruntables

	for (unsigned int i = 0; i < abonne.vecEmprunts_.size(); i++)
	{
		o << i + 1 << " - " << *(abonne.vecEmprunts_[i]) << endl;
	}

	// retour
	return o;

}

bool Abonne::operator==(const Abonne & abonne) const
{
	return
		(matricule_ == abonne.matricule_) &&
		(nom_ == abonne.nom_) &&
		(prenom_ == abonne.prenom_) &&
		(age_ == abonne.age_);
}

bool Abonne::operator==(const std::string & matricule) const
{
	return matricule_ == matricule;
}

bool operator==(const std::string & matricule, const Abonne & abonne)
{
	return abonne == matricule;
}




//______TP3______

// Une m�thode pour obtenir le nombre d�emprunts limite.
unsigned int Abonne::obtenirLimiteEmprunts() const
{
	return limiteEmprunts_;
}



// Une red�finition de la m�thode estEmprunte() qui prend en param�tre une cote et v�rifie
// si l�abonn� poss�de un emprunt associ� � cet objet.Si oui, la m�thode retourne true,
// sinon false.
bool Abonne::estEmprunte(const std::string& cote) const
{
	bool estEmprunte = false;
	for (unsigned int i = 0; i < vecEmprunts_.size(); i++){
		if (*vecEmprunts_[i]->obtenirObjetEmpruntable() == cote)
			estEmprunte = true;
	}
	return estEmprunte;
}


// Une red�finition de la m�thode retirerEmprunt() qui prend en param�tre un
// ObjetEmpruntable.La m�thode enl�ve l�emprunt associ� � cet objet du vecteur
// seulement s�il est pr�sent.La m�thode retourne un bool�en true si l�emprunt est retir� et
// false sinon
bool Abonne::retirerEmprunt(const ObjetEmpruntable &unObjet){

	for (unsigned int i = 0; i < vecEmprunts_.size(); i++){
		
		if ((vecEmprunts_[i]->obtenirObjetEmpruntable() == &unObjet)){ 
			vecEmprunts_[i] = vecEmprunts_[vecEmprunts_.size() - 1];
			vecEmprunts_.pop_back();
			return true;
		}
	}
	return false;
}

