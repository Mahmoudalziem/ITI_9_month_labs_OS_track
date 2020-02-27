#include <iostream>
using namespace std;

class Employee
{
    string name;
    int id;
public:
    Employee *pRight;
    Employee *pLeft;
    Employee(){ }
    Employee(int i){ id = i;}
    int getId(){return id;}

};
class BinaryTree
{
    Employee *pParent;
    Employee *insertion(Employee *pRoot , Employee *data);
    void inOrder(Employee *pRoot);
    void preOrder(Employee *pRoot);
    void postOrder(Employee *pRoot);
    int getHight(Employee *pRoot);
    Employee* deletee(Employee *pRoot,int id);
   public:
     BinaryTree(){pParent = NULL;}
     void insertNode(Employee *data);
     Employee* searching(int id);
     void inOrderTraverse();
     void preOrderTraverse();
     void postOrderTraverse();
     int getTreeHight();
     void deleteNode(int id);

};
//public insertion
 void BinaryTree::insertNode(Employee *data)
 {
    pParent = insertion(pParent , data);
 }
//private insertion
Employee* BinaryTree::insertion(Employee *pRoot , Employee *data)
{
    if(pRoot == NULL)
    {
      data->pRight = NULL;
       data->pLeft = NULL;
       return (data);
    }
    else
    {
      if(data->getId()< pRoot->getId())
          {
            pRoot->pLeft = insertion(pRoot->pLeft , data);
          }
      else
          {
            pRoot->pRight = insertion(pRoot->pRight , data);
          }
      return (pRoot);
    }

}
///search in tree
Employee* BinaryTree::searching(int id)
{
    Employee *pRoot;
    pRoot = pParent;

    while(pRoot && id != pRoot->getId())
    {
        if(id < pRoot->getId())
            pRoot = pRoot->pLeft;
        else
            pRoot = pRoot->pRight;
    }
    return pRoot;

}
///public
void BinaryTree::inOrderTraverse()
{
    inOrder(pParent);
}
void BinaryTree::preOrderTraverse()
{
    preOrder(pParent);
}
void BinaryTree::postOrderTraverse()
{
    postOrder(pParent);
}
///private
void BinaryTree::inOrder(Employee *pRoot)
{
    if(pRoot)
    {
        inOrder(pRoot->pLeft);
        cout<<"id : "<<pRoot->getId()<<endl;
        inOrder(pRoot->pRight);
    }
}
void BinaryTree::preOrder(Employee *pRoot)

{
    if(pRoot)
    {
        cout<<"id : "<<pRoot->getId()<<endl;
        inOrder(pRoot->pLeft);
        inOrder(pRoot->pRight);
    }
}
void BinaryTree::postOrder(Employee *pRoot)
{
    if(pRoot)
    {
        inOrder(pRoot->pLeft);
        inOrder(pRoot->pRight);
        cout<<"id : "<<pRoot->getId()<<endl;
    }
}

///hight
int BinaryTree::getTreeHight()
{
    return getHight(pParent);
}
 int BinaryTree::getHight(Employee *pRoot)
 {
     if(pRoot == NULL)
        return 0;
     else
     {
       int x = getHight(pRoot->pLeft);
       int y = getHight(pRoot->pRight);

       if(x > y)
        return x+1;
       else
        return y+1;
     }
 }
 ///Delete
void BinaryTree::deleteNode(int id)
{

    pParent = deletee(pParent , id);
}
 Employee* BinaryTree::deletee(Employee *pRoot,int id)
 {
     Employee *p , *p2;

     if(!pRoot)
        return pRoot;

     if(pRoot->getId() == id)
     {

         if(pRoot->pLeft == pRoot->pRight)
         {
             delete pRoot;
             return NULL;
         }
         else if(pRoot->pLeft == NULL)
         {
             p = pRoot->pRight;
             delete pRoot;
             return p;
         }
        else if(pRoot->pRight == NULL)
         {
             p = pRoot->pLeft;
             delete pRoot;
             return p;
         }
         else
         {
             p2 = pRoot->pRight;
             p = pRoot->pRight;

             while(p->pLeft)
                p = p->pLeft;

             p->pLeft = pRoot->pLeft;
             delete pRoot;
             return p2;
         }
     }

     if(pRoot->getId() < id)
        pRoot->pRight = deletee(pRoot->pRight , id);
     else
        pRoot->pLeft = deletee(pRoot->pLeft , id);


     return pRoot;
 }

int main()
{
    int hight;
    Employee* x;
    Employee e1;
    BinaryTree t;
    Employee e2(4);
    Employee e3(3);
    Employee e4(8);

    t.insertNode(&e2);
    t.insertNode(&e3);
    t.insertNode(&e4);
    cout<<"inOrder:\n";
    t.inOrderTraverse();
    cout<<"preOrder:\n";
    t.preOrderTraverse();
    cout<<"postOrder:\n";
    t.postOrderTraverse();

    cout<<"searching : \n";
    x = t.searching(8);
    if(x == NULL)
        cout<<"Not found\n";
    else
        cout<<"found: \n"<<"id : "<<x->getId()<<endl;

    hight = t.getTreeHight();
    cout<<"Hight of tree : "<<hight<<endl;

     cout<<"delete node 4: \n";
    t.deleteNode(4);
    t.postOrderTraverse();

    return 0;
}
