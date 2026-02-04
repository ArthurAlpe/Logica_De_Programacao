/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 08/10/2025
Objetivo: Faça um programa que lê o nome de um funcionário, as horas por ele 
trabalhadas e seu salário/hora. O programa deverá informar o salário final do 
funcionário, considerando 50% de acréscimo para horas extras. Considere como 
padrão 40 horas semanais.
*******************************************************************************/
#include <stdio.h>

int main()
{
    char nome[40];
    int horasTrabalhada;
    float salarioHora;
    float salarioFinal;
    int horasExtras;
    
    printf("Digite seu nome.............: ");
    fflush(stdin);
    fgets(nome, 40, stdin);
    
    printf("Digite sua horas trabalhadas: ");
    scanf("%d", &horasTrabalhada);
    
    printf("Digite seu salario por hora.: ");
    scanf("%f", &salarioHora);
    
    if (horasTrabalhada > 40) {
        horasExtras = horasTrabalhada - 40;
        salarioFinal = (40 * salarioHora) + (horasExtras * salarioHora * 1.5);
        printf("Seu nome e %s voce trabalhou %d e seu salario e %.2f", nome, horasTrabalhada, salarioFinal);
    } else if (horasTrabalhada < 40) {
        salarioFinal = horasTrabalhada * salarioHora;
        printf("Seu nome e %s voce trabalhou %d e seu salario e %.2f", nome, horasTrabalhada, salarioFinal);
    }

    return 0;
}
