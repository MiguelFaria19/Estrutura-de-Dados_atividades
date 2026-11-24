#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No *inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

void liberar(No *raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esquerda);
    liberar(raiz->direita);
    free(raiz);
}

int main(void) {
    No *raiz = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int quantidade = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < quantidade; i++)
        raiz = inserir(raiz, valores[i]);

    printf("Valores fixos inseridos: 50, 30, 70, 20, 40, 60, 80\n");
    printf("Percurso em ordem: ");
    emOrdem(raiz);
    printf("\n");

    liberar(raiz);
    return 0;
}
