#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TH[101];

int hash(char *key){
    int total = 0;
    for(int i = 0; i < strlen(key); i++){
        total += (key[i]*(i + 1LL));
    }
    return (19 * total) % 101;
}

int verifica_colisao(char *palavra){
    int j = hash(palavra), proximaPosicao;

    for(int i = 0; i < 20; i++){
        proximaPosicao = (j+i*i+23LL*i) % 101;
        if(TH[proximaPosicao] != NULL && strcmp(TH[proximaPosicao], palavra) == 0){
            return 0; 
        }
    }
    return 1;
}

void resolveCaso(){
    int quantOperacoes, tamanho = 0;
    char key[25];
    scanf("%d", &quantOperacoes); 

    for(int i = 0; i < quantOperacoes; i++){
        TH[i] = NULL;
    }

    for(int i = 0; i < quantOperacoes; i++){
        scanf("%s", key);
        char *palavra = &key[4];

        if(key[0] == 'A'){
            if(verifica_colisao(palavra)){
                int j = hash(palavra), proximaPosicao;
                for(int k = 0; k < 20; k++){
                    proximaPosicao = (j + k*k + 23LL*k) % 101;
                    if(TH[proximaPosicao] == NULL){ 
                        TH[proximaPosicao] = malloc(sizeof(char)*(strlen(palavra)+1));
                        strcpy(TH[proximaPosicao], palavra);
                        tamanho++;
                        break;
                    }
                }
            }

        } else if(key[0] == 'D'){
            int j = hash(palavra), proximaPosicao;
            for (int k = 0; k < 20; k++){
                proximaPosicao = (j + k*k + 23LL*k) % 101;
                if(TH[proximaPosicao] != NULL && strcmp(TH[proximaPosicao], palavra) == 0){
                    free(TH[proximaPosicao]);
                    TH[proximaPosicao] = NULL;
                    tamanho--;
                    break;
                }
            }
        }
    }

    printf("%d\n", tamanho);
    for(int i = 0; i < 101; i++){
        if(TH[i] != NULL){
            printf("%d:%s\n", i, TH[i]);
        }
    }
}

int main(void){
    int quantCasos;
    scanf("%d", &quantCasos);
    for(int i = 0; i < quantCasos; i++){
        resolveCaso();
    }
    return 0;
}