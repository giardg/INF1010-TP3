// To do
#include "Saison.h"

// To do
Saison::Saison():
    // To do
    numSaison_(0), 
    nbEpisodesmax_(0)
{
}

// To do
Saison::Saison(unsigned int numSaison, unsigned int nbEpisodemax):
    // To do
    numSaison_(numSaison), 
    nbEpisodesmax_(nbEpisodemax)
{
}

// To do
Saison::Saison(const Saison& saison)
{
    // To do
    for (unsigned int i = 0; i < saison.episodes_.size(); i++)
    {
        episodes_.push_back(std::make_unique<Episode>(*saison.episodes_[i]));
    }
    numSaison_ = saison.numSaison_;
    nbEpisodesmax_ = saison.nbEpisodesmax_;
}

// To do
Saison::~Saison()
{
    // To do
}

// To do
Saison& Saison::operator+=(std::unique_ptr<Episode> episode)
{
    // To do
}

// To do
Saison& Saison::operator-=(unsigned int numEpisode)
{
    // To do
}

// To do
bool Saison::operator==(unsigned int numSaison)
{
    // To do
}

// To do
std::ostream& operator<<(std::ostream& os, const Saison& saison)
{
    // To do
}

// To do
std::istream& operator>>(std::istream& is, Saison& saison)
{
    // To do
}

// To do
unsigned int Saison::getNumSaison() const
{
    // To do
}

// To do
size_t Saison::getNbEpisodes() const
{
   // To do
}

// To do
size_t Saison::trouverIndexEpisode(unsigned int numEpisode)
{
    // To do
}