/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 07/10/2025
Objetivo: Elaborar um programa que efetue a leitura de 15 valores numericos inteiros
e no final apresente o total do somatario da fatorial de cada valor lido
*******************************************************************************/

#include <stdio.h>

int main()
{
    //Variaveis
    int num;
    int soma = 0;
    int I;
    
    for (I = 1; I <= 15; I++) {
        printf("Digite o numero: ");
        scanf("%d", &num);
        
        soma = soma + num;
    
    }
    
    printf("A soma e %d", soma);
    
    
    

    return 0;
}