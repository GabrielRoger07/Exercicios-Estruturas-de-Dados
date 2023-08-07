#include <stdio.h>
#include <stdlib.h>

#define tamanho ((1<<20)+10)

char string[tamanho*2+100];

int main(int argc, char const *argv[])
{
    char *frase = &string[tamanho];
    int num, letra, menor = 0, maior = 0, aux;
    scanf("%d %c", &aux, &frase[0]);
    while(scanf("%d %c", &num, &letra) == 2){
        num -=aux;
        frase[num] = letra;
        if(num < menor) menor = num;
        else if(num > maior) maior = num;
    }
    frase[maior+1] = '\0';
    printf("%s\n", &frase[menor]);
    return 0;
}


