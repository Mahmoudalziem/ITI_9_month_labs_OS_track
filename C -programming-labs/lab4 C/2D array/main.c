#include <stdio.h>
#include <stdlib.h>
//int sum_of_deg(int deg[] , int n);
/*#include<windows.h>

void gotoxy(int x, int y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
*/
int main()
{
    int avg[3]={0};
    int arr[3][3] ,sum[3]={0};
    int i , j ,num , sumation;

     system("cls||clear");
    printf("Enter students degree:\n");

    // user enter the degree
     system("cls||clear");
    for(i=0 ; i<3 ; i++)
        {
            for(j=0 ; j<3 ; j++)

                scanf("%d" , &arr[i][j]);

            printf("\n");

        }

    for(i=0 ; i<3 ; i++)
        {
            for(j=0 ; j<3 ; j++)

                {
                  //gotoxy(i , j);
                   printf("%d\t" , arr[i][j] );
                   sum[i] += arr[i][j];

                }

              printf("sum = %d\n" , sum[i]);


           /* sumation = sum_of_deg( arr );
            printf("%d\n" , sumation);*/

        }

     for(j=0 ; j<3 ; j++)
     {

        for(i=0 ; i<3 ; i++)
        {

          avg[j] += arr[i][j];

        }
        avg[j] /= 3;
        printf("%d\t" , avg[j]);
     }


    getch();
    return 0;

}

/*int sum_of_deg(int deg[][] , int n)
{
      int i ,j, sum[3];

      for(i=0 ; i<n ;i++)
      {

        for(j=0 ; j<n ; j++)

           sum[i] += deg[i][j];
      }

    return sum[i];

}*/
