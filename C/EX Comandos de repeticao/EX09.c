/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 14/10/2025
Objetivo: A prefeitura de uma cidade realizou uma pesquisa entre seus habitantes,
coletando dados sobre o salário e o número de filhos. Com base nessa pesquisa, 
a prefeitura deseja obter as seguintes informações: 
1. Média do salário da população.
2. Média do número de filhos.
3. Maior salário registrado.
4. Percentual de pessoas com salário até R$100,00. 
*******************************************************************************/

#include <stdio.h>
#include <windows.h> //Biblioteca para system

int main()
{
    //Variaveis
    
    int filhos;
    int continuar;
    int contador = 0;
    int tot_1000 = 0;
    float media_salario;
    float total_salario = 0;
    float media_filhos;
    float total_filhos = 0;
    float maior_salario;
    float salario;
    float perc_1000;
    
    //Entrada de dados
    
    do {
        
        system("cls"); // Clear no terminal (ficar mais organizado)
        contador++;
        printf("Pessoas Entrevistadas......: %d\n", contador);
        printf("Digite o Salario...........: ");
        scanf("%f", &salario);
        printf("Digite o Numero de Filhos..: ");
        scanf("%d", &filhos);
        
        printf("\n");
        printf("Deseja responder novamente.: (0=Sim; 1=Nao).:");
        scanf("%d", &continuar);
        
        // Processamento do programa
        contador++;
        total_salario = total_salario + salario;
        total_filhos = total_filhos + filhos;
        
        if (salario > maior_salario) {
            maior_salario = salario; //Calculo para o maior salario
        }
        
        if (salario < 1000) {
            tot_1000++; //Quantidade de pessoas com salario menor que 1000
        }
        
    } while (continuar == 0);
    
    //Variaveis de calculo
    media_salario = (total_salario / contador);
    media_filhos = (total_filhos / contador);
    perc_1000 = (tot_1000 / contador) * 100;
    
    //Saida
    
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("Total de Pessoas Entrevistadas..................: %d\n", contador);
    printf("A media de salario dos Entrevistados............: %.2f\n", media_salario);
    printf("A media de Numero de filhos dos Entrevistados...: %.2f\n", media_filhos);
    printf("Total de Pessoas que ganham menos que 1000......: %d\n", tot_1000);
    printf("Percentual de Pessoas que ganham menos que 1000.: %.2f\n", perc_1000);
    printf("O Maior Salario dos Entrevistados...............: %.2f\n", maior_salario);
    
    
    return 0;
}