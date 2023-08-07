#include <stdio.h>
#include <stdlib.h>

#define LESS(A, B) (A < B)
#define EXCH(A, B) {int aux = B; B = A; A = aux;}
#define CMPEXCH(A, B) {if(LESS(B, A))EXCH(A, B);}

int main(int argc, char const *argv[])
{
    int *v, i = 0, ret;
    v = malloc(1000*sizeof(int));

    while(scanf("%d", &v[i]) != EOF){
        i++;
    }
    selectionSort(v, 0, i-1);

    for(int j = 0 ; j < i ; j++){
        printf("%d ", v[j]);
    }
    free(v);
    return 0;
}

void selectionSort(int *v, int l, int r){
    for(int i = l; i < r; i++){
        int min = i;
        for(int j = i+1; j <=r; j++){
            if(LESS(v[j], v[min])){
                min = j;
            }
        }
        EXCH(v[min], v[i]);
    }
}
