#include "Librairie.h"

// To do
Librairie::Librairie(const Librairie& librairie)
{
    // To do
}

// To do
Librairie& Librairie::operator=(const Librairie& librairie)
{
    // To do
}

//! Destructeur de la classe Librairie
Librairie::~Librairie()
{
    medias_.clear();
}

// To do
Film* Librairie::chercherFilm(const std::string& nomFilm)
{
    // To do
}

// To do
Serie* Librairie::chercherSerie(const std::string& nomSerie)
{
    // To do
}

// To do
void Librairie::ajouterSaison(const std::string& nomSerie, std::unique_ptr<Saison> saison)
{
    // To do
}

// To do
void Librairie::retirerSaison(const std::string& nomSerie, unsigned int numSaison)
{
    // To do
}

// To do
void Librairie::ajouterEpisode(const std::string& nomSerie, unsigned int numSaison,
                               std::unique_ptr<Episode> episode)
{
    // To do
}


void Librairie::retirerEpisode(const std::string& nomSerie, unsigned int numSaison,
                               unsigned int numEpisode)
{
    // To do
}

//! Méthode qui charge les series à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \param gestionnaireAuteurs  Le gestionnaire des auteurs. Nécessaire pour associer un serie à un
//! auteur.
//! \return                     Un bool représentant si le chargement a été un succès.
bool Librairie::chargerMediasDepuisFichier(const std::string& nomFichier,
                                           GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
}

//! Méthode qui charge les restrictions des series à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \return                     Un bool représentant si le chargement a été un succès.
bool Librairie::chargerRestrictionsDepuisFichiers(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        for (size_t i = 0; i < medias_.size(); i++)
            medias_[i]->supprimerPaysRestreints();

        std::string ligne;
        while (getline(fichier, ligne))
            if (!lireLigneRestrictions(ligne))
                return false;

        return true;
    }
    std::cerr << "Le fichier " << nomFichier
              << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
    return false;
}

// To do
size_t Librairie::getNbMedias() const
{
    // To do
}

// To do
std::ostream& operator<<(std::ostream& os, const Librairie& librairie)
{
    // To do
}

// To do
size_t Librairie::trouverIndexMedia(const std::string& nomMedia) const
{
    // To do
}

// To do
Librairie& Librairie::operator+=(std::unique_ptr<Media> media)
{
    // To do
}

// To do
Librairie& Librairie::operator-=(const std::string& nomMedia)
{
    // To do
}

// To do
Media* Librairie::chercherMedia(const std::string& nomMedia, Media::TypeMedia typeMedia)
{
    // To do
}

// To do
bool Librairie::lireLigneRestrictions(const std::string& ligne)
{
    // To do
}

// To do
bool Librairie::lireLigneMedia(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs)
{
    lireLigneMediaFunction fonctionLireligne[] = {&Librairie::lireLigneFilm,
                                                  &Librairie::lireLigneSerie,
                                                  &Librairie::lireLigneSaison,
                                                  &Librairie::lireLigneEpisode};
    std::istringstream stream(ligne);
    int typeMediaValeurEnum;

    if (stream >> typeMediaValeurEnum)
        return invoke(fonctionLireligne[typeMediaValeurEnum], *this, stream, gestionnaireAuteurs);

    return false;
}

// To do
const std::vector<std::unique_ptr<Media>>& Librairie::getMedias() const
{
    // To do
}

// To do
bool Librairie::lireLigneEpisode(std::istream& is, GestionnaireAuteurs&)
{
    // To do
}

// To do
bool Librairie::lireLigneSaison(std::istream& is, GestionnaireAuteurs&)
{
    // To do
}

// To do
bool Librairie::lireLigneSerie(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
}

// To do
bool Librairie::lireLigneFilm(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
}

// To do
size_t Librairie::getNbFilms() const
{
    // To do
}

// To do
size_t Librairie::getNbSeries() const
{
    // To do
}

// To do
size_t Librairie::getNbSaisons(const std::string& nomSerie) const
{
    // To do
}

// To do
size_t Librairie::getNbEpisodes(const std::string& nomSerie, const unsigned int numSaison) const
{
    // To do
}
