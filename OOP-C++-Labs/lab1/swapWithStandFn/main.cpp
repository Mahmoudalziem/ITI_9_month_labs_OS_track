#include <iostream>

using namespace std;

void swap1(int x , int y)
{
    int z;
    z = x;
    x = y;
    y = z;
}

void swap2(int* x , int* y)
{
    int z;
     z = *x;
    *x = *y;
    *y = z;
}

void swap3(int& x , int& y)
{
    int z;
    z = x;
    x = y;
    y = z;
}

int main()
{
    int a = 10 , b = 15;

    //call by value
    swap1(a , b);
    cout <<"call by value\na = "<<a<<"\nb = "<<b<<endl;

    //call by address
    swap2(&a , &b);
    cout << "call by address\na = " <<a<<"\nb = "<<b<<endl;

    //call by reference
    swap3(a , b);
    cout <<"call by reference\na = " <<a<<"\nb = "<<b<<endl;

    return 0;
}
