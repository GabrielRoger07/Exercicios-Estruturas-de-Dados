#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
int j = 0;

int main(int argc, char const *argv[])
{
    int quantInserida, k = 0;
    scanf("%d", &quantInserida);
    int *vetor1 = malloc(quantInserida*sizeof(int));
    int *vetor2 = malloc(quantInserida*sizeof(int));
    for(int i = 0; i < quantInserida; i++){
        scanf("%d", &vetor1[i]);
    }
    mergeSort(vetor1, 0, quantInserida-1);

    for(int i = 0; i < quantInserida-1; i++){
        if(vetor1[i] != vetor1[i+1]){
            vetor2[j] = vetor1[i];
            j++;
        }
    }
    if(vetor1[quantInserida-1] != vetor2[j-1]){
        vetor2[j] = vetor1[quantInserida-1];
        j++;
    }
    if(j%2 != 0){
        vetor2[j] = 1000000000;
        j++;
    }
    int *vetorSoma = malloc((j/2)*sizeof(int));
    for(int i = 0; i < j; i = i+2){
        vetorSoma[k] = vetor2[i] + vetor2[i+1]; 
        k++;
    }

    for(int i = 0; i < k; i++){
        buscaBinaria(vetor2, vetorSoma[i], quantInserida);
    }

    mergeSort(vetor2, 0, j-2);
    k = 0;
    while(k < j){
        printf("%d\n", vetor2[k]);
        k = k + 4;
    }

    printf("Elementos: %d\n", j);

    free(vetor1);
    free(vetor2);
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
    while(e != d-1){
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
    if(v[d] != num){
        v[j] = num;
        j++;
    }
}