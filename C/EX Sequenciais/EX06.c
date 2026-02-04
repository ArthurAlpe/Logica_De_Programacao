/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 26/09/2025
Objetivo: Calcular e imprimir o salário bruto a ser recebido por um funcionário em um mês
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    float horas_mes;
    float valor_hora_trabalho;
    int menor;
    
    //Terminal esperando o usuario
    printf("Digite o valor de horas trabalhou no mes...:");
    scanf("%f", &horas_mes);
    
    printf("Digite o valor que recebe por hora de trabalho...:");
    scanf("%f", &valor_hora_trabalho);
    
    printf("Digite o numero de filhos menor do que 14 anos...:");
    scanf("%d", &menor);
    
    //Variaveis de calculo
    float mes = horas_mes * valor_hora_trabalho + menor * 13.48;
    printf("O salario bruto no final do mes e R$%.2f", mes);
    
    return 0;
}