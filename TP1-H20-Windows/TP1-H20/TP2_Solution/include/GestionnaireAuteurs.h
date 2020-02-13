#ifndef GESTIONNAIREAUTEURS_H
#define GESTIONNAIREAUTEURS_H

#include <string>
#include <vector>
#include "Auteur.h"

class GestionnaireAuteurs
{
public:
    GestionnaireAuteurs();

    Auteur* chercherAuteur(const std::string& nomAuteur);
    bool chargerDepuisFichier(const std::string& nomFichier);

    std::size_t getNbAuteurs() const;

    static constexpr std::size_t NB_AUTEURS_MAX = 16;

	bool operator+=(const Auteur& auteur);
	friend std::ostream& operator<<(std::ostream& o, const GestionnaireAuteurs& gestionnaireAuteurs);

private:
    bool lireLigneAuteur(const std::string& ligne);

	std::vector<Auteur> auteurs_;
};

#endif // GESTIONNAIREAUTEURS_H