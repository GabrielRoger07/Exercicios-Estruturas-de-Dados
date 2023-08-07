#include <stdio.h>

int main(int argc, char const *argv[])
{
    int quantStrings, soma = 0, resultados[1000];
    char string[101];

    scanf("%d", &quantStrings);
    somaString(quantStrings, string, resultados);
    for(int i = 0; i < quantStrings; i++){
        printf("%d\n", resultados[i]);
    }

    return 0;
}

int somaString(int quant, char string[], int resultados[]){
    for(int i = 0; i < quant; i++){
        int j = 0, soma = 0;
        scanf(" %[^\n]", string);
        while(string[j] != '\0'){
            if(string[j] >= 49 && string[j] <= 57){
                soma += string[j] - '0';
            }
            j++;
        }
        resultados[i] = soma;
    }
}
