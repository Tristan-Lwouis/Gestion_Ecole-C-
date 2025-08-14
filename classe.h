#include "eleve.h"
#include <string.h>

#ifndef CLASSE_H
#define CLASSE_H

#define MAXELEVE 25

typedef struct prof
{
    char nom[MAXCHAR];
    char prenom[MAXCHAR];
} prof_t;

typedef struct classe
{
    char nom[MAXCHAR];
    int nbrEleve;
    prof_t prof;
    int nbgars; 
    int nbfille;
    eleve_t tabPersonne[200];
} classe_t;

// Prototypes de fonctions
void AfficherTabEleve(const classe_t *A);
bool RechercheEleveClasse(const classe_t *A, const char *nom, const char *prenom, int *indicepersonne);
void SaisirProf(classe_t *A);
void AfficherClasse(const classe_t *A);

// Fonctions d'impression dans un fichier
void ImprimerClasse(const classe_t *A, char *nomFichier);
void ImprimerTabEleve(const classe_t *A, char *nomFichier);

#endif