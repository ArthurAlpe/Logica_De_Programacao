/*
Autor: Arthur Almeida Pereira
Data: 28/03/2026
Objetivo: Agendar corte ( Barbearia )
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAX 50

// Estrutura

typedef struct
{
    int codigo;
    char nome_cliente[40];
    char telefone_cliente[16];
    char horario[5];

} reg_clientes;

typedef struct
{

    reg_clientes lista[MAX];
    int inicio;
    int fim;

} Clientes;

// Funcao para inicializar a lista
void inicializa_lista ( Clientes *C ) 
{
    C->inicio = 0;
    C->fim = 0;

}

// Funcao gotoxy
void gotoxy ( int x, int y )
{

    COORD coord;
    coord.X = ( short ) x;
    coord.Y = ( short ) y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

// Funcao para tela
void tela()
{

    int L;
    int C;

    system("cls");

    for ( L = 1; L < 25; L++ )
    {

        gotoxy(01,L);
        printf("|");

        gotoxy(80,L);
        printf("|");

    }

    for ( C = 1; C < 81; C++ )
    {

        gotoxy(C,01);
        printf("-");

        gotoxy(C,04);
        printf("-");

        gotoxy(C,22);
        printf("-");

        gotoxy(C,24);
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
    printf("UNICV - 2 Semestre");

    gotoxy(2,3);
    printf("Arthur");

    gotoxy(62,2);
    printf("Estrutura de Dados");

    gotoxy(02,23);
    printf("MSG: ");

}

// Funcao de cliente
void telaRegistro_Cliente()
{

    gotoxy(24,5);
    printf("AGENDAMENTO DE CORTE");

    gotoxy(24,7);
    printf("CODIGO...: ");

    gotoxy(24,9);
    printf("NOME.....: ");

    gotoxy(24,11);
    printf("TELEFONE.: ");

    gotoxy(24,13);
    printf("HORARIO..: ");

}

// Funcao para pesquisa
int pesquisa ( Clientes *C, int cod ) 
{

    int i;

    for ( i = 0; i < C->fim; i++ )
    {
        if ( C->lista[i].codigo == cod)
        {
            return 1;
        }
    }

    return -1;

}

// Funcao para o cadastro/agendamento do cliente
void agendar_cliente ( Clientes *C ) 
{

    int resp;

    if ( C->fim >= MAX )
    {

        gotoxy(24,5);
        printf("Lista cheia!\n");
        return;

    }

    do 
    {

        reg_clientes cliente;
        int result;

        do
        {

            tela();

            telaRegistro_Cliente();

            gotoxy(45,7);
            scanf("%d", &cliente.codigo);

            result = pesquisa ( C, cliente.codigo );
            if ( result != -1 )
            {

                gotoxy(07,23);
                printf("Codigo ja existe.");
                getch();

            }

        } while ( result != -1 );

        gotoxy(45,9);
        fflush(stdin);
        gets(cliente.nome_cliente);

        gotoxy(45,11);
        gets(cliente.telefone_cliente);

        gotoxy(45,13);
        gets(cliente.horario);

        gotoxy(07,23);
        printf("Deseja agendar o cliente? ( 1 = Sim, 2 = Nao ) ");

        int confirma;

        scanf("%d", &confirma);

        limpar();

        if ( confirma == 1 ) 
        {

            if ( C->fim < MAX )
            {

                C->lista[C->fim] = cliente;
                C->fim++;

                gotoxy(24,7);
                printf("Cliente agendado com sucesso!");

            } else {

                gotoxy(24,7);
                printf("Lista cheia, nao e possivel agendar!");

            }

        } else {

            gotoxy(24,7);
            printf("Agendamento cancelado!");

        }

        gotoxy(07,23);
        printf("Deseja sair do agendamento? ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 2 );

}

// Funcao para alterar o agendamento
void alterar_cliente ( Clientes *C )
{

    int resp;
    int codigo;
    int opcao;

    do
    {

        tela();

        gotoxy(24,5);
        printf("ALTERACAO DE CLIENTE");

        gotoxy(24,7);
        printf("DIGITE O CODIGO.: ");
        
        gotoxy(45,7);
        scanf("%d", &codigo);
        fflush(stdin);
        

        int encontrado = 0;

        for ( int i = 0; i < C->fim; i++ )
        {

            if ( C->lista[i].codigo == codigo )
            {

                encontrado = 1;

                telaRegistro_Cliente();

                gotoxy(21,9);
                printf("1");

                gotoxy(45,9);
                printf(" %s", C->lista[i].nome_cliente);

                gotoxy(21,11);
                printf("2");

                gotoxy(45,11);
                printf(" %s", C->lista[i].telefone_cliente);

                gotoxy(21,13);
                printf("3");

                gotoxy(45,13);
                printf(" %s", C->lista[i].horario);

                gotoxy(07,23);
                printf("Deseja alterar qual informacao? ");

                gotoxy(56,21);
                scanf("%d", &opcao);
                getchar();

                switch ( opcao )
                {

                    case 1:
                        
                        gotoxy(24,9);
                        printf("NOME ATUAL.: %s", C->lista[i].nome_cliente);

                        gotoxy(24,10);
                        printf("NOME NOVO..: ");

                        // Alteracao do nome

                        gotoxy(45,10);
                        scanf(" %[^\n]", C->lista[i].nome_cliente);

                        break;
                    
                    case 2:

                        gotoxy(24,11);
                        printf("TELEFONE ATUAL.: %s", C->lista[i].telefone_cliente);

                        gotoxy(24,12);
                        printf("TELEFONE NOVO.: ");

                        // Alteracao de telefone

                        gotoxy(45,12);
                        scanf(" %[^\n]", C->lista[i].telefone_cliente);

                        break;
                    
                    case 3:

                        gotoxy(24,13);
                        printf("HORARIO ATUAL.: %s", C->lista[i].horario);

                        printf("24,14");
                        printf("HORARIO NOVO.: ");

                        // Alteracao de horario

                        gotoxy(45,14);
                        scanf(" %[^\n]", C->lista[i].horario);

                        break;
                    
                    default:

                        break;
                    
                }
            }
        }

        if ( !encontrado )
        {

            gotoxy(24,9);
            printf("Cliente nao encontrado!");

        }

        gotoxy(07,23);
        printf("Deseja sair da alteracao? ( 1 = Sim, 2 = Nao ) ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 2 );

}

// Funcao para consultar agendamento
void consultar_cliente ( Clientes *C )
{

    int resp;
    int codigo;

    do
    {

        tela();
        
        gotoxy(24,5);
        printf("CONSULTA DE CLIENTE");

        gotoxy(24,7);
        printf("CODIGO.: ");

        gotoxy(45,7);
        scanf("%d", &codigo);

        int encontrado = 0;

        for ( int i = 0; i < C->fim; i++ )
        {

            if ( C->lista[i].codigo == codigo )
            {

                encontrado = 1;

                telaRegistro_Cliente();

                gotoxy(45,9);
                printf(" %s", C->lista[i].nome_cliente);

                gotoxy(45,11);
                printf(" %s", C->lista[i].telefone_cliente);

                gotoxy(45,13);
                printf(" %s", C->lista[i].horario);

                break;

            }
        }

        if ( !encontrado )
        {

            gotoxy(24,9);
            printf("Cliente nao encontrado! ");

        }

        gotoxy(07,23);
        printf("Deseja sair da consulta? ( 1 = Sim, 2 = Nao ) ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 2 );

}

// Funcao para excluir agendamento
void excluir_cliente ( Clientes *C )
{

    int resp;
    int codigo;

    do
    {
       tela();
       
       gotoxy(24,5);
       printf("EXCLUSAO DE CLIENTE");

       gotoxy(24,7);
       printf("CODIGO.: ");
       
       gotoxy(45,7);
       scanf("%d", &codigo);

       int encontrado = 0;

       for ( int i = 0; i < C->fim; i++ )
       {
            if ( C->lista[i].codigo == codigo ) 
            {
                encontrado = 1;

                telaRegistro_Cliente();

                gotoxy(56,9);
                printf(" %s", C->lista[i].nome_cliente);

                gotoxy(56,11);
                printf(" %s", C->lista[i].telefone_cliente);

                gotoxy(56,13);
                printf(" %s", C->lista[i].horario);

                gotoxy(24,5);
                printf("CONFIRMAR EXCLUSAO? ( 1 = Sim, 2 = Nao ) ");
                int confirma;
                scanf("%d", &confirma);

                if ( confirma == 1 ) 
                {

                    // Desloca os elementos para tras

                    for ( int j = i; j < C->fim - 1; j++ )
                    {
                        C->lista[j] = C->lista[j+1];

                    }

                    C->fim--;

                    gotoxy(24,7);
                    printf("Cliente excluido com sucesso!");


                } else {

                    gotoxy(24,7);
                    printf("Exclusao cancelada!");

                }

                break;

            }
       }

       if ( !encontrado ) 
       {
            
            gotoxy(24,9);
            printf("Cliente nao encontrado!");

       }

       gotoxy(07,23);
       printf("Deseja excluir outro cliente? ( 1 = Sim, 2 = Nao ) ");
       scanf("%d", &resp);
       system("cls");

    } while ( resp == 1 );

}

// Funcao para limpar mensagem
void limpar()
{

    gotoxy(07,23);
    printf("                                                      ");

}

// Funcao para ordenar os clientes por codigo
void ordenar_codigo ( Clientes *C )
{

    int i;
    int j;
    reg_clientes    auxiliar;

    for ( i = 0; i < C->fim-1; i++ )
    {
        for ( j = i + 1; j < C->fim; j++ )
        {
            if ( C->lista[i].codigo > C->lista[j].codigo )
            {

                auxiliar = C->lista[i];
                C->lista[i] = C->lista[j];
                C->lista[j] = auxiliar;

            }
        }
    }
}

// Funcao para ordenar de forma alfabetica os clientes
void alfabetica_cliente ( Clientes *C )
{

    int i;
    int j;
    int lin = 7;
    reg_clientes auxiliar;

    // Ordena os clientes por nome ( Bubble Sort )
    for ( i = 0; i < C->fim - 1; i++ )
    {

        for ( j = i + 1; j < C->fim; j++ ) 
        {

            if ( strcmp ( C->lista[i].nome_cliente, C->lista[j].nome_cliente) > 0 )
            {
                auxiliar = C->lista[i];
                C->lista[i] = C->lista[j];
                C->lista[j] = auxiliar;

            }
        }
    }

    tela();

    gotoxy(10,3);
    printf("-- Clientes por Ordem Alfabetica --");

    gotoxy(2,5);
    printf("Codigo.: ");

    gotoxy(8,5);
    printf("Nome.: ");

    gotoxy(36,5);
    printf("Telefone.: ");

    gotoxy(50,5);
    printf("Horario.: ");

    gotoxy(2,6);
    printf("---  --------------------------- -----------    ------------     ------------");

    for ( i = 0; i < C->fim; i++ )
    {

        gotoxy(3, lin);
        printf("%d", C->lista[i].codigo);

        gotoxy(8, lin);
        printf(" %s", C->lista[i].nome_cliente);

        gotoxy(33, lin);
        printf(" %s", C->lista[i].telefone_cliente);

        gotoxy(50, lin);
        printf(" %s", C->lista[i].horario);

        lin++;

        if ( lin > 22 ) 
        {

            tela();

            gotoxy(10,3);
            printf("-- Clientes por Ordem Alfabetica --");

            gotoxy(2,4);
            printf("Codigo.: ");

            gotoxy(8,4);
            printf("Nome.: ");

            gotoxy(36,4);
            printf("Telefone.: ");
            
            gotoxy(50,4);
            printf("Horario.: ");

            getch();

            lin = 7;

        }
    }

    getch();

}

// Funcao que lista clientes em ordem de codigo
void lista_codigo( Clientes *C )
{

    int i;
    int lin = 7;

    // Chama a funcao de ordenacao
    ordenar_codigo(C);

    tela();

    gotoxy(10,03);
    printf("-- Clientes por Ordem de Codigo --");

    gotoxy(02,5);
    printf("Codigo.: ");

    gotoxy(8,5);
    printf("Nome.: ");

    gotoxy(36,5);
    printf("Telefone.: ");

    gotoxy(50,5);
    printf("Horario.: ");

    gotoxy(02,6);
    printf("---  --------------------------- -----------    ------------     ------------");

    for ( i = 0; i < C->fim; i++ )
    {

        gotoxy(03, lin);
        printf("%d", C->lista[i].codigo);

        gotoxy(8, lin);
        printf(" %s", C->lista[i].nome_cliente);

        gotoxy(33, lin);
        printf(" %s", C->lista[i].telefone_cliente);

        gotoxy(50, lin);
        printf(" %s", C->lista[i].horario);

        lin++;

        if ( lin > 22 )
        {

            gotoxy(10,03);
            printf("-- Clientes por Ordem de Codigo --");

            gotoxy(02,5);
            printf("Codigo.: ");

            gotoxy(8,5);
            printf("Nome.: ");

            gotoxy(36,5);
            printf("Telefone.: ");

            gotoxy(50,5);
            printf("Horario.: ");

            getch();

        }
    }

    getch();

}

// Funcao para Mostrar o Menu de Consulta
void menu_consultar ( Clientes *C ) 
{

    int opcao;

    do
    {

        tela();

        gotoxy(20,03);
        printf("--- MENU DE CONSULTAS ---");

        gotoxy(21,9);
        printf("1 - Cliente por Codigo Especifico");
        gotoxy(21,12);
        printf("2 - Lista de Clientes em Ordem Alfabetica");
        gotoxy(21,15);
        printf("3 - Lista de Clientes em Ordem de Codigo");
        gotoxy(21,18);
        printf("4 - Retorna ao Menu Anterior");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        switch ( opcao )
        {

            case 1:

                consultar_cliente(C);
                break;
            
            case 2:

                alfabetica_cliente(C);
                break;
            
            case 3:

                lista_codigo(C);
                break;
            
            case 4:

                tela();
                break;
            
            default:

                break;
            
        }

    } while ( opcao == 4 );

}

// Funcao para Gravar no Disco
void gravar ( Clientes *C )
{

    int i;
    FILE *ptr;
    char *Filename = "agendamento.dat";
    char *modo_gravacao = "wb";
    reg_clientes clientes;

    ptr = fopen ( Filename, modo_gravacao );

    if ( ptr == NULL )
    {

        tela();
        gotoxy(25,03);
        printf("Erro ao abrir o arquivo para gravacao!");
        return;

    }

    // Um comando de repeticao para gravar todos os clientes da lista
    for ( i = 0; i < C->fim; i++ ) 
    {

        fwrite ( &C->lista[i], sizeof ( reg_clientes ), 1, ptr );

    }

    fclose ( ptr );

    tela();

    gotoxy(25,03);;
    printf("Dados gravados com sucesso!");
    getch();

}

// Funcao para ler os arquivos do disco
void ler_arquivo ( Clientes *C )
{

    FILE *ptr;
    char *Filename = "agendamento.dat";
    char *modo_leitura = "rb";

    ptr = fopen ( Filename, modo_leitura );
    if ( ptr == NULL )
    {

        // Um comando simples para se caso não existir arquivo, apenas inicializa a lista
        C->inicio = 0;
        C->fim = 0;

        tela();

        gotoxy(25,03);
        printf("Nenhuma arquivo encontrado. Lista iniciada vazia.");
        getch();
        return;

    }

    reg_clientes clientes;
    C->inicio = 0;
    C->fim = 0;

    while ( fread ( &clientes, sizeof ( reg_clientes ), 1, ptr ) == 1 )
    {

        if ( C->fim < MAX ) 
        {

            C->lista[C->fim] = clientes;
            C->fim++;

        }

    }

    fclose ( ptr );

    tela();
    
    gotoxy(25,03);
    printf("Dados carregados do arquivo com sucesso!");
    getch();

}   

// Programa principal
int main()
{
    // Declara variaveis
    Clientes C;
    int opcao;
    inicializa_lista(&C);

    // Carrega os dados guardados no arquivo
    ler_arquivo(&C);

    system("color 20");
    system("cls");

    do
    {

        tela();

        gotoxy(24,7);
        printf("AGENDAMENTO DE CLIENTES");

        gotoxy(24,9);
        printf("1 - AGENDAR");

        gotoxy(24,11);
        printf("2 - ALTERAR");

        gotoxy(24,13);
        printf("3 - CONSULTAR");

        gotoxy(24,15);
        printf("4 - EXCLUIR");

        gotoxy(24,17);
        printf("5 - FINALIZAR O PROGRAMA");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        system("cls");

        switch ( opcao )
        {

            case 1:

                agendar_cliente(&C);
                break;
            
            case 2:

                alterar_cliente(&C);
                break;
            
            case 3:

                menu_consultar(&C);
                break;
            
            case 4:

                excluir_cliente(&C);
                break;

            default:

                break;
            
        }

    } while ( opcao != 5 );

    gravar(&C);

    return 0;
}