Get next line
=============
Get next line est une fonction qui renvoi une ligne depuis un file descriptor.
Une ligne est une suite de caracteres terminee par un '\n'.

# Parametres #

### (const int fd) ###
fd est le file descriptor depuis lequel lire.

### char **line ###

line est l'adresse d'une pointeur sur caractere qui servira a stoker la ligne
sur le file descriptor.

# Valeur de retour

+ 1
Si la ligne a été lue.

+  0
Si la lecture est terminée.

+ -1
Si il surviens une erreur.

Get next ligne doit renvoyer son resultat sans le '\n'
# Fonctionnement #

Un appel en boucle de la fonction permetra de lire le texte disponible sur un
descripteur de fichier une ligne a la fois jusqu'a la fin du texte quelque
soit la taille du texte en question ou d'une de ses lignes

Il faut verifier que la fonction fonctionne bien quand on lit sur une fichier
sur l'entree standard ou depuis une redirection...etc

Pseudo Code
===========

### Fonction : ft_check_line(char *str, int size) ###


