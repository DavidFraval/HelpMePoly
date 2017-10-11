/****************************************************************************
* Fichier: Dresseur.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Impl�mentation de la classe Dresseur
****************************************************************************/

#include "Dresseur.h"
#include <iostream>
#include <string>

using namespace std;

//Un constructeur par d�faut qui initialise les quatre attributs aux valeurs par d�faut.

Dresseur::Dresseur() :nom_(""), equipe_(""), objetMagique_(), vecCreatures_()
{
	
}

//Un constructeur qui prend un param�tre un nom et une �quipe et qui initialise les attributs
//correspondants.Les autres attributs seront initialis�s par d�faut.

Dresseur::Dresseur(const string& nom, const string& equipe):nom_(nom), equipe_(equipe), objetMagique_(), vecCreatures_()
{

}

//Destructeur

Dresseur::~Dresseur()
{
	
}

string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}


void Dresseur::modifierCreature(Creature* creatures)
{
	for (int i = 0; i < vecCreatures_.size(); i++) {
		if(vecCreatures_[i] == creatures)
			vecCreatures_[i] = creatures;
	}
	
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(Creature* creature)
{
	for (unsigned int i = 0; i < vecCreatures_.size(); i++)
	{
		if (vecCreatures_[i]->obtenirNom() == creature->obtenirNom())
			return false;
	}
	vecCreatures_.push_back(creature);
	return true;
}



bool Dresseur::enleverCreature(const string& nom)
{
	for (unsigned int i = 0; i < vecCreatures_.size(); i++)
	{
		if (vecCreatures_[i]->obtenirNom() == nom)
		{
			vecCreatures_[i] = nullptr;
			vecCreatures_.pop_back();
			return true;
		}
	}
	return false;
}

// surchage de l'op�rateur <<

ostream& operator<<(ostream& out, const Dresseur& dresseur) {
	out << dresseur.nom_ << " possede " << dresseur.vecCreatures_.size() << " creature(s) et appartient a l'�quipe "
		<< dresseur.equipe_ << endl;

	return out;
}

// ___TP2___

string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const string& equipe)
{
	equipe_ = equipe;
}

vector<Creature*> Dresseur::obtenirVecteurCreatures() const {
	return vecCreatures_;
}

//surcharge de l'operateur == (dresseur1 == dresseur2)

bool Dresseur::operator==(Dresseur& dresseur){
	bool estEgal = false;
	int temp = 0;
	if (vecCreatures_.size()== dresseur.obtenirVecteurCreatures().size()) {

		for (unsigned int i = 0; i < vecCreatures_.size(); i++) {
			for (unsigned int j = 0; j < vecCreatures_.size(); j++) {
				if (vecCreatures_[i]->obtenirNom() == dresseur.vecCreatures_[j]->obtenirNom()) {
					temp++;
				}
			}
		}
	if (temp==vecCreatures_.size())
		estEgal = true;
	}
	return estEgal;
}

//surcharge de l'operateur == (dresseur == nom)

bool Dresseur::operator==(const string& nom) const {
	bool estEgal = false;

	if (nom_ == nom) {
		estEgal = true;
				}
	return estEgal;
}

//La m�thode obtenirUneCreature qui prend en param�tre le nom d�une cr�ature et qui
//retourne cette cr�ature.Cette methode renvoie un pointeur sur une creature.

Creature* Dresseur::obtenirUneCreature(const string& nom) const
{
	for (int i = 0; i < vecCreatures_.size(); i++) {
		if (*vecCreatures_[i] == nom) {
			return vecCreatures_[i];
		}
	}
}

//L�op�rateur == de type friend qui permet d�inverser l�ordre de l�op�rateur == pr�c�dent.
//Ainsi, cet op�rateur va pouvoir faire l�op�ration nom == dresseur.

bool operator==(const string& nom, const Dresseur& dresseur) {
	bool estEgal = false;

	if (dresseur == nom) {
		estEgal = true;
	}
	return estEgal;
}