/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 15/10/2025
Objetivo: Apresentar todos os valores numéricos inteiros ímpares situados na 
faixa de 0 a 20. Para verificar se o número é ímpar, efetuar dentro da malha a 
verificação lógica desta condição com a instrução IF, perguntando se o número é 
ímpar, sendo, mostre-o, não sendo, passe para o próximo passo.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int I;
    
    for(I = 0; I <= 20; I++) {
        
        if(I % 2 != 0) {
            printf("%d e impar\n", I);
        }
    }
    
    
    return 0;
}