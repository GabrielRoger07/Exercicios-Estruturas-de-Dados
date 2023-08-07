#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)

int main(int argc, char const *argv[])
{
    int tam = 10, quant = 0;

    int *vetor = malloc(tam*sizeof(int));

    while(scanf(" %d", &vetor[quant])!=EOF){
        if(quant == tam-1){
            tam=tam*2;
            vetor = realloc(vetor, tam*sizeof(int));
        }
        quant++;
    }
    
    mergeSort(vetor, 0, quant-1);
    
    for(int i = 0; i < quant; i++){
        printf("%d ", vetor[i]);
    }
    free(vetor);
    return 0;
}

void mergeSort(int *v, int l, int r){
    if(l >= r) return;
    int meio = (r-l)/2 + l;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}   

void merge(int *v, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;
    int *aux = malloc((r-l+1)*sizeof(int));
    int ci = 0, lc = 0, rc = r-l;

    while(l1i <= r1 && l2i <= r2){
        if(less(v[l1i], v[l2i])){
            aux[ci++] = v[l1i++];
        }else{
            aux[ci++] = v[l2i++];
        }
    }

    while(l1i <= r1){
        aux[ci++] = v[l1i++];
    }
    while(l2i <= r2){
        aux[ci++] = v[l2i++];
    }
    l1i = l;
    for(ci = 0; ci <= rc; ci++){
        v[l1i++] = aux[ci];
    }
    free(aux);
}