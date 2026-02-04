/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 14/10/2025
Objetivo: Apresentar os resultados de uma tabuada de um número qualquer.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int I;
    int Num;
    int Num1;
    int Num2;
    
    printf("Digite um numero: ");
    scanf("%d", &Num);
    
    printf("Digite o valor inicial: ");
    scanf("%d", &Num1);
    
    printf("Digite o valor final: ");
    scanf("%d", &Num2);
    
    for (I = Num1; I <= Num2; I++) {
        printf("%d x %d = %d \n", Num, I, Num * I);
    }   if (I = Num1 >= Num2) {
        printf("Nao pode dar o valor final maior que o numero inical");
    }
    
    return 0;
}