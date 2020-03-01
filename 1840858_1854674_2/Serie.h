#ifndef Serie_1_H
#define Serie_1_H

#include <iomanip>
#include "Media.h"
#include "GestionnaireSaisons.h"

// To do

class Serie
    : public Media
    , public GestionnaireSaisons
{
public:
    Serie(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
          bool estRestreintParAge, Auteur* auteur);
    Serie(Auteur* auteur);
    Serie(const Serie& serie);

    std::ostream& afficher(std::ostream& os) const override;
    std::unique_ptr<Media> clone() const override;
};

#endif // Serie_1_H
