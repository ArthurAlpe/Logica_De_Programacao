/*
Autor: Arthur Almeida Pereira
Data: 22/10/2025
Objetivo: Escreva um programa que leia um vetor de 10 números reais e calcule e mostre a
média aritmética dos elementos do vetor. 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    float numReal[10];
    float media = 0;
    float soma = 0;

    // Processamento
    printf("Digite 10 numeros reais para saber a media aritmetica deles.: \n");

    for ( i = 0; i < 10; i++) {
        scanf("%f", &numReal[i]);
        soma = soma + numReal[i];
    }

    media = soma / 10;

    // Saida
    printf("A media aritmetica dos elementos do vetor e.: %.2f", media);
}