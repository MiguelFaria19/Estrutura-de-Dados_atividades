#include <stdio.h>
#include <stdlib.h>

int pilhaVazia(int topo) {
    return topo == -1;
}

int pilhaCheia(int topo, int capacidade) {
    return topo == capacidade - 1;
}

void inserir(int pilha[], int *topo, int capacidade, int valor) {
    if (pilhaCheia(*topo, capacidade)) {
        printf("pilha esta cheia \n");
        return;
    }

    (*topo)++;
    pilha[*topo] = valor;
    printf("elemento inserido\n");
}

int remover(int pilha[], int *topo, int *valorRemovido) {
    if (pilhaVazia(*topo)) {
        printf("pilha esta vazia\n");
        return 0;
    }

    *valorRemovido = pilha[*topo];
    (*topo)--;
    return 1;
}

void mostrarPilha(int pilha[], int topo) {
    int i;

    if (pilhaVazia(topo)) {
        printf("pilha vazia\n");
        return;
    }

    printf("elementos da pilha (topo para a base): ");
    for (i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    int capacidade;
    int topo = -1;
    int valor;
    int removido;
    int i;
    int *pilha;

    printf("tamanho maximo da pilha: ");
    if (scanf("%d", &capacidade) != 1 || capacidade < 1) {
        printf("Informe um tamanho valido\n");
        return 1;
    }

    pilha = malloc(capacidade * sizeof(int));
    if (pilha == NULL) {
        printf("erro ao alocar memoria\n");
        return 1;
    }

    printf("\ndigite %d elementos para a pilha:\n", capacidade - 1);
    for (i = 0; i < capacidade - 1; i++) {
        printf("elemento %d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
            printf("valor invalido.\n");
            free(pilha);
            return 1;
        }
        inserir(pilha, &topo, capacidade, valor);
    }

    printf("\n-- PILHA INICIAL --\n");
    mostrarPilha(pilha, topo);

    if (pilhaVazia(topo)) {
        printf("pilha esta vazia.\n");
    } else {
        printf("pilha nao esta vazia.\n");
    }

    if (pilhaCheia(topo, capacidade)) {
        printf("pilha esta cheia\n");
    } else {
        printf("pilha nao esta cheia\n");
    }

    printf("\nvalor para inserir na pilha: ");
    if (scanf("%d", &valor) != 1) {
        printf("valor invalido.\n");
        free(pilha);
        return 1;
    }

    inserir(pilha, &topo, capacidade, valor);

    printf("\n-- PILHA APOS A INSERCAO --\n");
    mostrarPilha(pilha, topo);

    if (pilhaCheia(topo, capacidade)) {
        printf("pilha esta cheia.\n");
    } else {
        printf("pilha n esta cheia.\n");
    }

    printf("\n-- REMOCAO DE ELEMENTO --\n");
    if (remover(pilha, &topo, &removido)) {
        printf("elemento removido: %d\n", removido);
    }

    printf("\n-- PILHA APOS A REMOCAO --\n");
    mostrarPilha(pilha, topo);

    if (pilhaVazia(topo)) {
        printf("pilha esta vazia\n");
    } else {
        printf("pilha n esta vazia\n");
    }

    if (pilhaCheia(topo, capacidade)) {
        printf("pilha esta cheia.\n");
    } else {
        printf("pilha n esta cheia.\n");
    }

    free(pilha);
    return 0;
}
