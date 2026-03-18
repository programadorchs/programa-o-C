#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct do Território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para criar um novo território
void cadastrarTerritorio(Territorio *mapa, int n){
    for (int i = 0; i < n; i++) {
        printf("\n---Cadastrar Território %d---\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Cor do exército: ");
        scanf("%s", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// Função para exibir territórios
void exibirTerritorios(Territorio *mapa, int n) {
    printf("\n===== ESTADO DOS TERRITÓRIOS =====\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função de ataque
void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n--- ATAQUE ---\n");
    printf("Atacante (%s) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) rolou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");

        // Transferir cor
        strcpy(defensor->cor, atacante->cor);

        // Transferir metade das tropas
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;

    } else {
        printf("Defensor venceu!\n");

        // Atacante perde uma tropa
        if (atacante->tropas > 0) {
            atacante->tropas--;
        }
    }
}

// Função para liberar memória
void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

// Programa principal
int main() {
    int n;

    srand(time(NULL)); // Inicializa aleatoriedade

    printf("Quantidade de territórios: ");
    scanf("%d", &n);

    // Alocação dinâmica
    Territorio *mapa = (Territorio *)calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, n);

    int atacanteIdx, defensorIdx;

    do {
        exibirTerritorios(mapa, n);

        printf("\nEscolha o índice do território atacante (-1 para sair): ");
        scanf("%d", &atacanteIdx);

        if (atacanteIdx == -1) break;

        printf("Escolha o índice do território defensor: ");
        scanf("%d", &defensorIdx);

        // Validações
        if (atacanteIdx < 0 || atacanteIdx >= n ||
            defensorIdx < 0 || defensorIdx >= n) {
            printf("Índices inválidos!\n");
            continue;
        }

        if (strcmp(mapa[atacanteIdx].cor, mapa[defensorIdx].cor) == 0) {
            printf("Não é permitido atacar territórios da mesma cor!\n");
            continue;
        }

        if (mapa[atacanteIdx].tropas <= 1) {
            printf("Tropas insuficientes para atacar!\n");
            continue;
        }

        atacar(&mapa[atacanteIdx], &mapa[defensorIdx]);

    } while (1);

    liberarMemoria(mapa);

    printf("\nJogo encerrado.\n");
    return 0;
}
