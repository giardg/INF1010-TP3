#ifndef MEDIA_H
#define MEDIA_H

#include <algorithm>
#include <vector>
#include "Auteur.h"
#include "Pays.h"
#include "typesafe_enum.h"

class Media
{
public:
    static constexpr int SAISON_INEXSISTANTE = -1;

    class SortByTypeMedia
    {
    public:
        bool operator()(const std::unique_ptr<Media>& media_1,
                        const std::unique_ptr<Media>& media_2)
        {
            return media_1->typeMedia_ < media_2->typeMedia_;
        }
    };

    enum class TypeMedia
    {
        Film,
        Serie,
        Saison,
        Episode,
        first_ = Film,
        last_ = Episode
    };

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

    Media(Auteur* auteur, Media::TypeMedia typeMedia);

    Media(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
          bool estRestreintParAge, Auteur* auteur, Media::TypeMedia typeMedia);
    Media(const Media& media);
    virtual ~Media();

    void ajouterPaysRestreint(Pays pays);
    void supprimerPaysRestreints();
    bool estRestreintDansPays(Pays pays) const;
    bool estRestreintParAge() const;

    virtual std::ostream& afficher(std::ostream& os) const;
    virtual std::istream& lire(std::istream& os);

    friend std::ostream& operator<<(std::ostream& os, const Media& media);
    friend std::istream& operator>>(std::istream& is, Media& media);

    Genre getGenre() const;
    const std::string& getNom() const;
    Media::TypeMedia getTypeMedia() const;

    virtual std::unique_ptr<Media> clone() const;

protected:
    // Attributs
    std::string nom_;
    unsigned int anneeDeSortie_;
    Genre genre_;
    Pays pays_;
    bool estRestreintParAge_;
    Auteur* auteur_;
    Media::TypeMedia typeMedia_;
    std::vector<Pays> paysRestreints_;
};
#endif // MEDIA_H
