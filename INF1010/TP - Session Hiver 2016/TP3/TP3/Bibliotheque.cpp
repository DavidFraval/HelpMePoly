/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 19 f�vrier 2016
* Description: Impl�mentation de la classe Bibliotheque
****************************************************************************/


#include <iostream>
#include <vector>
#include "Bibliotheque.h"

using namespace std;

// Un constructeur par d�faut.
Bibliotheque::Bibliotheque()
{

}

// Un destructeur.
Bibliotheque::~Bibliotheque()
{
	while (!vecEmprunts_.empty()){
		delete vecEmprunts_.back();
		vecEmprunts_.pop_back();
	}
}

// Une m�thode trouveAbonne() qui prend un matricule (string) en param�tre, recherche
// dans le vecteur d�abonn�s et retourne un pointeur Abonne associ� � ce matricule.Si
// aucun abonn� n�est retrouv�, un pointeur nul est retourn�.
Abonne* Bibliotheque::trouveAbonne(const std::string& unMatricule) const{
	Abonne* ptrAbonne = nullptr;
	for (int unsigned i = 0; i < vecAbonnes_.size(); i++){
		if (vecAbonnes_[i]->obtenirMatricule() == unMatricule)
			ptrAbonne = vecAbonnes_[i];
	}
	return ptrAbonne;
}

// Une m�thode trouverObjetEmpruntable() qui prend une cote (string) en param�tre,
// recherche l�objet empruntable et retourne un pointeur de type ObjetEmpruntable.Si
// aucun objet empruntable n�est retrouv�, un pointeur nul est retourn� sinon.
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& unCote) const{

	ObjetEmpruntable* ptrObjetEmpruntable = nullptr;

	//recherche dans la liste de livres
	for (int unsigned i = 0; i < vecLivres_.size(); i++){
		if (vecLivres_[i]->obtenirCote() == unCote)
			ptrObjetEmpruntable = vecLivres_[i];
	}
	//recherche dans la liste de DVD
	if (ptrObjetEmpruntable == nullptr){
		for (int unsigned i = 0; i < vecDVD_.size(); i++){
			if (vecDVD_[i]->obtenirCote() == unCote)
				ptrObjetEmpruntable = vecDVD_[i];
		}
	}
	return ptrObjetEmpruntable;

}


// Une m�thode obtenirClasseObjet() qui prend une cote(string) en param�tre, et renvoie
// le nom de la classe correspondant � l�objet ayant cette cote(� Livre �, � DVD �).
string Bibliotheque::obtenirClasseObjet(const std::string& unCote) const{
	string typeObjet = "";

	//Si la cote correspond a un DVD
	for (int unsigned i = 0; i < vecDVD_.size(); i++){
		if (vecDVD_[i]->obtenirCote() == unCote)
			typeObjet = "DVD";
	}

	//Si la cote correspond a un livre
	for (int unsigned i = 0; i < vecLivres_.size(); i++){
		if (vecLivres_[i]->obtenirCote() == unCote)
			typeObjet = "Livre";

	}
	
	return typeObjet;
}


// Une m�thode ajouterAbonne() qui permet d�ajouter l�abonn� re�u en param�tre,
// seulement s�il n�est pas d�j� dans le vecteur.Si l�ajout a �t� fait, la m�thode renvoie
// true, false sinon.
bool Bibliotheque::ajouterAbonne(Abonne& unAbonne){
	bool estAjoute = false;
	if (trouveAbonne(unAbonne.obtenirMatricule()) == nullptr){
		vecAbonnes_.push_back(&unAbonne);
		estAjoute = true;
	}
	return estAjoute;
}




// La m�thode retirerAbonne() qui permet de retirer l�abonn� en utilisant le matricule re�u
// en param�tre.Avant de le retirer, il faut retourner tous les �l�ments que l�abonn� a
// emprunt� en appelant la m�thode appropri�e.Si le retrait a �t� fait, la m�thode renvoie
// true, false sinon.
bool Bibliotheque::retirerAbonne(const std::string & unMatricule){

	bool estRetire = false;
	Abonne* ptrAbonne = trouveAbonne(unMatricule);

	//Retourne l'objet emprunt� de l'abonn�.
	for (int unsigned i = 0; i < ptrAbonne->obtenirEmprunts().size(); i++){
		retourner(unMatricule, ptrAbonne->obtenirEmprunts()[i]->obtenirObjetEmpruntable()->obtenirCote());
	}
	//Retire l'abonn�.
	for (int unsigned i = 0; i < vecAbonnes_.size(); i++){
		if (vecAbonnes_[i]->obtenirMatricule() == unMatricule){
			vecAbonnes_[i] = vecAbonnes_[vecAbonnes_.size() - 1];
			vecAbonnes_.pop_back();
			estRetire = true;
		}
	}
	return estRetire;
}


// La m�thode ajouterLivre() qui permet d�ajouter le Livre re�u en param�tre seulement s�il
// n�est pas d�j� dans le vecteur.Si l�ajout a �t� fait, la m�thode renvoie true, false sinon.
bool Bibliotheque::ajouterLivre(Livre& unLivre){
	bool estAjoute = false;
	if (trouverObjetEmpruntable(unLivre.obtenirCote()) == nullptr){ //on regarde si le livre n est pas deja dans la bibliotheque
		vecLivres_.push_back(&unLivre);
		estAjoute = true;
	}
	return estAjoute;
}

// La m�thode ajouterDVD() qui permet d�ajouter le DVD re�u en param�tre seulement s�il
// n�est pas d�j� dans le vecteur.Si l�ajout a �t� fait, la m�thode renvoie true, false sinon.
bool Bibliotheque::ajouterDVD(Dvd& unDVD){
	bool estAjoute = false;
	if (trouverObjetEmpruntable(unDVD.obtenirCote()) == nullptr){ //on regarde si le DVD n est pas deja dans la bibliotheque
		vecDVD_.push_back(&unDVD);
		estAjoute = true;
	}
	return estAjoute;
}


// La m�thode retirerObjetEmpruntable() qui permet de retirer l�objet empruntable en
// utilisant la cote re�ue en param�tre.Il est retir� seulement s�il n�est pas emprunt�.La
// m�thode retourne donc un bool�en true s�il est retir�, sinon false.
bool Bibliotheque::retirerObjetEmpruntable(const std::string& uneCote){

	bool estEmprunte = false;
	string typeObjet = obtenirClasseObjet(uneCote);

	//V�rifier si l'objet est emprunt�.
	for (int unsigned i = 0; i < vecEmprunts_.size(); i++){
		if (*vecEmprunts_[i]->obtenirObjetEmpruntable() == uneCote)
			estEmprunte = true;
		return false; //On ne peut retirer l'objet.
	}
	if (!estEmprunte){
		//S'il s'agit d'un livre
		if (typeObjet == "Livre"){
			//Trouver l'objet dans le vecteur de Livres et le retirer.
			for (int unsigned i = 0; i < vecLivres_.size(); i++){
				if (vecLivres_[i]->obtenirCote() == uneCote){
					vecLivres_[i] = vecLivres_[vecLivres_.size() - 1];
					vecLivres_.pop_back();
					return true;
				}
			}
		}
		//S'il s'agit d'un DVD
		if (typeObjet == "DVD"){
			//Trouver l'objet dans le vecteur de DVD et le retirer.
			for (int unsigned i = 0; i < vecDVD_.size(); i++){
				if (vecDVD_[i]->obtenirCote() == uneCote){
					vecDVD_[i] = vecDVD_[vecDVD_.size() - 1];
					vecDVD_.pop_back();
					return true;
				}
			}
		}
	}
	return false;
}


// La m�thode rechercher() qui prend en param�tre une cha�ne de caract�res (string),
//		o	Cette m�thode va rechercher les diff�rents �l�ments empruntables de la biblioth�que qui contiennent 
//			l�information d�sir�e en utilisant la m�thode appropri�e de la classe.Pour chaque �l�ment trouv� les 
//			informations seront affich�es � l�aide de l�op�rateur << de la classe appropri�e.
//		o	N�oubliez pas de parcourir tous les �l�ments qui peuvent �tre emprunt�s
//		o	Si aucun rien n�a �t� trouv�, affichez un message.
void Bibliotheque::rechercher(const std::string& chaineCaracteres) const {

	cout << "Recherche pour le mot : " << chaineCaracteres << endl;

	bool estTrouve = false;

	//correspondance avec un livre
	for (int unsigned i = 0; i < vecLivres_.size(); i++){
		if (vecLivres_[i]->recherche(chaineCaracteres)){
			estTrouve = true;
			cout << *vecLivres_[i];
		}
	}

	//correspondance avec un DVD
	for (int unsigned i = 0; i < vecDVD_.size(); i++){
		if (vecDVD_[i]->recherche(chaineCaracteres)){
			estTrouve = true;
			cout << *vecDVD_[i];
		}
	}

	//message si aucune correspondance
	if (!estTrouve)
		cout << "Aucun Resultat Trouve :(" << endl;
}


// Une m�thode estEmpruntable() qui prend en param�tre un matricule et un objet empruntable.
//	o	Cette m�thode v�rifie s�il est possible pour l�abonn� d�effectuer l�emprunt en question.
//		Il est possible pour un abonn� d�emprunter un objet empruntable si ce dernier est disponible, 
//		qu�il a l��ge minimal requis, qu�il n�a pas d�j� emprunt� celui - ci et que sa limite 
//		d�emprunts n�est pas encore atteinte
//	o	Cette m�thode doit retourner une valeur bool�enne indiquant si l�emprunt est possible ou non.
bool Bibliotheque::estEmpruntable(const string & matricule, const ObjetEmpruntable & objetEmpruntable) const {

	Abonne* ptrAbonne = trouveAbonne(matricule);
	return (
		(objetEmpruntable.obtenirNbDisponibles() >= 1) &&
		(ptrAbonne->obtenirAge() >= objetEmpruntable.obtenirAgeMinimal()) &&
		(!(ptrAbonne->estEmprunte(objetEmpruntable.obtenirCote()))) &&
		(ptrAbonne->obtenirEmprunts().size() < ptrAbonne->obtenirLimiteEmprunts()));
}


// La m�thode emprunter() qui prend en param�tres le matricule d�un abonn�, la cote d�un objet empruntable 
// et la date de retour associ�e en fonction du statut de l�abonn�.Cette m�thode doit retourner une valeur 
// bool�enne indiquant si l�emprunt a �t� fait ou non.
//	o	Elle doit s�assurer que le nombre d�emprunts ne d�passe pas la limite par type d�abonn�.
//	o	Elle doit diminuer le nombre d�objets associ�s disponibles.
//	o	Indice : Utilisez la m�thode obtenirClasseObjet pour prendre en compte la bonne classe de l�objet emprunt�
bool Bibliotheque::emprunter(const std::string& unMatricule, const std::string uneCote, unsigned int dateRetour){

	Abonne* ptrAbonne = trouveAbonne(unMatricule);
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(uneCote);
	string typeObjet = obtenirClasseObjet(uneCote);

	if (estEmpruntable(unMatricule, *ptrObjet)){
		
		Emprunt* nouveauEmprunt;

		if (typeObjet == "Livre"){
			for (unsigned int i = 0; i < vecLivres_.size(); i++){
				if (vecLivres_[i]->obtenirCote() == uneCote)
					nouveauEmprunt = new Emprunt(unMatricule, vecLivres_[i], dateRetour);
			}
		}

		if (typeObjet == "DVD"){
			for (unsigned int i = 0; i < vecDVD_.size(); i++){
				if (vecDVD_[i]->obtenirCote() == uneCote){
					nouveauEmprunt = new Emprunt(unMatricule, vecDVD_[i], dateRetour);
				}
			}
		}

		vecEmprunts_.push_back(nouveauEmprunt);
		ptrAbonne->ajouterEmprunt(nouveauEmprunt);
		ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() - 1);
		return true;
	}

	return false;
}


// La m�thode retourner() qui prend en param�tres le matricule d�un abonn� et la cote d�un objet empruntable.
// Si l�abonn� avait bien emprunt� cet �l�ment, l�emprunt en question est retir� du vecteur d�emprunts.
//	o	Cette m�thode doit retourner une valeur bool�enne indiquant si le retour a �t� fait ou non.
//	o	Elle doit augmenter le nombre d�objets empruntables disponibles.
bool Bibliotheque::retourner(const std::string & matricule, const std::string & cote){

	Abonne* ptrAbonne = trouveAbonne(matricule);
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);


	//V�rifie si l'abonn� a bel et bien l'objetEmpruntable et retire celui-ci de sa liste d'emprunts si c'est le cas.
	if (ptrAbonne->retirerEmprunt(*ptrObjet)){

		//Pour retourner l'objetEmpruntable � la bibliotheque,
		//Allons scruter le tableau d'Emprunt
		for (int unsigned i = 0; i < vecEmprunts_.size(); i++){

			//lorsqu'on trouve l'emprunt 
			if ((vecEmprunts_[i]->obtenirObjetEmpruntable() == ptrObjet) && (vecEmprunts_[i]->obtenirMatricule() == matricule)){

				//Ajouter une disponibilit� et enlever l'emprunt de la liste
				ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() + 1);
				delete vecEmprunts_[i];
				vecEmprunts_[i] = vecEmprunts_[vecEmprunts_.size() - 1];
				vecEmprunts_.pop_back();
				return true;
			}
		}
	}

	return false;
}


// La m�thode infoAbonne() qui prend en param�tre un matricule d�abonn� et affiche les 
// informations qui le concerne en utilisant l�op�rateur << appropri�.
void Bibliotheque::infoAbonne(const std::string & matricule) const{
	Abonne* ptrAbonne = trouveAbonne(matricule);
	if (ptrAbonne == nullptr)
		cout << "Abonne - " << matricule << " - non trouve" << endl; //l abonne n existe pas
	else
		cout << *ptrAbonne;
}

// Un op�rateur >> qui permet d�entrer un mot-cl� � chercher, puis qui appelle la m�thode rechercher().
istream& operator>>(istream& in, Bibliotheque& uneBibliotheque){
	string chaineCaracteres = "";
	in >> chaineCaracteres;
	uneBibliotheque.rechercher(chaineCaracteres);
	return in;
}

// L�op�rateur += qui est d�fini 3 fois, avec un param�tre d�entr�e diff�rent :
//	o	Une d�finition pour chaque type d�abonn� qui prend en param�tre un pointeur 
//		de la classe correspondante. Son comportement est similaire � ajouterAbonne().
Bibliotheque& Bibliotheque::operator+=(Abonne* ptrAbonne){
	ajouterAbonne(*ptrAbonne);
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(Etudiant* ptrEtudiant){
	ajouterAbonne(*ptrEtudiant);
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(EtudiantBaccalaureat* ptrEtudiantBaccalaureat){
	ajouterAbonne(*ptrEtudiantBaccalaureat);
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(Professeur* ptrProfesseur){
	ajouterAbonne(*ptrProfesseur);
	return *this;
}

// L�op�rateur += qui est d�fini 3 fois, avec un param�tre d�entr�e diff�rent :
//	o	L�autre d�finition prend en param�tre un pointeur Livre.Son comportement est similaire � ajouterLivre().
Bibliotheque& Bibliotheque::operator+=(Livre* ptrLivre){
	ajouterLivre(*ptrLivre);
	return *this;
}

// L�op�rateur += qui est d�fini 3 fois, avec un param�tre d�entr�e diff�rent :
//	o	L�autre d�finition prend en param�tre un pointeur DVD.Son comportement est similaire � ajouterDVD().
Bibliotheque& Bibliotheque::operator+=(Dvd* ptrDVD){
	ajouterDVD(*ptrDVD);
	return *this;
}


// L�op�rateur -= qui est d�fini 2 fois, avec un param�tre d�entr�e diff�rent
//	o	Une d�finition prend en param�tre un pointeur Abonne. Son comportement est similaire � retirerAbonne().
Bibliotheque& Bibliotheque::operator-=(Abonne* ptrAbonne){
	retirerAbonne(ptrAbonne->obtenirMatricule());
	return *this;
}

// L�op�rateur -= qui est d�fini 2 fois, avec un param�tre d�entr�e diff�rent
//	o	L�autre d�finition prend en param�tre un pointeur ObjetEmpruntable. Son comportement est similaire � retirerObjetEmpruntable().
Bibliotheque& Bibliotheque::operator-=(ObjetEmpruntable* ptrObjet){
	retirerObjetEmpruntable(ptrObjet->obtenirCote());
	return *this;
}
