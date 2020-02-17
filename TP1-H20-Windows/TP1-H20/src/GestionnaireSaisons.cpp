// To do
#include "GestionnaireSaisons.h"

// To do
GestionnaireSaisons::~GestionnaireSaisons()
{ // To do
    saisons_.clear();
}

// To do
GestionnaireSaisons& GestionnaireSaisons::operator+=(std::unique_ptr<Saison> saison)
{
    // To do
    size_t indexSaison = trouverIndexSaison(saison->getNumSaison());
    if (indexSaison != SAISON_INEXSISTANTE)
    {
        saisons_[indexSaison] = std::move(saisons_[saisons_.size() - 1]);
        saisons_.pop_back();
    }
    saisons_.push_back(std::make_unique<Saison>(saison));
    sort(saisons_.begin(), saisons_.end(), Saison::SortByNumSaison());
    return *this;
}

// To do
GestionnaireSaisons& GestionnaireSaisons::operator-=(const unsigned int numSaison)
{
    // To do
    size_t indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != SAISON_INEXSISTANTE)
    {
        saisons_[indexSaison] = std::move(saisons_[saisons_.size() - 1]);
        saisons_.pop_back();
    }
    return *this;
}

// To do
void GestionnaireSaisons::ajouterEpisode(const unsigned int numSaison,
                                         std::unique_ptr<Episode> episode)
{
    // To do
    size_t indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        *(saisons_[indexSaison]) += std::move(episode);
    }
}

// To do
void GestionnaireSaisons::retirerEpisode(const unsigned int numSaison,
                                         const unsigned int numEpisode)
{
    // To do
    size_t indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        *(saisons_[indexSaison]) -= numEpisode;
    }
}

/// To do
size_t GestionnaireSaisons::trouverIndexSaison(const unsigned int numSaison) const
{
    // To do
    for (size_t i = 0; i < saisons_.size(); i++)
    {
        if (saisons_[i]->getNumSaison() == numSaison)
        {
            return i;
        }
    }
    return SAISON_INEXSISTANTE;
}

// To do
Saison* GestionnaireSaisons::getSaison(const unsigned int numSaison) const
{
    // To do
    size_t indexSaison = trouverIndexSaison(numSaison);
    return saisons_[indexSaison].get();
}

// To do
size_t GestionnaireSaisons::getNbSaisons() const
{
    // To do
    return saisons_.size();
}
