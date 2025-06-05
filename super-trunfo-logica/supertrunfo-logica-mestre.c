#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[5];
    char estado[30];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("Digite o código da carta (ex: A01): ");
    scanf("%4s", carta->codigo);

    printf("Digite o estado: ");
    scanf(" %29[^\n]", carta->estado);

    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", carta->nome);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área (km2): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (R$ bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void mostrarCarta(Carta c) {
    printf("\n--- Carta %s ---\n", c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km2\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
}

int compararAtributo(Carta c1, Carta c2, int attr) {
    switch (attr) {
        case 1: // População - maior vence
            return (c1.populacao > c2.populacao) ? 1 : (c1.populacao < c2.populacao) ? 2 : 0;
        case 2: // Área - maior vence
            return (c1.area > c2.area) ? 1 : (c1.area < c2.area) ? 2 : 0;
        case 3: // PIB - maior vence
            return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? 2 : 0;
        case 4: // Pontos turísticos - maior vence
            return (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : (c1.pontos_turisticos < c2.pontos_turisticos) ? 2 : 0;
        default:
            return -1; // atributo inválido
    }
}

int compararDoisAtributos(Carta c1, Carta c2, int atributo1, int atributo2) {
    int res1 = compararAtributo(c1, c2, atributo1);
    int res2 = compararAtributo(c1, c2, atributo2);

    if (res1 == res2) {
        // Mesma resposta nos dois atributos
        return res1; // 1, 2 ou 0 empate
    } else if (res1 == 0 && res2 != 0) {
        return res2; // desempate pelo segundo atributo
    } else if (res2 == 0 && res1 != 0) {
        return res1; // desempate pelo primeiro atributo
    } else {
        // Resultado diferente e nenhum empate - considerar empate geral
        return 0;
    }
}

const char* nomeAtributo(int attr) {
    switch (attr) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        default: return "Atributo desconhecido";
    }
}

int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;
    int resultado;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    printf("\nCartas cadastradas:\n");
    mostrarCarta(carta1);
    mostrarCarta(carta2);

    // Escolha dos atributos para comparação
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo1);

    printf("Escolha o segundo atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo2);

    // Validar entradas simples
    if (atributo1 < 1 || atributo1 > 4 || atributo2 < 1 || atributo2 > 4) {
        printf("Atributos inválidos. Finalizando o programa.\n");
        return 1;
    }

    resultado = compararDoisAtributos(carta1, carta2, atributo1, atributo2);

    printf("\nResultado da comparação:\n");
    if (resultado == 0) {
        printf("Empate entre as cartas %s e %s usando os atributos %s e %s.\n",
               carta1.codigo, carta2.codigo, nomeAtributo(atributo1), nomeAtributo(atributo2));
    } else if (resultado == 1) {
        printf("Carta %s venceu a carta %s com base nos atributos %s e %s.\n",
               carta1.codigo, carta2.codigo, nomeAtributo(atributo1), nomeAtributo(atributo2));
    } else if (resultado == 2) {
        printf("Carta %s venceu a carta %s com base nos atributos %s e %s.\n",
               carta2.codigo, carta1.codigo, nomeAtributo(atributo1), nomeAtributo(atributo2));
    } else {
        printf("Erro na comparação.\n");
    }

    return 0;
}
