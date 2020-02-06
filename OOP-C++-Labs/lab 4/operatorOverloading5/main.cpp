
#include <iostream>

using namespace std;

class Complex
{
    float real;
    float imag;

  public:
      Complex();
      Complex(int real , int imag);
     // ~Complex();
      float getReal();
      float getImag();
      void printComplex();
      int operator==(Complex c);


};
Complex::Complex()
{
    real = 0;
    imag = 0;
}

int Complex::operator==(Complex c)
{
    if(this->real == c.real && this->imag == c.imag)
        return 1;
    return 0;
}

Complex::Complex(int real , int imag)
{
   this->real = real;
    this->imag = imag;
}

/*
Complex::~Complex()
{
    cout<<"\nThe object destructed\n";
}

*/

float Complex::getReal()
 {
     return real;
 }

float Complex::getImag()
{
    return imag;
}

//print objects
void Complex::printComplex()
{
    if(imag < 0)
        cout<<real<<"-"<<imag<<"i"<<endl;
    else if(imag > 0)
        cout<<real<<"+"<<imag<<"i"<<endl;
}

int main()
{
   Complex c1(10 , 3);
   Complex c2(5 , 2);



    if(c1==c2)
    cout<<"true\n";
    else
    cout<<"false\n";


    return 0;
}
