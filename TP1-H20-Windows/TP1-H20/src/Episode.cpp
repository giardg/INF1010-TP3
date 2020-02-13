// To do
#include "Episode.h"

// To do
Episode::Episode()
    : // To do
    nom_("")
    , duree_("")
    , numEpisode_(0)
{
}

// To do
Episode::Episode(unsigned int numEpisode, const std::string& nom, const std::string& duree)
    : // To do
    nom_(nom)
    , duree_(duree)
    , numEpisode_(numEpisode)
{
}

// To do
bool Episode::operator==(unsigned int numEpisode)
{
    // To do
    if (numEpisode_ == numEpisode)
    {
        return true;
    }
    return false;
}

// To do
std::ostream& operator<<(std::ostream& os, const Episode& episode)
{
    // To do
    os << episode.nom_ << ": Episode:" << episode.numEpisode_
           << " | Duree: " << episode.duree_;

    return os;
}

// To do
std::istream& operator>>(std::istream& is, Episode& episode)
{
    // To do
    is >> episode.nom_ >> episode.duree_ >> episode.numEpisode_;
    return is;
}

// To do
unsigned int Episode::getNumEpisode() const
{
    // To do
    return numEpisode_;
}