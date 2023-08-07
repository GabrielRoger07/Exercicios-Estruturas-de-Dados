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

int remove_depois (celula *p){
    celula *lixo = p->prox;
    if(lixo!=NULL){
        int y = lixo->dado;
        p->prox = lixo->prox;
        free(lixo);
        return y;
    }
    //return 0;
}

void remove_elemento (celula *le, int x){
    celula *p, *p2;
    for(p = le; p ->prox != NULL && p->prox->dado != x; p = p->prox){

    }
    remove_depois(p);
}

void remove_todos_elementos (celula *le, int x){
    celula *p, *p2;
    do{
        for(p = le; p ->prox != NULL && p->prox->dado != x; p = p->prox){

        }
        p2 = p->prox;
        remove_depois(p);
    }while(p2 != NULL);
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
        printf("2 - Inserir antes de um numero\n");
        printf("3 - Remover pelo ponteiro\n");
        printf("4 - Remover elemento\n");
        printf("5 - Remover elementos repetidos\n\n");
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
        }else if(op == 3){
            
        }else if(op == 4){
            printf("Voce selecionou a opcao 4\n");
            printf("Digite qual numero voce vai remover:\n");
            scanf("%d", &x);
            remove_elemento(le, x);
            imprime(le);
        }else if(op == 5){
            printf("Voce selecionou a opcao 5\n");
            printf("Digite qual numero voce vai remover:\n");
            scanf("%d", &x);
            remove_todos_elementos(le, x);
            imprime(le);
        }else{
            printf("Voce nao escolheu nenhuma opcao\n");
        }
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir antes de um numero\n");
        printf("3 - Remover pelo ponteiro\n");
        printf("4 - Remover elemento\n");
        printf("5 - Remover elementos repetidos\n\n");
        scanf("%d", &op);
    }while(op!=7);

    //insere_inicio(&le,4);

    return 0;
}