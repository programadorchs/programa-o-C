#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int posicao_valida(int linha, int coluna) {
    return linha >= 1 && linha <= 8 && coluna >= 1 && coluna <= 8;
}

void movimentos_torre(int linha, int coluna) {
    printf("Movimentos da Torre:\n");
    for (int i = 1; i <= 8; i++) {
        if (i != linha) printf("(%d, %d)\n", i, coluna);
        if (i != coluna) printf("(%d, %d)\n", linha, i);
    }
}

void movimentos_bispo(int linha, int coluna) {
    printf("Movimentos do Bispo:\n");
    for (int i = 1; i <= 8; i++) {
        if (posicao_valida(linha + i, coluna + i)) printf("(%d, %d)\n", linha + i, coluna + i);
        if (posicao_valida(linha - i, coluna - i)) printf("(%d, %d)\n", linha - i, coluna - i);
        if (posicao_valida(linha + i, coluna - i)) printf("(%d, %d)\n", linha + i, coluna - i);
        if (posicao_valida(linha - i, coluna + i)) printf("(%d, %d)\n", linha - i, coluna + i);
    }
}

void movimentos_cavalo(int linha, int coluna) {
    printf("Movimentos do Cavalo:\n");
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int nova_linha = linha + movimentos[i][0];
        int nova_coluna = coluna + movimentos[i][1];
        if (posicao_valida(nova_linha, nova_coluna)) {
            printf("(%d, %d)\n", nova_linha, nova_coluna);
        }
    }
}

int main() {
    char peca;
    int linha, coluna;

    printf("Escolha a peça (T=t, B=b, C=c): ");
    scanf(" %c", &peca);
    peca = tolower(peca);

    printf("Digite a posição atual da peça (linha e coluna, de 1 a 8): ");
    scanf("%d %d", &linha, &coluna);

    if (!posicao_valida(linha, coluna)) {
        printf("Posição inválida!\n");
        return 1;
    }

    switch (peca) {
        case 't':
            movimentos_torre(linha, coluna);
            break;
        case 'b':
            movimentos_bispo(linha, coluna);
            break;
        case 'c':
            movimentos_cavalo(linha, coluna);
            break;
        default:
            printf("Peça inválida!\n");
    }

    return 0;
}

