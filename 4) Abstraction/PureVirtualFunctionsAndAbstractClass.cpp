#include <iostream>
using namespace std;

// Abstract Base Class
class Animal
{
public:
    // Pure Virtual Function
    virtual void makeSound() = 0;

    // Regular Member Function
    void breathe()
    {
        cout << "Breathing..." << endl;
    }
};

// Derived Class 1
class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Woof! Woof!" << endl;
    }
};

// Derived Class 2
class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << "Meow! Meow!" << endl;
    }
};

int main()
{
    // Animal a; // ❌ Error: Cannot instantiate abstract class

    Dog dog;
    Cat cat;

    dog.makeSound(); // Output: Woof! Woof!
    dog.breathe();   // Output: Breathing...

    cat.makeSound(); // Output: Meow! Meow!
    cat.breathe();   // Output: Breathing...

    return 0;
}