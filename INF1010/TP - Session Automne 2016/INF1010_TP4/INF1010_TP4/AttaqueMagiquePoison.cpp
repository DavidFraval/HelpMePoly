

#include "AttaqueMagiquePoison.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//Un constructeur par d�faut qui initialise la dur�e � 2

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(DUREE_MIN)
{

}
//Un constructeur qui prend en param�tre une dur�e
AttaqueMagiquePoison::AttaqueMagiquePoison(int duree) : AttaqueMagique(duree)
{

}
//Un destructeur
AttaqueMagiquePoison::~AttaqueMagiquePoison()
{

}
//Une m�thode appliquerAttaque(). L�attaque magique poison permet, dans le tiers
//des cas, de r�duire l��nergie de la cr�ature adverse de 2 points, dans le cas o�
//celle - ci � au moins 5 points d��nergie(si bien - s�r la dur�e de l�attaque magique
//n�est pas nulle).Dans les autres cas, rien ne se passe.

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature)
{
	if (rand() % 3 < 1 && creature.obtenirEnergie() >= 5 && duree_ != 0)
	{
		creature.modifierEnergie(creature.obtenirEnergie() - 2);
	}
}
//Une m�thode estFini() qui retourne vraie si la dur�e est nulle
bool AttaqueMagiquePoison::estFini()
{
	if (duree_ == 0)
	{
		return true;
	}
	return false;
}
