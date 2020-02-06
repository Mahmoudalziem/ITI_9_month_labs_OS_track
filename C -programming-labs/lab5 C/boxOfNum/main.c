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

int main()
{
    int size , i , pos = 0;
    char ch;
    char* arr;

    printf("enter the size:");
    scanf("%d" , &size);

    arr = (char*) malloc(size * sizeof(char));

    for(i = 0 ; i < size ; i++)
    {
        //textattr(0x70);
        arr[i] = ' ';
    }


   do{
       system("cls || clear");
       for(i = 0 ; i < size ; i++)
           {
               textattr(0x70);
               printf("%c" , arr[i]);
               textattr(0x07);

           }

               gotoxy(pos , 0);



       ch = getch();
       switch(ch)
       {
          case null:
              ch = getch();
              switch(ch)
              {

                case 75://left
                    if(pos == 0)
                        break;
                    pos--;
                    break;

                case 77: // right
                    if(pos == size-1)
                        break;
                    pos++;
                    break;
                case 72:  //up
                    if(arr[pos] >= 97 && arr[pos]<= 122)
                        arr[pos] = arr[pos]-32;
                    break;
                case 80:  //down
                   if(arr[pos] >= 65 && arr[pos]<= 90)
                        arr[pos] = arr[pos]+32;
                    break;


              }
           break;

          case 13:
              printf("\n\n");
              for(i = 0 ; i < size ; i++)
                printf("%c" , arr[i]);
            break;

           /* case 8:
               for(i = pos ; i < size ; i++)
               {
                   pos--;
                   arr[pos] = arr[i];
               }
               */


          default:
              if(pos > size-1)
                break;
              if((ch >= 97 && ch<= 122) || (ch >= 65 && ch<= 90)|| ch == ' ')
              {
                  arr[pos]= ch;
                  pos++;
              }




       }
           /*
           switch(ch)
           {
           case null:
            ch = getch();
            switch(ch)
            {
            case 75://left
                break;
            case 77: // right
                break;
            case 72:  //up
                break;
            case 80:  //down
            }
            */
     //      }





   }while(ch != 13);




    getch();
    return 0;
}
