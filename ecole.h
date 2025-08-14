// Elias 
#include "classe.h"

#ifndef ECOLE_H
#define ECOLE_H

#define NIVEAUCLASSE 6
#define NUMEROCLASSE 3

// Structure directeur
typedef struct directeur
{
    char nom[MAXCHAR];
    char prenom[MAXCHAR];
} directeur_t;

// Structure école
typedef struct ecole
{
    char nom[MAXCHAR];
    directeur_t directeur;
    classe_t tabClasse[NIVEAUCLASSE][NUMEROCLASSE];
    int nbClasse[NIVEAUCLASSE];
} ecole_t;

// Prototypes de fonctions
void AfficherEcole(const ecole_t *e); // Afficher l'ensemble des classes et des personnes dans les classes
void SaisirEcole(ecole_t *e); // Fonction de saisie du nom de l'école et du directeur
bool RechercherEleveEcole(const ecole_t *e, const char *nom, const char *prenom, int *numClasse, int *numNiveauClasse, int *indicepersonne); // Fonction qui boucle sur l'ensemble des classes en appelant la fonction RechercherEleveClasse()
void EstInscrit(ecole_t *e, const char *nom, const char *prenom); // RechercheEleveEcole() et printf ou SaisirEleve()/Repartir
void RepartirClasse(ecole_t *e); // Répartit les élèves de façon équitable dans les classes
void SaisirDirecteur(directeur_t *d); // Permet de saisir un directeur d'une école
void ModifierDirecteur(directeur_t *d); // Permet de modifier le nom et prénom du directeur
void AfficherDirecteur(const ecole_t *e); // Affichage du directeur
void CopierEleve(eleve_t *dest, const eleve_t *source);

#endif