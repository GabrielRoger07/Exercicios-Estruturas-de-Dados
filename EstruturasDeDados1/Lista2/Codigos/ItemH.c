#include <stdio.h>
#include <math.h>

long int pontuacao = 0;

void verificaPosicao(long int quantCirc, long int i, long int circulos[], double distancia[]){
    long int meio;
    long int e;
    long int d;

            e = -1;
            d = quantCirc;
        while(e != (d-1)){
            meio = (e+d)/2;
            if(distancia[i] > circulos[meio]){
                e = meio;
            }else{
                d = meio;
            }
        }
        pontuacao = pontuacao + (quantCirc-d);
    
}

void calculaDistancia(long int quantidadeDeTiros,long int tirosX[],long int tirosY[], double distancia[]){
    long int xQuadrado, yQuadrado, soma;
    long int i;
    
    for(i = 0; i < quantidadeDeTiros; i++){
        xQuadrado = tirosX[i] * tirosX[i];
        yQuadrado = tirosY[i] * tirosY[i];
        soma = xQuadrado + yQuadrado;
        distancia[i] = sqrt(soma);
    }
}

int main(int argc, char const *argv[])
{
    long int quantCirculos, quantTiros, circulos[100001], tirosx[100001], tirosy[100001];
    double distancia[100001];

    scanf("%ld", &quantCirculos);
    scanf("%ld", &quantTiros);

    for(long int i = 0; i < quantCirculos; i++){
        scanf("%ld", &circulos[i]);
    }
    for(long int j = 0; j < quantTiros; j++){
        scanf("%ld", &tirosx[j]);
        scanf("%ld", &tirosy[j]);
    }

    calculaDistancia(quantTiros, tirosx, tirosy, distancia);
    for(long int w = 0; w < quantTiros; w++){
        verificaPosicao(quantCirculos, w, circulos, distancia);
    }
    printf("%ld\n", pontuacao);
    
    return 0;
}
