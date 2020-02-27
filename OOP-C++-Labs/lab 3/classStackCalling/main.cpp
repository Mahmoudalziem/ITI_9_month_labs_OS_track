#include <iostream>

using namespace std;

class Stack
    {
        int tos;    //Top of stack
        int  s;  //Size of stack
        int *stk;  //Array
        static int counter;

        public:
             Stack(int n=10);
             Stack(Stack &x);
            ~Stack();
            int popFn();
            void pushFn(int num);
            //void getStack();
            static int getCount();

          friend void viewContent(Stack x);
         // friend void viewContent(Stack &x);

    };
int Stack::counter = 0;
int Stack::getCount()
{
    return counter;
}

//copy constructor
Stack::Stack(Stack &z)
    {

         tos = z.tos;
         s = z.s;
         stk = new int[s];
         for(int i= 0 ; i < tos ; i++)
            stk[i] = z.stk[i];

        counter++;
    }

//Constructor
Stack::Stack(int n)
     {
         counter++;
         tos = 0;
         s = n;
         stk = new int[s];
         cout<<"\ncall constructor\n";

     }

//Destructor
Stack::~Stack()
{

    delete[] stk;

    cout<<"\ncall dectructor";
    //cout<<"\nthe distroyed object number "<<counter;
    counter--;

}

//push Function
void Stack::pushFn(int num)
    {
        cout<<"push( " << num <<")\n";

        if( tos != s)
        {
            stk[tos] = num;
            tos++;
        }
        else
            cout<<"sorry the stack is full";
    }

// pop Function
int Stack::popFn()
    {
        int res;
        if( tos == 0)
            {
                cout<<"The stack is empty";
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
 void viewContent(Stack x)
 {
     int t = x.tos;
     while(t != 0)
        cout<<x.stk[--t]<<endl;

    cout<<"the # objects = "<<Stack::getCount();

}

//call by reference
/*
void viewContent(Stack &x)
{
         int t = x.tos;
         while(t != 0)
            cout<<x.stk[--t]<<endl;

}
*/
/*void Stack::getStack()
{
    int t = tos;
            while(t != 0)
            {
                cout<<stk[--t]<<endl;

            }


}
*/



int main()
{

    Stack s1(3);
    //cout<<"enter th size of stack: ";
    //cin>>s;

    s1.pushFn(3);
    s1.pushFn(4);
    s1.pushFn(5);



   // Stack s2(3);

   // s1.getStack();  cout<<"\n";
    cout<<"the # objects = "<<Stack::getCount()<<"\n";
    viewContent(s1);
    cout<<"\n";
    cout<<"the # objects = "<<Stack::getCount();
    //s1.getStack();
    cout<<"\n";
  //  s1.getStack();

    return 0;
}
