#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3 ");
            } else if (tabuleiro[i][j] == 5) {
                printf(" 5 ");
            }
        }
        printf("\n");
    }
}

void definirHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = TAMANHO_HABILIDADE / 2 - i; j <= TAMANHO_HABILIDADE / 2 + i; j++) {
            if (i <= TAMANHO_HABILIDADE / 2) {
                cone[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - TAMANHO_HABILIDADE / 2 + i;
            int colunaTabuleiro = origemColuna - TAMANHO_HABILIDADE / 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO && cone[i][j] == 1) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
        }
    }
}

void definirHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int cruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        cruz[origemLinha][i] = 1;
        cruz[i][origemColuna] = 1;
    }

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (cruz[i][j] == 1) {
                tabuleiro[i][j] = 5;
            }
        }
    }
}

void definirHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int octaedro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (abs(origemLinha - i) == abs(origemColuna - j)) {
                octaedro[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (octaedro[i][j] == 1) {
                tabuleiro
