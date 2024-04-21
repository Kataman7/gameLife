# Jeu de la vie

Le but de ce projet est d'implémenter le jeu de la vie, un automate cellulaire créé par le mathématicien britannique John Horton Conway en 1970. Le jeu se déroule sur une grille infinie de cellules, chaque cellule pouvant être vivante ou morte. Chaque cellule a huit voisines, qui sont les cellules qui sont horizontalement, verticalement ou diagonalement adjacentes. À chaque étape, les cellules vivantes ou mortes évoluent selon les règles suivantes :

1. Une cellule vivante avec moins de deux voisines vivantes meurt de solitude.
2. Une cellule vivante avec deux ou trois voisines vivantes continue à vivre.
3. Une cellule vivante avec plus de trois voisines vivantes meurt de surpopulation.
4. Une cellule morte avec exactement trois voisines vivantes devient vivante (naît).

## Utilisation

Pour utiliser ce projet, vous devez d'abord le cloner sur votre ordinateur en utilisant la commande suivante :
```
git clone https://github.com/[votre_nom_utilisateur]/jeu_de_la_vie.git
```
Ensuite, vous pouvez vous rendre dans le répertoire du projet en utilisant la commande :
```
cd jeu_de_la_vie
```
Pour compiler le projet, vous pouvez utiliser la commande suivante :
```
gcc -o jeu_de_la_vie main.c -lncurses
```
Cela va créer un exécutable nommé `jeu_de_la_vie` que vous pouvez lancer en utilisant la commande :
```
./jeu_de_la_vie
```
Par défaut, le jeu s'exécutera en mode automatique, avec une vitesse de 1. Vous pouvez spécifier une vitesse différente en passant un argument à la ligne de commande, comme ceci :
```
./jeu_de_la_vie 0.5
```
Cela va exécuter le jeu à une vitesse de 0.5.

Pendant que le jeu s'exécute, vous pouvez utiliser les touches suivantes :

* `Espace` : bascule entre le mode automatique et le mode manuel. En mode manuel, vous devez appuyer sur `Espace` pour passer à l'étape suivante.
* `q` : quitte le jeu.
* `p` : bascule entre le mode automatique et le mode pause. En mode pause, le jeu ne s'exécute pas, même si vous êtes en mode automatique.
* `Clic gauche` : bascule l'état d'une cellule (vivante ou morte) à l'endroit où vous avez cliqué.

Vous pouvez également utiliser la souris pour dessiner des formes sur la grille en cliquant et en faisant glisser le bouton gauche de la souris. Cela peut être utile pour créer des motifs intéressants au début du jeu.

Amusez-vous bien à explorer le jeu de la vie !
