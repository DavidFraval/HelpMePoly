/****************************************************************************
* Fichier: EtudiantBaccalaureat.h
* Auteur: PolySensei & Associates
* Date: 11 f�vrier 2016
* Mise a jour : 20 f�vrier 2016
* Description: D�finition de la classe EtudiantBaccalaureat
****************************************************************************/
#ifndef ETUDIANTBACCALAUREAT_H
#define ETUDIANTBACCALAUREAT_H


#include <string>
#include <vector>
#include <iostream>
#include "Etudiant.h"

//H�ritage de la classe Etudiant
class EtudiantBaccalaureat : public Etudiant{

public:

	EtudiantBaccalaureat(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age);

	~EtudiantBaccalaureat();

	unsigned int obtenirLimiteEmprunts() const;

};

#endif