#include <stdio.h>
#include <stdlib.h>
int calc( int x , int y , char ch);

int main()
{
    int z , x , y ;
    char op;

    scanf("%d" , &x);
    scanf("%d" , &y);
    op = getche();

    z= calc( x, y,op );
    printf("result = %d\n" , z);

    getch();
    return 0;
}

int calc( int x , int y , char ch)
{
      int res;
      system("cls||clear");
      switch(ch)
              {
              case '+':
                res = x + y;
                break;
              case '-':
                res = x - y;
                break;
              case '*':
                res = x * y;
                break;
              case '/':
                res = x / y;
                break;
              case '%':
                res = x % y;
                break;

              }
        return res;

}
