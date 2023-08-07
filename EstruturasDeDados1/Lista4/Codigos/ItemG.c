#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

int desenfileira(celula *f, int *y){
    celula *lixo = f->prox;
    if(f == NULL){
        return 0;
    }else{
        *y = lixo->dado;
        f->prox = lixo->prox;
        free(lixo);
        return 1;
    }
}

/*int main(int argc, char const *argv[])
{

    return 0;
}*/
