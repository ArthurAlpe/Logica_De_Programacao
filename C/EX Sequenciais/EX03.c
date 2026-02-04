/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 26/09/2025
Objetivo: programa que leia a idade de uma pessoa expressa em anos, meses e dias
e mostre-a expressa apenas em dias
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int anos;
    int meses;
    int dias;
    
    //Terminal esperando o usuario
    printf("Digite quantos anos voce tem...:");
    scanf("%d", &anos);
    
    printf("Digite o mes...:");
    scanf("%d", &meses);
    
    printf("Digite o dia...:");
    scanf("%d", &dias);
    
    //Variavel para o calculo final
    int total_dias = (anos * 365) + (meses * 30) + dias;
    printf("Sua idade em dias e %d\n", total_dias);

    return 0;
}