# Compilation du projet école
a.out : main.c menu.o fichier.o ecole.o classe.o eleve.o
	gcc main.c menu.o fichier.o ecole.o classe.o eleve.o

# Compilation des modules
menu.o : menu.c menu.h fichier.o ecole.o classe.o eleve.o
	gcc -c menu.c 

fichier.o : fichier.c fichier.h ecole.o classe.o eleve.o
	gcc -c fichier.c

ecole.o : ecole.c ecole.h classe.o eleve.o
	gcc -c ecole.c 

classe.o : classe.c classe.h eleve.o 
	gcc -c classe.c 

eleve.o : eleve.h eleve.c 
	gcc -c eleve.c

# Nettoyage des fichiers objets
clean :
	echo "Suppression des fichiers objets"
	rm -f *.o