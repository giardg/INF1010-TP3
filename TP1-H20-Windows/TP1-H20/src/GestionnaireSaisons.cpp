/*******************************************************
 * Titre: Travail pratique #3 - GestionnaireSaisons.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 ******************************************************/

#include "GestionnaireSaisons.h"

// Destructeur 
GestionnaireSaisons::~GestionnaireSaisons()
{
    saisons_.clear();
}

// Surcharge de l'op�rateur += qui ajoute une saison au vecteur saisons_
GestionnaireSaisons& GestionnaireSaisons::operator+=(std::unique_ptr<Saison> saison)
{
    int indexSaison = trouverIndexSaison(saison->getNumSaison());
    if (indexSaison != SAISON_INEXSISTANTE)
    {
        saisons_[indexSaison] = std::move(saisons_[saisons_.size() - 1]);
        saisons_.pop_back();
    }
    saisons_.push_back(std::move(saison));
    sort(saisons_.begin(), saisons_.end(), Saison::SortByNumSaison());
    return *this;
}

// Surcharge de l'op�rateur -= qui retire une saison du vecteur saisons_
GestionnaireSaisons& GestionnaireSaisons::operator-=(const unsigned int numSaison)
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != SAISON_INEXSISTANTE)
    {
        saisons_[indexSaison] = std::move(saisons_[saisons_.size() - 1]);
        saisons_.pop_back();
    }
    return *this;
}

// M�thode qui ajoute un �pisode � une saison
// Elle prend en entr�e le num�ro de l'�pisode
void GestionnaireSaisons::ajouterEpisode(const unsigned int numSaison,
                                         std::unique_ptr<Episode> episode)
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        *(saisons_[indexSaison]) += std::move(episode);
    }
}

// M�thode qui retire un �pisode d'une saison
// Elle prend en entr�e le num�ro de l'�pisode
void GestionnaireSaisons::retirerEpisode(const unsigned int numSaison,
                                         const unsigned int numEpisode)
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        *(saisons_[indexSaison]) -= numEpisode;
    }
}

// M�thode qui retourne la saison qui correspond avec l'entier entr� en param�tre si une saison
// ayant le m�me chiffre existe
int GestionnaireSaisons::trouverIndexSaison(const unsigned int numSaison) const
{
    for (int i = 0; i < saisons_.size(); i++)
    {
        if (saisons_[i]->getNumSaison() == numSaison)
        {
            return i;
        }
    }
    return SAISON_INEXSISTANTE;
}

// M�thode qui retourne les informations d'une saison
Saison* GestionnaireSaisons::getSaison(const unsigned int numSaison) const
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison == SAISON_INEXSISTANTE)
    {
        return nullptr;
    }
    return saisons_[indexSaison].get();
}

// M�thode qui retourne le nombre de saison
size_t GestionnaireSaisons::getNbSaisons() const
{
    return saisons_.size();
}
