/****************************************************************************
* Fichier: EtatConfus.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe EtatConfus
****************************************************************************/

#include "EtatConfus.h"


//Un constructeur qui prend le nom en argument
EtatConfus::EtatConfus(const std::string & nom) :EtatCreature(nom) 
{
	type_ = TypeEtat::TypeEtat_confus;
}
//Un constructeur qui prend le nom et la dur�e de l��tat en argument
EtatConfus::EtatConfus(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_confus;
}
//Destructeur
EtatConfus::~EtatConfus()
{
}
//La m�thode appliquerEtat qui inflige des dommages � la cr�ature, cette derni�re
//perd 5 % de ses points de vie(ou 5 points de vie si les 5 % sont inf�rieurs � 5) avec
//une probabilit� de 33 % .A la fin de cette m�thode, l�attribut dur�e est d�cr�ment�
//de 1 point.
void EtatConfus::appliquerEtat(Creature & creature)
{
	if (rand() % 100 < 33) 
	{
		if (creature.obtenirPointDeVie() >= 100)
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5 / 100 * creature.obtenirPointDeVie());
	}
	else 
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	}		
	duree_--;
}
//La m�thode peutAttaquer qui renvoie true avec une probabilit� de 50 %
bool EtatConfus::peutAttaquer() const
{
	return rand() % 6 <= 2;
}
//La m�thode estFini renvoie true si dur�e est inf�rieur ou �gal � 0, ou
//elle fait un tirage al�atoire et revoie true avec 33 %

bool EtatConfus::estFini() const
{
	if (duree_ <= 0 || (rand() % 100 < 33)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
//Fonction d'affichage
std::ostream & operator<<(std::ostream & o, const EtatConfus & EtatConfus)
{
	o << "etat" << EtatConfus.obtenirNom() << " durera " << EtatConfus.duree_  << std::endl;

	return o;
}