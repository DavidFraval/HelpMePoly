/****************************************************************************
* Fichier: DVD.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: Impl�mentation de la classe Dvd
****************************************************************************/
#include <iostream>
#include "Dvd.h"

using namespace std;

// Un constructeur par param�tre qui initialise les nouveaux attributs.
Dvd::Dvd(const std::string& cote, const std::string& titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string& realisateur, std::vector<std::string> vecActeurs) : ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), realisateur_(realisateur), vecActeurs_(vecActeurs)
{

}


Dvd::~Dvd()
{

}



// Des m�thodes d�acc�s et de modifications pour les nouveaux attributs : obtenirRealisateur(), obternirActeurs(), modifierRealisateur(), ajouterActeur(), retirerActeur().
std::string Dvd::obtenirRealisateur() const
{
	return realisateur_;
}

std::vector<std::string> Dvd::obternirActeurs() const
{
	return vecActeurs_;
}

void Dvd::modifierRealisateur(const std::string& unRealisateur){
	realisateur_ = unRealisateur;
}

void Dvd::ajouterActeur(const std::string& acteur)
{
	vecActeurs_.push_back(acteur);
}

bool Dvd::retirerActeur(const std::string& acteur){
	bool estRetire = false;
	for (unsigned int i = 0; i < vecActeurs_.size(); i++){
		if ((vecActeurs_[i] == acteur) && (!estRetire)){
			estRetire = true;
			vecActeurs_[i] = vecActeurs_[vecActeurs_.size() - 1];
			vecActeurs_.pop_back();
		}
	}
	return estRetire;
}



// Une red�finition de la m�thode rechercher() qui v�rifie si la cha�ne de caract�res est
// pr�sente dans les nouveaux attributs de type string
bool Dvd::recherche(const std::string& motsCle) const{

	bool estTrouve = false;
	std::size_t trouveRealisateur = convertirMinuscule(realisateur_).find(convertirMinuscule(motsCle));

	std::size_t trouveActeur = 0;
	for (unsigned int i = 0; i < vecActeurs_.size(); i++){
		if (trouveActeur == 0)
			trouveActeur = convertirMinuscule(vecActeurs_[i]).find(convertirMinuscule(motsCle));
	}

	estTrouve = ObjetEmpruntable::recherche(motsCle) ||
		(trouveRealisateur != string::npos) ||
		(trouveActeur != string::npos);

	return estTrouve;
}


// L�op�rateur << qui affiche les informations du Dvd, tel que pr�sent� dans l�exemple � la
// fin du document.Il doit appeler l�op�rateur << de la classe ObjetEmpruntable
ostream& operator<<(ostream& out, const Dvd& dvd){
	out << "Information sur le Dvd :" << endl
		<< (ObjetEmpruntable)dvd
		<< " Realisateur : " << dvd.realisateur_
		<< "; Acteurs : ";
	for (unsigned int i = 0; i < dvd.vecActeurs_.size(); i++){
		out << dvd.vecActeurs_[i] << "; ";
	}
	out << endl;
	return out;
}