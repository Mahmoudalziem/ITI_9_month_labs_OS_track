#include <stdio.h>
#include <stdlib.h>

int sum_deg(int deg[] , int s);
int searching(int deg[] , int s , int n);

int main()
{
    int std_deg[5]={};
    int i , x , z , y;

    printf("Enter the students Degree:\n");

    // insert the degree of students in array
    for(i = 0 ; i < 5 ; i++)
    {
        scanf("%d" , &std_deg[i]);
    }

    printf("students degree :\n" );

    // print the array
    for(x = 0 ; x < 5 ; x++)
    {
        printf("%d\n" , std_deg[x]);
    }

    //print sum
    z = sum_deg(std_deg , 5);
    printf("the sum of array = %d \n" , z);

    //search number in array
    y = searching(std_deg , 5 , 50);

         if (y != -1)
            printf("the Number Found in index : %d" , y);
         else
            printf("Not Found");

    getch();
    return 0;
}

int sum_deg(int deg[] , int s)
{
    int sum = 0 , i;
    for(i = 0 ; i < s ; i++)
        {
            sum += deg[i];
        }

    return sum;

}

int searching(int deg[] , int s , int n)
{
    int i;
    for(i = 0 ; i < s ; i++)

          if(n == deg[i])
            return i;


    return -1;

}


