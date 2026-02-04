/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 26/09/2025
Objetivo: Ler o preço e a taxa de conversão para o dólar. 
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    float reais;
    float taxa;
    char nome_produto[40];
    
    //Terminal esperando o usuario
    printf("Digite o nome do produto...:");
    fflush(stdin);
    fgets(nome_produto,40,stdin);
    
    printf("Digite o valor do produto em reais...:");
    scanf("%f", &reais);
    
    printf("Digite o valor do dolar no atual momento...:");
    scanf("%f", &taxa);
    
    float valorFinal = reais / taxa; //Calculo final
    printf("O seu produto, em dolar, e $%.2f, sendo a taxa de %.4f", valorFinal, taxa);    

    return 0;
}
