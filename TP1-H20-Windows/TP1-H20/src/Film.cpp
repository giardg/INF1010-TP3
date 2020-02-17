// To do
#include "Film.h"

// To do
Film::Film(Auteur* auteur)
// To do
    : Media(auteur, TypeMedia::Film)
    , duree_("")
{
}

// To do
Film::Film(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
           bool estRestreintParAge, Auteur* auteur, const std::string& duree)
    // To do
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, TypeMedia::Film)
    , duree_(duree)
{
}

// To do
std::ostream& Film::afficher(std::ostream& os) const
{
    // To do
}

// To do
std::istream& Film::lire(std::istream& is)
{
    // To do
}

// To do
std::unique_ptr<Media> Film::clone() const
{
    // To do
}
