#include <stdio.h>

// Nível MESTRE - Batalha de Xadrez
#define TAB 10
#define HAB 5
#define NAVIOS 3

// Estruturar o tabuleiro com o cabeçalho nas colunas e as linhas numeradas
void exibirTabuleiro(int tabuleiro[TAB][TAB]) {
    printf("   ");
    for (int j = 0; j < TAB; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAB; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAB; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Definir e inicializar a posição da habilidade: Cruz
void desenharCruz(int tabuleiro[TAB][TAB], int linha, int coluna) {
    int matriz[HAB][HAB] = {0};
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 5;  // Atualizando para 5
            }
        }
    }

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int ti = linha - centro + i;
            int tj = coluna - centro + j;

            if (ti >= 0 && ti < TAB && tj >= 0 && tj < TAB && matriz[i][j] == 5) {
                tabuleiro[ti][tj] = 5;
            }
        }
    }
}

// Definir e inicializar a posição da habilidade: Cone
void desenharCone(int tabuleiro[TAB][TAB], int linha, int coluna) {
    int matriz[HAB][HAB] = {0};
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                matriz[i][j] = 5;  // Atualizando para 5
            }
        }
    }

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int ti = linha - centro + i;
            int tj = coluna - centro + j;

            if (ti >= 0 && ti < TAB && tj >= 0 && tj < TAB && matriz[i][j] == 5) {
                tabuleiro[ti][tj] = 5;
            }
        }
    }
}

// Definir e inicializar a posição da habilidade: Octaedro
void desenharOctaedro(int tabuleiro[TAB][TAB], int linha, int coluna) {
    int matriz[HAB][HAB] = {0};
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        int distancia = i <= centro ? i : HAB - 1 - i;
        for (int j = centro - distancia; j <= centro + distancia; j++) {
            matriz[i][j] = 5;  // Atualizando para 5
        }
    }

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int ti = linha - centro + i;
            int tj = coluna - centro + j;

            if (ti >= 0 && ti < TAB && tj >= 0 && tj < TAB && matriz[i][j] == 5) {
                tabuleiro[ti][tj] = 5;
            }
        }
    }
}

// Definir e inicializar a posição dos navios
void colocarNavios(int tabuleiro[TAB][TAB]) {

    // Colocar o navio1 horizontalmente (linha 5)
    tabuleiro[5][2] = NAVIOS;
    tabuleiro[5][3] = NAVIOS;
    tabuleiro[5][4] = NAVIOS;

    // Colocar o navio2 verticalmente (coluna 7)
    tabuleiro[3][7] = NAVIOS;
    tabuleiro[4][7] = NAVIOS;
    tabuleiro[5][7] = NAVIOS;

    // Colocar o navio3 diagonalmente (linhas 1, 2 e 3; coluna 1, 2 e 3)
    tabuleiro[1][1] = NAVIOS;
    tabuleiro[2][2] = NAVIOS;
    tabuleiro[3][3] = NAVIOS;

    // Colocar o navio4 diagonalmente (linhas 6, 7 e 8; coluna 6, 7 e 8)
    tabuleiro[8][6] = NAVIOS;
    tabuleiro[7][7] = NAVIOS;
    tabuleiro[6][8] = NAVIOS;
}

int main() {

    // Inicializar tabuleiro com 0s (água)
    int tabuleiro[TAB][TAB] = {0};

    // Colocando os navios no tabuleiro
    colocarNavios(tabuleiro);

    // Aplicando as habilidades no tabuleiro
    desenharCone(tabuleiro, 1, 2);
    desenharCruz(tabuleiro, 7, 2);
    desenharOctaedro(tabuleiro, 2, 7);

    // Exibir o tabuleiro (resultado final)
    printf("=== Desafio da Batalha Naval ===\n");
    printf("\n");

    printf("0 = Água\n");
    printf("3 = Navio\n");
    printf("5 = Áreas de Habilidade\n");
    printf("\n");

    exibirTabuleiro(tabuleiro);

    // Exibir as posições dos navios no tabuleiro
    printf("\nNAVIO 1 ESTÁ NAS POSIÇÕES (HORIZONTAL): C6, D6 & E6.\n");
    printf("NAVIO 2 ESTÁ NAS POSIÇÕES (VERTICAL): H4, H5 & H6.\n");
    printf("NAVIO 3 ESTÁ NAS POSIÇÕES (DIAGONAL PRINCIPAL): B2, C3, D4.\n");
    printf("NAVIO 4 ESTÁ NAS POSIÇÕES (DIAGONAL SECUNDÁRIA): G9, H8, I7.\n");

    printf("\n");
    printf("Navios 1, 2 e 3 foram atingidos pelas habilidades!\n");

    return 0;
}
