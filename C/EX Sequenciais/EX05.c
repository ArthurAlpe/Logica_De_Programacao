/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 26/09/2025
Objetivo: Calcular e escrever as médias aritmética e harmônica
*******************************************************************************/
#include <stdio.h>

int main() {
    
    //Variaveis
    float A, B, C;
    float mediaAritmetica, mediaHarmonica;

    //Entrada de dados
    printf("Digite o valor de A: ");
    scanf("%f", &A);

    printf("Digite o valor de B: ");
    scanf("%f", &B);

    printf("Digite o valor de C: ");
    scanf("%f", &C);

    //Média Aritmética
    mediaAritmetica = (A + B + C) / 3.0;

    //Média Harmônica
    mediaHarmonica = 3.0 / ((1.0 / A) + (1.0 / B) + (1.0 / C));

    //Saída
    printf("\nMedia Aritmetica = %.2f", mediaAritmetica);
    printf("\n");
    printf("Media Harmonica  = %.2f", mediaHarmonica);

    return 0;
}