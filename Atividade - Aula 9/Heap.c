#include <stdio.h>

#define MAX 100

typedef struct {
    int chave;
} Elemento;

void subir(Elemento T[], int i) {
    int j = i / 2;

    if (j >= 1) {
        if (T[i].chave > T[j].chave) {
            Elemento temp = T[i];
            T[i] = T[j];
            T[j] = temp;

            subir(T, j);
        }
    }
}

void descer(Elemento T[], int i, int n) {
    int j = 2 * i;

    while (j <= n) {
        if (j < n && T[j + 1].chave > T[j].chave) {
            j = j + 1;
        }

        if (T[i].chave < T[j].chave) {
            Elemento temp = T[i];
            T[i] = T[j];
            T[j] = temp;

            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

void mostrar(Elemento T[], int n) {
    int i;

    for (i = 1; i <= n; i++) {
        printf("%d ", T[i].chave);
    }

    printf("\n");
}

int main() {
    Elemento T[MAX];
    int n = 9;
    int i, pos, novaPrioridade;

    int valores[] = {0, 92, 85, 90, 47, 31, 34, 20, 40, 46};

    for (i = 1; i <= n; i++) {
        T[i].chave = valores[i];
    }

    printf("HEAP inicial: ");
    mostrar(T, n);

    printf("\nDigite a posicao que deseja alterar: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Posicao invalida!\n");
        return 1;
    }

    printf("Digite a nova prioridade: ");
    scanf("%d", &novaPrioridade);

    if (novaPrioridade > T[pos].chave) {
        T[pos].chave = novaPrioridade;
        subir(T, pos);
    } else if (novaPrioridade < T[pos].chave) {
        T[pos].chave = novaPrioridade;
        descer(T, pos, n);
    }

    printf("\nHEAP resultante: ");
    mostrar(T, n);

    return 0;
}
