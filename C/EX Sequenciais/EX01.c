/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 26/09/2025
Objetivo: Um algoritmo que leia o nome do automóvel e o preço de fábrica e escre
va o nome do automóvel e o preço final. 
*******************************************************************************/

#include <stdio.h>

int main()
{
    float fabrica;
    float imposto = 0.45; // 45% dos impostos
    float revendedor = 0.28; // 28% do repasse do vendedor
    float valor_automovel; // com base no valor que o usuario colocar
    char  nome_automovel[30];

    // variavel para guardar valores calculados
    float valor_imposto;
    float valor_revendedor;

    printf(" Digite o nome do carro: ");
    fflush(stdin);
    fgets(nome_automovel,30,stdin);
    
    printf(" Digite o valor do automovel: R$ ");
    scanf("%f", &valor_automovel);

    valor_imposto = valor_automovel * imposto;
    printf(" O valor de imposto e: R$ %.2f\n", valor_imposto); 

    valor_revendedor = valor_automovel * revendedor;
    printf( " O valor do revendedor e: R$ %.2f\n", valor_revendedor);

    fabrica = valor_automovel + valor_imposto + valor_revendedor;
    printf(" O valor final da fabrica e: %.2f", fabrica);

return 0;
}