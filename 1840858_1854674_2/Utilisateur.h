#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Media.h"
#include "Pays.h"

class Utilisateur
{
public:
    Utilisateur(const std::string& nom, unsigned int age, bool estPremium, Pays pays);

    // Functions
    bool mediaEstDisponible(const Media& media) const;
    bool nbLimiteMediasAtteint() const;
    bool regarderMedia(const Media& media);

    // Getters
    unsigned int getNbMediasVus() const;

    static constexpr unsigned int NB_FILMS_GRATUITS = 3;

private:
    std::string nom_;
    unsigned int age_;
    unsigned int nbMediasVus_;
    bool estPremium_;
    Pays pays_;
};

#endif // UTILISATEUR_H
