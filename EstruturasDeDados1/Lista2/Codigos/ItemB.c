#include <stdio.h>

void movex(char *vetor, int i){
    if(vetor[i] != '\0'){
        if(vetor[i] != 'x'){
            printf("%c", vetor[i]);
            movex(vetor, (i+1));
        }else{
            movex(vetor, (i+1));
            printf("x");
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    char entrada[100];
    scanf("%s", entrada);
    movex(entrada, 0);
    return 0;
}
