#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)

int main(int argc, char const *argv[])
{
    int quantidadePatos, *codigos;
    scanf("%d", &quantidadePatos);
    while(quantidadePatos != 0){
        codigos = malloc(quantidadePatos * sizeof(int));
        for(int i = 0; i < quantidadePatos; i++){
            scanf("%d", &codigos[i]);
        }
        mergeSort(codigos, 0, quantidadePatos-1);
        majoritaria(codigos, quantidadePatos);
        free(codigos);
        scanf("%d", &quantidadePatos);
    }
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

void majoritaria(int *v, int quant){
    int majorit = 0, aux = 0;
    for(int i = 0; i < quant; i++){
        if(aux == 0){
            majorit = v[i];
            aux++;
        }else if(majorit == v[i]){
            aux++;
        }else{
            aux--;
        }
    }
    printf("%d\n", majorit);
}



