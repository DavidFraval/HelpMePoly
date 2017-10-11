/****************************************************************************
* Fichier: EtatEndormis.cpp
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe EtatEndormis
****************************************************************************/

#include "EtatEndormis.h"


//Un constructeur qui prend le nom en argument
EtatEndormi::EtatEndormi(const std::string & nom) : EtatCreature(nom)  
{
	type_ = TypeEtat::TypeEtat_endormi;
}
//Un constructeur qui prend le nom et la dur�e de l��tat en argument
EtatEndormi::EtatEndormi(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)  
{
	type_ = TypeEtat::TypeEtat_endormi;
}
//Un destructeur
EtatEndormi::~EtatEndormi()
{
}
//La m�thode appliquerEtat d�cr�mente la dur�e si la dur�e est positive
void EtatEndormi::appliquerEtat(Creature & creature)
{
	if (duree_ > 0) {
		duree_--;
	}
}
// La m�thode peutAttaquer qui renvoie false
bool EtatEndormi::peutAttaquer() const
{
	return false;
}
//La m�thode estFini renvoie true si dur�e est inf�rieur ou �gal � 0

bool EtatEndormi::estFini() const
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
std::ostream & operator<<(std::ostream & o, const EtatEndormi & EtatEndormi)
{
	o << "etat" << EtatEndormi.obtenirNom() << " durera " << EtatEndormi.duree_ << std::endl;

	return o;
}