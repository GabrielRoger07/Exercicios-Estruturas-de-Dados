#include <stdio.h>

int main(int argc, char const *argv[])
{
    double n1, ret;
    int total = 0;

    while((ret = scanf("%d", &n1)) != EOF){
        total++;
    }
    printf("%d", total);
    return 0;
}
