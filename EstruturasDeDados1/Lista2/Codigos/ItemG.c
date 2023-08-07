#include <stdio.h>

long int move(long int *v,long int i, long int elem){
    if(i<0 || v[i] <= elem){
        return i;
    }
    v[i+1] = v[i];
    move(v, i-1, elem);
}

void ordena(long int *v,long int n){
    if(n <= 1){
        return;
    }
    ordena(v, n-1);
    long int elem = v[n-1];
    long int i = move(v, n-2, elem);
    v[i+1] = elem;
}

void buscaBinaria(long int n,long int m,long int N[],long int M[],long int posicao[]){
    long int meio;
    long int e;
    long int d;
    for(int i = 0; i <m; i++){
            e = -1;
            d = n;
        while(e != (d-1)){
            meio = (e+d)/2;
            if(M[i] > N[meio]){
                e = meio;
            }else{
                d = meio;
            }
        }
        posicao[i] = d;
    }
}

int main(int argc, char const *argv[])
{
    long int numerosN[100000];
    long int numerosM[100000];
    long int posicao[100000];
    long int n,m;

    //printf("Digite a quantidade N: ");
    scanf("%ld", &n);
    //printf("Digite a quantidade M: ");
    scanf("%ld", &m);
    //printf("%d", m);
    //printf("Digite os numeros que serao armazenados em numerosN[]:\n");
    for(int i = 0; i < n; i++){
        scanf("%ld", &numerosN[i]);
    }
    //printf("Digite os numeros que serao armazenados em numerosM[]:\n");
    for(int j = 0; j < m; j++){
        scanf("%ld", &numerosM[j]);
    }
    ordena(numerosN, n);
    //for(int i = 0; i < n; i++){
    //    printf("%d ", numerosN[i]);
    //}
    //printf("%d\n", numerosM[0]);
    buscaBinaria(n, m, numerosN, numerosM, posicao);
    for(int j = 0; j < m; j++){
        printf("%ld\n", posicao[j]);
    }
    //printf("\n");
    return 0;
}