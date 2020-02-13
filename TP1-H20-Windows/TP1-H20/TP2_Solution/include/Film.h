#ifndef FILM_H
#define FILM_H

#include <memory>
#include <string>
#include <vector>
#include "Auteur.h"
#include "Pays.h"

class Film
{
public:
    enum class Genre
    {
        Action,
        Aventure,
        Comedie,
        Horreur,
        Romance,
		first_ = Action,
        last_ = Romance
    };

	~Film();

    Film() = default;
    Film(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
         bool estRestreintParAge, Auteur* auteur);

    void ajouterPaysRestreint(Pays pays);
    void supprimerPaysRestreints();
    bool estRestreintDansPays(Pays pays) const;

    Genre getGenre() const;
    bool estRestreintParAge() const;
    const std::string& getNom() const;
    Auteur* getAuteur();

	friend std::ostream& operator<<(std::ostream& os, const Film& film);

private:
    // Attributs
    std::string nom_;
    unsigned int anneeDeSortie_;
    Genre genre_;
    Pays pays_;
    bool estRestreintParAge_;
    Auteur* auteur_;

	std::vector<Pays> paysRestreints_;
};

#endif // FILM_H