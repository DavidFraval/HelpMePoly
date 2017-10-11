/****************************************************************************
* Fichier: RechercheObjetEmpruntable.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: D�finition et impl�mentation du foncteur RechercheObjetEmpruntable
****************************************************************************/


#ifndef RECHERCHEOBJETEMPRUNTABLE_H
#define RECHERCHEOBJETEMPRUNTABLE_H
#include "ObjetEmpruntable.h"


//�crire un foncteur pr�dicat unaire pour un algorithme de la librairie STL qui permet de chercher un string dans les objets empruntables.Il va rechercher les diff�rents �l�ments empruntables dans le gestionnaire d�objet de la biblioth�que qui contiennent l�information d�sir�e.Il retourne true si l�information a �t� trouv�e, false sinon.
class RechercheObjetEmpruntable
{
public:

	RechercheObjetEmpruntable(const std::string& str) :motCle_(str) {};

	bool operator()(ObjetEmpruntable* ptrObjet)
	{
		return ptrObjet->recherche(motCle_);
	}

private:
	std::string motCle_;


};

#endif


