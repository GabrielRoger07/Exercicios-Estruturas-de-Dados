#include <stdio.h>
#include <stdlib.h>

#define LESS(A, B) (A < B)
#define EXCH(A, B) {int aux = B; B = A; A = aux;}
#define CMPEXCH(A, B) {if(LESS(B, A))EXCH(A, B);}

int main(int argc, char const *argv[])
{
    int *v, i = 0, quant = 100;
    v = malloc(quant*sizeof(int));

    while(scanf("%d", &v[i]) != EOF){
        if(i + 1 == quant){
            quant*=2;
            v = realloc(v, quant*sizeof(int));
        }
        i++;
    }
    insertionSort(v, 0, i-1);

    for(int j = 0 ; j < i ; j++){
        printf("%d ", v[j]);
    }
    free(v);
    return 0;
}

void insertionSort(int *v, int l, int r){
    for(int i = r; i >l; i--){
        CMPEXCH(v[i-1], v[i]);
    }
    for(int i = l+1; i <= r; i++){
        int aux = v[i];
        int j = i-1;
        while(LESS(aux, v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}