/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 07/10/2025
Objetivo: Elaborar a leitura de um número inteiro e apresentar uma mensagem 
informando se o número é par ou impar. 
*******************************************************************************/
#include <stdio.h>

int main()
{
    int num1;
    int soma = 0;
    int qtd = 0;
    
    printf("Digite um numero para saber se e par ou impar: ");
    scanf("%d", &num1);
    
    if (num1 % 2 == 0) {
        soma += num1;
        qtd ++;
        printf("%d e par", num1);
    } else {
        printf("%d e impar", num1);
    }

    return 0;
}
