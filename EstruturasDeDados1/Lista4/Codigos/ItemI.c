#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

typedef struct fila{
    celula *i;
    celula *u;
}fila;

fila *cria_fila(){
    fila *f = malloc(sizeof(fila));
    f->i = NULL;
    f->u = NULL;
    return f;
}

void *empilha(fila *f, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = NULL;
    if(f->i == NULL){
        f->i = novo;
        f->u = novo;
    }else{
        f->u->prox = novo;
        f->u = novo;
    }
}

int desenfileira(fila *f){
    int x;
    celula *lixo = malloc(sizeof(celula));
    lixo = f->i;
    x = lixo->dado;
    f->i = lixo->prox;
    if(f->i == NULL){
        f->u = NULL;
    }
    free(lixo);
    return x;
}

int main(int argc, char const *argv[])
{
    int n, cont = 0;
    fila *f;
    f = cria_fila();
    scanf("%d", &n);
    
    for(int i = 1;i<=n;i++){
        empilha(f,i);
    }

    printf("Cartas descartadas:");
    while(n > 2){
        printf(" %d", desenfileira(f));
        empilha(f,desenfileira(f)); 
        printf(",");
        n--;
    }

    printf(" %d", desenfileira(f));
    empilha(f,desenfileira(f));

    printf("\nCarta restante: %d\n", desenfileira(f));

    return 0;
}