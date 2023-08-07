#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)

int main(int argc, char const *argv[])
{
    int quant, tam = 1000000, posicao = 0;
    int *vetor = malloc(tam*sizeof(int));
    for(int i = 0; i < 8; i++){
        scanf("%d", &quant);
        for(int j = posicao; j < posicao+quant; j++){
            if(tam-1 == j){
                tam = tam*2;
                realloc(vetor, tam*sizeof(int));
            }
            scanf("%d", &vetor[j]);
        }
        posicao = posicao + quant;
    }
    mergeSort(vetor, 0, posicao-1);
    for(int i = 0; i < posicao; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}

void mergeSort(int *v, int l, int r){
    if(l >= r) return;
    int meio = (r-l)/2 +l;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

void merge(int *v, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;
    int *c = malloc((r-l+1)*sizeof(int));
    int ci = 0, lc = 0, rc = r-l;

    while(l1i <= r1 && l2i <= r2){
        if(less(v[l1i], v[l2i])){
            c[ci++] = v[l1i++];
        }else{
            c[ci++] = v[l2i++];
        }
    }
    while(l1i <= r1){
        c[ci++] = v[l1i++];
    }
    while(l2i <= r2){
        c[ci++] = v[l2i++];
    }
    l1i = l;
    for(ci = 0; ci <= rc; ci++){
        v[l1i++] = c[ci];
    }
    free(c);
}
