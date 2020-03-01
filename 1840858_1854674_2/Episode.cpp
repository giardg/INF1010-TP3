/**************************************************
 * Titre: Travail pratique #3 - Episode.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 **************************************************/

#include "Episode.h"

// Constructeur sans paramètre
Episode::Episode()
    :
    nom_("")
    , duree_("")
    , numEpisode_(0)
{
}

// Constructeur avec paramètres
Episode::Episode(unsigned int numEpisode, const std::string& nom, const std::string& duree)
    :
    nom_(nom)
    , duree_(duree)
    , numEpisode_(numEpisode)
{
}

// Surcharge de l'opérateur == comparant un int à un numéro d'épisode
// Return true si les numéros sont égaux. Sinon retourne false
bool Episode::operator==(unsigned int numEpisode)
{
    if (numEpisode_ == numEpisode)
    {
        return true;
    }
    return false;
}

// Surcharge de l'opérateur == permettant d'effectuer la surcharge précédente
// en inversant les positions de l'entier et de l'épisode autour de l'opérateur
bool operator==(unsigned int numEpisode, const Episode& episode)
{
    if (episode.numEpisode_ == numEpisode)
    {
        return true;
    }
    return false;
}

// Surcharge de l'opérateur << permettant d'afficher tous les attributs de l'épisode
std::ostream& operator<<(std::ostream& os, const Episode& episode)
{
    std::string episode_str;
    // Condition pour uniformiser l'affichage
    if (episode.numEpisode_ < 10)
    {
        episode_str = "Episode0";
    }
    else
    {
        episode_str = "Episode";
    }
    os << episode_str << episode.numEpisode_ << ":" << episode.nom_ << "|Duree: " << episode.duree_;

    return os;
}

// Surcharge de l'opérateur >> permettant de lire une ligne et d'en tirer le numéro de l'épisode,
// le nom de l'épisode ainsi que la durée de celui-ci
std::istream& operator>>(std::istream& is, Episode& episode)
{
    is >> episode.numEpisode_ >> std::quoted(episode.nom_) >> std::quoted(episode.duree_);
    return is;
}

// Méthode qui retourne le nombre d'épisode
unsigned int Episode::getNumEpisode() const
{
    return numEpisode_;
}