/*
Autor: Arthur Almeida Pereira
Data: 16/04/2026
Objetivo: Cadastrar e consultar funcionarios em Lista Simples
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// Definicao Estruturas de dados
typedef struct
{

    int codigo;
    char nome[50];
    float salario;
    char endereco[60];
    char dt_nasc[10];
    char telefone[15];
    char cpf[15];
    char cargo[40];
    char departamento[30];

} reg_funcionario;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem
{

    reg_funcionario     conteudo;
    TipoApontador   proximo;

} TipoItem;

typedef struct 
{

    TipoApontador   Primeiro;
    TipoApontador   Ultimo;

} TipoLista;

void gotoxy(int x, int y) 
{

    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Funcao de tela
void tela(){
    
    int l;
    int c;

    system("cls");

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
    printf("UNICV - 2 Semestre");
    gotoxy(62,2);
    printf("Estrutura de Dados");
    gotoxy(67,3);
    printf("Prof. Rodney");
    gotoxy(02,23);
    printf("MSG: ");

}

// Funcao para Limpar Mensagem
void limpar_msg()
{

    gotoxy(07,23);
    printf("                                                                      ");
    
}

// Funcao de Tela Padrao para Cadastro de Funcionario
void tela_Funcionario()
{

    gotoxy(24,4);
    printf("CADASTRO DE FUNCIONARIO");
    gotoxy(24,6);
    printf("CODIGO.............: ");
    gotoxy(24,7);
    printf("NOME...............: ");
    gotoxy(24,8);
    printf("SALARIO............: ");
    gotoxy(24,9);
    printf("ENDERECO...........: ");
    gotoxy(24,10);
    printf("DATA DE NASCIMENTO.: ");
    gotoxy(24,11);
    printf("TELEFONE...........: ");
    gotoxy(24,12);
    printf("CPF................: ");
    gotoxy(24,13);
    printf("CARGO..............: ");
    gotoxy(24,14);
    printf("DEPARTAMENTO.......: ");

}

// Funcao para Pesquisa Funcionario na Lista
TipoApontador pesquisa(TipoLista *TL, int cod)
{
    TipoApontador aux;

    aux = TL->Primeiro;

    while (aux != NULL)
    {
        if (aux->conteudo.codigo == cod)
        {
            return aux;
        }

        aux = aux->proximo;
    }

    return NULL;
}

// Funcao para Cadastro de Funcionario no Final da Lista
void cadastrar_Funcionario_Final( TipoLista *TL )
{

    int resp;

    do 
    {

        reg_funcionario func;
        int resultado;

        do
        {

            tela();
            tela_Funcionario();

            gotoxy(45,6);
            scanf("%d", &func.codigo);

            resultado = pesquisa (TL, func.codigo);

            if ( resultado != NULL ) 
            {

                gotoxy(07,23);
                printf("Este Codigo ja Existe!");
                getch();

            }

        } while ( resultado != NULL );

        gotoxy(45,7);
        fflush(stdin);
        gets(func.nome);

        gotoxy(45,8);
        scanf("%f", &func.salario);

        gotoxy(45,9);
        fflush(stdin);
        gets(func.endereco);

        gotoxy(45,10);
        gets(func.dt_nasc);

        gotoxy(45,11);
        gets(func.telefone);

        gotoxy(45,12);
        gets(func.cpf);

        gotoxy(45,13);
        gets(func.cargo);

        gotoxy(45,14);
        gets(func.departamento);

        gotoxy(07,23);
        printf("Deseja cadastrar o Funcionario no Final da Lista? ( 1 = Sim, 2 = Nao ) ");

        int confirma;

        scanf("%d", &confirma);
        limpar_msg();

        if ( confirma == 1 )
        {
            TipoApontador novo = ( TipoApontador ) malloc (sizeof(TipoItem));
            novo->conteudo = func;
            novo->proximo = NULL;

            if ( TL->Ultimo == NULL )
            {
                TL->Primeiro = novo;
                TL->Ultimo = novo;

            } else {

                TL->Ultimo->proximo = novo;
                TL->Ultimo = novo;

            }

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Funcionario Cadastrado no Final da Lista com Sucesso!");

        } else {

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Cadastro Cancelado!");

        }
        
        gotoxy(07,23);
        printf("Deseja sair do cadastro? ( 1 = Sim, 2 = Nao ) ");
        scanf("%d", &resp);
        
    } while ( resp == 2 );
}

// Funcao para Cadastro de Funcionario no Inicio da Lista
void cadastrar_Funcionario_Inicio( TipoLista *TL )
{

    int resp;

    do 
    {

        reg_funcionario func;
        int resultado;

        do
        {

            tela();
            tela_Funcionario();

            gotoxy(45,6);
            scanf("%d", &func.codigo);

            resultado = pesquisa (TL, func.codigo);

            if ( resultado != NULL ) 
            {

                gotoxy(07,23);
                printf("Este Codigo ja Existe!");
                getch();

            }

        } while ( resultado != NULL );

        gotoxy(45,7);
        fflush(stdin);
        gets(func.nome);

        gotoxy(45,8);
        scanf("%f", &func.salario);

        gotoxy(45,9);
        fflush(stdin);
        gets(func.endereco);

        gotoxy(45,10);
        gets(func.dt_nasc);

        gotoxy(45,11);
        gets(func.telefone);

        gotoxy(45,12);
        gets(func.cpf);

        gotoxy(45,13);
        gets(func.cargo);

        gotoxy(45,14);
        gets(func.departamento);

        gotoxy(07,23);
        printf("Deseja cadastrar o Funcionario no Inicio da Lista? ( 1 = Sim, 2 = Nao ) ");

        int confirma;

        scanf("%d", &confirma);
        limpar_msg();

        if ( confirma == 1 )
        {
            TipoApontador p = ( TipoApontador ) malloc (sizeof(TipoItem));
            p->conteudo = func;
            p->proximo = TL->Primeiro;
            TL->Primeiro = p;

            if ( TL->Ultimo == NULL )
            {
                
                TL->Ultimo = p;

            }

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Funcionario Cadastrado no Inicio da Lista com Sucesso!");

        } else {

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Cadastro Cancelado!");

        }
        
        gotoxy(07,23);
        printf("Deseja sair do cadastro? ( 1 = Sim, 2 = Nao ) ");
        scanf("%d", &resp);
        
    } while ( resp == 2 );
}

// Funcao para Cadastro de Funcionario em uma Posicao da Lista
void cadastrar_Funcionario_Posicao( TipoLista *TL )
{

    int resp;
    int pos_lista;

    do 
    {

        reg_funcionario func;
        int resultado;

        do
        {

            tela();
            tela_Funcionario();
            gotoxy(24,5);
            printf("POSICAO............: ");
            gotoxy(45,5);
            scanf("%d", &pos_lista);
            gotoxy(45,6);
            scanf("%d", &func.codigo);

            resultado = pesquisa (TL, func.codigo);

            if ( resultado != NULL ) 
            {

                gotoxy(07,23);
                printf("Este Codigo ja Existe!");
                getch();

            }

        } while ( resultado != NULL );

        gotoxy(45,7);
        fflush(stdin);
        gets(func.nome);

        gotoxy(45,8);
        scanf("%f", &func.salario);

        gotoxy(45,9);
        fflush(stdin);
        gets(func.endereco);

        gotoxy(45,10);
        gets(func.dt_nasc);

        gotoxy(45,11);
        gets(func.telefone);

        gotoxy(45,12);
        gets(func.cpf);

        gotoxy(45,13);
        gets(func.cargo);

        gotoxy(45,14);
        gets(func.departamento);

        gotoxy(07,23);
        printf("Deseja cadastrar o Funcionario na Posicao %d da Lista? ( 1 = Sim, 2 = Nao ) ", pos_lista);

        int confirma;

        scanf("%d", &confirma);
        limpar_msg();

        if ( confirma == 1 )
        {
            TipoApontador p = ( TipoApontador ) malloc (sizeof(TipoItem));
            p->conteudo = func;
            p->proximo = NULL;

            if ( pos_lista == 1 )
            {
                
                p->proximo = TL->Primeiro;
                TL->Primeiro = p;

                if ( TL->Ultimo == NULL )
                {
                    TL->Ultimo = p;
                }

            } else {

                TipoApontador atual = TL->Primeiro;

                int i;

                while ( atual != NULL && i < pos_lista - 1 )
                {

                    atual = atual->proximo;
                    i++;

                }

                if ( atual == NULL ) 
                {

                    gotoxy(24,7);
                    printf("Posicao Invalida!");
                    free(p);

                } else {

                    p->proximo = atual->proximo;
                    atual->proximo = p;

                    if ( p->proximo == NULL )
                    {
                        TL->Ultimo = p;
                    }
                }
            }

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Funcionario Cadastrado na Posicao %d da Lista com Sucesso!", pos_lista);

        } else {

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Cadastro Cancelado!");

        }
        
        gotoxy(07,23);
        printf("Deseja sair do cadastro? ( 1 = Sim, 2 = Nao ) ");
        scanf("%d", &resp);
        
    } while ( resp == 2 );
}

// Funcao para Remover Funcionario no Final da Lista
void remover_Funcionario_Final ( TipoLista *TL )
{
    
    
}

// Funcao para Remover Funcionario em um Posicao da Lista
void remover_Funcionario_Posicao ( TipoLista *TL )
{


}

// Funcao para Remover Funcionario no Inicio da Lista
void remover_Funcionario_Inicio ( TipoLista *TL )
{
        


}

// Funcao para Menu de Consultar
void menu_consultar_Funcionarios ( TipoLista *TL )
{

    int opcao;

    do
    {
        tela();

        gotoxy(24,7);
        printf("1 - Consultar em Lista");

        gotoxy(24,9);
        printf("2 - Consultar por Codigo Especifico");

        gotoxy(24,11);
        printf("3 - Consultar por Ordem Alfabetica");

        gotoxy(24,13);
        printf("4 - Consultar por Ordem De Codigo");

        gotoxy(24,15);
        printf("5 - Sair do Menu de Consulta");

        gotoxy(07,23);
        scanf("%d", &opcao);

        system("cls");

        switch ( opcao )
        {

            case 1:
                consultar_lista(&TL);
                break;
            case 2:
                consultar_codigo_unico(&TL);
                break;
            case 3:
                consultar_ordem_alfabetica(&TL);
                break;
            case 4:
                consultar_ordem_codigo(&TL);
                break;
            default:
                break;

        }

    } while ( opcao != 5 );
    
}

// Funcao para Consultar por Lista
void consultar_lista ( TipoLista *TL )
{
    

}

// Funcao para Alterar Funcionario da Lista
void alterar_Funcionario ( TipoLista *TL )
{


}

// Funcao para Gravar no Disco
void gravar_lista( TipoLista *TL )
{

    int i;
    FILE *ptr;
    char *Filename = "funcionarios.dat";
    char *modo_gravacao = "wb";
    reg_funcionario func;

    ptr = fopen ( Filename, modo_gravacao );

    if ( ptr == NULL )
    {

        tela();
        gotoxy(25,03);
        printf("Erro ao Abrir Arquivo para Gravacao!");
        return;

    }

    TipoApontador aux = TL->Primeiro;

    while ( aux != NULL ) 
    {

        fwrite ( &aux->conteudo, sizeof(reg_funcionario), 1, ptr);
        aux = aux->proximo;

    }

    fclose ( ptr );

    tela();
    gotoxy(25,03);
    printf("Dados Gravados com Sucesso!");
    getch();

}

// Funcao para Ler os Arquivos do Disco
void le_arquivo_lista ( TipoLista *TL )
{

    FILE *ptr;
    char *Filename = "funcionarios.dat";
    char *modo_leitura = "rb";

    ptr = fopen ( Filename, modo_leitura );
    if ( ptr == NULL ) 
    {

        TL->Primeiro = NULL;
        TL->Ultimo = NULL;

        tela();
        gotoxy(25,03);
        printf("Nenhum Arquivo Encontrado. Lista Iniciada Vazia!");
        getch();
        return;

    }

    reg_funcionario func;
    
    while ( fread ( &func, sizeof(reg_funcionario), 1,  ptr ) == 1 )
    {

        TipoApontador p = ( TipoApontador ) malloc (sizeof( TipoItem ));
        p->conteudo = func;
        p->proximo = NULL;

        if ( TL->Primeiro == NULL )
        {

            TL->Primeiro = p;

        } else {

            TL->Ultimo->proximo = p;

        }

        TL->Ultimo = p;

    }

    fclose ( ptr );

    tela();
    gotoxy(25,03);
    printf("Dados Carregados do Arquivo com Sucesso!");
    getch();

}

// Programa Principal
int main()
{

    // Variaveis inicializadas no Main ( Programa principal )
    int opcao;
    TipoLista TL;
    TL.Primeiro = NULL;
    TL.Ultimo = NULL;

    // Carregar dados guardados no Disco
    le_arquivo_lista(&TL);

    // Layout
    system("color 17");
    system("cls");
    
    // Hub do programa
    do
    {
        tela();
        gotoxy(24,7);
        printf("1 - Cadastrar funcionario no Final da Lista");
        gotoxy(24,8);
        printf("2 - Cadastrar funcionario no Inicio da Lista");
        gotoxy(24,9);
        printf("3 - Cadastrar funcionario em uma Posicao da Lista");
        gotoxy(24,10);
        printf("4 - Remover funcionario no Final da Lista");
        gotoxy(24,11);
        printf("5 - Remover funcionario em uma Posicao da Lista");
        gotoxy(24,12);
        printf("6 - Remover funcionario no Inicio da Lista");
        gotoxy(24,13);
        printf("7 - Consultar Todos os Funcionarios");
        gotoxy(24,14);
        printf("8 - Alterar Dados de Funcionarios");
        gotoxy(24,15);
        printf("9 - Finalizar Programa");

        gotoxy(07,23);
        scanf("%d", &opcao);

        system("cls");

        switch(opcao)
        {

            case 1:
                cadastrar_Funcionario_Final(&TL);
                break;
            case 2:
                cadastrar_Funcionario_Inicio(&TL);
                break;
            case 3:
                cadastrar_Funcionario_Posicao(&TL);
                break;
            /*
            case 4:
                remover_Funcionario_Final(&TL);
                break;
            case 5:
                remover_Funcionario_Posicao(&TL);
                break;
            case 6:
                remover_Funcionario_Inicio(&TL);
                break;
            case 7:
                menu_consultar_Funcionarios(&TL); Consultar em fichario e lista ( ordem alfabetica ou codigo )
                break;
            case 8:
                alterar_Funcionario(&TL);
                break;
                */
            default:
                break;
        }
        
    } while ( opcao != 9 );

    gravar_lista(&TL);

    return 0;

}
