/****************************************************************************
* Fichier: Elixir.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Impl�mentation de la classe Elixir
****************************************************************************/

#include "Elixir.h"
//Un constructeur par d�faut semblable � celui de la classe m�re
Elixir::Elixir()
{
}
//Un constructeur par param�tre semblable � celui de la classe m�re
Elixir::Elixir(const std::string & nom, int bonus) :
	PotionMagique(nom, bonus)
{
}


Elixir::~Elixir()
{
}
//tiliserSur rend autant d��nergie que l�attribut bonus de la classe de base et
//2 * bonus points de vie
void Elixir::utiliserSur(Creature & creature) const
{
	PotionMagique::utiliserSur(creature);
	ObjetMagique::utiliserSur(creature);
}
//Fonction d'affichage
std::ostream& operator<<(std::ostream& os, const Elixir& elixir)
{
	return os << "l'objet " << elixir.nom_ << "fournit un bonus de " << elixir.bonus_ << std::endl;
}
