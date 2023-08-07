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

void divide_lista(celula *l, celula *l1, celula *l2){
    printf("Você selecionou a opção 'divide lista!\n'");
}

void mescla_listas (celula *l1, celula *l2, celula *l3){
    //l1 = le 
    //l2 = l1
    //l3 = l2
    //Quando uma lista chegar no NULL, l3 recebe o resto da outra lista
    l1 = l1->prox;
    l2 = l2->prox;
    while(l1 != NULL && l2 != NULL){
        if(l1->dado < l2->dado){
            //Se entrou aqui, l1 tem que ir pra l3
            l3 -> prox = l1;
            //Avança o l1 
            l1 = l1->prox;
        }else{
            //Se entrou aqui, l2 tem que ir pra l3
            l3 -> prox = l2;
            //Avança o l2
            l2 = l2->prox;
        }
        //Avança o l3 para não inserir no início, e sim depois do numero que foi inserido no clk anterior
        l3 = l3->prox;
    }
    if(l1 != NULL){
        l3->prox = l1;
    }else{
        l3->prox = l2;
    }
}

int main(int argc, char const *argv[])
{
    celula *le, *l1, *l2;
    int x, y;
    le = malloc(sizeof(celula));
    le->prox = NULL;
    l1 = malloc(sizeof(celula));
    l1->prox = NULL;
    l2 = malloc(sizeof(celula));
    l2->prox = NULL;

    int op;
    printf("Escolha uma opcao:\n");
        printf("1 - Inserir no inicio de le\n");
        printf("2 - Inserir apos um numero\n");
        printf("3 - Inserir no inicio de l1\n");
        printf("4 - Remover elemento\n");
        printf("5 - Remover elementos repetidos\n");
        printf("6 - Imprimir a lista\n");
        printf("7 - Juncao\n");
        printf("8 - Divisao\n\n");
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
            printf("Voce selecionou a opcao 3\n");
            printf("Digite qual numero voce vai inserir no inicio:\n");
            scanf("%d", &x);
            insere_inicio(l1, x);
            imprime(l1);
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
        }else if(op == 6){
            printf("Voce selecionou a opcao 6\n");
            imprime(le);
            imprime(l1);
            imprime(l2);
            printf("\n\n");
        }else if(op == 7){
            printf("Voce selecionou a opcao 7\n");
            mescla_listas(le, l1, l2);
            printf("l1: ");
            imprime(le);
            printf("\n");
            printf("l2: ");
            imprime(l1);
            printf("\n");
            printf("l3: ");
            imprime(l2);
            printf("\n");
        }else if(op == 8){
            printf("Voce selecionou a opcao 8\n");
            divide_lista(le, l1, l2);
            imprime(le);
            printf("\n");
            printf("lPar: ");
            imprime(l2);
            printf("\n");
            printf("lImpar: ");
            imprime(l1);
            printf("\n");
        }else{
            printf("Voce nao escolheu nenhuma opcao\n");
        }
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir no inicio de le\n");
        printf("2 - Inserir apos um numero\n");
        printf("3 - Inserir no inicio de l1\n");
        printf("4 - Remover elemento\n");
        printf("5 - Remover elementos repetidos\n");
        printf("6 - Imprimir a lista\n");
        printf("7 - Juncao\n");
        printf("8 - Divisao\n\n");
        scanf("%d", &op);

    }while(op!=9);

    return 0;
}
