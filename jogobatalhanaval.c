#include <stdio.h>

// Nível NOVATO - Batalha de Xadrez

int main() {

    // Inicializando o jogo "Batalha Naval"
    printf("=== Desafio da Batalha Naval ===\n\n");
    printf("0 = Água\n");
    printf("3 = Navio\n\n");


    // Variáveis do tabuleiro
    int tabuleiro[10][10];
    int i, j;
    
    // Inicializar o tabuleiro com 0s
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
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

    // Exibir o cabeçalho das colunas (letras A–J)
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Exibir as linhas numeradas de 1 a 10
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Exibir as posições dos navios no tabuleiro
    printf("\nNAVIO 1 ESTÁ NAS POSIÇÕES (HORIZONTAL): C6, D6 & E6.\n");
    printf("NAVIO 2 ESTÁ NAS POSIÇÕES (VERTICAL): H4, H5 & H6.\n");


    return 0;
}