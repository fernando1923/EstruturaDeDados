// matriz.h

#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int m, n; // número de linhas e colunas
    double **elementos; // matriz de elementos
} Matriz;

void imprimeMatriz(Matriz A);
Matriz leMatriz();
void liberaMatriz(Matriz A);
Matriz somaMatrizes(Matriz A, Matriz B);
Matriz multiplicaMatrizes(Matriz A, Matriz B);

#endif // MATRIZ_H
