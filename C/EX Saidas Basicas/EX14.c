/******************************************************************************
Autor.....: Arthur Almeida Pereira
Data......: 13/09/2025
Objetivo..: Exercicios de programção em Linguagem C
*******************************************************************************/
#include <stdio.h>

int main() {
    float salario, imposto;

    printf("Qual seu salário ?: ");
    scanf("%f", &salario);

    if (salario <= 1200.00) {
        imposto = 0;
        printf("Recebendo: ate 1200.00 (isento)\n");
        printf("Deve-se recolher: R$ %.2f de impostos\n", imposto);
    } 
    else if (salario <= 5000.00) {
        imposto = salario * 0.10;
        printf("Recebendo: de 1201.00 a 5000.00 (10%%)\n");
        printf("Deve-se recolher: R$ %.2f de impostos\n", imposto);
    } 
    else if (salario <= 10000.00) {
        imposto = salario * 0.15;
        printf("Recebendo: de 5001.00 a 10000.00 (15%%)\n");
        printf("Deve-se recolher: R$ %.2f de impostos\n", imposto);
    } 
    else {
        imposto = salario * 0.20;
        printf("Recebendo: acima de 10000.00 (20%%)\n");
        printf("Deve-se recolher: R$ %.2f de impostos\n", imposto);
    }

    return 0;
}