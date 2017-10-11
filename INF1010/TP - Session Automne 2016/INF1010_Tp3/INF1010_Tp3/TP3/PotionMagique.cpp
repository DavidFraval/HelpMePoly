/****************************************************************************
* Fichier: PotionMagique.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe PotionMagique
****************************************************************************/

#include "PotionMagique.h"
#include <iostream>
//Un constructeur par d�faut semblable � celui de la classe m�re
PotionMagique::PotionMagique()
{
}
//Un constructeur par param�tre semblable � celui de la classe m�re
PotionMagique::PotionMagique(const std::string & nom, int bonus) :
	ObjetMagique(nom, bonus)
{
}

//Un destructeur
PotionMagique::~PotionMagique()
{
}
//utiliserSur() rend autant d��nergie que l�attribut bonus de la classe de base

void PotionMagique::utiliserSur(Creature & creature) const
{
	if ((creature.obtenirPointDeVieTotal() - creature.obtenirPointDeVie()) >= obtenirBonus()) {
		creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
	}
	else {
		creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	}
}
//Fonction d'affichage
std::ostream& operator<<(std::ostream& os, const PotionMagique& potion)
{
	return os << "l'objet " << potion.obtenirNom() << " fournit un bonus de " << potion.obtenirBonus() << std::endl;
}
