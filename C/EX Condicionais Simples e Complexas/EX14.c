/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 30/09/2025
Objetivo: Exercicio com IF, ELSE IF e && ( e )
*******************************************************************************/

#include <stdio.h>

int main()
{
    int horasExtras;
    int horasFaltou;
    int H;
    int Premio;
    
    printf("Informe suas horas extras....: ");
    scanf("%d", &horasExtras);
    
    printf("Informe suas horas que faltou: ");
    scanf("%d", &horasFaltou);
    
    H = horasExtras - horasFaltou;
    Premio = 0;
    
    if ((H >= 0) && (H <= 10)) { //tem que colocar 2 parenteses para o calculo funcionar
        Premio = 20;
    } else if (H <= 20) {
        Premio = 40;
    } else if (H <= 30) {
        Premio = 60;
    } else if (H <= 40) {
        Premio = 80;
    } else if (H <= 100) {
        Premio = 100;
    }
    
    printf("O premio e R$ %d", Premio);
    
    return 0;
}