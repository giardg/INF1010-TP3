/*******************************************************
 * Titre: Travail pratique #3 - Saison.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 ******************************************************/

#include "Saison.h"

// Constructeur sans param�tre
Saison::Saison()
    : numSaison_(0)
    , nbEpisodesmax_(0)
{
}

// Constructeur par param�tre
Saison::Saison(unsigned int numSaison, unsigned int nbEpisodemax)
    : numSaison_(numSaison)
    , nbEpisodesmax_(nbEpisodemax)
{
}

// Constructeur par copie
Saison::Saison(const Saison& saison)
{
    episodes_.clear();
    for (unsigned int i = 0; i < saison.episodes_.size(); i++)
    {
        auto episode_ptr = std::make_unique<Episode>(*(saison.episodes_[i]));
        episodes_.push_back(std::move(episode_ptr));
    }
    numSaison_ = saison.numSaison_;
    nbEpisodesmax_ = saison.nbEpisodesmax_;
}

// Destructeur
Saison::~Saison()
{
    episodes_.clear();
}

// Surcahrge de l'op�rateur += qui ajoute un �pisode au vecteur episodes_
Saison& Saison::operator+=(std::unique_ptr<Episode> episode)
{
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

// M�thode qui retire un �pisode au vecteur episodes_
Saison& Saison::operator-=(unsigned int numEpisode)
{
    int indexEpisode = trouverIndexEpisode(numEpisode);
    if (indexEpisode != EPISODE_INEXSISTANTE)
    {
        episodes_[indexEpisode] = std::move(episodes_[episodes_.size() - 1]);
        episodes_.pop_back();
    }
    return *this;
}

// Surcharge de l'op�rateur == qui compare le num�ro en param�tre au num�ro des �pisodes
// Retourne true si un �pisode du m�me num�ro existe. Sinon, retourne false
bool Saison::operator==(unsigned int numSaison)
{
    if (numSaison_ == numSaison)
    {
        return true;
    }
    return false;
}

// Surcharge de l'op�rateur == qui compare le num�ro en param�tre au num�ro des �pisodes
// Retourne true si un �pisode du m�me num�ro existe. Sinon, retourne false
bool operator==(unsigned int numSaison, const Saison& saison)
{
    if (saison.numSaison_ == numSaison)
    {
        return true;
    }
    return false;
}

// Surcharge de l'op�rateur << permettant d'afficher les informations d'une saison
std::ostream& operator<<(std::ostream& os, const Saison& saison)
{
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

// Surcharge de l'op�rateur >> qui pemert de lire un ligne et d'initialiser les attributs de
// la classe saison
std::istream& operator>>(std::istream& is, Saison& saison)
{
    is >> saison.numSaison_ >> saison.nbEpisodesmax_;
    return is;
}

// M�thode qui retourne le num�ro de la saison
unsigned int Saison::getNumSaison() const
{
    return numSaison_;
}

// M�thode qui retourne le nombre d'�pisode d'une saison
size_t Saison::getNbEpisodes() const
{ 
    return episodes_.size();
}

// M�thode qui permet de retrouver l'�pisode ayant le m�me num�ro que celui entr� en param�tre
int Saison::trouverIndexEpisode(unsigned int numEpisode)
{
    for (int i = 0; i < episodes_.size(); i++)
    {
        if (episodes_[i]->getNumEpisode() == numEpisode)
        {
            return i;
        }
    }
    return EPISODE_INEXSISTANTE;
}