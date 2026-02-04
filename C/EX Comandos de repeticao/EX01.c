/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 14/10/2025
Objetivo: Apresentar o quadrado dos números inteiros de 15 a 200.
*******************************************************************************/

#include <stdio.h>

int main()
{
    //Variaveis
    
    int I;
    
    for (I = 15; I <= 200; I++) {
        printf("%d x %d = %d", I, I, I * I);
        printf("\n");
    }
    return 0;
}