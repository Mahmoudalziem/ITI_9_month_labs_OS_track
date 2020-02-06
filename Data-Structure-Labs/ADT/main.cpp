#include <iostream>

using namespace std;
void swapFn(int &x,int &y);
class Adt
{

public:
    int *arr;
    int sizee;


    Adt(int sizee=6) {}
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
    void enterData(int* ar , int sizee)
    {
        cout<<"enter the elements of array\n";
        for(int i = 0 ; i<sizee ; i++)
        {
            cin>>ar[i];
        }

    }
    void printData(int* ar , int sizee)
    {
        for(int i=0 ; i<sizee ; i++)
            cout<<ar[i]<<" ";
    }
    void selectionSort(int *a ,int n)
    {
        int i , j , mini;
        for(i = 0; i<n ; i++)
        {
            mini = i;
            for(j = (i+1) ; j< n ; j++)
            {
                if(a[mini] > a[j])
                {
                    mini = j;
                }
            }
            if(i != mini)
                swapFn(a[i],a[mini]);
        }

    }
    void bubbleSort(int*a, int n)
    {

        int swapped;
        int i, j;

        for (i= 1; i< n; i++)
        {
            swapped = 0;
            for(j = 0; j < n-i; j++)
            {
                if(a[j] > a[j+1])
                {
                    swapFn(a[j],a[j+1]);
                    swapped = 1;
                }
            }
            if(swapped == 0) break;
        }
    }
    void insertionSort(int *a , int n)
    {
        int i ,j;
        for(i = 1 ; i< n ; i++)
        {
            int val = a[i];
            j = i - 1;
            while(j>=0 && a[j]> val)
            {
                a[j+1] = a[j];

                j = j - 1;
            }
            a[j+1] = val;

        }
    }

    int sequentialSearch(int *a,int n,int num)
    {

        int i = 0 , found = 0;
        while( (!found)&&(i< n))
        {
            if(a[i] == num)
                found = 1;
            i++;

        }
        if(found == 1) return i-1;
        else return -1;

    }
    int binarySearch(int *a,int n,int num)
    {
        int found=0;
        int low = 0 , high = n , mid;

        while((!found) && low <= high)
        {
            mid =(low + high)/2;
            if(num < a[mid])
                high = mid -1;
            else if (num < a[mid])
                low = mid + 1;
            else
                found = 1;
        }

        if(found == 1) return mid+1;
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

    int a[6]= {0};


    sorting.enterData(a , 6);
    cout<<"selection sort:\n";
    sorting.selectionSort(a , 6);
    sorting.printData(a , 6);
    cout<<endl;
    /*
         sorting.enterData(a , 6);
        cout<<"\nbubble sort:\n";
        sorting.bubbleSort(a , 6);
        sorting.printData(a , 6);
        cout<<endl;

        sorting.enterData(a , 6);
        cout<<"\ninsertion sort:\n";
        sorting.insertionSort(a , 6);
        sorting.printData(a , 6);

    */
    ///search//
    cout<<"Enter the search number : ";
    cin>>num;
    /// x = sorting.sequentialSearch(a,6,num);
    x = sorting.binarySearch(a,6,num);
    if(x != -1)
        cout<<"the number is founded in : "<<x<<endl;
    else
        cout<<"not found\n";

    return 0;
}
