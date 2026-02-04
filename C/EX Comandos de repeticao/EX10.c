/******************************************************************************
Autor...: Arthur Almeida Pereira
Data....: 09/10/2025
Objetivo: Em uma eleição presidencial, há quatro candidatos. Os votos são informados através de
códigos, conforme a seguinte codificação:
1: Voto para o Candidato 1
2: Voto para o Candidato 2
3: Voto para o Candidato 3
4: Voto para o Candidato 4
5: Voto Nulo
6: Voto em Branco 
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Declarar Variaveis necessarias
    
    int voto;
    int Candidato1 = 0;
    int Candidato2 = 0;
    int Candidato3 = 0;
    int Candidato4 = 0;
    int brancos = 0;
    int nulos = 0;
    
    //Entradas de dados
    
    printf("Para finalizar e ver a soma total, digite 0\n\n");
    
    do {
        printf("Digite seu voto: ");
        scanf("%d", &voto);
    
        if (voto == 1) {
        Candidato1++;
        } else if (voto == 2) {
        Candidato2++;
        } else if (voto == 3) {
        Candidato3++;
        } else if (voto == 4) {
        Candidato4++;
        } else if (voto == 5) {
        brancos++;
        } else if (voto == 6) {
        nulos++;
        } 

        if (voto >= 7) {
        printf("Digite apenas 1 | 2 | 3 | 4 | 5 | 6 | 0\n");
        }
        } while (voto != 0);
    
    printf("---RESULTADO DAS ELEICOES---");
    printf("\n\n .Candidato 1 recebeu %d votos", Candidato1);
    printf("\n .Candidato 2 recebeu %d votos", Candidato2);
    printf("\n .Candidato 3 recebeu %d votos", Candidato3);
    printf("\n .Canditato 4 recebeu %d votos", Candidato4);
    printf("\n .%d votos em branco", brancos);
    printf("\n .%d votos nulos", nulos);
    
    return 0;
}