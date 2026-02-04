/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int A;
    int B;
    int Y;
    
    printf("Para saber o valor de Y");
    printf("\n");
    printf("Informe o numero A...: ");
    scanf("%d", &A);
    
    printf("Informe o numero B...: ");
    scanf("%d", &B);
    
    if (A < B) {
        Y = B - A;
        printf("%d = %d - %d", B - A, B, A);
    } else if (A > B) {
        Y = A - B;
        printf("%d = %d - %d", A - B, A, B);
    } else {
        Y = A + B;
        printf("%d = %d + %d", A + B, A, B);
    }
    
    printf("\n");
    printf("O valor do Y e %d, o valor de A e %d e o valor de B e %d", Y, A, B);
    

    return 0;
}