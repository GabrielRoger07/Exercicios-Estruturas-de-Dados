#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int *dado;
    int N;
    int topo;
}pilha;

/*pilha *cria_pilha(){
    pilha *p = malloc(sizeof(pilha));
    p->N = 10;
    p->dado = malloc(p->N*sizeof(int));
    p->topo = 0;
    return p;
}

int empilha(pilha *p, int x){
    if(p->topo == p->N){
        p->dado = realloc(p->dado, (2*p->N)*sizeof(pilha));
        if(p->dado == NULL){
            return 0;
        }else{
            p->N*=2;
        }
    }
    p->dado[p->topo] = x;
    p->topo++;
    return 1;
}*/

int desempilha(pilha *p, int *y){
    if(p->topo == 0){
        return 0;
    }else{
        p->topo--;
        *y = p->dado[p->topo];
        return 1;
    }
}

/*int main(int argc, char const *argv[])
{
    int y;
    pilha *p = cria_pilha();
    printf("valor do topo: %d\n", p->topo);
    empilha(p, 1);
    printf("valor do topo: %d\n", p->topo);
    empilha(p, 2);
    printf("valor do topo: %d\n", p->topo);
    empilha(p, 3);
    printf("valor do topo: %d\n", p->topo);
    desempilha(p, &y);
    printf("valor do topo: %d\n", p->topo);

    return 0;
}*/
