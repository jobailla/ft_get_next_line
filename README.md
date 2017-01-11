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

+ **1** - Si la ligne a été lue.
+ **0** - Si la lecture est terminée.
+ **-1** - Si il surviens une erreur.

Get next ligne doit renvoyer son resultat sans le '\n'
# Fonctionnement #

Un appel en boucle de la fonction permetra de lire le texte disponible sur un
descripteur de fichier une ligne a la fois jusqu'a la fin du texte quelque
soit la taille du texte en question ou d'une de ses lignes

Il faut verifier que la fonction fonctionne bien quand on lit sur une fichier
sur l'entree standard ou depuis une redirection...etc

Pseudo Code
===========

### Fonction :  t_gnl *find_fd(t_gnl **head, int cont fd)
---------------------------------------------------------

Renvoie un maillion sur notre liste chainee t_gnl

* t_gnl  *new
* t_gnl  *tmp

La fonction recherche dans notre liste le fd correspondant sinon elle va créee un nouveau maillon pour ce fd. Le nouveau maillon est plcer au debut de la liste.

NOTE : Cree une variable temportaire pour tester la position dans la liste.
       ft_bzero de new->next
	          *head = new

### Fonction :  int   look_buf(t_gnl *item, char **line)
--------------------------------------------------------

* char   *tmp

La fonction cherche la premiere occurance (ft_strchr) dans item->buf.

Si la premiere occurance est un retour a la ligne le caractere suivant est remplacer par un '\0' on stoke le pointeur dans tmp. (pour la gestion de tout les fichier utiliser memchr et pas qui strchr qui lui s'aretera au premier '\0')

Si *ligne != item->buf -> on renvoie 0
On va ensuite tester si tmp existe, s'il existe on copie item-buf dan tmp et on renvoi 1.

Enuite on netoi item->buf

### Fonction :  int   look_for_read(t_gnl *item, char **line)
-------------------------------------------------------------

* char   *tmp
* char   *save

Si la premiere occurance est un retour a la ligne le caractere suivant est remplacer par un '\0' on stoke le pointeur dans tmp.

* save = *line

Si on peut nous allons concatenner *line et item->buf.
Si on ne peut pas concater on libre save (strdel) et renvoyer -1.

Dans tous les cas on libere save
 
 Ensuite si tmp existe (tmp = pointeur sur le '\n'), on fait une copie de item->buf dans tmp et on renvoi 1

 Si tmp n'existe pas on renvoi 0.
