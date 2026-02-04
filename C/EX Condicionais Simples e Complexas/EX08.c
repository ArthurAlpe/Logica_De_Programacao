/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 08/10/2025
Objetivo: Ler quatro valores referentes a quatro notas escolares de um aluno e 
imprimir uma mensagem dizendo que o aluno foi aprovado, se o valor da media 
escolar for maior ou igual a 7. Se o valor da media for menor que 7 mostrar a 
mensagem que o aluno reprovou. 
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int num;
    int soma = 0;
    int I;
    
    for (I = 1; I <= 4; I++) {
        printf("Digite a nota do aluno: ");
        scanf("%d", &num);
        
        soma = soma + num;
    
    }
    
    soma = soma / 4;
    
    if (soma >= 7) {
        printf("O aluno foi aprovado!");
    } else if (soma < 7) {
        printf("O aluno foi reprovado!");
    }
    

    return 0;
}