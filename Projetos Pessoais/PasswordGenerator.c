/*
Autor: Arthur Almeida Pereira
Data: 22/03/2026
Objetivo: Gerador de senha
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 20
#include <time.h> // para usar srand(time(NULL))
#include <conio.h>

// Funcao GOTOXY, funcao para setar onde o cursor vai ir
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
    printf("Arthur Almeida Pereira");
    gotoxy(62,2);
    printf("Password Generator");
    gotoxy(02,23);
    printf("MSG: ");

}

// Tela Senha
void Tela_password() {

        gotoxy(24,5);
        printf("CADASTRO DE SENHA");
        gotoxy(24,7);
        printf("CODIGO.............: ");
        gotoxy(24,9);
        printf("NAVEGADOR..........: ");
        gotoxy(24,11);
        printf("REDE SOCIAL........: ");
        gotoxy(24,13);
        printf("EMAIL..............: ");
        gotoxy(24,15);
        printf("TAMAHNHO DA SENHA..: ");
        gotoxy(24,17);
        printf("SENHA..............: ");

}

// Struct para lista das variaveis das senhas
typedef struct 
{
    char maiuscula[27];
    char minuscula[27];
    char numeros[11];
    char simbolos[20];
    int codigo;
    char navegador[20];
    char rede[10];
    int tamanho_senha;
    char email[50];
    char senha[50]; // <-- campo para guardar a senha gerada

} reg_senha;

typedef struct
{
    reg_senha lista[MAX];
    int inicio;
    int fim;

} ListaSenha;

// Funcao para inicializar lista
void inicializa_lista( ListaSenha *LS ) {

    LS->inicio = 0;
    LS->fim = 0;
} 

// Funcao para pesquisa
int pesquisa(ListaSenha *LS, int cod) {
    int i;
    for (i = 0; i < LS->fim; i++) {
        if(LS->lista[i].codigo == cod) {
            return 1;
        }
    }
    return -1;
}

// Função para gerar senha aleatória
void gerar_senha(reg_senha *password) {
    int tamanho = password->tamanho_senha; // tamanho escolhido pelo usuário

    // Validação: se o usuário pedir mais que 49, limita para 49
    if (tamanho > 49) {
        tamanho = 49;
        password->tamanho_senha = 49; // atualiza o campo também
    }

    if (tamanho < 4) {
    tamanho = 4;
    password->tamanho_senha = 4;
    }

    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "abcdefghijklmnopqrstuvwxyz"
                      "0123456789"
                      "!@#$%¨&*()<>";
    int tamanho_alfabeto = 0;
    while (alfabeto[tamanho_alfabeto] != '\0') {
        tamanho_alfabeto++;
    }

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        int indice = rand() % tamanho_alfabeto;
        password->senha[i] = alfabeto[indice];
    }

    password->senha[tamanho] = '\0'; // finaliza string
}

// Funcao para cadastro de password
void cadastro_password ( ListaSenha *LS ) {
    int resp;

    if ( LS->fim >= MAX ) { // Condicao para que se a lista estiver cheia, imprimira na tela
        gotoxy(24,5);
        printf("Lista cheia!\n");
        return;
    }

    do {
        
        reg_senha password;
        int result;
        
        do{
            tela();
            

            Tela_password();

            gotoxy(45,7);
            scanf("%d", &password.codigo);

            result = pesquisa(LS, password.codigo);
            if ( result != -1) {
                gotoxy(07,23);
                printf("Codigo ja existe.");
                getch();
            }

        } while ( result != -1);
        
    
        gotoxy(45,9);
        fflush(stdin);
        gets(password.navegador);

        gotoxy(45,11);
        gets(password.rede);

        gotoxy(45,13);
        gets(password.email);

        // Pergunta o tamanho da senha
        gotoxy(45,15);
        scanf("%d", &password.tamanho_senha);

        // Gera a senha com o tamanho escolhido
        gotoxy(45,17);
        gerar_senha(&password);
        gotoxy(45,17);
        printf("%s", password.senha);

        gotoxy(07,23);
        printf("Deseja cadastrar a senha? ( 1 = Sim, 2 = Nao ).: ");
        int confirma;
        scanf("%d", &confirma);
        limpar();

        if (confirma == 1) {
            if ( LS->fim < MAX ) {
                LS->lista[LS->fim] = password;
                LS->fim++;
                gotoxy(24,7);
                printf("Senha cadastrado com sucesso!");
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
void alteracao_password ( ListaSenha *LS ) {
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
        for (int i = 0; i < LS->fim; i++) {
            if (LS->lista[i].codigo == codigo) {
                encontrado = 1;

                Tela_password();
                gotoxy(21,9);
                printf("1");
                gotoxy(45,9);
                printf(" %s", LS->lista[i].navegador);
                gotoxy(21,11);
                printf("2");
                gotoxy(45,11);
                printf(" %s", LS->lista[i].rede);
                gotoxy(21,13);
                printf("3");
                gotoxy(45,13);
                printf(" %s", LS->lista[i].email);
                gotoxy(21,15);

                gotoxy(07,23);
                printf("Deseja alterar qual informacao? ");
                gotoxy(56,21);
                scanf("%d", &opcao);
                getchar();

                switch ( opcao ) {

                    case 1:
                        gotoxy(24,9);
                        printf("NAVEGADOR ATUAL....: %s", LS->lista[i].navegador);
                        gotoxy(24,10);
                        printf("NAVEGADOR NOVO.....: ");
                        // NAVEGADOR
                        gotoxy(45,10);
                        scanf(" %[^\n]", LS->lista[i].navegador);

                        break;
                    
                    case 2:
                        gotoxy(24,11);
                        printf("REDE SOCIAL ATUAL..: %s", LS->lista[i].rede);
                        gotoxy(24,12);
                        printf("REDE SOCIAL NOVO...: ");
                        // REDE SOCIAL
                        gotoxy(45,12);
                        scanf(" %[^\n]", LS->lista[i].rede);


                        break;
                    
                    case 3:
                        gotoxy(24,13);
                        printf("EMAIL ATUAL........: %s", LS->lista[i].email);
                        gotoxy(24,14);
                        printf("EMAIL NOVO.........: ");
                        // EMAIL
                        gotoxy(45,14);
                        scanf(" %[^\n]", LS->lista[i].email);


                        break;
                    
                    case 4:
                        
                        gotoxy(24,15);
                        printf("SENHA ATUAL........: %s", LS->lista[i].senha);
                        gotoxy(24,16);
                        printf("Deseja gerar nova senha automaticamente? (1 = Sim, 2 = Nao): ");
                        int escolha;
                        scanf("%d", &escolha);

                        if (escolha == 1) {
                            gotoxy(24,17);
                            printf("Digite o novo tamanho da senha: ");
                            scanf("%d", &LS->lista[i].tamanho_senha);

                            gerar_senha(&LS->lista[i]); // gera nova senha
                            gotoxy(24,18);
                            printf("Nova senha gerada: %s", LS->lista[i].senha);
                        } else {
                            gotoxy(24,17);
                            printf("Digite a nova senha manualmente: ");
                            scanf(" %[^\n]", LS->lista[i].senha);
                        }
                        break;
                    
                    default:
                        break;
                }
            }
        }

        if (!encontrado) {
            gotoxy(24,9);
            printf("Codigo nao encontrado!");
        }

        gotoxy(07,23);
        printf("Deseja sair da alterecao? ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");

    } while (resp == 2);
    
        
}

// Funcao para cadastro de cliente
void consulta_password ( ListaSenha *LS ) {
    int resp;
    int codigo;
    do {
        tela();
        gotoxy(24,5);
        printf("CONSULTA DE SENHA");
        gotoxy(24,7);
        printf("CODIGO.............: ");
        gotoxy(45,7);
        scanf("%d", &codigo);

        int encontrado = 0;
        for (int i = 0; i < LS->fim; i++) {
            if (LS->lista[i].codigo == codigo) {
                encontrado = 1;

                Tela_password();
                gotoxy(45,9);
                printf(" %s", LS->lista[i].navegador);
                gotoxy(45,11);
                printf(" %s", LS->lista[i].rede);
                gotoxy(45,13);
                printf(" %s", LS->lista[i].email);
                gotoxy(45,15);
                printf(" %s", LS->lista[i].senha);

                break;
            }
        }

        if (!encontrado) {
            gotoxy(24,9);
            printf("Codigo nao encontrado!");
        }
        
        gotoxy(07,23);
        printf("Deseja sair da consulta ( 1 = Sim, 2 = Nao ).: ");
        scanf("%d", &resp);
        system("cls");
    } while (resp == 2);
    
}

void exclusao_password ( ListaSenha *LS ) {
    int resp;
    int codigo;

    do {
        tela();
        gotoxy(24,5);
        printf("EXCLUSAO DE SENHA");

        gotoxy(24,7);
        printf("CODIGO.............: ");
        gotoxy(45,7);
        scanf("%d", &codigo);

        int encontrado = 0;
        for(int i = 0; i < LS->fim; i++) {
            if ( LS->lista[i].codigo == codigo ) {
                encontrado = 1;

                Tela_password();
                gotoxy(56,9);
                printf(" %s", LS->lista[i].navegador);
                gotoxy(56,11);
                printf(" %s", LS->lista[i].rede);
                gotoxy(56,13);
                printf(" %s", LS->lista[i].email);
                gotoxy(56,15);
                printf(" %s", LS->lista[i].senha);

                gotoxy(24,5);
                printf("CONFIRMA EXCLUSAO? ( 1 = SIM, 2 = NAO): ");
                int confirma;
                scanf("%d", &confirma);

                if (confirma == 1) {
                    // Desloca os elementos para tras
                    for ( int j = i; j < LS->fim - 1; j++ ) {
                        LS->lista[j] = LS->lista[j+1];
                    }
                    LS->fim--;
                    gotoxy(24,7);
                    printf("Senha excluida com sucesso!");

                } else {
                    gotoxy(24,7);
                    printf("Exclusao cancelada");

                }

                break;
            }

        }

        if (!encontrado) {
            gotoxy(24,9);
            printf("Codigo nao encontrado");
        }

        gotoxy(07,23);
        printf("Deseja excluir outra senha ( 1 = Sim, 2 = Nao ).: ");
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
void ordena_codigo(ListaSenha *LS) {
    
    int i;
    int j;
    reg_senha    aux; // Auxiliar

    for ( i = 0; i < LS->fim-1; i++ ) {           // Looping para percorrer o vetor todo e
        for ( j = i+1; j <= LS->fim; j++ ) {      // ordenar por troca

            if ( LS->lista[i].codigo > LS->lista[j].codigo ) {

                aux = LS->lista[i];
                LS->lista[i] = LS->lista[j];
                LS->lista[j] = aux;

            }
        }
    }
}

// Funcao que Lista Clientes em Ordem de Codigo
void lista_codigo_clientes(ListaSenha *LS) {

    int i;
    int lin = 7;

    // Chama a funcao de Ordenacao
    ordena_codigo(LS);

    tela();
    gotoxy(10,03);
    printf("-- Lista Senha Ordem de Codigo --");
    gotoxy(02,5);
    printf("Cod:");
    gotoxy(8,5);
    printf("Navegador:");
    gotoxy(36,5);
    printf("Rede Social:");
    gotoxy(50,5);
    printf("Email:");
    gotoxy(67,5); 
    printf("Senha:");
    gotoxy(02,6);
    printf("---  --------------------------- -----------    ------------     ------------");    

    for ( i = 0; i < LS->fim; i++ ) {

        gotoxy(03,lin);
        printf("%d", LS->lista[i].codigo);
        gotoxy(8,lin);
        printf("%s", LS->lista[i].navegador);
        gotoxy(33,lin);
        printf("%s", LS->lista[i].rede);
        gotoxy(50,lin);
        printf("%s", LS->lista[i].email);
        gotoxy(67,lin);
        printf("%s", LS->lista[i].senha);
        
        lin++;
        if (lin > 22) {

            
            tela();
            gotoxy(10,03);
            printf("-- Lista Senha Ordem de Codigo --");
            gotoxy(02,04);
            printf("Cod:");
            gotoxy(06,4);
            printf("Navegador:");
            gotoxy(36,4);
            printf("Rede Social:");
            gotoxy(50,4);
            printf("Email:");
            gotoxy(67,4);
            printf("Senha:");

            getch();
        }
    }

    getch();
}

// Funcao que Mostra o Menu de consulta
void menu_consulta(ListaSenha *LS) {

    int opc;

    do {
        tela();
        gotoxy(20,03);
        printf("--- MENU DE CONSULTAS ---");

        gotoxy(21,9);
        printf("1 - Cliente por Codigo Especifico");
        gotoxy(21,12);
        printf("2 - Lista de Clientes em Ordem de Codigo");
        gotoxy(21,15);
        printf("3 - Retorna ao Menu Anterior");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opc);

        switch ( opc ) 
        {
            case 1:
                consulta_password(LS);
                break;
            case 2:
                lista_codigo_clientes(LS);
                break;
            case 3:
                tela();
                break;
            default:
                break;
        }

    } while ( opc == 4 );

}

// Funcao para Gravar no Disco
void gravar(ListaSenha *LS) {

    int i;
    FILE *ptr;
    char *Filename = "senhas.dat";
    char *modo_gravacao = "wb";
    reg_senha password;

    ptr = fopen ( Filename, modo_gravacao );  // Abre para escrita binaria
        
    if ( ptr == NULL ) {
        tela();
        gotoxy(25,03);
        printf("Erro ao abrir arquivo para gravacao!");
        return;
    }

    // Um comando de repeticao para gravar todos os clientes da lista
    for ( i = 0; i < LS->fim; i++ ) {
            
        fwrite(&LS->lista[i], sizeof(reg_senha), 1, ptr);

    }

    fclose( ptr ) ;

    tela();
    gotoxy(25,03);
    printf("Dados gravados com sucesso!");
    getch();
}

// Funcao para Ler os Arquivos do Disco
void le_arquivo(ListaSenha *LS) {

    FILE *ptr;
    char *Filename = "senhas.dat";
    char *modo_leitura = "rb";
    

    ptr = fopen( Filename, modo_leitura ); // Desta maneira, ele faz a leitura binaria
    if ( ptr == NULL ) {

        // Um comando simples para se caso não existir arquivo, apenas inicializa a lista
        LS->inicio = 0;
        LS->fim = 0;

        tela();
        gotoxy(25,03);
        printf("Nenhum arquivo encontrado. Lista iniciada vazia.");
        getch();
        return;

    }

    reg_senha password;
    LS->inicio = 0;
    LS->fim = 0;

    /*
        fread = Lê todas as senhas
        fopen = Abre o arquivo com todas as senhas
        fwrite = Grava todas as senhas no arquivo
        fclose = Fecha o arquivo com todas as senhas salvas
    */

    while ( fread( &password, sizeof(reg_senha), 1, ptr ) == 1 ) {

        if ( LS->fim < MAX ) { // Comando para que seja de acordo com o MAX introduzido no começo do codigo
                                 // garantindo que nao ultrapasse o limite, acordado no MAX                       

            LS->lista[LS->fim] = password;
            LS->fim++;

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
    ListaSenha LS;
    int opcao;
    inicializa_lista(&LS);
    
    // Carrega os dados guardados no arquivo
    le_arquivo(&LS);

    system("color 05");
    system("cls");
        
    do {
        
        tela();
        gotoxy(24,7);
        printf("SISTEMA DE SENHA");
        gotoxy(24,9);
        printf("1 - CRIAR");
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
                cadastro_password(&LS);
                break;
            case 2:
                alteracao_password(&LS);
                break;
            case 3:
                menu_consulta(&LS);
                break;
            case 4:
                exclusao_password(&LS);
                break;
            default:
                break;
        }

    } while(opcao != 5);

    gravar(&LS);

    return 0;
    
}