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
    Employee* pop();

};
///stack

class Stack:private LinkedList
    {

      public:
        Stack( ):LinkedList()
            { }
        ~Stack()
            {  }

        void push(Employee *e)
            {
               addList(e);
            }
        int deleteStack(int id)
        {
            return deleteList(id);
        }
        void freeStack()
        {
            freeList();
        }
        void displayAll()
        {
            LinkedList::displayAll();
        }

        Employee* searchStack(int id)
        {
            return searchEmp(id);
        }
        Employee* pop()
        {
            return LinkedList::pop();
        }

    };

LinkedList::LinkedList()
{
    pStart = pEnd = NULL;
}
LinkedList::~LinkedList()
{
   freeList();
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
Employee* LinkedList::pop()
{
            Employee *pNode;
            pNode = pEnd;
            if(pEnd){
                       if(pStart == pEnd)
                       {
                           pStart = pEnd =NULL;
                       }
                       else
                       {
                           pEnd = pEnd->pPrevious;
                           pEnd->pNext = NULL;
                       }
                     }
                     return pNode;
}
class Queue :private LinkedList
{
public:
    Queue():LinkedList()
    {

    }
    ~Queue()
    {

    }
    void enque(Employee *e)
    {
        addList(e);
    }
    Employee *dequ()
    {
     Employee *pNode;
     pNode=pStart;
     if(pStart)
     {
         if(pStart==pEnd)
         {
             pStart=pEnd;
         }
         else
         {
             pStart=pStart->pNext;
             pStart->pPrevious=NULL;
         }
     }
     return pNode;
    }
   /*  Employee *searchQueue(int id)
     {
         return searchList(id);
     }
     */
     int DeleteQueue(int id)
     {
         return deleteList(id);
     }
     void freeQueue()
     {
         freeList();
     }
     void displayAll()
     {
         LinkedList::displayAll();
     }

};

int main()
{
    Stack s;
    Queue q;
    Employee e1("ali" , 23);
    Employee e2("mohamed" , 24);
    Employee e3("salma" , 25);
    Employee e4("ahmed" , 30);

    s.push(&e1);
    s.push(&e2);
    s.push(&e3);
    s.push(&e4);
    s.displayAll();
    cout<<endl;
    s.pop();
    s.displayAll();

    cout<<"================"<<endl;
    q.enque(&e1);
    q.enque(&e2);
    q.enque(&e3);
    q.enque(&e4);

    q.displayAll();
    cout<<endl;
    q.dequ();
    q.dequ();
    q.displayAll();

    return 0;
}
