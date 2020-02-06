#include <iostream>
//#include <graphics.h>
#include "graphics.h"
#include <unistd.h>

using namespace std;

class Shape
{
    int color;

public:
    Shape()
    {

    }
    void setCol(int n)
    {
        color = n;
    }
    int getCol()
    {
        return color;
    }

};

class Point
{
   int x;
   int y;

   public:

    Point()
        {
            x = 0;
            y = 0;
        }
    Point(int m , int n)
        {
            x = m;
            y = n;
        }
    void setX(int m)
        {
            x = m;
        }
    void setY(int n)
        {
            y = n;
        }
    int getX()
        {
            return x;
        }
    int getY()
        {
            return y;
        }


};

 /**< class Line */
class Line:public Shape
{
    Point start;
    Point endd;

public:

    Line(): start() , endd()
         { cout<<"At line constructor"; }
    Line(int x1 , int y1 , int x2 , int y2 , int n): start(x1 , y1) , endd(x2 , y2)
        {
             setCol(n);
             cout<<"At line constructor";
        }
    void draw()
        {
            setcolor(getCol());
            line(start.getX() , start.getY() , endd.getX() , endd.getY());
        }


};

/**<  class Rectangle */
class Rect:public Shape
{
    Point ul;
    Point lr;

public:
    Rect(): ul() , lr()
    {
        cout<<"At rectangle constructor";
    }
      Rect(int x1 , int y1 , int x2 , int y2 , int n): ul(x1 , y1) , lr(x2 , y2)
    {
        setCol(n);
        cout<<"At rectangle constructor";
    }
    void draw()
    {
        setcolor(getCol());
        rectangle(ul.getX() , ul .getY() , lr.getX() , lr.getY());
    }

};

/**<  class Circle */
class Circle:public Shape
{
    Point center;
    int radius;

public:
    Circle(): center()
        {
            radius = 0;
            cout<<"At Circle constructor";
        }
    Circle(int x , int y , int r , int n): center(x , y)
        {
            radius = r;
            setCol(n);
            cout<<"At Circle constructor";
        }
    void draw()
        {
           setcolor(getCol());
           circle(center.getX(), center.getY() , radius);
           setfillstyle(SOLID_FILL, getCol());
           floodfill(center.getX(), center.getY(),getCol());
        }
};

/**  class Picture **/
class Picture
{
   int lNum , rNum , cNum;  /** # lines or circles or rectangles we want to draw **/
   Line *pLine;
   Rect *pRect;
   Circle *pCircle;

   public:

       Picture()
           {
                lNum = 0;
                rNum = 0;
                cNum = 0;
                pLine = NULL;
                pRect = NULL;
                pCircle = NULL;
           }
       Picture(int ln , int rn , int cn , Line *pL , Rect *pR , Circle *pC)
           {
                lNum = ln;
                rNum = rn;
                cNum = cn;
                pLine = pL;
                pRect = pR;
                pCircle = pC;
           }
       void setLines( int ln, Line *pL)
           {
                lNum = ln;
                pLine = pL;
           }
       void setRects( int rn, Rect *pR)
           {
                rNum = rn;
                pRect = pR;
           }
       void setCircles( int cn ,Circle *pC)
           {
                cNum = cn;
                pCircle = pC;
           }
       //drawing picture method
       void paint()
        {
            int i;
            for(i = 0 ; i < lNum ; i++)
                pLine[i].draw();

            for(i = 0 ; i < rNum; i++)
                pRect[i].draw();

            for(i = 0 ; i < cNum ; i++)
                pCircle[i].draw();

        }
};


int main()
{
      int gd=DETECT,gm,x,y,length,angle;
	initgraph(&gd, &gm, "");

 initwindow(900, 900);

    Picture myPic;

    Line lArr[4] = {Line(458 , 132 , 458 , 164 , 3), Line(438 , 148 ,479 , 148 , 3) ,Line(581 , 132 , 581 , 166 , 3) ,Line(560 , 149 , 603 , 149 , 3)};
    Rect rArr[4] = {Rect(375 , 107 , 660 , 257 , 3) , Rect(438 , 132 , 480 , 164 , 3) , Rect(561 , 132 , 603 , 166 ,3), Rect(662 , 218 , 686 , 248 ,7)};
    Circle cArr[2] ={Circle(604 , 273 ,17 , 3), Circle(470 , 276 ,18 , 3)};

    myPic.setLines(4 , lArr);
    myPic.setRects(4 , rArr);
    myPic.setCircles(2 , cArr);

    myPic.paint();

    for(int i = 0 ; i <= 500 ; i += 5)
    {
        cleardevice();

        Line lArr[4] = {Line(458 + i , 132 , 458 + i , 164, 3), Line(438 + i, 148 ,479 + i, 148 , 3) ,Line(581+i , 132 , 581+i , 166 , 3) ,Line(560+i , 149 , 603+i , 149 , 3)};
        Rect rArr[4] = {Rect(375+i , 107 , 660+i , 257 , 3) , Rect(438+i , 132 , 480+i , 164 ,3) , Rect(561+i , 132 , 603+i , 166 ,3), Rect(662+i , 218 , 686 +i, 248 ,7)};
        Circle cArr[2] ={Circle(604+i , 273 ,17 , 3), Circle(470+i , 276 ,18 , 3)};

        myPic.setLines(4 , lArr);
        myPic.setRects(4 , rArr);
        myPic.setCircles(2 , cArr);

        myPic.paint();


        delay(200);
    }



/**

initwindow(500 , 700);
circle(406, 202 ,100);
rectangle(50 , 200 , 300 , 188);
line(80, 50 , 100, 90);**/

    getch();
    return 0;
}
