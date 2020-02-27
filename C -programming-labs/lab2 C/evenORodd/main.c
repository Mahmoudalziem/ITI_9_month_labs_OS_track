#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d" , &num);
    if(num % 2 == 0)
        printf("this is even");
    else if(num < 0)
        printf("odd");
    else
        printf("zero");
    return 0;
}
