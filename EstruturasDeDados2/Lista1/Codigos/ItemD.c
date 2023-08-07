#include <stdio.h>

int main(int argc, char const *argv[])
{
    int contResposta = 0, contSim = 0, triagem = 0;
    char *str;
    str = malloc(4);

    while(scanf(" %s", str) != EOF){
        contResposta++;
        if(str[0] == 's'){
            contSim++;
        }
        if(contResposta == 10){
            if(contSim >= 2){
                triagem++;
            }
            contResposta = 0;
            contSim = 0;
        }
    }

    printf("%d\n", triagem);

    return 0;
}
