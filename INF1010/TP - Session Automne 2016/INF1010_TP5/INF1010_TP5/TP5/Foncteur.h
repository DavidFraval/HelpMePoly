/****************************************************************************
* Fichier: Foncteur.h
* Auteur: PolySensei and Associates
* Date: 5 novembre 2016 Mise a jour : 19 novembre 2016
* Description: Impl�mentation des diff�rents foncteurs
****************************************************************************/
#ifndef  FONCTEUR
#define  FONCTEUR

#include <functional>
#include "Dresseur.h"
#include <string>
#include <string>
#include <stdlib.h>

using namespace std;

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la cr�ature pass�e en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

//Ce foncteur prend en argument deux pointeurs de cr�ature et renvoie true si la premi�re cr�ature
//a une attaque inf�rieure � celle de la deuxi�me
class FoncteurComparerCreatures
{
public:
	FoncteurComparerCreatures() {}
	~FoncteurComparerCreatures() {}

	bool operator()(const Creature* creature1, const Creature* creature2) const {
		return (creature1->obtenirAttaque() < creature2->obtenirAttaque());
	}
};

//Ce foncteur prend en argument deux pointeurs de dresseurs et renvoie true si le premier a un
//nom strictement inf�rieur au nom du second. Cette comparaison se fera selon l�ordre
//alphanum�rique.
class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}
	
	bool operator()(const Dresseur* dresseur1, const Dresseur* dresseur2) const {
		return (dresseur1->obtenirNom() < dresseur2->obtenirNom());
	}
};

//Ce foncteur prend en argument deux pointeurs de pouvoir et renvoie true si le premier pouvoir a
//un nombre de d�g�ts inf�rieur � celui du deuxi�me.
class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator()(const Pouvoir* pouvoir1, const Pouvoir* pouvoir2) const {
		if (pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//Ce foncteur prend en argument un pointeur de cr�ature et renvoie true si cette cr�ature a le m�me
//nom que l�attribut de la classe correspondant
class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom(const std::string& creature) : creature_(creature) {}
	~FoncteurCreaturesDeMemeNom() {}
	
	bool operator()(const Creature* creature) const {
		return (creature->obtenirNom() == creature_);
		}
private:
	string creature_;
};

//Ce foncteur prend en argument un pointeur de cr�ature et renvoie true si cette cr�atures est �gale
//� l�attribut creature du foncteur (au sens de leur op�rateur ==).
class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures()
	{
	}

	FoncteurEgalCreatures(Creature* creature): creature_(creature)
	{
	}

	~FoncteurEgalCreatures() {}

	bool operator()(Creature* creature) {
		return creature->obtenirNom() == creature_->obtenirNom();
	}
private:
	Creature* creature_;
};

//Ce foncteur prend en argument un pointeur vers une cr�ature et incr�mente une variable interne
//si les points de vie de la cr�ature sont entre ces bornes
class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(unsigned int vieMin, unsigned int vieMax) : vieMin_(vieMin), vieMax_(vieMax), compteur_(0)
	{
		
	}
	~FoncteurCreatureVie() {}

	unsigned int obtenirCompteur() const
	{
		return compteur_;
	}

	void operator()(const Creature* creature) {
		if (creature->obtenirPointDeVie() <= vieMax_ && creature->obtenirPointDeVie() >= vieMin_)
		{
			compteur_++;
		}
	}
private:
	unsigned int vieMin_;
	unsigned int vieMax_;
	unsigned int compteur_;
};

//Ce foncteur permet de g�n�rer un nombre al�atoire compris dans un intervalle
class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() 
	{
		borneMin_ = RAND_MIN_DEFAUT;
		borneMax_ = RAND_MAX_DEFAUT;
	}
	FoncteurGenerateurNombresAlea(unsigned int borneMin, unsigned int borneMax) : borneMin_(borneMin), borneMax_(borneMax)
	{

	}
	~FoncteurGenerateurNombresAlea() {}
	unsigned int operator() (){
		return (borneMin_ + (rand()%(borneMax_ - borneMin_ + 1)));
	}

private:
	unsigned int borneMin_;
	unsigned int borneMax_;
};

#endif;