/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 09/10/2025
Objetivo: Somar notas pares
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    
    int nota = 0;
    float soma = 0;
    float media;
    int qtd = 0;

    do {
        printf("Digite notas pares: (0 = sair)");
        scanf("%d", &nota);
        
        if ((nota % 2 == 0) && (nota != 0)){
            soma = soma + nota;
            qtd++;
        }
        
        
    } while (nota != 0);
    
    media = soma / qtd;
    
    printf("\n\nForam digitados %d pares e a media do usuario e: %.2f", qtd, media);

    return 0;
}
