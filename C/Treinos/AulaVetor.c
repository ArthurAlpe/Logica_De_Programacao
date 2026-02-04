/*
Autor: Arthur Almeida Pereira
Data: 21/10/2025
Objetivo: 
*/

#include <stdio.h>

int main (){

    // Variaveis de entrada
    int i;
    int c;
    int idade[3][3];
    int maior_valor = 0;
    int menor_valor;

    // Le os valores
    for ( i = 0; i < 3; i++) {
        for ( c = 0; c < 3; c++) {
            printf("Digite valor[%d][%d]: ", i, c);
            scanf("%d", &idade[i][c]);

            if ( idade[i][c] > maior_valor ) {
                maior_valor = idade[i][c];
            }
            if ( idade[i][c] < menor_valor ) {
                menor_valor = idade[i][c];
            }
        }
    }

    // Mostra os valores da Matriz
    for ( i = 0; i < 3; i++) {
        for ( c = 0; c < 3; c++ ) {
            printf("%d \t", idade[i][c]);
        }
        printf("\n");
    }

    // Imprimir a diagonal principal
    for ( i = 0; i < 3; i++) {
        printf("%d\t", idade[i][i]);
    }
    printf("\n");

    // Imprimir o maior e o menor valor
    printf("O maior valor e.: %d\n", maior_valor);
    printf("O menor valor e.: %d", menor_valor);

}
