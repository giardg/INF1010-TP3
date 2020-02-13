#include "Auteur.h"
#include <iostream>

//! Constructeur de la classe Auteur
//! \param nom              Nom de l'auteur
//! \param anneeDeNaissance Année de naissance de l'auteur
Auteur::Auteur(const std::string& nom, unsigned int anneeDeNaissance)
    : nom_(nom)
    , anneeDeNaissance_(anneeDeNaissance)
    , nbFilms_(0)
{
}

//! Méthode qui retourne le nom de l'auteur
//! \return Le nom de l'auteur
const std::string& Auteur::getNom() const
{
    return nom_;
}

//! Méthode qui retourne l'année de naissance de l'auteur
//! \return L'année de naissance de l'auteur
unsigned int Auteur::getAnneeDeNaissance() const
{
    return anneeDeNaissance_;
}

//! Méthode qui retourne le nombre de films de l'auteur
//! \return Le nombre de films de l'auteur
unsigned int Auteur::getNbFilms() const
{
    return nbFilms_;
}

//! Méthode qui set le nombre de films de l'auteur
//! \param nbFilms  Le nombre de films de l'auteur
void Auteur::setNbFilms(unsigned int nbFilms)
{
    nbFilms_ = nbFilms;
}

//! Opérateur qui compare un string avec le nom de l'auteur avec auteur comme opérande de gauche
//! \param nom le nom avec le quel on veut comparé l'auteur
//! \return vrai si les noms sont identique, faux sinon
bool Auteur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

//! Opérateur qui compare un string avec le nom de l'auteur avec le nom comme opérande de gauche.
//! \param nom le nom avec le quel on veut comparé l'auteur
//! \param auteur l'auteur avec lequel on compare le nom.
bool operator==(const std::string& nom, const Auteur& auteur)
{
	return (nom == auteur.nom_);
}

//! Méthode qui affiche un auteur
//! \param os Le stream dans lequel afficher
//! \param auteur l'auteur a afficher
std::ostream& operator<<(std::ostream& os, const Auteur& auteur)
{
	os << "Nom: " << auteur.nom_ << " | Date de naissance: " << auteur.anneeDeNaissance_
		<< " | Nombre de films: " << auteur.nbFilms_;

	return os;
}