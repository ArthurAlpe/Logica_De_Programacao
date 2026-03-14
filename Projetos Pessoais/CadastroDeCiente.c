/*
Autor: Arthur Almeida Pereira
Data: 25/02/2026
Objetivo: Sistema de cadastro de cliente
gotoxy 80 por 24
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define MAX 5 // Capacidade da lista , determina o maximo de posicoes que tem no vetor

// Estruturas

/*
typedef char caractere;
typedef int inteiro;

Ou seja, apelidar e definir um tipo de dado
*/

typedef struct { // Tipo de dado

    // Um vetor para armazenar todos esses dados
    
    int codigo;
    char nome[50];
    char endereco[50];
    char telefone[16];
    char cpf[15];
    char email[50];
    char dt_nascimento[11];

} reg_clientes;

typedef struct {
    
    // Lista para controle de quantidade, inicio e fim
    reg_clientes ficha[MAX];
    int inicio;
    int fim;

} Lista;

// Funcao para inicializar lista
void inicializa_lista( Lista *L ) {

    L->inicio = 0;
    L->fim = 0;
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
    gotoxy(2,3);
    printf("Arthur");
    gotoxy(62,2);
    printf("Estrutura de Dados");
    gotoxy(67,3);
    printf("Prof. Rodney");
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

void Tela_Cliente() {

        gotoxy(24,5);
        printf("CADASTRO DE CLIENTE");
        gotoxy(24,7);
        printf("CODIGO.............: ");
        gotoxy(45,7);
        gotoxy(24,9);
        printf("NOME...............: ");
        gotoxy(45,9);
        gotoxy(24,11);
        printf("ENDERECO...........: ");
        gotoxy(45,11);
        gotoxy(24,13);
        printf("TELEFONE...........: ");
        gotoxy(45,13);
        gotoxy(24,15);
        printf("CPF................: ");
        gotoxy(45,15);
        gotoxy(24,17);
        printf("EMAIL..............: ");
        gotoxy(45,17);
        gotoxy(24,19);
        printf("DATA DE NASCIMENTO.: ");
        gotoxy(45,19);

}

// Funcao para pesquisa
int pesquisa(Lista *L, int cod) {
    int i;
    for (i = 0; i < L->fim; i++) {
        if(L->ficha[i].codigo == cod) {
            return 1;
        }
    }
    return -1;
}

// Funcao para cadastro de cliente
void cadastro_cliente ( Lista *L ) {
    int resp;

    if ( L->fim >= MAX ) { // Condicao para que se a lista estiver cheia, imprimira na tela
        gotoxy(24,5);
        printf("Lista cheia!\n");
        return;
    }

    do {
        
        reg_clientes clie;
        int result;
        
        do{
            tela();
            

            Tela_Cliente();

            gotoxy(45,7);
            scanf("%d", &clie.codigo);

            result = pesquisa(L, clie.codigo);
            if ( result != -1) {
                gotoxy(07,23);
                printf("Codigo ja existe.");
                getch();
            }

        } while ( result != -1);
        
    
        gotoxy(45,9);
        fflush(stdin);
        gets(clie.nome);

        gotoxy(45,11);
        gets(clie.endereco);

        gotoxy(45,13);
        gets(clie.telefone);

        gotoxy(45,15);
        gets(clie.cpf);

        gotoxy(45,17);
        gets(clie.email);

        gotoxy(45,19);
        gets(clie.dt_nascimento);

        gotoxy(07,23);
        printf("Deseja cadastrar o cliente? ( 1 = Sim, 2 = Nao ).: ");
        int confirma;
        scanf("%d", &confirma);
        limpar();

        if (confirma == 1) {
            if ( L->fim < MAX ) {
                L->ficha[L->fim] = clie;
                L->fim++;
                gotoxy(24,7);
                printf("Cliente cadastrado com sucesso!");
            } else {
                gotoxy(24,7);
                printf("Lista cheia, nao e possivel cadastrar!");
            }
        } else {
            gotoxy(24,7);
            printf("Cadastro cancelado!");

        }

        gotoxy(07,23);
        printf("Deseja sair do cadastro ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while (resp == 2);
    
}

// Funcao para alteracao de cliente
void alteracao_cliente ( Lista *L ) {
    int resp;
    int codigo;
    int opcao;

    do {
        tela();
        gotoxy(24,5);
        printf("ALTERECAO DE CLIENTE");
        gotoxy(24,7);
        printf("DIGITE O CODIGO....: ");
        gotoxy(45,7);
        scanf("%d", &codigo);
        fflush(stdin);

        
        int encontrado = 0;
        for (int i = 0; i < L->fim; i++) {
            if (L->ficha[i].codigo == codigo) {
                encontrado = 1;

                Tela_Cliente();
                gotoxy(21,9);
                printf("1");
                gotoxy(45,9);
                printf(" %s", L->ficha[i].nome);
                gotoxy(21,11);
                printf("2");
                gotoxy(45,11);
                printf(" %s", L->ficha[i].endereco);
                gotoxy(21,13);
                printf("3");
                gotoxy(45,13);
                printf(" %s", L->ficha[i].telefone);
                gotoxy(21,15);
                printf("4");
                gotoxy(45,15);
                printf(" %s", L->ficha[i].cpf);
                gotoxy(21,17);
                printf("5");
                gotoxy(45,17);
                printf(" %s", L->ficha[i].email);
                gotoxy(21,19);
                printf("6");
                gotoxy(45,19);
                printf(" %s", L->ficha[i].dt_nascimento);

                gotoxy(07,23);
                printf("Deseja alterar qual informacao? ");
                gotoxy(56,21);
                scanf("%d", &opcao);
                getchar();

                switch ( opcao ) {

                    case 1:
                        gotoxy(24,9);
                        printf("NOME ATUAL.........: %s", L->ficha[i].nome);
                        gotoxy(24,10);
                        printf("NOME NOVO..........: ");
                        // Nome
                        gotoxy(45,10);
                        scanf(" %[^\n]", L->ficha[i].nome);

                        break;
                    
                    case 2:
                        gotoxy(24,11);
                        printf("ENDERECO ATUAL.....: %s", L->ficha[i].endereco);
                        gotoxy(24,12);
                        printf("ENDERECO NOVO......: ");
                        // Endereco
                        gotoxy(45,12);
                        scanf(" %[^\n]", L->ficha[i].endereco);


                        break;
                    
                    case 3:
                        gotoxy(24,13);
                        printf("TELEFONE ATUAL.....: %s", L->ficha[i].telefone);
                        gotoxy(24,14);
                        printf("TELEFONE NOVO......: ");
                        // Telefone
                        gotoxy(45,14);
                        scanf(" %[^\n]", L->ficha[i].telefone);


                        break;
                    
                    case 4:
                        gotoxy(24,15);
                        printf("CPF ATUAL..........: %s", L->ficha[i].cpf);
                        gotoxy(24,16);
                        printf("CPF NOVO...........: ");
                        // CPF
                        gotoxy(45,16);
                        scanf(" %[^\n]", L->ficha[i].cpf);


                        break;
                    
                    case 5:
                        gotoxy(24,17);
                        printf("EMAIL ATUAL........: %s", L->ficha[i].email);
                        gotoxy(24,18);
                        printf("EMAIL NOVO.........: ");
                        // EMAIL
                        gotoxy(45,18);
                        scanf(" %[^\n]", L->ficha[i].email);


                        break;
                    
                    case 6:
                        gotoxy(24,19);
                        printf("NASCIMENTO ATUAL...: %s", L->ficha[i].dt_nascimento);
                        gotoxy(24,20);
                        printf("NASCIMENTO NOVO....: ");
                        // Data Nascimento
                        gotoxy(45,20);
                        scanf(" %[^\n]", L->ficha[i].dt_nascimento);


                        break;
                    
                    default:
                        break;
                }
            }
        }

        if (!encontrado) {
            gotoxy(24,9);
            printf("Cliente nao encontrado!");
        }

        gotoxy(07,23);
        printf("Deseja sair da alterecao? ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while (resp == 2);
    
        
}

// Funcao para cadastro de cliente
void consulta_cliente ( Lista *L ) {
    int resp;
    int codigo;
    do {
        tela();
        gotoxy(24,5);
        printf("CONSULTA DE CLIENTE");
        gotoxy(24,7);
        printf("CODIGO.............: ");
        gotoxy(45,7);
        scanf("%d", &codigo);

        int encontrado = 0;
        for (int i = 0; i < L->fim; i++) {
            if (L->ficha[i].codigo == codigo) {
                encontrado = 1;

                Tela_Cliente();
                gotoxy(45,9);
                printf(" %s", L->ficha[i].nome);
                gotoxy(45,11);
                printf(" %s", L->ficha[i].endereco);
                gotoxy(45,13);
                printf(" %s", L->ficha[i].telefone);
                gotoxy(45,15);
                printf(" %s", L->ficha[i].cpf);
                gotoxy(45,17);
                printf(" %s", L->ficha[i].email);
                gotoxy(45,19);
                printf(" %s", L->ficha[i].dt_nascimento);

                break;
            }
        }

        if (!encontrado) {
            gotoxy(24,9);
            printf("Cliente nao encontrado!");
        }
        
        gotoxy(07,23);
        printf("Deseja sair da consulta ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");
    } while (resp == 2);
    
}

void exclusao_cliente ( Lista *L ) {
    int resp;
    int codigo;

    do {
        tela();
        gotoxy(24,5);
        printf("EXCLUSAO DE CLIENTE");

        gotoxy(24,7);
        printf("CODIGO.............: ");
        gotoxy(45,7);
        scanf("%d", &codigo);

        int encontrado = 0;
        for(int i = 0; i < L->fim; i++) {
            if ( L->ficha[i].codigo == codigo ) {
                encontrado = 1;

                Tela_Cliente();
                gotoxy(56,9);
                printf(" %s", L->ficha[i].nome);
                gotoxy(56,11);
                printf(" %s", L->ficha[i].endereco);
                gotoxy(56,13);
                printf(" %s", L->ficha[i].telefone);
                gotoxy(56,15);
                printf(" %s", L->ficha[i].cpf);
                gotoxy(56,17);
                printf(" %s", L->ficha[i].email);
                gotoxy(56,19);
                printf(" %s", L->ficha[i].dt_nascimento);

                gotoxy(24,5);
                printf("CONFIRMA EXCLUSAO? ( 1 = SIM, 2 = NAO): ");
                int confirma;
                scanf("%d", &confirma);

                if (confirma == 1) {
                    // Desloca os elementos para tras
                    for ( int j = i; j < L->fim - 1; j++ ) {
                        L->ficha[j] = L->ficha[j+1];
                    }
                    L->fim--;
                    gotoxy(24,7);
                    printf("Cliente excluido com sucesso!");

                } else {
                    gotoxy(24,7);
                    printf("Exclusao cancelada");

                }

                break;
            }

        }

        if (!encontrado) {
            gotoxy(24,9);
            printf("Cliente nao encontrado");
        }

        gotoxy(07,23);
        printf("Deseja excluir outro cliente ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while (resp == 1);
}

// Funcao para limpar mensagem
void limpar() {

    gotoxy(07,23);
    printf("                                                      ");

}

// Funcao que Ordena Clientes em Ordem de codigo
void ordena_codigo(Lista *L) {
    
    int i;
    int j;
    reg_clientes    aux; // Auxiliar

    for ( i = 0; i < L->fim-1; i++ ) {           // Looping para percorrer o vetor todo e
        for ( j = i+1; j <= L->fim; j++ ) {      // ordenar por troca

            if ( L->ficha[i].codigo > L->ficha[j].codigo ) {

                aux = L->ficha[i];
                L->ficha[i] = L->ficha[j];
                L->ficha[j] = aux;

            }
        }
    }
}

// Funcao que Lista Clientes em Ordem Alfabetica
void lista_alfabetica_clientes(Lista *L) {

}

// Funcao que Lista Clientes em Ordem de Codigo
void lista_codigo_clientes(Lista *L) {

    int i;
    int lin = 7;

    // Chama a funcao de Ordenacao
    ordena_codigo(L);

    tela();
    gotoxy(10,03);
    printf("-- Lista Clientes Ordem de Codigo --");
    gotoxy(02,5);
    printf("Cod:");
    gotoxy(8,5);
    printf("Nome do Cliente:");
    gotoxy(36,5);
    printf("CPF:");
    gotoxy(50,5);
    printf("Telefone:");
    gotoxy(67,5); 
    printf("Dt_Nasc:");
    gotoxy(02,6);
    printf("---  --------------------------- -----------    ------------     ------------");    

    for ( i = 0; i < L->fim; i++ ) {

        gotoxy(03,lin);
        printf("%d", L->ficha[i].codigo);
        gotoxy(8,lin);
        printf("%s", L->ficha[i].nome);
        gotoxy(33,lin);
        printf("%s", L->ficha[i].cpf);
        gotoxy(50,lin);
        printf("%s", L->ficha[i].telefone);
        gotoxy(67,lin);
        printf("%s", L->ficha[i].dt_nascimento);
        
        lin++;
        if (lin > 22) {

            
            tela();
            gotoxy(10,03);
            printf("-- Lista Clientes Ordem de Codigo --");
            gotoxy(02,04);
            printf("Cod:");
            gotoxy(06,4);
            printf("Nome do Cliente:");
            gotoxy(36,4);
            printf("CPF:");
            gotoxy(50,4);
            printf("Telefone:");
            gotoxy(67,4);
            printf("Dt_Nasc:");

            getch();
        }
    }

    getch();
}

// Funcao que Mostra o Menu de consulta
void menu_consulta(Lista *L) {

    int opc;

    do {
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
        scanf("%d", &opc);

        switch ( opc ) 
        {
            case 1:
                consulta_cliente(L);
                break;
            case 2:
                lista_alfabetica_clientes(L);
                break;
            case 3:
                lista_codigo_clientes(L);
                break;
            case 4:
                tela();
                break;
            default:
                break;
        }

    } while ( opc == 4 );

}

    // Funcao para Gravar no Disco
    void gravar(Lista *L) {

        int i;
        FILE *ptr;
        char *Filename = "clientes.dat";
        char *modo_gravacao = "wb";
        reg_clientes clie;

        ptr = fopen ( Filename, modo_gravacao );  // Abre para escrita binaria
        
        if ( ptr == NULL ) {
            tela();
            gotoxy(25,03);
            printf("Erro ao abrir arquivo para gravacao!");
            return;
        }

        // Um comando de repeticao para gravar todos os clientes da lista
        for ( i = 0; i < L->fim; i++ ) {
            
            fwrite(&L->ficha[i], sizeof(reg_clientes), 1, ptr);

        }

        fclose( ptr ) ;

        tela();
        gotoxy(25,03);
        printf("Dados gravados com sucesso!");
        getch();
    }

// Funcao para Ler os Arquivos do Disco
void le_arquivo(Lista *L) {

    FILE *ptr;
    char *Filename = "clientes.dat";
    char *modo_leitura = "rb";
    

    ptr = fopen( Filename, modo_leitura ); // Desta maneira, ele faz a leitura binaria
    if ( ptr == NULL ) {

        // Um comando simples para se caso não existir arquivo, apenas inicializa a lista
        L->inicio = 0;
        L->fim = 0;

        tela();
        gotoxy(25,03);
        printf("Nenhum arquivo encontrado. Lista iniciada vazia.");
        getch();
        return;

    }

    reg_clientes clie;
    L->inicio = 0;
    L->fim = 0;

    /*
        fread = Lê todos os clientes
        fopen = Abre o arquivo com todos os clientes
        fwrite = Grava todos os clientes no arquivo
        fclose = Fecha o arquivo com todos os clientes salvos
    */

    while ( fread( &clie, sizeof(reg_clientes), 1, ptr ) == 1 ) {

        if ( L->fim < MAX ) { // Comando para que seja de acordo com o MAX introduzido no começo do codigo
                                 // garantindo que nao ultrapasse o limite, acordado no MAX                       

            L->ficha[L->fim] = clie;
            L->fim++;

        }

    }

    fclose(ptr);

    tela();
    gotoxy(25,03);
    printf("Dados carregados do arquivo com sucesso!");
    getch();
    
}

// Programa principal
int main()
{
    // Declara variaveis
    Lista L;
    int opcao;
    inicializa_lista(&L);
    
    // Carrega os dados guardados no arquivo
    le_arquivo(&L);

    system("color 17");
    system("cls");
        
    do {
        
        tela();
        gotoxy(24,7);
        printf("SISTEMA DE CLIENTES");
        gotoxy(24,9);
        printf("1 - INCLUSAO");
        gotoxy(24,11);
        printf("2 - ALTERACAO");
        gotoxy(24,13);
        printf("3 - CONSULTA");
        gotoxy(24,15);
        printf("4 - EXCLUSAO");
        gotoxy(24,17);
        printf("5 - FINALIZAR O PROGRAMA");
        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {
            case 1:
                cadastro_cliente(&L);
                break;
            case 2:
                alteracao_cliente(&L);
                break;
            case 3:
                menu_consulta(&L);
                break;
            case 4:
                exclusao_cliente(&L);
                break;
            default:
                break;
        }

    } while(opcao != 5);

    gravar(&L);

    return 0;
    
}