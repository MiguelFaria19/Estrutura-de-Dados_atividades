#include <stdio.h>

void inverterLista(int lista[], int tamanho) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio < fim) {
        int temp = lista[inicio];
        lista[inicio] = lista[fim];
        lista[fim] = temp;
        inicio++;
        fim--;
    }
}

int main(void) {
    int lista[] = {10, 20, 30, 40, 50, 60};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Vetor original: ");
    for (int i = 0; i < tamanho; i++) printf("%d ", lista[i]);

    inverterLista(lista, tamanho);

    printf("\\nVetor invertido: ");
    for (int i = 0; i < tamanho; i++) printf("%d ", lista[i]);
    printf("\\n");

    return 0;
}
