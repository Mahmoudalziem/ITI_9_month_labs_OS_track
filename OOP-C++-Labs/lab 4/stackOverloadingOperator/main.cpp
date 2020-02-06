#include <iostream>

using namespace std;

class Stack
    {
        int tos;    //Top of stack
        int  sizee;  //Size of stack
        int *stk;  //Array


        public:
            Stack(int n=10);
            Stack(Stack &x);
            int popFn();
            void pushFn(int num);

            ///operator overloading///
            void operator=(const Stack &s);

           friend void viewContent(Stack x);
          //friend void viewContent(Stack &x);

    };

  /// + operator overloading function
void Stack::operator=(const Stack &s)
{
    delete[] this->stk;
    this->tos = s.tos;
    this->sizee = s.sizee;
    this->stk = new int[sizee];
    for(int i=0 ; i < tos ; i++)
        this->stk[i] = s.stk[i];
}

///copy constructor
Stack::Stack(Stack &z)
    {

         tos = z.tos;
         sizee = z.sizee;
         stk = new int[sizee];
         for(int i= 0 ; i < tos ; i++)
            stk[i] = z.stk[i];


    }

///Constructor
Stack::Stack(int n)
     {

         tos = 0;
         sizee = n;
         stk = new int[sizee];

     }


//push Function
void Stack::pushFn(int num)
    {
        cout<<"push( " << num <<")\n";

        if( tos != sizee)
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

}

//call by reference
/*void viewContent(Stack &x)
{
         int t = x.tos;
         while(t != 0)
            cout<<x.stk[--t]<<endl;

}
*/

int main()
{
    Stack s1(3);
    Stack s2(2);



    s1.pushFn(2);
    s1.pushFn(3);
    s1.pushFn(4);

    s2.pushFn(4);
    s2.pushFn(5);

  cout<<"before:\ns1\n";
    viewContent(s1);
  cout<<"s2\n";
    viewContent(s2);


   s2 = s1;

  cout<<"after:\ns1\n";
    viewContent(s1);
  cout<<"after\n";
    viewContent(s2);

    return 0;
}




