/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 15/10/2025
Objetivo: Apresentar as potências de 3 variando de 0 a 15. Deve ser considerado
que qualquer número elevado a zero é 1, e elevado a 1 é ele próprio.
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int I;
    int potencia = 1;
    
    //Saida do programa
    for(I = 0; I <= 15; I++) {
        
        printf("3 elevado a %d = %d\n", I, potencia);
        
        potencia = potencia * 3;
    }

    return 0;
}