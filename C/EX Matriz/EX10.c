/*
Autor: Arthur Almeida Pereira
Data: 27/10/2025
Objetivo: Soma de Matrizes
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int c;
    int matriz1[3][3];
    int matriz2[3][3];
    int matriz3[3][3];

    // Processamento

    printf("Valores da Matriz 1:\n");

    for ( i = 0; i < 3; i++ ) {
        for ( c = 0; c < 3; c++ ) {
            printf("Digite o valor[%d][%d]: ", i, c);
            scanf("%d", &matriz1[i][c]);
        }
    }

    printf("\n");
    printf("+------------------+\n");
    printf("Valores da Matriz 2:\n");

    for ( i = 0; i < 3; i++ ) {
        for ( c = 0; c < 3; c++ ) {
            printf("Digite o valor[%d][%d]: ", i, c);
            scanf("%d", &matriz2[i][c]);
        }
    }

    for ( i = 0; i < 3; i++ ) {
        for ( c = 0; c < 3; c++ ) {
            matriz3[i][c] = matriz1[i][c] + matriz2[i][c];
        }
    }
    
    printf("\n");
    printf("+---------------------------+\n");
    printf("A soma das matrizes 1 e 2 e.: \n");

    for ( i = 0; i < 3; i++ ) {
        for ( c = 0; c < 3; c++ ) {
            printf("%d \t", matriz3[i][c]);
        }
        printf("\n");
    }
}