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

     virtual float calculateArea() = 0;

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
   float calculateArea()
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
        return Rect::calculateArea();
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

float sumArea(GeoShape **ptr ,int sizee)
{   int sum = 0;
    for(int i=0 ; i < sizee ; i++)
    {
        sum += ptr[i]->calculateArea();

    }
    return sum;
}


int main()
{
    int i;

    GeoShape **p = new GeoShape*[3];

    Circle c(5);




    for(i =0 ; i<3 ; i++)
    {
        p[i] = &c;
    }

     cout<<"the sum of areas of Circles = ";
     cout<<sumArea(p ,3);

    return 0;
}

