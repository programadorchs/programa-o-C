#include <stdio.h>
#include <string.h>

int main() {
    // Carta 1
    char nome_do_estado1[50];
    char codigo_carta1[50];
    char nome_da_cidade1[50];
    int populacao1, numero_de_pontos_turisticos1, pontos1;
    float area1, PIB1, densidade_populacional1, PIB_per_capita1;

    // Carta 2
    char nome_do_estado2[50];
    char codigo_carta2[50];
    char nome_da_cidade2[50];
    int populacao2, numero_de_pontos_turisticos2, pontos2;
    float area2, PIB2, densidade_populacional2, PIB_per_capita2;
    
    // Informações da carta 1 abaixo !

    printf("Digite o codigo da primeira carta:");
    fgets(codigo_carta1, 50, stdin);
    codigo_carta1[strcspn(codigo_carta1, "\n")] = 0;
    printf("O codigo da carta é: %s\n", codigo_carta1);
// Codigo A01

    printf("Digite o nome do primeiro estado:");
    fgets(nome_do_estado1, 50, stdin);
    nome_do_estado1[strcspn(nome_do_estado1, "\n")] = 0;
    printf("O nome do estado é: %s\n", nome_do_estado1);
// Estado A

    printf("Digite o nome da primeira cidade: \n");
    scanf(" %[^\n]", nome_da_cidade1); // Usando o formato %[^\n] permite ler strings com espaços
    printf("O nome da cidade é: %s\n", nome_da_cidade1);
// Cidade: São Paulo

    printf("Digite a populacao: \n");
    scanf(" %d", &populacao1);
    printf("A populacao é: %d\n", populacao1);
// Populaçao 12325000

    printf("Digite a area (em km²): \n");
    scanf(" %f", &area1);
    printf("A area é: %.2f km²\n", area1);
// Area 1521.11 km²

    printf("Digite o PIB (em bilhões): \n");
    scanf(" %f", &PIB1);
    printf("O PIB é: %.2f bilhões\n", PIB1);
// PIB 699.28 Bilhoes de reais

    printf("Digite o numero de pontos turisticos: \n");
    scanf(" %d", &numero_de_pontos_turisticos1);
    printf("O numero de pontos turisticos é: %d\n", numero_de_pontos_turisticos1);
// Numero de pontos turisticos: 50

    //Calculo 1
    densidade_populacional1 = (float) populacao1 / area1;
    //Calculo 2
    PIB_per_capita1 = (PIB1 * 1000000000) / populacao1; // convertendo bilhões para unidade

    printf("\n===== Resultados =====\n");
    printf("Codigo da carta: %s\n", codigo_carta1);
    printf("Estado: %s\n", nome_do_estado1);    
    printf("Cidade: %s\n", nome_da_cidade1);
    printf("Populaçao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", PIB1);
    printf("Pontos turisticos: %d\n", numero_de_pontos_turisticos1);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidade_populacional1);
    printf("PIB per capita: %.2f reais\n", PIB_per_capita1);
// Codigo B02

    printf("=== Carta 2 ===\n");
    printf("Digite o codigo da segunda carta: \n");
    scanf(" %s", codigo_carta2);
    printf("O codigo da carta é: %s\n", codigo_carta2);
// Codigo B02

    printf("Digite o nome do segundo estado: \n");
    scanf(" %[^\n]", nome_do_estado2); // Usando o formato %[^\n] permite ler strings com espaços
    printf("O nome do estado é: %s\n", nome_do_estado2);
// Estado B

    printf("Digite o nome da segunda cidade: \n");
    scanf(" %[^\n]", nome_da_cidade2); // Usando o formato %[^\n] permite ler strings com espaços
    printf("O nome da cidade é: %s\n", nome_da_cidade2);
// Cidade: Rio de Janeiro

    printf("Digite a populacao: \n");
    scanf(" %d", &populacao2);
    printf("A populacao é: %d\n", populacao2);
// Populaçao 6748000

    printf("Digite a area (em km²): \n");
    scanf(" %f", &area2);
    printf("A area é: %.2f km²\n", area2);
// Area 1200.25 km²

    printf("Digite o PIB (em bilhões): \n");
    scanf(" %f", &PIB2);
    printf("O PIB é: %.2f bilhões\n", PIB2);
// PIB 300.50 Bilhoes de reais

    printf("Digite o numero de pontos turisticos: \n");
    scanf(" %d", &numero_de_pontos_turisticos2);
    printf("O numero de pontos turisticos é: %d\n", numero_de_pontos_turisticos2);
// Numero de pontos turisticos: 30

    //Calculos
    densidade_populacional2 = (float) populacao2 / area2;
    PIB_per_capita2 = (PIB2 * 1000000000) / populacao2; // convertendo bilhoes para unidade

    printf("\n===== Resultados =====\n");
    printf("Codigo da carta: %s\n", codigo_carta2);
    printf("Estado: %s\n", nome_do_estado2);
    printf("Cidade: %s\n", nome_da_cidade2);
    printf("Populaçao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", PIB2);
    printf("Pontos turisticos: %d\n", numero_de_pontos_turisticos2);
    printf("Densidade populacional: %.2f habitantes/km²\n", densidade_populacional2);
    printf("PIB per capita: %.2f reais\n", PIB_per_capita2);
    

    return 0;


}
