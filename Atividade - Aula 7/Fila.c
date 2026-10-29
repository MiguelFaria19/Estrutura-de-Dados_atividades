#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int fila[MAX];
int inicio = 0;
int fim = -1;
int quantidade = 0;

int filaVazia() {
    return quantidade == 0;
}

int filaCheia() {
    return quantidade == MAX;
}

void enfileirar(int valor) {
    if (filaCheia()) {
        printf("\nA fila esta cheia\n");
    } else {
        fim = (fim + 1) % MAX;
        fila[fim] = valor;
        quantidade++;

        printf("\nElemento %d adicionado\n", valor);
    }
}

void desenfileirar() {
    if (filaVazia()) {
        printf("\nA fila esta vazia\n");
    } else {
        printf("\nElemento %d removido\n", fila[inicio]);

        inicio = (inicio + 1) % MAX;
        quantidade--;
    }
}

void mostrarFila() {
    int i;
    int posicao;

    if (filaVazia()) {
        printf("\nA fila esta vazia\n");
    } else {
        printf("\nElementos da fila:\n");

        for (i = 0; i < quantidade; i++) {
            posicao = (inicio + i) % MAX;
            printf("%d ", fila[posicao]);
        }

        printf("\n");
    }
}

int main() {
    int opcao;
    int valor;

    do {
        printf("\n -- MENU DA FILA -- \n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                enfileirar(valor);
                break;

            case 2:
                desenfileirar();
                break;

            case 3:
                mostrarFila();
                break;

            case 4:
                printf("\nEncerrando o programa\n");
                break;

            default:
                printf("\nOpcao invalida\n");
        }

    } while (opcao != 4);

    return 0;
}
