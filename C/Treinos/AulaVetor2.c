/*
Autor: Arthur Almeida Pereira
Data: 23/10/2025
Objetivo: 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int vetor[5];
    int dif = 0; // Diferenca
    int maior = 0;
    int l;

    // Entrada dos vetores
    for ( i = 0; i < 5; i++ ) {
        printf("Digite o valor.: ");
        scanf("%d", &vetor[i]);
    }

    // Encontrar a diferenca entre os elemnetos consecutivos
    l = 0;
    for ( i = 1; i < 5; i++ ) {
        dif = vetor[l] - vetor[i];
        if ( dif > maior) {
            maior = dif;
        }
        printf("vetor[%d] - vetor[%d] = %d\n", l, i, dif);
        l++;
    }

    printf("\n");

    // Processamento
    for ( i = 0; i < 5; i++ ) {
        printf("%d \t", vetor[i]);
    }

    printf("\n");

    // Saida com a maior diferenca
    printf("\n\n");
    printf("A diferenca entre os numeros do vetor e.: %d\n", maior);

    return 0;
}