#include <string.h>
#include <iostream>


 //base class 
class Fruit{
   private:
  		 Fruit* leftChild;   
  		 Fruit* rightChild;
		 int weight;
         

   public:
		Fruit* getLeft();
		Fruit* getRight();
        int getWeight();
        void setWeight(int);
        void setRight(Fruit*);
        void setLeft(Fruit*);
        Fruit(int);
        Fruit();
        virtual std::string getTaste();
        virtual std::string getType();
        virtual std::string getSpecific();


};
 class Tree{
 private:
        Fruit* parent;
 public:
        Fruit* findLightest();
        Fruit* findHeaviest(); 
        void setParent(Fruit*);
        Fruit* getParent();
        void Iterate();
        void IterateHelper(std::string);
        void filterByWeight(int);
        void magnifyByType(std::string,int);
        void filterByType(std::string); 
        Fruit* Insert(Fruit*,Fruit*, std::string,int );
        Fruit* InsertHelper(std::string,int);
        Fruit* findSuccessor(Fruit*,Fruit*,int);
       Fruit* findPredecessor(Fruit*);
        Fruit* searchForNode(Fruit*,Fruit* , int );
        Fruit* deleteFruit(int);
     
       void print(Fruit* ) ;

};
//subclasses
class OvalShape :virtual public Fruit{
    public:
        virtual std::string getType();
        virtual std::string getSpecific();

};
class TinyShape : virtual public Fruit{
    public:
        virtual std::string getType();
        virtual std::string getSpecific();


};
class Grapes : public TinyShape ,public OvalShape{
    public:
        virtual std::string getTaste();
        virtual std::string getType();
        virtual std::string getSpecific();

};
class Berry : public TinyShape,public OvalShape{
   
    public:
        virtual std::string getTaste();
        virtual std::string getType();
        virtual std::string getSpecific();
};
class BlueBerry : public Berry{

    public:
        virtual std::string getType();
        virtual std::string getSpecific();
};
class BlackBerry : public Berry{

    public:
        virtual std::string getType();
        virtual std::string getSpecific();
};
class GooseBerry : public Berry{

    public:
        virtual std::string getType();
        virtual std::string getSpecific();
};
class ElderBerry : public Berry{
    public:
        virtual std::string getType();
        virtual std::string getSpecific();
};
class Strawberry : public Berry{

    public:
        virtual std::string getTaste();
        virtual std::string getType();
        virtual std::string getSpecific();
};
class Avocado : public OvalShape{
     public:
        virtual std::string getTaste();
        virtual std::string getType();
        virtual std::string getSpecific();
};
class Apple : public OvalShape{
    public:
        virtual std::string getTaste();
        virtual std::string getType();
        virtual std::string getSpecific();
};