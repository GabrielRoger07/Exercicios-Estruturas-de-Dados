#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero, somaPar = 0, somaImpar =0;

    do{
        //printf("Insira o numero: ");
        scanf("%d", &numero);
        if(numero%2==0){
            somaPar = somaPar + numero;
        }else{
            somaImpar = somaImpar + numero;
        }
    }while(numero !=0);

    //printf("\nSoma dos pares: %d\nSoma dos impares: %d\n\n", somaPar, somaImpar);
    printf("%d %d", somaPar, somaImpar);

    return 0;
}
