#ifndef Librairie_H
#define Librairie_H

#include <functional>
// To do

class Librairie
{
public:
    static constexpr size_t MEDIA_INEXSISTANT = -1;

    Librairie() = default;
    Librairie(const Librairie&);
    ~Librairie();

    Librairie& operator=(const Librairie&);
    Librairie& operator+=(std::unique_ptr<Media> media);
    Librairie& operator-=(const std::string& nomMedia);
    friend std::ostream& operator<<(std::ostream& os, const Librairie& librairie);

    Film* chercherFilm(const std::string& nomFilm);
    Serie* chercherSerie(const std::string& nomSerie);

    void ajouterSaison(const std::string& nomSerie, std::unique_ptr<Saison> saison);
    void retirerSaison(const std::string& nomSerie, unsigned int numSaison);
    void ajouterEpisode(const std::string& nomSerie, unsigned int numSaison,
                        std::unique_ptr<Episode> episode);
    void retirerEpisode(const std::string& nomSerie, unsigned int numSaison,
                        unsigned int numEpisode);

    bool chargerMediasDepuisFichier(const std::string& nomFichier,
                                    GestionnaireAuteurs& gestionnaireAuteurs);
    bool chargerRestrictionsDepuisFichiers(const std::string& nomFichier);

    size_t getNbMedias() const;
    size_t getNbFilms() const;
    size_t getNbSeries() const;
    size_t getNbSaisons(const std::string& nomSerie) const;
    size_t getNbEpisodes(const std::string& nomSerie, unsigned int numSaison) const;
    const std::vector<std::unique_ptr<Media>>& getMedias() const;

protected:
    // Attributes
    size_t trouverIndexMedia(const std::string& nomSerie) const;
    Media* chercherMedia(const std::string& nomMedia, Media::TypeMedia typeMedia);

    bool lireLigneRestrictions(const std::string& ligne);
    bool lireLigneMedia(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs);
    bool lireLigneEpisode(std::istream& is, GestionnaireAuteurs&);
    bool lireLigneSaison(std::istream& is, GestionnaireAuteurs&);
    bool lireLigneSerie(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs);
    bool lireLigneFilm(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs);

    // Movies array
    std::vector<std::unique_ptr<Media>> medias_;
};

typedef bool (Librairie::*lireLigneMediaFunction)(std::istream&, GestionnaireAuteurs&);
#endif // Librairie_H
