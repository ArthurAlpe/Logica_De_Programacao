/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 26/09/2025
Objetivo: um algoritmo que leia o custo de fábrica de um carro e escreva o custo
ao consumidor.
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    float distribuidor;
    float impostos;
    float fabrica;
    float consumidor;
    char nome_carro[20];
    
    //Terminal esperar o usuario
    printf("Digite o nome do carro...:");
    fflush(stdin);
    fgets(nome_carro, 20, stdin);
    printf("Digite o valor de fabrica do carro...:");
    scanf("%f", &fabrica);
    
    //Variaveis de calculo final
    distribuidor = fabrica * 0.28;
    impostos = fabrica * 0.45;
    consumidor = fabrica + distribuidor + impostos;
    printf("O custo para o consumidor do carro e %.2f", consumidor);

    return 0;
}
