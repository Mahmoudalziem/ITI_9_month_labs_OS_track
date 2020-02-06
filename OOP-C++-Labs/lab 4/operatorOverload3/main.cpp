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
      friend Complex operator+(float x , Complex c);
      friend Complex operator-(float x , Complex c);

};
Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex operator+(float x ,Complex c)
{
    Complex b;
    b.real = x + c.real;
    b.imag = c.imag;
    return b;
}
Complex operator-(float x ,Complex c)
{
    Complex b;
    b.real = x - c.real;
    b.imag = c.imag;
    return b;
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

   Complex c3;


    c3 = 5 + c1;
    cout<<"c3 = 5 + c1\n";
    c3.printComplex();


    c3 = 5 - c1;
      cout<<"c3 = 5 - c1\n";
    c3.printComplex();

    return 0;
}
