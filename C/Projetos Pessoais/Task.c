/*
Autor: Arthur Almeida Pereira
Data: 02/03/2026
Objetivo: Gerenciador de tarefas
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Funcao de tela
void tela(){
    int l;
    int c;

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
    printf("ARTHUR ALMEIDA PEREIRA");
    gotoxy(62,2);
    printf("Estrutura de Dados");
    gotoxy(67,3);
    printf("Prof. Rodney");
    gotoxy(02,23);
    printf("MSG: ");

}

int main(){

    

    return 0;
}