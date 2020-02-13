//! Fonction main qui test le programme
//! \author Saad Belgana
//! \date 30 janvier 2020

//#include "Librairie.h"
//#include "Utilisateur.h"
#include "debogageMemoire.h"
#include <string> //?
#include <vector> //?
#include <sstream> //?
#include <iostream> //?
#include <iomanip> //?

// NOTE: Pour que le programme compile initialement, vous pouvez changer tous
// les #if false à des #if false, et mettre en commentaire tout le code qui a été
// écrit pour vous. Ainsi, vous pourrez graduellement les #if false et tester des
// petits blocs de code à la fois. Commencez par écrire vos constructeurs!

int main()
{
    initDebogageMemoire();

    // Ici, les constructeurs des objets se font appeler.
    // Vous devez au moins faire le squelette de leurs défintions
    // pour que le programme compile.
    //GestionnaireAuteurs gestionnaireAuteurs;
    //Librairie librairie;

    std::vector<bool> tests;

#if false
    // Test 1: classe Episode
    Episode episode_01;
    std::string episodeLigne = "1\"Episode:01\"\"00:00:00\"";
    std::string episodeString;
    const std::string episodeStringAttendu = "Episode01:Episode:01|Duree:00:00:00";
    std::istringstream streamEpisode(episodeLigne);
    std::stringstream episodeStream;

    streamEpisode >> episode_01;
    episodeStream << episode_01;
    episodeString = episodeStream.str();
    std::cout << episodeString << std::endl;

    episodeString.erase(remove_if(episodeString.begin(),
                                  episodeString.end(),
                                  [](unsigned char c) { return isspace(c); }),
                        episodeString.end());
    tests.push_back((episodeString == episodeStringAttendu) && (1 == episode_01) &&
                    (episode_01 == 1));

#else
    tests.push_back(false);
#endif

#if false
    // Test 2: classe Saison
    Saison saison_01;
    std::string saisonLigne = "1 20";
    std::string saisonString;
    const std::string saisonStringAttendu = "Saison01:3/20(Encour)"
                                            "Episode01:Episode:01|Duree:00:00:00"
                                            "Episode02:Episode:02|Duree:00:00:00"
                                            "Episode03:Episode:03|Duree:00:00:00"
                                            "Saison01:2/20(Encour)"
                                            "Episode01:Episode:01|Duree:00:00:00"
                                            "Episode03:Episode:03|Duree:00:00:00";
    std::istringstream streamSaison(saisonLigne);
    std::stringstream saisondeStream;

    streamSaison >> saison_01;
    (((saison_01 += std::make_unique<Episode>(1, "Episode:01", "00:00:00")) +=
      std::make_unique<Episode>(2, "Episode:02", "00:00:00")) +=
     std::make_unique<Episode>(3, "Episode:03", "00:00:00")) +=
        std::make_unique<Episode>(3, "Episode:03", "00:00:00");
    saisondeStream << saison_01 << std::endl;

    (saison_01 -= 2) -= 2;
    saisondeStream << saison_01 << std::endl;

    saisonString = saisondeStream.str();
    std::cout << saisonString;

    saisonString.erase(remove_if(saisonString.begin(),
                                 saisonString.end(),
                                 [](unsigned char c) { return isspace(c); }),
                       saisonString.end());
    tests.push_back((saisonString == saisonStringAttendu) && (saison_01.getNbEpisodes() == 2) &&
                    (1 == saison_01) && (saison_01 == 1));

#else
    tests.push_back(false);
#endif

#if false

    // test 3 classe Auteur
    std::stringstream auteurStream_01;
    std::string auteurString_01;
    Auteur auteur_01;
    std::string auteurLigne_01 = "\"Auteur Test\" 2019";
    std::istringstream streamAuteur_01(auteurLigne_01);

    streamAuteur_01 >> auteur_01;
    auteurStream_01 << auteur_01;

    const std::string auteurAttendu = "Nom:AuteurTest|Datedenaissance:2019|NombredeFilm/Serie:0";
    auteurString_01 = auteurStream_01.str();
    std::cout << auteurString_01 << std::endl;
    auteurString_01.erase(remove_if(auteurString_01.begin(),
                                    auteurString_01.end(),
                                    [](unsigned char c) { return isspace(c); }),
                          auteurString_01.end());

    tests.push_back((auteurString_01 == auteurAttendu) && ("Auteur Test" == auteur_01) &&
                    (auteur_01 == "Auteur Test"));

#else
    tests.push_back(false);
#endif

#if false
    // Test 4: classe Film / Media

    Film film_01(&auteur_01);

    std::string filmLigne = "\"Film Test\" 2019 0 3 0 \"00:00:00\"";
    std::string filmString;
    const std::string filmStringAttendu =
        "FilmTestDatedesortie:2019Genre:ActionAuteur:AuteurTestPays:EtatsUnisAucunpaysrestreint."
        "Duree:00:00:00";
    std::istringstream streanFilm(filmLigne);
    std::stringstream filmStream;

    streanFilm >> film_01;
    filmStream << film_01;
    filmString = filmStream.str();
    std::cout << filmString << std::endl;

    filmString.erase(remove_if(filmString.begin(),
                               filmString.end(),
                               [](unsigned char c) { return isspace(c); }),
                     filmString.end());
    tests.push_back((filmString == filmStringAttendu) &&
                    (film_01.getTypeMedia() == Film::TypeMedia::Film));

#else
    tests.push_back(false);
#endif

#if false
    // Test 5: classe Serie / Media / GestionnaireSaison
    Serie serie_01(&auteur_01);

    std::string serieLigne = "\"Serie Test\" 2019 0 3 0";
    std::string serieString;

    const std::string serieStringAttendu =
        "SerieTestDatedesortie:2019Genre:ActionAuteur:AuteurTestPays:EtatsUnisAucunpaysrestreint."
        "Saison01:2/20(Encour)"
        "Episode01:Episode:01|Duree:00:00:00"
        "Episode03:Episode:03|Duree:00:00:00"
        "Saison02:0/20(Encour)"
        "SerieTestDatedesortie:2019Genre:ActionAuteur:AuteurTestPays:EtatsUnisAucunpaysrestreint."
        "Saison01:2/20(Encour)"
        "Episode01:Episode:01|Duree:00:00:00"
        "Episode04:Episode:04|Duree:00:00:00"
        "Saison02:1/20(Encour)"
        "Episode05:Episode:05|Duree:00:00:00"
        "SerieTestDatedesortie:2019Genre:ActionAuteur:AuteurTestPays:EtatsUnisAucunpaysrestreint."
        "Saison01:2/20(Encour)"
        "Episode01:Episode:01|Duree:00:00:00"
        "Episode04:Episode:04|Duree:00:00:00";

    std::istringstream streanSerie(serieLigne);
    std::stringstream serieStream;

    streanSerie >> serie_01;
    ((serie_01 += std::make_unique<Saison>(1, 20)) += std::make_unique<Saison>(2, 20)) +=
        std::make_unique<Saison>(2, 20);
    serie_01.ajouterEpisode(1, std::make_unique<Episode>(1, "Episode:01", "00:00:00"));
    serie_01.ajouterEpisode(1, std::make_unique<Episode>(3, "Episode:03", "00:00:00"));
    serieStream << serie_01 << std::endl;

    serie_01.retirerEpisode(1, 2);
    serie_01.retirerEpisode(1, 3);
    serie_01.ajouterEpisode(1, std::make_unique<Episode>(4, "Episode:04", "00:00:00"));
    serie_01.ajouterEpisode(2, std::make_unique<Episode>(5, "Episode:05", "00:00:00"));
    serieStream << serie_01 << std::endl;

    (serie_01 -= 2) -= 2;
    serieStream << serie_01 << std::endl;

    serieString = serieStream.str();
    std::cout << serieString << std::endl;

    serieString.erase(remove_if(serieString.begin(),
                                serieString.end(),
                                [](unsigned char c) { return isspace(c); }),
                      serieString.end());
    tests.push_back((serieString == serieStringAttendu) && (serie_01.getNbSaisons() == 1) &&
                    (serie_01.getTypeMedia() == Serie::TypeMedia::Serie));
#else
    tests.push_back(false);
#endif

#if false
    // Test 6 et 7: Lecture des fichiers et affichage.
    // Assurez-vous de mettre les fichiers à la bonne place pour que
    // le programme puisse les trouver.
    bool resultatLectureAuteurs = gestionnaireAuteurs.chargerDepuisFichier("auteurs.txt") &&
                                  gestionnaireAuteurs.chargerDepuisFichier("auteurs.txt");
    bool resultatLectureFilms =
        librairie.chargerMediasDepuisFichier("Medias.txt", gestionnaireAuteurs) &&
        librairie.chargerMediasDepuisFichier("Medias.txt", gestionnaireAuteurs);
    bool resultatLectureRestrictions =
        librairie.chargerRestrictionsDepuisFichiers("restrictionsPays.txt") &&
        librairie.chargerRestrictionsDepuisFichiers("restrictionsPays.txt");

    // Test 6: Affichage des auteurs
    std::stringstream auteursStream;
    auteursStream << gestionnaireAuteurs << std::endl;
    std::string auteurString = auteursStream.str();
    std::cout << auteurString << '\n'; // Affichage dans la console
    const std::string sortieAttendueAuteurs =
        "Nom:GeorgeLucas|Datedenaissance:1944|NombredeFilm/Serie:6"
        "Nom:JohnRonaldReuelTolkien|Datedenaissance:1892|"
        "NombredeFilm/Serie:3Nom:DavidBenioff|Datedenaissance:1970|"
        "NombredeFilm/Serie:1Nom:PaulScheuring|Datedenaissance:1968|NombredeFilm/Serie:1";

    auteurString.erase(remove_if(auteurString.begin(),
                                 auteurString.end(),
                                 [](unsigned char c) { return isspace(c); }),
                       auteurString.end());

    tests.push_back(sortieAttendueAuteurs == auteurString && resultatLectureAuteurs == true &&
                    gestionnaireAuteurs.getNbAuteurs() == 4);

    // Test 7: Affichage des films et des restrictions
    std::stringstream librairieStream;
    librairieStream << librairie << std::endl;
    std::string librairieString = librairieStream.str();
    std::cout << librairieString; // Affichage dans la console
    const std::string sortieAttendueLibrairie =
        "ANewHopeDatedesortie:1977Genre:ActionAuteur:GeorgeLucasPays:EtatsUnisAucunpaysrestreint."
        "Duree:02:05:00"
        "RaidersoftheLostArkDatedesortie:1981Genre:AventureAuteur:GeorgeLucasPays:"
        "EtatsUnisPaysrestreints:"
        "BresilCanadaChineEtatsUnisFranceJaponRoyaumeUniRussieMexiqueDuree:01:55:00"
        "IndianaJonesandtheTempleofDoomDatedesortie:1984Genre:AventureAuteur:GeorgeLucasPays:"
        "EtatsUnisAucunpaysrestreint.Duree:01:58:00"
        "IndianaJonesandtheLastCrusadeDatedesortie:1989Genre:AventureAuteur:GeorgeLucasPays:"
        "EtatsUnisAucunpaysrestreint.Duree:02:08:00"
        "TheLordoftheRings:TheFellowshipoftheRingDatedesortie:2001Genre:AventureAuteur:"
        "JohnRonaldReuelTolkienPays:RoyaumeUniAucunpaysrestreint.Duree:03:48:00"
        "TheEmpireStrikesBackDatedesortie:1980Genre:ActionAuteur:GeorgeLucasPays:"
        "EtatsUnisAucunpaysrestreint.Duree:02:07:00"
        "ReturnoftheJediDatedesortie:1983Genre:ActionAuteur:GeorgeLucasPays:"
        "EtatsUnisAucunpaysrestreint.Duree:02:16:00"
        "TheLordoftheRings:TheTwoTowersDatedesortie:2002Genre:AventureAuteur:"
        "JohnRonaldReuelTolkienPays:RoyaumeUniAucunpaysrestreint.Duree:03:55:00"
        "TheLordoftheRings:TheReturnoftheKingDatedesortie:2003Genre:AventureAuteur:"
        "JohnRonaldReuelTolkienPays:"
        "RoyaumeUniPaysrestreints:ChineFranceJaponRussieDuree:03:29:00"
        "GameofThronesDatedesortie:2011Genre:ActionAuteur:DavidBenioffPays:"
        "EtatsUnisAucunpaysrestreint."
        "Saison01:10/10(Terminer)"
        "Episode01:WinterIsComing|Duree:00:40:20Episode02:TheKingsroad|Duree:00:40:20Episode03:"
        "LordSnow|Duree:00:40:20"
        "Episode04:Cripples,BastardsandBrokenThings|Duree:00:40:20Episode05:TheWolfandtheLion|"
        "Duree:00:40:20"
        "Episode06:AGoldenCrown|Duree:00:40:20Episode07:YouWinorYouDie|Duree:00:40:20Episode08:"
        "ThePointyEnd|Duree:00:40:20"
        "Episode09:Baelor|Duree:00:40:20Episode10:FireandBlood|Duree:00:40:20"
        "Saison02:10/10(Terminer)"
        "Episode01:TheNorthRemembers|Duree:00:40:20Episode02:TheNightLands|Duree:00:40:20"
        "Episode03:WhatIsDeadMayNeverDie|Duree:00:40:20Episode04:GardenofBones|Duree:00:40:20"
        "Episode05:TheGhostofHarrenhal|Duree:00:40:20Episode06:TheOldGodsandtheNew|Duree:00:40:20"
        "Episode07:AManWithoutHonor|Duree:00:40:20Episode08:ThePrinceofWinterfell|Duree:00:40:20"
        "Episode09:Blackwater|Duree:00:40:20Episode10:ValarMorghulis|Duree:00:40:20"
        "PrisonBreakDatedesortie:2005Genre:ActionAuteur:PaulScheuringPays:"
        "EtatsUnisAucunpaysrestreint."
        "Saison01:22/22(Terminer)"
        "Episode01:Pilot|Duree:00:40:20Episode02:Allen|Duree:00:40:20Episode03:CellTest|Duree:00:"
        "40:20"
        "Episode04:CutePoison|Duree:00:40:20Episode05:English,FitzorPercy|Duree:00:40:20"
        "Episode06:Riots,DrillsandtheDevil(Part1)|Duree:00:40:20Episode07:Riots,DrillsandtheDevil("
        "Part2)|Duree:00:40:20"
        "Episode08:TheOldHead|Duree:00:40:20Episode09:Tweener|Duree:00:40:20Episode10:"
        "SleightofHand|Duree:00:40:20"
        "Episode11:AndThenThereWere7|Duree:00:40:20Episode12:OddManOut|Duree:00:40:20Episode13:"
        "EndoftheTunnel|Duree:00:40:20"
        "Episode14:TheRat|Duree:00:40:20Episode15:BytheSkinandtheTeeth|Duree:00:40:20Episode16:"
        "Brother'sKeeper|Duree:00:40:20"
        "Episode17:J-Cat|Duree:00:40:20Episode18:Bluff|Duree:00:40:20Episode19:TheKey|Duree:00:40:"
        "20Episode20:Tonight|Duree:00:40:20"
        "Episode21:Go|Duree:00:40:20Episode22:Flight|Duree:00:40:20"
        "Saison02:22/22(Terminer)"
        "Episode01:Manhunt|Duree:00:40:20Episode02:Otis|Duree:00:40:20Episode03:Scan|Duree:00:40:"
        "20Episode04:FirstDown|Duree:00:40:20"
        "Episode05:Map1213|Duree:00:40:20Episode06:Subdivision|Duree:00:40:20Episode07:Buried|"
        "Duree:00:40:20"
        "Episode08:DeadFall|Duree:00:40:20Episode09:Unearthed|Duree:00:40:20Episode10:Rendez-vous|"
        "Duree:00:40:20"
        "Episode11:BolshoiBooze|Duree:00:40:20Episode12:Disconnect|Duree:00:40:20Episode13:"
        "TheKillingBox|Duree:00:40:20"
        "Episode14:JohnDoe|Duree:00:40:20Episode15:TheMessage|Duree:00:40:20Episode16:Chicago|"
        "Duree:00:40:20"
        "Episode17:BadBlood|Duree:00:40:20Episode18:Wash|Duree:00:40:20Episode19:SweetCaroline|"
        "Duree:00:40:20"
        "Episode20:Panama|Duree:00:40:20Episode21:FinDelCamino|Duree:00:40:20Episode22:Sona|Duree:"
        "00:40:20";

    librairieString.erase(remove_if(librairieString.begin(),
                                    librairieString.end(),
                                    [](unsigned char c) { return isspace(c); }),
                          librairieString.end());

    tests.push_back(sortieAttendueLibrairie == librairieString && resultatLectureFilms == true &&
                    resultatLectureRestrictions && librairie.getNbMedias() == 11 &&
                    librairie.getNbFilms() == 9 && librairie.getNbSeries() == 2);
#else
    tests.push_back(false);
    tests.push_back(false);
#endif

#if false
    // Test 8: operateur d'ajout d'auteurs
    bool test3Reussi = true;
    // Remplir le tableau des auteurs
    for (auto i = gestionnaireAuteurs.getNbAuteurs(); i < GestionnaireAuteurs::NB_AUTEURS_MAX; i++)
    {
        bool succes = gestionnaireAuteurs += Auteur("", 0);
        if (succes == false)
        {
            test3Reussi = false;
            tests.push_back(false);
            break;
        }
    }
    // Ajouter un autre auteur devrait retourner false puisque le tableau est etre
    // plein
    if (test3Reussi == true)
    {
        bool succes = gestionnaireAuteurs += Auteur("", 0);
        tests.push_back(!succes);
    }
#else
    tests.push_back(false);
#endif

#if false
    // Test 9: Fonction recherche d'auteurs
    const Auteur* auteurTest = gestionnaireAuteurs.chercherAuteur("George Lucas");
    const Auteur* auteurInexsistant = gestionnaireAuteurs.chercherAuteur("qwerty");
    if (auteurTest == nullptr || auteurInexsistant != nullptr)
        tests.push_back(false);
    else
        tests.push_back(auteurTest->getAnneeDeNaissance() == 1944);
#else
    tests.push_back(false);
#endif

#if false
    // Test 10: Ajouter des films
    size_t nbFilmsAvantTest10 = librairie.getNbMedias();
    static constexpr unsigned int test10NbFilmsAjouter = 200;
    Auteur auteurTest8("auteur test8", 1234);
    for (unsigned int i = 0; i < test10NbFilmsAjouter / 2; i++)
    {
        (librairie += std::make_unique<Film>("test",
                                             1,
                                             Film::Genre::Action,
                                             Pays::Canada,
                                             false,
                                             &auteurTest8,
                                             "20:00")) +=
            std::make_unique<Film>("test",
                                   1,
                                   Film::Genre::Action,
                                   Pays::Canada,
                                   false,
                                   &auteurTest8,
                                   "20:00");
    }
    // Ajouter un film nullptr ne devrait rien faire
    (librairie += nullptr) += nullptr; // cascade
    tests.push_back(librairie.getNbMedias() == nbFilmsAvantTest10 + test10NbFilmsAjouter);
#else
    tests.push_back(false);
#endif

#if false
    // Test 11: Supprimer des films
    // On supprime tous les films ajoutés au test 8
    size_t nbFilmsAvantTest11 = librairie.getNbMedias();
    for (unsigned int i = 0; i < test10NbFilmsAjouter / 2; i++)
    {
        (librairie -= "test") -= "test";
    }
    // Et on supprime un film qui n'existe pas
    (librairie -= "asdf") -= "cascade"; // cascade
    tests.push_back(librairie.getNbMedias() + test10NbFilmsAjouter == nbFilmsAvantTest11 &&
                    librairie.getNbMedias() == nbFilmsAvantTest10);

#else
    tests.push_back(false);
#endif

#if false
    // Test 12: Recherche film
    Film* raidersOfTheLostArk = (librairie.chercherFilm("Raiders of the Lost Ark"));
    tests.push_back(raidersOfTheLostArk != nullptr &&
                    raidersOfTheLostArk->getGenre() == Film::Genre::Aventure &&
                    raidersOfTheLostArk->getNom() == "Raiders of the Lost Ark" &&
                    librairie.chercherFilm("asdf") == nullptr);
#else
    tests.push_back(false);
#endif

#if false
    // Test 13: Ajouter des Series
    size_t nbFilmsAvantTest13 = librairie.getNbMedias();
    static constexpr unsigned int test13NbSeriesAjouter = 200;
    // Auteur auteurTest8("auteur test8", 1234);
    for (unsigned int i = 0; i < test13NbSeriesAjouter / 2; i++)
    {
        (librairie += std::make_unique<Serie>("test",
                                              1,
                                              Serie::Genre::Action,
                                              Pays::Canada,
                                              false,
                                              &auteurTest8)) +=
            std::make_unique<Serie>("test",
                                    1,
                                    Serie::Genre::Action,
                                    Pays::Canada,
                                    false,
                                    &auteurTest8);
    }
    // Ajouter une serie nullptr ne devrait rien faire
    (librairie += nullptr) += nullptr; // cascade
    tests.push_back(librairie.getNbMedias() == nbFilmsAvantTest13 + test13NbSeriesAjouter);
#else
    tests.push_back(false);
#endif

#if false
    // Test 14: Supprimer des Series
    // On supprime toutes les Series ajoutés au test 14
    size_t nbFilmsAvantTest14 = librairie.getNbMedias();
    for (unsigned int i = 0; i < test13NbSeriesAjouter / 2; i++)
    {
        (librairie -= "test") -= "test";
    }
    // Et on supprime un serie qui n'existe pas
    (librairie -= "asdf") -= "cascade"; // cascade
    tests.push_back(librairie.getNbMedias() + test13NbSeriesAjouter == nbFilmsAvantTest14 &&
                    librairie.getNbMedias() == nbFilmsAvantTest13);

#else
    tests.push_back(false);
#endif

#if false
    // Test 15: Recherche Serie
    Serie* gameofThrones = (librairie.chercherSerie("Game of Thrones"));
    tests.push_back(gameofThrones != nullptr && gameofThrones->getGenre() == Serie::Genre::Action &&
                    gameofThrones->getNom() == "Game of Thrones" &&
                    librairie.chercherSerie("asdf") == nullptr);
#else
    tests.push_back(false);
#endif

#if false
    // Test 16: Ajouter/retiser Episode/Saison
    bool test_1 = librairie.getNbSaisons("Game of Thrones") == 2;
    librairie.ajouterSaison("Game of Thrones", std::make_unique<Saison>(3, 20));
    librairie.ajouterSaison("Game of Thrones", std::make_unique<Saison>(4, 20));
    librairie.ajouterEpisode("Game of Thrones",
                             4,
                             std::make_unique<Episode>(1, "Episode 01", "00:00:00"));
    librairie.ajouterEpisode("Game of Thrones",
                             4,
                             std::make_unique<Episode>(5, "Episode 01", "00:00:00"));
    librairie.ajouterEpisode("Game of Thrones",
                             4,
                             std::make_unique<Episode>(20, "Episode 01", "00:00:00"));
    bool test_2 = librairie.getNbEpisodes("Game of Thrones", 4) == 3;
    librairie.retirerEpisode("Game of Thrones", 4, 1);
    librairie.retirerEpisode("Game of Thrones", 4, 2);
    librairie.retirerEpisode("Game of Thrones", 4, 5);
    bool test_3 = librairie.getNbEpisodes("Game of Thrones", 4) == 1;
    librairie.ajouterSaison("Game of Thrones", std::make_unique<Saison>(5, 20));
    bool test_4 = librairie.getNbSaisons("Game of Thrones") == 5;
    librairie.retirerSaison("Game of Thrones", 3);
    librairie.retirerSaison("Game of Thrones", 4);
    librairie.retirerSaison("Game of Thrones", 5);
    librairie.retirerSaison("Game of Thrones", 10);
    bool test_5 = librairie.getNbSaisons("Game of Thrones") == 2;
    bool test_6 = librairie.chercherSerie("Game of Thrones")->getSaison(10) == nullptr;
    tests.push_back(test_1 && test_2 && test_3 && test_4 && test_5 && test_6);
#else
    tests.push_back(false);
#endif

#if false
    // Test 17: Utilisateur non premium limite de films
    Auteur auteur("Test", 23);
    Film film("film1", 1990, Film::Genre::Comedie, Pays::Mexique, false, &auteur, "20:00");
    film.ajouterPaysRestreint(Pays::Russie);
    Utilisateur utilisateurNonPremium("Jean", 20, false, Pays::Japon);
    for (unsigned int i = 0; i < 5; i++)
    {
        utilisateurNonPremium.regarderMedia(film);
    }
    tests.push_back(utilisateurNonPremium.getNbMediasVus() == Utilisateur::NB_FILMS_GRATUITS);

    // Test 18: Utilisateur premium avec restrictions pays
    Utilisateur utilisateurPremium("Claudette", 20, true, Pays::Chine);
    film.ajouterPaysRestreint(Pays::Chine);
    utilisateurPremium.regarderMedia(film);
    Film film2("film2", 1990, Film::Genre::Aventure, Pays::France, true, &auteur, "20:00");
    unsigned int nbFilmARegarder = 10;
    for (unsigned int i = 0; i < nbFilmARegarder; i++)
    {
        utilisateurPremium.regarderMedia(film2);
    }
    tests.push_back(utilisateurPremium.getNbMediasVus() == nbFilmARegarder);

    // Test 19: Utilisateur premium avec restrictions age
    Utilisateur utilisateurPremium2("Guillaume", 12, true, Pays::Japon);
    Film film3("film3", 1995, Film::Genre::Aventure, Pays::France, false, &auteur, "20:00");
    auto result1 = utilisateurPremium2.regarderMedia(film2);
    auto result2 = utilisateurPremium2.regarderMedia(film3);
    tests.push_back(utilisateurPremium2.getNbMediasVus() == 1 && !result1 && result2);

#else
    tests.push_back(false);
    tests.push_back(false);
    tests.push_back(false);
#endif

#if false

    // test 20 constructeur de copie de librairie et operateur=
    librairie += std::make_unique<Film>("tes2t",
                                        1,
                                        Film::Genre::Action,
                                        Pays::Canada,
                                        false,
                                        &auteurTest8,
                                        "20:00");
    Librairie lib(librairie);
    Librairie lib3 = librairie = librairie;

    tests.push_back(lib.getMedias()[0] != librairie.getMedias()[0] &&
                    lib.getMedias()[0]->getNom() == librairie.getMedias()[0]->getNom() &&
                    lib3.getMedias()[0] != librairie.getMedias()[0] &&
                    lib3.getMedias()[0]->getNom() == librairie.getMedias()[0]->getNom());

#else
    tests.push_back(false);
#endif

    // Affichage
    for (size_t i = 0; i < tests.size(); i++)
    {
        std::string output = "Test " + std::to_string(i + 1) + ": ";
        if (tests[i] == true)
        {
            output += "OK!";
            std::stringstream stream;
            std::cout << std::left << std::setw(15) << std::left << output << stream.str() << '\n';
        }
        else
        {
            output += "ECHEC!";
            std::stringstream stream;
            std::cerr << std::left << std::setw(15) << output << "0/" << '\n';
        }
    }
}
