#include <stdio.h>
#include <stdbool.h>

#define NUM 3

int grafo[NUM][NUM] = {
    {0, 2, 3},
    {2, 0, 4},
    {3, 4, 0}
};

void buscaProfundidade(int estadoAtual, int visitados[NUM]) {
    printf("Visitando estado %c\n", 'A' + estadoAtual);
    visitados[estadoAtual] = 1; 

    for (int i = 0; i < NUM; i++) {
        if (grafo[estadoAtual][i] > 0 && !visitados[i]) {
            buscaProfundidade(i, visitados); 
        }
    }
}

int main() {
    int estadoInicial;
    printf("Digite o estado inicial (0 para A, 1 para B, 2 para C): ");
    scanf("%d", &estadoInicial);

    if (estadoInicial < 0 || estadoInicial >= NUM) {
        printf("Estado inicial inválido.\n");
    } else {
        printf("Busca em profundidade com o estado inicial %c\n", 'A' + estadoInicial);
        int visitados[NUM] = {0};
        buscaProfundidade(estadoInicial, visitados);
    }

    return 0;
}
