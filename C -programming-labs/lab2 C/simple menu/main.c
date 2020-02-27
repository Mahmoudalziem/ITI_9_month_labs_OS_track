#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    char ch;
    int f = 0;

    do{
        system("cls||clear");
        printf("New \n Display \n Exit");

        ch=getch();
        system("cls||clear");
        switch(ch)
            {
           case 'N':
           case 'n':
               printf("New");
               break;
           case 'D':
           case 'd':
               printf("Display");
               break;
           case 'E':
           case 'e':
               printf("exit");
               f = 1;
               break;
            }
        getch();
    }while(f == 0);


    return 0;
}
