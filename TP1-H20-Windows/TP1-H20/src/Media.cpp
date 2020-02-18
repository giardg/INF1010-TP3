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
    : auteur_(auteur)
    , typeMedia_(typeMedia)
    , nom_("")
    , anneeDeSortie_(0)
    , genre_(Genre())
    , pays_(Pays())
    , estRestreintParAge_(false)
{
}

// To do
Media::Media(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
             bool estRestreintParAge, Auteur* auteur, Media::TypeMedia typeMedia)
    // To do
    : auteur_(auteur)
    , typeMedia_(typeMedia)
    , nom_(nom)
    , anneeDeSortie_(anneeDeSortie)
    , genre_(genre)
    , pays_(pays)
    , estRestreintParAge_(estRestreintParAge)
{
}

// To do
Media::Media(const Media& serie)
{
    // To do
    paysRestreints_.clear();
    for (unsigned int i = 0; i < serie.paysRestreints_.size(); i++)
    {
        paysRestreints_.push_back(serie.paysRestreints_[i]);
    }
    auteur_ = serie.auteur_;
    typeMedia_ = serie.typeMedia_;
    nom_ = serie.nom_;
    anneeDeSortie_ = serie.anneeDeSortie_;
    genre_ = serie.genre_;
    pays_ = serie.pays_;
    estRestreintParAge_ = serie.estRestreintParAge_;
}

// To do
Media::~Media()
{
    // To do
    paysRestreints_.clear();
    auteur_->setNbMedias(auteur_->getNbMedias() - 1);
}

// To do
void Media::ajouterPaysRestreint(Pays pays)
{
    // To do
    paysRestreints_.push_back(pays);
}

// To do
void Media::supprimerPaysRestreints()
{
    // To do
    paysRestreints_.clear();
}

// To do
bool Media::estRestreintDansPays(Pays pays) const
{
    // To do
    for (std::size_t i = 0; i < paysRestreints_.size(); i++)
    {
        if (paysRestreints_[i] == pays)
        {
            return true;
        }
    }
    return false;
}

// To do
bool Media::estRestreintParAge() const
{
    // To do
    return estRestreintParAge_;
}

// To do
std::ostream& Media::afficher(std::ostream& os) const
{
    // To do
    os << nom_ << "\n\tDate de sortie: " << anneeDeSortie_
       << "\n\tGenre: " << getGenreString(genre_) << "\n\tAuteur: " << auteur_->getNom()
       << "\n\tPays: " << getPaysString(pays_)
       << (paysRestreints_.size() == 0 ? "\n\tAucun pays restreint." : "\n\tPays restreints:");

    for (std::size_t i = 0; i < paysRestreints_.size(); i++)
    {
        os << "\n\t\t" << getPaysString(paysRestreints_[i]);
    }
    os << '\n';
    return os;
}

// To do
std::ostream& operator<<(std::ostream& os, const Media& media)
{
    // To do
    media.afficher(os);
    return os;
}

// To do
Media::Genre Media::getGenre() const
{
    // To do
    return genre_;
}

// To do
const std::string& Media::getNom() const
{
    // To do
    return nom_;
}

// To do
Media::TypeMedia Media::getTypeMedia() const
{
    // To do
    return typeMedia_;
}

// To do
std::istream& Media::lire(std::istream& is)
{
    // To do
    int genreValeurEnum;
    int paysValeurEnum;
    // int mediaValeurEnum;
    // std::string nomAuteur;

    // is >> mediaValeurEnum >> std::quoted(nomAuteur) >> std::quoted(nom_) >> anneeDeSortie_ >>
    //    genreValeurEnum >> paysValeurEnum >> estRestreintParAge_;
    is >> std::quoted(nom_) >> anneeDeSortie_ >> genreValeurEnum >> paysValeurEnum >>
        estRestreintParAge_;
    //*auteur_ = Auteur(nomAuteur, ,); //JE NE SAIS PAS COMMENT SAVOIR L'ANNEE DE NAISSANCE DE
    // AUTEUR
    //*auteur_ = Auteur();
    genre_ = to_enum<Media::Genre>(genreValeurEnum);
    pays_ = to_enum<Pays>(paysValeurEnum);
    // typeMedia_ = to_enum<Media::TypeMedia>(mediaValeurEnum);
    return is;
}

// To do
std::istream& operator>>(std::istream& is, Media& media)
{
    // To do
    media.lire(is);
    return is;
}

// To do
std::unique_ptr<Media> Media::clone() const
{
    // To do

    return std::make_unique<Media>(*this);
}