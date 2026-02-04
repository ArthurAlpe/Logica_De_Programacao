/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 08/10/2025
Objetivo: Faça um programa que determina o menor entre três valores inteiros lidos.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int I;
    
    printf("Para saber o menor numero inteiro entre os 3 que voce digitar!");
    
    printf("\n");
    
    printf("Digite um numero: ");
    scanf("%d", &num1);
    
    printf("Digite outro numero: ");
    scanf("%d", &num2);
    
    printf("Digite outro numero: ");
    scanf("%d", &num3);
    
    if ((num1 <= num2) && (num1 <= num3)) {
        printf("O %d e o menor entre %d, %d e %d\n", num1, num1, num2, num3);
    } else if ((num2 <= num1) && (num2 <= num3)) {
        printf("O %d e o menor entre %d, %d e %d\n", num2, num1, num2, num3); 
    } else {
        printf("O %d e o menor entre %d, %d e %d\n", num3, num1, num2, num3);
    }
    return 0;
}
