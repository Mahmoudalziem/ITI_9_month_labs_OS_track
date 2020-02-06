#include <iostream>

using namespace std;
void swapFn(int &x,int &y);

class Employee
{
public:
    string name;
    int id;
    Employee(){ }
    Employee(string n , int i)
    {
        name = n;
        id = i;
    }
};
class Adt
{

public:
    Employee *arr;
    int sizee;


    Adt(int sizee=6) {
    arr=new Employee[sizee];
    }
    /* Adt(int &s)
     {
         sizee = s.sizee;
         arr = new int[sizee];
         for(int i=0;i<sizee;i++)
         {
             arr[i]=s.arr[i];
         }

     }*/
    ~Adt()
    {
        delete[] arr;
    }
    void enterData(Employee* ar , int sizee)
    {
        cout<<"enter the elements of array\n";

        for(int i = 0 ; i<sizee ; i++)
        {
            cin>>ar[i].id;
            cin>>ar[i].name;

        }

    }
    void printData(Employee *ar , int sizee)
    {
        for(int i=0 ; i<sizee ; i++)
            {cout<<ar[i].id<<" ";
            cout<<ar[i].name<<" "<<endl;

            }
    }
    void selectionSort(Employee *a ,int n)
    {
        int i , j , mini;
        for(i = 0; i<n ; i++)
        {
            mini = i;
            for(j = (i+1) ; j< n ; j++)
            {
                if(a[mini].id > a[j].id)
                {
                    mini = j;
                }
            }
            if(i != mini)
                swap(a[i],a[mini]);
        }

    }



    int sequentialSearch(Employee *a,int n,int num)
    {

        int i = 0 , found = 0;
        while( (!found)&&(i< n))
        {
            if(a[i].id == num)
                found = 1;
            i++;

        }
        if(found == 1) return i-1;
        else return -1;

    }

};

void swapFn(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int num , x;
   Adt sorting;

    Employee *e = new Employee[3];


    sorting.enterData(e, 3);
    cout<<"selection sort:\n";
    sorting.selectionSort(e , 3);
    sorting.printData(e , 3);
    cout<<endl;

    ///search//
    cout<<"Enter the search number : ";
    cin>>num;
     x = sorting.sequentialSearch(e,3,num);

    if(x != -1)
        cout<<"the number is founded in : "<<x<<endl;
    else
        cout<<"not found\n";

    return 0;
}

