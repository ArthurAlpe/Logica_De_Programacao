/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 10/10/2025
Objetivo: Faça um programa que lê a hora inicial e final de um jogo, considerando
apenas horas inteiras. Calcular a duração do jogo em horas, sabendo que o tempo 
máximo de duração de um jogo é de 24 horas e que o jogo pode começar em um dia 
e terminar no dia seguinte.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int horaInicial;
    int horaFinal;
    int calculoFinal;
    
    printf("Digite a hora que comecou o jogo: ");
    scanf("%d", &horaInicial);
    
    printf("Digite a hora que terminou o jogo: ");
    scanf("%d", &horaFinal);
    
    if (horaFinal > horaInicial) {
        calculoFinal = horaFinal - horaInicial;
        printf("A duracao da partida foi de %d", calculoFinal);
    } else {
        calculoFinal = (24 - horaInicial) + horaFinal;
        printf("A duracao da partida foi de %d", calculoFinal);
    }
    
    
    
    
    return 0;
}