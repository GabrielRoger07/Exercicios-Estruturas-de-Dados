#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    struct celula *prox;
    struct no *dado;
}celula;

typedef struct no{
    int dado;
    struct no *esq, *dir;
}no;

int *desempilha(celula **p){
    celula *lixo = *p;
    no *y = lixo->dado;
    *p = lixo -> prox;
    free(lixo);
    return y;
}

void empilha(celula **p, no *n){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = n;
    novo -> prox = *p;
    *p = novo;
}

void pre_ordem(no *raiz){
    no *temp = raiz;
    celula *pilha_temp = NULL;
    int val = 1;
    while(val != 0){
        if(temp){
            printf("%d", temp->dado);
            empilha(&pilha_temp, temp);
            temp = temp->esq;
        }else{
            if(pilha_temp != NULL){
                temp = desempilha(&pilha_temp);
                temp = temp->dir;
            }else{
                val = 0;
            }
        }
    }
}