#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)

int main(int argc, char const *argv[])
{
    int quantProibidos, verificaNum;

    scanf("%d", &quantProibidos);
    int *vetor = malloc(quantProibidos*sizeof(int));
    for(int i = 0; i < quantProibidos; i++){
        scanf("%d", &vetor[i]);
    }
    mergeSort(vetor, 0, quantProibidos-1);

    while(scanf("%d", &verificaNum) != EOF){
        buscaBinaria(vetor, verificaNum, quantProibidos);
    }
    free(vetor);

    return 0;
}

void mergeSort(int *v, int l, int r){
    if(l >= r) return;
    int meio = (r - l)/2 + l;
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

void buscaBinaria(int *v, int num, int tamanho){
    int e, d, meio;
    e = -1;
    d = tamanho;
    while(e != (d-1)){
        meio = (e+d)/2;
        if(num <= v[meio]){
            d = meio;
            if(num == v[meio]){
                e = d-1;
            }
        }else{
            e = meio;
        }
    }
    if(v[d] == num){
        printf("sim\n");
    }else{
        printf("nao\n");
    }
}
