/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Escreva um programa que leia um vetor de 15 números inteiros e mostre o maior e
o menor elemento do vetor, bem como suas respectivas posições. 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int numInteiro[15];
    int maior = 0;
    int menor = 999;
    int posMaior;
    int posMenor;

    // Processamento
    printf("Digite 15 numeros inteiros.\n");

    for ( i = 0; i < 15; i++ ) {
        printf("Digite o valor [%d].: \n", i);
        scanf("%d", &numInteiro[i]);
        
        if ( numInteiro[i] > maior ) {
            maior = numInteiro[i];
            posMaior = i;
        }

        if ( numInteiro[i] < menor ) {
            menor = numInteiro[i];
            posMenor = i;
        }


        
    }

    // Saida
    printf("O maior numero e [%d] %d e o menor numero e [%d] %d", posMaior, maior, posMenor, menor);
}