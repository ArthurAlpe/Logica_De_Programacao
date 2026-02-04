/******************************************************************************
Autor: Arthur Almeida Pereira
Data: 10/10/2025
Objetivo: Faça um programa que fornece o seguinte menu de opções:
A- Cálculo da área do círculo (3,14 * raio * raio)
B- Cálculo da área do retângulo (base x altura)
C- Cálculo da área do trapézio; ((base maior + base menor) * altura / 2)
D- Cálculo da área do triângulo (base x altura / 2)
*******************************************************************************/
#include <stdio.h>

int main()
{
    //Variaveis
    char letra;
    float raio = 0;
    float base = 0;
    float altura = 0;
    float baseMaior = 0;
    float baseMenor = 0;
    
    printf("Selecione umas das letras para o calculo da area: \n");
    printf("A- Calculo da area do circulo\n");
    printf("B- Calculo da area do retangulo\n");
    printf("C- Calculo da area do trapezio\n");
    printf("D- Calculo da area do triangulo\n");
    scanf(" %c", &letra);
    
    if (letra == 'A' || letra == 'a') {
        printf("Digite o raio do circulo: ");
        scanf("%f", &raio);
        
        float areaCirculo = 3.14 * (raio * raio);
        
        printf("A area do circulo e: %.2f", areaCirculo);
    } else if (letra == 'B' || letra == 'b') {
        printf("Digite a base do retangulo: ");
        scanf("%f", &base);
        printf("\n");
        printf("Digite a altura do retangulo: ");
        scanf("%f", &altura);
        
        float areaRetangulo = base * altura;
        
        printf("A area do retangulo e: %.2f", areaRetangulo);
    } else if (letra == 'C' || letra == 'c') {
        printf("Digite a base maior: ");
        scanf("%f", &baseMaior);
        printf("\n");
        printf("Digite a base menor: ");
        scanf("%f", &baseMenor);
        printf("\n");
        printf("Digite a altura: ");
        scanf("%f", &altura);
        
        float areaTrapezio = (baseMaior + baseMenor) * altura / 2;
        
        printf("A area do trapezio e: %.2f", areaTrapezio);
    } else if (letra == 'D' || letra == 'd') {
        printf("Digite a base: ");
        scanf("%f", &base);
        printf("\n");
        printf("Digite a altura: ");
        scanf("%f", &altura);
        
        float areaTriangulo = base * altura / 2;
        
        printf("A area do triangulo e: %.2f", areaTriangulo);
    }   else {
    printf("Digite apenas A | B | C | D\n");
    }
    

    return 0;
}
