/**************************************************
 * Titre: Travail pratique #3 - Episode.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 **************************************************/

#include "Episode.h"

// Constructeur sans param�tre
Episode::Episode()
    :
    nom_("")
    , duree_("")
    , numEpisode_(0)
{
}

// Constructeur avec param�tres
Episode::Episode(unsigned int numEpisode, const std::string& nom, const std::string& duree)
    :
    nom_(nom)
    , duree_(duree)
    , numEpisode_(numEpisode)
{
}

// Surcharge de l'op�rateur == comparant un int � un num�ro d'�pisode
// Return true si les num�ros sont �gaux. Sinon retourne false
bool Episode::operator==(unsigned int numEpisode)
{
    if (numEpisode_ == numEpisode)
    {
        return true;
    }
    return false;
}

// Surcharge de l'op�rateur == permettant d'effectuer la surcharge pr�c�dente
// en inversant les positions de l'entier et de l'�pisode autour de l'op�rateur
bool operator==(unsigned int numEpisode, const Episode& episode)
{
    if (episode.numEpisode_ == numEpisode)
    {
        return true;
    }
    return false;
}

// Surcharge de l'op�rateur << permettant d'afficher tous les attributs de l'�pisode
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

// Surcharge de l'op�rateur >> permettant de lire une ligne et d'en tirer le num�ro de l'�pisode,
// le nom de l'�pisode ainsi que la dur�e de celui-ci
std::istream& operator>>(std::istream& is, Episode& episode)
{
    is >> episode.numEpisode_ >> std::quoted(episode.nom_) >> std::quoted(episode.duree_);
    return is;
}

// M�thode qui retourne le nombre d'�pisode
unsigned int Episode::getNumEpisode() const
{
    return numEpisode_;
}