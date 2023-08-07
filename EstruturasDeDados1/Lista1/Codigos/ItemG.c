#include <stdio.h>

int main(int argc, char const *argv[])
{
    int quantidade, soma = 0, totalMaior = 0;
    float media;
    int numsInseridos[10000];

    scanf("%d", &quantidade);

    if(quantidade >= 10 && quantidade <= 10000){
        for(int a = 0; a < quantidade; a++){
            scanf("%d", &numsInseridos[a]);
            soma = soma + numsInseridos[a];
        }

        media = soma / quantidade;

        for(int b = 0; b < quantidade; b++){
            if(numsInseridos[b]>media){
                printf("%d ", numsInseridos[b]);
                totalMaior++;
            }
        }
        if(totalMaior==0){
            printf("0");
        }
    }else{

    }
    return 0;
}
