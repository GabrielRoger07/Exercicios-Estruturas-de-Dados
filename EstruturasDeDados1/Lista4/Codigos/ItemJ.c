#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    char *dado;
    int N;
    int topo;
}pilha;

pilha *cria_pilha(){
    pilha *p = malloc(sizeof(pilha));
    p->N = 500;
    p ->dado = malloc((p->N)*sizeof(int));
    p->topo = 0;
    return p; 
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

void bem_formada(char *expressao){
    int i = 0;
    int deuRuim = 0;
    int *y;
    pilha *p = cria_pilha();
    while(expressao[i] != '\0'){
        if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
            empilha(p,expressao[i]);
        }else if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}'){
            if(p->dado[(p->topo)-1] == '(' && expressao[i] == ')'){
                desempilha(p, &y);
            }else if(p->dado[(p->topo)-1] == '[' && expressao[i] == ']'){
                desempilha(p, &y);
            }else if(p->dado[(p->topo)-1] == '{' && expressao[i] == '}'){
                desempilha(p, &y);
            }else{
                deuRuim++;
            }
        }
        i++;
    }
    if(p->topo == 0 && deuRuim == 0){
        printf("sim");
    }else{
        printf("nao");
    }
    
}

int main(int argc, char const *argv[])
{
    char expressao[600];
    //printf("Digite a expressão matematica a seguir: ");
    scanf("%s", expressao);
    bem_formada(expressao);
    return 0;
}
