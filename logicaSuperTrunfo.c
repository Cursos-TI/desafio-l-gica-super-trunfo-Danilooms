#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[3];                // Ex: "SP"
    char codigo[10];              // Código da carta
    char nome_cidade[50];         // Nome da cidade
    int populacao;                // População
    float area;                   // Área em km²
    float pib;                    // Produto Interno Bruto
    int pontos_turisticos;       // Número de pontos turísticos

    // Atributos derivados
    float densidade_populacional;
    float pib_per_capita;
};

// Função para calcular os atributos derivados
void calcular_derivados(struct Carta *carta) {
    if (carta->area > 0)
        carta->densidade_populacional = carta->populacao / carta->area;
    else
        carta->densidade_populacional = 0;

    if (carta->populacao > 0)
        carta->pib_per_capita = carta->pib / carta->populacao;
    else
        carta->pib_per_capita = 0;
}

int main() {
    // Cadastro de duas cartas
    struct Carta carta1 = {
        "SP", "C001", "São Paulo",
        12300000, 1521.11, 700000.0, 15
    };

    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro",
        6710000, 1182.30, 400000.0, 20
    };

    // Calcular atributos derivados para as duas cartas
    calcular_derivados(&carta1);
    calcular_derivados(&carta2);

    // === Comparação por PIB per capita (escolhido diretamente no código) ===
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): R$ %.2f\n\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);

    // Lógica de comparação usando if-else
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}