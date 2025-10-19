#include <stdio.h>
#include <string.h>
#include <stdbool.h>




typedef struct {
    int row;
    int col;
} Position;

Position directions[] = {
    {-1, 0},  // haut
    {1, 0},   // bas
    {0, -1},  // gauche
    {0, 1},   // droite
    {-1, -1}, // diagonale haut-gauche
    {-1, 1},  // diagonale haut-droite
    {1, -1},  // diagonale bas-gauche
    {1, 1}    // diagonale bas-droite
};


void printGridWithCoordinates() {
    printf("Grille avec cases (lettres et coordonnées):\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c(%d,%d) ", grid[r][c], r, c);
        }
        printf("\n");
    }
    printf("\n");
}


bool checkWord(int row, int col, char *word, Position dir) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int r = row + i * dir.row;
        int c = col + i * dir.col;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != word[i]) {
            return false;
        }
    }
    return true;
}


void findWord(char *word) {
    int len = strlen(word);
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            for (int d = 0; d < 8; d++) {
                if (checkWord(r, c, word, directions[d])) {
                    printf("Mot \"%s\" trouvé à (%d,%d) direction (%d,%d)\n",
                           word, r, c, directions[d].row, directions[d].col);
                    return;
                }
            }
        }
    }
    printf("Mot \"%s\" non trouvé\n", word);
}

int main() {
    printGridWithCoordinates();

    printf("Liste des mots recherchés et leur position :\n");
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        findWord(words[i]);
    }

    return 0;
}
