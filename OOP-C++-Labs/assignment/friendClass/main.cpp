#include <iostream>
using namespace std;
class Rectangle
	{
		int L,B;

		public:
		Rectangle();

		friend class Square;        //Statement 1
	};
Rectangle::Rectangle()
    {
        L=10;
        B=20;
    }

class Square
	{
		int S;

		public:
		Square();

		void Display(Rectangle Rect);
	};

Square::Square()
    {
			S=5;
    }
void Square::Display(Rectangle Rect)
		{
			cout<<"\n\n\tLength : "<<Rect.L;
			cout<<"\n\n\tBreadth : "<<Rect.B;
			cout<<"\n\n\tSide : "<<S;
		}

int main()
	{

		Rectangle R;
		Square S;

		S.Display(R);       //Statement 2
		return 0;

	}
