/******************************************************************************
Autor.....: Arthur Almeida Pereira
Data......: 12/09/2025
Objetivo..: Exercicios de programção em Linguagem C

*******************************************************************************/
#include <stdio.h>

int main()
{
    // PE : Pulsos Excedentes
    float pe = 164 * 0.04;
    // CPC : Chamadas para celular
    float cpc = 23 * 0.20;
    // Final : Total final custo
    float final = 17.90 + pe + 34.29 + cpc;
    
    printf("Assinatura : R$17.90\n");
    printf("Pulsos interurbanos = R$0.04 por pulso que exceder a 90\n");
    printf("Chamadas para celular = R$ 0.20 por impulso\n");
    printf("\n");
    printf("254 impulsos\n");
    printf("R$34.29 de interurbanos\n");
    printf("23 chamadas para celular\n");
    printf("\n");
    printf("Total = 17.90 + %f de pulsos excedentes + 34.29 + %f \n", pe, cpc);
    printf("Total = %f", final);

    return 0;
}
