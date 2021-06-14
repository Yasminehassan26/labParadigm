 #include <iostream>

 //base class 
class Fruit{
   public:
  		 Fruit* leftChild;   
  		 Fruit* rightChild;
		 int weight;

   public:
		Fruit* getLeft();
		Fruit* getRight();
        int getWeight();
        void setWeight(int);
        Fruit(int);
        Fruit();

};
class Tree{

 public:
        Fruit* findLightest();
        Fruit* findHeaviest(); 
        void Iterate();
        void filterByWeight(int);
        void magnifyByType(Fruit*,int);
        void filterByType(Fruit*); 
        Fruit* Insert(Fruit*, int );
};
//subclasses
class OvalShape : public Fruit{

};
class TinyShape : public Fruit{

};
class Grapes : public TinyShape ,public OvalShape{

};
class Berry : public TinyShape,public OvalShape{

};
class Avocado : public OvalShape{

};
class Apple : public OvalShape{

};