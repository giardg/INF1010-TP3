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

bool operator==(unsigned int numEpisode, const Episode& episode)
{
    if (episode.numEpisode_ == numEpisode)
    {
        return true;
    }
    return false;
}

// To do
std::ostream& operator<<(std::ostream& os, const Episode& episode)
{
    // To do
    std::string episode_str;
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

// To do
std::istream& operator>>(std::istream& is, Episode& episode)
{
    // To do
    is >> episode.numEpisode_ >> std::quoted(episode.nom_) >> std::quoted(episode.duree_);
    return is;
}

// To do
unsigned int Episode::getNumEpisode() const
{
    // To do
    return numEpisode_;
}