/*
Autor: Arthur Almeida Pereira
Data: 23/10/2025
Objetivo: 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int vetor[2];
    int dif = 0; // Diferenca
    int maior = 0;
    int l;
    int s = 0;

    // Entrada dos vetores
    for ( i = 0; i < 20; i++ ) {
        printf("Digite o valor.: ");
        scanf("%d", &vetor[i]);
    }

    // Encontrar a diferenca entre os elemnetos consecutivos
    l = 19;
    for ( i = 0; i < 10; i++ ) {
        dif = vetor[l] - vetor[i];
        if ( dif > maior) {
            maior = dif;
        }
        printf("vetor[%d] - vetor[%d] = %d\n", i, l, dif);
        l--;
        s = s + dif;
    }

    printf("\n");

    // Saida com a maior diferenca
    printf("\n\n");
    printf("A soma da diferenca entre os numeros do vetor e.: %d\n", s);

    return 0;
}