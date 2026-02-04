/*
Autor: Arthur Almeida Pereira
Data: 17/10/2025
Objetivo:
*/
#include "stdio.h"

int main()
{

    float salario[10];
    char cargo[20][10];

    for(int i = 0; i < 10; i++)
    {

        printf("\nCargo %d: ", i + 1);
        fflush(stdin);
        fgets(cargo[i], 20, stdin);

        printf("\nSalario %d: ", i + 1);
        scanf("%f", &salario[i]);

    }


    printf("\n");

    for(int i = 0; i < 10; i++)
    {

        printf("\nCargo: %s", cargo[i]);

        printf("\nSalario: %.2f\n", salario[i]);


    }

}