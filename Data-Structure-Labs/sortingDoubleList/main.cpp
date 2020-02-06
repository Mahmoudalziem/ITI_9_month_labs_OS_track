#include <iostream>

using namespace std;

void swapFn(int& x,int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
class Employee
{
    string name;
    int id;
public:
    Employee* pNext;
    Employee* pPrevious;
    Employee()
    {name="no name"; id = 0;}
    Employee(string n , int i)
    {name = n; id = i; pNext = pPrevious = NULL;}

    ///getter & setter
    void setName(string n)
    {
        name = n;
    }
    void setId(int i)
    {
        id = i;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    void getEmp()
    {
        cout<<"Enter the name and id : ";
        cin>>name;
        cin>>id;
    }
    void printEmployee()
    {
        cout<<"Name : "<< name <<"  id: "<< id <<endl;
    }
};

class LinkedList
{
protected:
    Employee* pStart;
    Employee* pEnd;
public:
    LinkedList();
    void addList(Employee *pEmp);
    void displayAll();
    void sorting(Employee *e);

};

LinkedList::LinkedList()
{
    pStart = pEnd = NULL;
}

void LinkedList::addList(Employee *pEmp)
{
    if( pStart==NULL)
    {
         pEmp->pNext = NULL;
         pEmp->pPrevious = NULL;
         pStart = pEnd = pEmp;
    }
    else
    {
         pEnd->pNext = pEmp;
         pEmp->pPrevious = pEnd;
         pEnd = pEmp;
    }
}



void LinkedList::displayAll()
{
    Employee *pItem;
    pItem = pStart;
    while(pItem)
    {
        pItem->printEmployee();
        pItem = pItem->pNext;
    }
}


void LinkedList::sorting(Employee *e)
{
    Employee *p;
    p = pStart;
    int flag = 0;
    do{
        flag = 0;
        while(p != NULL && p->pNext != NULL)
        {
            if(p->getId() > p->pNext->getId())
            {
                swapFn((p->getId()) , (p->pNext->getId()));
                flag = 1;
            }
            p = p->pNext;
        }

    }while(flag == 1);
}

int main()
{
    int i;
    LinkedList LD;
    Employee *e=new Employee[2];
    //Employee e1("ALI" , 35);

    for(i = 0 ; i < 2 ; i++)
    {
        e[i].getEmp();
        LD.addList(&e[i]);
    }
    LD.displayAll();

    LD.sorting(e);
    LD.displayAll();


    return 0;
}





