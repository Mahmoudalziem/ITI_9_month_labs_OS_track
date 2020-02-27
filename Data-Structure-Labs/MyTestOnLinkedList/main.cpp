#include <iostream>

using namespace std;

class Emp
{
    string name;
    int id;

public:

    Emp* pPrev;
    Emp* pNext;

    Emp();
    Emp(string n , int i);

    void setId(int i);
    int getId();
    string getName();
    void enterData();
    void getEmp();
};

class LinkedList
{
protected:
    Emp* pStart;
    Emp* pEnd;

public:
    LinkedList();
    ~LinkedList();

    void addList(Emp* pItem);
    Emp* search_LinkedList(int id);
    void deleteNode(int id);
    void displayAll();
    void insertion(Emp* pItem);
    void freeList();

};
///implementation of Employee class

Emp::Emp()
{
  name = "none";   id =0;
  pNext = pPrev = NULL;
}

Emp::Emp(string n , int i)
{
  name = n; id = i;
  pNext = pPrev = NULL;
}

void Emp::setId(int i)
{
    id = i;
}

int Emp::getId()
{
    return id;
}
string Emp::getName()
{
    return name;
}
void Emp::enterData()
{

        cin>>name;
        cin>>id;

}

void Emp::getEmp()
{
    cout<<getName()<<"   "<<getId()<<endl;
}
///implementation of LinkedList class

LinkedList::LinkedList()
{
    pStart = pEnd = NULL;
}
LinkedList::~LinkedList()
{
    //freeList();
}

void LinkedList::addList(Emp* pItem)
{
    if(!pStart)
    {
        pItem->pNext = NULL;
        pItem->pPrev = NULL;
        pStart = pEnd = pItem;
    }
    else
    {
        pEnd->pNext = pItem;
        pItem->pPrev = pEnd;
        pItem->pNext= NULL;
        pEnd = pItem;
    }
}

Emp* LinkedList::search_LinkedList(int id)
{
    Emp* temp;
    temp = pStart;

    while(temp && temp->getId() != id)
    {
        temp = temp->pNext;
    }
    return temp;
}


void LinkedList::deleteNode(int id)
{
   Emp* temp = search_LinkedList(id);
   if(!temp)     //not found this id
   {
       cout<<"\n\nthe node you want to delete isn't exist\n";
   }
   else
       {
        if(temp == pStart)
       {
           pStart = pStart->pNext;
           pStart->pPrev = NULL;
           temp->pNext = NULL;
       }
        else if(temp == pEnd)
       {
           pEnd = pEnd->pPrev;
           pEnd->pNext= NULL;
           temp->pPrev = NULL;
       }
       else
       {
         temp->pPrev->pNext = temp->pNext;
         temp->pNext->pPrev = temp->pPrev;
         temp->pNext = temp->pPrev = NULL;
       }
    delete temp;
    }
}
void LinkedList::displayAll()
{

    Emp* pItem;
    pItem = pStart;
    while(pStart && pItem)
    {
        pItem->getEmp();
        pItem = pItem->pNext;
    }
}
void LinkedList::freeList()
{
    Emp* temp;
    while(!pStart)
    {
        temp = pStart;
        pStart = pStart->pNext;
        delete temp;
    }
    pEnd = NULL;
}
void LinkedList::insertion(Emp* pNode)
{
    Emp* pItem;
    if(!pStart)
        addList(pNode);
    else
    {
        pItem = pStart;
        while(pNode->getId() > pItem->getId() && pItem !=NULL)
        {
            pItem = pItem->pNext;
        }

        if(!pItem)
          addList(pNode);

        else if(pItem == pStart)
        {
            pNode->pNext = pStart;
            pStart->pPrev = pNode;
            pNode->pPrev = NULL;
            pStart = pNode;
        }

        else
        {

            pNode->pPrev = pItem->pPrev;
            pItem->pPrev->pNext = pNode;
            pItem->pPrev = pNode;
            pNode->pNext = pItem;

        }

    }

}


int main()
{
    int sizee, i ,id;
    LinkedList LD;

    cout<<"Enter the number of employees: ";
    cin>>sizee;
    Emp *e = new Emp[sizee];
    Emp* e1;
    Emp e2("ali" , 23);

    cout<<"write the name and id of each employee: \n";

    for(i = 0 ; i < sizee ; i++)
    {
        e[i].enterData();
        LD.addList(&e[i]);
    }

    cout<<"\nNodes of LinkedList are: \n";
    LD.displayAll();

    ///searching
    cout<<"\nEnter the id of Emp that you want to search: ";
    cin>>id;

    e1 = LD.search_LinkedList(id);
    if(e1)
    cout<<"the employee is found in : "<<e1<<endl;
    else
        cout<<"Not Found\n";


    cout<<"Enter the id of employee you want to delete : ";
    cin>>id;
    LD.deleteNode(id);
    cout<<"\n\nNodes of LinkedList are: \n";
    LD.displayAll();


    LD.insertion(&e2);
    cout<<"Display the list after insertion :\n";
    LD.displayAll();

    return 0;
}
