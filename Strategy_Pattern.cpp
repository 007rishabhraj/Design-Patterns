// Payment Strategy 

#include <iostream>
#include <string>
using namespace std;

// Create a Startegy Interface 

class PaymentStrategy {
    public:
        virtual void pay(int amount) = 0; // pure virtual function
        virtual ~PaymentStrategy() {} // virtual destructor
};

// Strategy 1: Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
    public:
        void pay(int amount) override {
            cout<<"Paid " << amount << " using Credit Card." << endl;
        }
};

// Strategy 2 : PayPal Payment
class PayPalPayment : public PaymentStrategy {
    public:
        void pay(int amount) override {
            cout<<"Paid " << amount << " using PayPal." << endl;
        }
};

// startegy 3: UPI
class UPIPayment : public PaymentStrategy {
    public:
        void pay(int amount) override {
            cout<<"Paid " << amount << " using UPI." << endl;
        }
};

// Context Class

class PayementService{
    private:
        PaymentStrategy* strategy; // pointer to strategy

        // A constructor is a special function that runs AUTOMATICALLY when you create an object.
    public:
        PayementService(){
            strategy = nullptr;
        }

        void setStrategy(PaymentStrategy* s){
            strategy = s;
        }

        void makePayment(int amount){
            if(!strategy){
                cout<<"No Method selected";
                return;
            }
            strategy ->pay(amount);
        }
};


int main(){

    PayementService Service_object;
    Service_object.setStrategy(new CreditCardPayment() );
    // Service_object.makePayment(1000);



    return 0;
} 