/*
Autor: Arthur Almeida Pereira
Data: 04/11/2025
Objetivo: Criar uma funcao
*/

#include <stdio.h>

// Funcao q1ue imprime o dobro de um numero
void imprimeDobro(int n){
    
    printf("O dobro do numero %d e %d\n", n, n * 2);

}

// Funcao que imprime o numero ao quadrado
void imprimeNumeroQuadrado(int x){
    
    printf("%d ao quadrado e %d\n", x, x * x);

}

// Funcao que mostra a tabuada do numero
void imprimeTabuada(int y){
    
    int i;
    
    printf("A Tabuada do %d:\n", y);

    for ( i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", y, i, y * i);
    }
}

// Funcao que mostra se e Par ou Impar
void imprimePar_ou_Impar(int z){
    if ( z % 2 == 0 ) {
        printf("%d e par\n", z);
    } else {
        printf("%d e impar\n", z);
    }
}

// Funcao principal
int main()
{
    
    int numero; // Variavel para numero

    printf("Digite um numero.: ");
    scanf("%d", &numero);
    imprimeDobro(numero);
    imprimeNumeroQuadrado(numero);
    imprimeTabuada(numero);

    imprimeTabuada(5);

    imprimeTabuada(10);

    imprimeTabuada(15);

    imprimeTabuada(20);

    imprimePar_ou_Impar(numero);

    printf("Fim do programa\n");

    return 0;
}