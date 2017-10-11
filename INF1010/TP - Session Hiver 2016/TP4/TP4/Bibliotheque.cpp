/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur: PolySensei & Associates
* Date: 22 f�vrier 2016
* Mise a jour : 3 mars 2016
* Description: Impl�mentation de la classe Bibliotheque
****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "Bibliotheque.h"
#include "Abonne.h"
#include "Etudiant.h"
#include "Professeur.h"
#include "EtudiantBaccalaureat.h"

using namespace std;

//Constructeur par d�faut
Bibliotheque::Bibliotheque()
{

}

//Destruction de la liste d'emprunts
Bibliotheque::~Bibliotheque()
{
	// Supprimer uniquement les emprunts
	for (size_t i = 0; i < vecEmprunts_.size(); i++)
	{
		delete vecEmprunts_.back();
		vecEmprunts_.pop_back();
	}
}


// Retourne l'abonn� selon le matricule donn�
Abonne * Bibliotheque::trouverAbonne(const std::string & matricule) const
{
	for (size_t i = 0; i < vecAbonnes_.size(); i++)
	{
		if (*(vecAbonnes_[i]) == matricule)
		{
			return vecAbonnes_[i];
		}
	}
	return nullptr;
}


// Une m�thode trouverObjetEmpruntable() qui prend une cote (string) en param�tre, recherche l�objet empruntable et retourne un pointeur de type ObjetEmpruntable.Si aucun objet empruntable n�est retrouv�, un pointeur nul est retourn� sinon.
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& cote) const
{
	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i]->obtenirCote() == cote){
			return vecObj_[i];
		}
	}
	return nullptr;
}



// Une m�thode obtenirClasseObjet() qui prend une cote (string) en param�tre, et renvoie le nom de la classe correspondant � l�objet ayant cette cote(� Livre �, � DVD �, � LivreNumerique �).
std::string Bibliotheque::obtenirClasseObjet(std::string const & cote) const
{
	for (int i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i]->obtenirCote() == cote){
			return vecObj_[i]->obtenirNomClasse();
		}
	}

	return "";
}



bool Bibliotheque::ajouterAbonne(Abonne& abonne)
{
	// V�rifier s'il est pr�sent dans le vecteur. Si non, l'ajouter
	bool estPresent = false;
	Abonne* ab = trouverAbonne(abonne.obtenirMatricule());
	if (ab != nullptr) {
		for (size_t i = 0; i < vecAbonnes_.size(); i++)
		{
			if ((*vecAbonnes_[i]) == abonne)
				estPresent = true;
		}
	}
	if (!estPresent)
	{
		vecAbonnes_.push_back(&abonne);
	}
	return !estPresent;
}


bool Bibliotheque::retirerAbonne(const string& matricule)
{
	bool estRetire = false;

	for (size_t i = 0; i < vecAbonnes_.size(); i++)
	{
		// Si l'abonne est trouv�, alors swap sa position avec le dernier �l�ment du vecteur, 
		// puis enlever de le dernier �l�ment du vecteur
		if ((*vecAbonnes_[i]) == matricule)
		{
			// Retirer tous les emprunts
			vector<Emprunt*> abEmprunt = vecAbonnes_[i]->obtenirEmprunts();
			for (size_t j = 0; j < abEmprunt.size(); j++)
			{
				retourner(matricule, abEmprunt[j]->obtenirObjEmprunt()->obtenirCote());
			}

			// Retirer l'abonn�
			estRetire = true;
			vecAbonnes_[i] = vecAbonnes_.back();
			vecAbonnes_.pop_back();
		}
	}

	return estRetire;
}

// La m�thode ajouterObjetEmpruntable () qui permet d�ajouter l�ObjetEmpruntable re�u en param�tre seulement s�il n�est pas d�j� dans le vecteur.Si l�ajout a �t� fait, la m�thode renvoie true, false sinon.
bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet)
{
	// V�rifier s'il est pr�sent dans le vecteur. Si non, l'ajouter
	bool estPresent = false;
	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i] == objet){
			estPresent = true;
		}
	}

	if (!estPresent)
	{
		vecObj_.push_back(objet);
	}
	return !estPresent;
}


// La m�thode retirerObjetEmpruntable() qui permet de retirer l�objet empruntable en utilisant la cote re�ue en param�tre. Il est retir� seulement s�il n�est pas emprunt�. La m�thode retourne donc un bool�en true s�il est retir�, sinon false.
bool Bibliotheque::retirerObjetEmpruntable(const std::string & cote)
{
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);

	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		// Si l'objet est trouv�, alors swap sa position avec le dernier �l�ment du vecteur, 
		// puis enlever de le dernier �l�ment du vecteur
		if (vecObj_[i]->obtenirCote() == cote){
			vecObj_[i] = vecObj_.back();
			vecObj_.pop_back();
			return true;
		}
	}
	return false;
}

// La m�thode rechercherObjetEmpruntable() qui prend en param�tre une cha�ne de caract�res(string),
//	o Cette m�thode va rechercher les diff�rents �l�ments empruntables de la biblioth�que qui contiennent l�information d�sir�e en utilisant la m�thode appropri�e de la classe. Pour chaque �l�ment trouv� les informations seront affich�es � l�aide de la m�thode afficherObjetEmpruntable() de la classe ObjetEmpruntable.La m�thode prendra la variable cout comme param�tre d�entr�e.
//	o N�oubliez pas de parcourir tous les �l�ments qui peuvent �tre emprunt� recherche la chaine de mots parmi les attributs de type string de tous les classes de la famille ObjetEmpruntable
void Bibliotheque::rechercherObjetEmpruntable(const string& str) const
{
	bool trouve = false;
	cout << "Recherche pour le mot : " << str << endl;
	//recherche parmi les objets empruntable
	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i]->recherche(str)){
			trouve = true;


			
			vecObj_[i]->afficherObjetEmpruntable(cout);
		}

	}

	if (!trouve)
	{
		cout << "Aucun Resultat Trouve :-(" << endl;
	}
}



bool Bibliotheque::estEmpruntable(const std::string & matricule, const ObjetEmpruntable & objetEmpruntable) const
{	// V�rifie si les conditions de bases sont respect�es et va v�rifier aussi parmi les �l�ments d�riv�s d'Abonne
	bool empruntable = false;
	Abonne* abonne = trouverAbonne(matricule);
	//On doit v�rifier que tous les vecteurs sont parcourus
	if (abonne != nullptr)
	{
		empruntable = (objetEmpruntable.obtenirNbDisponibles() >= 1) &&
			(abonne->obtenirAge() >= objetEmpruntable.obtenirAgeMinimal()) &&
			(!(abonne->estEmprunte(objetEmpruntable))) && abonne->obtenirEmprunts().size()<abonne->obtenirLimiteEmprunt();
	}
	
	return empruntable;
}


// La m�thode emprunter() qui prend en param�tres le matricule d�un abonn�, la cote d�unobjet empruntable et la date de retour associ�e en fonction du statut de l�abonn�.Cette m�thode doit retourner une valeur bool�enne indiquant si l�emprunt a �t� fait ou non.
//	o Elle doit s�assurer que le nombre d�emprunts ne d�passe pas la limite par type d�abonn�.
//	o Elle doit diminuer le nombre d�objets associ�s disponibles.
bool Bibliotheque::emprunter(const string& matricule, const string& cote, unsigned int date)
{
	//On doit v�rifier que tous les vecteurs sont parcourus
	Abonne* ab = trouverAbonne(matricule);

	ObjetEmpruntable* obj = trouverObjetEmpruntable(cote);

	bool peutEmprunte = false;

	if ((ab != nullptr) && (obj != nullptr))
	{
		// V�rifier s'il est possible d'emprunter l'objet, puis l'emprunter

		peutEmprunte = (estEmpruntable(ab->obtenirMatricule(), *obj));

		if (peutEmprunte)
		{
			vecEmprunts_.push_back(new Emprunt(matricule, obj, date));
			ab->ajouterEmprunt(vecEmprunts_.back());
			obj->modifierNbDisponibles(obj->obtenirNbDisponibles() - 1);
			return true;
		}
	}
	return false;

}


bool Bibliotheque::retourner(const string& matricule, const string& cote)
{
	int emPos = -1;
	bool estRetourne = false;

	// Chercher l'emprunt
	for (size_t i = 0; i < vecEmprunts_.size(); i++)
	{
		if ((vecEmprunts_[i]->obtenirMatricule() == matricule) &&
			(*(vecEmprunts_[i]->obtenirObjEmprunt()) == cote))
			emPos = i;
	}


	if (emPos != -1)
	{
		Emprunt* em = vecEmprunts_[emPos];
		ObjetEmpruntable* obj = em->obtenirObjEmprunt();
		//On doit v�rifier que tous les vecteurs sont parcourus
		Abonne* ab = trouverAbonne(matricule);
	
		// V�rifier s'il est possible de retourner l'objetEmpruntable, puis le retourner et d�truire l'emprunt
		estRetourne = ab->estEmprunte(*obj);
		if (estRetourne)
		{
			ab->retirerEmprunt(obj);
			vecEmprunts_[emPos] = vecEmprunts_.back();
			vecEmprunts_.pop_back();
			delete em;
			obj->modifierNbDisponibles(obj->obtenirNbDisponibles() + 1);
		}
	}
	return estRetourne;

}

// La m�thode infoAbonne() qui prend en param�tre un matricule d�abonn� et affiche les informations qui le concerne en utilisant l�op�rateur << appropri�.
//	o Cette m�thode doit d�terminer de quelle sous - classe fait partie l�abonn�.
//	o Une fois d�termin�, la m�thode doit faire un dynamic_cast<> pour obtenir un pointeur de la classe appropri�e, dans le but d�appeler l�op�rateur << .
void Bibliotheque::infoAbonne(const string& matricule) const
{
	//On doit v�rifier que tous les vecteurs sont parcourus
	Abonne* ab = trouverAbonne(matricule);

	if (ab != nullptr)
	{
		// Utilisez dynamic_cast<>()  pour convertir les types de pointeurs et appeler le bon op�rateur <<
		string typeClasse = ab->obtenirNomClasse();
		if (typeClasse == typeid(EtudiantBaccalaureat).name())
		{
			cout << *dynamic_cast<const EtudiantBaccalaureat*> (ab);
		}
		else if (typeClasse == typeid(Etudiant).name())
		{
			cout << *dynamic_cast<const Etudiant*> (ab);
		}
		else if (typeClasse == typeid(Professeur).name())
		{
			cout << *dynamic_cast<const Professeur*> (ab);
		}
		else if (typeClasse == typeid(Abonne).name())
		{
			cout << *dynamic_cast<const Abonne*> (ab);
		}
	}
	else
	{
		cout << "Abonne - " << matricule << " - non trouve" << endl;
	}

}


//Surcharges des op�rateurs demand�s
Bibliotheque & Bibliotheque::operator+=(Abonne * abonne)
{
	
	ajouterAbonne(*abonne);
	return *this;
}


Bibliotheque & Bibliotheque::operator+=(ObjetEmpruntable * obj)
{
	ajouterObjetEmpruntable(obj);
	return *this;
}


Bibliotheque & Bibliotheque::operator-=(Abonne * abonne)
{
	retirerAbonne(abonne->obtenirMatricule());
	return *this;
}

Bibliotheque & Bibliotheque::operator-=(ObjetEmpruntable * obj)
{
	retirerObjetEmpruntable(obj->obtenirCote());
	return *this;
}

std::istream & operator>>(std::istream & in, const Bibliotheque & biblio)
{
	string mot;
	in >> mot;
	biblio.rechercherObjetEmpruntable(mot);
	return in;
}


