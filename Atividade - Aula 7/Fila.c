#include <stdio.h>

#define TAMANHO 5

typedef struct {
    int dados[TAMANHO];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

int estaVazia(Fila *f) { return f->quantidade == 0; }
int estaCheia(Fila *f) { return f->quantidade == TAMANHO; }

void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia: nao foi possivel inserir %d.\n", valor);
        return;
    }
    f->fim = (f->fim + 1) % TAMANHO;
    f->dados[f->fim] = valor;
    f->quantidade++;
    printf("Inserido: %d\n", valor);
}

void desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia: nada para remover.\n");
        return;
    }
    printf("Removido: %d\n", f->dados[f->inicio]);
    f->inicio = (f->inicio + 1) % TAMANHO;
    f->quantidade--;
}

void exibir(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Frente -> ");
    for (int i = 0; i < f->quantidade; i++)
        printf("%d ", f->dados[(f->inicio + i) % TAMANHO]);
    printf("<- Retaguarda\n");
}

int main(void) {
    Fila fila;
    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    exibir(&fila);

    printf("\nRemovendo um elemento:\n");
    desenfileirar(&fila);
    exibir(&fila);

    printf("\nInserindo outro elemento:\n");
    enfileirar(&fila, 40);
    exibir(&fila);

    printf("Esta vazia? %s\n", estaVazia(&fila) ? "Sim" : "Nao");
    printf("Esta cheia? %s\n", estaCheia(&fila) ? "Sim" : "Nao");

    return 0;
}
