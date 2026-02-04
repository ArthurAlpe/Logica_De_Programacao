/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 30/09/2025
Objetivo: Algoritmo que leia o número de carros por ele vendidos, o valor total 
de suas vendas, o salário fixo e a comissão que recebe por carro vendido
*******************************************************************************/

#include <stdio.h>

int main()
{
    //Variaveis
    int carrosVendidos;
    float salarioFixo;
    float comissaoCarro;
    float valorTotalVendas;
    
    //Programa esperando o usuario
    printf("Informe o numero de carros vendidos..: ");
    scanf("%d", &carrosVendidos);
    
    printf("Informe o valor total das suas vendas: ");
    scanf("%f", &valorTotalVendas);
    
    printf("Informe seu salario fixo.............: ");
    scanf("%f", &salarioFixo);
    
    printf("Informe a comissao de cada carro.....: ");
    scanf("%f", &comissaoCarro);
    
    //Variavel para o calculo final
    float salarioMensalVendedor = salarioFixo + (comissaoCarro * carrosVendidos) + (0.05 * valorTotalVendas);
    
    //Saida
    printf("O salario mensal do vendedor e de R$%.2f", salarioMensalVendedor);

    return 0;
}