#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

/*celula *cria_pilha(){
    celula *topo = malloc(sizeof(celula));
    topo->prox = NULL;
}

int empilha(celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return 0;
    }
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
    return 1;
}*/

/*int desempilha(celula *p, int *y){
    celula *lixo = p->prox;
    if(p == NULL){
        return 0;
    }else{
        *y = lixo->dado;
        p->prox = lixo->prox;
        free(lixo);
        return 1;
    }
}*/

int desempilha(celula *p, int *y){
    celula *lixo = malloc(sizeof(celula));
    lixo = p->prox;
    if(lixo == NULL){
        return 0;
    }else{
        *y = lixo->dado;
        p->prox = lixo->prox;
        free(lixo);
        return 1;
    }
}

/*int main(int argc, char const *argv[])
{
    int y;
    celula *topo = cria_pilha();
    printf("valor do topo: %s\n", topo->dado);
    empilha(topo, 1);
    printf("valor do topo: %p\n", topo->dado);
    empilha(topo, 2);
    printf("valor do topo: %d\n", topo->dado);
    empilha(topo, 3);
    printf("valor do topo: %d\n", topo->dado);
    desempilha(topo, &y);
    printf("valor do topo: %d\n", topo->dado);
    while(desempilha(topo, &y));
    free(topo);
    return 0;
}*/
