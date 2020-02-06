#include <iostream>

using namespace std;

class Complex
{
    float real;
    float imag;

  public:

      void setReal(float);
      void setImag(float);
      float getReal();
      float getImag();
      void print();


};

void Complex::setImag(float i)
{
    imag = i;
}
void Complex::setReal(float i)
{
    real = i;
}

float Complex::getReal()
{
    return real;
}

float Complex::getImag()
{
    return imag;
}

void Complex::print()
{

    if(imag < 0)
        cout<<real<<"-"<< imag<<"i"<<endl;
    else if(imag > 0)
        cout<<real<<"+"<<imag<<"i"<<endl;

}

Complex add(Complex a ,Complex b)
{
    Complex res;

    float res1 , res2;

    res1 = a.getReal() +  b.getReal();
    res.setReal(res1);

    res2 = a.getImag() +  b.getImag();
    res.setImag(res2);

    return res;
}

Complex subtraction(Complex a ,Complex b)
{
    Complex res;

    float res1 , res2;

    res1 = (a.getReal())-(b.getReal());
    res.setReal(res1);

    res2 = (a.getImag())-(b.getImag());
    res.setImag(res2);

    return res;

}

int main()
{
    Complex comp1 , comp2 , resultcomp;
    float real1 , imag1 , real2 , imag2;

    cout<<"Enter the  first real number: "<<endl;
    cin>>real1;

    cout<<"Enter the  first imag number: "<<endl;
    cin>>imag1;

    cout<<"Enter the  second real number: "<<endl;
    cin>>real2;

     cout<<"Enter the  second imag number: "<<endl;
     cin>>imag2;

   comp1.setReal(real1);
   comp1.setImag(imag1);
   comp2.setReal(real2);
   comp2.setImag(imag2);

    comp1.print();
    comp2.print();

    resultcomp = add(comp1 , comp2);
    //cout<< "Add Res :"<<comp1.getImag()<<endl;
    resultcomp.print();

   // resultcomp = subtraction(comp1 , comp2);
    //resultcomp.print();

    return 0;
}
