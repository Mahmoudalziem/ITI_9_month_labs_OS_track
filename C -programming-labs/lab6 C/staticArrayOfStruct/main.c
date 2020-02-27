#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int id;
    char name[20];
    int salary;
};

int main()
{
    int i ;
    struct emp arr[3];

    printf("Enter the Data of all employees:\n");
    for(i = 0 ; i < 3 ; i++)
    {
            printf("Enter  employee:\n");

        scanf("%d" , &arr[i].id);
        scanf("%s" , arr[i].name);
        scanf("%d" , &arr[i].salary);
        printf("\n");
    }
    for(i = 0 ; i < 3 ; i++)
    {
        printf("%d : %s : %d" , arr[i].id , arr[i].name , arr[i].salary);
        printf("\n");
    }

    getch();
    return 0;
}
