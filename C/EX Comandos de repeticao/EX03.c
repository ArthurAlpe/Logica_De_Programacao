/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 15/10/2025
Objetivo: Elaborar um programa que apresente no final o somatório dos valores 
pares existentes na faixa de 1 até 500.
*******************************************************************************/

#include <stdio.h>

int main()
{
    //Variaveis
    int soma = 0;
    int I;
    
    //Comeco do programa
    printf("O somatorio dos valores pares existentes na faixa de 1 ate 500\n\n");
    
    //Dados a serem somados
    for(I = 1; I <= 500; I++) {
        
        if (I % 2 == 0) {
        soma = I + soma;
        }
    }
    
    //Saida
    printf("O somatorio total de pares e: %d", soma);
    return 0;
}