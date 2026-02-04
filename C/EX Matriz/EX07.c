/*
Autor: Arthur Almeida Pereira
Data: 25/10/2025
Objetivo:  Ler uma matriz 4 X 4 com números inteiros e verificar se essa matriz forma um
quadrado mágico.
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int c;
    int matriz[4][4];
    int soma_DigP = 0; // Diagonal Principal
    int soma_DigS = 0; // Diagonal Secundaria
    int soma_L = 0; // Linha
    int soma_C = 0; // Coluna
    int somaRef; //
    int resultado; // 

    // Processamento
    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("Digite o valor[%d][%d].: ", i, c);
            scanf("%d", &matriz[i][c]);

            if ( i == c ) {
                soma_DigP = soma_DigP + matriz[i][c]; // Soma da diagonal principal
            }

            if ( i + c == 3) {
                soma_DigS = soma_DigS + matriz[i][c]; // Soma da diagonal secundaria
            }

            if ( i == 0 ) {
                soma_L = soma_L + matriz[i][c]; // Soma da linha
                somaRef = soma_L; // Referencia para soma
            }

            if ( c == 0 ) {
                soma_C = soma_C + matriz[i][c]; // Soma da coluna
            }
        }
    }

    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("%d \t", matriz[i][c]); // Imprimir a matriz
        }
        printf("\n");
    }

    printf("\n");

    printf("Diagonal Principal: %d\n", soma_DigP);
    printf("Diagonal secundaria: %d\n", soma_DigS);
    printf("Linha: %d\n", soma_L);
    printf("Coluna: %d\n", soma_C);
    printf("\n");

    resultado = ( soma_L + soma_C + soma_DigP + soma_DigS ) / 4; // Validacao
    
    
    if (somaRef == resultado ) {
        printf("Esta matriz e um quadrado magico!");
    } else {
        printf("Esta matriz nao e um quadrado magico!");
    }
    

}