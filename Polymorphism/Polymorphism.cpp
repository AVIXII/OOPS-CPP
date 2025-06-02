// Compile Time Polymorphism - Function overloading and Operator overloading

#include <iostream>
using namespace std;

class Calculator
{
private:
    int a, b;

public:
    // Constructors
    Calculator(int x = 0, int y = 0) : a(x), b(y) {}

    // Function Overloading
    int add(int x, int y)
    {
        return x + y;
    }

    double add(double x, double y)
    {
        return x + y;
    }

    int add(int x, int y, int z)
    {
        return x + y + z;
    }

    // Operator Overloading: '+' to add two Calculator objects
    Calculator operator+(const Calculator &other)
    {
        return Calculator(a + other.a, b + other.b);
    }

    void display() const
    {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main()
{
    Calculator calc;

    // Function Overloading
    cout << "add(5, 10) = " << calc.add(5, 10) << endl;
    cout << "add(3.5, 2.5) = " << calc.add(3.5, 2.5) << endl;
    cout << "add(1, 2, 3) = " << calc.add(1, 2, 3) << endl;

    cout << endl;

    // Operator Overloading
    Calculator c1(2, 3), c2(4, 5);
    Calculator c3 = c1 + c2; // Uses overloaded '+'

    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();
    cout << "c1 + c2: ";
    c3.display();

    return 0;
}

// Runtime Polymorphism - Virtual Functions
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal *a; // Base class pointer
    Dog d;
    Cat c;

    a = &d;
    a->sound(); // Dog barks

    a = &c;
    a->sound(); // Cat meows

    return 0;
}