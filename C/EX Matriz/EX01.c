/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Crie um algoritmo que leia uma matriz 3x3 de números inteiros e calcule a
soma de todos os seus elementos.
*/

#include <stdio.h>

int main (){

    // Variaveis
    int i;
    int c;
    int numInt[3][3];
    int soma = 0;

    // Processamento

    for ( i = 0; i < 3; i++ ) {
        for ( c = 0; c < 3; c++) {           
            printf("Digite o valor.: ");
            scanf("%d", &numInt[i][c]);
            soma = soma + numInt[i][c];
        }
    }

    // Saida
    printf("A soma da matriz e.: %d", soma);
}