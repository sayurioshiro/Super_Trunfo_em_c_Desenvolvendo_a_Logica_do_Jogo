#include <stdio.h>

typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

int main() {

    Carta carta1 = {"Brasil", 203000000, 8515767, 1868.6, 100, 0};
    Carta carta2 = {"Argentina", 45000000, 2780400, 632.8, 60, 0};

    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO MESTRE ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    printf("Escolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2) {
        printf("Erro: atributos iguais!\n");
        return 1;
    }

    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    // Primeiro atributo
    switch(atributo1) {
        case 1:
            valor1_c1 = carta1.populacao;
            valor1_c2 = carta2.populacao;
            break;
        case 5:
            valor1_c1 = carta1.densidade;
            valor1_c2 = carta2.densidade;
            break;
    }

    // Segundo atributo
    switch(atributo2) {
        case 1:
            valor2_c1 = carta1.populacao;
            valor2_c2 = carta2.populacao;
            break;
        case 5:
            valor2_c1 = carta1.densidade;
            valor2_c2 = carta2.densidade;
            break;
    }

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma %s: %.2f\n", carta1.nomePais, soma1);
    printf("Soma %s: %.2f\n\n", carta2.nomePais, soma2);

    char* vencedor = (soma1 > soma2) ? carta1.nomePais :
                     (soma2 > soma1) ? carta2.nomePais : "Empate";

    printf("Resultado Final: %s\n", vencedor);

    return 0;
}