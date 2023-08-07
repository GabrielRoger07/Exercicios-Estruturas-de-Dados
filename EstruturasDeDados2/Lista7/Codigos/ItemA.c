#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

    int numLocaisBairro, numLocaisEsteve, numLocaisEstara, indice, indiceVizinho, indiceEsteve;
    scanf("%d %d %d", &numLocaisBairro, &numLocaisEsteve, &numLocaisEstara);
    int matAdj[numLocaisBairro][numLocaisBairro];

    memset(matAdj, 0, numLocaisBairro * numLocaisBairro * sizeof(int));
    for(int i = 0; i < numLocaisBairro; i++) {
        scanf("%d", &indice);
        for(int j = 0; j < indice; j ++) {
            scanf(" %d", &indiceVizinho);
            matAdj[i][indiceVizinho] = 1;
        }
    }

    for(int i = 0; i < numLocaisEsteve; i ++) {
        scanf(" %d", &indiceEsteve);
        matAdj[indiceEsteve][indiceEsteve] = -1;
        for(int j = 0; j < numLocaisBairro; j++) {
            if(matAdj[indiceEsteve][j] == 1) 
                matAdj[j][j] = -1;
        }
    }

    for(int i = 0; i < numLocaisEstara; i ++) {
        scanf("%d", &indiceEsteve);
        if(matAdj[indiceEsteve][indiceEsteve] == -1) {
            printf("Eu vou estar la\n");
        }
        else{
            printf("Nao vou estar la\n");
        }
    }

    return 0;
}
