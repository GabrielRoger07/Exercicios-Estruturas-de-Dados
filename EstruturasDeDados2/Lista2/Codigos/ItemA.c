#include <stdio.h>

//typedef struct x{
//    int chave;
//    char *data;
//}x
//typedef struct x Item;
//#define KEY(A) (A.chave)
//#define LESS(A, B) (KEY(A) < KEY(B))
//#define EXCH(A, B) {Item t = b, B = A, A = t;}
//#define CMPEXCH (A, B) {if(LESS(B, A))EXCH(A, B);}

#define LESS(A, B) (A < B)
#define EXCH(A, B) {int aux = B; B = A; A = aux;}
#define CMPEXCH(A, B) {if(LESS(B, A))EXCH(A, B);}

int main(int argc, char const *argv[])
{
    int *v, i = 0;
    v = malloc(1000*sizeof(int));

    while(scanf("%d", &v[i]) != EOF){
        i++;
    }

    bubbleSort(v, 0, i-1);

    for(int j = 0; j < i; j++){
        printf("%d ", v[j]);
    }
    return 0;
}

void bubbleSort(int *v, int l, int r){
    for(int i = l; i< r; i++){
        for(int j = l+1; j<=r; j++){
            CMPEXCH(v[j-1], v[j]);
        }
    }
}
