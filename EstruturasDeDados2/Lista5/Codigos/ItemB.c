#include <stdio.h>
#include <stdlib.h>

#define key(A) (A.contador)
#define less(A, B) (key(A) == key(B) ? A.caracter < B.caracter : key(A) < key(B))

typedef struct cont_st{
    char caracter;
    int contador;
}cont_st;

struct cont_st TH[128];

int main(int argc, char const *argv[]){
    char c;
    
    while(scanf("%c", &c) != EOF){
        frequencia_string(c);
    }

    return 0;
}

void inicializa_TH(){
    memset(TH, 0, 128*sizeof(cont_st));
}

void frequencia_string(char c){
    int i = 0;
    char b;

    inicializa_TH();
    TH[c].caracter = c;
    TH[c].contador++;

    while(scanf("%c", &b) == 1 && b != '\n'){
        TH[b].caracter = b;
        TH[b].contador++;
    }
    mergeSort(TH, 0, 127);
    while(TH[i].contador == 0) i++;
    while(i < 128){
        printf("%hd %d\n", TH[i].caracter, TH[i].contador);
        i++;
    }
    printf("\n");
}

void mergeSort(cont_st *v, int l, int r){
    if(l >= r) return;
    int meio = (r-l)/2 + l;
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
    while(l1i<=r1){
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




