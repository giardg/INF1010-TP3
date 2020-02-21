#include "Librairie.h"

// To do
Librairie::Librairie(const Librairie& librairie)
{
    // To do
    medias_.clear();
    for (unsigned int i = 0; i < librairie.medias_.size(); i++)
    {
        medias_.push_back(((librairie.medias_[i])->clone()));
    }
}

// To do
Librairie& Librairie::operator=(const Librairie& librairie)
{
    // To do
    if (&librairie == this)
        return *this;

    medias_.clear();

    for (unsigned int i = 0; i < librairie.medias_.size(); i++)
    {
        auto media_ptr = std::make_unique<Media>(*librairie.medias_[i]);
        medias_.push_back(std::move(media_ptr));
    }

    return *this;
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
    return dynamic_cast<Film*>(chercherMedia(nomFilm, Media::TypeMedia::Film));
}

// To do
Serie* Librairie::chercherSerie(const std::string& nomSerie)
{
    // To do
    return dynamic_cast<Serie*>(chercherMedia(nomSerie, Media::TypeMedia::Serie));
}

// To do
void Librairie::ajouterSaison(const std::string& nomSerie, std::unique_ptr<Saison> saison)
{
    // To do
    int indexMedia = trouverIndexMedia(nomSerie);
    if (indexMedia != MEDIA_INEXSISTANT)
    {
        if (medias_[indexMedia]->Media::getTypeMedia() == Media::TypeMedia::Serie)
        {
            dynamic_cast<Serie*>((medias_[indexMedia]).get())
                ->GestionnaireSaisons::operator+=(std::move(saison));
        }
    }
}

// To do
void Librairie::retirerSaison(const std::string& nomSerie, unsigned int numSaison)
{
    // To do
    int indexMedia = trouverIndexMedia(nomSerie);
    if (indexMedia != MEDIA_INEXSISTANT)
    {
        if (medias_[indexMedia]->Media::getTypeMedia() == Media::TypeMedia::Serie)
        {
            dynamic_cast<Serie*>((medias_[indexMedia]).get())
                ->GestionnaireSaisons::operator-=(numSaison);
        }
    }
}

// To do
void Librairie::ajouterEpisode(const std::string& nomSerie, unsigned int numSaison,
                               std::unique_ptr<Episode> episode)
{
    // To do
    int indexMedia = trouverIndexMedia(nomSerie);
    if (indexMedia != MEDIA_INEXSISTANT)
    {
        if (medias_[indexMedia]->Media::getTypeMedia() == Media::TypeMedia::Serie)
        {
            dynamic_cast<Serie*>((medias_[indexMedia]).get())
                ->GestionnaireSaisons::ajouterEpisode(numSaison, std::move(episode));
        }
    }
}

void Librairie::retirerEpisode(const std::string& nomSerie, unsigned int numSaison,
                               unsigned int numEpisode)
{
    // To do
    int indexMedia = trouverIndexMedia(nomSerie);
    if (indexMedia != MEDIA_INEXSISTANT)
    {
        if (medias_[indexMedia]->Media::getTypeMedia() == Media::TypeMedia::Serie)
        {
            dynamic_cast<Serie*>((medias_[indexMedia]).get())
                ->GestionnaireSaisons::retirerEpisode(numSaison, numEpisode);
        }
    }
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
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        // Supprimer les vieux films avant de lire les nouveaux
        medias_.clear();

        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            if (lireLigneMedia(ligne, gestionnaireAuteurs) == false)
            {
                return false;
            }
        }
        return true;
    }
    std::cerr << "Le fichier " << nomFichier
              << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
    return false;
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
    return medias_.size();
}

// To do
std::ostream& operator<<(std::ostream& os, const Librairie& librairie)
{
    // To do
    for (std::size_t i = 0; i < librairie.medias_.size(); i++)
    {
        os << *(librairie.medias_[i]) << std::endl;
    }

    return os;
}

// To do
int Librairie::trouverIndexMedia(const std::string& nomMedia) const
{
    // To do
    for (std::size_t i = 0; i < medias_.size(); i++)
    {
        if (medias_[i]->getNom() == nomMedia)
        {
            return (int)i;
        }
    }
    return MEDIA_INEXSISTANT;
}

// To do
Librairie& Librairie::operator+=(std::unique_ptr<Media> media)
{
    // To do
    if (media == nullptr)
    {
        return *this;
    }
    medias_.push_back(std::move(media));
    sort(medias_.begin(), medias_.end(), Media::SortByTypeMedia());
    return *this;
}

// To do
Librairie& Librairie::operator-=(const std::string& nomMedia)
{
    // To do
    int indexMedia = trouverIndexMedia(nomMedia);
    if (indexMedia == MEDIA_INEXSISTANT)
    {
        return *this;
    }

    medias_[indexMedia] = std::move(medias_[medias_.size() - 1]);
    medias_.pop_back();
    return *this;
}

// To do
Media* Librairie::chercherMedia(const std::string& nomMedia, Media::TypeMedia typeMedia)
{
    // To do
    int indexMedia = trouverIndexMedia(nomMedia);
    if ((indexMedia == MEDIA_INEXSISTANT) || (medias_[indexMedia]->getTypeMedia() != typeMedia))
    {
        return nullptr;
    }
    return medias_[indexMedia].get();
}

// To do
bool Librairie::lireLigneRestrictions(const std::string& ligne)
{
    // To do
    std::istringstream stream(ligne);
    std::string nomMedia;
    // Pour extraire tout ce qui se trouve entre "" dans un stream,
    // il faut faire stream >> std::quoted(variable)
    int mediaValeurEnum;
    stream >> mediaValeurEnum;
    if (stream >> std::quoted(nomMedia))
    {
        Media* media = chercherMedia(nomMedia, to_enum<Media::TypeMedia>(mediaValeurEnum));

        if (media == nullptr)
        {
            // Media n'existe pas
            return false;
        }

        int paysValeurEnum;
        while (stream >> paysValeurEnum)
        {
            media->ajouterPaysRestreint(to_enum<Pays>(paysValeurEnum));
        }
        return true;
    }
    return false;
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
    return medias_;
}

// To do
bool Librairie::lireLigneEpisode(std::istream& is, GestionnaireAuteurs&)
{
    // To do
    Episode episode;
    std::string nomSerie;
    int numSaison;
    if (is >> episode >> std::quoted(nomSerie) >> numSaison)
    {
        ajouterEpisode(nomSerie, numSaison, std::make_unique<Episode>(episode));
        return true;
    }
    return false;
}

// To do
bool Librairie::lireLigneSaison(std::istream& is, GestionnaireAuteurs&)
{
    // To do
    Saison saison;
    std::string nomSerie;
    if (is >> saison >> std::quoted(nomSerie))
    {
        ajouterSaison(nomSerie, std::make_unique<Saison>(saison));
        return true;
    }
    return false;
}

// To do
bool Librairie::lireLigneSerie(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
    std::string nomAuteur;
    if (is >> std::quoted(nomAuteur))
    {
        Auteur* auteur = gestionnaireAuteurs.chercherAuteur(nomAuteur);
        if (auteur == nullptr)
        {
            // Auteur non existant
            return false;
        }
        Serie serie = Serie(auteur);
        // if (is >> serie)
        if (serie.lire(is))
        {
            auteur->setNbMedias(auteur->getNbMedias() + 1);
            *this += std::make_unique<Serie>(serie);
            return true;
        }
        return false;
    }
    return false;
}

// To do
bool Librairie::lireLigneFilm(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
    std::string nomAuteur;
    if (is >> std::quoted(nomAuteur))
    {
        Auteur* auteur = gestionnaireAuteurs.chercherAuteur(nomAuteur);
        if (auteur == nullptr)
        {
            // Auteur non existant
            return false;
        }
        Film film = Film(auteur);
        // if (is >> film)
        if (film.lire(is))
        {
            auteur->setNbMedias(auteur->getNbMedias() + 1);
            *this += std::make_unique<Film>(film);
            return true;
        }
        return false;
    }
    return false;
}

// To do
size_t Librairie::getNbFilms() const
{
    // To do
    size_t cpt_films;
    cpt_films = 0;
    for (size_t i = 0; i < medias_.size(); i++)
    {
        if (medias_[i]->getTypeMedia() == Media::TypeMedia::Film)
        {
            cpt_films += 1;
        }
    }
    return cpt_films;
}

// To do
size_t Librairie::getNbSeries() const
{
    // To do
    size_t cpt_series;
    cpt_series = 0;
    for (size_t i = 0; i < medias_.size(); i++)
    {
        if (medias_[i]->getTypeMedia() == Media::TypeMedia::Serie)
        {
            cpt_series += 1;
        }
    }
    return cpt_series;
}

// To do
size_t Librairie::getNbSaisons(const std::string& nomSerie) //const??
{
    // To do

    return chercherSerie(nomSerie)->getNbSaisons();
}

// To do
size_t Librairie::getNbEpisodes(const std::string& nomSerie, const unsigned int numSaison) //const??
{
    // To do
    return chercherSerie(nomSerie)->getSaison(numSaison)->getNbEpisodes();
}
