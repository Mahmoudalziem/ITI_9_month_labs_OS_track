#include <stdio.h>
#include <stdlib.h>
int factorial(int num);
int power(int x , int n);

int main()
{
    int z , y , number;

    scanf("%d" , &number);

    //factorial
    z = factorial(number);
    printf("the factorial of # = %d\n" , z);

    //power
    y = power(number ,3 );
    printf("the power of # = %d  \n" , y);

    getch();
    return 0;
}

int factorial(int n)
{
    int i ,res = 1;
    for(i = n ; i > 0 ; i--)
    {
        res  *= i;
    }


    return res;

}

int power(int x , int n)
{
    int i , res = 1;
    for(i = 0 ; i < n ; i++)

        res *= x;

    return res;

}

