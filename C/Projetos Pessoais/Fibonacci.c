/*
Autor: Arthur Almeida Pereira
Data: 17/10/2025
Objetivo: Sequencia de Fibonacci
*/

#include <stdio.h>

int main (){

    int pos;
    int x = 1;
    int y = 1;
    int i;


    printf("Digite a posicao do fibonacci.: ");
    scanf("%d", &pos);

    for(i = 0; i < pos - 2; i++) {
        y += x;
        x = y - x;
    }

    printf("%d\n", y);

}