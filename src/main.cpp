#include <string.h>
#include <iostream>
#include <stack>
#include <list>
#include "fruitHeader.h"

using namespace std;

Fruit* root=NULL;
//------------------------------------Parent tree-------------------------------------------
Fruit ::Fruit(int value)
{
    weight = value;
    leftChild = rightChild= NULL;
}
Fruit ::Fruit()
{
    leftChild = rightChild= NULL;
}

Fruit* Fruit::getLeft()
{
    return this->leftChild;
}
void Fruit::setLeft(Fruit* value)
{
    this->leftChild=value;
}
Fruit* Fruit::getRight()
{
    return rightChild;
}
void Fruit::setRight(Fruit* value)
{
    this->rightChild=value;
}
int Fruit::getWeight()
{
    return weight;
}
void Fruit::setWeight(int w)
{
    this->weight=w;
}
string Fruit::getTaste()
{
    return "I have multiple tastes";
}
string Fruit::getType()
{
    return "Fruit";
}
string Fruit::getSpecific()
{
    return "Fruit";
}
//----------------------------------------subclasses--------------------------------------
string OvalShape::getType()
{
    return "Fruit OvalShape";
}
string OvalShape::getSpecific()
{
    return "OvalShape";
}
string TinyShape::getType()
{
    return "Fruit TinyShape";
}
string TinyShape::getSpecific()
{
    return "TinyShape";
}
//----------------------------------------------fruits kinds
//grape
string Grapes::getType()
{
    return OvalShape::getType()+" "+TinyShape::getType()+" "+"Grape";
}
string Grapes::getSpecific()
{
    return "Grape";
}
string Grapes::getTaste()
{
    return "<I'm sweet and juicy>";
}
//berry
string Berry::getType()
{
    return OvalShape::getType()+" "+TinyShape::getType()+" "+"Berry";
}
string Berry::getSpecific()
{
    return "Berry";
}
string Berry::getTaste()
{
    return "<I'm sour>";
}
//black berry
string BlackBerry::getType()
{
    return Berry::getType()+" "+"BlackBerry";
}
string BlackBerry::getSpecific()
{
    return "BlackBerry";
}
//blue berry
string BlueBerry::getType()
{
    return Berry::getType()+" "+"BlueBerry";
}
string BlueBerry::getSpecific()
{
    return "BlueBerry";
}
//goose berry
string GooseBerry::getType()
{
    return Berry::getType()+" "+"GooseBerry";
}
string GooseBerry::getSpecific()
{
    return "GooseBerry";
}
//eleder berry
string ElderBerry::getType()
{
    return Berry::getType()+" "+"ElderBerry";
}
string ElderBerry::getSpecific()
{
    return "ElderBerry";
}
//strawberry
string Strawberry::getType()
{
    return Berry::getType()+" "+"Strawberry";
}
string Strawberry::getSpecific()
{
    return "Strawberry";
}
string Strawberry::getTaste()
{
    return "<I'm sweet>";
}
//avocado
string Avocado::getType()
{
    return OvalShape::getType()+" "+"Avocado";
}
string Avocado::getSpecific()
{
    return "Avocado";
}

string Avocado::getTaste()
{
    return "<I'm creamy>";
}
//apple
string Apple::getType()
{
    return OvalShape::getType()+" "+"Apple";
}
string Apple::getSpecific()
{
    return "Apple";
}
string Apple::getTaste()
{
    return "<I'm sweet>";
}
//---------------------------------------main functions-------------------------------------
void Tree ::Iterate()
{
    IterateHelper("Fruit");
}
void Tree::filterByType(string type)
{
    IterateHelper(type);
}
// Insert function
Fruit* Tree ::Insert(Fruit* parent,Fruit* node,string type, int value)
{
    if (!node)
    {
        return InsertHelper(type,value);
    }
    // Insert data.
    if (value > node->getWeight())
    {
        node->setRight(Insert(node,node->getRight(),type, value));
    }
    else if(value < node->getWeight())
    {
        node->setLeft(Insert(node,node->getLeft(),type, value));
    }
    else if(value == node->getWeight())
    {
        Fruit* fruit=InsertHelper(type,value);
        fruit->setLeft(node->getLeft());
        fruit->setRight(node->getRight());
        if(parent==NULL)
        {
            root=fruit;
            return root;
        }
        if(parent->getLeft()==node)
        {
            parent->setLeft(fruit);
        }
        else
        {
            parent->setRight(fruit);
        }
        return fruit;
    }
    return node;
}
Fruit* Tree::findHeaviest()
{

    if(root==NULL)
    {
        return NULL ;
    }

    Fruit* currentFruit=root;
    while(currentFruit->getRight()!=NULL)
    {
        currentFruit=currentFruit->getRight();
    }
    return currentFruit;
}
Fruit* Tree::findLightest()
{
    if(root==NULL)
    {
        return NULL;
    }

    Fruit* currentFruit=root;
    while(currentFruit->getLeft()!=NULL)
    {
        currentFruit=currentFruit->getLeft();
    }
    return currentFruit;
}
void Tree::filterByWeight(int weight)
{
    list <Fruit*> weightList;
    if(root==NULL)
    {
        return ;
    }
    stack<Fruit*> stack;
    Fruit* currentFruit=root;
    while (!stack.empty() || currentFruit!=NULL )
    {
        while(currentFruit!=NULL)
        {
            stack.push(currentFruit);
            currentFruit=currentFruit->getRight();
        }
        currentFruit=stack.top();
        if(currentFruit->getWeight()>weight)
        {
            weightList.push_front(currentFruit);
        }
        else
        {
            int size=weightList.size();
            for(int it = 0; it<size; it++)
            {
                Fruit * curr=weightList.front();
                print(curr);
                cout << "next ---> ";
                weightList.pop_front();
            }
            cout<<"done \n";
            return;
        }
        stack.pop();
        currentFruit=currentFruit->getLeft();
    }

}
void Tree:: magnifyByType(string type, int value)
{
    stack<Fruit *> nodes;
    Fruit *currentFruit = root;
    list <Fruit*>  toMagnify;
    while (currentFruit != NULL || nodes.empty() == false)
    {
        while (currentFruit !=  NULL)
        {
            nodes.push(currentFruit);
            currentFruit = currentFruit->getLeft();
        }
        currentFruit = nodes.top();
        if(currentFruit ->getType().find(type)!= string::npos)
        {
            toMagnify.push_back(currentFruit);
        }
        nodes.pop();
        currentFruit = currentFruit->getRight();
    }
    while(! toMagnify.empty())
    {
        Fruit* current= toMagnify.front();
        int newWeight = (current->getWeight()) + value;
        deleteFruit(current ->getWeight());
        Insert(NULL,root,current->getSpecific(),newWeight);
        toMagnify.pop_front();
    }

    Iterate();
}
//*******************************secondary functions
void Tree ::IterateHelper(string type)
{
    if(root==NULL)
    {
        return ;
    }
    stack<Fruit*> stack;
    Fruit* currentFruit=root;
    cout<<"the "<<type<<" : ";
    while (!stack.empty() || currentFruit!=NULL )
    {
        while(currentFruit!=NULL)
        {
            stack.push(currentFruit);
            currentFruit=currentFruit->getLeft();
        }
        currentFruit=stack.top();

        if(currentFruit->getType().find(type)!=string::npos)
        {
            print(currentFruit);
            cout << "next ---> ";
        }
        stack.pop();
        currentFruit=currentFruit->getRight();
    }
    cout<<"done \n";
}


Fruit* Tree::InsertHelper(string type,int value)
{

    if(type.compare("Grape")==0)
    {
        Grapes* grape=new Grapes();
        grape->setWeight(value);
        return  grape;
    }
    else if(type.compare("Berry")==0)
    {
        Berry* berry=new Berry();
        berry->setWeight(value);
        return berry;
    }
    else if(type.compare("BlackBerry")==0)
    {
        BlackBerry* berry=new BlackBerry();
        berry->setWeight(value);
        return berry;
    }
    else if(type.compare("BlueBerry")==0)
    {
        BlueBerry* berry=new BlueBerry();
        berry->setWeight(value);
        return berry;
    }
    else if(type.compare("GooseBerry")==0)
    {
        GooseBerry* berry=new GooseBerry();
        berry->setWeight(value);
        return berry;
    }
    else if(type.compare("ElderBerry")==0)
    {
        ElderBerry* berry=new ElderBerry();
        berry->setWeight(value);
        return berry;
    }
    else if(type.compare("Strawberry")==0)
    {
        Strawberry* berry=new Strawberry();
        berry->setWeight(value);
        return berry;
    }
    else if(type.compare("Avocado")==0)
    {
        Avocado* fruit=new Avocado();
        fruit->setWeight(value);
        return fruit;
    }
    else if(type.compare("Apple")==0)
    {
        Apple* fruit=new Apple();
        fruit->setWeight(value);
        return fruit;
    }
    else if(type.compare("OvalShape")==0)
    {
        OvalShape* shape=new OvalShape();
        shape->setWeight(value);
        return shape;
    }
    else if(type.compare("TinyShape")==0)
    {
        TinyShape* shape=new TinyShape();
        shape->setWeight(value);
        return shape;
    }
    return new Fruit(value);

}
Fruit* Tree::getParent()
{
    return this->parent;
}

void Tree::setParent(Fruit* p)
{
    this->parent=p;
}
Fruit* Tree::findSuccessor(Fruit* node, Fruit* suc,int key)
{

    if (node==NULL)
    {
        return suc;
    }
    if (node->getWeight()==key)
    {
        if (node->getRight()!=NULL)
        {
            Fruit* currentNode = node->getRight();
            while (currentNode->getLeft()!=NULL)
            {
                currentNode = currentNode->getLeft();
            }
            suc = currentNode;
        }
        //parent->setLeft(suc->getRight());
        return suc;
    }
    else if (node->getWeight()>key)
    {
        suc = node;
        return findSuccessor(node->getLeft(), suc,key);
    }
    else
    {
        return findSuccessor(node->getRight(), suc, key);
    }
}

Fruit* Tree::searchForNode(Fruit* parent,Fruit* node, int key)
{

    if (node==NULL)
    {
        return NULL;
    }
    if (node->getWeight()==key)
    {
        setParent(parent);
        return node;
    }
    else if (key>node->getWeight())
    {
        return searchForNode(node,node->getRight(), key);
    }
    else
    {
        return searchForNode(node,node->getLeft(), key);
    }
}
Fruit* Tree::findPredecessor(Fruit* node)
{
        Fruit* pre=new Fruit();
        if (node->getRight()!=NULL)
        {
            Fruit* currentNode = node->getRight();
            while (currentNode->getLeft()!=NULL)
            {
                currentNode = currentNode->getLeft();
            }
            pre = currentNode;
        }
        return pre;      
}
Fruit* Tree::deleteFruit(int key)
{

    //search function
    Fruit* node = searchForNode(new Fruit(),root, key);
    if (node == NULL) return NULL;
    //step1
    if (node->getLeft()==NULL)
    {
        Fruit* parent=getParent();
         Fruit* temp=node->getRight();
        if(node==root)
        {
            root=temp;            
        }
        else if(parent->getLeft()==node)
        {
            parent->setLeft(temp);
        }
        else if(parent->getRight()==node)
        {
            parent->setRight(temp);
        }     
    }
    //step2
    else if (node->getRight()==NULL)
    {
        Fruit* parent=getParent();
        Fruit* temp=node->getLeft();
        if(node==root)
        {        
            root=temp;
        }
        else if(parent->getLeft()==node)
        {
            parent->setLeft(temp);
        }
         else if(parent->getRight()==node)
        {
            parent->setRight(temp);
        }
        
    }
    //step3
    else
    {
        Fruit* point=new Fruit();
        Fruit* newNode = findSuccessor(node,point,key);
        deleteFruit(newNode->getWeight());
        Fruit* parent=getParent();
        newNode->setLeft(node->getLeft());
        newNode->setRight(node->getRight());
        if(node==root)
        {
            root=newNode;
            return root;
        }
        if(parent->getLeft()==node)
        {
            parent->setLeft(newNode);
        }
        else
        {
            parent->setRight(newNode);
        }
    }

    return node;
}

void Tree::print(Fruit* node)
{
    cout <<"My type is: " <<node->getSpecific()<<" ,my weight is :" << node->getWeight() <<" and : "<<node->getTaste()<<"\n";
}

int main()
{
    Tree b;
	cout<<"----------------------------------------------------- insertion \n ";
    root=b.Insert(NULL,root,"Grape", 50);
    b.Insert(NULL,root,"BlackBerry", 60);
    b.Insert(NULL,root,"Grape", 30);
    b.Insert(NULL,root,"Grape", 40);
    b.Insert(NULL,root,"Grape", 10);
    b.Insert(NULL,root,"Berry", 70);
    b.Insert(NULL,root,"Strawberry",5);
    b.Insert(NULL,root,"BlueBerry", 80);
    b.Insert(NULL,root,"GooseBerry", 50);
     b.Insert(NULL,root,"ElderBerry", 90);
	cout<<"\n----------------------------------------------------- iteration 1 \n ";
  //  b.Iterate();
    b.Insert(NULL,root,"Apple", 30); 
	cout<<"\n----------------------------------------------------- iteration 2 \n ";
    b.deleteFruit(80);
    b.deleteFruit(50);
    b.deleteFruit(70);
   /*  b.deleteFruit(90);
      b.deleteFruit(60);
      b.Iterate();
      cout<<"root : "<<root->getWeight();*/
	Fruit* min=b.findLightest();
	cout<<" min : " ;
	b.print(min);
	Fruit* max=b.findHeaviest();
    cout<<" max is ";
    b.print(max);
	cout<<"\n----------------------------------------------------- filter by weight \n ";
    b.filterByWeight(20);
	cout<<"\n----------------------------------------------------- filter by type \n ";
    b.filterByType("Berry");
	cout<<"\n----------------------------------------------------- magnify \n ";
    b.magnifyByType("Berry",10);

    return 0;
}