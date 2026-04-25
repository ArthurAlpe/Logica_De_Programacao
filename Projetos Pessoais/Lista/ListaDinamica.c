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
    char dt_nasc[15];
    char telefone[20];
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
TipoApontador pesquisa(TipoLista *L, int cod)
{
    TipoApontador aux;

    aux = L->Primeiro;

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

// Função auxiliar para contar elementos da lista
int contar_elementos(TipoLista *L) 
{
    
    int n = 0;
    TipoApontador aux = L->Primeiro;

    while (aux != NULL) 
    {
        n++;
        aux = aux->proximo;
    }

    return n;
}

// Funcao para o Menu de Cadastros
void menu_cadastros ( TipoLista *L )
{

    int opcao;

    do
    {
        tela();

        gotoxy(20,03);
        printf("--- MENU DE CADASTROS ---");

        gotoxy(24,7);
        printf("1 - Cadastrar funcionario no Final da Lista");

        gotoxy(24,9);

        printf("2 - Cadastrar funcionario no Inicio da Lista");

        gotoxy(24,11);
        printf("3 - Cadastrar funcionario em uma Posicao da Lista");

        gotoxy(24,13);
        printf("4 - Sair do Menu de Cadastros");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        system("cls");

        switch ( opcao )
        {

            case 1:
                cadastrar_Funcionario_Final(L);
                break;
            case 2:
                cadastrar_Funcionario_Inicio(L);
                break;
            case 3:
                cadastrar_Funcionario_Posicao(L);
                break;
            default:
                break;

        }

    } while ( opcao != 4 );

}

// Funcao para Cadastro de Funcionario no Final da Lista
void cadastrar_Funcionario_Final( TipoLista *L )
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

            resultado = pesquisa (L, func.codigo);

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

            if ( L->Ultimo == NULL )
            {
                L->Primeiro = novo;
                L->Ultimo = novo;

            } else {

                L->Ultimo->proximo = novo;
                L->Ultimo = novo;

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
void cadastrar_Funcionario_Inicio( TipoLista *L )
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

            resultado = pesquisa (L, func.codigo);

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
            p->proximo = L->Primeiro;
            L->Primeiro = p;

            if ( L->Ultimo == NULL )
            {
                
                L->Ultimo = p;

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

// Função para Cadastro de Funcionario em uma Posicao da Lista
void cadastrar_Funcionario_Posicao(TipoLista *L) 
{
    int resp;
    int pos_lista;

    do 
    {
        reg_funcionario func;
        int resultado;

        tela();
        tela_Funcionario();

        // Conta quantos elementos já existem
        int total = contar_elementos(L);
        gotoxy(24,5);
        printf("POSICAO............: ");
        gotoxy(45,5);
        scanf("%d", &pos_lista);

        // Validação da posição
        if (pos_lista < 1 || pos_lista > total + 1) 
        {
            gotoxy(07,23);
            printf("Posicao invalida! Atualmente existem %d funcionarios.", total);

            getch();

            continue; // volta para pedir novamente
        }

        gotoxy(45,6);
        scanf("%d", &func.codigo);

        resultado = pesquisa(L, func.codigo);

        if (resultado != NULL) 
        {
            gotoxy(07,23);
            printf("Este Codigo ja Existe!");

            getch();

            continue;
        }

        // Coleta os demais dados normalmente
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
        printf("Deseja cadastrar o Funcionario na Posicao %d da Lista? (1 = Sim, 2 = Nao) ", pos_lista);

        int confirma;
        scanf("%d", &confirma);
        limpar_msg();

        if (confirma == 1) 
        {

            TipoApontador p = (TipoApontador) malloc(sizeof(TipoItem));
            p->conteudo = func;
            p->proximo = NULL;

            if (pos_lista == 1) 
            {

                p->proximo = L->Primeiro;
                L->Primeiro = p;

                if (L->Ultimo == NULL) 
                {
                    L->Ultimo = p;
                }

            } else {

                TipoApontador atual = L->Primeiro;

                for (int i = 1; i < pos_lista - 1; i++) 
                {
                    atual = atual->proximo;
                }

                p->proximo = atual->proximo;
                atual->proximo = p;

                if (p->proximo == NULL) 
                {
                    L->Ultimo = p;
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
        printf("Deseja sair do cadastro? (1 = Sim, 2 = Nao) ");
        scanf("%d", &resp);

    } while (resp == 2);
}

// Funcao para o Menu de Cadastros
void menu_remover ( TipoLista *L )
{

    int opcao;

    do
    {
        tela();

        gotoxy(20,03);
        printf("--- MENU DE REMOVER ---");

        gotoxy(24,07);
        printf("1 - Remover funcionario no Final da Lista");
        gotoxy(24,9);
        printf("2 - Remover funcionario em uma Posicao da Lista");
        gotoxy(24,11);
        printf("3 - Remover funcionario no Inicio da Lista");
        gotoxy(24,13);
        printf("4 - Remover funcionario por Codigo");
        gotoxy(24,15);
        printf("5 - Sair do Menu de Remover");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        system("cls");

        switch ( opcao )
        {

            case 1:
                remover_Funcionario_Final(L);
                break;
            case 2:
                remover_Funcionario_Posicao(L);
                break;
            case 3:
                remover_Funcionario_Inicio(L);
                break;
            case 4:
                remover_Funcionario_Codigo(L);
                break;
            default:
                break;

        }

    } while ( opcao != 5 );

}

// Funcao para Remover Funcionario no Final da Lista
void remover_Funcionario_Final(TipoLista *L) 
{

    if (L->Primeiro == NULL) 
    {
        tela();

        gotoxy(24,7);
        printf("Lista vazia! Nenhum funcionario para remover.");

        getch();

        return;

    }

    TipoApontador atual = L->Primeiro;
    TipoApontador anterior = NULL;

    while (atual->proximo != NULL) 
    {
        anterior = atual;
        atual = atual->proximo;
    }

    tela();

    gotoxy(24,7);
    printf("Deseja apagar este usuario? Codigo: %d, Nome: %s (1=Sim, 2=Nao): ", atual->conteudo.codigo, atual->conteudo.nome);

    int confirma;
    scanf("%d", &confirma);

    if (confirma == 1) 
    {
        if (anterior == NULL) // só tinha um elemento
        { 
            L->Primeiro = NULL;
            L->Ultimo = NULL;

        } else {

            anterior->proximo = NULL;
            L->Ultimo = anterior;
        }

        free(atual);

        tela();

        gotoxy(24,7);
        printf("Funcionario removido com sucesso!");

    } else {

        tela();

        gotoxy(24,7);
        printf("Remocao cancelada!");

    }

    getch();

}

// Funcao para Remover Funcionario em uma Posicao da Lista
void remover_Funcionario_Posicao(TipoLista *L) 
{

    if (L->Primeiro == NULL) 
    {

        tela();

        gotoxy(24,7);
        printf("Lista vazia!");

        getch();

        return;

    }

    int pos;

    tela();

    gotoxy(24,7);
    printf("Digite a posicao a remover: ");
    scanf("%d", &pos);

    int total = contar_elementos(L);

    if (pos < 1 || pos > total) 
    {

        tela();

        gotoxy(24,7);
        printf("Posicao invalida! Existem %d funcionarios.", total);

        getch();

        return;
    }

    TipoApontador atual = L->Primeiro;
    TipoApontador anterior = NULL;

    for (int i=1; i<pos; i++) 
    {
        anterior = atual;
        atual = atual->proximo;
    }

    tela();

    gotoxy(24,7);
    printf("Deseja apagar este usuario? Codigo: %d, Nome: %s (1=Sim, 2=Nao): ", atual->conteudo.codigo, atual->conteudo.nome);

    int confirma;
    scanf("%d", &confirma);

    if (confirma == 1) 
    {
        if (anterior == NULL) // remover primeiro
        { 
            L->Primeiro = atual->proximo;

            if (L->Primeiro == NULL) 
            {
                L->Ultimo = NULL;
            }

        } else {

            anterior->proximo = atual->proximo;

            if (anterior->proximo == NULL) 
            {
                L->Ultimo = anterior;
            }
        }

        free(atual);

        tela();

        gotoxy(24,7);
        printf("Funcionario removido com sucesso!");

    } else {

        tela();

        gotoxy(24,7);
        printf("Remocao cancelada!");
    }

    getch();
}

// Funcao para Remover Funcionario no Inicio da Lista
void remover_Funcionario_Inicio(TipoLista *L) 
{

    if (L->Primeiro == NULL) 
    {
        tela();

        gotoxy(24,7);
        printf("Lista vazia!");

        getch();

        return;

    }

    TipoApontador atual = L->Primeiro;

    tela();

    gotoxy(24,7);
    printf("Deseja apagar este usuario? Codigo: %d, Nome: %s (1=Sim, 2=Nao): ", atual->conteudo.codigo, atual->conteudo.nome);

    int confirma;
    scanf("%d", &confirma);

    if (confirma == 1) 
    {

        L->Primeiro = atual->proximo;

        if (L->Primeiro == NULL) 
        {
            L->Ultimo = NULL;
        }

        free(atual);

        tela();

        gotoxy(24,7);
        printf("Funcionario removido com sucesso!");

    } else {

        tela();

        gotoxy(24,7);
        printf("Remocao cancelada!");

    }

    getch();

}

// Funcao para Remover Funcionario pelo Codigo
void remover_Funcionario_Codigo(TipoLista *L) 
{

    if (L->Primeiro == NULL) 
    {
        tela();

        gotoxy(24,7);
        printf("Lista vazia!");

        getch();

        return;

    }

    int codigo;

    tela();

    gotoxy(24,7);
    printf("Digite o codigo do funcionario a remover: ");
    scanf("%d", &codigo);

    TipoApontador atual = L->Primeiro;
    TipoApontador anterior = NULL;

    while (atual != NULL && atual->conteudo.codigo != codigo) 
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) 
    {
        tela();

        gotoxy(24,7);
        printf("Funcionario com codigo %d nao encontrado!", codigo);

        getch();

        return;

    }

    tela();
    gotoxy(24,7);
    printf("Deseja apagar este usuario? Codigo: %d, Nome: %s (1=Sim, 2=Nao): ", atual->conteudo.codigo, atual->conteudo.nome);

    int confirma;
    scanf("%d", &confirma);

    if (confirma == 1) 
    {
        if (anterior == NULL)  // remover primeiro
        {
            L->Primeiro = atual->proximo;
            if (L->Primeiro == NULL) 
            {
                L->Ultimo = NULL;
            }

        } else {

            anterior->proximo = atual->proximo;

            if (anterior->proximo == NULL) 
            {
                L->Ultimo = anterior;
            }

        }

        free(atual);

        tela();

        gotoxy(24,7);
        printf("Funcionario removido com sucesso!");

    } else {

        tela();

        gotoxy(24,7);
        printf("Remocao cancelada!");

    }

    getch();

}

// Funcao para Menu de Consultar
void menu_consultar_Funcionarios ( TipoLista *L )
{

    int opcao;

    do
    {
        tela();

        gotoxy(20,03);
        printf("--- MENU DE CONSULTA ---");

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
        printf("Digite sua Opcao.: ");
        scanf("%d", &opcao);

        system("cls");

        switch ( opcao )
        {

            case 1:
                consultar_lista(L);
                break;
            case 2:
                consultar_codigo_unico(L);
                break;
            case 3:
                consultar_ordem_alfabetica(L);
                break;
            case 4:
                consultar_ordem_codigo(L);
                break;
            default:
                break;

        }

    } while ( opcao != 5 );
    
}

// Funcao para Consultar por Lista
void consultar_lista ( TipoLista *L )
{
    TipoApontador aux = L->Primeiro;
    int lin = 7;

    if (aux == NULL) {
        tela();
        gotoxy(24,7);
        printf("Lista vazia! Nenhum funcionario cadastrado.");
        getch();
        return;
    }

    tela();

    gotoxy(10,3);
    printf("-- Lista de Todos os Funcionarios --");

    gotoxy(2,5);  
    printf("Cod:");

    gotoxy(8,5);  
    printf("Nome:");

    gotoxy(36,5); 
    printf("CPF:");

    gotoxy(50,5); 
    printf("Telefone:");

    gotoxy(67,5); 
    printf("Dt_Nasc:");

    gotoxy(2,6);
    printf("----------------------------------------------------------------------------");

    while (aux != NULL) 
    {
        gotoxy(3, lin);  
        printf("%d", aux->conteudo.codigo);

        gotoxy(8, lin);  
        printf("%s", aux->conteudo.nome);

        gotoxy(33, lin); 
        printf("%s", aux->conteudo.cpf);

        gotoxy(50, lin); 
        printf("%s", aux->conteudo.telefone);
        
        gotoxy(67, lin); 
        printf("%s", aux->conteudo.dt_nasc);

        lin++;

        if (lin > 22 && aux->proximo != NULL) 
        {

            gotoxy(07,23);
            printf("Pressione qualquer tecla para continuar...");

            getch();
            tela();

            gotoxy(10,3);
            printf("-- Lista de Todos os Funcionarios (continua) --");

            gotoxy(2,5);  
            printf("Cod:");

            gotoxy(8,5);  
            printf("Nome:");

            gotoxy(36,5); 
            printf("CPF:");

            gotoxy(50,5); 
            printf("Telefone:");

            gotoxy(67,5); 
            printf("Dt_Nasc:");

            gotoxy(2,6);
            printf("----------------------------------------------------------------------------");
            lin = 7;
        }
        aux = aux->proximo;
    }

    gotoxy(07,23);
    printf("Ver salario, cargo e departamento use consulta por codigo especifico!");
    getch();
}



// Funcao para Consultar por Codigo Especifico
void consultar_codigo_unico ( TipoLista *L )
{

    int resp;
    int codigo;
    TipoApontador resultado;

    do
    {

        tela();

        gotoxy(24,5);
        printf("CONSULTA DE FUNCIONARIO");

        gotoxy(24,7);
        printf("CODIGO.............: ");

        gotoxy(45,7);
        scanf("%d", &codigo);

        resultado = pesquisa (L,codigo);

        system("cls");
        tela();

        if ( resultado != NULL )
        {

            gotoxy(24,5);
            printf("Funcionario Encontrado!");

            gotoxy(24,7);
            printf("CODIGO.............: %d", resultado->conteudo.codigo);

            gotoxy(24,8);
            printf("NOME...............: %s", resultado->conteudo.nome);

            gotoxy(24,9);
            printf("SALARIO............: %.2f", resultado->conteudo.salario);

            gotoxy(24,10);
            printf("ENDERECO...........: %s", resultado->conteudo.endereco);

            gotoxy(24,11);
            printf("DATA DE NASCIMENTO.: %s", resultado->conteudo.dt_nasc);

            gotoxy(24,12);
            printf("TELEFONE...........: %s", resultado->conteudo.telefone);

            gotoxy(24,13);
            printf("CPF................: %s", resultado->conteudo.cpf);

            gotoxy(24,14);
            printf("CARGO..............: %s", resultado->conteudo.cargo);

            gotoxy(24,15);
            printf("DEPARTAMENTO.......: %s", resultado->conteudo.departamento);

        } else {

            gotoxy(24,7);
            printf("Funcionario com codigo %d nao encontrado!", codigo);

        }

        gotoxy(07,23);
        printf("Deseja realizar outra consulta? (1 = Sim, 2 = Nao) ");
        scanf("%d", &resp);

    } while (resp == 1);

}

// Funcao para Consultar por Ordem Alfabetica
void consultar_ordem_alfabetica ( TipoLista *L )
{
    int n = 0;
    TipoApontador aux = L->Primeiro;

    while (aux != NULL) 
    { 
        n++; aux = aux->proximo; 
    }
    if (n == 0) { 
        tela(); 
        
        gotoxy(24,7); 
        printf("Lista vazia!"); 
        getch(); 

        return; 
    }

    reg_funcionario *vet = (reg_funcionario*) malloc(n * sizeof(reg_funcionario));
    aux = L->Primeiro;

    for (int i=0; i<n; i++) 
    { 
        vet[i] = aux->conteudo; 
        aux = aux->proximo; 
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (strcmp(vet[i].nome, vet[j].nome) > 0) {
                reg_funcionario tmp = vet[i]; 
                vet[i] = vet[j]; 
                vet[j] = tmp;
            }
        }
    }

    int lin = 7;
    tela();

    gotoxy(10,3);
    printf("-- Lista Funcionarios Ordem Alfabetica --");

    gotoxy(2,5);  
    printf("Cod:");

    gotoxy(8,5);  
    printf("Nome:");

    gotoxy(36,5); 
    printf("CPF:");

    gotoxy(50,5); 
    printf("Telefone:");

    gotoxy(67,5); 
    printf("Dt_Nasc:");

    gotoxy(2,6);
    printf("----------------------------------------------------------------------------");

    for (int i=0; i<n; i++) 
    {
        gotoxy(3, lin);  
        printf("%d", vet[i].codigo);

        gotoxy(8, lin);  
        printf("%s", vet[i].nome);

        gotoxy(33, lin); 
        printf("%s", vet[i].cpf);

        gotoxy(50, lin); 
        printf("%s", vet[i].telefone);

        gotoxy(67, lin); 
        printf("%s", vet[i].dt_nasc);

        lin++;
        if (lin > 22 && i < n-1) 
        {
            
            gotoxy(07,23);
            printf("Pressione qualquer tecla para continuar...");

            getch();
            tela();

            gotoxy(10,3);
            printf("-- Lista Funcionarios Ordem Alfabetica (continua) --");

            gotoxy(2,5);  
            printf("Cod:");

            gotoxy(8,5);  
            printf("Nome:");

            gotoxy(36,5); 
            printf("CPF:");

            gotoxy(50,5); 
            printf("Telefone:");

            gotoxy(67,5); 
            printf("Dt_Nasc:");

            gotoxy(2,6);
            printf("----------------------------------------------------------------------------");
            lin = 7;
        }
    }

    free(vet);
    gotoxy(07,23);
    printf("Ver salario, cargo e departamento use consulta por codigo especifico!");
    getch();
}


// Funcao para Consultar por Ordem de Codigo
void consultar_ordem_codigo ( TipoLista *L )
{
    int n = 0;
    TipoApontador aux = L->Primeiro;

    while (aux != NULL) 
    { 
        n++; aux = aux->proximo; 
    }
    if (n == 0) 
    {
        tela(); 
        gotoxy(24,7); 
        printf("Lista vazia!"); 
        getch(); 

        return; 
    }

    reg_funcionario *vet = (reg_funcionario*) malloc(n * sizeof(reg_funcionario));
    aux = L->Primeiro;
    for (int i=0; i<n; i++) 
    { 
        vet[i] = aux->conteudo; 
        aux = aux->proximo; 
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (vet[i].codigo > vet[j].codigo) {
                reg_funcionario tmp = vet[i]; 
                vet[i] = vet[j]; 
                vet[j] = tmp;
            }
        }
    }

    int lin = 7;
    tela();

    gotoxy(10,3);
    printf("-- Lista Funcionarios Ordem de Codigo --");

    gotoxy(2,5);  
    printf("Cod:");

    gotoxy(8,5);  
    printf("Nome:");

    gotoxy(36,5); 
    printf("CPF:");

    gotoxy(50,5); 
    printf("Telefone:");

    gotoxy(67,5); 
    printf("Dt_Nasc:");

    gotoxy(2,6);
    printf("----------------------------------------------------------------------------");

    for (int i=0; i<n; i++) 
    {
        gotoxy(3, lin);  
        printf("%d", vet[i].codigo);

        gotoxy(8, lin);  
        printf("%s", vet[i].nome);

        gotoxy(33, lin); 
        printf("%s", vet[i].cpf);

        gotoxy(50, lin); 
        printf("%s", vet[i].telefone);

        gotoxy(67, lin); 
        printf("%s", vet[i].dt_nasc);

        lin++;
        if (lin > 22 && i < n-1) 
        {

            gotoxy(07,23);
            printf("Pressione qualquer tecla para continuar...");

            getch();
            tela();

            gotoxy(10,3);
            printf("-- Lista Funcionarios Ordem de Codigo (continua) --");

            gotoxy(2,5);  
            printf("Cod:");

            gotoxy(8,5);  
            printf("Nome:");

            gotoxy(36,5); 
            printf("CPF:");

            gotoxy(50,5); 
            printf("Telefone:");

            gotoxy(67,5); 
            printf("Dt_Nasc:");

            gotoxy(2,6);
            printf("----------------------------------------------------------------------------");

            lin = 7;
        }
    }

    free(vet);
    gotoxy(07,23);
    printf("Ver salario, cargo e departamento use consulta por codigo especifico!");
    getch();
}


// Funcao para Alterar Funcionario da Lista
void alterar_Funcionario ( TipoLista *L )
{
    int resp; 
    int codigo; 
    int opcao;
    TipoApontador resultado;

    do {
        tela();
        gotoxy(24,5);
        printf("ALTERACAO DE FUNCIONARIO");

        gotoxy(24,7);
        printf("DIGITE O CODIGO....: ");
        gotoxy(45,7);
        scanf("%d", &codigo);

        resultado = pesquisa(L, codigo);

        system("cls");
        tela();

        if (resultado == NULL) 
        {
            gotoxy(24,9);
            printf("Funcionario nao encontrado!");

        } else {

            // Exibir dados atuais
            gotoxy(24,5); 
            printf("Funcionario Encontrado!");

            gotoxy(24,7); 
            printf("CODIGO.............: %d", resultado->conteudo.codigo);

            gotoxy(24,8); 
            printf("1 - NOME...............: %s", resultado->conteudo.nome);

            gotoxy(24,9); 
            printf("2 - SALARIO............: %.2f", resultado->conteudo.salario);

            gotoxy(24,10); 
            printf("3 - ENDERECO...........: %s", resultado->conteudo.endereco);

            gotoxy(24,11); 
            printf("4 - DATA DE NASCIMENTO.: %s", resultado->conteudo.dt_nasc);

            gotoxy(24,12); 
            printf("5 - TELEFONE...........: %s", resultado->conteudo.telefone);

            gotoxy(24,13); 
            printf("6 - CPF................: %s", resultado->conteudo.cpf);

            gotoxy(24,14); 
            printf("7 - CARGO..............: %s", resultado->conteudo.cargo);

            gotoxy(24,15); 
            printf("8 - DEPARTAMENTO.......: %s", resultado->conteudo.departamento);

            gotoxy(07,23);
            printf("Qual campo deseja alterar? ");
            scanf("%d", &opcao);

            system("cls");
            tela();

            switch(opcao) 
            {

                case 1:

                    gotoxy(24,7); 
                    printf("NOME ATUAL.........: %s", resultado->conteudo.nome);

                    gotoxy(24,8); 
                    printf("NOME NOVO..........: ");

                    scanf(" %49[^\n]", resultado->conteudo.nome);

                    break;

                case 2:

                    gotoxy(24,7); 
                    printf("SALARIO ATUAL......: %.2f", resultado->conteudo.salario);

                    gotoxy(24,8); 
                    printf("SALARIO NOVO.......: ");

                    scanf("%f", &resultado->conteudo.salario);

                    break;

                case 3:

                    gotoxy(24,7); 
                    printf("ENDERECO ATUAL.....: %s", resultado->conteudo.endereco);

                    gotoxy(24,8); 
                    printf("ENDERECO NOVO......: ");

                    scanf(" %59[^\n]", resultado->conteudo.endereco);

                    break;

                case 4:

                    gotoxy(24,7); 
                    printf("DATA NASC. ATUAL...: %s", resultado->conteudo.dt_nasc);

                    gotoxy(24,8); printf("DATA NASC. NOVA....: ");

                    scanf(" %14s", resultado->conteudo.dt_nasc);

                    break;

                case 5:

                    gotoxy(24,7); 
                    printf("TELEFONE ATUAL.....: %s", resultado->conteudo.telefone);

                    gotoxy(24,8); 
                    printf("TELEFONE NOVO......: ");

                    scanf(" %19s", resultado->conteudo.telefone);

                    break;

                case 6:

                    gotoxy(24,7); 
                    printf("CPF ATUAL..........: %s", resultado->conteudo.cpf);

                    gotoxy(24,8); 
                    printf("CPF NOVO...........: ");

                    scanf(" %14s", resultado->conteudo.cpf);

                    break;
                case 7:

                    gotoxy(24,7); 
                    printf("CARGO ATUAL........: %s", resultado->conteudo.cargo);

                    gotoxy(24,8); 
                    printf("CARGO NOVO.........: ");

                    scanf(" %39[^\n]", resultado->conteudo.cargo);
                    break;

                case 8:

                    gotoxy(24,7); 
                    printf("DEPARTAMENTO ATUAL.: %s", resultado->conteudo.departamento);

                    gotoxy(24,8); 
                    printf("DEPARTAMENTO NOVO..: ");

                    scanf(" %29[^\n]", resultado->conteudo.departamento);
                    break;

                default:

                    gotoxy(24,7); 
                    printf("Opcao invalida!");

                    break;
            }

            system("cls");
            tela();
            gotoxy(24,7);
            printf("Alteracao realizada com sucesso!");
        }

        gotoxy(07,23);
        printf("Deseja alterar outro funcionario? (1 = Sim, 2 = Nao): ");
        scanf("%d", &resp);

    } while (resp == 1);
}

// Funcao para Gravar no Disco
void gravar_lista( TipoLista *L )
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

    TipoApontador aux = L->Primeiro;

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
void le_arquivo_lista ( TipoLista *L )
{

    FILE *ptr;
    char *Filename = "funcionarios.dat";
    char *modo_leitura = "rb";

    ptr = fopen ( Filename, modo_leitura );
    if ( ptr == NULL ) 
    {

        L->Primeiro = NULL;
        L->Ultimo = NULL;

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

        if ( L->Primeiro == NULL )
        {

            L->Primeiro = p;

        } else {

            L->Ultimo->proximo = p;

        }

        L->Ultimo = p;

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
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;

    // Carregar dados guardados no Disco
    le_arquivo_lista(&L);

    // Layout
    system("color 17");
    system("cls");
    
    // Hub do programa
    do
    {
        
        tela();

        gotoxy(24,7);
        printf("1 - Cadastrar Funcionario");
        gotoxy(24,9);
        printf("2 - Remover Funcionario");
        gotoxy(24,11);
        printf("3 - Consultar Todos os Funcionarios");
        gotoxy(24,13);
        printf("4 - Alterar Dados de Funcionarios");
        gotoxy(24,15);
        printf("5 - Finalizar Programa");

        gotoxy(07,23);
        scanf("%d", &opcao);

        system("cls");

        switch(opcao)
        {
            case 1:
                menu_cadastros(&L);
                break;
            case 2:
                menu_remover(&L);
                break;
            case 3:
                menu_consultar_Funcionarios(&L);
                break;
            case 4:
                alterar_Funcionario(&L);
                break;
            default:
                break;
        }
        
    } while ( opcao != 5 );

    gravar_lista(&L);

    return 0;

}
