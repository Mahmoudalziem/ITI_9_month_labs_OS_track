#include <iostream>

using namespace std;

class Stack
    {
        int tos;  //Top of stack
        int  s;  //Size of stack
        int *stk;  //Array


        public:
            Stack(int n=10);
            //~Stack();
            int popFn();
            void pushFn(int num);
            //static int getCount();

    };

//Constructor
Stack::Stack(int n)
     {
//         counter++;
         tos = 0;
         s = n;
         stk = new int[s];

     }

//Destructor
Stack::~Stack()
{

    delete[] stk;

    //counter--;
    //cout<<"\nthe distroyed object number"<<counter;
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



int main()
{
    int popNum;
    Stack resultStack(5);
    //cout<<"enter th size of stack: ";
    //cin>>s;

    resultStack.pushFn(2);
    resultStack.pushFn(3);
    cout<<"pop( ) -> "<<resultStack.popFn()<<endl;
    resultStack.pushFn(4);
    resultStack.pushFn(5);

    //popNum = resultStack.popFn();
    cout<<"\npop( ) -> " <<resultStack.popFn();
    cout<<"\npop( ) -> " <<resultStack.popFn();
    cout<<"\npop( ) -> " <<resultStack.popFn();
    cout<<"\npop( ) -> " <<resultStack.popFn();

    Stack s1(3);
    cout<<"\nthe # object "<<Stack::getCount();




/*
    while(resultStack.stk[tos] != s)
    {
        if (num == 1)
            {
                cin>>stkNum;
                resultStack.pushFn(num);
                cout<<"push( " << num <<")\n";
            }
        else if(num == 0)
            {
                   popNum = resultStack.pophFn();

                   cout<<"pop( ) -> " <<popNum;
            }
    }
    */
    return 0;
}
