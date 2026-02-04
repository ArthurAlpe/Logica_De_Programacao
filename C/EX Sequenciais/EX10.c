/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 30/09/2025
Objetivo: programa que leia o número de empregados da loja, o valor do salário 
mínimo, o preço de custo de cada bicicleta, o número de bicicletas vendidas.
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    int numEmpregados, bicicletasVendidas;
    float salarioMinimo, precoCusto;
    
    //Entrada de dados ( esperando o usuario no terminal )
    printf("Informe o numero de empregados na loja....: ");
    scanf("%d", &numEmpregados);
    
    printf("Informe o valor do salario minimo..........: ");
    scanf("%f", &salarioMinimo);
    
    printf("Informe o preco de custo de cada bicicleta.: ");
    scanf("%f", &precoCusto);
    
    printf("Informe o numero de bicicletas vendidas....: ");
    scanf("%d", &bicicletasVendidas);
    
    //Cálculo do salário dos empregados
    float salarioFixo = salarioMinimo * 2;
    float comissaoTotal = 0.15 * precoCusto * bicicletasVendidas;
    float comissaoPorEmpregado = comissaoTotal / numEmpregados;
    float salarioFinal = salarioFixo + comissaoPorEmpregado;
    
    //Cálculo da receita e do lucro líquido
    float precoVenda = precoCusto * 1.5;
    float receita = precoVenda * bicicletasVendidas;
    float custoTotalBicicletas = precoCusto * bicicletasVendidas;
    float despesas = numEmpregados * salarioFinal;
    float lucro = receita - custoTotalBicicletas - despesas;
    
    //Saída
    printf("Salario final de cada empregado: R$ %.2f\n", salarioFinal);
    printf("Lucro liquido da loja..........: R$ %.2f\n", lucro);
    
    return 0;
}