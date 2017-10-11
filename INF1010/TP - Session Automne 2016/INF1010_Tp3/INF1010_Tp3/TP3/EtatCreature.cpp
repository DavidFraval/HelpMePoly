/****************************************************************************
* Fichier: EtatCreature.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe EtatCreature
****************************************************************************/

#include "EtatCreature.h"

#include "Creature.h"


//Un constructeur par param�tre qui prend comme argument le nom de l��tat,
EtatCreature::EtatCreature(const std::string & nom) : nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_normal)
{
}
//Un constructeur par param�tre qui prend comme argument le nom de l��tat et une dur�e
EtatCreature::EtatCreature(const std::string & nom, unsigned int duree) : nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_normal)
{
}
//Destructeur
EtatCreature::~EtatCreature()
{
}
//Une m�thode appliquerEtat qui sera surcharg�e dans les classes d�riv�es
void EtatCreature::appliquerEtat(Creature & creature)
{
}
//Une m�thode peutAttaquer qui d�termine si une cr�ature peut attaquer � ce tour. 
bool EtatCreature::peutAttaquer() const
{
    return rand() % 6 != 0;
}
//Une m�thode estFini qui caract�rise si la cr�ature peut revenir � un �tat normal. 
bool EtatCreature::estFini() const
{
    return false;
}
//Deux accesseurs pour le nom et l�attribut type
std::string EtatCreature::obtenirNom() const
{
    return nom_;
}

TypeEtat EtatCreature::obtenirType() const
{
    return type_;
}
//La fonction friend : operateur<< , pour afficher le nom de l��tat.
std::ostream & operator<<(std::ostream & o, const EtatCreature & etatCreature)
{
    o << "etat" << etatCreature.nom_ << std::endl;

    return o;
}
