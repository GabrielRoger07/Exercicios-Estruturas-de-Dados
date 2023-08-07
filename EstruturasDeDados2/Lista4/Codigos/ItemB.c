#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {int aux = B; B = A; A = aux;}
#define cmpexch(A, B) {if(less(B, A))exch(A, B);}

int main(int argc, char const *argv[])
{
    int quant;
    scanf("%d", &quant);
    int *vetor = malloc(quant*sizeof(int));

    for(int i=0; i<quant; i++){
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, quant-1);
    
    for(int i = 0; i<quant; i++){
        printf("%d ", vetor[i]);
    }
    
    free(vetor);    
    return 0;
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

int separa(int *v, int l, int r) {
    int i = l-1, j = r, c = v[r];
    for(;;){
        while(less(v[++i], c));
        while(less(c, v[--j])) 
            if(j==l) break;
        if(i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}
