/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Escreva um programa que leia um vetor de 10 números inteiros e um número
inteiro n e mostre quantas vezes o número n aparece no vetor. 
*/

#include <stdio.h>

int main(){
    
    // Variaveis
    int i;
    int n;
    int vet[10];
    int contador = 0;

    // Entrada

    printf("Digite um valor para saber quantas vezes ele vai aparecer no vetor.: ");
    scanf("%d", &n);
    printf("\n");

    // Processamento

    for ( i = 0; i < 10; i++ ) {
        printf("Digite o valor.: ");
        scanf("%d", &vet[i]);
        
        if (vet[i] == n) {
            contador++;
        }

    }

    for ( i = 0; i < 10; i++) {
        printf("%d \t", vet[i]);
    }

    printf("\n\n");
    printf("O numero %d apareceu %d vezes", n, contador);

}