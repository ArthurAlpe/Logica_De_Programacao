/*
Autor: Arthur Almeida Pereira
Data: 28/10/2025
Objetivo: Uma calculadora que soma, subtrai, divide e multiplica
*/

#include <stdio.h>
#include <windows.h>

int main(){

    // Variavel de controle
    int opcao;
    int i;

    // Variaveis de soma
    int qtdSoma = 0; 
    int soma = 0;
    int numSoma = 0;
    
    // Variaveis de subtracao
    int qtdSub = 0;
    int subtrair = 0;
    int numSub;

    // Variaveis de divisao
    int qtdDiv = 0;
    float divisao = 0;
    float numDiv;

    // Variaveis de multiplicacao
    int qtdMulti = 0;
    float multiplicacao = 1;
    float numMulti;

    // Entrada

    printf("+----------------------------+\n");
    printf("|                            |\n");
    printf("|        Calculadora         |\n");
    printf("|                            |\n");
    printf("+----------------------------+\n");

    system("pause");
    system("cls");

    printf("+----------------------------+\n");
    printf("|    Selecione a opcao:      |\n");
    printf("|                            |\n");
    printf("| 1 - Soma                   |\n");
    printf("| 2 - Subtracao              |\n");
    printf("| 3 - Divisao                |\n");
    printf("| 4 - Multiplicacao          |\n");
    printf("|                            |\n");
    printf("| 0 - Sair                   |\n");
    printf("+----------------------------+\n");
    printf("\n");
    scanf("%d", &opcao);

    while ( opcao != 0 ) {

        switch ( opcao ) {

            case 1:
            system("cls");
            
            soma = 0;
            
            printf("Digite a quantidade de numeros que deseja somar.: ");
            scanf("%d", &qtdSoma);
            
            for ( i = 0; i < qtdSoma; i++ ) {
                printf("Digite o valor.: ");
                scanf("%d", &numSoma);
                soma = soma + numSoma;
            }

            printf("A soma dos numeros que inseriu e.: %d\n", soma);
            printf("\n");

            printf("Deseja alguma outra opcao?\n");
            scanf("%d", &opcao);
            printf("\n");
            printf("+----------------------------+\n");
            printf("|    Selecione a opcao:      |\n");
            printf("|                            |\n");
            printf("| 1 - Soma                   |\n");
            printf("| 2 - Subtracao              |\n");
            printf("| 3 - Divisao                |\n");
            printf("| 4 - Multiplicacao          |\n");
            printf("|                            |\n");
            printf("| 0 - Sair                   |\n");
            printf("+----------------------------+\n");

            break;

            case 2:
            system("cls");

            subtrair = 0;

            printf("Digite a quantidade de numeros que deseja subtrair.: ");
            scanf("%d", &qtdSub);

            printf("Digite o primeiro valor: ");
            scanf("%d", &subtrair);

            for ( i = 1; i < qtdSub; i++) {
                printf("Digite o valor.: ");
                scanf("%d", &numSub);

                subtrair = subtrair - numSub;
            }
            
            printf("A subtracao dos numeros que inseriu e.: %d\n", subtrair);
            printf("\n");

            printf("Deseja alguma outra opcao?\n");
            scanf("%d", &opcao);
            printf("\n");
            printf("+----------------------------+\n");
            printf("|    Selecione a opcao:      |\n");
            printf("|                            |\n");
            printf("| 1 - Soma                   |\n");
            printf("| 2 - Subtracao              |\n");
            printf("| 3 - Divisao                |\n");
            printf("| 4 - Multiplicacao          |\n");
            printf("|                            |\n");
            printf("| 0 - Sair                   |\n");
            printf("+----------------------------+\n");

            break;

            case 3:
            system("cls");

            divisao = 0;

            printf("Digite a quantidade de numeros que deseja dividir.: ");
            scanf("%d", &qtdDiv);

            printf("Digite o primeiro valor: ");
            scanf("%f", &divisao);

            for (i = 1; i < qtdDiv; i++) {
                printf("Digite o próximo valor ( Que nao seja 0 ): ");
                scanf("%f", &numDiv);

                if (numDiv == 0) {
                    printf("Nao é possível dividir por 0, ignorando esse número.\n");
                    continue; // pula para o próximo número
                }

                divisao = divisao / numDiv;
            }

            printf("A divisao dos numeros que inseriu e.: %.2f\n", divisao);
            printf("\n");

            printf("Deseja alguma outra opcao?\n");
            scanf("%d", &opcao);
            printf("\n");
            printf("+----------------------------+\n");
            printf("|    Selecione a opcao:      |\n");
            printf("|                            |\n");
            printf("| 1 - Soma                   |\n");
            printf("| 2 - Subtracao              |\n");
            printf("| 3 - Divisao                |\n");
            printf("| 4 - Multiplicacao          |\n");
            printf("|                            |\n");
            printf("| 0 - Sair                   |\n");
            printf("+----------------------------+\n");

            break;

            case 4:
            system("cls");

            multiplicacao = 1;

            printf("Digite a quantidade de numeros que deseja multiplicar.: ");
            scanf("%d", &qtdMulti);

            for ( i = 0; i < qtdMulti; i++ ) {
                printf("Digite o valor.: ");
                scanf("%f", &numMulti);

                multiplicacao = multiplicacao * numMulti;
            }

            printf("A multiplicacao dos numeros que inseriu e.: %.2f\n", multiplicacao);
            printf("\n");

            printf("Deseja alguma outra opcao?\n");
            scanf("%d", &opcao);
            printf("\n");
            printf("+----------------------------+\n");
            printf("|    Selecione a opcao:      |\n");
            printf("|                            |\n");
            printf("| 1 - Soma                   |\n");
            printf("| 2 - Subtracao              |\n");
            printf("| 3 - Divisao                |\n");
            printf("| 4 - Multiplicacao          |\n");
            printf("|                            |\n");
            printf("| 0 - Sair                   |\n");
            printf("+----------------------------+\n");

            break;

            default:
            break;

        }
    }
}