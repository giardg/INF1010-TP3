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

// Surcharge de l'opérateur += qui ajoute une saison au vecteur saisons_
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

// Surcharge de l'opérateur -= qui retire une saison du vecteur saisons_
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

// Méthode qui ajoute un épisode à une saison
// Elle prend en entrée le numéro de l'épisode
void GestionnaireSaisons::ajouterEpisode(const unsigned int numSaison,
                                         std::unique_ptr<Episode> episode)
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        *(saisons_[indexSaison]) += std::move(episode);
    }
}

// Méthode qui retire un épisode d'une saison
// Elle prend en entrée le numéro de l'épisode
void GestionnaireSaisons::retirerEpisode(const unsigned int numSaison,
                                         const unsigned int numEpisode)
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        *(saisons_[indexSaison]) -= numEpisode;
    }
}

// Méthode qui retourne la saison qui correspond avec l'entier entré en paramètre si une saison
// ayant le même chiffre existe
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

// Méthode qui retourne les informations d'une saison
Saison* GestionnaireSaisons::getSaison(const unsigned int numSaison) const
{
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison == SAISON_INEXSISTANTE)
    {
        return nullptr;
    }
    return saisons_[indexSaison].get();
}

// Méthode qui retourne le nombre de saison
size_t GestionnaireSaisons::getNbSaisons() const
{
    return saisons_.size();
}
