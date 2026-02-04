/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 15/10/2025
Objetivo: Soma de números inteiros, ignorando decimais. O programa verifica se
o número digitado é inteiro e só então acumula na soma.
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int I;
    int quantidade;
    float numero;       // lê como float para detectar decimais
    int parteInteira;
    int soma = 0;

    //Enunciado
    printf("Cálculo da Soma de Números Inteiros\n\n");
    
    //Entrada
    printf("Digite a quantidade de números que deseja somar: ");
    scanf("%d", &quantidade);

    for(I = 0; I < quantidade; I++) {
        printf("Digite o número %d: ", I + 1);
        scanf("%f", &numero);

        parteInteira = (int)numero;  // pega a parte inteira

        if(numero == parteInteira) {
            soma += parteInteira;    // só soma se for inteiro
        } else {
            printf("Número decimal não é permitido, digite um inteiro.\n");
            I--;  // repete esta iteração
        }
    }
    
    //Saida
    printf("\nA soma de todos os números inteiros é: %d\n", soma);

    return 0;
}