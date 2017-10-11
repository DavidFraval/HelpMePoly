/****************************************************************************
* Fichier: ObjetNumerique.h
* Auteur: PolySensei & Associates
* Date: 22 f�vrier 2016
* Mise a jour : 3 mars 2016
* Description: D�finition de la classe ObjetNumerique
****************************************************************************/
#ifndef	OBJETNUMERIQUE_H
#define OBJETNUMERIQUE_H

#include <string>

class ObjetNumerique
{
public:

	// Un destructeur.
	virtual ~ObjetNumerique() {}

	// Bien que la classe ne contienne aucun attribut, il est tout de m�me demand� de faire des m�thodes 
	// d�acc�s et de modifications. Ceci va forcer les classes d�riv�es � impl�menter les attributs n�cessaires. 
	// Ainsi, on demande de faire les m�thodes d�acc�s et de modification virtuelles pures pour : 
	//	o La taille du document num�rique(entier positif), en octets. 
	//	o Le lien internet(string) vers l�objet num�rique.
	virtual unsigned int obtenirTaille() const = 0;
	virtual std::string obtenirLienInternet() const = 0;
	virtual void modifierTaille(unsigned int taille) = 0;
	virtual void modifierLien(const std::string& lien) = 0;

		
};



#endif

