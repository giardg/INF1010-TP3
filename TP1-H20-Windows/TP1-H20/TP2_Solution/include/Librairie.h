#ifndef LIBRAIRIE_H
#define LIBRAIRIE_H

#include <memory>
#include "Film.h"
#include "GestionnaireAuteurs.h"

class Librairie
{
public:
    Librairie();
	Librairie(const Librairie&);
	Librairie& operator=(const Librairie&);
    ~Librairie();

    Film* chercherFilm(const std::string& nomFilm);
    bool chargerFilmsDepuisFichier(const std::string& nomFichier,
                                   GestionnaireAuteurs& gestionnaireAuteurs);
    bool chargerRestrictionsDepuisFichiers(const std::string& nomFichier);


	std::size_t getNbFilms() const;

	const std::vector<std::unique_ptr<Film>>& getFilms() const;

	Librairie& operator+=(Film* film);
	Librairie& operator-=(const std::string& film);

	friend std::ostream& operator<<(std::ostream& os, const Librairie& librairie);

private:
    void supprimerFilms();
    bool lireLigneRestrictions(const std::string& ligne);
    bool lireLigneFilm(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs);
    int trouverIndexFilm(const std::string& nomFilm) const;

    // Movies array
	std::vector<std::unique_ptr<Film>> films_;
};

#endif // LIBRAIRIE_H