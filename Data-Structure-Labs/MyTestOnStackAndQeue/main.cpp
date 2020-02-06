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
        cout<< name <<"   "<< id <<endl;
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
    void addList(Employee *pEmp); ///push
    Employee* searchEmp(int key); ///search
    void displayAll();
    int deleteList(int key);
    void freeList();
};

/// class Stack

class Stack : private LinkedList
{
public:
    Stack():LinkedList()
    {  }
    ~Stack(){ }
    ///push
    void pushing(Employee* e)
    {
        addList(e);
    }

    ///pop
    Employee* pop()
    {
        Employee* temp;
        temp = pEnd;
        if(pEnd)
        {
            if(pEnd == pStart)
                pStart = pEnd =NULL;
            else
            {
              pEnd = pEnd->pPrevious;
              pEnd->pNext=NULL;
            }
        }

        return temp;
    }

    ///search
    Employee* searching(int key)
    {
        return searchEmp(key);
        }

    ///deleting element
    int deleteNode(int key)
    {
        return deleteList(key);
    }

    ///free Stack
    void freeStack()
    {
        freeList();
    }

    ///display Stack
    void displayStack()
    {
        displayAll();
    }

};

///class Queue
class Queue:private LinkedList
{
public:
    Queue():LinkedList()
    { }
    ~Queue(){ }

    ///inQueue
    void inqueue(Employee* e)
    {
        addList(e);
    }

    ///dequeue
    Employee* dequeue()
    {
       Employee* temp;
       temp = pEnd;

       if(pStart)
       {
            if(pStart == pEnd)
                pStart = pEnd = NULL;
            else
            {
                pStart = pStart->pNext;
                pStart->pPrevious = NULL;
            }
       }
       return temp;
    }

    ///searching

    Employee* searchQueue(int id)
    {
        return searchEmp(id);
    }

    ///deleteNode

    int deleteQueue(int id)
    {
        return deleteList(id);
    }

    ///free Queue

    void freeQueue()
    {
        freeList();
    }

    ///display the Queue content

    void displayQueue()
    {
        displayAll();
    }

};

///implementation of LinkedList
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


int main()
{

    Stack s;
    Queue q;

    Employee e1("alii" , 23);
    Employee e2("jhon" , 24);
    Employee e3("salma" , 25);
    Employee e4("ahmed" , 30);




    s.pushing(&e1);
    s.pushing(&e2);
    s.pushing(&e3);


    cout<<"the content of stack :\n";
    s.displayStack();
    cout<<endl;

    cout<<"pop() \n";
    s.pop();


    cout<<"the content of stack after pop :\n";
    s.displayStack();

    cout<<"======================================";

    q.inqueue(&e1);
    q.inqueue(&e2);
    q.inqueue(&e3);
    q.inqueue(&e4);

    cout<<"\n\nthe content of Queue :\n";
    q.displayQueue();
    cout<<endl;

    cout<<"dequeue()\ndequeue()\n";
    q.dequeue();
    q.dequeue();
    cout<<"\nthe content of Queue  after dequeue:\n";
    q.displayQueue();



    return 0;
}
