// main.c
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main() {
    // Exemplo de uso das funções
    Matriz A = leMatriz();
    Matriz B = leMatriz();

    printf("Matriz A:\n");
    imprimeMatriz(A);

    printf("\nMatriz B:\n");
    imprimeMatriz(B);

    // Soma das matrizes A e B
    Matriz C_soma = somaMatrizes(A, B);
    printf("\nSoma de A e B:\n");
    imprimeMatriz(C_soma);

    // Multiplicação das matrizes A e B
    Matriz C_multiplicacao = multiplicaMatrizes(A, B);
    printf("\nMultiplicação de A e B:\n");
    imprimeMatriz(C_multiplicacao);

    // Liberar memória alocada para as matrizes
    liberaMatriz(A);
    liberaMatriz(B);
    liberaMatriz(C_soma);
    liberaMatriz(C_multiplicacao);

    return 0;
}
