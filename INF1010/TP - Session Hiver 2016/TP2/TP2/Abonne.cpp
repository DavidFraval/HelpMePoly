/****************************************************************************
* Fichier: Abonne.cpp
* Auteur: PolySensei & Associates
* Date: 4 f�vrier 2016
* Mise a jour : 6 f�vrier 2016
* Description: Impl�mentation de la classe Abonne
****************************************************************************/
#include <iostream>
#include <string>
#include "Abonne.h"
using namespace std;

/****************************************************************************
* Fonction:	Abonne::Abonne
* Description: Constructeur par d�faut
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
Abonne::Abonne()
	:age_(0)
{
}

/****************************************************************************
* Fonction:	Abonne::Abonne
* Description: Constructeur par param�tres
* Param�tres:	- const string& matricule: valeur du matricule
*				- const string& nom: valeur du nom
*				- const string& prenom: valeur du prenom
*				- unsigned int age: valeur de l age
* Retour:		aucun
****************************************************************************/
Abonne::Abonne(const string& matricule, const string& nom, const string& prenom, unsigned int age)
	: matricule_(matricule), nom_(nom), prenom_(prenom), age_(age)
{
}

/****************************************************************************
* Fonction:	Abonne::~Abonne
* Description: Destructeur
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
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


// _____________TP2__________________
vector<Emprunt*> Abonne::obtenirListeEmprunt() const{
	return listeEmprunt_;
}


int Abonne::obtenirNombreEmprunte() const{
	return listeEmprunt_.size();
}


/****************************************************************************
* Fonction:	Abonne::estEmprunte
* Description: Prend en param�tre un Livre et v�rifie si l'abonn� poss�de un emprunt de ce livre. 
* Param�tres:	const Livre& unLivre
* Retour:		Bool�en qui true, si l�abonn� poss�de un emprunt associ� � ce livre, sinon false.
****************************************************************************/
bool Abonne::estEmprunte(const Livre& unLivre) const
{
	bool estEmprunt = false;
	for (unsigned int i = 0; i < listeEmprunt_.size(); i++){
		if (listeEmprunt_[i]->obtenirLivre() == &unLivre){ 
			estEmprunt = true;
		}
	}
	return estEmprunt;
}


/****************************************************************************
* Fonction:	Abonne::ajouterEmprunt
* Description: Ajout d'un emprunt a la fin du vecteur d'emprunt de l'abonn�
* Param�tres:	Emprunt* unEmprunt: un emprunt
* Retour:		Aucun
****************************************************************************/
void Abonne::ajouterEmprunt(Emprunt* unEmprunt){
	listeEmprunt_.push_back(unEmprunt);
}

/****************************************************************************
* Fonction:	Abonne::retireremprunt
* Description: Retirer un emprunt dans le vecteur d emprunt de l'abonne
* Param�tres:	Livre& unLivre; un livre
* Retour:		Un bool�en true si le livre est retirer sinon false
****************************************************************************/
bool Abonne::retirerEmprunt(Livre& unLivre){
	bool estRetire = false;
	for (unsigned int i = 0; i < listeEmprunt_.size(); i++){
		if (listeEmprunt_[i]->obtenirLivre() == &unLivre){	//S'assure que l'abonn� avait bel et bien emprunt� le livre.
			estRetire = true;
			listeEmprunt_[i] = listeEmprunt_[listeEmprunt_.size() - 1];
			listeEmprunt_.pop_back();
		}
	}
	return estRetire;
}


/****************************************************************************
* Fonction:	operator<<
* Description:	Surcharge de l�op�rateur << (remplace la m�thode d�affichage), 
*				qui affiche les informations qui concernent un Abonne, tel 
*				que pr�sent� dans l�exemple � la fin de l'�nonc� du TP.
* Param�tres:	ostream& out, le stream de sortie
*				const Abonne& unAbonne, l'Abonn� � afficher
* Retour:		ostream& out, le stream de sortie
****************************************************************************/
ostream& operator<<(ostream& out, const Abonne& unAbonne){
	out << unAbonne.prenom_ << ", " << unAbonne.nom_ << ". " << unAbonne.age_ << " ans. #" << unAbonne.matricule_ << endl << "LISTE DE LIVRES :";
	for (int unsigned i = 0; i < unAbonne.listeEmprunt_.size(); i++){
		out << endl << (i + 1) << " - " << *unAbonne.listeEmprunt_[i] << endl;
	}
	return out;
}




//L�op�rateur == qui prend un Abonne en param�tre et permet de comparer 2 abonn�s en consid�rant � la fois le matricule, le Nom, le Pr�nom et l��ge. L�op�rateur retourne true si les abonn�s sont identiques, false sinon. Ainsi, cet op�rateur va pouvoir faire l�op�ration abonne1 == abonne2.
bool Abonne::operator==(Abonne& abonne2) const{
	bool estEgal = false;

	if (matricule_ == abonne2.obtenirMatricule()){
		if (nom_ == abonne2.obtenirNom()){
			if (prenom_ == abonne2.obtenirPrenom()){
				if (age_ == abonne2.obtenirAge()){
					estEgal = true;
				}
			}
		}
	}
	return estEgal;
}


//L�op�rateur == qui prend un matricule en param�tre et permet de comparer 2 abonn�s en consid�rant seulement le matricule.L�op�rateur retourne true si les matricules sont identiques, false sinon.Ainsi, cet op�rateur va pouvoir faire l�op�ration abonne == matricule.
bool Abonne::operator==(std::string unMatricule) const{
	bool estEgal = false;
	if (matricule_ == unMatricule)
		estEgal = true;
	return estEgal;
}



//L�op�rateur == de type friend qui permet d�inverser l�ordre de l�op�rateur == pr�c�dent.Ainsi, cet op�rateur va pouvoir faire l�op�ration matricule == abonne.
bool operator==(std::string unMatricule, Abonne& unAbonne){
	bool estEgal = false;
	if (unAbonne == unMatricule)
		estEgal = true;
	return estEgal;
}