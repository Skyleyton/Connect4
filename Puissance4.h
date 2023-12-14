#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#define NB_COLS 7
#define NB_LIGS 6

// Macro-fonctions.
// Va permettre de clear le terminal sur les systèmes Linux, donc pas très portable.
#define CLEAR_SCREEN printf("\e[1;1H\e[2J")

// TODO : Rendre le jeu le plus portable possible, je pourrais utiliser des tests #ifndef pour détecter la plateforme par exemple.

typedef struct Player {
  char jeton; // x ou o;
  char *nom; // Le nom du joueur.
} Player; 

// Pour la position de la pièce.
typedef struct Position {
  unsigned int colonne;
  unsigned int ligne;
} Position;

// Va servir à créer le plateau de jeu.
char **new_plateau();

// Affiche le plateau de jeu.
void affiche_plateau(char **plateau);

// Pour nettoyer le plateau.
void clean_plateau(char **plateau);

// Pour jouer un coup, retourne 1 si le coup est correct, 0 sinon.
int jouer_coup(char **plateau, Player player, int position);

// Vérifie si le plateau est plein, retourne 1 si plein, 0 sinon.
int is_plateau_full(char **plateau);

// Vérifie si un joueur a gagné, retourne 1 si oui, 0 sinon.
int is_win(char **plateau);

// Fonction pour le DEBUG.
void debug_remplir_plateau(char **plateau);
#endif
