/*
Autor: Arthur Almeida Pereira
Data: 23/10/2025
Objetivo: Crie um algoritmo que leia uma matriz quadrada de 4 linhas e 4 colunas e
calcule a soma dos elementos da diagonal principal e da diagonal secundária. 
*/

#include <stdio.h>

int main() {

    // Variaveis
    int i;
    int c;
    int matriz[4][4];
    int soma1 = 0;
    int soma2 = 0;

    // Entrada

    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("Digite o valor[%d][%d]: ", i, c);
            scanf("%d", &matriz[i][c]);

            if ( i == c ) {
                soma1 = soma1 + matriz[i][c];
            }
            if ( i + c == 3) {
                soma2 = soma2 + matriz[i][c];
            }
        
        }
    }

    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("%d \t", matriz[i][c]);
        }
        printf("\n");
    }

    printf("A soma da diagonal principal e.: %d\n", soma1);
    printf("E a soma da diagonal secundaria e.: %d", soma2);
}