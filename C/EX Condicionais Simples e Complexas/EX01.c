/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 06/10/2025
Objetivo: programa que lendo o nome, idade em anos e sexo de um associado de um
clube concede desconto na mensalidade a ser paga
*******************************************************************************/

#include <stdio.h>

int main()
{
    char nome[40];
    int idade;
    char sexo;
    float mensalidade;
    float Desconto;
    
    
    printf("Informe seu nome.......: ");
    fflush(stdin);
    fgets(nome, 40, stdin);
    
    printf("Infome sua idade.......: ");
    scanf("%d", &idade);
    
    printf("Informe sua mensalidade: ");
    scanf("%f", &mensalidade);
    
    printf("Informe seu sexo com M ou F: ");
    scanf(" %c", &sexo);
    
    Desconto = 0;
    
    if ((sexo == 'F') && (idade <= 30)) {
        Desconto = mensalidade - mensalidade * 0.20;
    } else if ((sexo == 'F') && (idade = 31 <= 40)) {
        Desconto = mensalidade - mensalidade * 0.30;
    } else if ((sexo == 'F') && (idade >= 41)) {
        Desconto = mensalidade - mensalidade * 0.35;
    } else if ((sexo == 'M') && (idade <= 25)) {
        Desconto = 0;
    } else if ((sexo == 'M') && (idade >= 25)) {
        Desconto = mensalidade - mensalidade * 0.25;
    }
    
    printf("Seu nome e %s, sua idade e %d, sua mensalidade sera de %.2f", nome, idade, Desconto);
    return 0;
}