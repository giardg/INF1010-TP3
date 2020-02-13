#ifndef EPISODE_H
#define EPISODE_H

#include <iomanip>
#include <string>

class Episode
{
public:
    class SortByNumEpisode
    {
    public:
        bool operator()(const std::unique_ptr<Episode>& episode_1,
                        const std::unique_ptr<Episode>& episode_2)
        {
            return episode_1->numEpisode_ < episode_2->numEpisode_;
        }
    };

    Episode();
    Episode(unsigned int numEpisode, const std::string& nom, const std::string& duree);

    bool operator==(unsigned int numEpisode);
    friend std::ostream& operator<<(std::ostream& os, const Episode& episode);
    friend std::istream& operator>>(std::istream& is, Episode& episode);

    unsigned int getNumEpisode() const;

private:
    // Attributs
    std::string nom_;
    std::string duree_;
    unsigned int numEpisode_;
};

#endif // EPISODE_H