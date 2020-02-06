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
    int i , j , size;
    struct emp* arr;

    printf("Enter the size of array: ");
    scanf("%d" , &size);

    arr = (struct emp*)malloc(size * sizeof(struct emp));

        printf("Enter the Data of all employees:\n");

        for(i = 0 ; i < size ; i++)
        {
            scanf("%d" , &arr[i].id);
            scanf("%s" , arr[i].name);
            scanf("%d" , &arr[i].salary);
            printf("\n");
        }

        for(i = 0 ; i < size ; i++)
        {
            printf("%d : %s : %d" , arr[i].id , arr[i].name , arr[i].salary);
            printf("\n");
        }


    getch();
    return 0;
}
