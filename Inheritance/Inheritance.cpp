#include <iostream>
using namespace std;

// 1. Single Inheritance
class Animal
{
public:
    void eat()
    {
        cout << "Animal eats food" << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog barks" << endl;
    }
};

// 2. Multiple Inheritance
class Engine
{
public:
    void start()
    {
        cout << "Engine starts" << endl;
    }
};

class Wheels
{
public:
    void rotate()
    {
        cout << "Wheels rotate" << endl;
    }
};

class Car : public Engine, public Wheels
{
public:
    void drive()
    {
        cout << "Car is driving" << endl;
    }
};

// 3. Multilevel Inheritance
class Vehicle
{
public:
    void move()
    {
        cout << "Vehicle moves" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void balance()
    {
        cout << "Bike balances" << endl;
    }
};

class SportsBike : public Bike
{
public:
    void race()
    {
        cout << "SportsBike races" << endl;
    }
};

// 4. Hierarchical Inheritance
class Shape
{
public:
    void draw()
    {
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void drawCircle()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape
{
public:
    void drawSquare()
    {
        cout << "Drawing Square" << endl;
    }
};

// 5. Hybrid Inheritance
class Printer
{
public:
    void print()
    {
        cout << "Printing document" << endl;
    }
};

class Scanner
{
public:
    void scan()
    {
        cout << "Scanning document" << endl;
    }
};

class Machine : public Printer, public Scanner
{
public:
    void copy()
    {
        cout << "Copying document" << endl;
    }
};

int main()
{
    // Single Inheritance
    Dog d;
    d.eat();
    d.bark();

    cout << endl;

    // Multiple Inheritance
    Car c;
    c.start();
    c.rotate();
    c.drive();

    cout << endl;

    // Multilevel Inheritance
    SportsBike sb;
    sb.move();
    sb.balance();
    sb.race();

    cout << endl;

    // Hierarchical Inheritance
    Circle ci;
    ci.draw();
    ci.drawCircle();

    Square sq;
    sq.draw();
    sq.drawSquare();

    cout << endl;

    // Hybrid Inheritance
    Machine m;
    m.print();
    m.scan();
    m.copy();

    return 0;
}