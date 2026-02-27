/*
Autor: Arthur Almeida Pereira
Data: 18/10/2025
Objetivo: Tela de cadastro
*/

#include <stdio.h>
#include <windows.h>

//Funcao para tela
void tela(){

    int c;
    int l;

    for ( l = 1; l < 25; l++) {
        gotoxy(01,l);
        printf("|");
        gotoxy(80,l);
        printf("|");
    }
    
    for ( c = 1; c < 81; c++) {
        gotoxy(c,01);
        printf("-");
        gotoxy(c,04);
        printf("-");
        gotoxy(c,22);
        printf("-");
        gotoxy(c,24);
        printf("-");
    }

    gotoxy(01,1);
    printf("+");
    gotoxy(80,1);
    printf("+");
    gotoxy(1,22);
    printf("+");
    gotoxy(1,24);
    printf("+");
    gotoxy(80,24);
    printf("+");
    gotoxy(80,22);
    printf("+");
    gotoxy(01,4);
    printf("+");
    gotoxy(80,4);
    printf("+");
    gotoxy(2,2);
    printf("UNICV");
    gotoxy(2,3);
    printf("Arthur Almeida Pereira 2 Semestre ADS/ESW");
    gotoxy(62,2);
    printf("Estrutura de Dados");
    gotoxy(67,3);
    printf("Prof. Rodney");
}
//Funcao para gotoxy
void gotoxy(int x, int y) 
{

    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Programa principal
int main (){

    //Variaveis
    int opcao;
    char nome[50];
    int idade;
    char email[50];

    //Começo do programa

    system("color 02");
    system("cls");

    tela();
    gotoxy(24,5);
    printf("TELA DE CADASTRO");
    gotoxy(24,9);
    printf("1 - Cadastrar o aluno");
    gotoxy(24,11);
    printf("2 - Consultar o aluno");
    gotoxy(24,13);
    printf("3 - Editar o cadastro");
    gotoxy(24,15);
    printf("4 - Excluir cadastro");
    gotoxy(24,17);
    printf("5 - MENU");
    gotoxy(02,23);
    printf("MSG: ");
    gotoxy(07,23);
    scanf("%d", &opcao);

    while (opcao != 0) { 
        
        system("cls");

        switch (opcao) {

            case 1:
            system("cls");
            tela();
            
            gotoxy(24,5);
            printf("TELA DE CADASTRO");

            gotoxy(24,9);
            printf("Nome: ");
            gotoxy(24,11);
            printf("Idade: ");
            gotoxy(24,13);
            printf("Email: ");
            gotoxy(30,9);
            fflush(stdin);
            fgets(nome, 50, stdin);
            gotoxy(31,11);
            scanf("%d", &idade);  

            gotoxy(31,13);
            fflush(stdin);
            fgets(email, 50, stdin);

            gotoxy(24,15);
            printf("Cadastro feito com sucesso!");

            gotoxy(24,17);
            printf("5 - MENU");

            gotoxy(02,23);
            printf("MSG: ");
            gotoxy(07,23);
            scanf("%d", &opcao);

            system("cls");

            break;

            case 2:
            system("cls");
            
            tela();
            gotoxy(24,9);
            printf("Nome: %s", nome);
            gotoxy(24,11);
            printf("Idade: %d", idade);
            gotoxy(24,13);
            printf("Email: %s", email);
            gotoxy(24,15);
            printf("Consulta feita com sucesso!");
            gotoxy(24,17);
            printf("5 - MENU");
            gotoxy(02,23);
            printf("MSG: ");
            gotoxy(07,23);
            scanf("%d", &opcao);
            
            system("cls");

            break;
            
            case 3:
            system("cls");
            tela();
            
            gotoxy(24,5);
            printf("TELA DE CADASTRO");

            gotoxy(24,9);
            printf("Nome: ");
            gotoxy(24,11);
            printf("Idade: ");
            gotoxy(24,13);
            printf("Email: ");

            gotoxy(30,9);
            fflush(stdin);
            fgets(nome, 50, stdin);

            gotoxy(31,11);
            scanf("%d", &idade);

            gotoxy(31,13);
            fflush(stdin);
            fgets(email, 50, stdin);

            gotoxy(24,15);
            printf("Cadastro novo feito com sucesso!");

            gotoxy(24,17);
            printf("5 - MENU");

            gotoxy(02,23);
            printf("MSG: ");
            gotoxy(07,23);
            scanf("%d", &opcao);

            system("cls");

            break;

            case 4:
            system("cls");

            nome[0] = '\0';
            idade = 0;
            email[0] = '\0';

            gotoxy(24,11);
            printf("Cadastro excluido com sucesso!\n");

            tela();
            
            gotoxy(24,5);
            printf("TELA DE CADASTRO");
            gotoxy(24,9);
            printf("1 - Cadastrar o aluno");
            gotoxy(24,11);
            printf("2 - Consultar o aluno");
            gotoxy(24,13);
            printf("3 - Editar o cadastro");
            gotoxy(24,15);
            printf("4 - Excluir cadastro");
            gotoxy(24,17);
            printf("5 - MENU");
            gotoxy(24,17);
            printf("0 - Sair");
            gotoxy(02,23);
            printf("MSG: ");
            gotoxy(07,23);
            scanf("%d", &opcao);

            system("cls");
            break;

            case 5:

            system("cls");

            tela();
            
            gotoxy(24,5);
            printf("TELA DE CADASTRO");
            gotoxy(24,9);
            printf("1 - Cadastrar o aluno");
            gotoxy(24,11);
            printf("2 - Consultar o aluno");
            gotoxy(24,13);
            printf("3 - Editar o cadastro");
            gotoxy(24,15);
            printf("4 - Excluir cadastro");
            gotoxy(24,19);
            printf("0 - Sair");
            gotoxy(02,23);
            printf("MSG: ");
            gotoxy(07,23);
            scanf("%d", &opcao);

            system("cls");

            default:
            break;

        }


    }



}