#include <stdio.h>

#define n 3

void exibir_tabuleiro(char tabuleiro[n][n]);
char verificar_vencedor(char tabuleiro[n][n]);

int main() {
    char tabuleiro[n][n] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    int jogadas_total = 0;
    char vencedor = ' ';

    while (vencedor == ' ' && jogadas_total < n * n) {
        exibir_tabuleiro(tabuleiro);

        int pos_i, pos_j;
        char jogador_atual = (jogadas_total % 2 == 0) ? 'X' : 'O';

        printf("JOGADOR %c\n", jogador_atual);

        while (1) {
            printf("Digite a linha e coluna (0 a %d, ex: 0 0): ", n - 1);
            if (scanf("%d %d", &pos_i, &pos_j) != 2) {
                printf("Entrada inválida! Digite dois números.\n");
                while(getchar() != '\n');
                continue;
            }

            if (pos_i < 0 || pos_i >= n || pos_j < 0 || pos_j >= n) {
                printf("Posição fora dos limites do tabuleiro! Tente novamente.\n");
                continue;
            }

            if (tabuleiro[pos_i][pos_j] != ' ') {
                printf("Posição já ocupada! Tente novamente.\n");
                continue;
            }
            break;
        }

        tabuleiro[pos_i][pos_j] = jogador_atual;
        jogadas_total++;

        vencedor = verificar_vencedor(tabuleiro);
    }

    exibir_tabuleiro(tabuleiro);

    if (vencedor != ' ') {
        printf("FIM DE JOGO! O jogador %c venceu!\n", vencedor);
    } else {
        printf("FIM DE JOGO! É um empate!\n");
    }

    return 0;
}

void exibir_tabuleiro(char tabuleiro[n][n]) {
    printf("\n--- TABULEIRO ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < n - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < n - 1) {
            printf("---|---|---\n");
        }
    }
    printf("-----------------\n");
}

char verificar_vencedor(char tabuleiro[n][n]) {
    for (int i = 0; i < n; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2] &&
            tabuleiro[i][0] != ' ') {
            return tabuleiro[i][0];
        }
    }

    for (int j = 0; j < n; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] &&
            tabuleiro[1][j] == tabuleiro[2][j] &&
            tabuleiro[0][j] != ' ') {
            return tabuleiro[0][j];
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2] &&
        tabuleiro[0][0] != ' ') {
        return tabuleiro[0][0];
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0] &&
        tabuleiro[0][2] != ' ') {
        return tabuleiro[0][2];
    }

    return ' ';
}