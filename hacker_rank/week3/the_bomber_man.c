#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Display the current grid
void showGrid(int rows, int cols, char **mat) {
    for (int i = 0; i < rows; i++) {
        printf("%s\n", mat[i]);
    }
}

// Free allocated memory
void releaseGrid(int rows, char **mat) {
    if (mat == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Perform one detonation cycle
char **explode(int rows, int cols, char **mat) {
    char **res = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        res[i] = (char *)malloc((cols + 1) * sizeof(char));
        memset(res[i], 'O', cols);
        res[i][cols] = '\0';
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 'O') {
                res[i][j] = '.';
                if (i > 0) res[i - 1][j] = '.';
                if (i < rows - 1) res[i + 1][j] = '.';
                if (j > 0) res[i][j - 1] = '.';
                if (j < cols - 1) res[i][j + 1] = '.';
            }
        }
    }
    return res;
}

// Main Bomberman simulation
void bomberGame(long t, int rows, int cols, char **mat) {
    if (t == 1) {
        showGrid(rows, cols, mat);
        return;
    }

    if (t % 2 == 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("O");
            }
            printf("\n");
        }
        return;
    }

    char **first = explode(rows, cols, mat);

    if (t % 4 == 3) {
        showGrid(rows, cols, first);
        releaseGrid(rows, first);
        return;
    }

    char **second = explode(rows, cols, first);
    showGrid(rows, cols, second);

    releaseGrid(rows, second);
    releaseGrid(rows, first);
}

int main() {
    int r, c;
    long n;
    scanf("%d %d %ld", &r, &c, &n);

    char **grid = (char **)malloc(r * sizeof(char *));
    for (int i = 0; i < r; i++) {
        grid[i] = (char *)malloc((c + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    bomberGame(n, r, c, grid);
    releaseGrid(r, grid);

    return 0;
}
