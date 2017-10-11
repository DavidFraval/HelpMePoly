/****************************************************************************
* Fichier: Bibliotheque.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: D�finition du foncteur Bibliotheque
****************************************************************************/

#include "Bibliotheque.h"
#include <map>
using namespace std; 

//Un constructeur par d�faut.
Bibliotheque::Bibliotheque() {}


//Un destructeur (foncteur DetruireEmprunt).
Bibliotheque::~Bibliotheque()
{
	gestEmprunts_.retirerContenu(DetruireEmprunt());
}


// Une m�thode trouverAbonne () qui prend un matricule (string) en param�tre, elle doit cr�er le foncteur MemeObjet, recherche l�abonn� dans le gestionnaire et retourne un pointeur de type Abonne.Si aucun abonn� n�est retrouv�, un pointeur nul est retourn� sinon.
Abonne* Bibliotheque::trouverAbonne(const std::string& matricule) const 
{

	Abonne* ptrAbonne;
	MemeObjet<Abonne, const string> memeAbonne(&matricule);
	ptrAbonne = gestAbonnes_.trouverElement(memeAbonne);
	return ptrAbonne; //
}


// La m�thode ajouterAbonne () qui permet d�ajouter l�abonn� re�u en param�tre dans le gestionnaire appropri�.
bool Bibliotheque::ajouterAbonne(Abonne& abonne) 
{
	bool estAjoute = false;
	estAjoute = gestAbonnes_.ajouterElement(&abonne);
	return estAjoute;
}


// La m�thode retirerAbonne () qui permet de retirer l�abonn� en utilisant le matricule re�u en param�tre.La m�thode doit cr�er le foncteur MemeObjet. Avant de le retirer, il faut retourner tous les objets qu�il a emprunt�s.La m�thode retourne donc un bool�en true s�il est retir�, sinon false.
bool Bibliotheque::retirerAbonne(const std::string& matricule)
{
	bool estRetire = false;
	Abonne* ptrAbonne = trouverAbonne(matricule);

	if (ptrAbonne == nullptr){
		estRetire = false;
	}
	else
	{
		MemeObjet<Emprunt, const string> memeAbonne(&matricule); 
		list<Emprunt*> listeEmprunt = gestEmprunts_.trouverContenu(memeAbonne); // On trouve tous les emprunts de l'abonne

		//Boucle pour retourner tous les objets emprunt�s par l'abonn�.
		for (list<Emprunt*>::iterator it = listeEmprunt.begin(); it != listeEmprunt.end(); it++)
		{
			retourner(matricule, ((**it).obtenirObjetEmpruntable()->obtenirCote()));
		}
		gestAbonnes_.retirerElement(ptrAbonne);
		estRetire = true;
	}
	return estRetire;
}


// Une m�thode trouverObjetEmpruntable () qui prend une cote (string) en param�tre, elle doit cr�er le foncteur MemeObjet, recherche l�objet empruntable dans le gestionnaire et retourne un pointeur de type ObjetEmpruntable.Si aucun objet empruntable n�est retrouv�, un pointeur nul est retourn� sinon.
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& cote) const 
{
	MemeObjet<ObjetEmpruntable, const string> memeObjetEmpruntable(&cote);
	ObjetEmpruntable* ptrObjet = gestObj_.trouverElement(memeObjetEmpruntable);
	return ptrObjet;
}


// La m�thode ajouterObjetEmpruntable () qui permet d�ajouter l�ObjetEmpruntable re�u en param�tre dans le gestionnaire appropri�.
bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet) 
{
	bool estAjoute = false;
	estAjoute = gestObj_.ajouterElement(objet);
	return estAjoute;
}


// La m�thode retirerObjetEmpruntable() qui permet de retirer l�objet empruntable en utilisant la cote(string) re�ue en param�tre, elle doit cr�er le foncteur MemeObjet.L�objet est retir� seulement s�il n�est pas emprunt�.La m�thode retourne donc un bool�en true s�il est retir�, sinon false.
bool Bibliotheque::retirerObjetEmpruntable(const std::string& cote)
{
	bool estRetire = false;

	MemeObjet<Emprunt, const string> memeObjetEmpruntable(&cote);
	list<Emprunt*> listeEmpruntObjet = gestEmprunts_.trouverContenu(memeObjetEmpruntable); //Trouve les emprunts associ� � l'objet.
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);	// Trouve l'adresse de l'objet.

	if (listeEmpruntObjet.size() == 0) //Si l'objet n'est pas emprunt�.
	{
		estRetire = gestObj_.retirerElement(ptrObjet);
	}

	return estRetire;
}


// La m�thode rechercherObjetEmpruntable() qui prend en param�tre une cha�ne de caract�res(string), elle doit cr�er les foncteurs RechercheObjetEmpruntable et TrieParTitre .
//	o Cette m�thode va rechercher les diff�rents �l�ments empruntables de la biblioth�que qui contiennent l�information d�sir�e en utilisant la m�thode appropri�e de la classe gestionnaire.
//	o La m�thode doit trier les objets par ordre alphab�tique selon leur titre � l�aide du foncteur et de l�algorithme de tri avant de les afficher.
//	o Pour chaque �l�ment trouv�, les informations seront affich�es � l�aide de la fonction op�rator << .
//	o Si rien n�a �t� trouv�, affichez un message.
void Bibliotheque::rechercherObjetEmpruntable(const std::string& str) const
{
	cout << "Recherche pour le mot : " << str << endl;
	RechercheObjetEmpruntable rechercheMot(str);
	list<ObjetEmpruntable*> listeObjetTrouve = gestObj_.trouverContenu(rechercheMot);
	listeObjetTrouve.sort(TrieParTitre());

	if (listeObjetTrouve.empty())
	{
		cout << "Aucun resultat trouve :(" << endl;
	}
	else
	{
		for (list<ObjetEmpruntable*>::iterator it = listeObjetTrouve.begin(); it != listeObjetTrouve.end(); it++)
		{
			cout << *(*it) << endl;
		}
	}
}



// La m�thode emprunter() qui prend en param�tres le matricule d�un abonn�, la cote d�un objet empruntable et la date de retour associ�e.Cette m�thode doit retourner une valeur bool�enne indiquant si l�emprunt a �t� fait ou non.
//	o Elle doit s�assurer que le nombre d�emprunts ne d�passe pas la limite par type d�abonn�.
//	o Elle doit diminuer le nombre d�objets associ�s disponibles.
//	o Elle doit utiliser le foncteur Empruntable .
bool Bibliotheque::emprunter(const std::string& matricule, const std::string& cote, unsigned int date)
{
	bool peutEmprunter = false;

	Abonne* ptrAbonne = trouverAbonne(matricule);
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);

	//Pour compter le nombre d'emprunt d'un abonn�, allons voir la liste d'emprunt
	bool dejaEmprunte = false;
	int compteur = 0;
	Empruntable predicatEmpruntable(matricule, cote, &compteur, &dejaEmprunte);
	list<Emprunt*> listeDEmprunt = gestEmprunts_.trouverContenu(predicatEmpruntable);

	peutEmprunter = ((!dejaEmprunte) &&
					  (compteur < ptrAbonne->obtenirLimiteEmprunt()) &&
					  (ptrObjet->obtenirNbDisponibles() >= 1 ) &&
					  (ptrAbonne->obtenirAge() >= ptrObjet->obtenirAgeMinimal()));
		
	if (peutEmprunter)
	{
		ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() - 1); //diminuer le nombre d�objets associ�s disponibles
		Emprunt* nouveauEmprunt = new Emprunt(matricule, ptrObjet, date);
		gestEmprunts_.ajouterElement(nouveauEmprunt);
	}

	return peutEmprunter;
}


// La m�thode retourner() qui prend en param�tres le matricule d�un abonn�, la cote d�un objet empruntable.Cette m�thode doit retourner une valeur bool�enne indiquant si l�emprunt a �t� retourn� ou non.
//	o Elle doit utiliser le foncteur MemeObjet pour trouver l�emprunt.
//	o Elle doit augmenter le nombre d�objets associ�s disponibles.
//	o Elle doit d�truire l�objet de la m�moire apr�s son retrait du gestionnaire.
bool Bibliotheque::retourner(const std::string& matricule, const std::string& cote) 
{
	bool retourEffectue = false;
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);

	MemeObjet<Emprunt, const string> memeAbonne(&matricule);
	list<Emprunt*> listeEmprunt = gestEmprunts_.trouverContenu(memeAbonne); // On trouve tous les emprunts de l'abonne

	for (list<Emprunt*>::iterator it = listeEmprunt.begin(); it != listeEmprunt.end(); it++)
	{
		if ((*it)->obtenirObjetEmpruntable() == ptrObjet) //V�rifie que l'objet est bel et bien emprunt�.
		{
			retourEffectue = true;
			ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() + 1);
			gestEmprunts_.retirerElement(*it);
			delete *it;
			return true;
		}
	}
	return retourEffectue;
}


// La m�thode trierEmprunt () qui prend en param�tre un pointeur d�abonn� et retourne une map, cette m�thode doit chercher et trier les emprunts en ordre alphab�tique selon les titres des objets emprunt�s.Elle utilise le foncteur MemeObjet.Cette m�thode est appel�e par la m�thode infoAbonne().
map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const 
{
	map<string, Emprunt*> mapRetour;

	string  matricule = abonne->obtenirMatricule();
	MemeObjet<Emprunt, string> memeAbonne(&matricule);
	list<Emprunt*> listeDEmprunt = gestEmprunts_.trouverContenu(memeAbonne);

	for (list<Emprunt*>::iterator it = listeDEmprunt.begin(); it != listeDEmprunt.end(); it++)
	{
		mapRetour.insert(mapRetour.begin(), pair<string, Emprunt*>((*it)->obtenirObjetEmpruntable()->obtenirTitre(), *it));
	}

	return mapRetour;
}



// La m�thode infoAbonne() qui prend en param�tre un matricule d�abonn� et affiche les informations qui le concerne en utilisant l�op�rateur << appropri�.
//	o Cette m�thode doit d�terminer de quelle sous - classe fait partie l�abonn� (typeid).
//	o Une fois d�termin�, la m�thode doit faire un dynamic_cast<> pour obtenir un pointeur de la classe appropri�e, dans le but d�appeler l�op�rateur << .
//	o Finalement, la m�thode doit afficher les emprunts retourn�s par la m�thode trierEmprunt().
void Bibliotheque::infoAbonne(const std::string& matricule) const 
{
		//On doit v�rifier que tous les vecteurs sont parcourus
		Abonne* ptrAbonne = trouverAbonne(matricule);

		if (ptrAbonne != nullptr)
		{
			// Utilisez dynamic_cast<>()  pour convertir les types de pointeurs et appeler le bon op�rateur <<
			string typeClasse = ptrAbonne->obtenirNomClasse();
			if (typeClasse == typeid(EtudiantBaccalaureat).name())
			{
				cout << *dynamic_cast<const EtudiantBaccalaureat*> (ptrAbonne);
			}
			else if (typeClasse == typeid(Etudiant).name())
			{
				cout << *dynamic_cast<const Etudiant*> (ptrAbonne);
			}
			else if (typeClasse == typeid(Professeur).name())
			{
				cout << *dynamic_cast<const Professeur*> (ptrAbonne);
			}
			else if (typeClasse == typeid(Abonne).name())
			{
				cout << *dynamic_cast<const Abonne*> (ptrAbonne);
			}
		}
		else
		{
			cout << "Abonne - " << matricule << " - non trouve" << endl;
		}

		map<string, Emprunt*> mapEmprunt = trierEmprunt(ptrAbonne); 
		cout << "LISTE DE LIVRE : " << endl;
		int i = 1;
		for (map<string, Emprunt*>::iterator it = mapEmprunt.begin(); it != mapEmprunt.end(); it++) {
			cout << i << " - " << *it->second << endl; 
			i++;
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


