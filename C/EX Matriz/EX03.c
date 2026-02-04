/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo:  Crie um algoritmo que leia duas matrizes 2x2 e calcule a matriz resultante da
multiplicação dessas matrizes. Exiba a matriz resultante.
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int c;
    int matriz1[2][2];
    int matriz2[2][2];
    int matriz3[2][2];

    // Entrada

    for ( i = 0; i < 2; i++ ) {
        for ( c = 0; c < 2; c++ ) {
            printf("Digite o valor da matriz 1.: ");
            scanf("%d", &matriz1[i][c]);
        }
    }

    for ( i = 0; i < 2; i++ ) {
        for ( c = 0; c < 2; c++ ) {
            printf("Digite o valor da matriz 2.: ");
            scanf("%d", &matriz2[i][c]);
        }
    }

    // Saida

    for ( i = 0; i < 2; i++ ) {
        for ( c = 0; c < 2; c++ ) {
                matriz3[i][c] = matriz1[i][c] * matriz2[i][c];
                printf("%d \t", matriz3[i][c]);
        }
        printf("\n");
        
    }
}