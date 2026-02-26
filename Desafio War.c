#include <stdio.h>
#include <string.h>

#define QTD 5

//Definição da estrutura Territorio
struct Territorio {
    char nome [30];
    char cor [10];
    int tropas;
};

int main() {
    struct Territorio territorios[QTD];

    //Cadastro dos territórios  
    for (int i = 0; i < QTD; i++) {
            printf("Digite o nome do território %d: ", i + 1);
            fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
            territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;  // Remove a nova linha

            printf("Digite a cor do território %d: ", i + 1);
            fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
            territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;  // Remove a nova linha

            printf("Digite o número de tropas do território %d: ", i + 1);
            scanf("%d", &territorios[i].tropas);
            getchar();
        }

            // Exibição dos territórios cadastrados
            printf("\n==== Territórios Cadastrados ====\n");
            for (int i = 0; i < QTD; i++) {
                printf("Território %d:\n", i + 1);
                printf("Nome: %s\n", territorios[i].nome);
                printf("Cor: %s\n", territorios[i].cor);
                printf("Tropas: %d\n", territorios[i].tropas);
        }

        return 0;

}