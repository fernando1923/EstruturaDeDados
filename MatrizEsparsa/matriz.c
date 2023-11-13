// matriz.c

#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(Matriz A) {
    for (int i = 0; i < A.m; i++) {
        for (int j = 0; j < A.n; j++) {
            printf("%lf\t", A.elementos[i][j]);
        }
        printf("\n");
    }
}

Matriz leMatriz() {
    Matriz A;
    FILE *arquivo;
    int i, j, m, n;
    double valor;

    // Abre o arquivo de entrada
    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Lê as dimensões da matriz
    fscanf(arquivo, "%d", &m);
    fscanf(arquivo, "%d", &n);

    // Aloca a matriz
    A.m = m;
    A.n = n;
    A.elementos = (double **)malloc(m * sizeof(double *));
    for (i = 0; i < m; i++) {
        A.elementos[i] = (double *)malloc(n * sizeof(double));
    }

    // Inicializa a matriz com zeros
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A.elementos[i][j] = 0.0;
        }
    }

    // Lê as tuplas e atribui os valores à matriz
    while (fscanf(arquivo, "%d, %d, %lf", &i, &j, &valor) == 3) {
        A.elementos[i - 1][j - 1] = valor;
    }

    // Fecha o arquivo
    fclose(arquivo);

    return A;
}

void liberaMatriz(Matriz A) {
    for (int i = 0; i < A.m; i++) {
        free(A.elementos[i]);
    }
    free(A.elementos);
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz C;
    if (A.m != B.m || A.n != B.n) {
        fprintf(stderr, "Erro: As matrizes não têm as mesmas dimensões para a soma.\n");
        exit(EXIT_FAILURE);
    }

    C.m = A.m;
    C.n = A.n;

    // Aloca a matriz resultado
    C.elementos = (double **)malloc(C.m * sizeof(double *));
    for (int i = 0; i < C.m; i++) {
        C.elementos[i] = (double *)malloc(C.n * sizeof(double));
    }

    // Soma os elementos das matrizes A e B
    for (int i = 0; i < C.m; i++) {
        for (int j = 0; j < C.n; j++) {
            C.elementos[i][j] = A.elementos[i][j] + B.elementos[i][j];
        }
    }

    return C;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    Matriz C;
    if (A.n != B.m) {
        fprintf(stderr, "Erro: O número de colunas de A não é igual ao número de linhas de B para a multiplicação.\n");
        exit(EXIT_FAILURE);
    }

    C.m = A.m;
    C.n = B.n;

    // Aloca a matriz resultado
    C.elementos = (double **)malloc(C.m * sizeof(double *));
    for (int i = 0; i < C.m; i++) {
        C.elementos[i] = (double *)malloc(C.n * sizeof(double));
    }

    // Inicializa a matriz resultado com zeros
    for (int i = 0; i < C.m; i++) {
        for (int j = 0; j < C.n; j++) {
            C.elementos[i][j] = 0.0;
        }
    }

    // Multiplica as matrizes A e B
    for (int i = 0; i < A.m; i++) {
        for (int j = 0; j < B.n; j++) {
            for (int k = 0; k < A.n; k++) {
                C.elementos[i][j] += A.elementos[i][k] * B.elementos[k][j];
            }
        }
    }

    return C;
}
