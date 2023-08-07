#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)

int main(int argc, char const *argv[])
{
    int tamanhoVetor, quantBusca;
    scanf("%d", &tamanhoVetor);
    scanf("%d", &quantBusca);
    int *vetor = malloc(tamanhoVetor*sizeof(int));
    int *numerosBuscados = malloc(quantBusca*sizeof(int));
    int *vetorAux = malloc(tamanhoVetor*sizeof(int));

    for(int i = 0; i < tamanhoVetor; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < quantBusca; i++){
        scanf("%d", &numerosBuscados[i]);
    }
    for(int i = 0; i < tamanhoVetor; i++){
        vetorAux[i] = vetor[i];
    }
    mergeSort(vetor, 0, tamanhoVetor-1);
    buscaBinaria(vetor, numerosBuscados, tamanhoVetor, quantBusca, vetorAux);
    free(vetor);
    free(numerosBuscados);

    return 0;
}

void mergeSort(int *v, int l, int r){
    if(l>=r)return;
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
    while(l1i<=r1){
        aux[ci++] = v[l1i++];
    }
    while(l2i <= r2){
        aux[ci++] =v[l2i++]; 
    }
    l1i = l;
    for(ci = 0; ci <= rc; ci++){
        v[l1i++] = aux[ci];
    }
    free(aux);
}

void buscaBinaria(int *v, int *busca, int tam, int quant, int *vetorAux){
    int e, d, meio, j;
    for(int i = 0; i < quant; i++){
        e = -1;
        d = tam;
        while(e != d-1){
            meio = (e+d)/2;  
            if(busca[i] <= v[meio]){
                d = meio;
            }else{
                e = meio;
            }         
        }
        if(busca[i] == v[d]){
            for(j = 0; j < tam; j++){
                if(v[d] == vetorAux[j]){
                    printf("%d\n", j);
                    break;
                }
            }
        }else{
            printf("-1\n");
        }
    }
}
