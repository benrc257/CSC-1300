//class specification file

#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>
using namespace std;

//class declaration/definition
class IceCream { 
    private:
        string cone, flavor, topping;
        double price;
    public:
        //constructors
        IceCream(); //default
        IceCream(string, string, string, double); //overloaded

        //accessor
        string getCone() const;
        string getFlavor() const;
        string getTopping() const;
        double getPrice() const;

        //mutator
        void setCone(string);
        void setFlavor(string);
        void setTopping(string);
        void setPrice(double);

        void printIceCream();

        //destructor
        ~IceCream();
};



#endif