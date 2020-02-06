#include <iostream>
#include <graphics.h>
using namespace std;

class Point
{
    int x;
    int y;

  public:
      Point();
      Point(int m , int n);

      void setX(int m);
      void setY(int n);

      int getX();
      int getY();

};
class Line
{
    Point start;
    Point endd;

   public:
       /*
       Line(): start(),endd();
       Line(int x1 , int y1 , int x2 , int y2) : start(x1 , y1) , endd(x2 , y2);
       void draw();
        */
       Line(): start(),endd()
        {
            cout<<"At line Const.";
        }

        Line(int x1 , int y1 , int x2 , int y2) : start(x1 , y1) , endd(x2 , y2)
        {
            cout<<"At line Const .";
        }

        void draw()
        {
            line(start.getX() , start.getY() , endd.getX() , endd.getY());
        }

};

class Rec
{
    Point ul;
    Point lr;

   public:
    Rec(): ul(), lr()
    {
        cout<<"At Rec Const.";
    }

    Rec(int x1 , int y1 , int x2 , int y2) : ul(x1 , y1) , lr(x2 , y2)
    {
        cout<<"At Rec Const .";
    }




    void draw()
    {
        rectangle(ul.getX() , ul.getY() , lr.getX() , lr.getY());
    }

};

class Circle
{
    Point center;
    int radius;

  public:
    Circle() : center()
    {
        radius = 0 ;
        cout<<"At Circle Const.";
    }
    Circle(int m , int n , int r) : center(m , n)
    {

        radius = r ;
        cout<<"At Circle Const.";
    }
    void draw()
        {
            circle(center.getX() , center.getY() , radius);
        }


};


class Picture
{
    int cNum;
    int rNum;
    int lNum;

    Circle *pCircles;
    Rec *pRects;
    Line *pLines;

 public:
     Picture()
         {

             cNum = 0;
             rNum = 0;
             lNum = 0;
             pCircles = NULL;
             pRects = NULL;
             pLines = NULL;
         }
     Picture(int cn , int rn , int ln , Circle *pC , Rec *pR , Line *pL)
         {
             cNum = cn;
             rNum = rn;
             lNum = ln;
             pCircles = pC;
             pRects = pR;
             pLines = pL;

         }
     void setLines(int ln ,Line *pL)
     {
         lNum = ln;
         pLines = pL;
     }
     void setCircles(int cn , Circle *pC)
     {
         cNum = cn;
         pCircles = pC;
     }
     void setRects(int rn , Rec *pR)
     {
         rNum = rn;
         pRects = pR;

     }
     void paint()
         {
             int i;
             for(i = 0 ; i < cNum ; i++)
             {
                 pCircles[i].draw();
             }
             for(i = 0 ; i < rNum ; i++)
             {
                 pRects[i].draw();
             }
             for(i = 0 ; i < lNum ; i++)
             {
                 pLines[i].draw();
             }

         }

};

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int m , int n)
{
    x = m;
    y = n;
}

void Point::setX(int m)
{
    x = m;
}

void Point::setY(int n)
{
    y = n;
}
 int Point::getX()
 {
     return x;
 }

int Point::getY()
 {
     return y;
 }

//line
/*
Line::Line(): start(),endd()
{
    cout<<"At line Const.";
}

Line::Line(int x1 , int y1 , int x2 , int y2) : start(x1 , y1) , endd(x2 , y2)
{
    cout<<"At line Const .";
}

void Line::draw()
{
    line(start.getX() , start.getY() , endd.getX() , endd.getY());
}
*/








int main()
{
    int gd=DETECT,gm,x,y,length,angle;
	initgraph(&gd, &gm, "");

	Picture myPic;

	Circle cArr[1] = { Circle(406, 202 ,100)};
	Rec rArr[1] = {Rec(50 , 200 , 300 , 188)};
    Line  lArr[1] = {Line(420 , 50 , 300 , 300)};

     myPic.setCircles(1 , cArr);
     myPic.setRects(1 , rArr);
     myPic.setLines(1 , lArr);
     myPic.paint();
/*
initwindow(500 , 700);
line(80, 50 , 100, 90);

*/
    getch();
    return 0;
}
