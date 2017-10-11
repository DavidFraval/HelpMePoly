/****************************************************************************
* Fichier: ObjetMagique.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Impl�mentation de la classe ObjetMagique
****************************************************************************/
#include <iostream>
#include "ObjetMagique.h"

using namespace std;

ObjetMagique::ObjetMagique()
	: nom_(""), bonus_(0)
{
}

ObjetMagique::ObjetMagique(const std::string& nom, unsigned int bonus)
	: nom_(nom), bonus_(bonus)
{
}

ObjetMagique::~ObjetMagique()
{
}

string ObjetMagique::obtenirNom() const
{
	return nom_;
}

unsigned int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(unsigned int bonus)
{
	bonus_= bonus;
}

/*Une m�thode d�affichage des informations, nomm�e affichage(), qui affichera les
diff�rentes informations contenus dans les attributs*/

void ObjetMagique::affichage() const
{
	cout << "L'objet " << nom_
		<< " fournit un bonus de " << bonus_ << endl;
}
