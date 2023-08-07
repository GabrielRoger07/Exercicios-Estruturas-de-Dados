#include <stdio.h>
#include <stdlib.h>

#define key(A)(A.key)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) {Instrucao t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

typedef struct Instrucao{
    int key;
    char str[16];
} Instrucao;

void insertionSort(Instrucao *instrucao, int l, int r){
    for(int i = r; i > l; i--){
        if(less(instrucao[i], instrucao[i-1])){
            exch(instrucao[i], instrucao[i-1])
        }
    }
    for(int i = l+1; i <= r; i++){

        int j = i - 1;
        Instrucao tmp = instrucao[j + 1]; 

        while(less(tmp, instrucao[j])){
            instrucao[j + 1] = instrucao[j];
            j--;
        }
        instrucao[j + 1] = tmp;
    }
}

void BuscaBinaria(Instrucao *vetor, int l, int r, int numero){
    while (l <= r)
    {
        int meio = (l + r) / 2;

        if (vetor[meio].key == numero){
            printf("%s\n", vetor[meio].str);
            return;
        }   

        if (vetor[meio].key > numero){
            r = meio - 1;
        }else{
            l = meio + 1;
        }
    }

    printf("undefined\n"); 
    return;
}

int main(int argc, char const *argv[]){
    int quant, numero,i;

    scanf(" %d", &quant);

    Instrucao *instrucao = malloc(quant*sizeof(Instrucao));

    for ( i = 0; i < quant; i++){
        scanf(" %d %s", &instrucao[i].key, &instrucao[i].str);
    }
    
    insertionSort(instrucao, 0, quant-1);

    while(scanf(" %d", &numero) != EOF){
        BuscaBinaria(instrucao, 0, quant-1, numero);
    }

    free(instrucao);

    return 0;
}

