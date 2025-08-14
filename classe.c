#include "classe.h"

void AfficherTabEleve(const classe_t *A)
{
    for(int i = 0; i < A->nbrEleve; i++)
        AfficherEleve(&A->tabPersonne[i]);
}

bool RechercheEleveClasse(const classe_t *A, const char *nom, const char *prenom, int *indicepersonne)
{   
    for(int i = 0; i < A->nbrEleve; i++)
    {
        if (strcmp(nom, A->tabPersonne[i].nom) == 0 && strcmp(prenom, A->tabPersonne[i].prenom) == 0)
        {
            *indicepersonne = i;
            return true;
        }
    }
    return false;
}

void SaisirProf(classe_t *A)
{
    printf("Saisir le nom et le prénom du professeur : ");
    scanf("%s %s", A->prof.nom, A->prof.prenom);
}

void AfficherClasse(const classe_t *A)
{
    printf("Pour la classe %s, nous avons %d élève(s) sous la direction de M.%s %s et contient %d fille(s) et %d garçon(s).\n", 
           A->nom, A->nbrEleve, A->prof.prenom, A->prof.nom, A->nbfille, A->nbgars);
    AfficherTabEleve(A);
}

// Fonctions d'impression dans un fichier .txt
void ImprimerTabEleve(const classe_t *A, char *nomFichier)
{
    for(int i = 0; i < A->nbrEleve; i++)
        ImprimerEleve(&A->tabPersonne[i], nomFichier);
}

void ImprimerClasse(const classe_t *A, char *nomFichier)
{
    FILE *ptrfic;
    ptrfic = fopen(nomFichier, "a");
    
    if(ptrfic == NULL) {
        perror("Erreur d'écriture classe");
        exit(EXIT_FAILURE);
    }

    printf(">>> Enregistrement des classes\n");
    fprintf(ptrfic, "Dans la classe il y a %d fille(s) et %d garçon(s).\n", A->nbfille, A->nbgars);
    fprintf(ptrfic, "\n");
    fclose(ptrfic);
    ImprimerTabEleve(A, nomFichier);  
}
