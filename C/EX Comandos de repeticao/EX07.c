/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 16/10/2025
Objetivo: Elabore um algoritmo em Linguagem C que leia 5 conjuntos de 2 valores,
onde o primeiro valor representa o número de um aluno e o segundo representa sua
altura em centímetros.
*******************************************************************************/

#include <stdio.h>

int main()
{
    // Variáveis
    int num_aluno;
    int altura_aluno;
    int I;
    int maior_altura;
    int menor_altura;
    int num_aluno_maior;
    int num_aluno_menor;

    // Entrada e processamento
    for (I = 1; I <= 5; I++) {

        printf("Digite o numero do aluno.: ");
        scanf("%d", &num_aluno);

        printf("Digite a altura do aluno.: ");
        scanf("%d", &altura_aluno);

        // Inicialização no primeiro loop
        if (I == 1) {
            maior_altura = altura_aluno;
            menor_altura = altura_aluno;
            num_aluno_maior = num_aluno;
            num_aluno_menor = num_aluno;
        }

        // Verifica se é mais alto
        if (altura_aluno > maior_altura) {
            maior_altura = altura_aluno;
            num_aluno_maior = num_aluno;
        }

        // Verifica se é mais baixo
        if (altura_aluno < menor_altura) {
            menor_altura = altura_aluno;
            num_aluno_menor = num_aluno;
        }
    }

    // Saída
    printf("\n--------------------------------------------\n");
    printf(". O Aluno %d e o mais alto com %dcm de altura\n", num_aluno_maior, maior_altura);
    printf(". O Aluno %d e o mais baixo com %dcm de altura\n", num_aluno_menor, menor_altura);

    return 0;
}