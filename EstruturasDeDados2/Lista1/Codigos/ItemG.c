#include <stdio.h>

typedef struct pilha{
    char *dado;
    int N;
    int topo;
}pilha;

pilha *cria_pilha(){
    pilha *p = malloc(sizeof(pilha));
    p->N = 500;
    p -> dado = malloc((p->N)*sizeof(int));
    p -> topo = 0;
    return p;
}

int empilha(pilha *p, int x){
    if(p->topo == p->N){
        p->dado = realloc(p->dado, (2*p->N)*sizeof(pilha));
        if(p->dado == NULL){
            return 0;
        }else{
            p->N*=2;
        }
    }
    p->dado[p->topo] = x;
    p->topo++;
    return 1;
}

int desempilha(pilha *p, int *y){
    if(p->topo == 0){
        return 0;
    }else{
        p->topo--;
        *y = p->dado[p->topo];
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int numeros[30];
    int limiteSoma, soma = 0, i = -1, *y;
    pilha *p = cria_pilha();

    do{
        i++;
        scanf("%d", &numeros[i]);
    }while(numeros[i] != 0);

    scanf("%d", &limiteSoma);

    for(int j = 0; j < i; j++){
        if(soma + numeros[j] > limiteSoma){
            empilha(p, numeros[j]);
            soma = 0;
        }else{
            soma = soma + numeros[j];
        }
    }

    while(desempilha(p, &y) != 0){
        printf("%d\n", y);
    }

    return 0;
}
