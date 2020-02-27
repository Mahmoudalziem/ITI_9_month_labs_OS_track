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

     virtual float calculateArea()
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
    Rect():GeoShape(){}
    Rect(float x , float y):GeoShape(x,y)
    { }
    /** overriding **/
    virtual float calculateArea()
    {
        return dim1 * dim2;
    }

};

class Square:public Rect
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
        return dim1*dim2;
    }

};

class Circle:public GeoShape
{
  public:
      Circle(float r):GeoShape(r)
      { }

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


//standalone function

float sumArea(GeoShape *p1 , GeoShape *p2 ,GeoShape *p3);
int main()
{

    //GeoShape *p;

    Triangle t(20 , 10);
    Rect r(2 ,5);
   // Square s(60);
    Circle c(5);



    cout<<"sum of all Areas = "<<sumArea(&t , &r ,&c);


    return 0;
}

float sumArea(GeoShape *p1 , GeoShape *p2 ,GeoShape *p3)
{
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}
