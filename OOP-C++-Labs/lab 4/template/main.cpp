#include <iostream>

using namespace std;

template <class T>
class Stack
    {
        int tos;    ///Top of stack
        int  sizee;  ///Size of stack
        T *stk;  ///Array


        public:
            Stack<T>(T n);
            //Stack(Stack &x);
            T popFn();
            void pushFn(T num);

          //friend void viewContent(Stack &x);

    };


///Constructor
template <class T>
Stack<T>::Stack(T n)
     {

         tos = 0;
         sizee = n;
         stk = new T[sizee];

     }


///push Function
template <class T>
void Stack<T>::pushFn(T num)
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

/// pop Function
template <class T>
T Stack<T>::popFn()
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
    Stack<int> s1(3);
    Stack<char> s2(2);



    s1.pushFn(2);
    s1.pushFn(3);
    s1.pushFn(4);

    s2.pushFn('e');
    s2.pushFn('R');




    return 0;
}




