#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y , res;
    char op;
    scanf("%d" , &x);
    scanf("%d" , &y);
    op = getch();
    switch(op)
    {
    case '+':
        res = x+y;
        break;
    case '-':
        res = x-y;
        break;
    case '*':
        res = x*y;
        break;
    case '/':
        res = x/y;
        break;
    case '%':
        res = x%y;
        break;
    }

    printf("res=%d" , res);
    return 0;
}
