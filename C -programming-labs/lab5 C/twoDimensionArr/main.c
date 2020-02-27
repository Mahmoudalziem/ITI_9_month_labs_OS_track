#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col , i , j;

    int** ptr;

    printf("enter the row# :");
    scanf("%d" , &row);
    printf("enter the col # :");
    scanf("%d" , &col);


     ptr = (int**) malloc(row * sizeof(int*));

     for(i = 0 ; i < col ; i++)
         ptr[i]=(int*) malloc(col* sizeof(int));

     for(i = 0 ; i < row ; i++)
     {
        for(j = 0 ; j < col ; j++)
              scanf("%d" ,&ptr[i][j]);
     }

    for(i = 0 ; i < row ; i++)
        {
             for(j = 0 ; j < col ; j++)
                  printf("%d\t" , ptr[i][j]);

             printf("\n");
        }

    for(i = 0 ; i < row ; i++)
    {

              free(ptr[i]);
    }

     free(ptr);



    getch();
    return 0;
}
