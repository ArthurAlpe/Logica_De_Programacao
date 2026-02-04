/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 08/10/2025
Objetivo: Faça um programa que lê o nome de um aluno, suas três notas e fornece 
o conceito obtido em função da sua média considerando: nota1 - peso 2, nota2 - 
peso 3 nota3 - peso 5.
*******************************************************************************/
#include <stdio.h>

int main()
{
    char nome[40];
    float nota1;
    float nota2;
    float nota3;
    
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(nome, 40, stdin);
    
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("Digite a segunda nota.: ");
    scanf("%f", &nota2);
    
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);
    
    float media = ((nota1 * 2) + (nota2 * 3) + (nota3 * 5)) / (2 + 3 + 5);
    
    if (media < 5) {
        printf("O aluno %s ficou com a nota %.2f Conceito D", nome, media);
    } else if (media >= 5 && media <= 6) {
        printf("O aluno %s ficou com a nota %.2f Conceito C", nome, media);
    } else if (media >= 7 && media <= 8) {
        printf("O aluno %s ficou com a nota %.2f Conceito B", nome, media);
    } else if (media >= 9 && media <= 10) {
        printf("O aluno %s ficou com a nota %.2f Conceito A", nome, media);
    }
    

    return 0;
}