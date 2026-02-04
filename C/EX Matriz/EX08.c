/*
Autor: Arthur Almeida Pereira
Data: 25/10/2025
Objetivo: Preencher a Matriz com números pares e Ímpares nas
colunas corretas 
*/

#include <stdio.h>

int main(){

    // Variaveis
    int matriz[5][4];
    int linhaPar = 0;
    int colunaPar = 0;
    int linhaImpar = 1;
    int colunaImpar = 0;
    int semEspacoPar = 0;
    int semEspacoImpar = 0;
    int i;
    int c;
    int num;


    // Inicializando a matriz em 0
    for ( i = 0; i < 5; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            matriz[i][c] = 0;
        }
    }

    // Loop infinito para separar e armazenar os numeros pares e impares
    while (1) {
        printf("Digite o valor.: ");
        scanf("%d", &num);

        if ( num % 2 == 0 && !semEspacoPar ) {
            matriz[linhaPar][colunaPar] = num;  // Separando a matriz para pegar apenas numeros pares
            colunaPar++;

            if ( colunaPar == 4 ) {
            linhaPar += 2; // Apos encher a linha par, pular para a proxima que possa armazenar
            colunaPar = 0;
            }
            
            if ( linhaPar > 4 ) {
            semEspacoPar = 1;
            printf("Sem espaço para numeros pares!\n");
            }
        }
        
        if ( num % 2 != 0 && !semEspacoImpar ) {
            matriz[linhaImpar][colunaImpar] = num; // Separando a matriz para pegar apenas numeros impares
            colunaImpar++;
            if ( colunaImpar == 4 ) {
            linhaImpar += 2;  // Apos encher a linha impar, pular para a proxima que possa armazenar
            colunaImpar = 0;
            }
            if ( linhaImpar > 3 ) {
            semEspacoImpar = 1;
            printf("Sem espaço para numeros impares!\n");
            }
        }
        

        if ( semEspacoImpar && semEspacoPar ) {
            
            printf("Matriz totalmente preenchida!\n");  // Terminal mostrando que a Matriz ja esta preenchida e informando para o usuario a matriz final
            
            break;
        }
    }


    // Saida
    for ( i = 0; i < 5; i++ ) {
        for ( c = 0; c < 4; c++ ) {
            printf("%d \t", matriz[i][c]);  // Matriz final com todos os numeros inseridos 
        }
        printf("\n");
    }
}