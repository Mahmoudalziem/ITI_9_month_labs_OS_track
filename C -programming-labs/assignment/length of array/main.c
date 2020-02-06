#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strinLength(char str[] , int size , int* count);
int main()
{
        char str[10];
        int len = 0;
        scanf("%s" , str);
        strinLength(str ,10 , &len);
        printf(" length of string = %d" , len);

    getch();
    return 0;
}

void strinLength(char str[] , int size , int* count)
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        if(str[i] == '\0')
            break;
        else
          *count += 1;
    }
}
