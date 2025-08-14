#include "menu.h"

// Menu d'accueil (sans nom d'école)
void MenuAccueil1(ecole_t* e)
{
    int choix;
    do
    {
        printf("\nBienvenue\n");
        printf("1 - Saisir une école\n");
        printf("2 - Lecture d'un fichier d'école existant\n");
        printf("3 - Impression dans un fichier texte\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
    } while (choix != 1 && choix != 2 && choix != 3);

    if (choix == 1)
    {
        SaisirEcole(e);
        MenuGeneral(e);
    }
    else if (choix == 2)
    {
        printf("Fonction de lecture de fichier à compléter.\n");
    }
    else if (choix == 3)
    {
        // Fonction à implémenter
    }
}

// Menu général
void MenuGeneral(ecole_t* e)
{ 
    system("clear");
    char nomFichier[20];
    int choix = -1;
    
    do
    {
        printf("\n--- Menu Général ---\n");
        printf("1 - Menu Élève\n2 - Menu Classe\n3 - Menu École\n4 - Lire Fichier\n5 - Écrire Fichier\n0 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1: 
                MenuEleve1(e); 
                break;
            case 2: 
                MenuClasse1(e); 
                break;
            case 3: 
                MenuEcole1(e); 
                break;
            case 4:
                printf("\nQuel est le nom du fichier que vous souhaitez lire ? ");
                scanf("%s", nomFichier); 
                LectureFichierTexte(e, nomFichier); 
                break;
            case 5: 
                printf("\nQuel est le nom du fichier que vous souhaitez écrire ? ");
                scanf("%s", nomFichier);
                EcrireFichierTexte(e, nomFichier); 
                break;
            case 0: 
                printf("Au revoir !\n"); 
                break;
            default: 
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}

// Menu Élève
void MenuEleve1(ecole_t* e)
{
    system("clear");
    int choix = -1;
    int niveauClasse, numeroClasse;
    char nom[20], prenom[20];

    do {
        printf("\n--- Menu Élève ---\n");
        printf("1 - Saisir un élève\n2 - Afficher un élève\n3 - Modifier un élève\n4 - Rechercher un élève\n6 - Menu Général\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        int u, y, t;
        bool retour;
        
        switch (choix) 
        {
            case 1:
                e->tabClasse[0][0].nbrEleve++;
                SaisirEleve(&e->tabClasse[0][0].tabPersonne[0]);
                printf("\nVous avez bien saisi l'élève :\n");
                AfficherEleve(&e->tabClasse[0][0].tabPersonne[0]);
                break;
            case 2: 
                MenuEleve2(e);
                break;
            case 3:
                printf("\nQuel élève souhaitez-vous modifier ?\nSaisir le nom et prénom : ");
                scanf("%s %s", nom, prenom);
                printf("\nSaisir niveau (1-5) et classe (0-2) et l'indice de l'élève : ");
                scanf("%d %d %d", &u, &y, &t);
                retour = RechercherEleveEcole(e, nom, prenom, &u, &y, &t);
                ModifierEleve(&e->tabClasse[u][y].tabPersonne[t]);
                break;
            case 4:
                printf("Nom et prénom : ");
                scanf("%s %s", nom, prenom);
                retour = RechercherEleveEcole(e, nom, prenom, &u, &y, &t);
                if (retour == false)
                {
                    printf("\nIl n'est pas présent\n");
                }
                break;
            case 6: 
                MenuGeneral(e);
                break;
        }
    } while (choix != 6);
}

void MenuEleve2(ecole_t* e)
{
    system("clear");
    int choix = -1;
    int niveauClasse, numeroClasse;
    char nom[20], prenom[20];

    do {
        printf("\n--- Menu Afficher un Élève ---\n");
        printf("1 - Vous connaissez la classe et le niveau de l'élève\n2 - Rechercher par son nom et prénom\n6 - Menu Général\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) 
        {
            case 1:
                printf("Saisir niveau (1-5) et classe (0-2) : ");
                scanf("%d %d", &niveauClasse, &numeroClasse);
                for (int i = 0; i < e->tabClasse[niveauClasse][numeroClasse].nbrEleve; i++)
                {
                    AfficherEleve(&e->tabClasse[niveauClasse][numeroClasse].tabPersonne[i]);
                }
                break;
            case 2:
                printf("\nVeuillez saisir le nom et le prénom de l'élève : ");
                scanf("%s %s", nom, prenom);
                int u, y, t;
                bool rep;
                rep = RechercherEleveEcole(e, nom, prenom, &u, &y, &t);
                if (rep == true)
                {
                    AfficherEleve(&e->tabClasse[u][y].tabPersonne[t]);
                }
                else
                {
                    printf("Il n'est pas là\n");
                }
                break;
            case 6: 
                MenuGeneral(e);
                break;
        }
    } while (choix != 6);
}

// Menu Classe
void MenuClasse1(ecole_t* e)
{
    system("clear");
    int choix = -1;
    char nom[20], prenom[20];
    int indice;
    int niveauClasse = 0;
    int numeroClasse = 0;

    do {
        printf("\n--- Menu Classe ---\n");
        printf("1 - Afficher classe\n5 - Menu Général\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) 
        {
            case 1: 
                printf("Les élèves de quelle classe souhaitez-vous afficher ?\nSaisir niveau (1-5) et classe (0-2) : ");
                scanf("%d %d", &niveauClasse, &numeroClasse);
                AfficherClasse(&e->tabClasse[niveauClasse][numeroClasse]); 
                break;
            case 5: 
                MenuGeneral(e);
                break;
        }
    } while (choix != 5);
}

// Menu École
void MenuEcole1(ecole_t* e)
{
    system("clear");
    int choix = -1;
    char nom[20], prenom[20];
    int niveau, classe, indice;
    bool rep;

    do {
        printf("\n--- Menu École ---\n");
        printf("1 - Afficher École\n2 - Saisir École\n3 - Rechercher élève\n4 - Saisir directeur (écrase le directeur actuel)\n5 - Afficher directeur\n6 - Savoir si un élève est inscrit\n7 - Menu Général\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) 
        {
            case 1: 
                AfficherEcole(e); 
                break;
            case 2: 
                SaisirEcole(e); 
                break;
            case 3:
                printf("Nom, prénom, niveau, classe, indice : ");
                scanf("%s %s %d %d %d", nom, prenom, &niveau, &classe, &indice);
                rep = RechercherEleveEcole(e, nom, prenom, &niveau, &classe, &indice);
                printf("Résultat : %s\n", rep ? "Trouvé" : "Non trouvé");
                break;
            case 4: 
                SaisirDirecteur(&e->directeur); 
                break;
            case 5: 
                AfficherDirecteur(e); 
                break;
            case 6: 
                printf("Nom prénom : ");
                scanf("%s %s", nom, prenom);
                EstInscrit(e, nom, prenom);
                break;
            case 7: 
                MenuGeneral(e);
                break;
        }
    } while (choix != 7);
}






