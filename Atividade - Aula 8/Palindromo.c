#include <stdio.h>

#define MAX 100

int main() {
    char palavra[MAX];
    char deque[MAX];
    int inicio = 0, fim = -1;
    int i;
    int palindromo = 1;

    printf("Diga uma palavra: ");
    scanf("%99s", palavra);

    for (i = 0; palavra[i] != '\0'; i++) {
        fim++;
        deque[fim] = palavra[i];
    }

    while (inicio < fim) {
        if (deque[inicio] != deque[fim]) {
            palindromo = 0;
            break;
        }

        inicio++;
        fim--;
    }

    if (palindromo) {
        printf("A palavra e um palindromo!\n");
    } else {
        printf("A palavra nao e um palindromo!\n");
    }

    return 0;
}
