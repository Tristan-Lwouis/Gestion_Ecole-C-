#include "fichier.h"

// Fonction d'écriture de fichier
void EcrireFichierTexte(const ecole_t *E, char *nomFichier) {
    FILE *ptrfic;
    ptrfic = fopen(nomFichier, "w");
    int totalClasse = 0;
    
    if(ptrfic == NULL) { // Si le fichier ne s'ouvre pas
        perror("Erreur d'écriture du fichier texte");
        exit(EXIT_FAILURE);
    }

    printf(">>> Enregistrement en cours dans le fichier \"%s\"\n", nomFichier);

    fprintf(ptrfic, "-------------------- ÉCOLE %s --------------------\n", E->nom);
    fprintf(ptrfic, "\n");
    fprintf(ptrfic, "Nom du directeur : %s %s\n", E->directeur.nom, E->directeur.prenom);
    
    // Informations relatives à l'école
    for (int i = 1; i < NIVEAUCLASSE; i++) {
        totalClasse = totalClasse + E->nbClasse[i];
    }
    fprintf(ptrfic, "Le total de classes dans l'école est de : %d\n", totalClasse);
    
    // Attention toute la partie suivante n'est pas dynamique si on change le nombre de classes possibles
    // ex: si on ajoute la classe de 6ème il faudra ajouter un nouveau fprintf associé
    fprintf(ptrfic, "Dans l'école il y a %d classes de CP\n", E->nbClasse[1]);
    fprintf(ptrfic, "Dans l'école il y a %d classes de CE1\n", E->nbClasse[2]);
    fprintf(ptrfic, "Dans l'école il y a %d classes de CE2\n", E->nbClasse[3]);
    fprintf(ptrfic, "Dans l'école il y a %d classes de CM1\n", E->nbClasse[4]);
    fprintf(ptrfic, "Dans l'école il y a %d classes de CM2\n", E->nbClasse[5]);
    fprintf(ptrfic, "--- FIN ÉCOLE -------------------------------------\n");
    fprintf(ptrfic, "\n");

    // Informations relatives aux classes
    for (int i = 1; i < NIVEAUCLASSE; i++) {
        // Permet de parcourir les différents niveaux de 1 à 5 -> de CP à CM2

        char classe[10]; // Permet de convertir la valeur de i en classe
        switch (i) { // Afficher la chaîne de caractères "CE1" en fonction de i
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
            default:
                break;
        }
        
        for (int j = 0; j < NUMEROCLASSE; j++) { // Permet de parcourir les classes de 0 à 3
            if (E->tabClasse[i][j].nbrEleve > 0) { // Si il y a au moins une classe de i ex:"CE1" alors je le print dans mon fichier

                // Afficher nom du prof et numéro de la classe
                fprintf(ptrfic, "~~~~~~~~~~~~~~ CLASSE DE %s %d ~~~~~~~~~~~~~~ \n", classe, j + 1);
                fprintf(ptrfic, "Nom du professeur : MMe ou Mr %s %s\n", E->tabClasse[i][j].prof.nom, E->tabClasse[i][j].prof.prenom);
                
                // Afficher tous les élèves dans la classe
                fclose(ptrfic);
                ImprimerClasse(&E->tabClasse[i][j], nomFichier);
                fopen(nomFichier, "a");
            }
        }
    }
}

// Fonction de lecture dans un fichier
void LectureFichierTexte(ecole_t *E, char *nomFichier)
{
    FILE *ptrfic = fopen(nomFichier, "r");
    if (!ptrfic) {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[512], nomClasse[20];
    char *morceau;
    int niveau = 0, indexClasse = 0;

    // Lecture nom de l'école
    fgets(ligne, sizeof(ligne), ptrfic);
    morceau = strstr(ligne, "École");
    morceau = strtok(ligne, "-");
    strcpy(E->nom, morceau);

    // Ligne vide
    fgets(ligne, sizeof(ligne), ptrfic);

    // Directeur
    fgets(ligne, sizeof(ligne), ptrfic);
    morceau = strtok(ligne, ":");
    morceau = strtok(NULL, " ");
    strcpy(E->directeur.nom, morceau);
    morceau = strtok(NULL, "\n");
    strcpy(E->directeur.prenom, morceau);

    // Total classes (on peut ignorer)
    fgets(ligne, sizeof(ligne), ptrfic);

    // Nombre de classes par niveau
    for (int i = 0; i < 5; i++) {
        fgets(ligne, sizeof(ligne), ptrfic);
        if (strstr(ligne, "CP")) 
            niveau = 1;
        else if (strstr(ligne, "CE1")) 
            niveau = 2;
        else if (strstr(ligne, "CE2")) 
            niveau = 3;
        else if (strstr(ligne, "CM1")) 
            niveau = 4;
        else if (strstr(ligne, "CM2")) 
            niveau = 5;
        morceau = strtok(ligne, " ");
        morceau = strtok(NULL, " ");
        morceau = strtok(NULL, " ");
        morceau = strtok(NULL, " ");
        morceau = strtok(NULL, " ");
        morceau = strtok(NULL, " ");
        E->nbClasse[niveau] = atoi(morceau);
    }

    // Lecture ligne FIN ÉCOLE
    fgets(ligne, sizeof(ligne), ptrfic);
    // Saut de ligne
    fgets(ligne, sizeof(ligne), ptrfic);
    printf("\n%s\n", ligne);
    
    // Lecture classes
    void ChargerEcoleDepuisFichier(FILE *ptrfic, ecole_t *E) {
        char ligne[256];
        char nomClasse[20];
        int niveau = 0;
        int indexClasse = 0;
    
        while (fgets(ligne, sizeof(ligne), ptrfic)) {
            if (strstr(ligne, "CLASSE DE")) {
                // Trouver le niveau
                sscanf(ligne, "~~~~~~~~~~~~~~ CLASSE DE %s ~~~~~~~~~~~~~~", nomClasse);
    
                if (strstr(nomClasse, "CP")) niveau = 1;
                else if (strstr(nomClasse, "CE1")) niveau = 2;
                else if (strstr(nomClasse, "CE2")) niveau = 3;
                else if (strstr(nomClasse, "CM1")) niveau = 4;
                else if (strstr(nomClasse, "CM2")) niveau = 5;
    
                indexClasse = atoi(&nomClasse[strlen(nomClasse) - 1]) - 1;
    
                // Lire le professeur
                fgets(ligne, sizeof(ligne), ptrfic); // "Nom du professeur : MMe ou Mr Durand Céline"
                char buffer[128], nom[64], prenom[64];
                sscanf(buffer, "%*[^ ] %s %s", nom, prenom); // Ignore titre, extrait nom/prénom
                strcpy(E->tabClasse[niveau][indexClasse].prof.nom, nom);
                strcpy(E->tabClasse[niveau][indexClasse].prof.prenom, prenom);
    
                // Lire nb filles et garçons
                fgets(ligne, sizeof(ligne), ptrfic); // "Dans la classe il y a X fille et Y garçon"
                int nbFille = 0, nbGarcon = 0;
                sscanf(ligne, "Dans la classe il y a %d fille et %d garçon", &nbFille, &nbGarcon);
                E->tabClasse[niveau][indexClasse].nbfille = nbFille;
                E->tabClasse[niveau][indexClasse].nbgars = nbGarcon;
                E->tabClasse[niveau][indexClasse].nbrEleve = nbFille + nbGarcon;
    
                // Lire les élèves
                for (int i = 0; i < nbFille + nbGarcon; i++) {
                    eleve_t *eleve = &E->tabClasse[niveau][indexClasse].tabPersonne[i];
    
                    fgets(ligne, sizeof(ligne), ptrfic); // ligne avec le nom complet — ignorée
                    fgets(ligne, sizeof(ligne), ptrfic); // Nom
                    sscanf(ligne, "Nom : %s", eleve->nom);
                    fgets(ligne, sizeof(ligne), ptrfic); // Prénom
                    sscanf(ligne, "Prenom : %s", eleve->prenom);
                    fgets(ligne, sizeof(ligne), ptrfic); // Sexe
                    if (strstr(ligne, "Homme")) 
                        eleve->sexe = true;
                    else 
                        eleve->sexe = false;
                    fgets(ligne, sizeof(ligne), ptrfic); // Date
                    int j, m, a;
                    sscanf(ligne, "Date de naissance : %d-%d-%d", &j, &m, &a);
                    eleve->dateNaissance.tm_mday = j;
                    eleve->dateNaissance.tm_mon = m - 1;
                    eleve->dateNaissance.tm_year = a - 1900;
    
                    eleve->numClasse = indexClasse;
                }
    
                // Met à jour le compteur de classes du niveau
                if (E->nbClasse[niveau] <= indexClasse)
                    E->nbClasse[niveau] = indexClasse + 1;
            }
        }
    }

    fclose(ptrfic);
    printf("\nLecture terminée avec succès.\n");
}