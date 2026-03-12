/*
Autor: Arthur Almeida Pereira
Data: 10/03/2026
Objetivo: Jogo da velha
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


// Funcao GOTOXY, funcao para setar onde o cursor vai ir
void gotoxy(int x, int y) 
{

    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int verificarVitoria(int tabuleiro[])
{
    // Vitoria por linha
    if (tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[0] != 0)
        return tabuleiro[0];

    if (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[3] != 0)
        return tabuleiro[3];

    if (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[6] != 0)
        return tabuleiro[6];

    // Vitoria por coluna
    if (tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[0] != 0)
        return tabuleiro[0];

    if (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[1] != 0)
        return tabuleiro[1];

    if (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[2] != 0)
        return tabuleiro[2];

    // Vitoria pelas diagonais
    if (tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[0] != 0)
        return tabuleiro[0];

    if (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[2] != 0)
        return tabuleiro[2];

    return 0;
}

// Funcao para nao sobrescrever outra localizao
int validarLocal(int tabuleiro[], int posicao)
{
    // verifica se esta entre 1 e 9
    if (posicao < 1 || posicao > 9) {
        return 0;
    }

    // verifica se ja esta ocupada
    if (tabuleiro[posicao - 1] != 0) {
        return 0;
    }

    return 1;
}

// Funcao para limpar a linha
void limpar()
{
    gotoxy(2,7);
    printf("                                                                             ");
}

// Funcao para imprimir EMPATE
void empate()
{
    gotoxy(37,7);
    printf("EMPATE!");
}

// Funcao para posicoes
void posicoes()
{
    gotoxy(32,10);
    printf("1");
    gotoxy(40,10);
    printf("2");
    gotoxy(48,10);
    printf("3");
    gotoxy(32,14);
    printf("4");
    gotoxy(40,14);
    printf("5");
    gotoxy(48,14);
    printf("6");
    gotoxy(32,18);
    printf("7");
    gotoxy(40,18);
    printf("8");
    gotoxy(48,18);
    printf("9");

}

// Funcao para a tela
void tela()
{
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
        gotoxy(c,05);
        printf("-");
        gotoxy(c,24);
        printf("-");
    }

    gotoxy(01,1);
    printf("+");
    gotoxy(80,1);
    printf("+");
    gotoxy(1,24);
    printf("+");
    gotoxy(80,24);
    printf("+");
    gotoxy(01,5);
    printf("+");
    gotoxy(80,5);
    printf("+");
    gotoxy(32,3);
    printf("# JOGO DA VELHA #");
    gotoxy(02,21);
    printf("MSG: ");
    
}

void telaVelha()
{

    int l;

    tela();
    for ( l = 9; l < 20; l++) {
        gotoxy(36,l);
        printf("|");
        gotoxy(44,l);
        printf("|");
    }

    gotoxy(30,12);
    printf("------+-------+------");
    gotoxy(30,16);
    printf("------+-------+------");
    
}
int main()
{
    system("color 87");
    system("cls");

    int posX[9] = {32,40,48,32,40,48,32,40,48};
    int posY[9] = {10,10,10,14,14,14,18,18,18};
    int tabuleiro[9] = {0,0,0,0,0,0,0,0,0};
    int jogo = 1;
    int jogador1;
    int jogador2;
    int jogadas = 0;
    int vencedor;
    int opcao;

    tela();
    telaVelha();
    posicoes();
    
    do {
        
        jogo = 1;
        jogadas = 0;

        for (int i = 0; i < 9; i++)
            tabuleiro[i] = 0;

        system("cls");
        tela();
        telaVelha();
        posicoes();

        while (jogo) {

        
            gotoxy(25,7);
            printf("Vez do jogador 1! ( Digite a posicao ) ");
            gotoxy(64,7);
            scanf("%d", &jogador1);
            limpar();

            while (!validarLocal(tabuleiro, jogador1))
            {
                gotoxy(25,7);
                printf("Posicao invalida ou ocupada! Digite outra: ");
                gotoxy(64,7);
                scanf("%d", &jogador1);
            }

            gotoxy(posX[jogador1 - 1], posY[jogador1 - 1]);
            printf("X");

            tabuleiro[jogador1 - 1] = 1;
            
            vencedor = verificarVitoria(tabuleiro);

            if (vencedor == 1) {
                gotoxy(32,7);
                printf("Jogador 1 venceu!");
                jogo = 0;
                break;
            }

            // jogada jogador 1
            jogadas++;

            if (jogadas == 9) {
                empate();
                jogo = 0;
                break;
            }

            gotoxy(25,7);
            printf("Vez do jogador 2! ( Digite a posicao ) ");
            gotoxy(64,7);
            scanf("%d", &jogador2);
            limpar();

            while (!validarLocal(tabuleiro, jogador2))
            {
                gotoxy(25,7);
                printf("Posicao invalida ou ocupada! Digite outra: ");
                gotoxy(64,7);
                scanf("%d", &jogador2);
            }

            gotoxy(posX[jogador2 - 1], posY[jogador2 - 1]);
            printf("O");

            tabuleiro[jogador2 - 1] = 2;

            vencedor = verificarVitoria(tabuleiro);

            // jogada jogador 2
            jogadas++;

            if (jogadas == 9) {
                empate();
                jogo = 0;
                break;
            }

            if (vencedor == 2) {
            gotoxy(32,7);
            printf("Jogador 2 venceu!");
            jogo = 0;
            break;
            }

        }

        gotoxy(7,21);
        system("pause");
        limpar();

        gotoxy(20,7);
        printf("Deseja reiniciar? ( 1 = Sim | 2 = Nao ) ");
        gotoxy(60,7);
        scanf("%d", &opcao);

    } while ( opcao == 1 );

 
    return 0;
}