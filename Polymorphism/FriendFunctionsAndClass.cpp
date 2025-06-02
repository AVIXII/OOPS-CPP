#include <iostream>
using namespace std;

// Forward declaration of class Engine
class Engine;

class Car
{
private:
    int speed;
    int fuel;

public:
    Car() : speed(0), fuel(0) {}

    // Friend Function Declaration
    friend void tuneCar(Car &c);

    // Friend Class Declaration
    friend class Engine;

    void showStatus()
    {
        cout << "Car speed: " << speed << " km/h, Fuel: " << fuel << " L" << endl;
    }
};

// Friend Function: Can access Car's private members
void tuneCar(Car &c)
{
    c.speed += 20;
    c.fuel += 10;
    cout << "[Friend Function] Car tuned! Speed increased, fuel added." << endl;
}

// Friend Class: Engine can access all private members of Car
class Engine
{
public:
    void boost(Car &c)
    {
        c.speed += 50;
        cout << "[Friend Class] Engine boosted! Speed increased." << endl;
    }

    void refuel(Car &c, int amount)
    {
        c.fuel += amount;
        cout << "[Friend Class] Refueled " << amount << "L of fuel." << endl;
    }
};

int main()
{
    Car myCar;

    cout << "Initial Car Status:" << endl;
    myCar.showStatus();

    // Using friend function
    tuneCar(myCar);
    myCar.showStatus();

    // Using friend class
    Engine e;
    e.boost(myCar);
    e.refuel(myCar, 15);
    myCar.showStatus();

    return 0;
}