#include "ecole.h"
#include "menu.h"

// Afficher l'ensemble des classes et des personnes dans les classes
void AfficherEcole(const ecole_t *e)
{
    printf("\nBienvenue à l'école : %s\n", e->nom);
    AfficherDirecteur(e);
    for (int i = 1; i < NIVEAUCLASSE; i++)
    {
        for (int k = 0; k < NUMEROCLASSE; k++)
        {
            if (e->tabClasse[i][k].nbrEleve != 0)
            {
                AfficherClasse(&e->tabClasse[i][k]);
            }
        }
    }
}

// Fonction qui boucle sur l'ensemble des classes en appelant la fonction RechercherEleveClasse()
bool RechercherEleveEcole(const ecole_t *e, const char *nom, const char *prenom, int *numClasse, int *numNiveauClasse, int *indicepersonne)
{
    int tmp;
    bool estPresent;
    
    for (int i = 0; i < NIVEAUCLASSE; i++) // Parcourt le tableau des niveaux CP, CE1, CE2, CM1, CM2
    {   
        tmp = e->nbClasse[i];
        
        for (int k = 0; k < tmp; k++) // Parcourt le nombre de classes en double ou en triple
        {
            estPresent = RechercheEleveClasse(&e->tabClasse[i][k], nom, prenom, indicepersonne);
            if (estPresent == true)
            {
                *numNiveauClasse = k;
                *numClasse = i;
                return true;
            }
        }
    }
    return false;
}

// Fonction de saisie du nom de l'école et du directeur
void SaisirEcole(ecole_t *e)
{
    eleve_t tmp; // Structure élève temporaire
    char conf; // Caractère de confirmation
    
    printf("\nQuel est le nom de l'école : ");
    scanf("%s", e->nom);
    SaisirDirecteur(&e->directeur);

    // Initialisation des noms de classes
    for(int i = 0; i < NUMEROCLASSE; i++)
    {
        strcpy(e->tabClasse[1][i].nom, "CP");
        strcpy(e->tabClasse[2][i].nom, "CE1");
        strcpy(e->tabClasse[3][i].nom, "CE2");
        strcpy(e->tabClasse[4][i].nom, "CM1");
        strcpy(e->tabClasse[5][i].nom, "CM2");
    }

    // Initialisation des compteurs
    for (int i = 0; i < NIVEAUCLASSE; i++)
    {
        e->nbClasse[i] = 0;
        for(int k = 0; k < NUMEROCLASSE; k++)
        {
            e->tabClasse[i][k].nbrEleve = 0;
            e->tabClasse[i][k].nbgars = 0;
            e->tabClasse[i][k].nbfille = 0;
        }
    }

    do
    {
        SaisirEleve(&tmp); // L'utilisateur saisit les infos de l'élève

        // En fonction de sa réponse on incrémente le tableau nbClasse
        if (tmp.numClasse == 1)
        {
            CopierEleve(&e->tabClasse[1][0].tabPersonne[e->nbClasse[1]], &tmp);
            e->nbClasse[1]++;
            e->tabClasse[1][0].nbrEleve++;
            if (tmp.sexe == true)
                e->tabClasse[1][0].nbgars++;
            else
                e->tabClasse[1][0].nbfille++;
        }
        else if (tmp.numClasse == 2)
        {
            CopierEleve(&e->tabClasse[2][0].tabPersonne[e->nbClasse[2]], &tmp);
            e->nbClasse[2]++;
            e->tabClasse[2][0].nbrEleve++;
            if (tmp.sexe == true)
                e->tabClasse[2][0].nbgars++;
            else
                e->tabClasse[2][0].nbfille++;
        }
        else if (tmp.numClasse == 3)
        {
            CopierEleve(&e->tabClasse[3][0].tabPersonne[e->nbClasse[3]], &tmp);
            e->nbClasse[3]++;
            e->tabClasse[3][0].nbrEleve++;
            if (tmp.sexe == true)
                e->tabClasse[3][0].nbgars++;
            else
                e->tabClasse[3][0].nbfille++;
        }
        else if (tmp.numClasse == 4)
        {
            CopierEleve(&e->tabClasse[4][0].tabPersonne[e->nbClasse[4]], &tmp);
            e->nbClasse[4]++;
            e->tabClasse[4][0].nbrEleve++;
            if (tmp.sexe == true)
                e->tabClasse[4][0].nbgars++;
            else
                e->tabClasse[4][0].nbfille++;
        }
        else if (tmp.numClasse == 5)
        {
            CopierEleve(&e->tabClasse[5][0].tabPersonne[e->nbClasse[5]], &tmp);
            e->nbClasse[5]++;
            e->tabClasse[5][0].nbrEleve++;
            if (tmp.sexe == true)
                e->tabClasse[5][0].nbgars++;
            else
                e->tabClasse[5][0].nbfille++;
        }

        do
        {
            printf("\nSaisir le caractère (c:continuer q:arrêter) : ");
            getchar();
            scanf("%c", &conf);
        } while (!(conf == 'q' || conf == 'c'));
        
    } while (conf == 'c');    

    // Saisie des professeurs
    for(int i = 1; i < NIVEAUCLASSE; i++)
    {
        int n;
        if (e->nbClasse[i] == 0) // Cas où il n'y a aucun élève
            printf("\nIl n'y a pas d'élève(s) en %s\n", e->tabClasse[i][0].nom);
        else
        {
            n = (e->nbClasse[i] / 25) + 1; 
            if (n == 1) // Si il y a une seule classe
            {
                printf("Saisir le prof de la première classe de %s\n", e->tabClasse[i][0].nom);
                SaisirProf(&e->tabClasse[i][0]);
            }
            else
            {
                for(int k = 0; k < n; k++)
                {
                    printf("Saisir le prof de la classe %s %d\n", e->tabClasse[i][k].nom, k);
                    SaisirProf(&e->tabClasse[i][k]);
                }
            }   
        }
    }

    RepartirClasse(e); 
} 

// RechercheEleveEcole() et printf ou SaisirEleve()/Repartir
void EstInscrit(ecole_t *e, const char *nom, const char *prenom)
{
    char rep;
    int i, j, k;
    bool reponse;
    
    reponse = RechercherEleveEcole(e, nom, prenom, &i, &j, &k);
    if (reponse == false)
    {
        printf("\nCet élève n'est pas inscrit\nVoulez-vous l'inscrire ? ('o' ou 'n')\n");
        getchar();
        scanf("%c", &rep);
        while (!(rep == 'o' || rep == 'n'));
        
        if (rep == 'o')
        {
            SaisirEleve(&e->tabClasse[0][0].tabPersonne[0]);
        }
        else if (rep == 'n')
        {
            MenuEleve1(e);
        }
    }
}

// Répartit les élèves de façon équitable dans les classes
void RepartirClasse(ecole_t *e) 
{
    int reste = 0;
    int classeACreer = 0;
    int nbrEleveClasse = 0;
    
    for (int i = 1; i < NIVEAUCLASSE; i++)
    {
        int nbEleveTmp = e->nbClasse[i];
        if (e->nbClasse[i] > MAXELEVE)
        {
            classeACreer = (e->nbClasse[i] + MAXELEVE - 1) / MAXELEVE;

            for(int j = 1; j < classeACreer; j++) // Boucle pour saisir les profs sauf pour la première classe
            {
                printf("Saisir le prof de la classe %s %d\n", e->tabClasse[i][j].nom, j);
                SaisirProf(&e->tabClasse[i][j]);
            }

            nbrEleveClasse = e->nbClasse[i] / classeACreer;
            reste = e->nbClasse[i] % classeACreer;

            for (int j = 1; j < classeACreer; j++) 
            {
                e->tabClasse[i][j].nbrEleve = nbrEleveClasse; // Mettre le nombre d'élève après répartition
                for (int k = 0; k < nbrEleveClasse; k++)
                {
                    nbEleveTmp--;

                    if (e->tabClasse[i][0].tabPersonne[nbEleveTmp].sexe == true)
                    {
                        e->tabClasse[i][0].nbgars--;
                        e->tabClasse[i][j].nbgars++;
                    }
                    else
                    {
                        e->tabClasse[i][0].nbfille--;
                        e->tabClasse[i][j].nbfille++;
                    }

                    CopierEleve(&e->tabClasse[i][j].tabPersonne[k], &e->tabClasse[i][0].tabPersonne[nbEleveTmp]);
                    e->tabClasse[i][0].nbrEleve--;
                }   
            }
            
            int compteur = 0; // Indice qui incrémente tmp
            int michel = 0; // Indice qui parcourt les nums de classe

            // Pour le reste
            while (reste > 0)
            {
                int jacky = e->tabClasse[i][michel].nbrEleve; // Indice qui indique l'endroit de la copie
                int tmp = nbrEleveClasse + 1 + compteur; // Indice qui indique l'élève à copier
                
                if (e->tabClasse[i][0].tabPersonne[tmp].sexe == true)
                {
                    e->tabClasse[i][0].nbgars--;
                    e->tabClasse[i][michel].nbgars++;
                }
                else
                {
                    e->tabClasse[i][0].nbfille--;
                    e->tabClasse[i][michel].nbfille++;
                }
                
                CopierEleve(&e->tabClasse[i][michel].tabPersonne[jacky], &e->tabClasse[i][0].tabPersonne[tmp]);
                e->tabClasse[i][michel].nbrEleve++;
                e->tabClasse[i][0].nbrEleve--;
                
                reste--;
                michel++;
                compteur++;
            }
        }

        for(int i = 0; i < NIVEAUCLASSE; i++) // Changer le total des élèves par classe en nombre de classe
            e->nbClasse[i] = e->nbClasse[i] / 25;
    }
}

// Permet de saisir un directeur d'une école
void SaisirDirecteur(directeur_t *d)
{
    printf("\nSaisir le prénom du directeur : ");
    scanf("%s", d->prenom);
    printf("\nSaisir le nom du directeur : ");
    scanf("%s", d->nom);
}

// Permet de modifier le nom et prénom du directeur
void ModifierDirecteur(directeur_t *d)
{
    printf("\nQuel est le nouveau prénom du directeur : ");
    scanf("%s", d->prenom);
    printf("\nQuel est le nouveau nom du directeur : ");
    scanf("%s", d->nom);
}

void AfficherDirecteur(const ecole_t *e)
{
    printf("\nL'école %s est dirigée par %s %s\n", e->nom, e->directeur.nom, e->directeur.prenom);
}

void CopierEleve(eleve_t *dest, const eleve_t *source)
{
    strcpy(dest->nom, source->nom);
    strcpy(dest->prenom, source->prenom);
    dest->sexe = source->sexe;
    dest->dateNaissance.tm_mday = source->dateNaissance.tm_mday;
    dest->dateNaissance.tm_mon = source->dateNaissance.tm_mon;
    dest->dateNaissance.tm_year = source->dateNaissance.tm_year;
    dest->numClasse = source->numClasse;
}
