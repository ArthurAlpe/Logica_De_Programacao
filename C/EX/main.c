/*
Autor: Arthur Almeida Pereira
Data: 04/11/2025
Objetivo: Soma de elementos de um vetor
*/

#include <stdio.h>
#include <windows.h>

int main(){

    // Variaveis

    int i;
    int num[5];
    int soma = 0;

    // Entrada

    for ( i = 0; i < 5; i++ ) {
        printf("Digite o numero para somar.: ");
        scanf("%d", &num[i]);

        soma = soma + num[i];
    }

    // Saida

    printf("\n\n");
    printf("A soma do vetor e %d", soma);

    return 0;
}