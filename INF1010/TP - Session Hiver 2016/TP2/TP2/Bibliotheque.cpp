/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur: PolySensei & Associates
* Date: 4 f�vrier 2016
* Mise a jour : 6 f�vrier 2016
* Description: Impl�mentation de la classe Bibliotheque
****************************************************************************/
#include <iostream>
#include <vector>
#include "Bibliotheque.h"

using namespace std;

/****************************************************************************
* Fonction:	Bibliotheque::Biliotheque
* Description: Constructeur par d�faut
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
Bibliotheque::Bibliotheque()
{
	
}
/****************************************************************************
* Fonction:	Bibliotheque::~Biliotheque
* Description: Destructeur
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
Bibliotheque::~Bibliotheque()
{
	for (int unsigned i = 0; i < listeEmprunts_.size(); i++)
		delete listeEmprunts_[i];
}


/****************************************************************************
* Fonction:	Bibliotheque::estEmpruntable
* Description: V�rifie si les conditions de bases sont respect�es pour qu'un livre soit empruntable
* Param�tres:	const Abonne & abonne,  l'abonn� d�sirant faire l'emprunt.
*				const Livre & livre,	le livre a emprunter.
* Retour:		un bool�en qui est true si c'est empruntable et false en cas contraire.
****************************************************************************/
bool Bibliotheque::estEmpruntable(const Abonne & abonne, const Livre & livre) const
{	// V�rifie si les conditions de bases sont respect�es
	return (
		(livre.obtenirNbDisponibles() >= 1) &&
		(abonne.obtenirAge() >= livre.obtenirAgeMinimal()) &&
		(!(abonne.estEmprunte(livre))));
}

/****************************************************************************
* Fonction:	Bibliotheque::trouverAbonne
* Description: Cherche un abonne a l aide de son matricule
* Param�tres:	std::string const unMatricule: matricule de l abonne
* Retour:		Abonne* ptrAbonne, un pointeur vers l'abonn� si l'abonn� est trouv�,
*				sinon un pointeur nul 
****************************************************************************/
Abonne* Bibliotheque::trouverAbonne(std::string const unMatricule) const{
	Abonne* ptrAbonne = nullptr;
	for (int unsigned i = 0; i < listeAbonnes_.size(); i++){
		if (listeAbonnes_[i]->obtenirMatricule() == unMatricule)
			ptrAbonne = listeAbonnes_[i];
	}
	return ptrAbonne;
}

/****************************************************************************
* Fonction:	Bibliotheque::trouverLivre
* Description: Cherche un livre a l aide de sa cote
* Param�tres:	std::string const unCote: Cote d un livre
* Retour:		Livre* ptrLivre, Un pointeur nul si le livre n est pas trouve ou un pointeur pointant au livre.
****************************************************************************/
Livre* Bibliotheque::trouverLivre(std::string const unCote) const{
	Livre* ptrLivre = nullptr;
	for (int unsigned i = 0; i < listeLivres_.size(); i++){
		if (listeLivres_[i]->obtenirCote() == unCote)
			ptrLivre = listeLivres_[i];
	}
	return ptrLivre;
}


/****************************************************************************
* Fonction:	Bibliotheque::ajouterAbonne
* Description: Ajouter l�abonn� re�u en param�tre, seulement s�il n�est pas d�j� dans le vecteur.
* Param�tres:	Abonne& unAbonne, l'abonn� � ajouter
* Retour:		aucun
****************************************************************************/
void Bibliotheque::ajouterAbonne(Abonne& unAbonne){
	if (trouverAbonne(unAbonne.obtenirMatricule()) == nullptr)
		listeAbonnes_.push_back(&unAbonne);
}


/****************************************************************************
* Fonction:	Bibliotheque::retirerAbonne
* Description:	Permet de retirer l�abonn� en utilisant le matricule re�u en param�tre. 
*				Avant de le retirer, il faut retourner tous les livres qu�il poss�de en appelant la m�thode appropri�e.
* Param�tres:	std::string const unMatricule, le matricule de l'abonn� a retirer.
* Retour:		aucun
****************************************************************************/
void Bibliotheque::retirerAbonne(std::string const unMatricule){

	Abonne* ptrAbonne = trouverAbonne(unMatricule);

	//Retourne les livres de l'abonn�.
	for (int unsigned i = 0; i < ptrAbonne->obtenirListeEmprunt().size(); i++){
		retourner(unMatricule, ptrAbonne->obtenirListeEmprunt()[i]->obtenirLivre()->obtenirCote());
	}
	//Retire l'abonn�.
	for (int unsigned i = 0; i < listeAbonnes_.size(); i++){
		if (listeAbonnes_[i]->obtenirMatricule() == unMatricule){
			listeAbonnes_[i] = listeAbonnes_[listeAbonnes_.size()-1];
			listeAbonnes_.pop_back();
		}
	}
}


/****************************************************************************
* Fonction:	Bibliotheque::ajouterLivre
* Description:	Ajouter le livre re�u en param�tre seulement s�il n�est pas d�j� dans le vecteur
* Param�tres:	Livre& unLivre, Le livre a ajouter.
* Retour:		aucun
****************************************************************************/
void Bibliotheque::ajouterLivre(Livre& unLivre){
	if (trouverLivre(unLivre.obtenirCote()) == nullptr)
		listeLivres_.push_back(&unLivre);
}


/****************************************************************************
* Fonction:	Bibliotheque::retirerLivre
* Description:	Retirer le livre en utilisant la cote re�ue en param�tre. Le livre est retir� seulement s�il n�est pas emprunt�.
* Param�tres:	std::string const uneCote,  la cote du livre a retirer
* Retour:		retourne un bool�en true si le livre est retir�, sinon false.
****************************************************************************/
bool Bibliotheque::retirerLivre(std::string const uneCote){
	bool estEmprunte = false;

	//V�rifier si le livre est emprunt�.
	for (int unsigned i = 0; i < listeEmprunts_.size(); i++){
		if (*listeEmprunts_[i]->obtenirLivre() == uneCote)
			estEmprunte = true;
			return false; //On ne peut retirer le livre.
	}
	if (!estEmprunte){
		//Trouver le livre dans la listes.
		for (int unsigned i = 0; i < listeLivres_.size(); i++){
			if (listeLivres_[i]->obtenirCote() == uneCote){
				listeLivres_[i] = listeLivres_[listeLivres_.size() - 1];
				listeLivres_.pop_back();
				return true;
			}	
		}
	}
	return false;
}


/*La m�thode rechercherLivre() qui prend en param�tre une cha�ne de caract�res(string),
oCette m�thode va rechercher les livres qui contiennent l�information d�sir�e en utilisant la 
	m�thode appropri�e de la classe Livre.Pour chaque livre trouv� les informations seront affich�es 
	� l�aide de l�op�rateur << de la classe Livre.
o Si aucun livre n�est trouv�, affichez un message.*/
void Bibliotheque::rechercherLivre(const std::string chaineCaracteres) const{

	cout << "Recherche pour le mot : "<< chaineCaracteres << endl;

	bool estTrouve = false;
	for (int unsigned i = 0; i < listeLivres_.size(); i++){
		if (listeLivres_[i]->recherche(chaineCaracteres)){
			estTrouve = true;
			cout << *listeLivres_[i] << endl;
		}
	}
	if (!estTrouve)
		cout << "Aucun Resultat Trouve :(" << endl;
}



/*La m�thode emprunter() qui prend en param�tres le matricule d�un abonn�, la cote d�un livre et la date de retour.Cette m�thode doit retourner une valeur bool�enne indiquant si l�emprunt a �t� fait ou non.
o Elle doit aussi appeler la m�thode estEmpruntable().
o Elle doit s�assurer que le nombre d�emprunts ne d�passe pas la limite de 2 par abonn�.
o Elle doit diminuer le nombre de livres disponibles.*/
bool Bibliotheque::emprunter(const std::string unMatricule, const std::string uneCote, unsigned int dateRetour){
	Abonne* ptrAbonne = trouverAbonne(unMatricule);
	Livre* ptrLivre = trouverLivre(uneCote);
	
	if (estEmpruntable(*ptrAbonne, *ptrLivre)){
		if (ptrAbonne->obtenirListeEmprunt().size() < LIMITE_EMPRUNTS){
			Emprunt* nouveauEmprunt = new Emprunt(unMatricule, ptrLivre, dateRetour);
			listeEmprunts_.push_back(nouveauEmprunt);
			ptrAbonne->ajouterEmprunt(nouveauEmprunt);
			ptrLivre->modifierNbDisponibles(ptrLivre->obtenirNbDisponibles() - 1);
			return true;
		}
	}
	return false;
}


/*La m�thode retourner() qui prend en param�tres le matricule d�un abonn� et la cote d�un livre.Si l�abonn� avait bien emprunt� ce livre, l�emprunt en question est retir� du vecteur d�emprunts.
o Cette m�thode doit retourner une valeur bool�enne indiquant si le retour a �t� fait ou non.
o Elle doit aussi appeler la m�thode retirerEmprunt() de la classe Abonne.
o N'oubliez pas de retirer l'emprunt du vecteur d'emprunts de la Biblioth�que.
o Elle doit augmenter le nombre de livres disponibles.*/
bool Bibliotheque::retourner(const std::string matricule, const std::string cote){

	Abonne* ptrAbonne = trouverAbonne(matricule);
	Livre* ptrLivre = trouverLivre(cote);

	//V�rifie si l'abonn� a bel et bien le livre et retire le livre de sa liste d'emprunts si c'est le cas.
	if (ptrAbonne->retirerEmprunt(*ptrLivre)){

		//Pour retourner le livre � la bibliotheque,
		//Allons scruter le tableau d'Emprunt
		for (int unsigned i = 0; i < listeEmprunts_.size(); i++){

			//lorsqu'on trouve l'emprunt 
			if ((listeEmprunts_[i]->obtenirLivre() == ptrLivre) &&(listeEmprunts_[i]->obtenirMatricule() == matricule)){

				//Ajouter une disponibilit� et enlever l'emprunt de la liste
				ptrLivre->modifierNbDisponibles(ptrLivre->obtenirNbDisponibles() + 1);
				delete listeEmprunts_[i];
				listeEmprunts_[i] = listeEmprunts_[listeEmprunts_.size() - 1];
				listeEmprunts_.pop_back();
				return true;
			}
		}
	}

	return false;
}


//La m�thode infoAbonne() qui prend en param�tre un matricule d�abonn� et affiche les informations qui le concerne en utilisant l�op�rateur << appropri�
void Bibliotheque::infoAbonne(const std::string matricule) const{
	Abonne* ptrAbonne = trouverAbonne(matricule);
	if (ptrAbonne == nullptr)
		cout << endl << "Abonne - " << matricule << " - non trouve" << endl;
	else
		cout << *ptrAbonne;
}

//Un op�rateur >> qui permet d�entrer un mot - cl� � chercher, puis qui appelle la m�thode rechercherLivre().
void operator>>(istream& entre, Bibliotheque& uneBibliotheque){
	string chaineCaracteres = "";
	entre >> chaineCaracteres;
	uneBibliotheque.rechercherLivre(chaineCaracteres);
}

//L�op�rateur += qui prend en param�tre un pointeur Abonne. Son comportement est similaire � ajouterAbonne().
void Bibliotheque::operator+=(Abonne* ptrAbonne){
	ajouterAbonne(*ptrAbonne);
}

//L�op�rateur += qui prend en param�tre un pointeur Livre. Son comportement est similaire � ajouterLivre().
void Bibliotheque::operator+=(Livre* ptrLivre){
	ajouterLivre(*ptrLivre);
}

//L�op�rateur -= qui prend en param�tre un pointeur Abonne. Son comportement est similaire � retirerAbonne().
void Bibliotheque::operator-=(Abonne* ptrAbonne){
	retirerAbonne(ptrAbonne->obtenirMatricule());
}

//L�op�rateur -= qui prend en param�tre un pointeur Livre. Son comportement est similaire � retirerLivre().
void Bibliotheque::operator-=(Livre* ptrLivre){
	retirerLivre(ptrLivre->obtenirCote());
}
