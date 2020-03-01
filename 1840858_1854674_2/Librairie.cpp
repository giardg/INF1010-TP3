/*******************************************************
 * Titre: Travail pratique #3 - Librairie.cpp
 * Date: 1 mars 2020
 * Auteurs: Gamache Olivier, Giard Gregory
 ******************************************************/

#include "Librairie.h"

// Constructeur par paramètre
Librairie::Librairie(const Librairie& librairie)
{
    medias_.clear();
    for (unsigned int i = 0; i < librairie.medias_.size(); i++)
    {
        medias_.push_back(((librairie.medias_[i])->clone()));
    }
}

// Surcharge de l'opérateur = qui permet de faire une copie
// du paramètre en entré
Librairie& Librairie::operator=(const Librairie& librairie)
{
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

// Destructeur de la classe Librairie
Librairie::~Librairie()
{
    medias_.clear();
}

//! Méthode qui retourne un film comportant le même nom que celui envoyé en paramètre
//! \param nomFilm Le nom du film à chercher
//! \return        Un pointeur vers le film. Nullptr si le film n'existe pas
Film* Librairie::chercherFilm(const std::string& nomFilm)
{
    return dynamic_cast<Film*>(chercherMedia(nomFilm, Media::TypeMedia::Film));
}

// Méthode qui permet de retourner la série qui correspond au nombre entré en paramètre
Serie* Librairie::chercherSerie(const std::string& nomSerie)
{
    return dynamic_cast<Serie*>(chercherMedia(nomSerie, Media::TypeMedia::Serie));
}

// Méthode qui permet d'ajouter une saison à la série 
void Librairie::ajouterSaison(const std::string& nomSerie, std::unique_ptr<Saison> saison)
{
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

// Méthode qui supprime une saison de la série
void Librairie::retirerSaison(const std::string& nomSerie, unsigned int numSaison)
{
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

// Méthode qui permet d'ajouter un épisode à la saison dont les informations de la série correspondante
// ont été mis en paramètres
void Librairie::ajouterEpisode(const std::string& nomSerie, unsigned int numSaison,
                               std::unique_ptr<Episode> episode)
{
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

// Méthode qui permet de retirer un épisode à la saison dont les informations de la série
// correspondante ont été mis en paramètres
void Librairie::retirerEpisode(const std::string& nomSerie, unsigned int numSaison,
                               unsigned int numEpisode)
{
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

// Méthode qui retourne le nombre de média 
size_t Librairie::getNbMedias() const
{
    return medias_.size();
}

// Surcharge de l'opérateur << permettant d'afficher les informations d'un média
std::ostream& operator<<(std::ostream& os, const Librairie& librairie)
{
    for (std::size_t i = 0; i < librairie.medias_.size(); i++)
    {
        os << *(librairie.medias_[i]) << std::endl;
    }

    return os;
}

// Méthode qui permet de retourner le média ayant le même nom que le string entré en paramètre
int Librairie::trouverIndexMedia(const std::string& nomMedia) const
{
    for (std::size_t i = 0; i < medias_.size(); i++)
    {
        if (medias_[i]->getNom() == nomMedia)
        {
            return (int)i;
        }
    }
    return MEDIA_INEXSISTANT;
}

// Surcharge de l'opérateur += qui permet d'ajouter un média au vecteur medias_
Librairie& Librairie::operator+=(std::unique_ptr<Media> media)
{
    if (media == nullptr)
    {
        return *this;
    }
    medias_.push_back(std::move(media));
    sort(medias_.begin(), medias_.end(), Media::SortByTypeMedia());
    return *this;
}

// Surcharge de l'opérarteur -= permettant de retirer un média du vecteur medias_
Librairie& Librairie::operator-=(const std::string& nomMedia)
{
    int indexMedia = trouverIndexMedia(nomMedia);
    if (indexMedia == MEDIA_INEXSISTANT)
    {
        return *this;
    }

    medias_[indexMedia] = std::move(medias_[medias_.size() - 1]);
    medias_.pop_back();
    return *this;
}

// Méthode qui cherche un média correspondant au nom entré en paramètre
Media* Librairie::chercherMedia(const std::string& nomMedia, Media::TypeMedia typeMedia)
{
    int indexMedia = trouverIndexMedia(nomMedia);
    if ((indexMedia == MEDIA_INEXSISTANT) || (medias_[indexMedia]->getTypeMedia() != typeMedia))
    {
        return nullptr;
    }
    return medias_[indexMedia].get();
}

// Méthode qui permet de lire la ligne en paramètre et d'en retirer les pays restreints
bool Librairie::lireLigneRestrictions(const std::string& ligne)
{
    std::istringstream stream(ligne);
    std::string nomMedia;

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

// Méthode permettant de lire les informations d'un média
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

// Méthode qui retourne les médias
const std::vector<std::unique_ptr<Media>>& Librairie::getMedias() const
{
    return medias_;
}

// Méthode qui lit une ligne et ajoute un épisode à une saison d'une série
bool Librairie::lireLigneEpisode(std::istream& is, GestionnaireAuteurs&)
{
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

// Méthode qui lit une ligne et ajoute une saison à une série
bool Librairie::lireLigneSaison(std::istream& is, GestionnaireAuteurs&)
{
    Saison saison;
    std::string nomSerie;
    if (is >> saison >> std::quoted(nomSerie))
    {
        ajouterSaison(nomSerie, std::make_unique<Saison>(saison));
        return true;
    }
    return false;
}

// Méthode qui lit une ligne ajoute une série à la librairie
bool Librairie::lireLigneSerie(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
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

// Méthode qui lit une ligne et ajoute un flim à la librairie
bool Librairie::lireLigneFilm(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
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

// Méthode qui retourne le nombre de films
size_t Librairie::getNbFilms() const
{
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

// Méthode qui retourne le nombre de séries
size_t Librairie::getNbSeries() const
{
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

// Méthode qui retourne le nombre de saions d'une série
size_t Librairie::getNbSaisons(const std::string& nomSerie)
{
    return chercherSerie(nomSerie)->getNbSaisons();
}

// Méthode qui retourne le nombre d'épisode d'une saison
size_t Librairie::getNbEpisodes(const std::string& nomSerie, const unsigned int numSaison)
{
    return chercherSerie(nomSerie)->getSaison(numSaison)->getNbEpisodes();
}
