#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

/*celula *cria_fila(){
    celula *topo = malloc(sizeof(celula));
}

void imprime_lista(celula *f){
    for(celula *p = f->prox; p->dado != NULL; p = p->prox){
        printf("%d -> ", p->dado);
    }
    printf("NULL\n");
}*/

celula *enfileira(celula *f, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return NULL;
    }else{
        //Inserindo a nova célula no início da lista
        
        novo -> prox = f->prox;
        f->prox = novo;
        f->dado = x;
        f=novo;
        
        //novo->dado = f->dado;
        //f->dado = x;

        //novo->dado = x;
        //novo->prox = f->prox;
        //f->prox = novo;

        return novo;
    }
}

/*int main(int argc, char const *argv[])
{    
    celula *cabeca = malloc(sizeof(celula));
    celula *no1 = malloc(sizeof(celula));
    celula *no2 = malloc(sizeof(celula));
    celula *no3 = malloc(sizeof(celula));

    printf("chegou aqui\n");
    cabeca->dado = NULL;
    no1->dado = 1;
    no2->dado = 2;
    no3->dado = 3;

    cabeca->prox = no1;
    no1->prox = no2;
    no2->prox = no3;
    no3->prox = cabeca;

    imprime_lista(cabeca);
    enfileira(cabeca, 4);
    //printf("chegou aqui\n");
    imprime_lista(cabeca);

    return 0;
}*/
