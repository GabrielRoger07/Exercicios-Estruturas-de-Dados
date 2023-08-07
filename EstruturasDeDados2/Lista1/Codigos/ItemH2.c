#include <stdio.h>
#include <strings.h>

int main(int argc, char const *argv[])
{
    int nota, quantidadeAlunos, notaMenor = 11;
    char *nome, *nomeReprovado;

    nome = malloc(21);
    nomeReprovado = malloc(21);

    strcpy(nomeReprovado, "a");

    scanf("%d", &quantidadeAlunos);
    for(int i = 0; i < quantidadeAlunos; i++){
        int j = 0;
        scanf(" %s %d", nome, &nota);
        if(notaMenor >= nota){
            if(notaMenor > nota){
                notaMenor = nota;
                strcpy(nomeReprovado, nome);
            }else{
                while(nomeReprovado[j] == nome[j]){
                    j++;
                }
                if(nomeReprovado[j] < nome[j]){
                    strcpy(nomeReprovado, nome);
                }
            }
        }
    }
    printf("Instancia 1\n");
    printf("%s\n", nomeReprovado);
    return 0;
}
