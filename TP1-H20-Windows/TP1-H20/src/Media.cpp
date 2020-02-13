#include "Media.h"

namespace
{
    //! Fonction qui convertit le enum Media::Genre en string
    //! \param genre    Le genre à convertir
    //! \return         Le string qui représente le enum
    const std::string& getGenreString(Media::Genre genre)
    {
        static const std::string NOMS_GENRES[] = {"Action",
                                                  "Aventure",
                                                  "Comedie",
                                                  "Horreur",
                                                  "Romance"};

        auto index = enum_value(genre);
        assert(valid_as_enum<Media::Genre>(index));
        return NOMS_GENRES[index];
    }

    //! Fonction qui convertit le enum Pays en string
    //! \param pays     Le pays à convertir
    //! \return         Le string qui représente le enum
    const std::string& getPaysString(Pays pays)
    {
        static const std::string NOMS_PAYS[] = {"Bresil",
                                                "Canada",
                                                "Chine",
                                                "EtatsUnis",
                                                "France",
                                                "Japon",
                                                "RoyaumeUni",
                                                "Russie",
                                                "Mexique"};
        auto index = enum_value(pays);
        assert(valid_as_enum<Pays>(index));
        return NOMS_PAYS[index];
    }
} // namespace

// To do
Media::Media(Auteur* auteur, Media::TypeMedia typeMedia)
// To do
{
}

// To do
Media::Media(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
             bool estRestreintParAge, Auteur* auteur, Media::TypeMedia typeMedia)
    // To do
{
}

// To do
Media::Media(const Media& serie)
{
    // To do
}


// To do
Media::~Media()
{
    // To do
}

// To do
void Media::ajouterPaysRestreint(Pays pays)
{
    // To do
}

// To do
void Media::supprimerPaysRestreints()
{
    // To do
}

// To do
bool Media::estRestreintDansPays(Pays pays) const
{
    // To do
}

// To do
bool Media::estRestreintParAge() const
{
    // To do
}

// To do
std::ostream& Media::afficher(std::ostream& os) const
{
    // To do
}

// To do
std::ostream& operator<<(std::ostream& os, const Media& media)
{
    // To do
}

// To do
Media::Genre Media::getGenre() const
{
    // To do
}

// To do
const std::string& Media::getNom() const
{
    // To do
}

// To do
Media::TypeMedia Media::getTypeMedia() const
{
    // To do
}

// To do
std::istream& Media::lire(std::istream& is)
{
    // To do
}

// To do
std::istream& operator>>(std::istream& is, Media& media)
{
    // To do
}

// To do
std::unique_ptr<Media> Media::clone() const
{
    // To do
}