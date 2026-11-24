#include <stdio.h>

#define TAMANHO 5

typedef struct {
    int dados[TAMANHO];
    int topo;
} Pilha;

void inicializar(Pilha *p) { p->topo = -1; }
int estaVazia(Pilha *p) { return p->topo == -1; }
int estaCheia(Pilha *p) { return p->topo == TAMANHO - 1; }

void push(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia: nao foi possivel inserir %d.\n", valor);
        return;
    }
    p->dados[++p->topo] = valor;
    printf("Inserido: %d\n", valor);
}

void pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia: nada para remover.\n");
        return;
    }
    printf("Removido: %d\n", p->dados[p->topo--]);
}

void exibir(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Topo -> ");
    for (int i = p->topo; i >= 0; i--) printf("%d ", p->dados[i]);
    printf("\n");
}

int main(void) {
    Pilha pilha;
    inicializar(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    push(&pilha, 40);

    printf("\nPilha atual:\n");
    exibir(&pilha);

    printf("\nRemovendo um elemento:\n");
    pop(&pilha);
    exibir(&pilha);

    printf("Esta vazia? %s\n", estaVazia(&pilha) ? "Sim" : "Nao");
    printf("Esta cheia? %s\n", estaCheia(&pilha) ? "Sim" : "Nao");

    return 0;
}
