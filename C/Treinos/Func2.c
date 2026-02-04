/*
Autor: Arthur Almeida Pereira
Data: 06/11/2025
Objetivo: Faça uma funcao que recebe, por parametro, um valor inteiro e positivo
e retorna ZERO se for par e 1 para valores impares
*/

#include <stdio.h>

// Funcao para saber se e par ou impar
void parImpar(int n){
    if ( n % 2 == 0 ) {
        printf("0\n");
    } else {
        printf("1\n");
    }
}

// Funcao principal
int main(){

    // Variaveis
    int numero;

    // Entrada

    printf("Digite um numero.: ");
    scanf("%d", &numero);
    parImpar(numero);
}