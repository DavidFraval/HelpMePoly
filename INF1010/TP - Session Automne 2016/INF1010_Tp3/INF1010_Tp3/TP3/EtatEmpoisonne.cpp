/****************************************************************************
* Fichier: EtatEmpoisonne.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe EtatEmpoisonne
****************************************************************************/

#include "EtatEmpoisonne.h"

// Un constructeur qui prend le nom en argument

EtatEmpoisonne::EtatEmpoisonne(const std::string & nom) : EtatCreature(nom) 
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}
//Un constructeur qui prend le nom et la dur�e de l��tat en argument

EtatEmpoisonne::EtatEmpoisonne(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}
//Destructeur
EtatEmpoisonne::~EtatEmpoisonne()
{
}
//La m�thode appliquerEtat d�cr�mente la dur�e et retire 5 points de vie � la
//cr�ature
void EtatEmpoisonne::appliquerEtat(Creature & creature)
{
	creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	duree_--;
}
//La m�thode estFini renvoie true si dur�e est inf�rieur ou �gal � 0

bool EtatEmpoisonne::estFini() const
{
	if (duree_ <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Fonction d'affichage
std::ostream & operator<<(std::ostream & o, const EtatEmpoisonne & EtatEmpoisonne)
{
	o << "etat" << EtatEmpoisonne.obtenirNom() << " durera " << EtatEmpoisonne.duree_ << std::endl;

	return o;
}