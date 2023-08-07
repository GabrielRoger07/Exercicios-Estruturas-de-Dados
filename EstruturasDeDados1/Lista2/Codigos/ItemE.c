#include <stdio.h>

void move(int v[], int n){

}

void ordena(int v[], int n){
    int i, j, elem;
    for(i = 0; i<n; i++){
        elem = v[i];
        for(j = i-1; j>=0 && v[j]>elem;j--){
            v[j+1] = v[j];
        }
        v[j+1] = elem;
    }
}


int main(int argc, char const *argv[])
{
    int numero[1000];
    int i = 0;

    for(i = 0; i < 5; i++){
        scanf("%d", &numero[i]);
    }

    ordena(numero, i);
    for(int j = 0; j < i; j++){
        printf("%d ", numero[j]);
    }

    return 0;
}
