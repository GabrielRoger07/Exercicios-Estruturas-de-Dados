#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) {semente aux = B; B = A; A = aux;}
#define lessQualidade(A, B) (A.qualidade == B.qualidade ? A.codigo < B.codigo : A.qualidade < B.qualidade)
#define lessCodigo(A, B) (A.codigo == B.codigo ? A.qualidade < B.qualidade : A.codigo < B.codigo)
#define cmpexchQualidade(A, B) {if(lessQualidade(B, A)) exch(A ,B);}

#define cmpexchCodigo(A, B) {if (lessCodigo(B, A)) exch(A, B);}

typedef struct semente{
    int codigo;
    int qualidade;
}semente;

semente sementes[10000001];

int main(void){
    int n, i = 0;
    scanf("%d", &n);
    while(scanf("%d %d", &sementes[i].codigo, &sementes[i].qualidade) != EOF){
        i++;
    }

    quickselect(sementes, 0, i-1, n-1); 
    quicksortInsertion(sementes, 0, n-1); 

    for(int j = 0; j < n; j++){
        printf("%d %d\n", sementes[j].codigo, sementes[j].qualidade);
    }
    return 0;
}

int separa(semente *v, int l, int r){ 
    semente aux = v[r];
    int j = l;
    
    for (int k = l; k < r; k++){
        if (lessQualidade(v[k], aux)){
            exch(v[k], v[j]);
            j++;
        }
    } 
    exch(v[j], v[r]);
    return j;
}

void quicksortMD3(semente *v, int l, int r){
    if (l>=r) return;
    exch(v[(l + r) / 2], v[r - 1]);
    cmpexchCodigo(v[l], v[r - 1]);
    cmpexchCodigo(v[l], v[r]);
    cmpexchCodigo(v[r - 1], v[r]);

    int j = separa(v, l, r);
    quicksortMD3(v, l, j - 1);
    quicksortMD3(v, j + 1, r);
}

void insertionSort(semente *v, int l, int r){
    for (int i = l + 1, j; i <= r; i++){
        semente aux = v[i];
        int j = i;
        while(j > 0 && lessCodigo(aux, v[j - 1])){
            v[j] = v[j - 1];
            j--;
        }   
        v[j] = aux;
    }
}

void quicksortInsertion(semente *v, int l, int r){
    quicksortMD3(v, l, r);
    insertionSort(v, l, r);
}

void quickselect(semente *v, int l, int r, int p){

    cmpexchQualidade(v[(l + r) / 2], v[r]);
    cmpexchQualidade(v[l], v[(l + r) / 2]);
    cmpexchQualidade(v[r], v[(l + r) / 2]);
    int j = separa(v, l, r);
    if (j > p){
        quickselect(v, l, j - 1, p);
    } else if (j < p){
        quickselect(v, j + 1, r, p);
    }
}
