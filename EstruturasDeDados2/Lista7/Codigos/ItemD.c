#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V;
    int E;
    int **adj;
}Graph;

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

int pre[5001], ht[5001];
char criaturas[5001][32];

int **MATRIXinit(int V, int x){
    int **matrix = malloc(V*sizeof(int*));
    for(int i = 0; i < V; i++)
        matrix[i] = malloc(V*sizeof(int));

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            matrix[i][j] = x;
    
    }
    return matrix;
}

Graph *GraphInit(int V){
    Graph *G = malloc(sizeof(Graph));
    G->V = V;
    G->E = 0;
    G->adj = MATRIXinit(V, 0);
    return G;
}

void GraphInsertE(Graph *G, Edge e){
    int v = e.v, w = e.w;
    if(G->adj[v][w] == 0)
        G->E++;

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

int main(){
    solve();

    return 0;
}

void solve(){
    int c, r;
    scanf("%d %d", &c, &r);
    if (c == 0 && r == 0){
        return;
    }

    for(int i = 0; i < c; i++){
        pre[i] = -1;
    }

    for(int i = 0; i < c; i++){
        ht[i] = 0;
    }

    for (int i = 0; i < c; i++){
        scanf(" %s", criaturas[i]);
    }
        
    Graph *G = GraphInit(c);

    for (int i = 0; i < r; i++){
        char criatura1[32], criatura2[32];
        scanf(" %s %s", criatura1, criatura2);
        
        int ai = -1, bi = -1, j = 0;

        while(j < c && (ai == -1 || bi == -1)){
            if (ai == -1 && strcmp(criaturas[j], criatura1) == 0){
                ai = j;
            } else if (bi == -1 && strcmp(criaturas[j], criatura2) == 0){
                bi = j;
            }

            j++;
        }

        Edge E = EDGE(bi, ai);
        GraphInsertE(G, E);
    }

    for (int i = 0; i < c; i++){
        dfsR(G, i);
    }
        
    for (int i = 0; i < G->V; i++)
        free(G->adj[i]);
    free(G->adj);

    int ans = 0;
    for (int i = 0; i < c; i++){
        if (++ht[pre[i]] > ans){
            ans = ht[pre[i]];
        }
    }    

    printf("%d\n", ans);

    solve();
}

void dfsR(Graph *G, int x){
    if (pre[x] < 0)
        pre[x] = x;
    for (unsigned i = 0; i < G->V; i++)
        if (G->adj[x][i] != 0 && pre[i] < 0){
            int mn = ((int)i < pre[x] ? (int)i : pre[x]);
            pre[x] = mn;
            pre[i] = mn;
            dfsR(G, i);
        }
}