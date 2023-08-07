#include <stdio.h>

int main(int argc, char const *argv[])
{
    int iguais = 0;
    int numQuestoes;
    char gabarito[100];
    char prova[100];

    scanf("%d", &numQuestoes);
    scanf(" %s", &gabarito);
    scanf(" %s", &prova);
    for(int a = 0; a < numQuestoes ; a++ ){
        if(gabarito[a] == prova[a]){
            iguais++;
        }
    }
    printf("%d", iguais);
    return 0;
}
