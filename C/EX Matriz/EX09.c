/*
Autor: Arthur Almeida Pereira
Data: 27/10/2025
Objetivo: Ler uma matriz A de elementos inteiros distintos de dimensão 4 x 4. Gerar dois vetores V e W,
formados respectivamente pela linha de A correspondente ao maior elemento da diagonal
principal e pela coluna de A correspondente ao menor elemento da diagonal principal. Escrever
a matriz A e os vetores V e W 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int i;
    int c;
    int matrizA[4][4];
    int V[4];
    int W[4];
    int maior;
    int posMaior;
    int menor;
    int posMenor;

    // Processamento

    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("Digite o valor[%d][%d].: ", i, c);
            scanf("%d", &matrizA[i][c]);
        }
    }


    // Atribuindo um valor 0 para nao ocorrer nenhum problema
    maior = menor = matrizA[0][0];
    posMaior = posMenor = 0;


    // Primeiro laco de repeticao para saber as posicoes do maior e menor valor
    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            
            if ( i == c ) {
                if ( matrizA[i][c] > maior ) {                
                    maior = matrizA[i][c];
                    posMaior = i;
                }
                
                if ( matrizA[i][c] < menor ) {
                    menor = matrizA[i][c];
                    posMenor = c;
                }
            }
                       
        }
    }

    // Lacos de repeticao para atribuir aos vetores os valores
    for ( c = 0; c < 4; c++ ) {
        V[c] = matrizA[posMaior][c];
    }

    for ( i = 0; i < 4; i++ ) {
        W[i] = matrizA[i][posMenor];
    }

    // Laco para imprimir a matrizA
    for ( i = 0; i < 4; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("%d \t", matrizA[i][c]);
        }
        printf("\n");
    }

    // Laco para imprimir o vetor V
    for ( c = 0; c < 4; c++ ) {
        printf("V %d\n", V[c]);
    }

    // Laco para imprimir o vetor W
    for ( i = 0; i < 4; i++ ) {
        printf("W %d", W[i]);
    }
}