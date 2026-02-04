/******************************************************************************
Autor.....: Arthur Almeida Pereira
Data......: 12/09/2025
Objetivo..: Exercicios de programção em Linguagem C
*******************************************************************************/
#include <stdio.h>

int main()
{
    int resultado1 = 37 % 13;
    int resultado2 = 41 / 7;
    int resultado3 = (11 / 3) % 2;
    int resultado4 = (11 % 3) / 2;
    
    
    printf("37 mod 13      = %d\n", resultado1);
    printf("41 div 7       = %d\n", resultado2);
    printf("11 div 3 mod 2 = %d\n", resultado3);
    printf("11 mod 3 div 2 = %d\n", resultado4);

    return 0;
}
