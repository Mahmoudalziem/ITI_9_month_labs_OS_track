#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size ,x=1,i,j ,row ,col;
    scanf("%d" , &size);
    int arr[size][size];

    for(i=0 ; i< size ; i++){
        for(j=0 ; j<size ; j++)
        {
            if(x==1)
           {
               row = 0;
               col = size/2;
              // arr[0][(size/2)]=1;

           }
       else if ((x-1)% size == 0)
           {
               row++;
                if(row == size)
                   row = 0;
               //arr[0][(size/2)]=1;
           }
       else
           {
               row--;
               if(row < 0)
                row = size-1;
               col--;
               if(col< 0)
                 col= size-1;
           }
            arr[row][col]= x;
            x++;
        }
    }


    for(i=0;i<size ; i++)
    {
        for(j=0 ;j<size ;j++)
        {
            printf("%d " , arr[i][j] );

        }
        printf(" \n ");
    }


     getch();
    return 0;
}
