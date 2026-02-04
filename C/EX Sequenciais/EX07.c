/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 29/09/2025
Objetivo: Um programa em C para mostrar e calcular o numero do vendedor, nome e salario final
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int numVendedor = 0;
    char nome[30];
    float salarioFixo = 0.00;
    float totalVendas = 0.00;
    float totalSalario = 0.00;
    
    //Esperando a resposta do usuario
    printf("Informe o numero do vendedor: ");
    scanf("%d", &numVendedor);
    getchar();
    
    printf("Informe o nome do vendedor: ");
    fflush(stdin);
    fgets(nome, 30, stdin);
    
    printf("Informe o salario fixo do vendedor: ");
    scanf("%f", &salarioFixo);
    
    printf("Informe o total de vendas(R$): ");
    scanf("%f", &totalVendas);
    
    //Variavel para o calculo final
    totalSalario = salarioFixo + (totalVendas * 0.28);
    
    //Execução para o valor final
    printf("Vendedor codigo: %d, nome: %s\n", numVendedor, nome);
    printf("Salario total: %.2f", totalSalario);

    return 0;
}