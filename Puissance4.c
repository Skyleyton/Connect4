#include "Puissance4.h"
#include <stdio.h>
#include <stdlib.h>

char **new_plateau() {
  char **plateau = NULL;
  plateau = malloc(NB_LIGS * sizeof(*plateau));

  for (int i = 0; i < NB_LIGS; i++) {
	plateau[i] = malloc(NB_COLS * sizeof(**plateau));
  }

  clean_plateau(plateau);
  
  return plateau;
}

void affiche_plateau(char **plateau) {
  printf("%s\n", "1 2 3 4 5 6 7");
  for (int i = 0; i < NB_LIGS; i++) {
	for (int j = 0; j < NB_COLS; j++) {
	  printf("%c ", plateau[i][j]);
	}
	printf("%c", '\n');
  }
  
  return;
}

void clean_plateau(char **plateau) {
  for (int i = 0; i < NB_LIGS; i++) {
	for (int j = 0; j < NB_COLS; j++) {
	  plateau[i][j] = '-';
	}
  }
}

int jouer_coup(char **plateau, Player player, int position) {
    for (int i = NB_LIGS - 1; i >= 0; i--) {
        if (plateau[i][position] == '-') {
            plateau[i][position] = player.jeton;
            return 1;
        }
    }

    fprintf(stderr, "%s\n", "Colonne pleine.");
    return 0;
}

int is_plateau_full(char **plateau) {
    for (int j = 0; j < NB_COLS; j++) {
        if (plateau[0][j] == '-') {
            return 0;
        }
    }

    return 1;
}

int is_win(char **plateau) {
    /* Alignement horizontal */
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'x'\
                && plateau[i][j+1] == 'x'\
                && plateau[i][j+2] == 'x'\
                && plateau[i][j+3] == 'x') return 1;
        }
    }
    
    // Même commentaires qu'en haut.
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'o'\
                && plateau[i][j+1] == 'o'\
                && plateau[i][j+2] == 'o'\
                && plateau[i][j+3] == 'o') return 1;
        }
    }

    /* Alignement vertical 
     * Ici je fais -1 car le pion va tomber en bas donc si je fais
     * +1 je fais avoir un segfault (je parle en connaissances causes xD). */
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'x'\
                && plateau[i-1][j] == 'x'\
                && plateau[i-2][j] == 'x'\
                && plateau[i-3][j] == 'x') return 1;
        }
    }
    
    // Même commentaires qu'en haut.
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'o'\
                && plateau[i-1][j] == 'o'\
                && plateau[i-2][j] == 'o'\
                && plateau[i-3][j] == 'o') return 1;
        }
    }

    /* Alignement horizontal haut-gauche vers bas-droit. */
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'x'\
                && plateau[i-1][j-1] == 'x'\
                && plateau[i-2][j-2] == 'x'\
                && plateau[i-3][j-3] == 'x') return 1;
        }
    }

    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'o'\
                && plateau[i-1][j-1] == 'o'\
                && plateau[i-2][j-2] == 'o'\
                && plateau[i-3][j-3] == 'o') return 1;
        }
    }

    /* Alignement horizontal bas-gauche vers haut-droit. */
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'x'\
                && plateau[i-1][j+1] == 'x'\
                && plateau[i-2][j+2] == 'x'\
                && plateau[i-3][j+3] == 'x') return 1;
        }
    }

    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            if (plateau[i][j] == 'o'\
                && plateau[i-1][j+1] == 'o'\
                && plateau[i-2][j+2] == 'o'\
                && plateau[i-3][j+3] == 'o') return 1;
        }
    }

    return 0;
}

// DEBUG
void debug_remplir_plateau(char **plateau) {
    for (int i = 0; i < NB_LIGS; i++) {
        for (int j = 0; j < NB_COLS; j++) {
            plateau[i][j] = 'x';
        }
    }

    return;
}


