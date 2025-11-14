#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 8
#define NAVIOS 5

void inicializar(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '~';  // água
}

void imprimir(char tab[TAM][TAM], int revelar) {
    printf("  ");
    for (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            if (!revelar && tab[i][j] == 'N')
                printf("~ ");
            else
                printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int posicao_valida(char tab[TAM][TAM], int x, int y, int tam, int dir) {
    // dir: 0 = horizontal, 1 = vertical
    for (int i = 0; i < tam; i++) {
        int nx = x + (dir ? i : 0);
        int ny = y + (dir ? 0 : i);

        if (nx >= TAM || ny >= TAM) return 0;
        if (tab[nx][ny] != '~') return 0;
    }
    return 1;
}

void posicionar_navios(char tab[TAM][TAM]) {
    int tamanhos[NAVIOS] = {5, 4, 3, 3, 2};

    for (int k = 0; k < NAVIOS; k++) {
        int tam = tamanhos[k];
        int x, y, dir, ok = 0;

        while (!ok) {
            x = rand() % TAM;
            y = rand() % TAM;
            dir = rand() % 2;

            if (posicao_valida(tab, x, y, tam, dir)) {
                for (int i = 0; i < tam; i++) {
                    int nx = x + (dir ? i : 0);
                    int ny = y + (dir ? 0 : i);
                    tab[nx][ny] = 'N';
                }
                ok = 1;
            }
        }
    }
}

int realizar_tiro(char tab[TAM][TAM], int x, int y) {
    if (x < 0 || x >= TAM || y < 0 || y >= TAM)
        return -1; // inválido

    if (tab[x][y] == 'N') {
        tab[x][y] = 'X'; // acerto
        return 1;
    }
    if (tab[x][y] == '~') {
        tab[x][y] = 'O'; // água
        return 0;
    }
    return -1; // já atirou aqui
}

int navios_restantes(char tab[TAM][TAM]) {
    int count = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (tab[i][j] == 'N') count++;
    return count;
}

int main() {
    srand(time(NULL));

    char tab[TAM][TAM];
    inicializar(tab);
    posicionar_navios(tab);

    int x, y, status;

    printf("===== BATALHA NAVAL =====\n");

    while (1) {
        printf("\nTabuleiro:\n");
        imprimir(tab, 0);

        printf("\nDigite coordenadas (linha coluna): ");
        scanf("%d %d", &x, &y);

        status = realizar_tiro(tab, x, y);

        if (status == 1) {
            printf("💥 ACERTOU UM NAVIO!\n");
        } else if (status == 0) {
            printf("🌊 Acertou a água...\n");
        } else {
            printf("⚠️ Tiro inválido ou repetido.\n");
        }

        if (navios_restantes(tab) == 0) {
            printf("\n🎉 Parabéns! Você afundou todos os navios!\n");
            break;
        }
    }

    printf("\nTabuleiro final (navios revelados):\n");
    imprimir(tab, 1);

    return 0;
}

