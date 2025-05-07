#include <stdio.h>

// Nível AVENTUREIRO - Batalha de Xadrez

#define TAB 10
#define NAVIOS 3

int main() {
    printf("=== Bem-vindo ao Desafio da Batalha Naval ===\n\n");
    printf("0 = Água\n");
    printf("3 = Navio\n\n");

    int tabuleiro[TAB][TAB];
    int i, j;

    // Inicializar tabuleiro com 0s (água)
    for (i = 0; i < TAB; i++) {
        for (j = 0; j < TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definir e inicializar a posição dos navios
    int navio1[3] = {2, 3, 4};
    int navio2[3] = {3, 4, 5}; 
    
    // Colocar o navio1 horizontalmente (linha 5)
    for (i = 0; i < 3; i++) {
        tabuleiro[5][navio1[i]] = 3;
    }

    // Colocar o navio2 verticalmente (coluna 7)
    for (i = 0; i < 3; i++) {
        tabuleiro[navio2[i]][7] = 3;
    }

    // Colocar o navio3 diagonalmente (linhas 1, 2 e 3; coluna 1, 2 e 3)
    for (i = 1; i == 1; i++) {
        for (j = 1; j == 1; j++) {
            tabuleiro[i][j] = NAVIOS;
            tabuleiro[i + 1][j + 1] = NAVIOS;
            tabuleiro[i + 2][j + 2] = NAVIOS;
        }
    }

    // Colocar o navio3 diagonalmente (linhas 6, 7 e 8; coluna 6, 7 e 8)
    for (i = 6; i == 6; i++) {
        for (j = 8; j == 8; j++) {
            tabuleiro[i][j] = NAVIOS;
            tabuleiro[i + 1][j - 1] = NAVIOS;
            tabuleiro[i + 2][j - 2] = NAVIOS;
        }
    }

    // Exibir o cabeçalho das colunas (letras A–J)
    printf("   ");
    for (j = 0; j < TAB; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Exibir as linhas numeradas de 1 a 10
    for (i = 0; i < TAB; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAB; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Exibir as posições dos navios no tabuleiro
    printf("\nNAVIO 1 ESTÁ NAS POSIÇÕES (HORIZONTAL): C6, D6 & E6.\n");
    printf("NAVIO 2 ESTÁ NAS POSIÇÕES (VERTICAL): H4, H5 & H6.\n");
    printf("NAVIO 3 ESTÁ NAS POSIÇÕES (DIAGONAL PRINCIPAL): B2, C3, D4.\n");
    printf("NAVIO 4 ESTÁ NAS POSIÇÕES (DIAGONAL SECUNDÁRIA): G9, H8, I7.\n");

    return 0;
}
