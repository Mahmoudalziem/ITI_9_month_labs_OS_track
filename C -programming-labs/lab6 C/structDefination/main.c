#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int id;
    char name[30];
    int salary;
};

struct emp getData();
void printData(struct emp e1);

int main()
{

    struct emp e2;
    e2 = getData();
    printData(e2);

    getch();
    return 0;
}

struct emp getData()
{
    struct emp e;
    printf("Enter th Data of employee:\n");
    scanf("%d" , &e.id);
    scanf("%s" , e.name);
    scanf("%d" , &e.salary);

    return e;
}

void printData(struct emp e1)
{
    printf("%d:%s:%d" , e1.id , e1.name ,e1.salary);
}
