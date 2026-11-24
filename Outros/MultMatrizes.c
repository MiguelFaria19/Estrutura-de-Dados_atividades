#include <stdio.h>

int main(void) {
    /* A e 2x3; B e 3x2; resultado sera 2x2. */
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("Matriz produto A x B:\\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d\\t", C[i][j]);
        printf("\\n");
    }

    return 0;
}
