#include <stdio.h>
#include <stdbool.h>

#define NUM_STATES 3

int graph[NUM_STATES][NUM_STATES] = {
    {0, 2, 3},
    {2, 0, 4},
    {3, 4, 0}
};

typedef struct {
    int estado;
    int distancia;
} No;

typedef struct {
    No dados[NUM_STATES];
    int inicio, fim;
} Fila;

void inicializarFila(Fila *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

bool estaVazia(Fila *fila) {
    return fila->inicio == -1;
}

void enfileirar(Fila *fila, int estado, int distancia) {
    fila->fim++;
    fila->dados[fila->fim].estado = estado;
    fila->dados[fila->fim].distancia = distancia;

    if (fila->inicio == -1) {
        fila->inicio = 0;
    }
}

No desenfileirar(Fila *fila) {
    No no = fila->dados[fila->inicio];

    if (fila->inicio == fila->fim) {
        fila->inicio = -1;
        fila->fim = -1;
    } else {
        fila->inicio++;
    }

    return no;
}

void buscaLargura(int estadoInicial) {
    Fila fila;
    inicializarFila(&fila);
    enfileirar(&fila, estadoInicial, 0);

    int visitados[NUM_STATES] = {0}; 

    while (!estaVazia(&fila)) {
        No atual = desenfileirar(&fila);
        visitados[atual.estado] = 1;

        printf("Visitando estado %c\n", 'A' + atual.estado);

        for (int i = 0; i < NUM_STATES; i++) {
            if (graph[atual.estado][i] > 0 && !visitados[i]) {
                enfileirar(&fila, i, atual.distancia + graph[atual.estado][i]);
            }
        }
    }
}

int main() {
    int estadoInicial;
    printf("Digite o estado inicial (0 para A, 1 para B, 2 para C): ");
    scanf("%d", &estadoInicial);

    if (estadoInicial < 0 || estadoInicial >= NUM_STATES) {
        printf("Estado inicial inválido.\n");
    } else {
        printf("Busca em profundidade com o estado inicial %c\n", 'A' + estadoInicial);
        buscaLargura(estadoInicial);
    }

    return 0;
}
