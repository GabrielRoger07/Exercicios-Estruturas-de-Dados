#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct fila{
    int *dados;
    int N, p, u, quantidade;
}fila;

fila *cria_fila(){
    fila *f = malloc(sizeof(fila));
    f->N =20000;
    f->dados = malloc(f->N*sizeof(int));
    f->p = f->u = 0;
    f->quantidade = 0;
    return f;
}

int fila_vazia(fila *f){
    if(f->quantidade == 0){
        return 1;
    }else{
        return 0;
    }
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

typedef struct node *link;
typedef struct vertice{
    int x, y;
}vertice;

vertice totalVertices[4000];
typedef struct node{
    int v;
    link next; 
}node;

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

graph *graphInit(int quant){
    int i;
    graph *g = malloc(sizeof(graph));
    g->V = quant;
    g->E = 0;
    g ->adj = malloc(quant*sizeof(link));
    for(i = 0; i < quant; i++){
        g->adj[i] = NULL; 
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
    link x = malloc(sizeof(link));
    G->adj[i] = new(j, G->adj[i]);
    G->adj[j] = new(i, G->adj[j]);
    G->E++;
}

int main(int argc, char const *argv[]){
    int i, j, dist[4000], pre[4000];
    int tamanhoPasso, numAlmofadas, valorX, valorY;
    scanf("%d", &tamanhoPasso);
    scanf("%d", &numAlmofadas);
    
    graph *grafo = graphInit(numAlmofadas);

    for(i = 0; i < numAlmofadas; i++){
        scanf("%d %d", &totalVertices[i].x, &totalVertices[i].y);
    }
    for(i = 0; i < numAlmofadas; i++){
        for(j = i+1; j < numAlmofadas; j++){
            verificaDistancia(grafo, i, j, tamanhoPasso);
        }
    }      

    receba(grafo, 0, dist, pre);
    /*for(int i = 0; i < numAlmofadas;i++){
        printf("posicao %d: ", i);
        for(link l = grafo->adj[i]; l != NULL; l = l->next){
            printf("%d-> ", l->v);
        }
        printf("NULL\n");
    }*/
    if(dist[1] == numAlmofadas){
        printf("-1\n");
    }else{
        printf("%d\n", dist[1]);
    }

    return 0;
}

void verificaDistancia(graph *g, int i, int j, int passo){
    float resultado = (float)sqrt(((totalVertices[i].x - totalVertices[j].x) * (totalVertices[i].x - totalVertices[j].x)) + ((totalVertices[i].y - totalVertices[j].y) * (totalVertices[i].y - totalVertices[j].y)));
    if(resultado <= passo){
        //printf("entrou\t");
        //printf("i e j: %d e %d\n", i, j);
        GraphInsert(g, i, j);
    }
}

void receba(graph *g, int s, int *dist, int *pre){
    int maximo = g->V;
    for(int i = 0; i < g->V; i++){
        dist[i] = g->V;
        pre[i] = -1;
    }
    dist[s] = 0;
    pre[s] = s;
    fila *f = cria_fila();
    enfileira(f, s);
    while(!fila_vazia(f)){
        //printf("chegou aqui\n");
        int e = desenfileira(f); 
        for(link l = g->adj[e]; l != NULL; l = l->next){
            int v = l->v;
            if(dist[v] == maximo){
                dist[v] = dist[e] + 1;
                pre[v] = e;
                enfileira(f, v);
            }
        }
    }
    free(f);
}