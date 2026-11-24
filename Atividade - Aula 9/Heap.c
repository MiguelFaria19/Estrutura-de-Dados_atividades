#include <stdio.h>

#define MAX 20

typedef struct {
    int valores[MAX + 1]; /* Heap usa indices de 1 ate tamanho. */
    int tamanho;
} Heap;

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void subir(Heap *h, int i) {
    while (i > 1 && h->valores[i] > h->valores[i / 2]) {
        trocar(&h->valores[i], &h->valores[i / 2]);
        i = i / 2;
    }
}

void descer(Heap *h, int i) {
    int filho;
    while (2 * i <= h->tamanho) {
        filho = 2 * i;

        if (filho + 1 <= h->tamanho &&
            h->valores[filho + 1] > h->valores[filho])
            filho++;

        if (h->valores[i] >= h->valores[filho]) break;

        trocar(&h->valores[i], &h->valores[filho]);
        i = filho;
    }
}

void inserir(Heap *h, int valor) {
    if (h->tamanho == MAX) return;
    h->valores[++h->tamanho] = valor;
    subir(h, h->tamanho);
}

void exibir(Heap *h) {
    printf("Heap: ");
    for (int i = 1; i <= h->tamanho; i++)
        printf("%d ", h->valores[i]);
    printf("\n");
}

int removerMaior(Heap *h) {
    if (h->tamanho == 0) return -1;
    int maior = h->valores[1];
    h->valores[1] = h->valores[h->tamanho--];
    if (h->tamanho > 0) descer(h, 1);
    return maior;
}

int main(void) {
    Heap heap = {{0}, 0};

    inserir(&heap, 40);
    inserir(&heap, 15);
    inserir(&heap, 30);
    inserir(&heap, 10);
    inserir(&heap, 50);
    inserir(&heap, 20);

    printf("Heap depois das insercoes fixas:\n");
    exibir(&heap);

    printf("Maior elemento removido: %d\n", removerMaior(&heap));

    printf("Heap depois da remocao:\n");
    exibir(&heap);

    return 0;
}
