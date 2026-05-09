/*
Autor: Arthur Almeida Pereira
Data: 30/04/2026
Objetivo: Lista Duplamente Encadeada
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

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

    TipoApontador anterior;
    reg_funcionario conteudo;
    TipoApontador proximo;

} TipoItem;

typedef struct
{

    TipoApontador primeiro;
    TipoApontador ultimo;

} TipoLista;

int vazia ( TipoLista lista )
{

    return ( lista.primeiro == lista.ultimo );

}

// Programa principal
int main()
{
    

    return 0;
}