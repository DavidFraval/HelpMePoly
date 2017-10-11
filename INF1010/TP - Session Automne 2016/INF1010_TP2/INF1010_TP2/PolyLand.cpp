/****************************************************************************
* Fichier: PolyLand.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Impl�mentation de la classe PolyLand
****************************************************************************/

#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//Un constructeur par d�faut.

PolyLand::PolyLand() :dresseurs_(), creatures_() 
{
}

vector<Dresseur*> PolyLand::obtenirDresseurs() const
{
	return dresseurs_;
}

//Un destructeur 

PolyLand::~PolyLand()
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		delete dresseurs_[i];
		dresseurs_[i] = nullptr;
	}
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
}

//La m�thode ajouterDresseur qui permet d�ajouter un dresseur re�u en param�tre ; deux
//dresseurs ne peuvent pas avoir le m�me nom.

bool PolyLand::ajouterDresseur(Dresseur* dresseur) 
{
	if (dresseurs_.size() >= MAX_DRESSEURS)
		return false;
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (dresseurs_[i] == dresseur)
			return false;
	}
	dresseurs_.push_back(dresseur);
	std::cout << dresseur->obtenirNom() << " a bien �t� ajout� !" << std::endl;
	return true;
}

//La m�thode ajouterCreature qui permet d�ajouter une cr�ature re�ue en param�tre; deux
//cr�atures ne peuvent pas avoir le m�me nom.

bool PolyLand::ajouterCreature(Creature* creature) 
{
	if(creatures_.size() >= MAX_CREATURES)
		return false;
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (creatures_[i] == creature)
			return false;
	}
	creatures_.push_back(creature);
	std::cout << creature->obtenirNom() << " a bien �t� ajout� !" << std::endl;
	return true;
}

//La m�thode retirerDresseur qui permet de retirer le dresseur en utilisant le nom re�u en
//param�tre.

bool PolyLand::retirerDresseur(const std::string& nom) 
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (*dresseurs_[i] == nom)
		{
			delete dresseurs_[i];
			dresseurs_[i] = dresseurs_[dresseurs_.size() - 1];
			dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}

//La m�thode retirerCreature qui permet de retirer la cr�ature en utilisant le nom re�u en
//param�tre.

bool PolyLand::retirerCreature(const std::string& nom) 
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
		{
			delete creatures_[i];
			creatures_[i] = creatures_[creatures_.size() - 1];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() 
{
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() 
{
	if (creatures_.size() > 0) 
    {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature) 
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

//L�op�rateur << (remplace la m�thode d�affichage), qui affiche les informations qui
//concernant Polyland

ostream& operator<<(ostream& out, const PolyLand& polyLand)
{
	for (unsigned int i = 0; i < polyLand.obtenirDresseurs().size(); i++){
		out << polyLand.obtenirDresseurs()[i]->obtenirNom() << " possede " << polyLand.obtenirDresseurs()[i]->obtenirVecteurCreatures().size() <<
			" creature(s) et appartient a l'equipe " << polyLand.obtenirDresseurs()[i]->obtenirEquipe() << endl;
			for (unsigned int j = 0; j < polyLand.obtenirDresseurs()[i]->obtenirVecteurCreatures().size(); j++)
			{
				std::cout << "- " << j + 1 << " - " <<
				polyLand.obtenirDresseurs()[i]->obtenirVecteurCreatures()[j]->obtenirNom() <<endl;
			}
	}
	return out;
}

//L�op�rateur += qui prend en param�tre un dresseur, qui l�ajoute au vecteur de dresseurs
//et qui retourne la Polyland avec les nouvelles modifications.Le comportement de cette
//surcharge d�op�rateur �tre tr�s similaire � ajouterDresseur.

void PolyLand::operator+=(Dresseur* dresseur) {
	ajouterDresseur(dresseur);
}

//L�op�rateur -= qui prend en param�tre un dresseur, qui l�enl�ve du vecteur de dresseurs
//et qui retourne la Polyland avec les nouvelles modifications.Le comportement de cette
//surcharge d�op�rateur �tre tr�s similaire � retirerDresseur.

void PolyLand::operator-=(Dresseur* dresseur) {
	retirerDresseur(dresseur->obtenirNom());
}

//L�op�rateur += qui prend en param�tre une cr�ature, qui l�ajoute au vecteur de cr�atures
//et qui retourne la Polyland avec les nouvelles modifications.Le comportement de cette
//surcharge d�op�rateur �tre tr�s similaire � ajouterCreature.

void PolyLand::operator+=(Creature* creature) {
	ajouterCreature(creature);
}

//L�op�rateur -= qui prend en param�tre une cr�ature, qui l�enl�ve du vecteur de cr�atures
//et qui retourne la Polyland avec les nouvelles modifications.Le comportement de cette
//surcharge d�op�rateur �tre tr�s similaire � retirerCreature.

void PolyLand::operator-=(Creature* creature) {
	retirerCreature(creature->obtenirNom());
}