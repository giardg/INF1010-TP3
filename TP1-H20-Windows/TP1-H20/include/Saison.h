#ifndef SAISON_H
#define SAISON_H

#include <algorithm>
#include <vector>
// To do
#include "Episode.h"

class Saison
{
public:
    static constexpr size_t EPISODE_INEXSISTANTE = -1;

    class SortByNumSaison
    {
    public:
        bool operator()(const std::unique_ptr<Saison>& saison_1,
                        const std::unique_ptr<Saison>& saison_2)
        {
            return saison_1->numSaison_ < saison_2->numSaison_;
        }
    };

    Saison();
    Saison(unsigned int numSaison, unsigned int nbEpisodemax);
    Saison(const Saison& saison);
    ~Saison();

    Saison& operator+=(std::unique_ptr<Episode> episode);
    Saison& operator-=(unsigned int numEpisode);
    bool operator==(unsigned int numSaison);
    friend std::ostream& operator<<(std::ostream& os, const Saison& Saison);
    friend std::istream& operator>>(std::istream& is, Saison& saison);

    unsigned int getNumSaison() const;
    size_t getNbEpisodes() const;

private:
    size_t trouverIndexEpisode(unsigned int numEpisode);

    // Attributs
    std::vector<std::unique_ptr<Episode>> episodes_;
    unsigned int numSaison_;
    unsigned int nbEpisodesmax_;
};

#endif // SAISON_H
