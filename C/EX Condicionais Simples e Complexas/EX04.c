/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 07/10/2025
Objetivo: Considerar três notas inteiras, encontrar a Média aritmética simples, 
entre as notas que correspondem aos números, deixando de fora da media as notas 
impares. Se nenhuma for PAR emita a mensagem “NENHUMA NOTA PAR”.
*******************************************************************************/

#include <stdio.h>

int main()
{
    int A;
    int B;
    int C;
    int soma = 0;
    int qtd = 0;
    float media;

    printf("Digite sua nota 1: ");
    scanf("%d", &A);

    printf("Digite sua nota 2: ");
    scanf("%d", &B);

    printf("Digite sua nota 3: ");
    scanf("%d", &C);

    if (A % 2 == 0) {
        soma += A;
        qtd++;
    }

    if (B % 2 == 0) {
        soma += B;
        qtd++;
    }

    if (C % 2 == 0) {
        soma += C;
        qtd++;
    }

    if (qtd == 0) {
        printf("NENHUMA NOTA PAR\n");
    } else {
        media = (float)soma / qtd;
        printf("A media aritmetica das notas pares e: %.2f\n", media);
    }

    return 0;
}