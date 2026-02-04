/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 07/10/2025
Objetivo: Determinar num conjunto de 3 números o menor deles, imprimindo-o e 
também o maior deles. 
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int num1;
    int num2;
    int num3;

    //Entrada de dados
    printf("Digite o primeiro numero:");
    scanf("%d", &num1);
    printf("\n");
    printf("Digite o segundo numero.:");
    scanf("%d", &num2);
    printf("\n");
    printf("Digite o terceiro numero:");
    scanf("%d", &num3);
    printf("\n");
    
    //Saida dos dados
    if (num1 < num2 && num1 < num3) {
        printf("O menor numero é o numero: %d", num1);
    } else if (num2 < num1 && num2 < num3) {
        printf("O menor numero é o numero: %d", num2);
    } else {
        printf("O menor numero é o numero: %d", num3);
    } 
    printf("\n\n");

    if (num1 > num2 && num1 > num3) {
        printf("O maior numero é o numero: %d", num1);
    } else if (num2 > num1 && num2 > num3) {
        printf("O maior numero é o numero: %d", num2);
    } else {
        printf("O maior numero é o numero: %d", num3);
    }

    return 0;
}