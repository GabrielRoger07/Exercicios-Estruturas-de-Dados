#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *busca(celula *le, int x){
    celula *p;
    for(p = le->prox; p != NULL && p->dado != x; p = p->prox){
    }
    return p;
}

celula *busca_rec (celula *le, int x){
    celula *p = le->prox;
    if(p == NULL || p->dado == x){
        return p;
    }else{
        busca_rec(p, x);
    }
}

/*int main(int argc, char const *argv[])
{
    celula le, no1, no2, no3;

    no1.dado =1;
    no2.dado =2;
    no3.dado =3;

    le.prox = &no1;
    no1.prox = &no2;
    no2.prox = &no3;
    no3.prox = NULL;

    //celula *retorno = busca(&le, 3);
    printf("%p\n", busca(&le, 3));
    printf("%p\n", busca_rec(&le, 3));
    
    if(retorno == NULL){
        printf("Elemento nao encontrado\n");
    }else{
        printf("Elemento encontrado, endereco do no: %p\n", retorno);
    }
    return 0
}*/
