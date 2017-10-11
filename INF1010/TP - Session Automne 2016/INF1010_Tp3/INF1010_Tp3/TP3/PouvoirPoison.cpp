/****************************************************************************
* Fichier: PouvoirPoison.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe PouvoirPoison
****************************************************************************/

#include "PouvoirPoison.h"
#include <iostream>


PouvoirPoison::PouvoirPoison()
{
}
//Un constructeur par param�tres ayant les m�mes param�tres que celui de la
//classe de base

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat_empoisonne;
}
//Un constructeur comprenant les m�mes param�tres que ceux du constructeur
//pr�c�dent ainsi qu�une dur�e
PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_ (duree)
{
	type_ = TypeEtat_empoisonne;
}
//Un destructeur
PouvoirPoison::~PouvoirPoison()
{
}
//appliquerEffetOffensif modifie l��tat de la cr�ature cible vers l��tat empoisonn�
void PouvoirPoison::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	EtatEmpoisonne* etatEmpoisonne = new EtatEmpoisonne("Empoisonne", duree_);
	creatureEnnemie.modifierEtat(etatEmpoisonne);
}

//Fonction d'affichage
std::ostream& operator<<(std::ostream& os, const PouvoirPoison& PouvoirPoison)
{
	return os << PouvoirPoison.obtenirNom() << " possede un nombre de d�gat de " << PouvoirPoison.obtenirNombreDeDegat() <<
		" et une energie necessaire de " << PouvoirPoison.obtenirEnergieNecessaire() << std::endl << "il peut empoisonner la cible" << std::endl;
}
