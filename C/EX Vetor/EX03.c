/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Escreva um programa que leia dois vetores de 5 números inteiros cada e mostre a
soma dos elementos correspondentes de cada vetor. 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int o;
    int vet1[5];
    int soma1 = 0;
    int vet2[5];
    int soma2 = 0;

    // Processamento
    printf("Digite 5 numeros inteiros para o programa somar os elementos de 2 vetores.: \n");

    for ( i = 0; i < 5; i++ ) {
        printf("Digite o valor.: ");
        scanf("%d", &vet1[i]);
        soma1 = soma1 + vet1[i];
    }
    
    printf("\n");

    for ( o = 0; o < 5; o++ ) {
        printf("Digite o valor.: ");
        scanf("%d", &vet2[o]);
        soma2 = soma2 + vet2[o];
    }

    printf("A soma do primeiro vetor e.: %d\n", soma1);
    printf("A soma do primeiro vetor e.: %d", soma2);
}