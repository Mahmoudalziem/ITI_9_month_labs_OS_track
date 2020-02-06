#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree;
    char grad;
    scanf("%d" , &degree);
    if(degree >= 85)
        grad = 'e';
    else if(degree >= 75)
        grad= 'v';
    else if(degree >= 65)
        grad= 'g';
    else
        grad ='f';

    printf("grad=%c" , grad);

    getch();
    return 0;
}
