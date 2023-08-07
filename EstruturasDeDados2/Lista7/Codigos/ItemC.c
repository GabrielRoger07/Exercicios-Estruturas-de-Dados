#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V;
    int E;
    int **adj;
}Graph;

typedef struct componente{
    int inicial;
    int tamanho;
}componente;

typedef struct Edge{
    int v;
    int w;
}Edge;

Edge EDGE(int v, int w){
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

int pre[5001], ht[5001], tamanho = 0, maior = 0;

int **MATRIXinit(int V, int init){
    int **matrix = malloc(V*sizeof(int*));
    for(int i = 0; i < V; i++)
        matrix[i] = malloc(V*sizeof(int));

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            matrix[i][j] = init;
    }
    return matrix;
}

Graph *GraphInit(int v){
    Graph *G = malloc(sizeof(Graph));
    G->V = v;
    G->E = 0;
    G->adj = MATRIXinit(v, 0);
    return G;
}

void graphInsertE(Graph *G, Edge e){
    int v = e.v, w = e.w;
    if(G->adj[v][w] == 0)
        G->E++;

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

int main(int argc, char const *argv[]) {

    int quantCidades, cidadeJoao, estradaV, estradaW, quantConexa;
    scanf("%d %d", &quantCidades, &cidadeJoao);
    componente *atual = malloc(quantCidades * sizeof(componente));
    Graph *grafo = GraphInit(quantCidades);

    memset(pre, 0, sizeof(int)*5001);
    memset(ht, 0, sizeof(int)*5001);

    while(scanf("%d %d", &estradaV, &estradaW) != EOF) {
        Edge aresta = EDGE(estradaV, estradaW);
        graphInsertE(grafo, aresta);
    }
  
    quantConexa = compConexos(grafo, atual);
    caminho(atual, cidadeJoao, quantConexa);
  
    return 0;
}

void dfsR(Graph *G, int v, int w, int x){
    pre[w] = 1;
    ht[w] = x;
    for(v = 0; v < G->V; v++){
        if(pre[v] == 0 && G->adj[w][v]){
            tamanho++; 
            dfsR(G, w, v, x);
        }
    }
}

int compConexos(Graph *G, componente *atual){
    int x = 0;
    for(int i = 0; i < G->V; i++){
        if(pre[i] == 0){
            atual[x].inicial = i;
            tamanho = 1;
            dfsR(G, i, i, x);
            if(tamanho > maior)
                maior = tamanho;

            atual[x].tamanho = tamanho;
            x++;
        }
    }
    return x;
}

void caminho(componente *atual, int x, int quant) {
    if(atual[ht[x]].tamanho == maior){
        if(maior != 1){
            printf("Bora pra estrada\n"); 
        } else{
            printf("Fique em casa\n"); 
        } 
    } else {
        for(int i = 0; i < quant; i ++) {
            if(atual[i].tamanho == maior) {
                printf("Vamos para %d\n", atual[i].inicial);
                return;
            }
        }
    }
}