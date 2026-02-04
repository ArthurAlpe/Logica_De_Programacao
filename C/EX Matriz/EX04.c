/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Ler uma matriz 10 X 10 com números inteiros, executar as trocas especificadas
e mostrar a matriz resultante.
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i; // Linha
    int c; // Coluna
    int x; // Troca da linha 5 com a coluna 10
    int numInt[10][10];
    int resultado = 0;

    // Processamento

    for ( i = 0; i < 10; i++ ) {
        for ( c = 0; c < 10; c++ ) {
            printf("Digite o valor [%d][%d].: ", i, c);
            scanf("%d", &numInt[i][c]);
        }
    }

    for ( i = 0; i < 10; i++ ) {
        for ( c = 0; c < 10; c++ ) {
            if ( i == 1 ) {
                resultado = numInt[i][c];  // Troca da linha 2 com linha 8
                numInt[i][c] = numInt[7][c];
                numInt[7][c] = resultado;
            }

        }

    }
    
    for ( i = 0; i < 10; i++ ) {
        for ( c = 0; c < 10; c++ ) {

            if ( c == 3 ) {
                resultado = numInt[i][c]; // Troca da coluna 4 com coluna 10
                numInt[i][c] = numInt[i][9];
                numInt[i][9] = resultado;   

            }

        }

    }
    
    for (x = 0; x < 10; x++) {
        resultado = numInt[4][x]; // Troca da linha 5 com a coluna 10
        numInt[4][x] = numInt[x][9];
        numInt[x][9] = resultado;
    }        

    for ( i = 0; i < 10; i++ ) {
        for ( c = 0; c < 10; c++ ) {
            printf("%d \t", numInt[i][c]);
        }
        printf("\n");
    }
}