// To do
#include "Saison.h"

// To do
Saison::Saison()
    : // To do
    numSaison_(0)
    , nbEpisodesmax_(0)
{
}

// To do
Saison::Saison(unsigned int numSaison, unsigned int nbEpisodemax)
    : // To do
    numSaison_(numSaison)
    , nbEpisodesmax_(nbEpisodemax)
{
}

// To do
Saison::Saison(const Saison& saison)
{
    // To do
    episodes_.clear();
    for (unsigned int i = 0; i < saison.episodes_.size(); i++)
    {
        auto episode_ptr = std::make_unique<Episode>(*(saison.episodes_[i]));
        episodes_.push_back(std::move(episode_ptr));
    }
    numSaison_ = saison.numSaison_;
    nbEpisodesmax_ = saison.nbEpisodesmax_;
}

// To do
Saison::~Saison()
{
    // To do
    episodes_.clear();
}

// To do
Saison& Saison::operator+=(std::unique_ptr<Episode> episode)
{
    // To do
    int indexEpisode = trouverIndexEpisode(episode->getNumEpisode());
    if (indexEpisode != EPISODE_INEXSISTANTE)
    {
        episodes_[indexEpisode] = std::move(episodes_[episodes_.size() - 1]);
        episodes_.pop_back();
    }
    episodes_.push_back(std::move(episode));
    sort(episodes_.begin(), episodes_.end(), Episode::SortByNumEpisode());
    return *this;
}

// To do
Saison& Saison::operator-=(unsigned int numEpisode)
{
    // To do
    int indexEpisode = trouverIndexEpisode(numEpisode);
    if (indexEpisode != EPISODE_INEXSISTANTE)
    {
        episodes_[indexEpisode] = std::move(episodes_[episodes_.size() - 1]);
        episodes_.pop_back();
    }
    return *this;
}

// To do
bool Saison::operator==(unsigned int numSaison)
{
    // To do
    if (numSaison_ == numSaison)
    {
        return true;
    }
    return false;
}

bool operator==(unsigned int numSaison, const Saison& saison)
{
    if (saison.numSaison_ == numSaison)
    {
        return true;
    }
    return false;
}

// To do
std::ostream& operator<<(std::ostream& os, const Saison& saison)
{
    // To do
    std::string etatSaison;
    std::string saison_str;
    if (saison.episodes_.size() == saison.nbEpisodesmax_)
    {
        etatSaison = "(Terminer)";
    }
    else
    {
        etatSaison = "(Encour)";
    }
    if (saison.numSaison_ < 10)
    {
        saison_str = "Saison0";
    }
    else
    {
        saison_str = "Saison";
    }
    os << saison_str << saison.numSaison_ << ":" << saison.episodes_.size() << "/"
       << saison.nbEpisodesmax_ << etatSaison << std::endl;
    for (int i = 0; i < saison.episodes_.size(); i++)
    {
        os << "\t\t" << *(saison.episodes_[i]) << std::endl;
    }

    return os;
}

// To do
std::istream& operator>>(std::istream& is, Saison& saison)
{
    // To do
    is >> saison.numSaison_ >> saison.nbEpisodesmax_;
    return is;
}

// To do
unsigned int Saison::getNumSaison() const
{
    // To do
    return numSaison_;
}

// To do
size_t Saison::getNbEpisodes() const
{ // To do
    return episodes_.size();
}

// To do
int Saison::trouverIndexEpisode(unsigned int numEpisode)
{
    // To do
    for (int i = 0; i < episodes_.size(); i++)
    {
        if (episodes_[i]->getNumEpisode() == numEpisode)
        {
            return i;
        }
    }
    return EPISODE_INEXSISTANTE;
}