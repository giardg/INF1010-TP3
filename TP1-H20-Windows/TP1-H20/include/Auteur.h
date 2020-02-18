#ifndef AUTEUR_H
#define AUTEUR_H

#include <iomanip>
#include <iostream>
#include <string>

class Auteur
{
public:
    Auteur();
    Auteur(const std::string& nom, unsigned int anneeDeNaissance);

    const std::string& getNom() const;
    unsigned int getAnneeDeNaissance() const;
    unsigned int getNbMedias() const;

    void setNbMedias(unsigned int nbFilms);

    bool operator==(const std::string& nom) const;
    friend bool operator==(const std::string& nom, const Auteur& auteur);
    friend std::ostream& operator<<(std::ostream& os, const Auteur& auteur);
    friend std::istream& operator>>(std::istream& is, Auteur& auteur);

private:
    std::string nom_;
    unsigned int anneeDeNaissance_;
    unsigned int nbMedias_;
};

#endif // AUTEUR_H