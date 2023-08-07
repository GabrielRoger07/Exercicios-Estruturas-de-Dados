#include <stdio.h>
#include <stdlib.h>

#define key(A) (A.quantidade)
#define less(A, B) (key(A) == key(B) ? A.nota < B.nota : key(A) < key(B))

typedef struct cont_st{
    int nota;
    int quantidade;
}cont_st;

cont_st TH[101];

int main(int argc, char const *argv[])
{
    int quantAlunos, cod;
    inicializa_vetor();
    scanf("%d", &quantAlunos);
    for(int i = 0; i < quantAlunos; i++){
        scanf("%d", &cod); 
        TH[cod].nota = cod;
        TH[cod].quantidade++;
    }
    mergeSort(TH, 0, 100);
    printf("%d\n", TH[100].nota);
    return 0;
}

void inicializa_vetor(){
    memset(TH, 0, 101*sizeof(cont_st));
}

void mergeSort(cont_st *v, int l, int r){
    if(l >= r) return;
    int meio = (r-l)/2 +l;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

void merge(cont_st *v, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;
    cont_st *c = malloc((r-l+1)*sizeof(cont_st));
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