#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio horizontal pode ser posicionado
bool podePosicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return false;
    }
    return true;
}

// Função para verificar se o navio vertical pode ser posicionado
bool podePosicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return false;
    }
    return true;
}

// Função para verificar se o navio diagonal (\) pode ser posicionado
bool podePosicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return false;
    }
    return true;
}

// Função para verificar se o navio diagonal (/) pode ser posicionado
bool podePosicionarNavioDiagonalInverso(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha - TAMANHO_NAVIO + 1 < 0 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha - i][coluna + i] != 0) return false;
    }
    return true;
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para posicionar um navio diagonal (\)
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

// Função para posicionar um navio diagonal (/)
void posicionarNavioDiagonalInverso(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha - i][coluna + i] = 3;
    }
}

int main() {
    // Inicializa o tabuleiro com 0s (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios definidos no código
    // Navios horizontais
    int linhaH1 = 1, colunaH1 = 2;
    int linhaH2 = 4, colunaH2 = 5;
    
    // Navios verticais
    int linhaV1 = 6, colunaV1 = 7;
    int linhaV2 = 8, colunaV2 = 1;

    // Navios diagonais
    int linhaD1 = 2, colunaD1 = 2;
    int linhaD2 = 7, colunaD2 = 7;

    // Validação e posicionamento dos navios horizontais
    if (podePosicionarNavioHorizontal(tabuleiro, linhaH1, colunaH1)) {
        posicionarNavioHorizontal(tabuleiro, linhaH1, colunaH1);
    }

    if (podePosicionarNavioHorizontal(tabuleiro, linhaH2, colunaH2)) {
        posicionarNavioHorizontal(tabuleiro, linhaH2, colunaH2);
    }

    // Validação e posicionamento dos navios verticais
    if (podePosicionarNavioVertical(tabuleiro, linhaV1, colunaV1)) {
        posicionarNavioVertical(tabuleiro, linhaV1, colunaV1);
    }

    if (podePosicionarNavioVertical(tabuleiro, linhaV2, colunaV2)) {
        posicionarNavioVertical(tabuleiro, linhaV2, colunaV2);
    }

    // Validação e posicionamento dos navios diagonais
    if (podePosicionarNavioDiagonal(tabuleiro, linhaD1, colunaD1)) {
        posicionarNavioDiagonal(tabuleiro, linhaD1, colunaD1);
    }

    if (podePosicionarNavioDiagonalInverso(tabuleiro, linhaD2, colunaD2)) {
        posicionarNavioDiagonalInverso(tabuleiro, linhaD2, colunaD2);
    }

    // Exibe o tabuleiro final
    printf("\nTabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
