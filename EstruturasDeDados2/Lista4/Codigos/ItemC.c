#include <stdio.h>
#include <stdlib.h>

typedef struct tradutor{
    char palavraJapones[81];
    char traducao[81];
}tradutor;

int main()
{
    int quantInstancias, quantPalavras, quantLinhas, i = 0;
    scanf(" %d", &quantInstancias);
    while(i < quantInstancias) {

        scanf(" %d %d", &quantPalavras, &quantLinhas);

        char musica[quantLinhas][81];
        tradutor *dicionario = malloc(quantPalavras * sizeof(tradutor));

        for(int j = 0; j < quantPalavras; j++) {
            scanf(" %[^\n]", dicionario[j].palavraJapones);
            scanf(" %[^\n]", dicionario[j].traducao);
        }

        for(int j = 0; j < quantLinhas; j++){
            scanf(" %[^\n]", musica[j]);
        }
        traducao(quantLinhas, quantPalavras, musica, dicionario);

        free(dicionario);
        i++;
        printf("\n");
    }

    return 0;
}

void verifica(char auxiliar[81], int quantPalavras, tradutor *dicionario, int tamanhoPalavra) {
    for(int i = 0; i < quantPalavras; i ++) {
        for(int j = 0; j < tamanhoPalavra; j ++) {
            if(auxiliar[j] == dicionario[i].palavraJapones[j] && j == (tamanhoPalavra - 1) && dicionario[i].palavraJapones[j+1] == '\0') {
                printf("%s ", dicionario[i].traducao);
                return;
            }
            else if(auxiliar[j] == dicionario[i].palavraJapones[j]){
                continue;
            }
            else{
                break;
            }
        }
    }
    printf("%s ", auxiliar);
}

void traducao(int quantLinhas, int quantPalavras, char musica[quantLinhas][81], tradutor *dicionario) {
    int k = 0;
    char auxiliar[81];

    for(int i = 0; i < quantLinhas; i ++) {
        for(int j = 0; musica[i][j] != '\0'; j ++) {
            if(musica[i][j] == ' ') {
                auxiliar[k++] = '\0';
                verifica(auxiliar, quantPalavras, dicionario, k-1);
                k = 0;
            } else if(musica[i][j+1] == '\0') {
                auxiliar[k++] = musica[i][j];
                auxiliar[k++] = '\0';
                verifica(auxiliar, quantPalavras, dicionario, k-1);
                k = 0;
            } else{
                auxiliar[k++] = musica[i][j];
        }
        printf("\n");
        }
    }
}