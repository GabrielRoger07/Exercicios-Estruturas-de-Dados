#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(A) (A.quantidade)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {sequencia aux = B; B = A; A = aux;}

typedef struct sequencia{
    char letra;
    int posicaoInicio;
    int quantidade;
}sequencia;

int main(int argc, char const *argv[])
{
    char str[100000];
    sequencia sequencia[100000];
    scanf(" %[^\n]", str);
    int tam = strlen(str), quant = 1;

    sequencia[0].letra = str[0];
    sequencia[0].posicaoInicio = 0;

    for(int i = 1; i < tam; i++){
        if(str[i] != str[i-1]){
            sequencia[quant].letra = str[i];
            sequencia[quant].posicaoInicio = i;
            quant++;
        }else{
            sequencia[quant-1].quantidade++;
        }
    }
    mergeSort(sequencia, 0, quant-1);

    //for(int i = quant-1; i >= 0; i--){
    //    printf("letra %c comeca na posicao %d e tem tamanho %d\n", sequencia[i].letra, sequencia[i].posicaoInicio,sequencia[i].quantidade);
    //}

    for(int i = quant-1; i >=0; i--){
        printf("%d %c %d\n", (sequencia[i].quantidade)+1, sequencia[i].letra, sequencia[i].posicaoInicio);
    }
    return 0;
}

void quickSort(sequencia *v, int l, int r){
    if(l>=r) return;
    int j = separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

int separa(sequencia *v, int l, int r){
    int i = l-1, j = r;
    sequencia c = v[r];
    for(;;){
        while(less(v[++i], c));
        while(less(c, v[--j])) 
            if(j == l) break;
        if(i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void mergeSort(sequencia *v, int l, int r){
    if(l>=r) return;
    int meio = (r-l)/2 +l;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

void merge(sequencia *v, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;
    sequencia *c = malloc((r-l+1)*sizeof(sequencia));
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


