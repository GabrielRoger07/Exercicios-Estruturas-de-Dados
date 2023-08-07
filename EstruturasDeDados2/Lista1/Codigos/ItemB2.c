#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int quant, num, total = 0;
    scanf("%d", &quant);
    for(int i = 0; i< quant; i++){
        scanf("%d", &num);
        total = total + num;
    }
    printf("%d\n", total);
    return 0;
}
