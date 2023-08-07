#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void imprime (celula *le){
    for(celula *p = le->prox; p != NULL; p = p->prox){
        printf("%d -> ", p->dado);
    }
    printf("NULL\n");
}

celula *busca(celula *le, int x){
    celula *p;
    for(p = le->prox; p != NULL && p->dado != x; p = p->prox){
    }
    return p;
}

void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le-> prox = novo;
}

void insere_antes(celula *le, int x, int y){
    celula *p;
    for(p = le; p ->prox != NULL && p->prox->dado != y; p = p->prox){

    }
    insere_inicio(p, x);
}

int main(int argc, char const *argv[])
{
    celula *le;
    int x, y;
    le = malloc(sizeof(celula));
    le->prox = NULL;
    int op;
    printf("Escolha uma opcao:\n");
    printf("1 - Inserir no inicio\n");
    printf("2 - Inserir apos um numero\n\n");
    scanf("%d", &op);

    do{
        if(op == 1){
            printf("Voce selecionou a opcao 1\n");
            printf("Digite qual numero voce vai inserir no inicio:\n");
            scanf("%d", &x);
            insere_inicio(le, x);
            imprime(le);
        }else if(op == 2){
            printf("Voce selecionou a opcao 2\n");
            printf("Digite qual numero voce vai inserir:\n");
            scanf("%d", &x);
            printf("Digite qual numero sera o posterior do que voce vai inserir:\n");
            scanf("%d", &y);
        
            insere_antes(le, x, y);
            imprime(le);
        }else{
            printf("Voce nao escolheu nenhuma opcao\n");
        }
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir apos um numero\n\n");
        scanf("%d", &op);
    }while(op!=7);

    //insere_inicio(&le,4);

    return 0;
}
