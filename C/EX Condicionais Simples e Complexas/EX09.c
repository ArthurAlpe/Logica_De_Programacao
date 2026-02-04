/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 10/10/2025
Objetivo: Dado um número inteiro positivo identificar se o mesmo é par, ímpar, 
múltiplo de 3, múltiplo de 5 ou múltiplo de 7
*******************************************************************************/

#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("O numero deve ser positivo.\n");
        return 0;
    }

    if (numero % 2 == 0)
        printf("%d e par.\n", numero);
    else
        printf("%d e impar.\n", numero);

    if (numero % 3 == 0)
        printf("%d e multiplo de 3.\n", numero);

    if (numero % 5 == 0)
        printf("%d e multiplo de 5.\n", numero);

    if (numero % 7 == 0)
        printf("%d e multiplo de 7.\n", numero);

    return 0;
}