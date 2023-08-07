#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {int aux = B; B = A; A = aux;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

int main(int argc, char const *argv[]){

    int quantProd, pagina, produtosPorPagina, posicaoInicial, posicaoFinal;
    scanf("%d %d %d", &quantProd, &pagina, &produtosPorPagina);
    int *produtos = malloc(quantProd * sizeof(int));

    posicaoInicial = produtosPorPagina * pagina;
    posicaoFinal = posicaoInicial + produtosPorPagina;

    if(posicaoFinal > quantProd){
        posicaoFinal = quantProd;
    }

    for(int i = 0; i < quantProd; i++){
        scanf("%d", &produtos[i]);
    }

    quickSelect(produtos, 0, quantProd-1, posicaoInicial);
    quickSelect(produtos, posicaoInicial+1, quantProd-1, posicaoFinal);
    quickSort(produtos, posicaoInicial, posicaoFinal-1);
    for(int i = posicaoInicial; i < posicaoFinal; i++){
        printf("%d\n", produtos[i]);
    }
    free(produtos);

    return 0;
}

void quickSelect(int *v, int l, int r, int p){
    if(l >= r) return;
    int j = separa(v, l, r);
    if(j > p){
        quickSelect(v, l, j-1, p);
    }else if(j < p){
        quickSelect(v, j+1, r, p);
    }
}

void quickSort(int *v, int l, int r){
    if(l >= r) return;
    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);
    int j = separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

int separa(int *v, int l, int r){
    int j = l, c = v[r];
    for(int i = l; i < r ;i++){
        if(less(v[i], c)){
            exch(v[i], v[j]);
        j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}
