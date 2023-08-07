#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n1, ret, total = 0;

    while((ret = scanf("%d", &n1)) != EOF){
        total++;
    }
    printf("%d", total);
    return 0;
}
