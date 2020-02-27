#include <stdio.h>
#include <stdlib.h>
#define null -32

int sum(int* ptr , int size);
int avg(int* ptr , int size);
int searching(int* ptr , int size , int num);

int main()
{

     int size , i , res ,avg_of_arr , ser;
     int* ptr;

     printf("Enter the size of array:");
     scanf("%d" , &size);

     ptr = (int*) malloc(size * sizeof(int));

     if(ptr != null)
     {
         for(i = 0 ;i < size ; i++)

            scanf("%d" , &ptr[i]);

         for(i = 0 ; i < size ; i++)

             printf("%d\t" , ptr[i]);

             // sumation
        res = sum( ptr  , size);
        printf("\nsumation = %d" , res);

            //average
        avg_of_arr = avg( ptr , size);
        printf("\naverage = %d" , avg_of_arr );

       ser = searching(ptr , size , 10);
         if(ser != -1)
            printf("\nthe num found in index # : %d" , ser);
         else
            printf("\nnot found");

         free(ptr);
     }


    getch();
    return 0;
}

int sum(int* ptr , int size)
     {
        int i;
        int sum = 0;

        for(i = 0 ; i < size ; i++)

           sum += ptr[i];

        return sum;
     }

int avg(int* ptr , int size)
      {
          int i , res = 0;

          for(i = 0 ; i < size ; i++)
             res += ptr[i];
          res /= size;

          return res;
      }

int searching(int* ptr , int size , int num)
{
    int i;

    for(i = 0 ; i < size ; i++)
        if( num == ptr[i])
           return i;
    return -1;

}
