#include "eleve.h"

void AffecterEleveClasse(eleve_t *A) {
    /*
    1 - Convertir la date au format struct tm en secondes
    2 - Initialiser une variable locale qui vaut la date du jour en secondes
    3 - Faire la différence entre les deux pour trouver l'âge de l'élève
    4 - En fonction de l'âge faire un if en cascade pour modifier la valeur A.numClasse
    */
    struct tm *zero;
    int diff;
    
    time_t today = time(NULL);
    zero = localtime(&today); // Convertit le time_t d'aujourd'hui en struct tm
    
    diff = zero->tm_year - A->dateNaissance.tm_year;

    if (diff <= 6)
    {
        printf("Trop jeune\n");
    }
    else if (diff == 7)
    {
        A->numClasse = 1;
    }
    else if(diff == 8)
    {
        A->numClasse = 2;
    }
    else if(diff == 9)
    {
        A->numClasse = 3;
    }
    else if(diff == 10)
    {
        A->numClasse = 4;
    }
    else if(diff == 11)
    {
        A->numClasse = 5;
    }
    else
    {
        printf("Trop vieux\n");
    }
}

void SaisirEleve(eleve_t *A) {
    char temp;
    A->numClasse = 0; // Initialiser la valeur de la classe à 0

    printf("---------- SAISIR ÉLÈVE ----------\n");
    printf("Quel est le prénom de l'élève ? : ");
    scanf("%s", A->prenom);
    printf("Quel est le nom de l'élève ? : ");
    scanf("%s", A->nom);

    // Saisie du sexe de l'élève
    do { 
        printf("Quel est le sexe de %s %s ? ('H' ou 'F') : ", A->prenom, A->nom);
        scanf(" %c", &temp);
    } while (!((temp == 'H') || (temp == 'F'))); // Tant que l'utilisateur n'a pas rentré 'H' ou 'F' il continue à redemander
        
    switch (temp) { // En fonction de la réponse on assigne la bonne valeur à A.sexe
        case 'H':
            A->sexe = 1; // Passer le sexe à Homme
            break;
        default:
            A->sexe = 0; // Passer le sexe à Femme
            break;
    }

    // Saisie date de naissance de l'élève
    memset(&A->dateNaissance, 0, sizeof(struct tm));
    printf("Quel est la date de naissance de %s %s ? (dd/mm/yyyy)\n", A->prenom, A->nom);
    scanf("%2d/%2d/%4d", &A->dateNaissance.tm_mday, &A->dateNaissance.tm_mon, &A->dateNaissance.tm_year);
    A->dateNaissance.tm_mon -= 1;  // Les mois commencent à 0
    A->dateNaissance.tm_year -= 1900; // Les années commencent à 1900

    // Appeler la fonction AffecterEleveClasse() pour définir la classe de l'élève
    AffecterEleveClasse(A);
}

void AfficherEleve(const eleve_t *A) {
    char bufferDOB[100]; // Pour mettre la date au format texte
    char classe[100];

    printf("---------- ÉLÈVE %s %s ----------\n", A->prenom, A->nom);
    printf("Nom : %s\n", A->nom);
    printf("Prénom : %s\n", A->prenom);
    printf("Sexe : %s\n", (A->sexe == true ? "Homme" : "Femme")); // Fonction ternaire pour afficher une chaîne de caractères en fonction de la valeur de A.sexe

    strftime(bufferDOB, 100, "%d-%m-%Y", &A->dateNaissance); // Convertir une struct tm en chaîne de caractères
    printf("Date de naissance : %s\n", bufferDOB);
    
    switch (A->numClasse) { // Afficher la chaîne de caractères "CE1" en fonction de i
        case 1:
            strcpy(classe, "CP");
            break;
        case 2:
            strcpy(classe, "CE1");
            break;
        case 3:
            strcpy(classe, "CE2");
            break;
        case 4:
            strcpy(classe, "CM1");
            break;
        case 5:
            strcpy(classe, "CM2");
            break;
    }
    printf("Classe de l'élève : %s\n", classe);
}       

void ModifierEleve(eleve_t *A) {
    char reponse;
    char temp;
    char bufferDOB[100];

    printf("---------- MODIFIER ÉLÈVE %s %s -----------\n", A->prenom, A->nom);

    printf("-------------------------------------------\n");
    printf("| Que voulez-vous modifier ? -------------|\n");
    printf("| -1 : Prénom-----------------------------|\n");
    printf("| -2 : Nom--------------------------------|\n");
    printf("| -3 : Sexe-------------------------------|\n");
    printf("| -4 : Date de naissance------------------|\n");
    printf("-------------------------------------------\n");

    scanf(" %c", &reponse);

    switch (reponse)
    {
        case '1':
            printf("Vous avez choisi de modifier le prénom \"%s\", par quoi voulez-vous le modifier ?\n", A->prenom);
            scanf("%s", A->prenom);
            break;
        
        case '2':
            printf("Vous avez choisi de modifier le nom \"%s\", par quoi voulez-vous le modifier ?\n", A->nom);
            scanf("%s", A->nom);
            break;

        case '3':
            printf("Vous avez choisi de modifier le sexe \"%s\", par quoi voulez-vous le modifier ?\n", (A->sexe == true ? "Homme" : "Femme"));
            printf("\n");
            do { 
                printf("Quel est le sexe de %s %s ? ('H' ou 'F') : ", A->prenom, A->nom);
                scanf(" %c", &temp);
            } while (!((temp == 'H') || (temp == 'F'))); // Tant que l'utilisateur n'a pas rentré 'H' ou 'F' il continue à redemander
                
            switch (temp) { // En fonction de la réponse on assigne la bonne valeur à A.sexe
                case 'H':
                    A->sexe = 1; // Passer le sexe à Homme
                    break;
                default:
                    A->sexe = 0; // Passer le sexe à Femme
                    break;
            }
            break;

        case '4':
            printf("Vous avez choisi de modifier la date de naissance ");
            strftime(bufferDOB, 100, "%d-%m-%Y", &A->dateNaissance); // Convertir une struct tm en chaîne de caractères
            printf("Date de naissance : %s\n", bufferDOB);
            printf(" par quoi voulez-vous la modifier ? (dd/mm/yyyy) \n");

            scanf("%2d/%2d/%4d", &A->dateNaissance.tm_mday, &A->dateNaissance.tm_mon, &A->dateNaissance.tm_year);
            A->dateNaissance.tm_mon -= 1;  // Les mois commencent à 0
            A->dateNaissance.tm_year -= 1900; // Les années commencent à 1900

            strftime(bufferDOB, 100, "%d-%m-%Y", &A->dateNaissance); // Convertir une struct tm en chaîne de caractères
            printf("NOUVELLE Date de naissance : %s\n", bufferDOB);
            break;
        
        default:
            printf("Veuillez choisir un chiffre entre 1 et 4 ou appuyer sur 'q' pour quitter\n");
            break;
    }
}

// Fonction d'impression d'un élève dans un fichier
void ImprimerEleve(const eleve_t *A, char *nomFichier) {
    FILE *ptrfic;
    ptrfic = fopen(nomFichier, "a");
    
    if(ptrfic == NULL) {
        perror("Erreur d'écriture de l'élève");
        exit(EXIT_FAILURE);
    }
    
    char bufferDOB[100]; // Pour mettre la date au format texte
    char classe[100];

    fprintf(ptrfic, "---------- ÉLÈVE %s %s ----------\n", A->prenom, A->nom);
    fprintf(ptrfic, "Nom : %s\n", A->nom);
    fprintf(ptrfic, "Prénom : %s\n", A->prenom);
    fprintf(ptrfic, "Sexe : %s\n", (A->sexe == true ? "Homme" : "Femme")); // Fonction ternaire pour afficher une chaîne de caractères en fonction de la valeur de A.sexe

    strftime(bufferDOB, 100, "%d-%m-%Y", &A->dateNaissance); // Convertir une struct tm en chaîne de caractères
    fprintf(ptrfic, "Date de naissance : %s\n", bufferDOB);
    
    switch (A->numClasse) { // Afficher la chaîne de caractères "CE1" en fonction de i
        case 1:
            strcpy(classe, "CP");
            break;
        case 2:
            strcpy(classe, "CE1");
            break;
        case 3:
            strcpy(classe, "CE2");
            break;
        case 4:
            strcpy(classe, "CM1");
            break;
        case 5:
            strcpy(classe, "CM2");
            break;
    }
    fprintf(ptrfic, "Classe de l'élève : %s\n", classe);
    fprintf(ptrfic, "\n");
    fclose(ptrfic);
}