#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void reverseNumber(int* number , int* reverseNum);
int main()
    {
        /*
            int num , reverseNum = 0;

            printf("Enter an Integer Number :");
            scanf("%d" , &num);

            reverseNumber(&num , &reverseNum);
            printf("%d" , reverseNum);


        */

        //string
        int i , end , count = 0;
        char str[10];
        char* ptr;
        ptr = (char*)malloc(10 * sizeof(char));
        scanf("%s" , str);

        while(str[count] != '\0')
            count++;

        end = count-1;

        for(i = 0 ; i < count ; i++)
        {
            ptr[i] = str[end];
            end--;
        }

        ptr[i] = '\0';

        printf("%s" , ptr);

        free(ptr);

        getch();
        return 0;
    }
/*
void reverseNumber(int* number , int* reverseNum)
    {
        int reminder;
        while(*number != 0)
        {

            reminder = *number %10;
            *reverseNum = *reverseNum*10 + reminder;
            *number /= 10;
        }
    }
*/
