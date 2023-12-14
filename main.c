#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Puissance4.h"

int main(int argc, char *argv[]) {
    printf("%s\n", "Hello World !");

    char **plateau = new_plateau();

    Player player1 = {
	    'x',
	    "joueur 1",
    };

    Player player2 = {
	    'o',
	    "joueur 2",
     };

    printf("Veuillez entrer le pseudo du joueur qui jouera le jeton %c: ", player1.jeton);
    player1.nom = malloc(256 * sizeof(*player1.nom));
    scanf("%s", player1.nom);

    printf("Veuillez entrer le pseudo du joueur qui jouera le jeton %c: ", player2.jeton);
    player2.nom = malloc(256 * sizeof(*player2.nom));
    scanf("%s", player2.nom);
  
    int in_game = 1; // 1: Indique qu'on est en partie, 0: fin de la partie.
    unsigned int tour = 0; // Le nombre de tour de la partie.
    int gagnant = 0; // 0: Pas encore de gagnant.
    Player current_player = {0};
    while (in_game) {
        // Clear screen.
        CLEAR_SCREEN;

        printf("Tour numéro %d\n", tour);

        // Test si la partie est terminé.
        if (is_plateau_full(plateau)) {
            printf("Partie terminé\n");
            affiche_plateau(plateau);
            in_game = 0;
            break;
        }

        // Test si un joueur a gagné.
        if (is_win(plateau)) {
            printf("%s a gagné.\n", current_player.nom);
            affiche_plateau(plateau);
            in_game = 0;
            break;
        }

        // Change de joueur à chaque tour.
        if (tour % 2 == 0) {
            current_player = player1;
        }
        else current_player = player2;

	    affiche_plateau(plateau);

        // Demande le choix du joueur sous forme de chaine de caractère.
        printf("\nVotre coup: ");
        char *choix = malloc(1 * sizeof(*choix)); // Allocation pour un seul caractère dans la chaine.
        scanf("%s", choix);

        // Convertit le choix du joueur en entier.
        int col = atoi(choix);
        if ( strcmp(choix, "q") == 0 ) {
            printf("Aurevoir !\n");
            break;
        }

        if (col < 1 || col > 7) {
            fprintf(stderr, "%s\n", "Erreur de colonne, veuillez reéssayer.");
            continue;
        }
        
        if (jouer_coup(plateau, current_player, col-1) == 1) {
            tour++;
        }
        else continue;
    }

    return 0;
}

