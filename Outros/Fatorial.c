#include <stdio.h>

int fatorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorial(n - 1);
}

int main(void) {
    int numero = 5;

    printf("Numero: %d\\n", numero);
    printf("Fatorial de %d = %d\\n", numero, fatorial(numero));

    return 0;
}
