/*******************************************************
 * Titre: Travail pratique #3 - Serie.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 ******************************************************/

#include "Serie.h"

// Constructeur par paramètre
Serie::Serie(Auteur* auteur)
    : Media(auteur, TypeMedia::Serie)
    , GestionnaireSaisons()
{
    auteur->setNbMedias(auteur->getNbMedias() + 1);
}

// Constructeur par paramètres
Serie::Serie(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
             bool estRestreintParAge, Auteur* auteur)
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, TypeMedia::Serie)
    , GestionnaireSaisons()
{
}

// Constructeur par copie
Serie::Serie(const Serie& serie)
    : Media(serie)
    , GestionnaireSaisons()
{
    saisons_.clear();
    for (unsigned int i = 0; i < serie.saisons_.size(); i++)
    {
        auto saison_ptr = std::make_unique<Saison>(*(serie.saisons_[i]));
        saisons_.push_back(std::move(saison_ptr));
    }
}

// Méthode qui permet d'afficher les attributs de la classe serie
std::ostream& Serie::afficher(std::ostream& os) const
{
    Media::afficher(os);
    for (int i = 0; i < saisons_.size(); i++)
    {
        os << "\t" << *saisons_[i];
    }
    return os;
}

// Méthode qui crée une copie de l'objet courant
std::unique_ptr<Media> Serie::clone() const
{
    return std::make_unique<Media>(*this);
}