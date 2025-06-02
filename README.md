# Object Oriented Programming - CPP

The complete module is divided into 4 main parts according to the pillars of OOPS.
Refer to the notes in the folders as well as the following explanation side-by-side.

# Encapsulation
## Access Specifiers
🔓 public

	•	Members are accessible from anywhere the object is visible.
	•	Used to expose class interfaces and behaviors.
	•	Allows access to constructors, getters, setters, and public methods.

🔐 private

	•	Members are only accessible within the class or by friend functions.
	•	Default access level for class members.
	•	Used to hide internal data and enforce encapsulation.

🛡️ protected

	•	Members are accessible within the class and by derived (child) classes.
	•	Not accessible from outside the class hierarchy.
	•	Commonly used in inheritance scenarios.

---
Getters - Accessor functions

Setters - Mutator functions

---

Scope resolution operator
```cpp

class Student{
    int marks;

    public:
        int getMarks();
};

int Student::getMarks(){
    return marks;
}
```
---
## Constructors:

A constructor in a class is a special method invoked for creating or initializing objects of a class.

A constructor has following characteristics:
- Constructor is a member function of a class and has same name as that of
the class.
- Constructor functions are invoked automatically when the objects are created. It is only invoked once (at the time of creation of the object).
- Memory allocation happens when the constructor is called.
- Constructor functions obey the usual access rules. (That is, private constructors are available only for member functions, however, public
constructors are available for all functions)
- Constructor has no return type, not even void.

There are two types of constructors:
- Default
- Custom 
    - Non-parameterized
    - Parameterized

The creation of custom constructor overshadows the default constructor. Hence, care should be taken while creation of objects in case of inheritance(refer further codes).

---
## Shallow & Deep Copies, Copy Constructors and Copy Assignment Operators

### Shallow Copy
A shallow copy copies the values of data members as-is, including pointers (addresses). Dependant copies.

### Deep Copy 
A deep copy copies not just the pointer values but the actual content they point to. Independent copies.

### Copy Constructor:

- A copy constructor is a special constructor in C++ that creates a new object as a copy of an existing object.
- It takes a reference to another object of the same class as an argument.
- Used when: 
    - An object is passed by value.
    - An object is returned by value.
    - A new object is explicitly initialized from an existing object.
- Types of copy constructors:
    - Default (Shallow copy)
    - Custom (Deep copy)

### Copy Assignment Operator
Assigns the contents of one existing object to another existing object.

Invokes the copy constructor (custom if defined)


---
## Destructors

A destructor is a special member function of a class that is automatically called when an object goes out of scope or is explicitly deleted.
It is used to free resources like memory, file handles, sockets, etc., that the object may have acquired during its lifetime.

Two types of Destructors:
- Default
- Custom (Used only when there is dynamic memory allocation)


Features:
- Automatic invocation - Out-of-scope or `delete` called.
- Only 1 destructor per class - No overloading 

---
## Initialisation Lists:

Required for `const` and reference variables. As they must be initialized at creation time.

---

## Rule of Three
```
If your class manages resources it should define:
    - Destructor
    - Copy Constructor
    - Copy Assignment Operator
```
---
## Constant Functions

Constant functions are those which don’t change any property of current objects.
Only constant objects of the class could invoke these.

Syntax:
datatype function_name() const;

---

## Static Keyword
1. Some properties of a class are common to all the objects (like the school name in case of students or functions like getAcademicCalendar() which can be accessed irrespective of the objects of the class).

    In such a case, static keyword is used to define data members and functions which are a property of the `class` not the objects.

2. In a function, if a variable is declared static, it will be created and initialized once for the lifetime of the program.

3. In a class, if a static object is created it persists till the end of the program.

---

## Operator Overloading

Operator Overloading allows you to redefine the way operators work for user-defined types (like classes). This helps your classes behave more like built-in types.

return_type operator\<op>(argument_list);

---

# Inheritance
Inheritance in C++ is a fundamental Object-Oriented Programming (OOP) concept that allows a class (called the derived class or child class) to inherit properties and behaviors (data members and member functions) from another class (called the base class or parent class).

|                 | Private Mode   | Protected Mode | Public Mode    |
|-----------------|----------------|----------------|----------------|
| **Base Class**  |                |                |                |
| Private         | Not Inherited  | Not Inherited  | Not Inherited  |
| Protected       | Private        | Protected      | Protected      |
| Public          | Private        | Protected      | Public         |

### Types of Inheritance in C++

C++ supports five main types of inheritance:

---

## 1. Single Inheritance
A derived class inherits from only one base class.

```cpp
class Base {
    // Base class members
};

class Derived : public Base {
    // Derived class members
};
```

## 2. Multi-level Inheritance
A class is derived from another derived class

```cpp
class Base {
    // ...
};

class Intermediate : public Base {
    // ...
};

class Derived : public Intermediate {
    // ...
};
```

## 3. Multiple Inheritance
A child class is created from more than one base class

```cpp
class Base1 {
    // ...
};

class Base2 {
    // ...
};

class Derived : public Base1, public Base2 {
    // ...
};
```
## 4. Hierarchial Inheritance
Multiple derived classes inherit from a single base class

```cpp
class Base {
    // ...
};

class Derived1 : public Base {
    // ...
};

class Derived2 : public Base {
    // ...
};
```

## 5. Hybrid Inheritance
A combination of two or more types of inheritance. It can lead to the diamond problem, which is solved using virtual inheritance.

```cpp
class A {
    // ...
};

class B : public virtual A {
    // ...
};

class C : public virtual A {
    // ...
};

class D : public B, public C {
    // D inherits A only once due to virtual inheritance
};
```

# Polymorphism

**Polymorphism** means **"many forms"**. In C++, it allows the same function or operator to behave differently based on the context.

---

## Types of Polymorphism in C++

### 1. **Compile-time Polymorphism (Static Binding)**
Achieved using:
- Function Overloading
- Operator Overloading

### 2. **Run-time Polymorphism (Dynamic Binding)**
Achieved using:
- Virtual Functions and Inheritance

---

## 1. Compile-time Polymorphism

### Function Overloading
Multiple functions with the same name but different parameters.

```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }

    void show(double x) {
        cout << "Double: " << x << endl;
    }

    void show(string x) {
        cout << "String: " << x << endl;
    }
};
```

### Operator Overloading
Redefining operators for user-defined types

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
```

## Runtime Polymorphism
Achieved using virtual functions and base class pointers

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a;  // Base class pointer
    Dog d;
    Cat c;

    a = &d;
    a->sound();  // Dog barks

    a = &c;
    a->sound();  // Cat meows

    return 0;
}
```

## Pure Virtual Functions and Abstract Classes

A **pure virtual function** is a virtual function that has **no implementation in the base class** and is specified using `= 0`.

### Syntax:
```cpp
virtual void functionName() = 0;

Syntax:
```cpp
#include <iostream>
using namespace std;
class Vehicle { public :
// This class becomes abstract as it contains a pure virtual function
string color;

// Pure virtual function
virtual void print() = 0;
};
```

## Abstract Class
An abstract class is a class that contains at least one pure virtual function.
- You cannot create an object of an abstract class.
- You must override **all** the pure virtual function(s) in derived classes to make them concrete.

# Friend Functions and Friend Classes

A **friend function** is a function that is **not a member** of a class but has **access to its private and protected members**.

### Syntax:
```cpp
class ClassName {
    friend returnType functionName(arguments);
};
```

A friend class is a class that is allowed to access the private and protected members of another class.

### Syntax
```cpp
class ClassB;

class ClassA {
    friend class ClassB;
};
```

Best Practice
- Use sparingly — friend functions/classes break encapsulation.
- Prefer using getters/setters if public access is required.