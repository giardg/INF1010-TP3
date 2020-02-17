// To do
#include "Serie.h"

// To do              Pointeur vers l'auteur du serie
Serie::Serie(Auteur* auteur)
    // To do
    : Media(auteur, TypeMedia::Serie)
    , GestionnaireSaisons() // Pas sûr du constructeur de GestionnaireSaisons
{
}

// To do
Serie::Serie(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
             bool estRestreintParAge, Auteur* auteur)
    // To do
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, TypeMedia::Serie)
    , GestionnaireSaisons()
{
}

// To do
Serie::Serie(const Serie& serie)
    // To do
    : Media(serie.nom_, serie.anneeDeSortie_, serie.genre_, serie.pays_, serie.estRestreintParAge_,
            serie.auteur_, TypeMedia::Serie)
    , GestionnaireSaisons()
{
    // To do (Je ne suis pas sûr s'il faut faire quelque chose de plus)
}

// To do
std::ostream& Serie::afficher(std::ostream& os) const
{
    // To do
    for (int i = 0; i < saisons_.size(); i++)
    {
        os << saisons_[i];
    }
    return os;
}

// To do
std::unique_ptr<Media> Serie::clone() const
{
    // To do
    return std::make_unique<Media>(*this); // Dans le .h, objet de type Media et non pas Serie...
}