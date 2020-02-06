#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
void gotoxy(int x, int y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void magic(int size);

int main()
{
    int num;
    scanf("%d" , &num);
    magic(num);

    getch();
    return 0;
}

void magic(int size)
{
    int i , row , col;

    for(i = 1 ; i <= size * size ; i++)
    {
       if(i == 1)
           {
               row = 1;
               col = size / 2+1;
           }
       else if((i-1) % size == 0)
           {
               row++;
           }
       else
           {
               row--;
               col--;
               if(row == 0)
                row = size;
               if (col == 0)
                col = size;

           }
       gotoxy(3*col ,row);
       printf("%d" , i);

    }

}
