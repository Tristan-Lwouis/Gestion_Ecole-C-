#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifndef ELEVE_H
#define ELEVE_H

#define MAXCHAR 50

// Définition des structures
typedef struct eleve {
    char nom[MAXCHAR];
    char prenom[MAXCHAR];
    bool sexe;
    struct tm dateNaissance;
    int numClasse;
} eleve_t;

// Prototypes des fonctions
// Fonctions pour le terminal
void SaisirEleve(eleve_t *A);
void AffecterEleveClasse(eleve_t *A);
void AfficherEleve(const eleve_t *A);
void ModifierEleve(eleve_t *A);

// Fonctions d'impression dans un fichier
void ImprimerEleve(const eleve_t *A, char *nomFichier);

#endif