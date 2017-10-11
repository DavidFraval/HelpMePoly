/****************************************************************************
* Fichier: Empruntable.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: D�finition et impl�mentation du foncteur Empruntable
****************************************************************************/
#ifndef Empruntable_H
#define Empruntable_H

#include <list>
#include <algorithm>
#include <string>
#include "Emprunt.h"

using namespace std;

// Foncteur pr�dicat unaire pour un algorithme de la librairie STL qui permet de compter les emprunts de l�abonne et qui permet de v�rifier si l�objet a �t� d�j� emprunt�.
class Empruntable
{
public:

	Empruntable::Empruntable(string matricule, string cote, int* compteur, bool* dejaEmprunte) : matricule_(matricule), cote_(cote), compteur_(compteur), dejaEmprunte_(dejaEmprunte) {}

	bool operator()(Emprunt* ptrEmprunt)
	{
		if (ptrEmprunt->obtenirMatricule() == matricule_)
		{
			(*compteur_)++; // permet de compter les emprunts de l�abonne
			if (ptrEmprunt->obtenirObjetEmpruntable()->obtenirCote() == cote_)
			{
				*dejaEmprunte_ = true; //permet de v�rifier si l�objet a �t� d�j� emprunt�;
			}
			return true;
		}
		return false;
	}

private:
	//Attributs demand�s
	string matricule_;
	string cote_;
	int* compteur_;
	bool* dejaEmprunte_;

};
#endif
