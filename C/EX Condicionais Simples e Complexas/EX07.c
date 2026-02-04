/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 07/10/2025
Objetivo: Elaborar um algoritmo que efetue a leitura do nome e do sexo de uma 
pessoa, apresentando como saída uma das seguintes mensagens: “ILMO SR.” Para o 
sexo Masculino; “ILMA SRA.”, para o sexo feminino. Apresente também abaixo da 
mensagem o nome da pessoa. 
*******************************************************************************/
#include <stdio.h>

int main()
{
    char nome[40];
    char genero;
    
    printf("Informe seu nome..........: ");
    fflush(stdin);
    fgets(nome, 40, stdin);
    
    printf("Informe seu genero, M ou F: ");
    scanf(" %c", &genero);
    
    if (genero == 'F') {
        printf("ILMA SRA. %s", nome);
    } else if (genero == 'M') {
        printf("ILMO SR. %s", nome);
    }

    return 0;
}