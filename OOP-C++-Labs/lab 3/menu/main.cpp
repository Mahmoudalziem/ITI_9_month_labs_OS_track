#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <conio.h>
#define null -32
using namespace std;

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
class Stack
    {
        int tos;    //Top of stack
        int  s;  //Size of stack
        int *stk;  //Array
        //static int counter;

        public:
            Stack(int n=10);
           // Stack(Stack &x);
            //~Stack();
            int popFn();
            void pushFn(int num);
            void getStack();
            //static int getCount();

          //friend void viewContent(Stack x);
          friend void viewContent(Stack &x);

    };
Stack::Stack(int n)
     {

         tos = 0;
         s = n;
         stk = new int[s];

     }



//push Function
void Stack::pushFn(int num)
    {
        if( tos != s)
            {
                stk[tos] = num;
                tos++;
            }
        else
            printf("sorry the stack is full");
    }

// pop Function
int Stack::popFn()
    {
        int res;
        if( tos == 0)
            {
                printf("The stack is empty");
                return -1;
            }
        else
            {
                tos--;
                res = stk[tos];

            }
        return res;

    }
//call by value
 /*void viewContent(Stack x)
 {
     int t = x.tos;
     while(t != 0)
        cout<<x.stk[--t]<<endl;

}
*/
//call by reference
void viewContent(Stack &x)
{
         int t = x.tos;
         while(t != 0)
            cout<<x.stk[--t]<<endl;

}

void Stack::getStack()
{
    int t = 0;
            while(t < tos)
            {
                cout<<stk[t]<<endl;
                t++;

            }


}

void draw(int pos ,char menu[][10],int d);

int main()
{
    int i ,number,pos=0 , flag = 0;
    Stack resultStack(4);
    char menu[3][10]={"New" , "Display" , "pop"};
    char ch;
do{
    system("cls ||clear");
    /*for(i = 0 ; i< 3 ; i++)
        {
            if(i == pos)
            textattr(0x70);
            gotoxy(10 , 10+i);
            printf("%s" , menu[i]);
            textattr(0x07);
        }
     */
     //calling draw function
     draw(pos , menu ,0);

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
                            pos = 2;
                        break;

                    case 80:  //down
                        pos++;
                        if(pos > 2)
                            pos= 0;
                        break;

                    }
                    break;

          case 13: //enter
              system("cls||clear");
              //printf("%s" , menu[pos]);
              if(pos == 0)
                  {
                          //push Function
                        cin>>number;
                        resultStack.pushFn(number);

                  }
             else if(pos == 1)
                {
                    resultStack.getStack();

                }

            else if(pos == 2)
            {
               cout<<"pop( ) -> "<<resultStack.popFn()<<endl;
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

//function

void draw(int pos ,char menu[][10],int d)
{
    int i;

    for(i = 0 ; i< 3 ; i++)
        {
            if(i == pos)
                textattr(0x70);

            if(d==0)
               //gotoxy(15*i+10 , 5);
               gotoxy(10 , 5+i);

            printf("%s" , menu[i]);
            textattr(0x07);
        }
}
