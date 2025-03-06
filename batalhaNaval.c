#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para validar se o navio pode ser colocado nas coordenadas especificadas
bool podePosicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro na posição horizontal
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return false;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return false;  // Já tem algo no lugar
        }
    }

    return true;
}

bool podePosicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro na posição vertical
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return false;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return false;  // Já tem algo no lugar
        }
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

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com 0 (água)

    int linhaH, colunaH, linhaV, colunaV;

    // Solicita as coordenadas para o navio horizontal
    printf("Digite as coordenadas para o navio horizontal (linha e coluna): ");
    scanf("%d %d", &linhaH, &colunaH);

    // Valida e posiciona o navio horizontal
    if (podePosicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) {
        posicionarNavioHorizontal(tabuleiro, linhaH, colunaH);
    } else {
        printf("Posição inválida para o navio horizontal!\n");
        return 1;
    }

    // Solicita as coordenadas para o navio vertical
    printf("Digite as coordenadas para o navio vertical (linha e coluna): ");
    scanf("%d %d", &linhaV, &colunaV);

    // Valida e posiciona o navio vertical
    if (podePosicionarNavioVertical(tabuleiro, linhaV, colunaV)) {
        posicionarNavioVertical(tabuleiro, linhaV, colunaV);
    } else {
        printf("Posição inválida para o navio vertical!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
