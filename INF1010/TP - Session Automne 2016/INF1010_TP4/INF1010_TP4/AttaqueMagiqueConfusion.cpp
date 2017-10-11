

#include "AttaqueMagiqueConfusion.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Un constructeur par d�faut qui initialise la dur�e � 2

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() : AttaqueMagique(DUREE_MIN)
{

}
//Un constructeur qui prend en param�tre une dur�e

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(int duree) : AttaqueMagique(duree)
{

}
//Un destructeur
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{

}
//Une m�thode appliquerAttaque(). L�attaque magique poison permet, dans le tiers
//des cas, de r�duire les points de vie de la cr�ature adverse de 2 points, dans le
//cas o� celle - ci � au moins 5 points de vie(si bien - s�r la dur�e de l�attaque magique
//	n�est pas nulle).Dans les autres cas, rien ne se passe.
void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature)
{
	if (rand() % 3 < 1 && creature.obtenirPointDeVie() >= 5 && duree_ != 0)
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVie() - 2);
	}
}
//Une m�thode estFini() qui retourne vraie si la dur�e est nulle 
bool AttaqueMagiqueConfusion::estFini()
{
	if (duree_ == 0)
	{
		return true;
	}
	return false;
}
