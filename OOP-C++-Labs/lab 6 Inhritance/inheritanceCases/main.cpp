#include <iostream>

using namespace std;

class Base
{

    int a;
    //int b;
protected:
    int b;

public:
    Base()
        {
            a = b = 0;
        }
    Base(int n)
        {
            a = b = n;
        }
    Base(int x , int y)
        {
            a = x;
            b = y;
        }
    void setA(int x)
        {
            a = x;
        }
    void setB(int y)
        {
            b = y;
        }
    int getA()
        {
            return a;
        }
    int getB()
        {
            return b;
        }
   /* int productAB()
        {
            return a * b;
        } */
      int product()    /** override **/
      {
          return a * b ;
      }
};

/** Derived Class **/
class Derived : public Base
{
  int c;
  public:
      Derived():Base()
       { c = 0;}

      Derived(int n):Base(n)
       { c = n;}

      Derived(int x, int y , int z):Base(x,y)
       { c = z;}

      void setC(int z)
       { c = z; }

      int getC()
       { return c;}
     /*
      int productABC()
      {
           //private b
          //return productAB()*c;

          //protected b
          return getA() * b * c;


      }
      */
      int product()    /** overriding **/
      {
          return Base::product() * c ;
      }



};

/** secondDerived Class **/
class SecondDerived : public Derived
{
  int d;
  public:
      SecondDerived():Derived()
       { d = 0;}

      SecondDerived(int n):Derived(n)
       { d = n;}

      SecondDerived(int x, int y ,int m ,int z):Derived(x,y,m)
       { d= z;}

      void setD(int z)
       { d = z; }

      int getD()
       { return d;}

      int product()    /** overriding **/
      {
          return  getA() * b * getC() * d;
      }



};

int main()
{
    Derived obj1;
    Base b(5,4);
    SecondDerived snd(1,2 ,3 ,4);

    /** pointer of Base **/
    Derived obj2(10 , 20 , 30);
    Base *pt = &obj2;

    /**  private **/
/*
    //access from Derived object
    obj1.setA(3);
    obj1.setB(7);
    obj1.setC(2);

    cout<<"From obj1 : a * b = "<<obj1.productAB()<<endl;
    cout<<"From obj1 : a * b * c = "<<obj1.productABC()<<endl;

    //access from Base object
    b.setA(3);
    b.setB(7);

    cout<<"From b : a * b = "<<obj1.productAB()<<endl;

*/

  /** overriding method access **/

    cout<<"calling product by Base object : "<<b.product()<<endl;
    cout<<"calling product by Derived object : "<<obj1.product()<<endl;
    cout<<"calling product by Derived object : "<<obj1.Base::product()<<endl;
     cout<<"calling product by SecondDerived object : "<<snd.product()<<endl<<endl;

  /** overriding method access by Base pointer **/

    cout<<"calling product by Derived object : "<<obj2.product()<<endl;   /** call derived method **/
    cout<<"calling product by Derived object : "<<obj2.Base::product()<<endl; /** call Base method **/
    cout<<"calling product by Base Pointer : "<<pt -> product()<<endl;  /** call Base method **/




    return 0;
}
