#include <iostream>

using namespace std;
class GeoShape
{
protected:

    float dim1;
    float dim2;

public:
    GeoShape()
    { dim1 = dim2 = 0;}

    GeoShape(float x)
    { dim1 = dim2 = x; }

    GeoShape(float x,float y)
    {
        dim1 = x;
        dim2 = y;
    }

    void setDim1(float x)
    { dim1 = x; }

    void setDim2(float x)
    { dim2 = x;}

    float getDim1()
    { return dim1;}

    float getDim2()
    { return dim2; }

    float claculateArea()
    {
        return 0;
    }


};

class Triangle:public GeoShape
{
public:
    Triangle(float base , float hight):GeoShape(base,hight)
    { }
    float calculateArea()
    {
        return 0.5 * dim1 * dim2;
    }
};

class Rect:public GeoShape
{
    public:
    Rect(float x , float y):GeoShape(x,y)
    { }
    /** overriding **/
    float calculateArea()
    {
        return dim1 * dim2;
    }

};

class Square:private Rect
{
public:
    Square(float x):Rect( x, x)
    { }

    void setSquarDim(float x)
    { dim1 = dim2 = x;}

    float getSquareDim()
    { return dim1; }

    /** overriding **/
    float calculateArea()
    {
        return Rect::calculateArea();
    }

};

class Circle:private GeoShape
{
  public:
      Circle(float r):GeoShape(r)
      {  }

      void setRadius(float r)
      { dim1 = dim2 = r; }

      float getRadius()
      { return dim1; }

      /** overriding **/
      float calculateArea()
      {
        return 22.0/7 * dim1 * dim2;
      }

};


int main()
{

    Triangle t(20 , 10);
    Rect r(2 ,5);
    Square s(4);
    Circle c(5);

    cout<<"\nthe area of Triangle = "<<t.calculateArea();
    cout<<"\nthe area of Rect = "<<r.calculateArea();
    cout<<"\nthe area of Square = "<<s.calculateArea();
    cout<<"\nthe area of Circle = "<<c.calculateArea();


    return 0;
}
