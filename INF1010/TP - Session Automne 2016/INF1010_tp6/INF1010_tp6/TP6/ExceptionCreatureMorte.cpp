/****************************************************************************
* Fichier: ExceptionCreatureMorte.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 d�cembre 2016
* Description: Impl�mentation de la classe ExceptionCreatureMorte
****************************************************************************/
#include "ExceptionCreatureMorte.h"
#include <string>
using namespace std;


int ExceptionCreatureMorte::compteur_ = 0; //Initialisation

//Un constructeur par param�tre recevant une cha�ne de caract�res (string) contenant le message
//de l�erreur. Le constructeur doit incr�menter la valeur du compteur.

ExceptionCreatureMorte::ExceptionCreatureMorte(const std::string & descriptionErreur): runtime_error(descriptionErreur)
{
	compteur_++;
}

//La m�thode statique public obtenirValeurCompteur() qui retourne la valeur de compteur_.
int ExceptionCreatureMorte::obtenirValeurCompteur()
{ 
	return compteur_; 
}
