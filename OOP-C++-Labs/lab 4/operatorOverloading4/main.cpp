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
       Complex operator+=(Complex &c);
       Complex operator-=(Complex &c);

};
Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex Complex::operator+=(Complex &c)
{

    this->real = this->real + c.real;
  this->imag = this->imag + c.imag;
    return *this;
}
Complex Complex::operator-=(Complex &c)
{

     this->real = this->real - c.real;
    this->imag = this->imag - c.imag;
    return *this;
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



    c1 += c2;
    cout<<"c1 += c2\n";
    c1.printComplex();


    c1 -= c2;
    cout<<"c1 -= c2\n";
    c1.printComplex();

    return 0;
}
