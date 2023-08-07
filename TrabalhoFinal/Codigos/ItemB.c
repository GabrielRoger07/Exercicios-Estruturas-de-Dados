#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct nome_valor{
    char nome[26];
    int valor;
}nome_valor;

typedef struct no{
    nome_valor a;
    struct no *prox; 
}no;

typedef struct lista{
    no *cabeca;
    int contador;
}lista;
typedef struct ht{
    int valor;
    lista *hashtable;
}ht;

void inicializaHash(ht *hash){
    hash->hashtable = malloc(1013*sizeof(lista));
    hash->valor = 0;
    for(int i = 0; i < 1013; i++){
        inicializaLista(&hash->hashtable[i]);
    }
}

void insereHash(ht *hash, nome_valor x){
    int v = hashU(x.nome);
    insereNaLista(&hash->hashtable[v], x);
    hash->valor++;
}

int buscaHash(ht *hash, char *nome){
    int v = hashU(nome);
    return buscaNaLista(&hash->hashtable[v], nome);
}

typedef struct fila{
    int *dados;
    int N, p, u, quantidade;
}fila;

fila *cria_fila(){
    fila *f = malloc(sizeof(fila));
    f->N = 1001;
    f->dados = malloc(f->N*sizeof(int));
    f->p = f->u = 0;
    f->quantidade = 0;
    return f;
}

int fila_vazia(fila *f){
    return (f->quantidade == 0);
}

int enfileira(fila *f, int x){
    if((f->u+1) % f->N == f->p){
        return 0;
    }
    f->dados[f->u] = x;
    f->u = (f->u+1) % f->N;
    f->quantidade++;
    return 1;
}

/*int desenfileira(fila *f, int *y){
    if(f->p == f->u){
        return 0;
    }
    *y = f->dados[f->p];
    f->p = (f->p+1) % f->N;
}*/

int desenfileira(fila *f){
    if(f->p == f->u){
        return 0;
    }
    int y = f->dados[f->p];
    f->p = (f->p+1) % f->N;
    f->quantidade--;
    return y;
}

int hashU(char *v){
    int h, a = 31415, b = 27183;
    for(h = 0; *v != '\0'; v++){
        a = (a*b) % (1013);
        h = (a*h + *v) % 1013;
    }
    return h;
}

typedef struct node *link;

typedef struct node{
    int v;
    link next; 
}node;

void inicializaLista(lista *listaEntrada){
    listaEntrada->cabeca = NULL;
    listaEntrada->contador = 0;
}

void insereNaLista(lista *listaEntrada, nome_valor x){
    no *l = malloc((sizeof(no)));
    l->a = x;
    l->prox = listaEntrada->cabeca;
    listaEntrada->cabeca = l;
    listaEntrada->contador++;
}

int buscaNaLista(lista *listaEntrada, char *nome){
    no *aux = listaEntrada->cabeca;
    while(aux != NULL){
        if(strcmp(aux->a.nome, nome) == 0){
            return aux->a.valor;
        }
        aux = aux->prox;
    }
    return 0;
}
typedef struct graph{
    int V, E;
    link *adj;
}graph;
typedef struct Edge{
    int v, w;
}Edge;

Edge EDGE(int v, int w){
    Edge ret;
    ret.v = v;
    ret.w = w;
}

ht hash;

graph *graphInit(int quant){
    int i, j;
    graph *g = malloc(sizeof(graph));
    g->V = quant;
    g->E = 0;
    g ->adj = malloc(quant*sizeof(link));
    inicializaHash(&hash);
    for(i = 0; i < quant; i++){
        g->adj[i] = NULL;
        //printf("nome: %s na posicao %d do vetor nomes\n", nomes[j].nome, j);
    }
    return g;
}

link new(int valor, link next){
    link x = malloc(sizeof(link));
    x ->v = valor;
    x->next = next;
    return x;
}

void GraphInsert(graph *G, int i, int j){
    G->adj[i] = new(j, G->adj[i]);
    G->adj[j] = new(i, G->adj[j]);
    G->E++;
}

int main(){
    int quantPessoas, quantApertos, i;
    char nome1[26], nome2[26], nome3[26], nome4[26], nome[26];
    int j, k, l, m;
    scanf(" %s %s", nome1, nome2);
    scanf(" %d %d", &quantPessoas, &quantApertos);
    int *pre = malloc(sizeof(int)*quantPessoas);
    int *dist = malloc(sizeof(int)*quantPessoas);
    graph *grafinho = graphInit(quantPessoas);
    for(int i = 0; i < quantPessoas; i++){
        scanf(" %s", nome);
        nome_valor x;
        x.valor = i;
        strcpy(x.nome, nome);
        insereHash(&hash, x);
    }
    for(int i = 0; i < quantApertos; i++){
        scanf(" %s %s", nome3, nome4);
        int valor1 = buscaHash(&hash, nome3);
        int valor2 = buscaHash(&hash, nome4);
        GraphInsert(grafinho, valor1, valor2);
    }
    receba(grafinho, buscaHash(&hash, nome1), dist, pre);
    if(dist[buscaHash(&hash, nome2)] == quantPessoas){
        printf("-1");
    }else{
        printf("%d\n", dist[buscaHash(&hash, nome2)]);
    }
      
    return 0;
}

void receba(graph *g, int s, int *dist, int *pre){
    //memset(dist, g->V, (g->V)*sizeof(int));
    //memset(pre, -1, sizeof(int)*(g->V));
    for(int i = 0; i < g->V; i++){
        dist[i] = g->V;
        //pre[i] = -1;
    }
    
    dist[s] = 0;
    //pre[s] = s;
    fila *f = cria_fila();
    enfileira(f, s);
    while(!fila_vazia(f)){
        //printf("entrou no while\n");
        int e = desenfileira(f); 
        //printf("valor de e: %d\n", e);
        for(link l = g->adj[e]; l != NULL; l = l->next){
            int v = l->v;
            if(dist[v] == g->V){
                //printf("entrou aqui\n");
                dist[v] = dist[e] + 1;
                //pre[v] = e;
                enfileira(f, v);
            }
        }
    }
    free(f);
}