#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define null -32
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
  GetStdHandle( STD_OUTPUT_HANDLE ),
  coord
    );
  }

//void draw(int pos ,char menu[][10],int d);

struct emp
{
    int id;
    char name[20];
    int salary;
};

struct emp scanData();

int main()
{
    int i ,pos=0 , flag = 0 , s  , loc, ask , id  , f = 0 , res ;
    char menu[4][10]={"New" , "Display" , "Exit" , "search"};
    char ch;
    char word[10];
    struct emp* arr;

    printf("Enter the size of arr: ");
    scanf("%d" , &s);

    arr = (struct emp*) malloc(s * sizeof(struct emp));
     for(i = 0; i < s ; i++ )
        arr[i].id = -1;

do{
    system("cls ||clear");
    for(i = 0 ; i< 4 ; i++)
        {
            if(i == pos)
            textattr(0x70);
            gotoxy(10 , 10+i);
            printf("%s" , menu[i]);
            textattr(0x07);
        }

     //calling draw function
     //draw(pos , menu ,0);

     ch = getch();
     switch(ch)
     {
         case null:
                ch= getch();
                switch(ch)
                    {
                    case 72:  //up
                        pos--;
                        if(pos < 0)
                            pos = 3;
                        break;

                    case 71:  // home
                        pos = 0;

                        break;
                    case  79:  //end
                        pos = 3;
                        break;
                    case 80:  //down
                        pos++;
                        if(pos > 3)
                            pos= 0;
                        break;

                    }
                    break;

          case 13: //enter
                  system("cls || clear");
                  switch(pos)
                  {
                    case 0:
                              printf("Enter the location of struct :");
                              scanf("%d" , &loc);

                              if(arr[loc].id == -1)
                                 {

                                    scanf("%d" , &arr[loc].id);
                                    scanf("%s", arr[loc].name);
                                    scanf("%d", &arr[loc].salary);

                                     //e2 = struct emp scanData();

                                 }
                             else
                                 {
                                    printf("do you like insert Data? 0 or 1");
                                    scanf("%d" , &ask);
                                    if(ask == 1)
                                        {
                                            printf("Enter the Data :\n");
                                            scanf("%d" , &arr[loc].id);
                                            scanf("%s", arr[loc].name);
                                            scanf("%d", &arr[loc].salary);
                                        }

                                 }

                     break;

                    case 1:
                        for(i = 0 ; i < s ; i++)
                        {
                            if(arr[i].id != -1)
                            printf("%d:%s:%d" , arr[i].id , arr[i].name , arr[i].salary);
                        }
                       break;

                   case  2:
                       flag = 1;
                       break;

                    case 3:
                         //search by id
                        printf("Enter the ID to search: ");
                        scanf("%d" , &id);
                        f = 0;
                        for(i = 0 ; i < s ; i++)
                            {
                                if(arr[i].id == id)
                                {
                                   printf("this id is fount in index # : %d\n" , i);
                                    f = 1;
                                }

                            }
                        if(f == 0)
                           printf("this id not found\n");

                           //search by name

                       printf("Enter the name to search: ");
                        scanf("%s" , word);

                        f = 0;

                        for(i = 0 ; i < s ; i++)
                            {
                                res = strcmpi(word , arr[i].name);
                                if(res == 0 )
                                {
                                   printf("this id is found");
                                    f = 1;
                                }

                            }
                        if(f == 0)
                           printf("this name not found");

                  }
              getch();
              break;

          case 27:
            flag = 1;
            break;



     }
}while(flag == 0);


    getch();
    return 0;
}

struct emp scanData()
{
    struct emp e;
      scanf("%d" , &e.id);
      scanf("%s", e.name);
      scanf("%d", &e.salary);
    return e;
}

//function

/*void draw(int pos ,char menu[][10],int d)
{
    int i;

    for(i = 0 ; i< 3 ; i++)
        {
            if(i == pos)
                textattr(0x70);

            if(d==0)
                gotoxy(15*i+10 , 5);

            printf("%s" , menu[i]);
            textattr(0x07);
        }
}
*/
