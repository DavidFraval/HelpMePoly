/****************************************************************************
* Fichier: PouvoirHallucinogene.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe PouvoirHallucinogene
****************************************************************************/

#include "PouvoirHallucinogene.h"
#include <iostream>


PouvoirHallucinogene::PouvoirHallucinogene()
{
}
//Un constructeur par param�tres ayant les m�mes param�tres que celui de la
//classe m�re
PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat_confus;
}
//Un constructeur comprenant les m�mes param�tres que ceux du constructeur
//pr�c�dent ainsi qu�une dur�e
PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_ (duree)
{
	type_ = TypeEtat_confus;
}
//Un destructeur
PouvoirHallucinogene::~PouvoirHallucinogene()
{
}
//appliquerEffetOffensif modifie l��tat de la cr�ature cible vers l��tat confus
void PouvoirHallucinogene::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	EtatConfus* etatConfus = new EtatConfus("Confus", duree_);
	creatureEnnemie.modifierEtat(etatConfus);
}

//Affichage
std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& PouvoirHallucinogene)
{
	return os << PouvoirHallucinogene.obtenirNom() << " possede un nombre de d�gat de " << PouvoirHallucinogene.obtenirNombreDeDegat() <<
		" et une energie necessaire de " << PouvoirHallucinogene.obtenirEnergieNecessaire() << std::endl << " il peut rendre confus la cible" << std::endl;
}
