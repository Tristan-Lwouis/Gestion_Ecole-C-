#include "menu.h"

int main()
{
    ecole_t E1 = {
        .nom = "SAINT-MICHEL",
        .directeur = {
            "Corey",
            "Taylor"
        },
        {
            "CE1",
            3,
            {
                "Ken",
                "Block"
            }
        }
    };

    ecole_t monEcole = {
        .nom = "École des Petits Génies",
        .directeur = { "Lemoine", "Valérie" },
        .nbClasse = {0, 2, 1, 0, 0, 0}, // 2 classes en CP, 1 en CE1
        .tabClasse = {
            {}, // Niveau 0
            { // CP en général
                { // CP1
                    .nom = "CP-1",
                    .nbrEleve = 3,
                    .prof = { "Lemoine", "Paul" },
                    .nbgars = 3,
                    .nbfille = 0,
                    .tabPersonne = {
                        {
                            .nom = "Taylor",
                            .prenom = "Corey",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2016 - 1900, .tm_mon = 11, .tm_mday = 8 },
                            .numClasse = 1
                        },
                        {
                            .nom = "Crahan",
                            .prenom = "Shawn",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2016 - 1900, .tm_mon = 8, .tm_mday = 24 },
                            .numClasse = 1
                        },
                        {
                            .nom = "Thomson",
                            .prenom = "Mick",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2016 - 1900, .tm_mon = 5, .tm_mday = 3 },
                            .numClasse = 1
                        }
                    }
                },
                { // CP-2
                    .nom = "CP-2",
                    .nbrEleve = 3,
                    .prof = { "Roux", "Benoît" },
                    .nbgars = 3,
                    .nbfille = 0,
                    .tabPersonne = {
                        {
                            .nom = "Root",
                            .prenom = "Jim",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2016 - 1900, .tm_mon = 1, .tm_mday = 2 },
                            .numClasse = 1
                        },
                        {
                            .nom = "Weinberg",
                            .prenom = "Jay",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2016 - 1900, .tm_mon = 3, .tm_mday = 26 },
                            .numClasse = 1
                        },
                        {
                            .nom = "Fehn",
                            .prenom = "Chris",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2016 - 1900, .tm_mon = 1, .tm_mday = 24 },
                            .numClasse = 1
                        }
                    }
                }
            },
            { // CE1
                { // CE1-1
                    .nom = "CE1-1",
                    .nbrEleve = 3,
                    .prof = { "Marchand", "Thomas" },
                    .nbgars = 3,
                    .nbfille = 0,
                    .tabPersonne = {
                        {
                            .nom = "Gray",
                            .prenom = "Paul",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2015 - 1900, .tm_mon = 3, .tm_mday = 8 },
                            .numClasse = 2
                        },
                        {
                            .nom = "Wilson",
                            .prenom = "Sid",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2015 - 1900, .tm_mon = 0, .tm_mday = 20 },
                            .numClasse = 2
                        },
                        {
                            .nom = "Colsefni",
                            .prenom = "Anders",
                            .sexe = true,
                            .dateNaissance = { .tm_year = 2015 - 1900, .tm_mon = 6, .tm_mday = 16 },
                            .numClasse = 2
                        }
                    }
                }
            },
            {}, // CE2
            {},
            {} 
        }
    };

    ecole_t E;
    ecole_t E2 = {
        .nom = "École des Petits Génies",
        .directeur = { "Lemoine", "Valérie" },
        .nbClasse = {0, 2, 1, 0, 0, 0}, // 2 classes en CP, 1 en CE1
        .tabClasse = {
            {}, // Niveau zéro
            { // Niveau 1 (CP)
                { // CP-1
                    .nom = "CP-1",
                    .nbrEleve = 3,
                    .prof = { "Durand", "Céline" },
                    .nbgars = 2,
                    .nbfille = 1,
                    .tabPersonne = {
                        { "Dubois", "Léo", true,  {.tm_year=2016-1900, .tm_mon=2, .tm_mday=5}, 1 },
                        { "Morel", "Emma", false, {.tm_year=2017-1900, .tm_mon=9, .tm_mday=12}, 1 },
                        { "Petit", "Noah", true,   {.tm_year=2016-1900, .tm_mon=5, .tm_mday=20}, 1 }
                    }
                },
                { // CP-2
                    .nom = "CP-2",
                    .nbrEleve = 3,
                    .prof = { "Roux", "Benoît" },
                    .nbgars = 1,
                    .nbfille = 2,
                    .tabPersonne = {
                        { "Garcia", "Lucas", true,  {.tm_year=2017-1900, .tm_mon=1, .tm_mday=18}, 1 },
                        { "Leroy", "Lina", false,   {.tm_year=2016-1900, .tm_mon=11, .tm_mday=3}, 1 },
                        { "Faure", "Zoé", false,    {.tm_year=2017-1900, .tm_mon=7, .tm_mday=25}, 1 }
                    }
                }
            },
            { // Niveau 2 (CE1)
                { // CE1-1
                    .nom = "CE1-1",
                    .nbrEleve = 3,
                    .prof = { "Marchand", "Thomas" },
                    .nbgars = 2,
                    .nbfille = 1,
                    .tabPersonne = {
                        { "Blanc", "Adam", true,    {.tm_year=2016-1900, .tm_mon=3, .tm_mday=30}, 0 },
                        { "Meunier", "Anna", false, {.tm_year=2016-1900, .tm_mon=6, .tm_mday=14}, 0 },
                        { "Henry", "Ethan", true,   {.tm_year=2017-1900, .tm_mon=8, .tm_mday=6}, 0 }
                    }
                }
            }
        }
    }; 
    
    MenuGeneral(&monEcole);
}