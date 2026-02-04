/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 07/10/2025
Objetivo: Em uma empresa, cada funcionário recebe mensalmente o salário bruto 
mais um prêmio de comissões. São fornecidos os seguintes valores: salário bruto,
prêmio, base do INSS, base do imposto de renda (IR) e suas respectivas taxas. 
O demonstrativo de pagamento deve incluir o salário bruto, prêmio, rendimento, 
desconto de IR e salário líquido. O rendimento é a soma do salário bruto e do 
prêmio. O desconto do INSS aplica-se se o rendimento exceder a base do INSS. 
O desconto do IR aplica-se se a diferença entre o rendimento e o desconto do 
INSS for maior que a base do IR. 
*******************************************************************************/

#include <stdio.h>

int main()
{
    // Variáveis
    float salarioBruto;
    float premio;
    float rendimento;
    float taxaINSS, taxaIR;
    float baseINSS, baseIR;
    float descINSS = 0, descIR = 0;
    float salarioLiquido;
    
    // Entrada de dados
    printf("Qual o salario bruto..: ");
    scanf("%f", &salarioBruto);
    
    printf("Qual o valor do premio: ");
    scanf("%f", &premio);
    
    printf("Qual a taxa do INSS...: ");
    scanf("%f", &taxaINSS);
    
    printf("Qual a taxa do IR.....: ");
    scanf("%f", &taxaIR);
    
    printf("Qual a base do INSS...: ");
    scanf("%f", &baseINSS);
    
    printf("Qual a base do IR.....: ");
    scanf("%f", &baseIR);
    
    // Cálculos
    rendimento = salarioBruto + premio;
    
    // Desconto INSS
    if (rendimento > baseINSS) {
        descINSS = rendimento * (taxaINSS / 100);
    }
    
    // Desconto IR
    if ((rendimento - descINSS) > baseIR) {
        descIR = (rendimento - descINSS) * (taxaIR / 100);
    }
    
    salarioLiquido = rendimento - descINSS - descIR;
    
    // Saída
    printf("\n==== DEMONSTRATIVO DE PAGAMENTO ====\n");
    printf("Salario Bruto.....: %.2f\n", salarioBruto);
    printf("Premio............: %.2f\n", premio);
    printf("Rendimento........: %.2f\n", rendimento);
    printf("Desconto INSS.....: %.2f\n", descINSS);
    printf("Desconto IR.......: %.2f\n", descIR);
    printf("------------------------------------\n");
    printf("Salario Liquido...: %.2f\n", salarioLiquido);
    
    return 0;
}