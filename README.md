# Voici l'objectif du projet: 

- Vous avez 2 piles nommées a et b.
- Au début :
	- La pile a contient une quantité aléatoire de nombres négatifs et/ou positifs qui ne peuvent pas être dupliqués.
	- La pile b est vide.
- Le but est de trier par ordre croissant les nombres dans la pile a en utilisant le moins d'opération possible. Les opérations disponibles sont les suivante :
	- sa (swap a) : Intervertir les 2 premiers éléments en haut de la pile a. Ne fait rien s'il n'y a qu'un seul ou aucun élément.
	- sb (swap b) : Echanger les 2 premiers éléments au sommet de la pile b. Ne faites rien s'il n'y a qu'un seul ou aucun élément.
	- ss : sa et sb en même temps.
	- pa (push a) : Prendre le premier élément au sommet de b et le mettre au sommet de a. Ne fait rien si b est vide.
	- pb (push b) : Prend le premier élément au sommet de a et le met au sommet de b. Ne fait rien si a est vide.
	- ra (rotate a) : Décale vers le haut tous les éléments de la pile a de 1. Le premier élément devient le dernier.
	- rb (rotation de b) : Déplace vers le haut tous les éléments de la pile b de 1. Le premier élément devient le dernier.
	- rr : ra et rb en même temps.
	- rra (reverse rotate a) : Décale vers le bas tous les éléments de la pile a de 1. Le dernier élément devient le premier.
	- rrb (reverse rotate b) : Décale vers le bas tous les éléments de la pile b de 1. Le dernier élément devient le premier.
	-rrr : rra et rrb en même temps.
	
# Utilisation:
Faites `make all` pour build les binaires.
Le programme `push_swap` permet de trier une pile passée en paramètres tandis que `checker` permet de vérifier les résultats du tri.
Pour vérifier le résultat du tri: `arg=$(sh gen.sh 500); ./push_swap $arg | ./checker $arg`
Pour compter le nombre d'opérations utilisées :`arg=$(sh gen.sh 500); ./push_swap $arg | wc -l`
