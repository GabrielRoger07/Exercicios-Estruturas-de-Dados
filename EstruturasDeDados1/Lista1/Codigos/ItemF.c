#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero, comparador1 = 1, comparador2 = 1;

    printf("Digite o numero: ");
    scanf("%d", &numero);
    //printf("\nVoce digitou o numero %d\n", numero);
    
    //printf("\n");
    for(int a = 1; a <= numero; a++){
        while(comparador1 <= a){
            printf("%02d ", a);
            comparador1++;
        }
        printf("\n");
        comparador1 =1;
    }
    printf("\n");

    for(int b = 1; b <= numero; b++){
        while(comparador2 <= b){
            printf("%02d ", comparador2);
            comparador2++;
        }
        printf("\n");
        comparador2 = 1;
    }
    printf("\n");

    return 0;
}