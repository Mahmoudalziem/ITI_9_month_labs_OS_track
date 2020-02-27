#include <iostream>

using namespace std;

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
    ~LinkedList();
    void addList(Employee *pEmp);
    Employee* searchEmp(int key);
    void displayAll();
    int deleteList(int key);
    void freeList();
    void insertion(Employee *pNode);
};

LinkedList::LinkedList()
{
    pStart = pEnd = NULL;
}
LinkedList::~LinkedList()
{
   // freeList();
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

Employee* LinkedList::searchEmp(int key)
{
    Employee *pItem;
    pItem = pStart;
    while(pItem != NULL && pItem->getId()!= key)
    {
        pItem = pItem->pNext;
    }
    return pItem;
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
int LinkedList::deleteList(int key)
{
    Employee *pItem;
    int flag = 1;
    pItem = searchEmp(key);

    if(!pItem)
        flag = 0;
    else{
            if(pItem == pStart)
            {
              pStart = pStart->pNext;
              pStart->pPrevious = NULL;
              pItem ->pNext = NULL;
            }
            else if(pItem == pEnd)
            {
              pEnd = pEnd->pPrevious;
              pEnd->pNext = NULL;
             // PItem->pPrevious =NULL;
            }
            else
            {
                pItem->pPrevious->pNext=pItem->pNext;
                pItem->pNext->pPrevious= pItem->pPrevious;
                pItem->pNext=NULL;
                pItem->pPrevious=NULL;
            }
            delete pItem;
    }

    return flag;
}

void LinkedList::freeList()
{

    Employee *pItem;
    while(pStart)
    {
      pItem = pStart;
      pStart = pStart->pNext;
      delete pItem;
    }
    pEnd = NULL; ///ask

}
void LinkedList::insertion(Employee *pNode)
{

    Employee *pItem;
    if(pStart == NULL)
        addList(pNode);
    else
    {
        pItem = pStart;
        while(pItem && pNode->getId()> pItem->getId())
           pItem=pItem->pNext;

       if(!pItem)
         addList(pNode);

        else if(pItem == pStart)
        {
            pNode->pNext = pStart;
            pNode->pPrevious=NULL;
            pStart->pPrevious = pNode;
            pStart = pNode;
        }
        else
        {
            pNode->pNext=pItem;
            pNode->pPrevious = pItem->pPrevious;
            pItem->pPrevious->pNext = pNode;
            pItem->pPrevious=pNode;

        }

    }
}

int main()
{
    int i;
    LinkedList LD;
    Employee *e=new Employee[2];
    Employee e1("ALI" , 35);

    for(i = 0 ; i < 2 ; i++)
    {
        e[i].getEmp();
        LD.addList(&e[i]);
    }
    LD.displayAll();
    cout<<"flag : "<<LD.deleteList(5)<<endl;

    LD.insertion(&e1);
    LD.displayAll();


    return 0;
}
