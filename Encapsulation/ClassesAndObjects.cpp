#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
    int *id;

    const int birthYear;
    string &nickname;

    static int personCount; // 🔹 Static member

public:
    // 🔸 Default constructor
    Person()
        : name("Unknown"), age(0), id(new int(0)), birthYear(2000), nickname(name)
    {
        personCount++;
        cout << "Default constructor called\n";
    }

    // 🔸 Parameterized constructor
    Person(string name, int age, int idVal, int birthYear, string &nick)
        : name(name), age(age), id(new int(idVal)), birthYear(birthYear), nickname(nick)
    {
        personCount++;
        cout << "Parameterized constructor called\n";
    }

    // 🔸 Copy constructor
    Person(const Person &other)
        : name(other.name), age(other.age), id(new int(*other.id)),
          birthYear(other.birthYear), nickname(other.nickname)
    {
        personCount++;
        cout << "Copy constructor called (deep copy)\n";
    }

    // 🔹 Static method
    static int getPersonCount()
    {
        return personCount;
    }

    // 🔹 Operator Overload ==
    bool operator==(const Person &other) const
    {
        return name == other.name && age == other.age && *id == *other.id;
    }

    // 🔹 Public method for printing instead of << overloading
    void print() const
    {
        cout << "Name: " << name
             << ", Age: " << age
             << ", ID: " << *id
             << ", Birth Year: " << birthYear
             << ", Nickname: " << nickname << endl;
    }

    // Setters and Getters
    void setName(string name) { this->name = name; }

    void setAge(int age)
    {
        if (age > 0)
            this->age = age;
    }

    void setId(int idVal) { *id = idVal; }

    string getName() { return name; }

    int getAge() { return age; }

    int getId() { return *id; }

    int getBirthYear() const { return birthYear; }

    string &getNickname() { return nickname; }

    void displayInfo() const
    {
        print(); // Uses the internal print function
    }

    ~Person()
    {
        delete id;
        cout << "Destructor called for " << name << "\n";
    }
};

// Define static member outside the class
int Person::personCount = 0;

int main()
{
    string nick = "Ally";

    Person p1("Alice", 25, 101, 1995, nick);
    p1.displayInfo();

    Person p2 = p1;
    p2.displayInfo();

    p1.getNickname() = "Lissy";

    cout << "\nAfter changing nickname of p1:\n";
    p1.displayInfo();
    p2.displayInfo();

    cout << "\nAre p1 and p2 equal? " << (p1 == p2 ? "Yes" : "No") << "\n";
    cout << "Total Persons created: " << Person::getPersonCount() << "\n";

    return 0;
}