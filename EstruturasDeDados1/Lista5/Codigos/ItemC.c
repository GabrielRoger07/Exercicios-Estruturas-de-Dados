#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int N;
    int topo;
    struct no *array;
}pilha;

typedef struct no{
    int dado;
    struct no *esq, *dir;
}no;

no *novo_no(int dado){
    no *novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

pilha *cria_pilha(int tamanho){
    pilha *pilha = malloc(sizeof(pilha));
    pilha->N = tamanho;
    pilha->topo = 1;
    pilha->array = malloc(tamanho*sizeof(no));
    return pilha;
}

int pilha_cheia(pilha *p){
    return p->topo-1 == p->N;
}

int pilha_vazia(pilha *p){
    return p->N == -1;
}

void empilha(pilha *p, no *n){
    if(pilha_cheia(p)){
        return;
    }
    p->array[++p->topo] = n;
}
