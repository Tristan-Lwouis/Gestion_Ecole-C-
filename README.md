# Projet École C - Gestion d'établissement scolaire

## Description

Ce projet est une application de gestion d'école développée en langage C. Elle permet de gérer les élèves, les classes, les professeurs et les informations générales d'un établissement scolaire.

## Fonctionnalités

### Gestion des élèves
- Saisie d'informations d'élèves (nom, prénom, sexe, date de naissance)
- Affichage des informations d'élèves
- Modification des données d'élèves
- Recherche d'élèves dans l'école
- Affectation automatique des élèves à une classe selon leur âge

### Gestion des classes
- Affichage des classes avec leurs élèves
- Gestion des professeurs par classe
- Répartition automatique des élèves dans les classes

### Gestion de l'école
- Saisie des informations de l'école (nom, directeur)
- Affichage des informations générales
- Recherche d'élèves dans l'établissement
- Vérification d'inscription d'élèves

### Gestion des fichiers
- Sauvegarde des données dans des fichiers texte
- Lecture des données depuis des fichiers texte

## Structure du projet

```
PROJET_ECOLE/
├── main.c          # Point d'entrée du programme
├── menu.h/c        # Gestion des menus utilisateur
├── ecole.h/c       # Gestion de l'école et du directeur
├── classe.h/c      # Gestion des classes et professeurs
├── eleve.h/c       # Gestion des élèves
├── fichier.h/c     # Gestion des fichiers
├── Makefile        # Compilation du projet
└── README.md       # Documentation
```

## Compilation

Pour compiler le projet, utilisez la commande :
```bash
make
```

Pour nettoyer les fichiers objets :
```bash
make clean
```

## Utilisation

1. Lancez le programme : `./a.out`
2. Suivez les menus pour naviguer dans l'application
3. Utilisez les options disponibles pour gérer les données de l'école

## Niveaux de classe

Le système gère les niveaux suivants :
- CP (Cours Préparatoire)
- CE1 (Cours Élémentaire 1)
- CE2 (Cours Élémentaire 2)
- CM1 (Cours Moyen 1)
- CM2 (Cours Moyen 2)

## Auteurs

Projet réalisé dans le cadre d'un cours de programmation en langage C.

## Licence

Ce projet est fourni à des fins éducatives.
