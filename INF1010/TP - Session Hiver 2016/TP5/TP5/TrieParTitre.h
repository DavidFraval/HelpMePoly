/****************************************************************************
* Fichier: TrieParTitre.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: D�finition du foncteur TrieParTitre
****************************************************************************/
#ifndef TrieParTitre_H
#define TrieParTitre_H

#include "ObjetEmpruntable.h"

// Ce foncteur est un pr�dicat binaire qui permet de comparer les titres de deux ObjetEmpruntable, il retourne true si les titres sont en ordre alphab�tique, false sinon.
class TrieParTitre
{
public:
	
	bool operator()(ObjetEmpruntable* ptrObjet1, ObjetEmpruntable* ptrObjet2)
	{
		if (*ptrObjet1 < *ptrObjet2)
		{
			return true;
		}
		return false;
	}
};

#endif


