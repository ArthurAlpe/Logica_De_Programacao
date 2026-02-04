/******************************************************************************
Autor.....: Arthur Almeida Pereira
Data......: 12/09/2025
Objetivo..: Exercicios de programção em Linguagem C

*******************************************************************************/
#include <stdio.h>

int main()
{
    int resultado1 = 300 / 45;
    int resultado2 = 300 % 45;
    int resultado3 = 400 / 45;
    int resultado4 = 400 % 45;
    int resultado5 = 500 / 45;
    int resultado6 = 500 % 45;
    
    printf("Tabua de 3 metros, ele vai ter %d pedacos e %d cm em sobras\n", resultado1, resultado2);
    printf("Ja com a tabua de 4 metros, ele vai ter %d pedacos e %d cm em sobras\n", resultado3, resultado4);
    printf("E com tabua de 5 metros, ele vai ter %d pedacos e %d cm em sobras\n", resultado5, resultado6);
    return 0;
}
