/*
Autor: Arthur Almeida Pereira
Data: 16/10/2025
Objetivo: Aprender e executar vetor
*/

#include <stdio.h>
#include <windows.h>

int main(){

    //Variaveis
    int idade[5];
    int i;
    int maior_idade = 0;
    int menor_idade = 130;
    int posicaoMaior = 0;
    int posicaoMenor = 0;

    for(i = 0; i < 5; i++) {
        system("cls"); //Clear o terminal
        printf("Digite a idade [%d].: ", i);
        scanf("%d", &idade[i]);

    }

    for(i = 0; i < 5; i++) {
        printf("idade[%d] = %d\n", i, idade[i]);

        if (idade[i] > maior_idade) { //Compara para saber qual a maior idade
            maior_idade = idade[i];
            posicaoMaior = i;
        }

        if (idade[i] < menor_idade) {
            menor_idade = idade[i];
            posicaoMenor = i;
        }

    }

    //Saida do programa com a maior idade
    system("cls"); //Clear o terminal
    printf("A maior idade[%d] = %d\n", posicaoMaior, maior_idade);
    printf("A menor idade[%d] = %d", posicaoMenor, menor_idade);
}