#include <stdio.h>
#include <stdlib.h>
void swap(int* x ,int* y);

int main()
{
    int x = 10 , y = 15 , z;

  //  int* ptrx = &x;
   // int* ptry = &y;

    swap(&x,&y);
    printf("x= %d and y= %d" , x ,y);

    getch();
    return 0;
}

void swap(int* x ,int* y)
{

    int temp = *x;
        *x = *y;
        *y = temp;


}
