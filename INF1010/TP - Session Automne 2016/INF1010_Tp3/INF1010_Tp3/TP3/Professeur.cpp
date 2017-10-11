/****************************************************************************
* Fichier: Professeur.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe Professeur
****************************************************************************/
#include <iostream>
#include "Professeur.h"

using namespace std;

// Un constructeur par d�faut.
Professeur::Professeur() {

}

// Un constructeur par param�tres qui initialise les attributs en fonction des param�tres.
Professeur::Professeur(const std::string& nom, const std::string& equipe)
	: Dresseur(nom, equipe), outilScientifique_ (nullptr)
{

}

Professeur::Professeur(const Professeur& professeur)
{
	modifierNom(professeur.obtenirNom());
	modifierEquipe(professeur.obtenirEquipe());
}


// Le destructeur pour cette classe.
Professeur::~Professeur()
{

}

// Les m�thodes d�acc�s de modification au nouvel attribut.

OutilScientifique* Professeur::obtenirOutilScientifique() const 
{
	return outilScientifique_;
}

void Professeur::modifierOutil(OutilScientifique outilScientifique)
{
	outilScientifique_ = &outilScientifique;
}



// Une m�thode utiliserOutil qui s�applique � une cr�ature.
void Professeur::utiliserOutil(Creature creature)
{
	outilScientifique_->utiliser(creature);
}


// Une m�thode soigner qui r�tablit les points de vie et l��nergie de la cr�ature(pass�e en
//	argument) � leur valeur maximale

void Professeur::soigner(Creature& creature)
{
	creature.modifierEnergie(creature.obtenirEnergieTotale());
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
}


// L�op�rateur << , qui affiche les informations du Professeur, tel que pr�sent� dans
// l�exemple � la fin du document. Il doit appeler l�op�rateur << de la classe Abonne.
Professeur& Professeur::operator=(Professeur& professeur)
{
	if (this != &professeur)
	{
		modifierNom(professeur.obtenirNom());
		modifierEquipe(professeur.obtenirEquipe());
		outilScientifique_ = professeur.outilScientifique_;
	}

	return *this;
}
