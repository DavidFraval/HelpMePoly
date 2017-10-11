/****************************************************************************
* Fichier: Livre.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: Impl�mentation de la classe Livre
****************************************************************************/
#include <iostream>
#include "Livre.h"

using namespace std;


Livre::Livre()
{

}

// Un constructeur par param�tres qui initialise en plus les nouveaux attributs.
Livre::Livre(const std::string &cote, const std::string &titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string &auteur, const std::string &genre) : ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), auteur_(auteur), genre_(genre)
{

}

Livre::~Livre()
{

}


// La m�thodes d�acc�s et de modifications pour les nouveaux attributs : obtenirAuteur(), obtenirGenre(), modifierAuteur(), modifierGenre()
std::string Livre::obtenirAuteur() const							
{
	return auteur_;
}

std::string Livre::obtenirGenre() const
{
	return genre_;
}

void Livre::modifierAuteur(const std::string& unAuteur){
	auteur_ = unAuteur;
}

void Livre::modifierGenre(const std::string& unGenre){
	genre_ = unGenre;
}




// Une red�finition de la m�thode rechercher() qui va aussi v�rifier si la cha�ne de
// caract�res est pr�sente dans les nouveaux attributs de type string
bool Livre::recherche(const std::string& motsCle) const{		

	bool estTrouve = false;

	std::size_t trouveAuteur = convertirMinuscule(auteur_).find(convertirMinuscule(motsCle));
	std::size_t trouveGenre = convertirMinuscule(genre_).find(convertirMinuscule(motsCle));

	estTrouve = ObjetEmpruntable::recherche(motsCle) || 
		(trouveAuteur != string::npos) ||
		(trouveGenre != string::npos);

	return estTrouve;

}



// L�op�rateur << qui affiche les informations du Livre, tel que pr�sent� dans l�exemple � la
// fin du document. Il doit appeler l�op�rateur << de la classe ObjetEmpruntable.
ostream& operator<<(ostream& out, const Livre& livre){
	out << "Information sur le livre :" << endl
		<< (ObjetEmpruntable)livre
		<< " Auteur : " << livre.auteur_
		<< "; Genre : " << livre.genre_ << endl;
	return out;
}