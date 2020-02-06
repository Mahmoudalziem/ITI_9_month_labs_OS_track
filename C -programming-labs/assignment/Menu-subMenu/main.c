#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void menu(char arr[][10] ,int pos);
/*
void sub_file(char file[][10] , int pos2);
void sub_edit(char edit[][10] ,int pos2);
void sub_view(char view[][10] , int pos2);
*/
void sub(char sub_menu[][10] ,int pos2);

int main()
{
    int i ,pos = 0 , flag = 0 , pos2 = 0;
    char ch;
    char arr[3][10] = {"File" , "Edit" , "View"};
    char file[3][10] = {"save" , "new" , "save as"};
    char edit[3][10] = {"open" , "font" , "color"};
    char view[3][10] = {"direction" , "tools" , "screen"};

    /*
        printf("Enter the menu :\n");

        for(i = 0 ; i < 3 ; i++)
        {
           scanf("%s" , arr);
        }

        */
    do
    {
        system("cls || clear");

        menu(arr , pos );

        ch = getch();
        switch(ch)
        {
        case null:
            ch=getch();
            switch(ch)
            {
            case 75: // left
                pos--;
                if(pos < 0)
                    pos = 2;
                break;

            case 77: // right
                pos++;
                if(pos > 2)
                    pos = 0;
                break;
            }
            break;



        case 13: //enter

            if(pos == 0)
            {

                sub(file,0);
            }
            else if(pos == 1)
            {

                sub(edit , 1);
            }
            else
            {

                sub(view ,2);
            }
            getch();
            break;

        case 27:
            flag = 1;
            break;

        }



    }
    while(flag == 0);


    getch();
    return 0;
}

void menu(char arr[][10] ,int pos)
{
    int i;
    for(i = 0 ; i < 3 ; i++)
    {
        if(i == pos)
        {
            textattr(0x70);
        }

        gotoxy(15*i+10 , 5);
        //gotoxy(10 , 5+i);

        printf("%s" , arr[i]);
        textattr(0x07);

    }
}
void sub(char sub_menu[][10] ,int pos2)
{

    int i ;
    // int col = 0;
    for(i = 0 ; i < 3 ; i++)
    {
        //if(i == pos2)


        switch(pos2)
        {
        case 0:
            gotoxy(10 , 6+i);
            printf("%s" , sub_menu[i]);
            break;
        case 1:
            gotoxy(25 , 6+i);
            printf("%s" , sub_menu[i]);
            break;
        case 2:
            gotoxy(40 , 6+i);
            printf("%s" , sub_menu[i]);
            break;
        }
        // textattr(0x07);



    }
}


/*
void sub_edit(char edit[][10])
{

    int i;
    for(i = 0 ; i < 3 ; i++)
    {
        gotoxy(25 , 6+i );
        printf("%s\n" , edit[i]);
    }
}

void sub_view(char view[][10])
{

    int i;
    for(i = 0 ; i < 3 ; i++)
    {
        gotoxy(40 , 6+i );
        printf("%s\n" , view[i]);
    }
}

*/
