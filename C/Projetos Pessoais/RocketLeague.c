/*
Autor: Arthur Almeida Pereira
Data: 14/10/2025
Objetivo: Informações do Arthur no Rocket League
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main (){
    
    //Variaveis
    int option = 0;
    
    //Entrada
    
    printf("=== INFO ===\n");
    printf("1 - Nick\n");
    printf("2 - Name\n");
    printf("3 - Earnings\n");
    printf("4 - Camera\n");
    printf("5 - Sensi\n\n");
    printf("0 - Finish\n\n");
    
    do {
        
        scanf("%d", &option);
        system("cls");
        switch (option) {
            
            case 1:
            printf("My nick is Alpe\n");
            printf("\n\n");
            printf("=== INFO ===\n");
            printf("1 - Nick\n");
            printf("2 - Name\n");
            printf("3 - Earnings\n");
            printf("4 - Camera\n");
            printf("5 - Sensi\n\n");
            printf("0 - Finish\n\n");

            break;
            
            
            case 2:
            printf("My name is Arthur Almeida Pereira\n");
            printf("\n\n");
            printf("=== INFO ===\n");
            printf("1 - Nick\n");
            printf("2 - Name\n");
            printf("3 - Earnings\n");
            printf("4 - Camera\n");
            printf("5 - Sensi\n\n");
            printf("0 - Finish\n\n");
            
            break;
            
            
            case 3:
            printf("My earnings on tournaments in Rocket league is $16k\n");
            printf("\n\n");
            printf("=== INFO ===\n");
            printf("1 - Nick\n");
            printf("2 - Name\n");
            printf("3 - Earnings\n");
            printf("4 - Camera\n");
            printf("5 - Sensi\n\n");
            printf("0 - Finish\n\n");
            
            break;
            
            
            case 4:
            printf("My camera is 110 | 270 | 100 | -3 | 0.35\n");
            printf("Or 110 | 270 | 90 | -5 | 0.35\n");
            printf("\n\n");
            printf("=== INFO ===\n");
            printf("1 - Nick\n");
            printf("2 - Name\n");
            printf("3 - Earnings\n");
            printf("4 - Camera\n");
            printf("5 - Sensi\n\n");
            printf("0 - Finish\n\n");
            
            break;
            
            
            case 5:
            printf("My sensibility is 1.50 and 2.00 | deadzone is 0.09 and 0.81\n");
            printf("\n\n");
            printf("=== INFO ===\n");
            printf("1 - Nick\n");
            printf("2 - Name\n");
            printf("3 - Earnings\n");
            printf("4 - Camera\n");
            printf("5 - Sensi\n\n");
            printf("0 - Finish\n\n");
            
            break;
            
            default:
            break;
            
        }    
        
    } while (option != 0);
    
}