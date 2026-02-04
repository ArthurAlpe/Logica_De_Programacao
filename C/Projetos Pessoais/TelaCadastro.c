/*
Autor: Arthur Almeida Pereira
Data: 18/10/2025
Objetivo: Tela de cadastro
*/

#include <stdio.h>
#include <windows.h>

int main (){

    //Variaveis
    int opcao;
    char nome[50];
    int idade;
    char email[50];

    //Começo do programa

    printf("+-----------------------------+\n");
    printf("|           Tela              |\n");
    printf("|            de               |\n");
    printf("|         Cadastro            |\n");
    printf("+-----------------------------+\n");

    system("pause");
    

    printf("+-----------------------------+\n");
    printf("| 1 - Cadastrar o aluno       |\n");
    printf("| 2 - Consultar o aluno       |\n");
    printf("| 3 - Editar o cadastro       |\n");
    printf("| 4 - Excluir cadastro        |\n");
    printf("|                             |\n");
    printf("| 0 - Sair                    |\n");
    printf("+-----------------------------+\n");
    printf("\n");
    scanf("%d", &opcao);

    while (opcao != 0) { 
        
        switch (opcao) {

            case 1:
            system("cls");
            printf("+-----------------------------+\n");
            
            printf("Nome:\n");
            fflush(stdin);
            fgets(nome, 50, stdin);
        
            printf("Idade:\n");
            scanf("%d", &idade);    
            
            printf("Email:\n");
            fflush(stdin);
            fgets(email, 50, stdin);

            printf("+-----------------------------+\n");

            printf("\n\nCadastro feito com sucesso!\n");

            printf("Deseja alguma outra opcao? \n");
            printf("+-----------------------------+\n");
            printf("| 2 - Consultar o aluno       |\n");
            printf("| 3 - Editar o cadastro       |\n");
            printf("| 4 - Excluir cadastro        |\n");
            printf("|                             |\n");
            printf("| 0 - Sair                    |\n");
            printf("+-----------------------------+\n");
            scanf("%d", &opcao);

            break;

            case 2:
            system("cls");
            
            printf("+-----------------------------+\n");
            printf("| Nome: %s\n", nome);
            printf("| Idade: %d\n", idade);
            printf("| Email: %s\n", email);
            printf("+-----------------------------+\n");

            printf("\n\nConsulta feita com sucesso!\n");

            printf("+-----------------------------+\n");
            printf("| 3 - Editar o cadastro       |\n");
            printf("| 4 - Excluir cadastro        |\n");
            printf("|                             |\n");
            printf("| 0 - Sair                    |\n");
            printf("+-----------------------------+\n");


            printf("Deseja alguma outra opcao? \n");
            
            scanf("%d", &opcao);
            
            break;
            
            case 3:
            system("cls");
            
            printf("+-----------------------------+\n");
            
            printf("Nome:\n");
            fflush(stdin);
            fgets(nome, 50, stdin);
        
            printf("Idade:\n");
            scanf("%d", &idade);    
            
            printf("Email:\n");
            fflush(stdin);
            fgets(email, 50, stdin);

            printf("+-----------------------------+\n");

            printf("\n\nAlteracao feita com sucesso!\n");

            printf("+-----------------------------+\n");
            printf("| 2 - Consultar o aluno       |\n");
            printf("| 4 - Excluir cadastro        |\n");
            printf("|                             |\n");
            printf("| 0 - Sair                    |\n");
            printf("+-----------------------------+\n");

            printf("Deseja alguma outra opcao? \n");
            scanf("%d", &opcao);

            break;

            case 4:
            system("cls");

            nome[0] = '\0';
            idade = 0;
            email[0] = '\0';

            printf("Cadastro excluido com sucesso!\n");

            printf("+-----------------------------+\n");
            printf("| 1 - Cadastrar o aluno       |\n");
            printf("| 2 - Consultar o aluno       |\n");
            printf("| 3 - Editar o cadastro       |\n");
            printf("|                             |\n");
            printf("| 0 - Sair                    |\n");
            printf("+-----------------------------+\n");

            printf("Deseja alguma outra opcao? \n");
            scanf("%d", &opcao);

            break;

            default:
            break;

        }


    }



}