/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 30/09/2025
Objetivo: Algoritmo que lê o número do funcionário, seu salário atual, e o 
índice de produtividade discutido com a empresa
*******************************************************************************/

#include <stdio.h>

int main()
{
    //Variaveis
    int numFuncionario = 0;
    float aumentoEmpresa = 0.08;
    float ipde = 0.00; //Indice de Produtividade Discutido com a Empresa
    float salarioFuncionario = 0.00;
    
    printf("Informe o numero do funcionario: ");
    scanf("%d", &numFuncionario);
    
    printf("Informe seu salario atual: ");
    scanf("%f", &salarioFuncionario);
    
    printf("Informe o índice de produtividade discutido com a empresa: ");
    scanf("%f", &ipde);
    
    float aumentoSalario = (salarioFuncionario * ipde) + (salarioFuncionario * aumentoEmpresa);
    float novoSalario = salarioFuncionario + aumentoSalario;
    
    printf("Seu novo salario sera de: (R$) %.2f", novoSalario);

    return 0;
}