#include <iostream>
using namespace std;

// Implementing the duck example of head first


// This is the RULE
// •	Any flying behavior must have a fly() function
// •	= 0 means NO body → child must implement it
// •	This is the Strategy Interface
// same for quack

// Implementing FlyBehaviour

class FlyBehaviour{
    public:
        // this is because every flying behviour must have fly function
        virtual void fly()= 0;  // pure virtual
        virtual ~FlyBehaviour() {}

};

// Implementing QuackBehaviour

class QuackBehaviour{
    public:
        virtual void quack() =0;
        virtual ~QuackBehaviour() {}
};



// Now Create concrete behaviour 

class FlyWithWings : public FlyBehaviour{
    public:
        void fly() override{
            cout<<"I can Fly"<<endl;
        }
};

class FlyNoWings : public FlyBehaviour{
    public:
        void fly() override{
            cout<<"I can't Fly"<<endl;
        }
};

class Quack : public QuackBehaviour{
    public :
        void quack() override{
            cout<< "Quack"<<endl;
        }
} ;

class Squeak : public QuackBehaviour{
    public: 
        void quack() override{
            cout<<"Squeak"<<endl;
        }
};

class MuteQuack : public QuackBehaviour{
    public: 
        void quack() override{
            cout<<"Silence"<<endl;
        }
};


// Create the duck base class 

class Duck{
    // why pointer -> because we want to switch the behaviour at runtime
    public:
        FlyBehaviour* flyBehaviour;  // Pointer → can point to any flying strategy (wings or no-fly)
        QuackBehaviour* quackBehaviour; // Pointer → can point to any quacking strategy

        Duck(){
            flyBehaviour = nullptr;
            quackBehaviour = nullptr;
        }

        void performFly(){
            flyBehaviour->fly();
        }

        void performQuack(){
            quackBehaviour->quack();
        }

        void setFlyBehaviour(FlyBehaviour*fb){
            flyBehaviour = fb;
        }

        void setQuackBehaviour(QuackBehaviour*qb){
            quackBehaviour = qb;
        }

        // Every duck looks different → they must override this.
        virtual void display() =0;
        
        virtual ~Duck() {}


};


class MallardDuck : public Duck {
public:
    MallardDuck() {
        flyBehaviour = new FlyWithWings();
        quackBehaviour = new Quack();
    }

    void display() override {
        cout << "I'm a real Mallard duck\n";
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck() {
        flyBehaviour = new FlyNoWings();
        quackBehaviour = new Squeak();
    }

    void display() override {
        cout << "I'm a Rubber Duck\n";
    }
};


class DecoyDuck : public Duck {
public:
    DecoyDuck() {
        flyBehaviour = new FlyNoWings();
        quackBehaviour = new MuteQuack();
    }

    void display() override {
        cout << "I'm a Decoy Duck \n";
    }
};

class ModelDuck : public Duck {
public:
    ModelDuck() {
        flyBehaviour = new FlyNoWings();
        quackBehaviour = new Quack();
    }

    void display() override {
        cout << "I'm a Model Duck\n";
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Duck * mallard= new MallardDuck;
    mallard->display();
    mallard->performFly();
    mallard->performQuack();


// create a new duck 
    Duck* model = new ModelDuck();
    model->display();
    // model->setFlyBehaviour(new FlyWithWings()); 
    model->performFly();  
    return 0;
}



