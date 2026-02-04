#include <stdio.h>

int calculo(num1){
    int result;
    result = 5 + num1;
    return result;
}
void imprimirTela(){
    printf("+-----------------+\n");
    printf("|                 |\n");
    printf("|                 |\n");
    printf("+-----------------+\n");
}

int main(){
    int resultado;
    int num1 = 6;
    resultado = calculo(num1);
    printf("%d", resultado);
}