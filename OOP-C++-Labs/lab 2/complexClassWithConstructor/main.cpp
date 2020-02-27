#include <iostream>

using namespace std;

class Complex
{
    float real;
    float imag;

  public:


      Complex();
      Complex(int num);
      ~Complex();
      void setComplex(float real ,float img);
      float getReal();
      float getImag();
      void printComplex();


};

Complex::Complex()
{
    real = 3;
    imag = 5;

    //cout<<"this is default constructor: ";
}
Complex::Complex(int num)
{
    real = imag = num;

    //cout<<"this is overloaded constructor: ";
}
void Complex::setComplex(float real , float imag)
{
    this->real = real;
    this->imag = imag;

}
Complex::~Complex()
{
    cout<<"\nThe object destructed\n";
}



float Complex::getReal()
 {
     return real;
 }

float Complex::getImag()
{
    return imag;
}

//addition function

Complex addFn(Complex comp1 , Complex comp2)
{
    Complex result;
    int x , y;

    x = comp1.getReal() +  comp2.getReal();
    y = comp1.getImag() +  comp2.getImag();
    result.setComplex(x , y);

    return result;
}
//addition function
Complex subtractFn(Complex comp1 , Complex comp2)
{
    Complex result;
    int x , y;

    x = comp1.getReal() -  comp2.getReal();
    y = comp1.getImag() -  comp2.getImag();
    result.setComplex(x , y);

    return result;
}

void Complex::printComplex()
{
    if(imag < 0)
        cout<<real<<"-"<<imag<<"i"<<endl;
    else if(imag > 0)
        cout<<real<<"+"<<imag<<"i"<<endl;
}

int main()
{
   int real , img;
   Complex comp1 ,comp3 ,resultComp;
   Complex comp2(3);



   cout<<"Enter the real number: "<<endl;
    cin>>real;

   cout<<"Enter the imag number: "<<endl;
    cin>>img;

   cout<<"this is default constructor: ";
   comp1.printComplex();

   cout<<"this is overloaded constructor: ";
   comp2.printComplex();

   cout<<"this is setcomplex method by input user: ";
   comp3.setComplex(real , img);
   comp3.printComplex();

   //complex number of addition comp1 + comp3
   cout<<"\ncomplex number of addition comp1 + comp3:\n";
   resultComp = addFn(comp1 , comp3);
   resultComp.printComplex();

    //complex number of addition comp1 + comp3
   cout<<"\ncomplex number of subtraction comp1 + comp3:\n";
   resultComp = subtractFn(comp3 , comp2);
   resultComp.printComplex();



    return 0;
}
