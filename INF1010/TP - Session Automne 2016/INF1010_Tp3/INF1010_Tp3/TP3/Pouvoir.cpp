/****************************************************************************
* Fichier: Pouvoir.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe Pouvoir
****************************************************************************/

#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
{
}

Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire), type_(TypeEtat_normal)
{
}


Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

TypeEtat Pouvoir::obtenirType() const
{
    return type_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

Pouvoir::Pouvoir(const Pouvoir& pouvoir)
{
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
    type_ = pouvoir.obtenirType();
}

Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir)
{
	if (this != &pouvoir)
	{
		nom_ = pouvoir.nom_;
		nombreDeDegat_ = pouvoir.nombreDeDegat_;
		energieNecessaire_ = pouvoir.energieNecessaire_;
        type_ = pouvoir.obtenirType();
	}
	return *this;
}

bool Pouvoir::operator==(const Pouvoir& pouvoir) const
{
	return (nom_ == pouvoir.nom_);
}
//AppliquerEffetOffensif : si un pouvoir doit changer l��tat d�une cr�ature adverse,
//c�est cette m�thode qui est responsable de cette action.La cr�ature adverse sera
//pass�e en arguments.
void Pouvoir::appliquerEffetOffensif(Creature & creatureEnnemie)
{
    //Pas d�faut le pouvoir n'a pas d'effet suppl�mentaire
    //il inflige juste des d�gats
    return;
}
//AppliquerEffetDefensif : si un pouvoir doit apporter un bonus � l�attaquant c�est
//cette m�thode qui en sera responsable.C�est la cr�ature(l�attaquant) elle - m�me
//qui sera pass�e en argument.

void Pouvoir::appliquerEffetDefensif(Creature & creatureAllie)
{
    //par d�faut un pouvoir n'apas d'effet sur la 
    //creature qui lance le pouvoir

    return;
}

std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir)
{
	return os << pouvoir.nom_ << " possede un nombre de d�gat de " << pouvoir.nombreDeDegat_ <<
        " et une energie necessaire de " << pouvoir.energieNecessaire_ << std::endl;
}
