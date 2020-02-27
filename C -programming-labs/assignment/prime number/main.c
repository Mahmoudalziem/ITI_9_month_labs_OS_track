#include <stdio.h>
#include <stdlib.h>

int main()
{
     int num , i , flag = 0;

     scanf("%d" , &num);

     if(num == 1 || num == 2)

        printf("this is prim #");

     else
        for(i = 2 ; i < num ; i++)
             {
                  if (num % i == 0)
                  {
                    flag = 1;
                    printf("this is not prim #");
                    break;
                  }
             }

     if(flag == 0)
        printf("this is prim #");

    getch();
    return 0;
}
