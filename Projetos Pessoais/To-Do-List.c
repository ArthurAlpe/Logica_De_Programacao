/*
Autor: Arthur Almeida Pereira
Data: 17/03/2026
Objetivo: Lista de tarefas
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 30 // Capacidade da lista

typedef struct {

    // Vetor para armazenar os dados

    char tarefa[50];
    int codigo;
    char data[10];
    char horario[6];
    char quantidade[5];
    char desc_tarefa[30];

} reg_tarefas;

typedef struct {

    reg_tarefas ficha[MAX];
    int inicio;
    int fim;

} Tarefas;

void inicializa_Tarefa ( Tarefas *T ) {

    T->inicio = 0;
    T->fim = 0;

}

// Funcao para tela
void layout(){
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
    printf("Arthur Almeida Pereira");
    gotoxy(62,2);
    printf("Estrutura de Dados");
    gotoxy(02,23);
    printf("MSG: ");

}

// Funcao GOTOXY, funcao para setar onde o cursor vai ir
void gotoxy(int x, int y) 
{

    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Funcao para pesquisa
int pesquisa(Tarefas *T, int cod) {

    int i;
    for (i = 0; i < T->fim; i++) {
        if(T->ficha[i].codigo == cod) {
            return i;
        }
    }
    return -1;
}

// TELA DE CADASTRO DE TAREFA
void layout_Tarefa() {

    gotoxy(24,5);
    printf("CRIAR TAREFA");

    gotoxy(24,7);
    printf("CODIGO.....: ");

    gotoxy(24,9);
    printf("TAREFA.....: ");

    gotoxy(24,11);
    printf("DESCRICAO..: ");

    gotoxy(24,13);
    printf("QUANTIDADE.: ");

    gotoxy(24,15);
    printf("DATA.......: ");

    gotoxy(24,17);
    printf("HORARIO....: ");


}

// Funcao para cadastrar uma tarefa
void criar_Tarefa( Tarefas *T ){

    int resp;

    if ( T->fim >= MAX ) {
        gotoxy(24,5);
        printf("Lista Cheia!");
        return;
    }

    do {
        reg_tarefas taref;
        int result;

        // Garante que o código seja único
        do {
            layout();
            layout_Tarefa();

            gotoxy(45,7);
            scanf("%d", &taref.codigo);

            result = pesquisa(T, taref.codigo);
            if ( result != -1 ) {
                gotoxy(07,23);
                printf("Codigo ja Existe.");
                getch();
            }
        } while ( result != -1 );

        // Preenche os campos
        gotoxy(40,9); 
        fflush(stdin); 
        gets(taref.tarefa);

        gotoxy(40,11); 
        gets(taref.desc_tarefa);

        gotoxy(40,13); 
        gets(taref.quantidade);

        gotoxy(40,15); 
        gets(taref.data);

        gotoxy(40,17); 
        gets(taref.horario);

        // Adiciona direto na lista
        if ( T->fim < MAX ) {
            T->ficha[T->fim] = taref;
            T->fim++;
            gotoxy(24,7);
            printf("Tarefa criada com sucesso!");
        }

        gotoxy(07,23);
        printf("Deseja criar outra tarefa? (1 = Sim, 2 = Nao): ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 1 );
}

void alterar_Tarefa ( Tarefas *T ) {

    int resp;
    int codigo;
    int opcao;

    do {
        layout();

        gotoxy(24,5);
        printf("ALTERACAO DE TAREFA");

        gotoxy(24,7);
        printf("DIGITE O CODIGO.: ");
        
        gotoxy(45,7);
        scanf("%d", &codigo);
        fflush(stdin);

        int encontrado = 0;

        for ( int i = 0; i < T->fim; i++) {
            if ( T->ficha[i].codigo == codigo ) {

                encontrado = 1;

                layout_Tarefa();

                gotoxy(21,9);
                printf("1");

                gotoxy(40,9);
                printf(" %s", T->ficha[i].tarefa);

                gotoxy(21,11);
                printf("2");

                gotoxy(40,11);
                printf(" %s", T->ficha[i].desc_tarefa);

                gotoxy(21,13);
                printf("3");

                gotoxy(40,13);
                printf(" %s", T->ficha[i].quantidade);

                gotoxy(21,15);
                printf("4");

                gotoxy(40,15);
                printf(" %s", T->ficha[i].data);

                gotoxy(21,17);
                printf("5");

                gotoxy(40,17);
                printf(" %s", T->ficha[i].horario);

                gotoxy(07,23);
                printf("Deseja alterar qual informacao? ");

                gotoxy(56,21);
                scanf("%d", &opcao);
                getchar();

                switch ( opcao ) {

                    case 1:
                        gotoxy(24,9);
                        printf("TAREFA ATUAL....: %s", T->ficha[i].tarefa);

                        gotoxy(24,10);
                        printf("TAREFA NOVA.....: ");

                        // Tarefa

                        gotoxy(40,10);
                        scanf(" %[^\n]", T->ficha[i].tarefa);
                        
                        break;

                    case 2:

                        gotoxy(24,11);
                        printf("DESCRICAO ATUAL.: %s", T->ficha[i].desc_tarefa);

                        gotoxy(24,12);
                        printf("DESCRICAO NOVA..: ");

                        // Descricao nova

                        gotoxy(40,12);
                        scanf(" %[^\n]", T->ficha[i].desc_tarefa);

                        break;

                    case 3:

                        gotoxy(24,13);
                        printf("QUANTIDADE ATUAL: %s", T->ficha[i].quantidade);

                        gotoxy(24,14);
                        printf("QUANTIDADE NOVA.: ");

                        // Quantidade nova

                        gotoxy(40,14);
                        scanf(" %[^\n]", T->ficha[i].quantidade);

                        break;
                    
                    case 4:

                        gotoxy(24,15);
                        printf("DATA ATUAL......: %s", T->ficha[i].data);

                        gotoxy(24,16);
                        printf("DATA NOVA.......: ");

                        // Data nova

                        gotoxy(40,16);
                        scanf(" %[^\n]", T->ficha[i].data);

                        break;

                    case 5:

                        gotoxy(24,17);
                        printf("HORARIO ATUAL...: %s", T->ficha[i].horario);

                        gotoxy(24,18);
                        printf("HORARIO NOVO....: ");

                        // Horario novo

                        gotoxy(40,18);
                        scanf(" %[^\n]", T->ficha[i].horario);

                        break;

                    default:

                        break;
                    
                }
            }
        }

        if ( !encontrado ) {

            gotoxy(24,9);
            printf("Tarefa nao encontradao!");

        }

        gotoxy(07,23);
        printf("Deseja sair da alteracao? ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 2 );
}

void consulta_Tarefa ( Tarefas *T ) {

    int resp;
    int codigo;

    do {

        layout();

        gotoxy(24,5);
        printf("CONSULTA DE TAREFA");

        gotoxy(24,7);
        printf("CODIGO.: ");

        gotoxy(40,7);
        scanf("%d", &codigo);

        int encontrado = 0;

        for ( int i = 0; i < T->fim; i++ ) {

            if ( T->ficha[i].codigo == codigo ) {
                encontrado = 1;

                layout_Tarefa();

                gotoxy(40,9);
                printf(" %s", T->ficha[i].tarefa);

                gotoxy(40,11);
                printf(" %s", T->ficha[i].desc_tarefa);

                gotoxy(40,13);
                printf(" %s", T->ficha[i].quantidade);

                gotoxy(40,15);
                printf(" %s", T->ficha[i].data);

                gotoxy(40,17);
                printf(" %s", T->ficha[i].horario);

                break;

            }
        }

        if ( !encontrado ) {
            gotoxy(24,9);
            printf("Tarefa nao encontrada!");

        }

        gotoxy(07,23);
        printf("Deseja sair da consulta ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 2 );

}

void exclusao_Tarefa ( Tarefas *T ) {

    int resp;
    int codigo;

    do {

        layout();

        gotoxy(24,5);
        printf("EXCLUSAO DE TAREFA");

        gotoxy(24,7);
        printf("codigo.............: ");

        gotoxy(40,7);
        scanf("%d", &codigo);

        int encontrado = 0;

        for ( int i = 0; i < T->fim; i++ ) {
            if ( T->ficha[i].codigo == codigo ) {

                encontrado = 1;

                layout_Tarefa();

                gotoxy(56,9);
                printf(" %s", T->ficha[i].tarefa);

                gotoxy(56,11);
                printf(" %s", T->ficha[i].desc_tarefa);

                gotoxy(56,13);
                printf(" %s", T->ficha[i].quantidade);

                gotoxy(56,15);
                printf(" %s", T->ficha[i].data);

                gotoxy(56,17);
                printf(" %s", T->ficha[i].horario);

                gotoxy(24,5);
                printf("CONFIRMA EXCLUSAO? ( 1 = Sim, 2 = Nao ) ");
                int confirma;
                scanf("%d", &confirma);

                if ( confirma == 1 ) {
                    // Desloca os elementos para tras

                    for ( int j = i; j < T->fim - 1; j++ ) {
                        T->ficha[j] = T->ficha[j+1];
                    
                    }
                    T->fim--;

                    gotoxy(24,7);
                    printf("Tarefa excluida com sucesso!");

                } else {

                    gotoxy(24,7);
                    printf("Exclusao cancelada");

                }

                break;
            }
        }

        if ( !encontrado ) {
            gotoxy(24,9);
            printf("Tarefa nao encontrada");

        }

        gotoxy(07,23);
        printf("Deseja excluir outra tarefa? ( 1 = Sim, 2 = Nao ) ");
        scanf("%d", &resp);
        system("cls");

    } while ( resp == 1 );

}

void limpar() {

    gotoxy(07,23);
    printf("                                                     ");
}

// Funcao para Gravar no Disco
void gravar( Tarefas *T ) {

    int i;
    FILE *ptr;
    char *Filename = "tarefas.dat";
    char *modo_gravacao = "wb";

    ptr = fopen ( Filename, modo_gravacao );  // Abre para escrita binaria
        
    if ( ptr == NULL ) {
        layout();
        gotoxy(25,03);
        printf("Erro ao abrir arquivo para gravacao!");
        return;
    }

    // Um comando de repeticao para gravar todas as tarefas da lista
    for ( i = 0; i < T->fim; i++ ) {
            
        fwrite(&T->ficha[i], sizeof(reg_tarefas), 1, ptr);

    }

    fclose( ptr ) ;

    layout();
    gotoxy(25,03);
    printf("Dados gravados com sucesso!");
    getch();
}

// Funcao para Ler os Arquivos do Disco
void le_arquivo( Tarefas *T ) {

    FILE *ptr;
    char *Filename = "tarefas.dat";
    char *modo_leitura = "rb";
    

    ptr = fopen( Filename, modo_leitura ); // Desta maneira, ele faz a leitura binaria
    if ( ptr == NULL ) {

        // Um comando simples para se caso não existir arquivo, apenas inicializa a lista
        T->inicio = 0;
        T->fim = 0;

        layout();
        gotoxy(25,03);
        printf("Nenhum arquivo encontrado. Lista iniciada vazia.");
        getch();
        return;

    }

    reg_tarefas taref;
    T->inicio = 0;
    T->fim = 0;

    /*
        fread = Lê todos os clientes
        fopen = Abre o arquivo com todas as tarefas
        fwrite = Grava todas as tarefas no arquivo
        fclose = Fecha o arquivo com todas as tarefas salvos
    */

    while ( fread( &taref, sizeof(reg_tarefas), 1, ptr ) == 1 ) {

        if ( T->fim < MAX ) { // Comando para que seja de acordo com o MAX introduzido no começo do codigo
                                 // garantindo que nao ultrapasse o limite, acordado no MAX                       

            T->ficha[T->fim] = taref;
            T->fim++;

        }

    }

    fclose(ptr);

    layout();
    gotoxy(25,03);
    printf("Dados carregados do arquivo com sucesso!");
    getch();
    
}

// Programa principal
int main(){

    // Declarando variaveis
    int opcao;
    Tarefas T;
    inicializa_Tarefa(&T);

    // Carrega os dados armazenados no arquivo
    le_arquivo(&T);

    system("color 72");
    system("cls");

    do {
        layout();
        gotoxy(20,03);
        printf("--- MENU DO PROGRAMA ---");

        gotoxy(21,9);
        printf("1 - Criar uma Tarefa");

        gotoxy(21,11);
        printf("2 - Alterar uma Tarefa");

        gotoxy(21,13);
        printf("3 - Consultar as Tarefas");

        gotoxy(21,15);
        printf("4 - Excluir uma Tarefa");

        gotoxy(21,17);
        printf("5 - Finalizar o Programa");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        system("cls");

        switch ( opcao ) {

            case 1:
                criar_Tarefa(&T);
                break;
            
            case 2:
                alterar_Tarefa(&T);
                break;
            
            case 3:
                consulta_Tarefa(&T);
                break;
            
            case 4:
                exclusao_Tarefa(&T);
                break;
            
            default:
                break;
            
        }
    } while ( opcao != 5 );

    gravar(&T);

    return 0;

}