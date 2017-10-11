/****************************************************************************
* Fichier: Gestionnaire.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: D�finition de la classe Gestionnaire
****************************************************************************/

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <algorithm>
#include <list>
#include <string>
using namespace std;

template <typename T>
class Gestionnaire
{
public:
	Gestionnaire(){}
	~Gestionnaire(){}

	bool ajouterElement(T* ptrElement);
	bool retirerElement(T* ptrElement);

	template <typename P>
	bool retirerContenu(P& predicat);
	template <typename P>
	T* trouverElement(const P& predicat) const;

	bool trouverElement(const T& element) const;

	template <typename P>
	list<T*> trouverContenu(const P& predicat) const;

	
private:
	list<T*> conteneur_;

};
#endif //GESTIONNAIRE_H



//Une m�thode ajouterElement() qui re�oit un pointeur de l��l�ment en param�tre et qui permet de l�ajouter seulement s�il n�est pas d�j� dans le conteneur.Si l�ajout a �t� fait, la m�thode renvoie true, false sinon.
template <typename T>
bool Gestionnaire<T>::ajouterElement(T* ptrElement)
{
	bool estAjoute = false;
	list<T*>::iterator it = find(conteneur_.begin(), conteneur_.end(), ptrElement);

	if (it == conteneur_.end())
	{
		estAjoute = true;
		conteneur_.push_back(ptrElement);
	}

	return estAjoute;
}


// Une m�thode retirerElement () qui re�oit un pointeur de l��l�ment en param�tre et qui permet de le retirer du conteneur.Si le retrait a �t� fait, la m�thode renvoie true, false sinon.
template <typename T>
bool Gestionnaire<T>::retirerElement(T* ptrElement)
{
	bool estRetire = false;
	int nElementInitial = conteneur_.size();

	conteneur_.remove(ptrElement);

	if (nElementInitial > conteneur_.size())
	{
		estRetire = true;
	}

	return estRetire;
}


// Une m�thode g�n�rique sur le predicat, retirerContenu() qui prend un pr�dicat unaire(Predicate&) en param�tre, retire l�objet ou les objets dans le conteneur qui v�rifie le pr�dicat et retourne true si au moins un �l�ment est retir�, false sinon. Un pr�dicat unaire une fonction qui a un seul param�tre et retourne un bool�en.
template <typename T>
template <typename P>
bool Gestionnaire<T>::retirerContenu(P& predicat)
{
	bool estRetire = false;
	int nElementInitiale = conteneur_.size();

	conteneur_.remove_if(predicat);

	if (nElementInitiale > conteneur_.size())
	{
		estRetire = true;
	}
	return estRetire;
}


// Une m�thode g�n�rique sur le pr�dicat trouverElement() qui prend un pr�dicat unaire(Predicate&) en param�tre, recherche l�objet qui v�rifie le pr�dicat et retourne un pointeur de type T.Si aucun objet n�est retrouv�, un pointeur nul est retourn� sinon.
template <typename T>
template <typename P>
T* Gestionnaire<T>::trouverElement(const P& predicat) const
{
	auto it = find_if(conteneur_.begin(), conteneur_.end(), predicat);
	if (it != conteneur_.end())
	{
		return *it;
	}
	return nullptr;
}


// Une m�thode trouverElement() qui est une surcharge de la m�thode pr�c�dente, elle prend un �l�ment de type T re�u en param�tre, recherche l�objet et retourne true si l��l�ment est trouv�, false sinon.
template <typename T>
bool Gestionnaire<T>::trouverElement(const T& element) const
{
	bool estTrouve = false;
	list<T*>::iterator it = find(conteneur_.begin(), conteneur_.end(), &element);

	if (it != conteneur_.end() || !(conteneur_.empty()))
	{
		estTrouve = true;
	}

	return estTrouve;
}


// Une m�thode g�n�rique sur le pr�dicat, trouverContenu() qui prend un pr�dicat unaire(Predicate&) en param�tre, recherche tous les objets qui v�rifient le pr�dicat et retourne une liste de pointeur de type T.Si aucun objet n�est retrouv�, une liste vide est retourn�e sinon.
template <typename T>
template <typename P> 
list<T*> Gestionnaire<T>::trouverContenu(const P& predicat) const
{
	list<T*> conteneurRetour(conteneur_.size());
	list<T*>::iterator it = copy_if(conteneur_.begin(), conteneur_.end(), conteneurRetour.begin(), predicat);
	conteneurRetour.resize(distance(conteneurRetour.begin(), it));
	return conteneurRetour;
}