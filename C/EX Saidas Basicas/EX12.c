/******************************************************************************
Autor.....: Arthur Almeida Pereira
Data......: 12/09/2025
Objetivo..: Exercicios de programção em Linguagem C
*******************************************************************************/
#include <stdio.h>

int main()
{
    float nota1 = 8.5;
    float nota2 = 5.5;
    float nota3 = 7;
    float nota4 = 6.75;
    float nota5 = (nota1 + nota2 + nota3 + nota4) / 4;
    
    printf("+---------------------------------------------------------+\n");
    printf("|                     NOTAS DO ALUNO                      |\n");
    printf("|                                                         |\n");
    printf("|  %f + %f + %f + %f = %f                                 |\n", nota1, nota2, nota3, nota4, nota5);
    printf("|                                                         |\n");
    printf("|               MEDIA FINAL DO ALUNO: 6.93                |\n");
    printf("+---------------------------------------------------------+\n");
    

    return 0;
}
