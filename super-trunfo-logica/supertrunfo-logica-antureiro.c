#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    double area;
    double pib;
    int pontos_turisticos;
} Carta;

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void cadastrarCarta(Carta *carta) {
    printf("Digite o estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    removerNovaLinha(carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    removerNovaLinha(carta->codigo);

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    removerNovaLinha(carta->nome);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%lf", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    getchar(); // limpa o '\n' do buffer do scanf
}

void exibirCarta(Carta carta) {
    printf("\n--- Carta %s ---\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2lf km²\n", carta.area);
    printf("PIB: %.2lf bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

int compararCartas(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: // população - maior vence
            if (c1.populacao > c2.populacao) return 1;
            else if (c1.populacao < c2.populacao) return 2;
            else return 0;
        case 2: // área - maior vence
            if (c1.area > c2.area) return 1;
            else if (c1.area < c2.area) return 2;
            else return 0;
        case 3: // PIB - maior vence
            if (c1.pib > c2.pib) return 1;
            else if (c1.pib < c2.pib) return 2;
            else return 0;
        case 4: // pontos turísticos - maior vence
            if (c1.pontos_turisticos > c2.pontos_turisticos) return 1;
            else if (c1.pontos_turisticos < c2.pontos_turisticos) return 2;
            else return 0;
        default:
            return -1; // opção inválida
    }
}

int main() {
    Carta carta1, carta2;
    int opcao, resultado;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    resultado = compararCartas(carta1, carta2, opcao);

    if (resultado == 1)
        printf("A carta vencedora é: %s (%s)\n", carta1.codigo, carta1.nome);
    else if (resultado == 2)
        printf("A carta vencedora é: %s (%s)\n", carta2.codigo, carta2.nome);
    else if (resultado == 0)
        printf("Empate entre as cartas!\n");
    else
        printf("Opção inválida!\n");

    return 0;
}
