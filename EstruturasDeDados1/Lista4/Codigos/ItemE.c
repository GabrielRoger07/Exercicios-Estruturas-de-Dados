#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int *dados;
    int N, p, u;
}fila;

/*fila *cria_fila(){
    fila *f = malloc(sizeof(fila));
    f->N =10;
    f->dados = malloc(f->N*sizeof(int));
    f->p = f->u = 0;
    return f;
}

int enfileira(fila *f, int x){
    if((f->u+1) % f->N == f->p){
        //if(!redimensiona(f)){
            return 0;
        //}
    }
    f->dados[f->u] = x;
    f->u = (f->u+1) % f->N;
    return 1;
}*/

int desenfileira(fila *f, int *y){
    if(f->p == f->u){
        return 0;
    }
    *y = f->dados[f->p];
    f->p = (f->p+1) % f->N;
}

/*int main(int argc, char const *argv[])
{
    int y;
    fila *f = cria_fila();
    enfileira(f, 1);
    enfileira(f, 2);
    enfileira(f, 3);
    desenfileira(f, &y);
    free(f->dados);
    free(f);
    return 0;
}*/
