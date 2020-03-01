#ifndef GESTIONNAIREAUTEURS_H
#define GESTIONNAIREAUTEURS_H

#include <fstream>
#include <sstream>
#include <vector>
#include "Auteur.h"

class GestionnaireAuteurs
{
public:
    static constexpr size_t NB_AUTEURS_MAX = 16;
    GestionnaireAuteurs();

    Auteur* chercherAuteur(const std::string& nomAuteur);
    bool chargerDepuisFichier(const std::string& nomFichier);

    size_t getNbAuteurs() const;

    bool operator+=(const Auteur& auteur);
    friend std::ostream& operator<<(std::ostream& o,
                                    const GestionnaireAuteurs& gestionnaireAuteurs);

private:
    std::vector<Auteur> auteurs_;
};
#endif // GESTIONNAIREAUTEURS_H
