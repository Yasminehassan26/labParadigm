#include <iostream>
#include <stack>
#include <list>
#include "fruitHeader.h"

using namespace std;
Fruit* root=NULL;
Fruit ::Fruit(int value) 
{
	 weight = value; 
	leftChild = rightChild= NULL; 
} 
Fruit ::Fruit() {
	 leftChild = rightChild= NULL; } 

Fruit* Fruit::getLeft(){
	return leftChild;
}
Fruit* Fruit::getRight(){
	return rightChild;
}
int Fruit::getWeight(){
	return weight;
}
void Fruit::setWeight(int w){
weight=w;
}


void Tree ::Iterate()
{
   // list <int> myList;
    if(root==NULL) {
    		 return ;
    	 }
    	stack<Fruit*> stack;
    	Fruit* currentNode=root;
    	while (!stack.empty() || currentNode!=NULL ) {
    		while(currentNode!=NULL) {
    			stack.push(currentNode);
    			currentNode=currentNode->getLeft();
    		}
    		currentNode=stack.top();
			cout<< currentNode->getWeight()<<" --> ";
			stack.pop();
    		currentNode=currentNode->getRight();    		    		
    	}   
		cout<<"done \n";
		
}
// Insert function definition.
Fruit* Tree ::Insert(Fruit* node, int value)
{
    if (!node)
    {
        // Insert the first node, if root is NULL.
	//	Fruit* root;
        return new Fruit(value);
    }
 
    // Insert data.
    if (value > node->getWeight())
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        node->rightChild=Insert(node->getRight(), value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        node->leftChild=Insert(node->getLeft(), value);
    }
 
    // Return 'root' node, after insertion.
    return node;
}
Fruit* Tree::findHeaviest(){
	
         if(root==NULL) {
    		 return NULL ;
    	 }
    	
    	Fruit* currentNode=root;
    		while(currentNode->getRight()!=NULL) {
    			currentNode=currentNode->getRight();
    		}  
			return currentNode;
} 
Fruit* Tree::findLightest(){
if(root==NULL) {
    		 return NULL;
    	 }
    	
    	Fruit* currentNode=root;
    		while(currentNode->getLeft()!=NULL) {
    			currentNode=currentNode->getLeft();
    		} 
			return currentNode; 
} 
void Tree::filterByWeight(int weight){
	list <Fruit*> weightList;
 	 if(root==NULL) {
    		 return ;
    	 }
    	stack<Fruit*> stack;
    	Fruit* currentNode=root;
    	while (!stack.empty() || currentNode!=NULL ) {
    		while(currentNode!=NULL) {
    			stack.push(currentNode);
    			currentNode=currentNode->getRight();
    		}
    		currentNode=stack.top();
			if(currentNode->getWeight()>weight){
				weightList.push_front(currentNode);
			}
			else{
				int size=weightList.size();
                for(int it = 0; it<size; it++){
			        cout << weightList.front()->getWeight()<< " ---> ";
				    weightList.pop_front();
				}
				cout<<"done";
				return;
			}
			stack.pop();
    		currentNode=currentNode->getLeft();    		    		
    	}   	

}


int main() { 
Tree b;
root= b.Insert(root, 50); 
b.Insert(root, 30); 
b.Insert(root, 20);
 b.Insert(root, 40);
  b.Insert(root, 70); 
 b.Insert(root, 60); 
 //b.Insert(root, 50);
  b.Iterate();
  Fruit* min=b.findLightest();
  cout<<" min is "<<min->getWeight()<<"\n";
  Fruit* max=b.findHeaviest();
  cout<<" max is "<<max->getWeight()<<"\n";
  b.filterByWeight(20);
  return 0;
   } 