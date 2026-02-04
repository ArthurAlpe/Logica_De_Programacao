/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Crie um algoritmo que leia uma matriz 2x3 de números reais e gere a matriz
transposta (3x2). Exiba ambas as matrizes.
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int c;
    int numReal[2][3];

    // Processamento
    for ( i = 0; i < 2; i++ ) {
        for ( c = 0; c < 3; c++ ) {
            printf("Digite o valor.: ");
            scanf("%d", &numReal[i][c]);
        }
    }

    printf("\n");
    printf("A matriz original e.: \n");

    for ( i = 0; i < 2; i++ ) {
        for ( c = 0; c < 3; c++ ) {
            printf("%d \t", numReal[i][c]);
        }
        printf("\n");
        
    }

    printf("\n");
    printf("A matriz transposta e.: \n");

    for ( c = 0; c < 3; c++ ) {
        for ( i = 0; i < 2; i++ ) {
            printf("%d \t", numReal[i][c]);
        }
        printf("\n");
        
    }
}