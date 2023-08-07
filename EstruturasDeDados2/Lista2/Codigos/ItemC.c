#include <stdio.h>
#include <stdlib.h>

#define LESS(A, B) (A < B)
#define EXCH(A, B) {int t = B; B = A; A = t;}
#define CMPEXCH(A, B) {if(LESS(B, A))EXCH(A, B);}

int main(int argc, char const *argv[])
{
    int *v, i = 0;
    v = malloc(1000 * sizeof(int));

    while(scanf("%d", &v[i]) != EOF){
        i++;
    }

    insertionSort(v, 0, i-1);

    for(int j = 0; j < i; j++){
        printf("%d ", v[j]);
    }
    free(v);

    return 0;
}

void insertionSort(int *v, int l, int r){
    for(int i = l + 1; i <= r; i++){
        for(int j = i; j>l; j--){
            CMPEXCH(v[j-1], v[j]);
        }
    }
}
