#include <iostream>

using namespace std;

class Adt
{

public:
    int *arr;
    int s;

    Adt(int n);
    ~Adt();
    void enterData();
    void Displaying();
    void selectionSort();
    void bubbleSort();
    void insertionSort();
    int sequentialSearch(int key);
    int binarySearch(int key);

};

///implementation
Adt::Adt(int n)
    {
        s = n;
        arr=new int[s];
    }
Adt::~Adt()
    {
      delete[] arr;
    }
void Adt::enterData()
{
    int i;
    cout<<"enter the elements of array:\n";
    for(i=0 ; i<s ; i++)
    {
        cin>>arr[i];
    }
}

void Adt::Displaying()
{
    int i;
    for(i=0 ; i<s ; i++)
    {
       cout<<arr[i]<<" ";
    }

     cout<<endl;
}

void Adt::selectionSort()
{
    int i , j , mini;
    for( i=0 ; i<(s-1) ; i++)
    {
       mini = i;
       for(j = (i+1) ; j < s ; j++)
           {
               if(arr[mini] > arr[j])
                mini = j;

           }

       if(i != mini)
        swap( arr[i] , arr[mini]);

    }
}

void Adt::bubbleSort()
{
    int i = 1 , j, swapped = 0;

        do
        {
            swapped = 0;

            for(j = 0 ; j < (s - i) ; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap( arr[j] , arr[j+1] );
                    swapped = 1;
                }

            }
            i = i + 1;
        }while(swapped == 1 && i < s);
}

void Adt::insertionSort()
{
    int i , j , value;

    for(i = 1 ; i< s ; i++)
    {
        value = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > value)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
         arr[j+1] = value;
    }

}

int Adt::sequentialSearch(int key)
{
    int i = 0 , found = 0;
    while(!found && i<s)
    {
        if(arr[i] == key)
            found = 1;
        else
            i++;
    }
    if(found)
        return i;
    return -1;

}

int Adt::binarySearch(int key)
{
    int low = 0 , high = s , mid , found = 0;

    while(!found && low <= high)
    {
        mid = (low + high)/ 2;

        if(key > arr[mid])
            low = mid + 1;
        else if(key < arr[mid])
            high = mid - 1;
        else
            found = 1;
    }

    if(!found)
        return -1;
    else
        return 1;

}

int main()
{
    int num, x;
    Adt t(4);

    t.enterData();
    cout<<"Array before sorting:\n";
    t.Displaying();

  /*  t.selectionSort();
    cout<<"After selection sort algorithm:\n";
    t.Displaying();

    t.bubbleSort();
    cout<<"After Bubble sort algorithm:\n";
    t.Displaying();
*/
    t.insertionSort();
    cout<<"After insertion sort algorithm:\n";
    t.Displaying();


    cout<<"Enter the search number: ";
    cin>>num;
     ///x = t.sequentialSort(num);

     x = t.binarySearch(num);
    if(x != -1)
        cout<<"the number is found in : "<< x<< endl;

    else
        cout<<"Not found\n";


    return 0;
}
