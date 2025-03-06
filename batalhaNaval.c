#include <stdio.h>
#include <stdlib.h>  // Inclui a biblioteca para abs()

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5  // Tamanho das matrizes de habilidade (5x5)

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3 ");
            } else if (tabuleiro[i][j] == 5) {
                printf(" 5 ");  // Representação das áreas afetadas pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para definir a habilidade em cone
void definirHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    // Construindo a forma do cone (simétrica em relação à linha superior)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = TAMANHO_HABILIDADE / 2 - i; j <= TAMANHO_HABILIDADE / 2 + i; j++) {
            if (i <= TAMANHO_HABILIDADE / 2) {
                cone[i][j] = 1;  // Marca a área afetada
            }
        }
    }

    // Sobrepondo a matriz de cone no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - TAMANHO_HABILIDADE / 2 + i;
            int colunaTabuleiro = origemColuna - TAMANHO_HABILIDADE / 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO && cone[i][j] == 1) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;  // Marca a área afetada pela habilidade (cone)
            }
        }
    }
}

// Função para definir a habilidade em cruz
void definirHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    // Construindo a forma da cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        cruz[TAMANHO_HABILIDADE / 2][i] = 1;  // Linha central
        cruz[i][TAMANHO_HABILIDADE / 2] = 1;  // Coluna central
    }

    // Sobrepondo a matriz de cruz no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - TAMANHO_HABILIDADE / 2 + i;
            int colunaTabuleiro = origemColuna - TAMANHO_HABILIDADE / 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO && cruz[i][j] == 1) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;  // Marca a área afetada pela habilidade (cruz)
            }
        }
    }
}

// Função para definir a habilidade em octaedro
void definirHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    // Construindo a forma do octaedro (losango)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                octaedro[i][j] = 1;  // Marca a área afetada
            }
        }
    }

    // Sobrepondo a matriz de octaedro no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - TAMANHO_HABILIDADE / 2 + i;
            int colunaTabuleiro = origemColuna - TAMANHO_HABILIDADE / 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO && octaedro[i][j] == 1) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;  // Marca a área afetada pela habilidade (octaedro)
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro com 0s (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios definidos no código
    int linhaH1 = 1, colunaH1 = 2;
    int linhaH2 = 4, colunaH2 = 5;
    
    // Posicionamento dos navios no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH1][colunaH1 + i] = 3;
        tabuleiro[linhaH2][colunaH2 + i] = 3;
    }

    // Definir habilidades
    definirHabilidadeCone(tabuleiro, 2, 3);   // Cone no ponto (2, 3)
    definirHabilidadeCruz(tabuleiro, 5, 5);   // Cruz no ponto (5, 5)
    definirHabilidadeOctaedro(tabuleiro, 7, 7); // Octaedro no ponto (7, 7)

    // Exibe o tabuleiro final
    printf("\nTabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
