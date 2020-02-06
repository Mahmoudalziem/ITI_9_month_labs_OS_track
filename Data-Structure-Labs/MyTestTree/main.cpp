#include <iostream>

using namespace std;
class Employee
{
    int id;
public:
    Employee* pLeft;
    Employee* pRight;
    Employee(){ id = 0; pLeft = pRight = NULL; }
    Employee(int n){id = n;  pLeft = pRight = NULL;  }
    int getId(){return id;}

};

class Tree
{
    Employee* pParent;
    Employee* insertion(Employee* pRoot , Employee* data);
    void inOrder(Employee *pRoot);
    void preOrder(Employee *pRoot);
    void postOrder(Employee *pRoot);
    int getHeight(Employee* pRoot);

public:
    Tree(){pParent = NULL;}
    void insertNode(Employee* data );
    Employee* searching(int id);

    void inOrderTraverse();
    void preOrderTraverse();
    void postOrderTraverse();
    int getTreeHeight();
};

/// insert implementation

void Tree::insertNode(Employee* data )
{
    pParent = insertion(pParent , data);
}

 Employee* Tree::insertion(Employee* pRoot , Employee* data)
 {
   if(pRoot == NULL)
   {
       data->pLeft = NULL;
       data->pRight = NULL;
       pRoot = data;
       return (data);
   }
   else
   {
       if(pRoot->getId() > data->getId())
       {
           pRoot->pLeft = insertion(pRoot->pLeft , data);
       }
       else
       {
            pRoot->pRight = insertion(pRoot->pRight , data);
       }
       return pRoot;
   }
 }

 /// search implementation

Employee* Tree::searching(int id)
{
    Employee* pRoot;
    pRoot = pParent;

    while(pRoot && pRoot->getId() != id )
        {
            if(pRoot->getId() > id)
            {
              pRoot = pRoot->pLeft;
            }
            else
            {
                 pRoot = pRoot->pRight;
            }
        }

    return pRoot;
}


/// inOrder traversing
 void Tree::inOrderTraverse()
 {
     inOrder(pParent);
 }
void Tree::inOrder(Employee* pRoot)
{
      if(pRoot)
      {
          inOrder(pRoot->pLeft);
          cout<<pRoot->getId()<<endl;
          inOrder(pRoot->pRight);
      }
}

/// preOrder traversing
 void Tree::preOrderTraverse()
 {
     preOrder(pParent);
 }
void Tree::preOrder(Employee* pRoot)
{
      if(pRoot)
      {

          cout<<pRoot->getId()<<endl;
          preOrder(pRoot->pLeft);
          preOrder(pRoot->pRight);
      }
}

/// postOrder traversing
 void Tree::postOrderTraverse()
 {
     postOrder(pParent);
 }
void Tree::postOrder(Employee* pRoot)
{
      if(pRoot)
      {

          postOrder(pRoot->pLeft);
          postOrder(pRoot->pRight);
          cout<<pRoot->getId()<<endl;
      }
}

/// Height of tree
int Tree::getTreeHeight()
{
  return getHeight(pParent);
}
int Tree::getHeight(Employee* pRoot)
{
    if(pRoot == NULL)
        return 0;
    else
        {
            int  x = getHeight(pRoot->pLeft);
            int  y = getHeight(pRoot->pRight);
            if(x > y)
                return x+1;
            else
                return y+1;
        }

}


int main()
{

    return 0;
}
