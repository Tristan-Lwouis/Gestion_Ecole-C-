//Elias
#include "fichier.h"

// Menu d'accueil (sans nom d'école) propose 
// 1 - la lecture d'un fichier d'école ou
// 2 - Saisir d'une école entière
void MenuAccueil1(ecole_t* e); 

// Menu Classe
// Menu qui permet de choisir si on veut 
// 1 - Afficher un tableau d'élèves
// 2 - Afficher une classe
// 3 - Saisir un prof
// 4 - Rechercher un élève dans une classe
// 5 - Accueil École
// 6 - Accueil élève
// 7 - Menu des menus
void MenuClasse1(ecole_t* e);

// Menu Élève
// Menu qui permet de choisir si on veut 
// 1 - Saisir un élève
// 2 - Afficher un élève
// 3 - Affecter un élève
// 4 - Modifier un élève
// 5 - Rechercher un élève
// 6 - Menu principal
void MenuEleve1(ecole_t* e);
void MenuEleve2(ecole_t* e);

// Menu École
// Menu qui permet de choisir si on veut
// 1 - Afficher École
// 2 - Saisir École
// 3 - Rechercher un élève dans l'école (retourne un booléen)
// 4 - Rechercher si un élève est bien inscrit dans l'école sinon l'enregistrer
// 5 - Répartir les classes
// 6 - Saisir Directeur
// 7 - Afficher Directeur
void MenuEcole1(ecole_t* e);

// Menu général
// Menu qui permet la navigation entre les menus
// 1 - Menu Élève
// 2 - Menu Classe
// 3 - Menu École
// 4 - Lire Fichier
// 5 - Écrire Fichier
// 0 - Quitter
void MenuGeneral(ecole_t* e);
