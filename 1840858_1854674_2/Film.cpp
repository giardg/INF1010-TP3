/**************************************************
 * Titre: Travail pratique #3 - Film.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 **************************************************/

#include "Film.h"

// Constructeur par param�tres
Film::Film(Auteur* auteur)
    : Media(auteur, TypeMedia::Film)
    , duree_("")
{
    auteur->setNbMedias(auteur->getNbMedias() + 1);
}

// Constructeur par param�tres
Film::Film(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
           bool estRestreintParAge, Auteur* auteur, const std::string& duree)
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, TypeMedia::Film)
    , duree_(duree)
{
}

// M�thode qui affiche tous les attributs de Film
std::ostream& Film::afficher(std::ostream& os) const
{
    Media::afficher(os);
    os << "\tDuree: " << duree_;
    return os;
}

// M�thode qui permet de lire l'information d'une ligne et d'intialiser les attributs 
// de la classe Film
std::istream& Film::lire(std::istream& is)
{
    Media::lire(is) >> std::quoted(duree_);
    return is;
}

// M�thode qui permet de cr�er une copie de l'objet courant
std::unique_ptr<Media> Film::clone() const
{
    return std::make_unique<Media>(*this);
}
