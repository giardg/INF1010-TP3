/*******************************************************
 * Titre: Travail pratique #3 - Saison.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 ******************************************************/

#include "Saison.h"

// Constructeur sans paramètre
Saison::Saison()
    : numSaison_(0)
    , nbEpisodesmax_(0)
{
}

// Constructeur par paramètre
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

// Surcahrge de l'opérateur += qui ajoute un épisode au vecteur episodes_
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

// Méthode qui retire un épisode au vecteur episodes_
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

// Surcharge de l'opérateur == qui compare le numéro en paramètre au numéro des épisodes
// Retourne true si un épisode du même numéro existe. Sinon, retourne false
bool Saison::operator==(unsigned int numSaison)
{
    if (numSaison_ == numSaison)
    {
        return true;
    }
    return false;
}

// Surcharge de l'opérateur == qui compare le numéro en paramètre au numéro des épisodes
// Retourne true si un épisode du même numéro existe. Sinon, retourne false
bool operator==(unsigned int numSaison, const Saison& saison)
{
    if (saison.numSaison_ == numSaison)
    {
        return true;
    }
    return false;
}

// Surcharge de l'opérateur << permettant d'afficher les informations d'une saison
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

// Surcharge de l'opérateur >> qui pemert de lire un ligne et d'initialiser les attributs de
// la classe saison
std::istream& operator>>(std::istream& is, Saison& saison)
{
    is >> saison.numSaison_ >> saison.nbEpisodesmax_;
    return is;
}

// Méthode qui retourne le numéro de la saison
unsigned int Saison::getNumSaison() const
{
    return numSaison_;
}

// Méthode qui retourne le nombre d'épisode d'une saison
size_t Saison::getNbEpisodes() const
{ 
    return episodes_.size();
}

// Méthode qui permet de retrouver l'épisode ayant le même numéro que celui entré en paramètre
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