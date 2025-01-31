# Get_Next_Line
![illustration getnextline]()
Le projet get_next_line de l'École 42 vise à développer une fonction en C capable de lire et de retourner une ligne complète depuis un descripteur de fichier, à chaque appel. Ce projet est essentiel pour comprendre la gestion des entrées/sorties en C, la manipulation des descripteurs de fichiers, et l'utilisation des variables statiques.

🎯 Objectifs du Projet
Lecture Ligne par Ligne : Implémenter une fonction get_next_line qui lit une ligne complète depuis un descripteur de fichier donné.

Gestion des Descripteurs de Fichiers : Apprendre à manipuler les descripteurs de fichiers pour lire des données depuis différentes sources, telles que des fichiers ou l'entrée standard.

Utilisation des Variables Statiques : Comprendre et utiliser les variables statiques pour conserver l'état entre les appels de fonction, notamment pour gérer les données restantes entre les lectures.

🛠️ Spécifications Techniques
Prototype de la Fonction :
char *get_next_line(int fd);

Comportement Attendu :
La fonction doit lire une ligne complète depuis le descripteur de fichier fd et la retourner.

Une ligne est définie par une séquence de caractères se terminant par un saut de ligne ('\n') ou par la fin du fichier (EOF).

La fonction doit gérer les descripteurs de fichiers multiples, en conservant l'état de lecture pour chacun.

Gestion de la Mémoire :

Allouer dynamiquement la mémoire nécessaire pour chaque ligne lue.

Assurer la libération appropriée de la mémoire allouée pour éviter les fuites de mémoire.

Variables Statiques :

Utiliser des variables statiques pour stocker les données restantes entre les appels de la fonction, permettant ainsi de gérer correctement les lectures partielles.

🔧 Approche d'Implémentation
Lecture par Blocs :

Lire le contenu du descripteur de fichier par blocs de taille définie (BUFFER_SIZE).

Concaténer les blocs lus jusqu'à ce qu'une ligne complète soit obtenue.

Gestion des Lignes :

Identifier la position du caractère de saut de ligne ('\n') pour délimiter la fin de la ligne.

Extraire la ligne complète et conserver le reste des données pour les appels suivants.

Utilisation des Variables Statiques :

Stocker les données restantes après chaque lecture dans une variable statique, afin de les utiliser lors des appels ultérieurs de la fonction pour le même descripteur de fichier.
Gestion des Erreurs :

Gérer les cas où la lecture échoue, où la mémoire ne peut pas être allouée, ou où le descripteur de fichier est invalide.

📂 Structure du Projet
Fichiers Principaux :

get_next_line.c : Contient l'implémentation de la fonction principale get_next_line.

get_next_line.h : Déclare le prototype de la fonction et les inclusions nécessaires.

get_next_line_utils.c : Contient les fonctions utilitaires utilisées par get_next_line (par exemple, fonctions de manipulation de chaînes).

Compilation :

Utiliser un Makefile pour automatiser la compilation du projet.

Définir la macro BUFFER_SIZE lors de la compilation pour spécifier la taille des blocs de lecture.

🧪 Tests et Validation
Cas de Test :

Lire des fichiers de différentes tailles, y compris des fichiers vides et de très grands fichiers.

Tester la lecture depuis l'entrée standard (stdin).

Gérer les fichiers contenant des lignes sans saut de ligne final.

Gestion des Descripteurs Multiples :

Assurer que la fonction peut gérer plusieurs descripteurs de fichiers simultanément, en maintenant l'état de lecture pour chacun.
Vérification des Fuites de Mémoire :

Utiliser des outils tels que Valgrind pour détecter et corriger les fuites de mémoire potentielles.

📚 Ressources Utiles

[Dépôt GitHub : Implémentation de get_next_line][https://github.com/mcombeau/get_next_line]
[Vidéo Explicative : get_next_line expliqué spécial DBZ][https://www.youtube.com/watch?v=8E9siq7apUU]