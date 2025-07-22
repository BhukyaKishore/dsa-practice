# 🧠 Complete C++ Placement Preparation Notebook
## From Beginner to Interview-Ready

**Author:** Bhavani Kishore(Using Manus AI) 
**Version:** 1.0  
**Last Updated:** July 22, 2025

---

## 📋 Table of Contents

1. [🧩 Object-Oriented Programming (OOPs) in C++](#1-object-oriented-programming-oops-in-c)
2. [📚 Standard Template Library (STL)](#2-standard-template-library-stl)
3. [🔄 Important Data Structures](#3-important-data-structures)
4. [📌 Essential Algorithms with Practice Problems](#4-essential-algorithms-with-practice-problems)
5. [🧠 Advanced Topics](#5-advanced-topics)
6. [📋 Practice Sheet & Tracker](#6-practice-sheet--tracker)
7. [🎯 Interview Tips & Final Preparation](#7-interview-tips--final-preparation)

---

## Introduction

Welcome to the most comprehensive C++ placement preparation notebook designed specifically for beginners who want to become interview-ready for top companies including TCS, Infosys, Wipro, Accenture, Capgemini, Amazon, and product-based startups.

This notebook follows a structured approach that takes you from basic concepts to advanced topics, ensuring you have a solid foundation in C++ programming, data structures, algorithms, and problem-solving techniques that are essential for technical interviews.

Each section includes:
- Clear conceptual explanations with real-life analogies
- Comprehensive code examples
- Practice problems with detailed solutions
- Time and space complexity analysis
- Interview tips and common pitfalls

Let's begin your journey to placement success!

---


## 1. 🧩 Object-Oriented Programming (OOPs) in C++

Object-Oriented Programming is a programming paradigm that organizes code around objects and classes rather than functions and logic. Think of OOP as a way to model real-world entities in your code, making it more intuitive, maintainable, and scalable.

### 1.1 The Four Pillars of OOP

#### 1.1.1 Encapsulation

Encapsulation is like a protective capsule around your data and methods. Imagine a medicine capsule that protects the medicine inside from external contamination while providing a controlled way to access it. Similarly, encapsulation bundles data (attributes) and methods (functions) together within a class and restricts direct access to some of the object's components.

**Key Benefits:**
- Data hiding and security
- Controlled access through getter and setter methods
- Easier maintenance and debugging
- Prevents accidental modification of data

**Code Example:**

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    // Constructor
    BankAccount(string accNum, string owner, double initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }
    
    // Getter methods (Accessors)
    string getAccountNumber() const {
        return accountNumber;
    }
    
    string getOwnerName() const {
        return ownerName;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Setter methods (Mutators) with validation
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
            return true;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
            return false;
        }
    }
    
    void displayAccountInfo() const {
        cout << "Account: " << accountNumber 
             << ", Owner: " << ownerName 
             << ", Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account("ACC123456", "John Doe", 1000.0);
    
    account.displayAccountInfo();
    account.deposit(500.0);
    account.withdraw(200.0);
    account.displayAccountInfo();
    
    // Direct access to private members would cause compilation error
    // account.balance = 5000; // Error!
    
    return 0;
}
```

#### 1.1.2 Abstraction

Abstraction is like using a car without knowing how the engine works internally. You know how to use the steering wheel, accelerator, and brakes, but you don't need to understand the complex internal mechanisms. In programming, abstraction means hiding complex implementation details while showing only the essential features of an object.

**Types of Abstraction:**
1. **Data Abstraction:** Hiding data implementation details
2. **Function Abstraction:** Hiding function implementation details

**Code Example - Abstract Class:**

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Abstract base class
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {}
    
    // Pure virtual function makes this class abstract
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    
    // Concrete method
    void setColor(string c) {
        color = c;
    }
    
    string getColor() const {
        return color;
    }
    
    // Virtual destructor for proper cleanup
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(double l, double w, string c) : Shape(c), length(l), width(w) {}
    
    double calculateArea() override {
        return length * width;
    }
    
    double calculatePerimeter() override {
        return 2 * (length + width);
    }
    
    void displayInfo() {
        cout << "Rectangle - Color: " << color 
             << ", Area: " << calculateArea() 
             << ", Perimeter: " << calculatePerimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;
    
public:
    Circle(double r, string c) : Shape(c), radius(r) {}
    
    double calculateArea() override {
        return PI * radius * radius;
    }
    
    double calculatePerimeter() override {
        return 2 * PI * radius;
    }
    
    void displayInfo() {
        cout << "Circle - Color: " << color 
             << ", Area: " << calculateArea() 
             << ", Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    // Cannot instantiate abstract class
    // Shape s; // Error!
    
    Rectangle rect(5.0, 3.0, "Red");
    Circle circle(4.0, "Blue");
    
    rect.displayInfo();
    circle.displayInfo();
    
    // Using polymorphism with abstract class
    vector<Shape*> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circle);
    
    cout << "\nUsing polymorphism:" << endl;
    for (Shape* shape : shapes) {
        cout << "Area: " << shape->calculateArea() << endl;
    }
    
    return 0;
}
```

#### 1.1.3 Inheritance

Inheritance is like a family tree where children inherit traits from their parents. In programming, inheritance allows a class (child/derived class) to inherit properties and methods from another class (parent/base class). This promotes code reusability and establishes a hierarchical relationship between classes.

**Types of Inheritance:**
1. **Single Inheritance:** One child class inherits from one parent class
2. **Multiple Inheritance:** One child class inherits from multiple parent classes
3. **Multilevel Inheritance:** A chain of inheritance (A→B→C)
4. **Hierarchical Inheritance:** Multiple child classes inherit from one parent class
5. **Hybrid Inheritance:** Combination of multiple inheritance types

**Code Example - Comprehensive Inheritance:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double price;
    
public:
    Vehicle(string b, string m, int y, double p) 
        : brand(b), model(m), year(y), price(p) {}
    
    virtual void displayInfo() {
        cout << "Vehicle Info: " << brand << " " << model 
             << " (" << year << ") - $" << price << endl;
    }
    
    virtual void start() {
        cout << "Vehicle is starting..." << endl;
    }
    
    virtual void stop() {
        cout << "Vehicle is stopping..." << endl;
    }
    
    // Getter methods
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    
    virtual ~Vehicle() {}
};

// Derived class - Single Inheritance
class Car : public Vehicle {
protected:
    int numberOfDoors;
    string fuelType;
    
public:
    Car(string b, string m, int y, double p, int doors, string fuel)
        : Vehicle(b, m, y, p), numberOfDoors(doors), fuelType(fuel) {}
    
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Car specific: " << numberOfDoors << " doors, " 
             << fuelType << " fuel" << endl;
    }
    
    void start() override {
        cout << "Car engine is starting with " << fuelType << "..." << endl;
    }
    
    void honk() {
        cout << "Car is honking: Beep! Beep!" << endl;
    }
};

// Another derived class
class Motorcycle : public Vehicle {
protected:
    bool hasSidecar;
    int engineCC;
    
public:
    Motorcycle(string b, string m, int y, double p, bool sidecar, int cc)
        : Vehicle(b, m, y, p), hasSidecar(sidecar), engineCC(cc) {}
    
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Motorcycle specific: " << engineCC << "CC engine, "
             << (hasSidecar ? "with" : "without") << " sidecar" << endl;
    }
    
    void start() override {
        cout << "Motorcycle engine is revving up..." << endl;
    }
    
    void wheelie() {
        cout << "Motorcycle is doing a wheelie!" << endl;
    }
};

// Multilevel Inheritance
class SportsCar : public Car {
private:
    int topSpeed;
    bool hasTurbo;
    
public:
    SportsCar(string b, string m, int y, double p, int doors, string fuel, 
              int speed, bool turbo)
        : Car(b, m, y, p, doors, fuel), topSpeed(speed), hasTurbo(turbo) {}
    
    void displayInfo() override {
        Car::displayInfo();
        cout << "Sports Car specific: Top speed " << topSpeed 
             << " mph, " << (hasTurbo ? "with" : "without") << " turbo" << endl;
    }
    
    void activateSportMode() {
        cout << "Sport mode activated! Maximum performance!" << endl;
    }
    
    void start() override {
        cout << "Sports car engine roaring to life!" << endl;
    }
};

int main() {
    cout << "=== Inheritance Demo ===" << endl;
    
    Vehicle vehicle("Generic", "Model", 2020, 15000);
    Car car("Toyota", "Camry", 2022, 25000, 4, "Gasoline");
    Motorcycle bike("Harley", "Davidson", 2021, 18000, false, 1200);
    SportsCar sports("Ferrari", "F8", 2023, 280000, 2, "Gasoline", 211, true);
    
    cout << "\n1. Base Vehicle:" << endl;
    vehicle.displayInfo();
    vehicle.start();
    
    cout << "\n2. Car (Single Inheritance):" << endl;
    car.displayInfo();
    car.start();
    car.honk();
    
    cout << "\n3. Motorcycle:" << endl;
    bike.displayInfo();
    bike.start();
    bike.wheelie();
    
    cout << "\n4. Sports Car (Multilevel Inheritance):" << endl;
    sports.displayInfo();
    sports.start();
    sports.activateSportMode();
    
    cout << "\n=== Polymorphism with Inheritance ===" << endl;
    Vehicle* vehicles[] = {&vehicle, &car, &bike, &sports};
    
    for (int i = 0; i < 4; i++) {
        cout << "\nVehicle " << (i+1) << ":" << endl;
        vehicles[i]->displayInfo();
        vehicles[i]->start();
    }
    
    return 0;
}
```

#### 1.1.4 Polymorphism

Polymorphism means "many forms." It's like a person who can be a student at school, a child at home, and a team member in sports - the same person behaving differently in different contexts. In programming, polymorphism allows objects of different types to be treated as objects of a common base type, while still maintaining their specific behaviors.

**Types of Polymorphism:**
1. **Compile-time Polymorphism (Static):**
   - Function Overloading
   - Operator Overloading
   - Template Specialization

2. **Runtime Polymorphism (Dynamic):**
   - Virtual Functions
   - Function Overriding

**Code Example - Runtime Polymorphism:**

```cpp
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Base class with virtual functions
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {}
    
    // Virtual function for runtime polymorphism
    virtual void makeSound() {
        cout << name << " makes a generic animal sound" << endl;
    }
    
    virtual void move() {
        cout << name << " moves in some way" << endl;
    }
    
    virtual void eat() {
        cout << name << " eats food" << endl;
    }
    
    // Pure virtual function
    virtual void displaySpecialAbility() = 0;
    
    void displayBasicInfo() {
        cout << "Name: " << name << ", Age: " << age << " years" << endl;
    }
    
    virtual ~Animal() {}
};

class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}
    
    void makeSound() override {
        cout << name << " barks: Woof! Woof!" << endl;
    }
    
    void move() override {
        cout << name << " runs on four legs" << endl;
    }
    
    void eat() override {
        cout << name << " eats dog food and bones" << endl;
    }
    
    void displaySpecialAbility() override {
        cout << name << " can fetch and guard the house" << endl;
    }
    
    void wagTail() {
        cout << name << " is wagging tail happily!" << endl;
    }
};

class Cat : public Animal {
private:
    bool isIndoor;
    
public:
    Cat(string n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {}
    
    void makeSound() override {
        cout << name << " meows: Meow! Meow!" << endl;
    }
    
    void move() override {
        cout << name << " walks gracefully and can climb" << endl;
    }
    
    void eat() override {
        cout << name << " eats cat food and fish" << endl;
    }
    
    void displaySpecialAbility() override {
        cout << name << " can hunt mice and has excellent night vision" << endl;
    }
    
    void purr() {
        cout << name << " is purring contentedly" << endl;
    }
};

class Bird : public Animal {
private:
    double wingSpan;
    
public:
    Bird(string n, int a, double span) : Animal(n, a), wingSpan(span) {}
    
    void makeSound() override {
        cout << name << " chirps: Tweet! Tweet!" << endl;
    }
    
    void move() override {
        cout << name << " flies with " << wingSpan << " inch wingspan" << endl;
    }
    
    void eat() override {
        cout << name << " eats seeds and insects" << endl;
    }
    
    void displaySpecialAbility() override {
        cout << name << " can fly and has excellent eyesight" << endl;
    }
    
    void buildNest() {
        cout << name << " is building a nest" << endl;
    }
};

// Function demonstrating polymorphism
void animalCare(Animal* animal) {
    cout << "\n--- Animal Care Session ---" << endl;
    animal->displayBasicInfo();
    animal->makeSound();
    animal->move();
    animal->eat();
    animal->displaySpecialAbility();
    cout << "--- Care Session Complete ---\n" << endl;
}

int main() {
    cout << "=== Polymorphism Demo ===" << endl;
    
    // Creating objects
    Dog dog("Buddy", 3, "Golden Retriever");
    Cat cat("Whiskers", 2, true);
    Bird bird("Tweety", 1, 8.5);
    
    // Array of base class pointers
    Animal* animals[] = {&dog, &cat, &bird};
    
    cout << "\n1. Individual Animal Behaviors:" << endl;
    for (int i = 0; i < 3; i++) {
        animalCare(animals[i]);
    }
    
    cout << "\n2. Specific Animal Methods:" << endl;
    dog.wagTail();
    cat.purr();
    bird.buildNest();
    
    cout << "\n3. Using Smart Pointers with Polymorphism:" << endl;
    vector<unique_ptr<Animal>> animalShelter;
    animalShelter.push_back(make_unique<Dog>("Rex", 4, "German Shepherd"));
    animalShelter.push_back(make_unique<Cat>("Mittens", 3, false));
    animalShelter.push_back(make_unique<Bird>("Eagle", 5, 24.0));
    
    for (auto& animal : animalShelter) {
        animal->makeSound();
        animal->displaySpecialAbility();
    }
    
    return 0;
}
```

### 1.2 Advanced OOP Concepts

#### 1.2.1 Virtual Functions and Virtual Destructors

Virtual functions are the backbone of runtime polymorphism in C++. They allow derived classes to override base class methods, ensuring the correct function is called based on the actual object type, not the pointer type.

**Key Points:**
- Virtual functions enable dynamic binding
- Virtual destructors ensure proper cleanup in inheritance hierarchies
- Pure virtual functions create abstract classes
- Virtual function table (vtable) mechanism

**Code Example:**

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor called" << endl; }
    
    // Virtual function
    virtual void display() {
        cout << "Base display function" << endl;
    }
    
    // Pure virtual function
    virtual void pureVirtualFunction() = 0;
    
    // Virtual destructor - VERY IMPORTANT!
    virtual ~Base() { 
        cout << "Base destructor called" << endl; 
    }
};

class Derived1 : public Base {
private:
    int* data;
    
public:
    Derived1() {
        data = new int[100];
        cout << "Derived1 constructor called" << endl;
    }
    
    void display() override {
        cout << "Derived1 display function" << endl;
    }
    
    void pureVirtualFunction() override {
        cout << "Derived1 implementation of pure virtual function" << endl;
    }
    
    ~Derived1() {
        delete[] data;
        cout << "Derived1 destructor called" << endl;
    }
};

class Derived2 : public Base {
private:
    string* message;
    
public:
    Derived2() {
        message = new string("Hello from Derived2");
        cout << "Derived2 constructor called" << endl;
    }
    
    void display() override {
        cout << "Derived2 display function: " << *message << endl;
    }
    
    void pureVirtualFunction() override {
        cout << "Derived2 implementation of pure virtual function" << endl;
    }
    
    ~Derived2() {
        delete message;
        cout << "Derived2 destructor called" << endl;
    }
};

void demonstrateVirtualFunctions(Base* obj) {
    obj->display();  // Calls the overridden version
    obj->pureVirtualFunction();
}

int main() {
    cout << "=== Virtual Functions Demo ===" << endl;
    
    cout << "\n1. Creating Derived1 object:" << endl;
    Derived1 d1;
    
    cout << "\n2. Creating Derived2 object:" << endl;
    Derived2 d2;
    
    cout << "\n3. Polymorphic behavior:" << endl;
    Base* ptr1 = &d1;
    Base* ptr2 = &d2;
    
    demonstrateVirtualFunctions(ptr1);
    demonstrateVirtualFunctions(ptr2);
    
    cout << "\n4. Dynamic allocation with proper cleanup:" << endl;
    {
        unique_ptr<Base> smartPtr1 = make_unique<Derived1>();
        unique_ptr<Base> smartPtr2 = make_unique<Derived2>();
        
        smartPtr1->display();
        smartPtr2->display();
        
        // Destructors called automatically when going out of scope
    }
    
    cout << "\n5. Manual dynamic allocation:" << endl;
    Base* dynamicPtr = new Derived1();
    dynamicPtr->display();
    delete dynamicPtr;  // Virtual destructor ensures proper cleanup
    
    return 0;
}
```

#### 1.2.2 Function Overloading

Function overloading allows multiple functions with the same name but different parameters. It's like having multiple tools with the same name but different purposes - a "cut" function that can cut paper, wood, or metal depending on the parameters.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Calculator {
public:
    // Function overloading with different parameter types
    int add(int a, int b) {
        cout << "Adding two integers: ";
        return a + b;
    }
    
    double add(double a, double b) {
        cout << "Adding two doubles: ";
        return a + b;
    }
    
    string add(string a, string b) {
        cout << "Concatenating two strings: ";
        return a + b;
    }
    
    // Function overloading with different number of parameters
    int add(int a, int b, int c) {
        cout << "Adding three integers: ";
        return a + b + c;
    }
    
    // Function overloading with vector
    int add(const vector<int>& numbers) {
        cout << "Adding vector of integers: ";
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        return sum;
    }
    
    // Overloaded display functions
    void display(int value) {
        cout << "Integer value: " << value << endl;
    }
    
    void display(double value) {
        cout << "Double value: " << value << endl;
    }
    
    void display(const string& value) {
        cout << "String value: " << value << endl;
    }
    
    void display(const vector<int>& values) {
        cout << "Vector values: ";
        for (int val : values) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Calculator calc;
    
    cout << "=== Function Overloading Demo ===" << endl;
    
    // Different parameter types
    int intResult = calc.add(5, 3);
    calc.display(intResult);
    
    double doubleResult = calc.add(5.5, 3.2);
    calc.display(doubleResult);
    
    string stringResult = calc.add("Hello, ", "World!");
    calc.display(stringResult);
    
    // Different number of parameters
    int threeIntResult = calc.add(1, 2, 3);
    calc.display(threeIntResult);
    
    // Vector parameter
    vector<int> numbers = {1, 2, 3, 4, 5};
    int vectorResult = calc.add(numbers);
    calc.display(vectorResult);
    calc.display(numbers);
    
    return 0;
}
```

#### 1.2.3 Operator Overloading

Operator overloading allows you to define custom behavior for operators when used with user-defined classes. It's like teaching the '+' operator how to add two custom objects, such as complex numbers or vectors.

**Code Example:**

```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imaginary;
    
public:
    // Constructors
    Complex() : real(0), imaginary(0) {}
    Complex(double r) : real(r), imaginary(0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}
    
    // Getter methods
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    
    // Arithmetic operators
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }
    
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImag = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImag);
    }
    
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        if (denominator == 0) {
            throw runtime_error("Division by zero!");
        }
        double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
        double newImag = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(newReal, newImag);
    }
    
    // Unary operators
    Complex operator-() const {
        return Complex(-real, -imaginary);
    }
    
    Complex operator+() const {
        return *this;
    }
    
    // Assignment operators
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }
    
    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imaginary -= other.imaginary;
        return *this;
    }
    
    // Comparison operators
    bool operator==(const Complex& other) const {
        return (abs(real - other.real) < 1e-9) && (abs(imaginary - other.imaginary) < 1e-9);
    }
    
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    
    // Stream operators (friend functions)
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imaginary >= 0) {
            os << c.real << " + " << c.imaginary << "i";
        } else {
            os << c.real << " - " << abs(c.imaginary) << "i";
        }
        return os;
    }
    
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imaginary;
        return is;
    }
    
    // Utility methods
    double magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }
    
    Complex conjugate() const {
        return Complex(real, -imaginary);
    }
};

// Example of a Vector3D class with operator overloading
class Vector3D {
private:
    double x, y, z;
    
public:
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
    
    // Arithmetic operators
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }
    
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }
    
    // Scalar multiplication
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }
    
    // Dot product
    double operator*(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
    // Cross product
    Vector3D operator^(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
    
    // Array subscript operator
    double& operator[](int index) {
        switch(index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw out_of_range("Index out of range");
        }
    }
    
    const double& operator[](int index) const {
        switch(index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw out_of_range("Index out of range");
        }
    }
    
    // Stream operator
    friend ostream& operator<<(ostream& os, const Vector3D& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    
    double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }
};

int main() {
    cout << "=== Operator Overloading Demo ===" << endl;
    
    cout << "\n1. Complex Number Operations:" << endl;
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;
    
    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << product << endl;
    cout << "c1 / c2 = " << quotient << endl;
    
    cout << "Magnitude of c1: " << c1.magnitude() << endl;
    cout << "Conjugate of c1: " << c1.conjugate() << endl;
    
    cout << "\n2. Vector3D Operations:" << endl;
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    
    Vector3D vSum = v1 + v2;
    Vector3D vDiff = v1 - v2;
    Vector3D vScaled = v1 * 2.5;
    double dotProduct = v1 * v2;
    Vector3D crossProduct = v1 ^ v2;
    
    cout << "v1 + v2 = " << vSum << endl;
    cout << "v1 - v2 = " << vDiff << endl;
    cout << "v1 * 2.5 = " << vScaled << endl;
    cout << "v1 · v2 = " << dotProduct << endl;
    cout << "v1 × v2 = " << crossProduct << endl;
    
    cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << ", v1[2] = " << v1[2] << endl;
    
    return 0;
}
```

### 1.3 OOP Best Practices and Interview Tips

**Key Interview Questions and Concepts:**

1. **What is the difference between public, private, and protected access specifiers?**
   - Public: Accessible from anywhere
   - Private: Accessible only within the same class
   - Protected: Accessible within the class and its derived classes

2. **What is the difference between function overloading and function overriding?**
   - Overloading: Same function name, different parameters (compile-time)
   - Overriding: Redefining virtual functions in derived classes (runtime)

3. **Why do we need virtual destructors?**
   - To ensure proper cleanup when deleting objects through base class pointers

4. **What is the diamond problem in multiple inheritance?**
   - When a class inherits from two classes that have a common base class
   - Solved using virtual inheritance

**Common Pitfalls to Avoid:**
- Forgetting virtual destructors in base classes
- Not understanding the difference between early and late binding
- Misusing public inheritance vs. composition
- Not properly handling memory management in inheritance hierarchies

This comprehensive coverage of OOP concepts provides a solid foundation for understanding object-oriented programming in C++. The examples demonstrate real-world applications and common patterns you'll encounter in technical interviews.

---


## 2. 📚 Standard Template Library (STL)

The Standard Template Library (STL) is a powerful set of C++ template classes that provide generic algorithms and data structures. It's a cornerstone of modern C++ programming, offering efficient and reusable components for common programming tasks. Using STL correctly can significantly improve code readability, maintainability, and performance.

### 2.1 Containers

Containers are objects that store data. They are classified into sequence containers, associative containers, and container adapters.

#### 2.1.1 `std::vector`

`std::vector` is a dynamic array that can grow or shrink in size. It stores elements in contiguous memory locations, allowing for efficient random access.

**Use Cases:**
- When you need a dynamic array that can change size.
- When you need efficient random access to elements.
- When you need to frequently add/remove elements from the end.

**Performance Notes:**
- **Accessing elements:** O(1) (constant time) due to contiguous memory.
- **Adding/removing at end:** Amortized O(1) (constant time). When capacity is exceeded, a new larger array is allocated, and elements are copied, which can be O(N) in worst case.
- **Adding/removing at beginning/middle:** O(N) (linear time) because elements need to be shifted.

**Code Examples:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << name << ": [ ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}

int main() {
    // Example 1: Basic operations
    std::vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    printVector(vec1, "vec1 after push_back");

    std::cout << "Size of vec1: " << vec1.size() << "\n";
    std::cout << "Element at index 1: " << vec1[1] << "\n";

    vec1.pop_back();
    printVector(vec1, "vec1 after pop_back");

    // Example 2: Initialization and iteration
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    printVector(vec2, "vec2 initialized");

    // Using iterators
    std::cout << "Iterating vec2: ";
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Example 3: Resizing and inserting
    std::vector<int> vec3(5, 0); // Vector of 5 zeros
    printVector(vec3, "vec3 initialized with 5 zeros");

    vec3.resize(3); // Shrink
    printVector(vec3, "vec3 after resize(3)");

    vec3.insert(vec3.begin() + 1, 99); // Insert 99 at index 1
    printVector(vec3, "vec3 after insert");

    vec3.erase(vec3.begin()); // Erase first element
    printVector(vec3, "vec3 after erase");

    // Example 4: Capacity vs Size
    std::vector<int> vec4;
    std::cout << "\nvec4 initial size: " << vec4.size() << ", capacity: " << vec4.capacity() << "\n";
    for (int i = 0; i < 10; ++i) {
        vec4.push_back(i);
        std::cout << "After push_back " << i << ": size: " << vec4.size() << ", capacity: " << vec4.capacity() << "\n";
    }
    vec4.shrink_to_fit(); // Reduce capacity to fit size
    std::cout << "After shrink_to_fit: size: " << vec4.size() << ", capacity: " << vec4.capacity() << "\n";

    return 0;
}
```

#### 2.1.2 `std::set`

`std::set` is an associative container that stores unique elements in a sorted order. It is typically implemented using a self-balancing binary search tree (like a Red-Black Tree).

**Use Cases:**
- Storing unique elements.
- Maintaining elements in sorted order.
- Fast searching, insertion, and deletion of elements.

**Performance Notes:**
- **Search, Insertion, Deletion:** O(log N) (logarithmic time) on average, due to tree structure.
- **Space Complexity:** O(N) (linear time) for storing N elements.

**Code Examples:**

```cpp
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

void printSet(const std::set<int>& s, const std::string& name) {
    std::cout << name << ": { ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << "}\n";
}

int main() {
    // Example 1: Basic insertion and uniqueness
    std::set<int> s1;
    s1.insert(50);
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(10); // Duplicate, will not be inserted
    printSet(s1, "s1 after insertions");

    // Example 2: Searching and deletion
    if (s1.count(30)) {
        std::cout << "30 is in the set.\n";
    }
    if (s1.find(100) == s1.end()) {
        std::cout << "100 is not in the set.\n";
    }

    s1.erase(20);
    printSet(s1, "s1 after erasing 20");

    // Example 3: Initializing from a range
    std::vector<int> nums = {10, 5, 20, 5, 15, 10};
    std::set<int> s2(nums.begin(), nums.end());
    printSet(s2, "s2 initialized from vector");

    // Example 4: Set operations (union, intersection - conceptual)
    std::set<int> s3 = {1, 2, 3, 4};
    std::set<int> s4 = {3, 4, 5, 6};
    
    std::cout << "s3: "; printSet(s3, "");
    std::cout << "s4: "; printSet(s4, "");

    std::cout << "Intersection: { ";
    std::set_intersection(s3.begin(), s3.end(), s4.begin(), s4.end(),
                          std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}\n";

    std::cout << "Union: { ";
    std::set_union(s3.begin(), s3.end(), s4.begin(), s4.end(),
                   std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}\n";

    return 0;
}
```

#### 2.1.3 `std::map`

`std::map` is an associative container that stores key-value pairs in a sorted order based on keys. Like `std::set`, it is typically implemented using a self-balancing binary search tree.

**Use Cases:**
- Storing data as key-value pairs where keys must be unique and sorted.
- Implementing dictionaries or lookup tables.
- When you need efficient retrieval of values based on keys.

**Performance Notes:**
- **Search, Insertion, Deletion:** O(log N) (logarithmic time) on average.
- **Space Complexity:** O(N) (linear time).

**Code Examples:**

```cpp
#include <iostream>
#include <map>
#include <string>

void printMap(const std::map<std::string, int>& m, const std::string& name) {
    std::cout << name << ": { ";
    for (const auto& pair : m) {
        std::cout << pair.first << ":" << pair.second << " ";
    }
    std::cout << "}\n";
}

int main() {
    // Example 1: Basic insertion and access
    std::map<std::string, int> student_scores;
    student_scores["Alice"] = 95;
    student_scores["Bob"] = 88;
    student_scores["Charlie"] = 72;
    student_scores.insert({"David", 90});
    printMap(student_scores, "student_scores after insertions");

    std::cout << "Bob's score: " << student_scores["Bob"] << "\n";

    // Example 2: Checking existence and updating
    if (student_scores.count("Alice")) {
        std::cout << "Alice is in the map.\n";
    }
    if (student_scores.find("Eve") == student_scores.end()) {
        std::cout << "Eve is not in the map.\n";
    }

    student_scores["Alice"] = 98; // Update score
    printMap(student_scores, "student_scores after updating Alice");

    // Example 3: Iterating through a map
    std::cout << "Iterating student_scores:\n";
    for (auto it = student_scores.begin(); it != student_scores.end(); ++it) {
        std::cout << "  Key: " << it->first << ", Value: " << it->second << "\n";
    }

    // Example 4: Deletion
    student_scores.erase("Charlie");
    printMap(student_scores, "student_scores after erasing Charlie");

    return 0;
}
```

#### 2.1.4 `std::unordered_map`

`std::unordered_map` is an associative container that stores key-value pairs in an unsorted order. It is implemented using hash tables, providing average constant-time complexity for operations.

**Use Cases:**
- When you need fast average-case lookup, insertion, and deletion.
- When the order of elements does not matter.
- Implementing hash tables or caches.

**Performance Notes:**
- **Search, Insertion, Deletion:** Average O(1) (constant time). Worst case O(N) (linear time) if many hash collisions occur.
- **Space Complexity:** O(N) (linear time).

**Code Examples:**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

void printUnorderedMap(const std::unordered_map<std::string, int>& m, const std::string& name) {
    std::cout << name << ": { ";
    for (const auto& pair : m) {
        std::cout << pair.first << ":" << pair.second << " ";
    }
    std::cout << "}\n";
}

int main() {
    // Example 1: Basic insertion and access
    std::unordered_map<std::string, int> word_counts;
    word_counts["apple"] = 5;
    word_counts["banana"] = 3;
    word_counts["apple"]++; // Increments count for apple
    word_counts.insert({"orange", 2});
    printUnorderedMap(word_counts, "word_counts after insertions");

    std::cout << "Count of 'apple': " << word_counts["apple"] << "\n";

    // Example 2: Checking existence and deletion
    if (word_counts.count("banana")) {
        std::cout << "'banana' is in the map.\n";
    }
    if (word_counts.find("grape") == word_counts.end()) {
        std::cout << "'grape' is not in the map.\n";
    }

    word_counts.erase("banana");
    printUnorderedMap(word_counts, "word_counts after erasing 'banana'");

    // Example 3: Iterating (order is not guaranteed)
    std::cout << "Iterating word_counts (order is arbitrary):\n";
    for (auto it = word_counts.begin(); it != word_counts.end(); ++it) {
        std::cout << "  Key: " << it->first << ", Value: " << it->second << "\n";
    }

    return 0;
}
```

#### 2.1.5 `std::stack`

`std::stack` is a container adapter that provides LIFO (Last-In, First-Out) functionality. It is typically implemented on top of other sequence containers like `std::deque` (default) or `std::vector`.

**Use Cases:**
- Function call stack management.
- Expression evaluation (infix to postfix conversion).
- Backtracking algorithms.
- Undo/redo functionality.

**Performance Notes:**
- **Push, Pop, Top:** O(1) (constant time) as operations are only at one end.
- **Space Complexity:** O(N) (linear time).

**Code Examples:**

```cpp
#include <iostream>
#include <stack>
#include <string>

void printStack(std::stack<char> s, const std::string& name) {
    std::cout << name << ": [top] -> ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
}

int main() {
    // Example 1: Basic stack operations
    std::stack<char> char_stack;
    char_stack.push('A');
    char_stack.push('B');
    char_stack.push('C');
    printStack(char_stack, "char_stack after pushes");

    std::cout << "Top element: " << char_stack.top() << "\n";
    char_stack.pop();
    printStack(char_stack, "char_stack after pop");

    std::cout << "Is stack empty? " << (char_stack.empty() ? "Yes" : "No") << "\n";
    std::cout << "Stack size: " << char_stack.size() << "\n";

    // Example 2: Parentheses matching
    std::string expression = "{([()])}";
    std::stack<char> paren_stack;
    bool balanced = true;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            paren_stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (paren_stack.empty()) {
                balanced = false;
                break;
            }
            char top_char = paren_stack.top();
            paren_stack.pop();
            if ((c == ')' && top_char != '(') ||
                (c == '}' && top_char != '{') ||
                (c == ']' && top_char != '[')) {
                balanced = false;
                break;
            }
        }
    }
    if (!paren_stack.empty()) balanced = false;

    std::cout << "Expression \"" << expression << "\" is balanced: " << (balanced ? "Yes" : "No") << "\n";

    return 0;
}
```

#### 2.1.6 `std::queue`

`std::queue` is a container adapter that provides FIFO (First-In, First-Out) functionality. It is typically implemented on top of `std::deque` (default) or `std::list`.

**Use Cases:**
- Task scheduling and processing.
- Breadth-First Search (BFS) in graphs.
- Printer queues.
- Buffering data.

**Performance Notes:**
- **Push, Pop, Front, Back:** O(1) (constant time) as operations are only at the ends.
- **Space Complexity:** O(N) (linear time).

**Code Examples:**

```cpp
#include <iostream>
#include <queue>
#include <string>

void printQueue(std::queue<int> q, const std::string& name) {
    std::cout << name << ": [front] -> ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

int main() {
    // Example 1: Basic queue operations
    std::queue<int> int_queue;
    int_queue.push(10);
    int_queue.push(20);
    int_queue.push(30);
    printQueue(int_queue, "int_queue after pushes");

    std::cout << "Front element: " << int_queue.front() << "\n";
    std::cout << "Back element: " << int_queue.back() << "\n";

    int_queue.pop();
    printQueue(int_queue, "int_queue after pop");

    std::cout << "Is queue empty? " << (int_queue.empty() ? "Yes" : "No") << "\n";
    std::cout << "Queue size: " << int_queue.size() << "\n";

    // Example 2: Simple task processing simulation
    std::queue<std::string> tasks;
    tasks.push("Download file");
    tasks.push("Process image");
    tasks.push("Upload data");

    std::cout << "\nProcessing tasks:\n";
    while (!tasks.empty()) {
        std::cout << "  Processing: " << tasks.front() << "\n";
        tasks.pop();
    }
    std::cout << "All tasks processed.\n";

    return 0;
}
```

#### 2.1.7 `std::priority_queue`

`std::priority_queue` is a container adapter that provides a max-heap (by default) or min-heap functionality. Elements are always retrieved in order of their priority (largest element first for max-heap, smallest for min-heap).

**Use Cases:**
- Implementing Dijkstra's algorithm.
- Finding K-largest/smallest elements.
- Event simulation.
- Task scheduling based on priority.

**Performance Notes:**
- **Push, Pop:** O(log N) (logarithmic time) due to heap property maintenance.
- **Top:** O(1) (constant time).
- **Space Complexity:** O(N) (linear time).

**Code Examples:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // For std::greater

void printPriorityQueue(std::priority_queue<int> pq, const std::string& name) {
    std::cout << name << ": [top] -> ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}

void printMinPriorityQueue(std::priority_queue<int, std::vector<int>, std::greater<int>> pq, const std::string& name) {
    std::cout << name << ": [top] -> ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}

int main() {
    // Example 1: Max-heap (default)
    std::priority_queue<int> max_pq;
    max_pq.push(10);
    max_pq.push(30);
    max_pq.push(20);
    max_pq.push(5);
    printPriorityQueue(max_pq, "max_pq after pushes");

    std::cout << "Top element: " << max_pq.top() << "\n";
    max_pq.pop();
    printPriorityQueue(max_pq, "max_pq after pop");

    // Example 2: Min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(5);
    printMinPriorityQueue(min_pq, "min_pq after pushes");

    std::cout << "Top element: " << min_pq.top() << "\n";
    min_pq.pop();
    printMinPriorityQueue(min_pq, "min_pq after pop");

    // Example 3: K-largest elements (using max-heap)
    std::vector<int> data = {3, 2, 1, 5, 6, 4, 7, 8, 9};
    int k = 3;
    std::priority_queue<int> k_largest_pq;
    for (int x : data) {
        k_largest_pq.push(x);
    }
    std::cout << "\n" << k << " largest elements: ";
    for (int i = 0; i < k; ++i) {
        std::cout << k_largest_pq.top() << " ";
        k_largest_pq.pop();
    }
    std::cout << "\n";

    return 0;
}
```

#### 2.1.8 `std::deque`

`std::deque` (double-ended queue) is a sequence container that allows efficient insertion and deletion at both the beginning and the end. It is similar to `std::vector` but provides constant time complexity for operations at both ends.

**Use Cases:**
- When you need a dynamic array that supports efficient additions/removals from both ends.
- Implementing queues and stacks (it's the default underlying container for `std::queue` and `std::stack`).
- Sliding window problems where elements are added/removed from both ends.

**Performance Notes:**
- **Accessing elements:** O(1) (constant time).
- **Adding/removing at beginning/end:** O(1) (constant time).
- **Adding/removing in middle:** O(N) (linear time).
- **Space Complexity:** O(N) (linear time).

**Code Examples:**

```cpp
#include <iostream>
#include <deque>
#include <algorithm>

void printDeque(const std::deque<int>& d, const std::string& name) {
    std::cout << name << ": [ ";
    for (int x : d) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}

int main() {
    // Example 1: Basic operations
    std::deque<int> dq1;
    dq1.push_back(10);
    dq1.push_front(5);
    dq1.push_back(15);
    dq1.push_front(1);
    printDeque(dq1, "dq1 after pushes");

    std::cout << "Front element: " << dq1.front() << "\n";
    std::cout << "Back element: " << dq1.back() << "\n";
    std::cout << "Element at index 2: " << dq1[2] << "\n";

    dq1.pop_front();
    dq1.pop_back();
    printDeque(dq1, "dq1 after pops");

    // Example 2: Inserting and erasing in the middle
    std::deque<int> dq2 = {1, 2, 3, 4, 5};
    printDeque(dq2, "dq2 initialized");

    dq2.insert(dq2.begin() + 2, 99); // Insert 99 at index 2
    printDeque(dq2, "dq2 after insert");

    dq2.erase(dq2.begin() + 1); // Erase element at index 1
    printDeque(dq2, "dq2 after erase");

    // Example 3: Using deque as a sliding window (conceptual)
    std::deque<int> window;
    std::vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::cout << "\nSliding window (max element):\n";
    for (int i = 0; i < arr.size(); ++i) {
        // Remove elements from front that are out of window
        if (!window.empty() && window.front() == i - k) {
            window.pop_front();
        }
        // Remove elements from back that are smaller than current element
        while (!window.empty() && arr[window.back()] <= arr[i]) {
            window.pop_back();
        }
        window.push_back(i);

        if (i >= k - 1) {
            std::cout << arr[window.front()] << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
```

### 2.2 Algorithms

STL also provides a rich set of algorithms that operate on containers. These algorithms are generic and work with iterators, making them highly flexible.

**Commonly Used Algorithms:**
- `std::sort`: Sorts elements in a range.
- `std::find`: Searches for an element in a range.
- `std::min_element`, `std::max_element`: Finds the minimum/maximum element.
- `std::accumulate`: Sums up elements in a range.
- `std::for_each`: Applies a function to each element.
- `std::transform`: Applies a function to elements and stores results in another range.
- `std::copy`: Copies elements from one range to another.
- `std::unique`: Removes consecutive duplicate elements.

**Code Example - STL Algorithms:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate
#include <functional> // For std::greater

void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << name << ": [ ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> vec = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    printVector(vec, "Original vector");

    // 1. std::sort
    std::sort(vec.begin(), vec.end());
    printVector(vec, "Sorted vector (ascending)");

    std::sort(vec.begin(), vec.end(), std::greater<int>());
    printVector(vec, "Sorted vector (descending)");

    // 2. std::find
    auto it_find = std::find(vec.begin(), vec.end(), 5);
    if (it_find != vec.end()) {
        std::cout << "Found 5 at index: " << std::distance(vec.begin(), it_find) << "\n";
    } else {
        std::cout << "5 not found.\n";
    }

    // 3. std::min_element and std::max_element
    std::cout << "Min element: " << *std::min_element(vec.begin(), vec.end()) << "\n";
    std::cout << "Max element: " << *std::max_element(vec.begin(), vec.end()) << "\n";

    // 4. std::accumulate
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of elements: " << sum << "\n";

    // 5. std::for_each
    std::cout << "Elements doubled: ";
    std::for_each(vec.begin(), vec.end(), [](int& n){ n *= 2; });
    printVector(vec, "");

    // 6. std::transform
    std::vector<int> vec_squared(vec.size());
    std::transform(vec.begin(), vec.end(), vec_squared.begin(), [](int n){ return n * n; });
    printVector(vec_squared, "Elements squared");

    // 7. std::copy
    std::vector<int> vec_copy(vec.size());
    std::copy(vec.begin(), vec.end(), vec_copy.begin());
    printVector(vec_copy, "Copied vector");

    // 8. std::unique (requires sorted range)
    std::vector<int> duplicates = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    printVector(duplicates, "Vector with duplicates");
    auto last = std::unique(duplicates.begin(), duplicates.end());
    duplicates.erase(last, duplicates.end());
    printVector(duplicates, "Vector after unique and erase");

    return 0;
}
```

### 2.3 Iterators

Iterators are generalizations of pointers that allow you to traverse through elements of containers. They provide a uniform way to access elements regardless of the container type.

**Types of Iterators:**
- **Input Iterators:** Can read elements in a forward direction (e.g., `std::istream_iterator`).
- **Output Iterators:** Can write elements in a forward direction (e.g., `std::ostream_iterator`).
- **Forward Iterators:** Can read and write elements in a forward direction.
- **Bidirectional Iterators:** Can read and write elements in both forward and backward directions (e.g., `std::list::iterator`, `std::set::iterator`).
- **Random Access Iterators:** Can read and write elements, and move an arbitrary number of positions in constant time (e.g., `std::vector::iterator`, raw pointers).

**Code Example - Iterators:**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <set>

int main() {
    // Vector iterators (Random Access Iterators)
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "Vector elements using iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // List iterators (Bidirectional Iterators)
    std::list<int> lst = {1, 2, 3, 4, 5};
    std::cout << "List elements using iterators: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Set iterators (Bidirectional Iterators)
    std::set<int> s = {100, 200, 300};
    std::cout << "Set elements using iterators: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Reverse iterators
    std::cout << "Vector elements in reverse: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    return 0;
}
```

This section provides a comprehensive overview of the most commonly used STL containers and algorithms, along with their performance characteristics and practical examples. Mastering STL is crucial for competitive programming and efficient C++ development.

---


## 3. 🔄 Important Data Structures

Data structures are fundamental to efficient algorithm design and problem-solving. They provide ways to organize and store data to facilitate specific operations. Understanding the strengths and weaknesses of various data structures is crucial for writing optimized code.

### 3.1 Linked Lists

A linked list is a linear data structure where elements are not stored at contiguous memory locations. Instead, each element (node) points to the next element in the sequence. This non-contiguous storage allows for efficient insertions and deletions anywhere in the list, unlike arrays.

**Advantages:**
- Dynamic size: Can grow or shrink as needed.
- Efficient insertions and deletions: O(1) if the position is known, O(N) otherwise.

**Disadvantages:**
- No random access: To access an element, you must traverse from the beginning, making access O(N).
- Extra memory for pointers.

#### 3.1.1 Singly Linked List

A singly linked list is the simplest form, where each node contains data and a pointer to the next node.

**Code Example:**

```cpp
#include <iostream>

// Node structure for Singly Linked List
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Singly Linked List class
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert after a specific value
    bool insertAfter(T key, T val) {
        Node<T>* current = head;
        while (current != nullptr && current->data != key) {
            current = current->next;
        }
        if (current == nullptr) {
            return false; // Key not found
        }
        Node<T>* newNode = new Node<T>(val);
        newNode->next = current->next;
        current->next = newNode;
        return true;
    }

    // Delete a node by value
    bool deleteNode(T key) {
        if (head == nullptr) {
            return false; // List is empty
        }
        if (head->data == key) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != key) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return false; // Key not found
        }
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    // Search for a value
    bool search(T val) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Display the list
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    SinglyLinkedList<int> sll;
    sll.insertAtEnd(10);
    sll.insertAtBeginning(5);
    sll.insertAtEnd(20);
    sll.insertAfter(10, 15);
    sll.display(); // Output: 5 -> 10 -> 15 -> 20 -> nullptr

    std::cout << "Searching for 15: " << (sll.search(15) ? "Found" : "Not Found") << "\n";
    std::cout << "Searching for 25: " << (sll.search(25) ? "Found" : "Not Found") << "\n";

    sll.deleteNode(10);
    sll.display(); // Output: 5 -> 15 -> 20 -> nullptr

    sll.deleteNode(5);
    sll.display(); // Output: 15 -> 20 -> nullptr

    sll.deleteNode(20);
    sll.display(); // Output: 15 -> nullptr

    sll.deleteNode(15);
    sll.display(); // Output: nullptr

    return 0;
}
```

#### 3.1.2 Doubly Linked List

A doubly linked list allows traversal in both forward and backward directions. Each node contains data, a pointer to the next node, and a pointer to the previous node.

**Code Example:**

```cpp
#include <iostream>

// Node structure for Doubly Linked List
template <typename T>
struct DNode {
    T data;
    DNode* prev;
    DNode* next;

    DNode(T val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
template <typename T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
        DNode<T>* current = head;
        while (current != nullptr) {
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(T val) {
        DNode<T>* newNode = new DNode<T>(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(T val) {
        DNode<T>* newNode = new DNode<T>(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a node by value
    bool deleteNode(T key) {
        if (head == nullptr) {
            return false; // List is empty
        }

        DNode<T>* current = head;
        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current == nullptr) {
            return false; // Key not found
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        if (current == head) {
            head = current->next;
        }
        if (current == tail) {
            tail = current->prev;
        }

        delete current;
        return true;
    }

    // Display the list forward
    void displayForward() const {
        DNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Display the list backward
    void displayBackward() const {
        DNode<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    DoublyLinkedList<int> dll;
    dll.insertAtEnd(10);
    dll.insertAtBeginning(5);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(1);
    dll.displayForward();  // Output: 1 <-> 5 <-> 10 <-> 20 <-> nullptr
    dll.displayBackward(); // Output: 20 <-> 10 <-> 5 <-> 1 <-> nullptr

    dll.deleteNode(10);
    dll.displayForward();  // Output: 1 <-> 5 <-> 20 <-> nullptr
    dll.displayBackward(); // Output: 20 <-> 5 <-> 1 <-> nullptr

    dll.deleteNode(1);
    dll.displayForward();  // Output: 5 <-> 20 <-> nullptr

    dll.deleteNode(20);
    dll.displayForward();  // Output: 5 <-> nullptr

    dll.deleteNode(5);
    dll.displayForward();  // Output: nullptr

    return 0;
}
```

#### 3.1.3 Cycle Detection in Linked List

Detecting cycles (loops) in a linked list is a common interview problem. Floyd's Cycle-Finding Algorithm (also known as the 


tortoise and hare algorithm) is a popular and efficient method for this.

**Algorithm:**
1. Initialize two pointers, `slow` and `fast`, both pointing to the head of the list.
2. Move `slow` one step at a time and `fast` two steps at a time.
3. If there is a cycle, `fast` will eventually meet `slow`.
4. If `fast` reaches `nullptr` or `fast->next` reaches `nullptr`, there is no cycle.

**Code Example:**

```cpp
#include <iostream>

// Node structure for Linked List
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

class LinkedListCycleDetector {
public:
    // Function to detect a cycle in a linked list
    bool hasCycle(Node<int>* head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // No cycle if list is empty or has only one node
        }

        Node<int>* slow = head;
        Node<int>* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
    }

    // Function to find the starting node of the cycle
    Node<int>* detectCycleStart(Node<int>* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        Node<int>* slow = head;
        Node<int>* fast = head;
        bool cycle_exists = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle_exists = true;
                break;
            }
        }

        if (!cycle_exists) {
            return nullptr; // No cycle
        }

        // Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow; // Start of the cycle
    }

    // Function to find the length of the cycle
    int detectCycleLength(Node<int>* head) {
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }

        Node<int>* slow = head;
        Node<int>* fast = head;
        bool cycle_exists = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle_exists = true;
                break;
            }
        }

        if (!cycle_exists) {
            return 0; // No cycle
        }

        // Calculate length of the cycle
        int length = 0;
        Node<int>* current = slow;
        do {
            current = current->next;
            length++;
        } while (current != slow);

        return length;
    }
};

int main() {
    // Create a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle)
    Node<int>* head = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    Node<int>* node5 = new Node<int>(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3; // Creates a cycle

    LinkedListCycleDetector detector;

    std::cout << "Has cycle? " << (detector.hasCycle(head) ? "Yes" : "No") << "\n";

    Node<int>* cycleStart = detector.detectCycleStart(head);
    if (cycleStart) {
        std::cout << "Cycle starts at node with data: " << cycleStart->data << "\n";
    } else {
        std::cout << "No cycle detected.\n";
    }

    std::cout << "Cycle length: " << detector.detectCycleLength(head) << "\n";

    // Create a linked list without a cycle: 1 -> 2 -> 3
    Node<int>* head_no_cycle = new Node<int>(1);
    head_no_cycle->next = new Node<int>(2);
    head_no_cycle->next->next = new Node<int>(3);

    std::cout << "\nHas cycle (no cycle)? " << (detector.hasCycle(head_no_cycle) ? "Yes" : "No") << "\n";

    // Clean up memory (for lists without cycles)
    Node<int>* current = head_no_cycle;
    while (current != nullptr) {
        Node<int>* temp = current;
        current = current->next;
        delete temp;
    }

    // Note: For the cyclic list, manual cleanup is tricky. In a real scenario,
    // you'd typically break the cycle before deleting or use smart pointers.
    // For this example, we'll leave the cyclic list as is for simplicity after demonstration.

    return 0;
}
```

### 3.2 Stacks

A stack is a linear data structure that follows the Last-In, First-Out (LIFO) principle. Think of a stack of plates: you can only add a new plate to the top, and you can only remove the top plate.

**Key Operations:**
- `push()`: Adds an element to the top of the stack.
- `pop()`: Removes the top element from the stack.
- `top()`: Returns the top element without removing it.
- `empty()`: Checks if the stack is empty.
- `size()`: Returns the number of elements in the stack.

**Use Cases:**
- Function call management (recursion).
- Expression evaluation (infix to postfix/prefix conversion).
- Backtracking algorithms.
- Undo/redo functionality in applications.

**Implementation (using `std::vector` as underlying storage):**

```cpp
#include <iostream>
#include <vector>
#include <stdexcept> // For std::out_of_range

template <typename T>
class MyStack {
private:
    std::vector<T> data;

public:
    MyStack() {}

    void push(T val) {
        data.push_back(val);
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty, cannot pop.");
        }
        data.pop_back();
    }

    T top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty, no top element.");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    void display() const {
        if (empty()) {
            std::cout << "Stack: [empty]\n";
            return;
        }
        std::cout << "Stack: [top] -> ";
        for (int i = data.size() - 1; i >= 0; --i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MyStack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Output: Stack: [top] -> 30 20 10 

    std::cout << "Top element: " << s.top() << "\n"; // Output: Top element: 30
    s.pop();
    s.display(); // Output: Stack: [top] -> 20 10 

    std::cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << "\n"; // Output: Is stack empty? No
    std::cout << "Stack size: " << s.size() << "\n"; // Output: Stack size: 2

    s.pop();
    s.pop();
    std::cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << "\n"; // Output: Is stack empty? Yes

    try {
        s.pop(); // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
```

### 3.3 Queues

A queue is a linear data structure that follows the First-In, First-Out (FIFO) principle. Think of a line at a ticket counter: the first person in line is the first to be served.

**Key Operations:**
- `enqueue()` (or `push()`): Adds an element to the back (rear) of the queue.
- `dequeue()` (or `pop()`): Removes the element from the front of the queue.
- `front()`: Returns the front element without removing it.
- `back()`: Returns the back element without removing it.
- `empty()`: Checks if the queue is empty.
- `size()`: Returns the number of elements in the queue.

#### 3.3.1 Normal Queue (using `std::list` or `std::deque` as underlying storage)

**Implementation (using `std::list`):**

```cpp
#include <iostream>
#include <list>
#include <stdexcept>

template <typename T>
class MyQueue {
private:
    std::list<T> data;

public:
    MyQueue() {}

    void enqueue(T val) {
        data.push_back(val);
    }

    void dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty, cannot dequeue.");
        }
        data.pop_front();
    }

    T front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty, no front element.");
        }
        return data.front();
    }

    T back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty, no back element.");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    void display() const {
        if (empty()) {
            std::cout << "Queue: [empty]\n";
            return;
        }
        std::cout << "Queue: [front] -> ";
        for (const T& val : data) {
            std::cout << val << " ";
        }
        std::cout << "<- [back]\n";
    }
};

int main() {
    MyQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: Queue: [front] -> 10 20 30 <- [back]

    std::cout << "Front element: " << q.front() << "\n"; // Output: Front element: 10
    std::cout << "Back element: " << q.back() << "\n";   // Output: Back element: 30

    q.dequeue();
    q.display(); // Output: Queue: [front] -> 20 30 <- [back]

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n"; // Output: Is queue empty? No
    std::cout << "Queue size: " << q.size() << "\n"; // Output: Queue size: 2

    q.dequeue();
    q.dequeue();
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n"; // Output: Is queue empty? Yes

    try {
        q.front(); // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
```

#### 3.3.2 Circular Queue

A circular queue is a linear data structure in which the operations are performed based on FIFO principle and the last position is connected back to the first position to make a circle. It efficiently utilizes memory by reusing empty slots.

**Implementation (using array):**

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class CircularQueue {
private:
    std::vector<T> data;
    int front_idx;
    int rear_idx;
    int capacity;
    int current_size;

public:
    CircularQueue(int size) : capacity(size), front_idx(-1), rear_idx(-1), current_size(0) {
        data.resize(size);
    }

    bool enqueue(T val) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot enqueue " << val << ".\n";
            return false;
        }
        if (isEmpty()) {
            front_idx = 0;
        }
        rear_idx = (rear_idx + 1) % capacity;
        data[rear_idx] = val;
        current_size++;
        return true;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty, cannot dequeue.");
        }
        T val = data[front_idx];
        if (front_idx == rear_idx) { // Last element
            front_idx = -1;
            rear_idx = -1;
        } else {
            front_idx = (front_idx + 1) % capacity;
        }
        current_size--;
        return val;
    }

    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty, no front element.");
        }
        return data[front_idx];
    }

    T back() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty, no back element.");
        }
        return data[rear_idx];
    }

    bool isEmpty() const {
        return current_size == 0;
    }

    bool isFull() const {
        return current_size == capacity;
    }

    int size() const {
        return current_size;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Circular Queue: [empty]\n";
            return;
        }
        std::cout << "Circular Queue: [front] -> ";
        int count = 0;
        int i = front_idx;
        while (count < current_size) {
            std::cout << data[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        std::cout << "<- [back]\n";
    }
};

int main() {
    CircularQueue<int> cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display(); // Output: Circular Queue: [front] -> 10 20 30 <- [back]

    std::cout << "Dequeued: " << cq.dequeue() << "\n"; // Output: Dequeued: 10
    cq.display(); // Output: Circular Queue: [front] -> 20 30 <- [back]

    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); // This will fail as queue is full
    cq.display(); // Output: Circular Queue: [front] -> 20 30 40 50 <- [back]

    std::cout << "Front: " << cq.front() << ", Back: " << cq.back() << "\n";

    return 0;
}
```

#### 3.3.3 Deque (Double-Ended Queue)

A deque (double-ended queue) is a linear data structure that allows insertion and deletion at both ends. It combines the features of both stacks and queues.

**Key Operations:**
- `push_front()`: Adds an element to the front.
- `push_back()`: Adds an element to the back.
- `pop_front()`: Removes an element from the front.
- `pop_back()`: Removes an element from the back.
- `front()`: Returns the front element.
- `back()`: Returns the back element.
- `empty()`: Checks if the deque is empty.
- `size()`: Returns the number of elements.

**Implementation (using `std::deque` from STL is recommended, but here's a conceptual array-based one for understanding):**

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class MyDeque {
private:
    std::vector<T> data;
    int front_idx;
    int rear_idx;
    int capacity;
    int current_size;

public:
    MyDeque(int size) : capacity(size), front_idx(-1), rear_idx(-1), current_size(0) {
        data.resize(size);
    }

    bool push_front(T val) {
        if (isFull()) {
            std::cout << "Deque is full! Cannot push_front " << val << ".\n";
            return false;
        }
        if (isEmpty()) {
            front_idx = 0;
            rear_idx = 0;
        } else {
            front_idx = (front_idx - 1 + capacity) % capacity;
        }
        data[front_idx] = val;
        current_size++;
        return true;
    }

    bool push_back(T val) {
        if (isFull()) {
            std::cout << "Deque is full! Cannot push_back " << val << ".\n";
            return false;
        }
        if (isEmpty()) {
            front_idx = 0;
            rear_idx = 0;
        } else {
            rear_idx = (rear_idx + 1) % capacity;
        }
        data[rear_idx] = val;
        current_size++;
        return true;
    }

    T pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty, cannot pop_front.");
        }
        T val = data[front_idx];
        if (front_idx == rear_idx) {
            front_idx = -1;
            rear_idx = -1;
        } else {
            front_idx = (front_idx + 1) % capacity;
        }
        current_size--;
        return val;
    }

    T pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty, cannot pop_back.");
        }
        T val = data[rear_idx];
        if (front_idx == rear_idx) {
            front_idx = -1;
            rear_idx = -1;
        } else {
            rear_idx = (rear_idx - 1 + capacity) % capacity;
        }
        current_size--;
        return val;
    }

    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty, no front element.");
        }
        return data[front_idx];
    }

    T back() const {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty, no back element.");
        }
        return data[rear_idx];
    }

    bool isEmpty() const {
        return current_size == 0;
    }

    bool isFull() const {
        return current_size == capacity;
    }

    int size() const {
        return current_size;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Deque: [empty]\n";
            return;
        }
        std::cout << "Deque: [front] -> ";
        int count = 0;
        int i = front_idx;
        while (count < current_size) {
            std::cout << data[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        std::cout << "<- [back]\n";
    }
};

int main() {
    MyDeque<int> dq(5);
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);
    dq.push_front(1);
    dq.display(); // Output: Deque: [front] -> 1 5 10 20 <- [back]

    std::cout << "Popped from front: " << dq.pop_front() << "\n"; // Output: Popped from front: 1
    std::cout << "Popped from back: " << dq.pop_back() << "\n";   // Output: Popped from back: 20
    dq.display(); // Output: Deque: [front] -> 5 10 <- [back]

    dq.push_back(30);
    dq.push_front(2);
    dq.display(); // Output: Deque: [front] -> 2 5 10 30 <- [back]

    return 0;
}
```

### 3.4 Strings

Strings are sequences of characters. In C++, strings can be handled using C-style character arrays (`char[]`) or the `std::string` class. `std::string` is generally preferred due to its safety, flexibility, and rich set of member functions.

#### 3.4.1 Basic Manipulations (`std::string`)

**Code Example:**

```cpp
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // 1. Declaration and Initialization
    std::string s1 = "Hello";
    std::string s2("World");
    std::string s3(5, 'A'); // "AAAAA"
    std::string s4 = s1 + " " + s2; // Concatenation
    std::cout << "s1: " << s1 << ", s2: " << s2 << ", s3: " << s3 << ", s4: " << s4 << "\n";

    // 2. Accessing characters
    std::cout << "First char of s1: " << s1[0] << "\n";
    std::cout << "Last char of s1: " << s1.back() << "\n";

    // 3. Length and Capacity
    std::cout << "Length of s4: " << s4.length() << "\n";
    std::cout << "Size of s4: " << s4.size() << "\n";
    std::cout << "Capacity of s4: " << s4.capacity() << "\n";

    // 4. Appending and Inserting
    s1.append(" C++"); // s1 is now "Hello C++"
    std::cout << "s1 after append: " << s1 << "\n";

    s2.insert(0, "Great "); // s2 is now "Great World"
    std::cout << "s2 after insert: " << s2 << "\n";

    // 5. Erasing and Replacing
    s4.erase(6, 5); // Erase "World" from "Hello World"
    std::cout << "s4 after erase: " << s4 << "\n"; // Output: Hello 

    s4.replace(0, 5, "Hi"); // Replace "Hello" with "Hi"
    std::cout << "s4 after replace: " << s4 << "\n"; // Output: Hi 

    // 6. Substring
    std::string sub = s4.substr(3, 2); // Get substring from index 3, length 2
    std::cout << "Substring of s4: " << sub << "\n"; // Output: i 

    // 7. Finding substrings
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::string pattern = "fox";
    size_t pos = text.find(pattern);
    if (pos != std::string::npos) {
        std::cout << "Pattern \"" << pattern << "\" found at index: " << pos << "\n";
    } else {
        std::cout << "Pattern not found.\n";
    }

    // 8. Comparison
    std::string str_a = "apple";
    std::string str_b = "banana";
    std::string str_c = "apple";

    std::cout << "str_a == str_b: " << (str_a == str_b ? "True" : "False") << "\n";
    std::cout << "str_a == str_c: " << (str_a == str_c ? "True" : "False") << "\n";
    std::cout << "str_a < str_b: " << (str_a < str_b ? "True" : "False") << "\n";

    // 9. Iterators
    std::cout << "s1 using iterators: ";
    for (char ch : s1) {
        std::cout << ch << " ";
    }
    std::cout << "\n";

    // 10. Conversion to C-style string
    const char* c_str = s1.c_str();
    std::cout << "C-style string from s1: " << c_str << "\n";

    return 0;
}
```

#### 3.4.2 Pattern Matching (Naive Algorithm)

Pattern matching involves finding occurrences of a smaller string (pattern) within a larger string (text). The naive approach is straightforward but can be inefficient for large strings.

**Algorithm:**
1. Iterate through the text from the first character up to `text.length() - pattern.length()`.
2. For each character in the text, compare the substring of the text (of length `pattern.length()`) with the pattern.
3. If they match, an occurrence is found.

**Time Complexity:** O((N-M+1) * M), where N is text length, M is pattern length. In worst case, O(N*M).

**Code Example:**

```cpp
#include <iostream>
#include <string>
#include <vector>

// Naive pattern matching function
std::vector<int> naivePatternSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return occurrences; // Empty pattern matches at every position conceptually
    if (n < m) return occurrences; // Pattern longer than text

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) { // If pattern found
            occurrences.push_back(i);
        }
    }
    return occurrences;
}

int main() {
    std::string text1 = "ABABDABACDABABCABAB";
    std::string pattern1 = "ABABCABAB";
    std::vector<int> result1 = naivePatternSearch(text1, pattern1);
    std::cout << "Text: \"" << text1 << "\"\nPattern: \"" << pattern1 << "\"\n";
    if (result1.empty()) {
        std::cout << "No occurrences found.\n";
    } else {
        std::cout << "Occurrences found at indices: ";
        for (int idx : result1) {
            std::cout << idx << " ";
        }
        std::cout << "\n";
    }

    std::string text2 = "AAAAA";
    std::string pattern2 = "AA";
    std::vector<int> result2 = naivePatternSearch(text2, pattern2);
    std::cout << "\nText: \"" << text2 << "\"\nPattern: \"" << pattern2 << "\"\n";
    if (result2.empty()) {
        std::cout << "No occurrences found.\n";
    } else {
        std::cout << "Occurrences found at indices: ";
        for (int idx : result2) {
            std::cout << idx << " ";
        }
        std::cout << "\n";
    }

    std::string text3 = "ABC";
    std::string pattern3 = "DEF";
    std::vector<int> result3 = naivePatternSearch(text3, pattern3);
    std::cout << "\nText: \"" << text3 << "\"\nPattern: \"" << pattern3 << "\"\n";
    if (result3.empty()) {
        std::cout << "No occurrences found.\n";
    } else {
        std::cout << "Occurrences found at indices: ";
        for (int idx : result3) {
            std::cout << idx << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

#### 3.4.3 Hashing (for strings - Rolling Hash / Rabin-Karp concept)

String hashing is a technique to convert a string into a numerical value (hash value). This can be used for efficient string comparison, pattern matching, and other string-related problems. The Rabin-Karp algorithm uses a rolling hash to efficiently check for pattern occurrences.

**Concept:**
- Assign a numerical value to each character (e.g., 'a'=1, 'b'=2, ...).
- Calculate a hash value for a string using a polynomial rolling hash function: `hash(S) = (S[0]*p^(k-1) + S[1]*p^(k-2) + ... + S[k-1]*p^0) % m`, where `p` is a prime number and `m` is a large prime modulus.
- For a rolling hash, the hash of the next window can be calculated from the current window's hash in O(1) time.

**Time Complexity:** Average O(N+M), Worst Case O(N*M) (due to hash collisions).

**Code Example (Simplified Rabin-Karp for demonstration):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// A simple Rabin-Karp implementation for demonstration
// Note: For real-world use, choose larger prime numbers for 'p' and 'm'
// and handle potential collisions more robustly.

std::vector<int> rabinKarpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return occurrences;
    if (n < m) return occurrences;

    long long p = 31; // A prime number
    long long mod = 1e9 + 7; // A large prime modulus

    long long pattern_hash = 0;
    long long current_text_hash = 0;
    long long h_pow = 1; // p^(m-1) % mod

    // Calculate p^(m-1) % mod
    for (int i = 0; i < m - 1; ++i) {
        h_pow = (h_pow * p) % mod;
    }

    // Calculate hash for pattern and first window of text
    for (int i = 0; i < m; ++i) {
        pattern_hash = (pattern_hash * p + (pattern[i] - 'a' + 1)) % mod;
        current_text_hash = (current_text_hash * p + (text[i] - 'a' + 1)) % mod;
    }

    // Slide the window over the text
    for (int i = 0; i <= n - m; ++i) {
        // If hashes match, check characters one by one (to handle collisions)
        if (pattern_hash == current_text_hash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                occurrences.push_back(i);
            }
        }

        // Calculate hash for next window
        if (i < n - m) {
            current_text_hash = (current_text_hash - (text[i] - 'a' + 1) * h_pow % mod + mod) % mod;
            current_text_hash = (current_text_hash * p + (text[i + m] - 'a' + 1)) % mod;
        }
    }
    return occurrences;
}

int main() {
    std::string text1 = "ababa";
    std::string pattern1 = "aba";
    std::vector<int> result1 = rabinKarpSearch(text1, pattern1);
    std::cout << "Text: \"" << text1 << "\"\nPattern: \"" << pattern1 << "\"\n";
    if (result1.empty()) {
        std::cout << "No occurrences found.\n";
    } else {
        std::cout << "Occurrences found at indices: ";
        for (int idx : result1) {
            std::cout << idx << " ";
        }
        std::cout << "\n";
    }

    std::string text2 = "geeksforgeeks";
    std::string pattern2 = "geeks";
    std::vector<int> result2 = rabinKarpSearch(text2, pattern2);
    std::cout << "\nText: \"" << text2 << "\"\nPattern: \"" << pattern2 << "\"\n";
    if (result2.empty()) {
        std::cout << "No occurrences found.\n";
    } else {
        std::cout << "Occurrences found at indices: ";
        for (int idx : result2) {
            std::cout << idx << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

### 3.5 Trees

A tree is a non-linear data structure that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node, represented as a set of linked nodes. Trees are widely used for representing hierarchical data, such as file systems, XML/HTML documents, and organizational charts.

**Key Terminology:**
- **Root:** The topmost node in a tree.
- **Child:** A node directly connected to another node when moving away from the root.
- **Parent:** A node directly connected to another node when moving towards the root.
- **Siblings:** Nodes that share the same parent.
- **Leaf:** A node with no children.
- **Edge:** The connection between two nodes.
- **Path:** A sequence of nodes and edges connecting one node to another.
- **Depth:** The length of the path from the root to the node.
- **Height:** The length of the longest path from the node to a leaf.

#### 3.5.1 Tree Traversal

Tree traversal refers to the process of visiting each node in the tree exactly once. There are three common ways to traverse a tree:

1.  **Inorder Traversal (Left, Root, Right):** Typically used with Binary Search Trees (BSTs) to retrieve elements in sorted order.
2.  **Preorder Traversal (Root, Left, Right):** Useful for creating a copy of the tree or for expressing the structure of the tree.
3.  **Postorder Traversal (Left, Right, Root):** Useful for deleting the tree or for evaluating expressions.

**Code Example (Binary Tree Node and Traversal):**

```cpp
#include <iostream>
#include <queue> // For level order traversal

// Node structure for Binary Tree
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTreeTraversals {
public:
    // Inorder Traversal (Left, Root, Right)
    void inorder(TreeNode<int>* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder(TreeNode<int>* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(TreeNode<int>* root) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }

    // Level Order Traversal (Breadth-First Search)
    void levelOrder(TreeNode<int>* root) {
        if (root == nullptr) {
            return;
        }
        std::queue<TreeNode<int>*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode<int>* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    // Helper to create a sample tree
    TreeNode<int>* createSampleTree() {
        TreeNode<int>* root = new TreeNode<int>(1);
        root->left = new TreeNode<int>(2);
        root->right = new TreeNode<int>(3);
        root->left->left = new TreeNode<int>(4);
        root->left->right = new TreeNode<int>(5);
        root->right->left = new TreeNode<int>(6);
        root->right->right = new TreeNode<int>(7);
        return root;
    }

    // Helper to delete the tree (postorder traversal for deletion)
    void deleteTree(TreeNode<int>* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    BinaryTreeTraversals bt_traversals;
    TreeNode<int>* root = bt_traversals.createSampleTree();

    std::cout << "Inorder Traversal: ";
    bt_traversals.inorder(root); // Expected: 4 2 5 1 6 3 7
    std::cout << "\n";

    std::cout << "Preorder Traversal: ";
    bt_traversals.preorder(root); // Expected: 1 2 4 5 3 6 7
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    bt_traversals.postorder(root); // Expected: 4 5 2 6 7 3 1
    std::cout << "\n";

    std::cout << "Level Order Traversal: ";
    bt_traversals.levelOrder(root); // Expected: 1 2 3 4 5 6 7
    std::cout << "\n";

    bt_traversals.deleteTree(root);

    return 0;
}
```

#### 3.5.2 Binary Search Tree (BST) Operations

A Binary Search Tree (BST) is a special type of binary tree where for each node, all values in its left subtree are smaller than the node's value, and all values in its right subtree are larger than the node's value. This property allows for efficient searching, insertion, and deletion.

**Key Operations:**
- **Insertion:** Insert a new node while maintaining the BST property.
- **Deletion:** Delete a node while maintaining the BST property (can be complex, especially for nodes with two children).
- **Search:** Find a node with a specific value.
- **Min/Max:** Find the minimum or maximum value in the BST.

**Time Complexity for balanced BST:** O(log N) for search, insert, delete. Worst case O(N) for skewed trees.

**Code Example (BST):**

```cpp
#include <iostream>

// Node structure for Binary Search Tree
template <typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    BSTNode<int>* root;

    // Helper function for insertion
    BSTNode<int>* insertRecursive(BSTNode<int>* node, int val) {
        if (node == nullptr) {
            return new BSTNode<int>(val);
        }
        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }

    // Helper function for searching
    bool searchRecursive(BSTNode<int>* node, int val) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        if (val < node->data) {
            return searchRecursive(node->left, val);
        } else {
            return searchRecursive(node->right, val);
        }
    }

    // Helper function to find the minimum value node in a subtree
    BSTNode<int>* findMin(BSTNode<int>* node) {
        BSTNode<int>* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function for deletion
    BSTNode<int>* deleteRecursive(BSTNode<int>* node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->data) {
            node->left = deleteRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = deleteRecursive(node->right, val);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                BSTNode<int>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode<int>* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            BSTNode<int>* temp = findMin(node->right);
            node->data = temp->data; // Copy the inorder successor's content to this node
            node->right = deleteRecursive(node->right, temp->data); // Delete the inorder successor
        }
        return node;
    }

    // Helper for inorder traversal (for display)
    void inorderTraversal(BSTNode<int>* node) const {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Helper to delete the entire tree
    void deleteTree(BSTNode<int>* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        deleteTree(root);
    }

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    bool search(int val) const {
        return searchRecursive(root, val);
    }

    void deleteNode(int val) {
        root = deleteRecursive(root, val);
    }

    void displayInorder() const {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << "\n";
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.displayInorder(); // Expected: 20 30 40 50 60 70 80

    std::cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << "\n";
    std::cout << "Searching for 90: " << (bst.search(90) ? "Found" : "Not Found") << "\n";

    std::cout << "\nDeleting 20 (leaf node):\n";
    bst.deleteNode(20);
    bst.displayInorder(); // Expected: 30 40 50 60 70 80

    std::cout << "\nDeleting 70 (node with one child):\n";
    bst.deleteNode(70);
    bst.displayInorder(); // Expected: 30 40 50 60 80

    std::cout << "\nDeleting 50 (root with two children):\n";
    bst.deleteNode(50);
    bst.displayInorder(); // Expected: 30 40 60 80 (or 30 40 50 80 if using predecessor)

    return 0;
}
```

#### 3.5.3 Lowest Common Ancestor (LCA)

The Lowest Common Ancestor (LCA) of two nodes `n1` and `n2` in a tree is the lowest (deepest) node that has both `n1` and `n2` as descendants (where a node can be a descendant of itself).

**Algorithm for BST:**
Since BSTs are ordered, we can efficiently find LCA:
1. If both `n1` and `n2` are smaller than the current node, LCA is in the left subtree.
2. If both `n1` and `n2` are larger than the current node, LCA is in the right subtree.
3. If one is smaller and the other is larger (or one matches the current node), then the current node is the LCA.

**Time Complexity:** O(H), where H is the height of the tree. O(log N) for balanced BST, O(N) for skewed BST.

**Code Example (LCA in BST):**

```cpp
#include <iostream>

// Node structure for Binary Search Tree
template <typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

class LCA_BST {
public:
    // Function to find LCA in a BST
    BSTNode<int>* lowestCommonAncestor(BSTNode<int>* root, int p, int q) {
        if (root == nullptr) {
            return nullptr;
        }

        // If both p and q are smaller than root, LCA is in left subtree
        if (p < root->data && q < root->data) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both p and q are greater than root, LCA is in right subtree
        else if (p > root->data && q > root->data) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // Otherwise, current node is the LCA
        else {
            return root;
        }
    }

    // Helper to create a sample BST
    BSTNode<int>* createSampleBST() {
        BSTNode<int>* root = new BSTNode<int>(6);
        root->left = new BSTNode<int>(2);
        root->right = new BSTNode<int>(8);
        root->left->left = new BSTNode<int>(0);
        root->left->right = new BSTNode<int>(4);
        root->right->left = new BSTNode<int>(7);
        root->right->right = new BSTNode<int>(9);
        root->left->right->left = new BSTNode<int>(3);
        root->left->right->right = new BSTNode<int>(5);
        return root;
    }

    // Helper to delete the tree
    void deleteTree(BSTNode<int>* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    LCA_BST lca_finder;
    BSTNode<int>* root = lca_finder.createSampleBST();

    // Test cases
    int p1 = 2, q1 = 8;
    BSTNode<int>* result1 = lca_finder.lowestCommonAncestor(root, p1, q1);
    std::cout << "LCA of " << p1 << " and " << q1 << " is: " << (result1 ? result1->data : -1) << "\n"; // Expected: 6

    int p2 = 2, q2 = 4;
    BSTNode<int>* result2 = lca_finder.lowestCommonAncestor(root, p2, q2);
    std::cout << "LCA of " << p2 << " and " << q2 << " is: " << (result2 ? result2->data : -1) << "\n"; // Expected: 2

    int p3 = 3, q3 = 5;
    BSTNode<int>* result3 = lca_finder.lowestCommonAncestor(root, p3, q3);
    std::cout << "LCA of " << p3 << " and " << q3 << " is: " << (result3 ? result3->data : -1) << "\n"; // Expected: 4

    int p4 = 7, q4 = 9;
    BSTNode<int>* result4 = lca_finder.lowestCommonAncestor(root, p4, q4);
    std::cout << "LCA of " << p4 << " and " << q4 << " is: " << (result4 ? result4->data : -1) << "\n"; // Expected: 8

    lca_finder.deleteTree(root);

    return 0;
}
```

#### 3.5.4 Diameter of a Binary Tree

The diameter of a binary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

**Algorithm:**
To find the diameter, for each node, we calculate the longest path that passes through it. This path is `height(left_subtree) + height(right_subtree) + 1`. The overall diameter is the maximum of these values across all nodes.

**Time Complexity:** O(N) if height is calculated efficiently (e.g., during a post-order traversal).

**Code Example:**

```cpp
#include <iostream>
#include <algorithm> // For std::max

// Node structure for Binary Tree
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTreeDiameter {
private:
    int max_diameter;

    // Helper function to calculate height and update diameter
    int height(TreeNode<int>* node) {
        if (node == nullptr) {
            return 0;
        }

        int left_height = height(node->left);
        int right_height = height(node->right);

        // Update the maximum diameter found so far
        // Path through current node = left_height + right_height + 1 (for current node itself)
        max_diameter = std::max(max_diameter, left_height + right_height + 1);

        // Return height of the current subtree
        return 1 + std::max(left_height, right_height);
    }

public:
    BinaryTreeDiameter() : max_diameter(0) {}

    int calculateDiameter(TreeNode<int>* root) {
        max_diameter = 0; // Reset for each calculation
        height(root);
        return max_diameter;
    }

    // Helper to create a sample tree
    TreeNode<int>* createSampleTree() {
        TreeNode<int>* root = new TreeNode<int>(1);
        root->left = new TreeNode<int>(2);
        root->right = new TreeNode<int>(3);
        root->left->left = new TreeNode<int>(4);
        root->left->right = new TreeNode<int>(5);
        root->left->left->left = new TreeNode<int>(8);
        root->right->right = new TreeNode<int>(6);
        root->right->right->right = new TreeNode<int>(7);
        return root;
    }

    // Helper to delete the tree
    void deleteTree(TreeNode<int>* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    BinaryTreeDiameter tree_diameter;
    TreeNode<int>* root = tree_diameter.createSampleTree();

    std::cout << "Diameter of the binary tree: " << tree_diameter.calculateDiameter(root) << "\n"; // Expected: 6 (path 8-4-2-1-3-6-7)

    tree_diameter.deleteTree(root);

    // Another example
    TreeNode<int>* root2 = new TreeNode<int>(1);
    root2->left = new TreeNode<int>(2);
    root2->right = new TreeNode<int>(3);
    root2->left->left = new TreeNode<int>(4);
    root2->left->right = new TreeNode<int>(5);

    std::cout << "Diameter of the second binary tree: " << tree_diameter.calculateDiameter(root2) << "\n"; // Expected: 4 (path 4-2-1-3 or 5-2-1-3)

    tree_diameter.deleteTree(root2);

    return 0;
}
```

### 3.6 Graphs

A graph is a non-linear data structure consisting of a finite set of vertices (or nodes) and a set of edges connecting pairs of vertices. Graphs are used to model relationships between objects, such as social networks, road maps, and computer networks.

**Key Terminology:**
- **Vertex (Node):** A fundamental unit of a graph.
- **Edge:** A connection between two vertices.
- **Adjacency:** Two vertices are adjacent if they are connected by an edge.
- **Path:** A sequence of vertices connected by edges.
- **Cycle:** A path that starts and ends at the same vertex.
- **Directed Graph:** Edges have a direction.
- **Undirected Graph:** Edges have no direction.
- **Weighted Graph:** Edges have associated weights or costs.

**Representations:**
1.  **Adjacency Matrix:** A 2D array where `adj[i][j]` is 1 if there's an edge from `i` to `j`, and 0 otherwise. Good for dense graphs, but uses O(V^2) space.
2.  **Adjacency List:** An array of lists, where `adj[i]` contains a list of all vertices adjacent to vertex `i`. Good for sparse graphs, uses O(V+E) space.

**Code Example (Graph Representation - Adjacency List):**

```cpp
#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display the graph
    void printGraph() const {
        for (int i = 0; i < V; ++i) {
            std::cout << "Adjacency list of vertex " << i << ":\n head ";
            for (int neighbor : adj[i]) {
                std::cout << "-> " << neighbor;
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
```

#### 3.6.1 Depth-First Search (DFS)

DFS is an algorithm for traversing or searching tree or graph data structures. It starts at the root (or an arbitrary node) and explores as far as possible along each branch before backtracking.

**Algorithm:**
1. Start at a chosen vertex `s`.
2. Mark `s` as visited and process it.
3. For each unvisited neighbor `v` of `s`, recursively call DFS on `v`.

**Time Complexity:** O(V + E) for adjacency list, O(V^2) for adjacency matrix.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <list>

class GraphDFS {
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    GraphDFS(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start_node) {
        std::vector<bool> visited(V, false);
        std::cout << "DFS Traversal (starting from " << start_node << "): ";
        DFSUtil(start_node, visited);
        std::cout << "\n";
    }
};

int main() {
    GraphDFS g(7); // Graph with 7 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.DFS(0); // Expected: 0 1 3 4 2 5 6 (order might vary based on adjacency list iteration)

    return 0;
}
```

#### 3.6.2 Breadth-First Search (BFS)

BFS is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph), and explores all of the neighbor nodes at the present depth before moving on to the nodes at the next depth level.

**Algorithm:**
1. Start at a chosen vertex `s`.
2. Create a queue and enqueue `s`.
3. Mark `s` as visited.
4. While the queue is not empty:
   a. Dequeue a vertex `u`.
   b. Process `u`.
   c. Enqueue all unvisited neighbors of `u` and mark them as visited.

**Time Complexity:** O(V + E) for adjacency list, O(V^2) for adjacency matrix.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>

class GraphBFS {
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

public:
    GraphBFS(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start_node) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[start_node] = true;
        q.push(start_node);

        std::cout << "BFS Traversal (starting from " << start_node << "): ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << " ";

            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }
};

int main() {
    GraphBFS g(7); // Graph with 7 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.BFS(0); // Expected: 0 1 2 3 4 5 6

    return 0;
}
```

#### 3.6.3 Dijkstra's Algorithm

Dijkstra's algorithm is a single-source shortest path algorithm for a graph with non-negative edge weights. It finds the shortest path from a single source vertex to all other vertices in the graph.

**Algorithm:**
1. Initialize distances to all vertices as infinity and distance to source as 0.
2. Use a priority queue to always extract the vertex with the minimum distance.
3. For each extracted vertex, relax its neighbors (update their distances if a shorter path is found).

**Time Complexity:** O((V + E) log V) using a binary heap (priority queue).

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits> // For std::numeric_limits

const int INF = std::numeric_limits<int>::max();

// Pair to store {distance, vertex}
typedef std::pair<int, int> iPair;

class GraphDijkstra {
private:
    int V; // Number of vertices
    std::vector<std::vector<iPair>> adj; // Adjacency list: {neighbor, weight}

public:
    GraphDijkstra(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    void dijkstra(int start_node) {
        // Min-priority queue to store {distance, vertex}
        std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;

        std::vector<int> dist(V, INF); // Distance from source to i

        dist[start_node] = 0;
        pq.push({0, start_node});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Iterate over all adjacent vertices of u
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                // If there is a shorter path to v through u
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        std::cout << "Shortest distances from source " << start_node << ":\n";
        for (int i = 0; i < V; ++i) {
            std::cout << "  To vertex " << i << ": " << (dist[i] == INF ? "INF" : std::to_string(dist[i])) << "\n";
        }
    }
};

int main() {
    GraphDijkstra g(5); // Graph with 5 vertices
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.dijkstra(0); // Expected shortest paths from 0
    // To vertex 0: 0
    // To vertex 1: 3 (0->2->1)
    // To vertex 2: 1 (0->2)
    // To vertex 3: 4 (0->2->1->3)
    // To vertex 4: 7 (0->2->1->3->4)

    return 0;
}
```

#### 3.6.4 Topological Sort

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering. It is not possible for graphs with cycles.

**Algorithms:**
1.  **Kahn's Algorithm (BFS-based):** Uses in-degrees of vertices.
2.  **DFS-based Algorithm:** Uses a stack to store vertices in the order of their finishing times.

**Time Complexity:** O(V + E).

**Code Example (DFS-based Topological Sort):**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <stack>

class GraphTopoSort {
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list (directed graph)

    void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, Stack);
            }
        }
        Stack.push(v); // Push current vertex to stack after all its neighbors are visited
    }

public:
    GraphTopoSort(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Directed edge from u to v
    }

    void topologicalSort() {
        std::stack<int> Stack;
        std::vector<bool> visited(V, false);

        // Call the recursive helper function for all vertices one by one
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        std::cout << "Topological Sort: ";
        while (!Stack.empty()) {
            std::cout << Stack.top() << " ";
            Stack.pop();
        }
        std::cout << "\n";
    }
};

int main() {
    GraphTopoSort g(6); // Graph with 6 vertices
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort(); // Expected: 5 4 2 3 1 0 (or other valid topological order)

    return 0;
}
```

#### 3.6.5 Union-Find (Disjoint Set Union - DSU)

Union-Find is a data structure that stores a collection of disjoint (non-overlapping) sets. It provides two primary operations:
- **`find(i)`:** Returns the representative (or root) of the set that element `i` belongs to. Used to check if two elements are in the same set.
- **`union(i, j)`:** Merges the sets containing elements `i` and `j` into a single set.

**Optimizations:**
- **Path Compression:** Flattens the tree structure during `find` operations by making every node in the path point directly to the root.
- **Union by Rank/Size:** Attaches the smaller tree under the root of the larger tree (by rank or size) to keep the tree flat.

**Time Complexity:** Nearly constant time (amortized O(α(N)), where α is the inverse Ackermann function, which grows extremely slowly) for `find` and `union` with both optimizations.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::iota

class UnionFind {
private:
    std::vector<int> parent; // parent[i] stores the parent of element i
    std::vector<int> rank;   // rank[i] stores the rank (height) of the tree rooted at i

public:
    UnionFind(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Each element is its own parent initially
        rank.assign(n, 0); // All ranks are 0 initially
    }

    // Find operation with path compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); // Path compression
    }

    // Union operation by rank
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Attach smaller rank tree under root of high rank tree
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++; // If ranks are same, increment rank of new root
            }
        }
    }

    // Check if two elements are in the same set
    bool areInSameSet(int i, int j) {
        return find(i) == find(j);
    }

    void printSets() {
        std::cout << "Current sets (representative for each element):\n";
        for (int i = 0; i < parent.size(); ++i) {
            std::cout << "Element " << i << " -> Root " << find(i) << "\n";
        }
    }
};

int main() {
    UnionFind uf(5); // 5 elements: 0, 1, 2, 3, 4

    std::cout << "Initial state:\n";
    uf.printSets();

    uf.unite(0, 1);
    uf.unite(2, 3);
    std::cout << "\nAfter uniting (0,1) and (2,3):\n";
    uf.printSets();

    std::cout << "Are 0 and 1 in same set? " << (uf.areInSameSet(0, 1) ? "Yes" : "No") << "\n"; // Yes
    std::cout << "Are 0 and 2 in same set? " << (uf.areInSameSet(0, 2) ? "Yes" : "No") << "\n"; // No

    uf.unite(0, 2);
    std::cout << "\nAfter uniting (0,2):\n";
    uf.printSets();

    std::cout << "Are 0 and 3 in same set? " << (uf.areInSameSet(0, 3) ? "Yes" : "No") << "\n"; // Yes

    return 0;
}
```

This section provides a solid foundation in essential data structures, including their implementations and common operations. Mastering these structures is crucial for tackling complex algorithmic problems.

---


## 4. 📌 Essential Algorithms with Practice Problems

Algorithms are step-by-step procedures or formulas for solving a problem. Mastering various algorithmic paradigms is crucial for excelling in coding interviews. This section covers fundamental algorithms, common techniques, and handpicked practice problems with solutions and complexity analysis.

### 4.1 Greedy Algorithms

A greedy algorithm is an algorithmic paradigm that makes the locally optimal choice at each stage with the hope of finding a global optimum solution. It builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit [1, 2].

**Analogy:** Imagine you are trying to collect the most money from a pile of coins. A greedy approach would be to pick the largest denomination coin available at each step, without considering if picking a smaller coin now might lead to a better overall sum later (e.g., if you need exact change for something specific). For some problems, this greedy choice leads to the globally optimal solution, while for others, it does not.

**When to use Greedy Algorithms?**
Greedy algorithms are typically used for optimization problems. They work best when a problem exhibits two key properties:
1.  **Greedy Choice Property:** A globally optimal solution can be reached by making a locally optimal (greedy) choice at each step.
2.  **Optimal Substructure:** An optimal solution to the problem contains optimal solutions to subproblems.

**Common Techniques/Patterns:**
-   **Sorting:** Many greedy problems require sorting the input data based on some criteria to make optimal local choices.
-   **Priority Queues:** Used to efficiently select the best available option at each step (e.g., Dijkstra's algorithm, Huffman coding).
-   **Interval Scheduling:** Problems involving selecting non-overlapping intervals (e.g., Activity Selection Problem).
-   **Coin Change (Specific Cases):** For certain coin denominations (like standard currency), a greedy approach works.
-   **Fractional Knapsack:** Unlike 0/1 Knapsack, fractional knapsack can be solved greedily.

**Proof Techniques for Greedy Algorithms:**
Proving the correctness of a greedy algorithm often involves one of two techniques:
1.  **Greedy Stays Ahead:** Show that the greedy algorithm's solution is always at least as good as any other optimal solution at each step.
2.  **Exchange Argument:** Assume there exists an optimal solution that is different from the greedy one. Then, show that you can transform the optimal solution into the greedy solution by a series of exchanges, where each exchange improves or maintains the optimality, eventually proving that the greedy solution is also optimal.

### 4.1.1 Practice Problems (Greedy Algorithms)

Here are 10 handpicked important problems related to Greedy Algorithms from platforms like LeetCode and GeeksForGeeks, along with their solutions in C++ and complexity analysis.

#### Problem 1: Activity Selection Problem

**Description:** You are given `n` activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming a person can only work on one activity at a time.

**Example:**
Input: `start[] = {1, 3, 0, 5, 8, 5}`, `finish[] = {2, 4, 6, 7, 9, 9}`
Output: `(1,2), (3,4), (5,7), (8,9)` or `(0,6), (8,9)` (depending on selection, but max activities is 4)

**Approach:**
1. Sort the activities by their finish times in ascending order.
2. Select the first activity.
3. For the remaining activities, select the next activity whose start time is greater than or equal to the finish time of the previously selected activity.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Custom comparator for sorting activities by finish time
bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.finish < a2.finish;
}

void printMaxActivities(std::vector<Activity>& activities) {
    // Sort activities by finish time
    std::sort(activities.begin(), activities.end(), compareActivities);

    std::cout << "Selected Activities:\n";

    // The first activity always gets selected
    int i = 0;
    std::cout << "(" << activities[i].start << "," << activities[i].finish << ")\n";

    // Consider rest of the activities
    for (int j = 1; j < activities.size(); ++j) {
        // If this activity has start time greater than or equal to the finish time
        // of previously selected activity, then select it
        if (activities[j].start >= activities[i].finish) {
            std::cout << "(" << activities[j].start << "," << activities[j].finish << ")\n";
            i = j;
        }
    }
}

int main() {
    std::vector<Activity> activities = {
        {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    printMaxActivities(activities);

    return 0;
}
```

**Time Complexity:** O(N log N) due to sorting. The iteration takes O(N).
**Space Complexity:** O(1) if sorting in-place, or O(N) if a copy is made for sorting.

#### Problem 2: Fractional Knapsack Problem

**Description:** Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. You can take fractions of items.

**Example:**
Input: `items = {{60, 10}, {100, 20}, {120, 30}}` (value, weight), `W = 50`
Output: `240.0` (Take item 0 fully (60, 10), item 1 fully (100, 20), and 2/3 of item 2 (120, 30) -> 60 + 100 + (2/3)*120 = 240)

**Approach:**
1. Calculate the value-to-weight ratio for each item.
2. Sort the items in descending order based on this ratio.
3. Iterate through the sorted items. For each item, take as much as possible until the knapsack capacity is full.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::fixed and std::setprecision

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double ratio;

    Item(int v, int w) : value(v), weight(w), ratio(static_cast<double>(v) / w) {}
};

// Custom comparator for sorting items by value-to-weight ratio
bool compareItems(const Item& i1, const Item& i2) {
    return i1.ratio > i2.ratio; // Sort in descending order of ratio
}

double fractionalKnapsack(int W, std::vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    std::sort(items.begin(), items.end(), compareItems);

    double total_value = 0.0;
    int current_weight = 0;

    for (const auto& item : items) {
        if (current_weight + item.weight <= W) {
            // Take the whole item
            current_weight += item.weight;
            total_value += item.value;
        } else {
            // Take a fraction of the item
            int remaining_capacity = W - current_weight;
            total_value += item.ratio * remaining_capacity;
            break; // Knapsack is full
        }
    }
    return total_value;
}

int main() {
    std::vector<Item> items = {
        {60, 10}, {100, 20}, {120, 30}
    };
    int W = 50;

    double max_value = fractionalKnapsack(W, items);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Maximum value in Knapsack = " << max_value << "\n"; // Expected: 240.00

    return 0;
}
```

**Time Complexity:** O(N log N) due to sorting.
**Space Complexity:** O(1) if sorting in-place, or O(N) if a copy is made for sorting.

#### Problem 3: Minimum Number of Coins

**Description:** Given a value `V` and a list of coin denominations `coins[]`, find the minimum number of coins required to make the change. Assume you have an infinite supply of each coin. (This problem has a greedy solution only for certain coin systems, like standard currency. For arbitrary coin systems, Dynamic Programming is needed. Here, we assume a standard currency system where greedy works).

**Example:**
Input: `coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}`, `V = 70`
Output: `2` (50 + 20)

**Approach:**
1. Sort the coin denominations in descending order.
2. Iterate through the sorted denominations. For each denomination, take as many coins as possible without exceeding the remaining value `V`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void findMinCoins(int V, std::vector<int>& coins) {
    std::sort(coins.begin(), coins.end(), std::greater<int>()); // Sort in descending order

    std::vector<int> result_coins;
    int count = 0;

    for (int coin : coins) {
        while (V >= coin) {
            V -= coin;
            result_coins.push_back(coin);
            count++;
        }
    }

    std::cout << "Minimum coins required: " << count << "\n";
    std::cout << "Coins used: ";
    for (int coin : result_coins) {
        std::cout << coin << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int V = 70;
    findMinCoins(V, coins);

    V = 123;
    findMinCoins(V, coins);

    return 0;
}
```

**Time Complexity:** O(N log N) for sorting, plus O(V) in the worst case for the inner loop (if `V` is large and smallest coin is 1). More precisely, it's O(N log N + K) where K is the number of coins used.
**Space Complexity:** O(K) for storing result coins.

#### Problem 4: Job Sequencing Problem

**Description:** Given a list of jobs where each job has a deadline and a profit. You can perform one job at a time, and each job takes 1 unit of time. Find the maximum profit that can be obtained.

**Example:**
Input: `jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}}` (id, deadline, profit)
Output: `142` (Jobs: c, a, e)

**Approach:**
1. Sort the jobs in descending order of their profits.
2. Create a time slot array (or boolean array) to keep track of free time slots. The size of this array should be `max_deadline + 1`.
3. Iterate through the sorted jobs. For each job, try to place it in the latest possible free time slot before its deadline. If a slot is found, mark it as occupied and add the job's profit to the total.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Structure to represent a job
struct Job {
    char id;      // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is finished before or on deadline
};

// Custom comparator for sorting jobs by profit in descending order
bool compareJobs(const Job& j1, const Job& j2) {
    return j1.profit > j2.profit;
}

void printJobScheduling(std::vector<Job>& jobs) {
    // Sort all jobs according to decreasing order of profit
    std::sort(jobs.begin(), jobs.end(), compareJobs);

    int max_deadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline > max_deadline) {
            max_deadline = job.deadline;
        }
    }

    // Array to keep track of free time slots
    // A slot free[i] = true means that slot i is free
    std::vector<bool> slot(max_deadline + 1, false);

    // To store result (Sequence of jobs)
    std::vector<char> result(max_deadline + 1, ' ');
    int total_profit = 0;

    // Iterate through all given jobs
    for (const auto& job : jobs) {
        // Find a free slot for this job (starting from the latest possible time)
        for (int j = job.deadline; j >= 1; --j) {
            // Free slot found
            if (!slot[j]) {
                result[j] = job.id;
                total_profit += job.profit;
                slot[j] = true; // Mark this slot filled
                break;
            }
        }
    }

    std::cout << "Maximum Profit: " << total_profit << "\n";
    std::cout << "Jobs sequence: ";
    for (int i = 1; i <= max_deadline; ++i) {
        if (slot[i]) {
            std::cout << result[i] << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    printJobScheduling(jobs);

    return 0;
}
```

**Time Complexity:** O(N log N) for sorting. The nested loop can be O(N * M) where M is max deadline. Overall, it can be O(N^2) in worst case. Using a Disjoint Set Union (DSU) data structure can optimize it to O(N log N) or O(N α(N)).
**Space Complexity:** O(M) for the `slot` and `result` arrays.

#### Problem 5: Huffman Coding

**Description:** Given a set of characters and their frequencies, construct a Huffman tree and find the Huffman codes for each character. Huffman coding is a greedy algorithm used for lossless data compression.

**Approach:**
1. Create a leaf node for each character and its frequency. Add all leaf nodes to a min-priority queue.
2. While the priority queue has more than one node:
   a. Extract the two nodes with the minimum frequencies from the priority queue.
   b. Create a new internal node with these two nodes as children and a frequency equal to the sum of their frequencies. Mark the left child with '0' and the right child with '1'.
   c. Add the new internal node to the priority queue.
3. The remaining node in the priority queue is the root of the Huffman tree.
4. Traverse the Huffman tree to generate codes for each character.

**Solution (C++ - Conceptual, as full implementation is lengthy):**

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

// A Huffman tree node
struct MinHeapNode {
    char data;         // One of the input characters
    unsigned freq;     // Frequency of the character
    MinHeapNode *left, *right; // Left and right child

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// For priority queue (min heap)
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

// Function to print Huffman codes from the root of Huffman Tree.
void printCodes(MinHeapNode* root, std::string str, std::map<char, std::string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node, then it contains one of the input characters
    if (root->data != 

```

**Note:** The Huffman Coding problem's full C++ implementation is quite extensive due to the tree structure and code generation. The provided snippet is a conceptual start. For a complete implementation, refer to resources like GeeksforGeeks [3].

**Time Complexity:** O(N log N) where N is the number of unique characters. Building the heap takes O(N), and extracting/inserting N-1 times takes O(N log N).
**Space Complexity:** O(N) for storing the tree nodes and codes.

#### Problem 6: N meetings in one room

**Description:** There is one meeting room in a firm. There are `N` meetings in the form of `(start_time[i], end_time[i])`. Each meeting takes place in the same room. Find the maximum number of meetings that can be accommodated in the meeting room.

**Example:**
Input: `start[] = {1, 3, 0, 5, 8, 5}`, `end[] = {2, 4, 6, 7, 9, 9}`
Output: `4` (Meetings: (1,2), (3,4), (5,7), (8,9))

**Approach:** This is identical to the Activity Selection Problem. The greedy choice is to always pick the meeting that finishes earliest among the available meetings.

**Solution (C++):** (Same as Activity Selection Problem)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a meeting
struct Meeting {
    int start;
    int end;
    int pos; // Original position for tracking
};

// Custom comparator for sorting meetings by finish time
bool compareMeetings(const Meeting& m1, const Meeting& m2) {
    return m1.end < m2.end;
}

void maxMeetings(int s[], int f[], int n) {
    std::vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i) {
        meetings[i] = {s[i], f[i], i + 1};
    }

    // Sort all meetings by their finishing times
    std::sort(meetings.begin(), meetings.end(), compareMeetings);

    std::cout << "Maximum meetings that can be accommodated: ";

    // The first meeting always gets selected
    int i = 0;
    std::cout << meetings[i].pos << " ";

    // Consider rest of the meetings
    for (int j = 1; j < n; ++j) {
        // If this meeting has start time greater than or equal to the finish time
        // of previously selected meeting, then select it
        if (meetings[j].start >= meetings[i].end) {
            std::cout << meetings[j].pos << " ";
            i = j;
        }
    }
    std::cout << "\n";
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);

    maxMeetings(s, f, n);

    return 0;
}
```

**Time Complexity:** O(N log N) due to sorting.
**Space Complexity:** O(N) for storing meeting structures.

#### Problem 7: Assign Cookies

**Description:** Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child `i` has a greed factor `g[i]`, which is the minimum size of a cookie that the child will be content with; and each cookie `j` has a size `s[j]`. If `s[j] >= g[i]`, we can assign the cookie `j` to the child `i`, and the child `i` will be content. Your goal is to maximize the number of your content children.

**Example:**
Input: `g = [1,2,3]`, `s = [1,1]`
Output: `1` (Only child with greed 1 can be content with cookie size 1)

**Approach:**
1. Sort both the children's greed factors and the cookie sizes in ascending order.
2. Iterate through the children and cookies. Try to assign the smallest possible cookie to the child with the smallest greed factor. If a cookie satisfies a child, assign it and move to the next child and next cookie. If not, move to the next cookie (as the current cookie is too small for the current child and any subsequent children with higher greed).

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end()); // Sort children's greed factors
    std::sort(s.begin(), s.end()); // Sort cookie sizes

    int child_idx = 0;
    int cookie_idx = 0;
    int content_children = 0;

    while (child_idx < g.size() && cookie_idx < s.size()) {
        if (s[cookie_idx] >= g[child_idx]) {
            // This cookie can satisfy this child
            content_children++;
            child_idx++;
            cookie_idx++;
        } else {
            // This cookie is too small for the current child, try next cookie
            cookie_idx++;
        }
    }
    return content_children;
}

int main() {
    std::vector<int> g1 = {1, 2, 3};
    std::vector<int> s1 = {1, 1};
    std::cout << "Content children for g1, s1: " << findContentChildren(g1, s1) << "\n"; // Expected: 1

    std::vector<int> g2 = {1, 2};
    std::vector<int> s2 = {1, 2, 3};
    std::cout << "Content children for g2, s2: " << findContentChildren(g2, s2) << "\n"; // Expected: 2

    return 0;
}
```

**Time Complexity:** O(G log G + S log S) where G is the number of children and S is the number of cookies, due to sorting. The two-pointer iteration is O(G + S).
**Space Complexity:** O(1) if sorting in-place.

#### Problem 8: Jump Game

**Description:** You are given an integer array `nums`. You are initially positioned at the array's first index, and each `nums[i]` represents the maximum length of a forward jump from index `i`. Return `true` if you can reach the last index, or `false` otherwise.

**Example:**
Input: `nums = [2,3,1,1,4]`
Output: `true` (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

**Approach (Greedy):**
Maintain a variable `reachable` (or `max_reach`) that stores the maximum index reachable so far. Iterate through the array. If the current index `i` is greater than `reachable`, it means we cannot reach this index, so return `false`. Otherwise, update `reachable` to `max(reachable, i + nums[i])`. If `reachable` becomes greater than or equal to the last index, return `true`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool canJump(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return true;

    int max_reach = 0;
    for (int i = 0; i < n; ++i) {
        // If current index is beyond max_reach, we can't reach it
        if (i > max_reach) {
            return false;
        }
        // Update max_reach
        max_reach = std::max(max_reach, i + nums[i]);

        // If max_reach covers or exceeds the last index, we can reach it
        if (max_reach >= n - 1) {
            return true;
        }
    }
    return false; // Should not reach here if logic is correct for n > 1
}

int main() {
    std::vector<int> nums1 = {2, 3, 1, 1, 4};
    std::cout << "Can jump [2,3,1,1,4]? " << (canJump(nums1) ? "True" : "False") << "\n"; // Expected: True

    std::vector<int> nums2 = {3, 2, 1, 0, 4};
    std::cout << "Can jump [3,2,1,0,4]? " << (canJump(nums2) ? "True" : "False") << "\n"; // Expected: False

    std::vector<int> nums3 = {0};
    std::cout << "Can jump [0]? " << (canJump(nums3) ? "True" : "False") << "\n"; // Expected: True

    std::vector<int> nums4 = {0, 1};
    std::cout << "Can jump [0,1]? " << (canJump(nums4) ? "True" : "False") << "\n"; // Expected: False

    return 0;
}
```

**Time Complexity:** O(N) as we iterate through the array once.
**Space Complexity:** O(1).

#### Problem 9: Merge Intervals

**Description:** Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

**Example:**
Input: `intervals = [[1,3],[2,6],[8,10],[15,18]]`
Output: `[[1,6],[8,10],[15,18]]`
Explanation: Intervals `[1,3]` and `[2,6]` overlap, merge them into `[1,6]`.

**Approach:**
1. Sort the intervals based on their start times.
2. Initialize a `merged_intervals` list with the first interval.
3. Iterate through the rest of the sorted intervals. For each interval, compare it with the last interval in `merged_intervals`:
   a. If they overlap, merge them by updating the end time of the last interval in `merged_intervals` to the maximum of its current end time and the current interval's end time.
   b. If they don't overlap, add the current interval to `merged_intervals`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort intervals based on their start times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            std::vector<int>& last_merged = merged_intervals.back();
            std::vector<int>& current_interval = intervals[i];

            // Check for overlap
            if (current_interval[0] <= last_merged[1]) {
                // Overlap: merge by updating the end time
                last_merged[1] = std::max(last_merged[1], current_interval[1]);
            } else {
                // No overlap: add the current interval as a new merged interval
                merged_intervals.push_back(current_interval);
            }
        }
        return merged_intervals;
    }
};

void printIntervals(const std::vector<std::vector<int>>& intervals) {
    std::cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        std::cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;
    std::vector<std::vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> result1 = sol.merge(intervals1);
    std::cout << "Merged intervals 1: ";
    printIntervals(result1); // Expected: [[1,6],[8,10],[15,18]]

    std::vector<std::vector<int>> intervals2 = {{1,4},{4,5}};
    std::vector<std::vector<int>> result2 = sol.merge(intervals2);
    std::cout << "Merged intervals 2: ";
    printIntervals(result2); // Expected: [[1,5]]

    std::vector<std::vector<int>> intervals3 = {{1,4},{0,4}};
    std::vector<std::vector<int>> result3 = sol.merge(intervals3);
    std::cout << "Merged intervals 3: ";
    printIntervals(result3); // Expected: [[0,4]]

    return 0;
}
```

**Time Complexity:** O(N log N) due to sorting. The single pass for merging is O(N).
**Space Complexity:** O(N) for storing the merged intervals (in the worst case, no overlaps).

#### Problem 10: Best Time to Buy and Sell Stock

**Description:** You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

**Example:**
Input: `prices = [7,1,5,3,6,4]`
Output: `5` (Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5. Not 7-1 = 6, as selling price needs to be after buying price.)

**Approach (Greedy / Single Pass):**
Maintain a `min_price` variable, initialized to a very large value (or the first price). Iterate through the prices. For each price, calculate the potential profit (`current_price - min_price`). Update `max_profit` if the potential profit is greater. Also, update `min_price` if the current price is lower than the `min_price` found so far.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For std::numeric_limits

int maxProfit(std::vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int min_price = std::numeric_limits<int>::max();
    int max_profit = 0;

    for (int price : prices) {
        if (price < min_price) {
            min_price = price;
        } else if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}

int main() {
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << "Max profit for [7,1,5,3,6,4]: " << maxProfit(prices1) << "\n"; // Expected: 5

    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    std::cout << "Max profit for [7,6,4,3,1]: " << maxProfit(prices2) << "\n"; // Expected: 0

    std::vector<int> prices3 = {1, 2};
    std::cout << "Max profit for [1,2]: " << maxProfit(prices3) << "\n"; // Expected: 1

    return 0;
}
```

**Time Complexity:** O(N) as we iterate through the array once.
**Space Complexity:** O(1).

---

### References

[1] GeeksforGeeks. "Greedy Algorithms." *GeeksforGeeks*, 7 Apr. 2025, www.geeksforgeeks.org/dsa/greedy-algorithms/.
[2] FreeCodeCamp. "What is a Greedy Algorithm? Examples of Greedy Algorithms." *freeCodeCamp.org*, 12 May 2023, www.freecodecamp.org/news/greedy-algorithms/.
[3] GeeksforGeeks. "Huffman Coding Greedy Algorithm." *GeeksforGeeks*, www.geeksforgeeks.org/huffman-coding-greedy-algo/.

---



### 4.2 Dynamic Programming (DP)

Dynamic Programming (DP) is an algorithmic technique for solving complex problems by breaking them down into simpler, overlapping subproblems and storing the results of these subproblems to avoid recomputing them. It is mainly an optimization over plain recursion [1, 2].

**Analogy:** Imagine you are building a large LEGO castle. Instead of building each unique part from scratch every time it's needed, you build common components (like walls, towers, roofs) once, store them, and then reuse them whenever they are required. Dynamic Programming works similarly by solving subproblems once and storing their solutions for future use.

**When to use Dynamic Programming?**
DP is applicable to problems that exhibit two main characteristics:
1.  **Overlapping Subproblems:** The problem can be broken down into smaller subproblems that are solved multiple times. DP solves each subproblem only once and stores its solution.
2.  **Optimal Substructure:** An optimal solution to the problem can be constructed from optimal solutions of its subproblems.

**Approaches to Dynamic Programming:**
1.  **Memoization (Top-Down):** This is a recursive approach where you solve the problem by breaking it down into subproblems and store the results of subproblems in a table (e.g., an array or hash map) as they are computed. If a subproblem is encountered again, its stored result is retrieved instead of recomputing.
2.  **Tabulation (Bottom-Up):** This is an iterative approach where you solve the subproblems first and then use their solutions to build up the solutions to larger problems. You typically fill a table in a specific order, starting from the base cases.

**Common Techniques/Patterns:**
-   **State Definition:** Clearly define what `dp[i]` or `dp[i][j]` represents.
-   **Base Cases:** Identify the simplest subproblems and their solutions.
-   **Recurrence Relation:** Formulate a relationship between the solution of a larger problem and the solutions of its smaller subproblems.
-   **Order of Computation:** Determine the order in which subproblems should be solved (especially for tabulation).

### 4.2.1 Practice Problems (Dynamic Programming)

Here are 10 handpicked important problems related to Dynamic Programming, along with their solutions in C++ and complexity analysis.

#### Problem 1: Fibonacci Numbers

**Description:** Given a non-negative integer `n`, calculate the `n`-th Fibonacci number. The Fibonacci sequence is defined as `F(0) = 0`, `F(1) = 1`, and `F(n) = F(n-1) + F(n-2)` for `n > 1`.

**Approach (Memoization):**
Use a recursive function with a memoization table (array) to store already computed Fibonacci numbers. Before computing `F(n)`, check if it's already in the table. If not, compute it and store it.

**Solution (C++ - Memoization):**

```cpp
#include <iostream>
#include <vector>

std::vector<long long> memo;

long long fib_memo(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

long long fibonacci_memoization(int n) {
    memo.assign(n + 1, -1); // Initialize memoization table with -1
    return fib_memo(n);
}

int main() {
    std::cout << "Fibonacci(0): " << fibonacci_memoization(0) << "\n"; // Expected: 0
    std::cout << "Fibonacci(1): " << fibonacci_memoization(1) << "\n"; // Expected: 1
    std::cout << "Fibonacci(5): " << fibonacci_memoization(5) << "\n"; // Expected: 5
    std::cout << "Fibonacci(10): " << fibonacci_memoization(10) << "\n"; // Expected: 55
    std::cout << "Fibonacci(30): " << fibonacci_memoization(30) << "\n"; // Expected: 832040
    return 0;
}
```

**Time Complexity:** O(N) because each Fibonacci number is computed only once.
**Space Complexity:** O(N) for the memoization table and recursion stack.

**Approach (Tabulation):**
Create a DP table `dp` of size `n+1`. Initialize `dp[0] = 0` and `dp[1] = 1`. Then, iterate from `i = 2` to `n`, calculating `dp[i] = dp[i-1] + dp[i-2]`.

**Solution (C++ - Tabulation):**

```cpp
#include <iostream>
#include <vector>

long long fibonacci_tabulation(int n) {
    if (n <= 1) {
        return n;
    }
    std::vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    std::cout << "Fibonacci(0): " << fibonacci_tabulation(0) << "\n"; // Expected: 0
    std::cout << "Fibonacci(1): " << fibonacci_tabulation(1) << "\n"; // Expected: 1
    std::cout << "Fibonacci(5): " << fibonacci_tabulation(5) << "\n"; // Expected: 5
    std::cout << "Fibonacci(10): " << fibonacci_tabulation(10) << "\n"; // Expected: 55
    std::cout << "Fibonacci(30): " << fibonacci_tabulation(30) << "\n"; // Expected: 832040
    return 0;
}
```

**Time Complexity:** O(N) as we iterate through the table once.
**Space Complexity:** O(N) for the DP table.

#### Problem 2: Climbing Stairs

**Description:** You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Example:**
Input: `n = 3`
Output: `3`
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

**Approach:**
This problem has optimal substructure and overlapping subproblems. The number of ways to reach step `n` is the sum of ways to reach `n-1` (then take 1 step) and ways to reach `n-2` (then take 2 steps). This is essentially the Fibonacci sequence.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    std::cout << "Ways to climb 2 stairs: " << climbStairs(2) << "\n"; // Expected: 2
    std::cout << "Ways to climb 3 stairs: " << climbStairs(3) << "\n"; // Expected: 3
    std::cout << "Ways to climb 4 stairs: " << climbStairs(4) << "\n"; // Expected: 5
    std::cout << "Ways to climb 10 stairs: " << climbStairs(10) << "\n"; // Expected: 89
    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(N).

#### Problem 3: House Robber

**Description:** You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security systems connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

**Example:**
Input: `nums = [2,3,2]`
Output: `3` (Rob house 2 (money = 3). You cannot rob house 1 (money = 2) and then house 3 (money = 2) because they are adjacent.)

**Approach:**
Since the houses are arranged in a circle, the first and last houses are adjacent. This means we cannot rob both the first and the last house simultaneously. We can break this problem into two subproblems:
1.  Rob houses from index 0 to `n-2` (excluding the last house).
2.  Rob houses from index 1 to `n-1` (excluding the first house).
The maximum profit will be the maximum of the results from these two subproblems.

For a linear arrangement of houses (which is what each subproblem becomes), the DP state `dp[i]` represents the maximum money that can be robbed up to house `i`. The recurrence relation is `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Helper function for linear house robbery
int robLinear(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}

int rob(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Case 1: Exclude the last house (rob houses from 0 to n-2)
    std::vector<int> nums1(nums.begin(), nums.end() - 1);
    int profit1 = robLinear(nums1);

    // Case 2: Exclude the first house (rob houses from 1 to n-1)
    std::vector<int> nums2(nums.begin() + 1, nums.end());
    int profit2 = robLinear(nums2);

    return std::max(profit1, profit2);
}

int main() {
    std::vector<int> nums1 = {2, 3, 2};
    std::cout << "Max money for [2,3,2]: " << rob(nums1) << "\n"; // Expected: 3

    std::vector<int> nums2 = {1, 2, 3, 1};
    std::cout << "Max money for [1,2,3,1]: " << rob(nums2) << "\n"; // Expected: 4 (rob 2 and 1)

    std::vector<int> nums3 = {0};
    std::cout << "Max money for [0]: " << rob(nums3) << "\n"; // Expected: 0

    std::vector<int> nums4 = {1, 2};
    std::cout << "Max money for [1,2]: " << rob(nums4) << "\n"; // Expected: 2

    return 0;
}
```

**Time Complexity:** O(N) because we iterate through the array twice.
**Space Complexity:** O(N) for the DP table in `robLinear` and for creating temporary vectors.

#### Problem 4: Longest Increasing Subsequence (LIS)

**Description:** Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

**Example:**
Input: `nums = [10,9,2,5,3,7,101,18]`
Output: `4`
Explanation: The longest increasing subsequence is `[2,3,7,101]`, hence the length is 4.

**Approach:**
Define `dp[i]` as the length of the longest increasing subsequence ending at index `i`. To compute `dp[i]`, iterate through all `j < i`. If `nums[i] > nums[j]`, then `dp[i]` can be `dp[j] + 1`. We take the maximum such `dp[j] + 1` over all valid `j`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> dp(n, 1); // Initialize all dp[i] to 1 (each element is an LIS of length 1)
    int max_len = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max_len = std::max(max_len, dp[i]);
    }
    return max_len;
}

int main() {
    std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "LIS length for [10,9,2,5,3,7,101,18]: " << lengthOfLIS(nums1) << "\n"; // Expected: 4

    std::vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    std::cout << "LIS length for [0,1,0,3,2,3]: " << lengthOfLIS(nums2) << "\n"; // Expected: 4

    std::vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    std::cout << "LIS length for [7,7,7,7,7,7,7]: " << lengthOfLIS(nums3) << "\n"; // Expected: 1

    return 0;
}
```

**Time Complexity:** O(N^2) due to nested loops.
**Space Complexity:** O(N) for the DP table.

**Optimization (N log N solution):**
This problem can be solved in O(N log N) time using a different approach involving binary search. Maintain a `tails` array where `tails[i]` is the smallest tail of all increasing subsequences of length `i+1`. For each number `num` in `nums`:
- If `num` is greater than all elements in `tails`, append `num` to `tails` (extends the longest subsequence).
- Otherwise, find the smallest element in `tails` that is greater than or equal to `num` and replace it with `num` (this creates a new increasing subsequence of the same length but with a smaller ending, which is more promising for future extensions).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS_optimized(std::vector<int>& nums) {
    std::vector<int> tails;
    for (int num : nums) {
        auto it = std::lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    return tails.size();
}

int main() {
    std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "LIS length (optimized) for [10,9,2,5,3,7,101,18]: " << lengthOfLIS_optimized(nums1) << "\n"; // Expected: 4

    std::vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    std::cout << "LIS length (optimized) for [0,1,0,3,2,3]: " << lengthOfLIS_optimized(nums2) << "\n"; // Expected: 4

    std::vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    std::cout << "LIS length (optimized) for [7,7,7,7,7,7,7]: " << lengthOfLIS_optimized(nums3) << "\n"; // Expected: 1

    return 0;
}
```

**Time Complexity:** O(N log N) due to binary search in each iteration.
**Space Complexity:** O(N) for the `tails` vector.

#### Problem 5: Longest Common Subsequence (LCS)

**Description:** Given two strings `text1` and `text2`, return the length of their longest common subsequence. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example:**
Input: `text1 = "abcde"`, `text2 = "ace"`
Output: `3`
Explanation: The longest common subsequence is "ace", and its length is 3.

**Approach:**
Define `dp[i][j]` as the length of the LCS of `text1[0...i-1]` and `text2[0...j-1]`. The recurrence relation is:
- If `text1[i-1] == text2[j-1]`, then `dp[i][j] = 1 + dp[i-1][j-1]`.
- Else, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int longestCommonSubsequence(std::string text1, std::string text2) {
    int m = text1.length();
    int n = text2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << "LCS for \"abcde\" and \"ace\": " << longestCommonSubsequence("abcde", "ace") << "\n"; // Expected: 3
    std::cout << "LCS for \"abc\" and \"abc\": " << longestCommonSubsequence("abc", "abc") << "\n"; // Expected: 3
    std::cout << "LCS for \"abc\" and \"def\": " << longestCommonSubsequence("abc", "def") << "\n"; // Expected: 0
    return 0;
}
```

**Time Complexity:** O(M*N) where M and N are the lengths of the two strings.
**Space Complexity:** O(M*N) for the DP table.

#### Problem 6: 0/1 Knapsack Problem

**Description:** Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. You cannot break items, either take the whole item or don't take it.

**Example:**
Input: `W = 50`, `weights = [10, 20, 30]`, `values = [60, 100, 120]`
Output: `220` (Take items with weights 20 and 30, total weight 50, total value 100 + 120 = 220)

**Approach:**
Define `dp[i][w]` as the maximum value that can be obtained with a knapsack of capacity `w` using items up to index `i`. The recurrence relation is:
- If `weights[i-1] > w` (current item's weight is more than current capacity), then `dp[i][w] = dp[i-1][w]` (don't include current item).
- Else, `dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]])` (either don't include or include current item).

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int knapSack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    std::cout << "Max value for 0/1 Knapsack: " << knapSack(W, weights, values, n) << "\n"; // Expected: 220

    return 0;
}
```

**Time Complexity:** O(N*W) where N is the number of items and W is the knapsack capacity.
**Space Complexity:** O(N*W) for the DP table. Can be optimized to O(W) using only two rows or one row.

#### Problem 7: Coin Change

**Description:** You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

**Example:**
Input: `coins = [1,2,5]`, `amount = 11`
Output: `3` (11 = 5 + 5 + 1)

**Approach:**
Define `dp[i]` as the minimum number of coins needed to make amount `i`. Initialize `dp[0] = 0` and all other `dp[i]` to infinity. For each amount `i` from 1 to `amount`, and for each `coin` in `coins`, if `i >= coin`, then `dp[i] = min(dp[i], 1 + dp[i - coin])`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For std::numeric_limits

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != std::numeric_limits<int>::max()) {
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
}

int main() {
    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << "Min coins for amount 11 with [1,2,5]: " << coinChange(coins1, amount1) << "\n"; // Expected: 3

    std::vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << "Min coins for amount 3 with [2]: " << coinChange(coins2, amount2) << "\n"; // Expected: -1

    std::vector<int> coins3 = {1};
    int amount3 = 0;
    std::cout << "Min coins for amount 0 with [1]: " << coinChange(coins3, amount3) << "\n"; // Expected: 0

    return 0;
}
```

**Time Complexity:** O(amount * number_of_coins).
**Space Complexity:** O(amount).

#### Problem 8: Edit Distance

**Description:** Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`. You have the following three operations permitted on a word:
1. Insert a character
2. Delete a character
3. Replace a character

**Example:**
Input: `word1 = "horse"`, `word2 = "ros"`
Output: `3`
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (delete 'r')
rose -> ros (delete 'e')

**Approach:**
Define `dp[i][j]` as the minimum number of operations to convert `word1[0...i-1]` to `word2[0...j-1]`. The recurrence relation is:
- If `word1[i-1] == word2[j-1]`, then `dp[i][j] = dp[i-1][j-1]` (no operation needed).
- Else, `dp[i][j] = 1 + min(dp[i-1][j],    // Delete
                          dp[i][j-1],    // Insert
                          dp[i-1][j-1])` // Replace

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // Initialize DP table
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i; // Deleting all characters of word1 to get empty word2
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j; // Inserting all characters of word2 to get word1 from empty
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j],    // Delete
                                         dp[i][j - 1],    // Insert
                                         dp[i - 1][j - 1]}); // Replace
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << "Edit distance for \"horse\" and \"ros\": " << minDistance("horse", "ros") << "\n"; // Expected: 3
    std::cout << "Edit distance for \"intention\" and \"execution\": " << minDistance("intention", "execution") << "\n"; // Expected: 5
    std::cout << "Edit distance for \"\" and \"a\": " << minDistance("", "a") << "\n"; // Expected: 1
    return 0;
}
```

**Time Complexity:** O(M*N) where M and N are the lengths of the two strings.
**Space Complexity:** O(M*N) for the DP table.

#### Problem 9: Longest Palindromic Subsequence

**Description:** Given a string `s`, find the longest palindromic subsequence's length.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example:**
Input: `s = "bbbab"`
Output: `4`
Explanation: One possible longest palindromic subsequence is "bbbb".

**Approach:**
This problem can be reduced to finding the Longest Common Subsequence (LCS) between the given string `s` and its reverse `s_reversed`. The LCS of a string and its reverse will be the longest palindromic subsequence.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Reusing LCS function from Problem 5
int longestCommonSubsequence(std::string text1, std::string text2) {
    int m = text1.length();
    int n = text2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int longestPalindromeSubseq(std::string s) {
    std::string s_reversed = s;
    std::reverse(s_reversed.begin(), s_reversed.end());
    return longestCommonSubsequence(s, s_reversed);
}

int main() {
    std::cout << "LPS for \"bbbab\": " << longestPalindromeSubseq("bbbab") << "\n"; // Expected: 4
    std::cout << "LPS for \"cbbd\": " << longestPalindromeSubseq("cbbd") << "\n"; // Expected: 2
    std::cout << "LPS for \"a\": " << longestPalindromeSubseq("a") << "\n"; // Expected: 1
    return 0;
}
```

**Time Complexity:** O(N^2) where N is the length of the string (due to LCS).
**Space Complexity:** O(N^2) for the DP table.

#### Problem 10: Word Break

**Description:** Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words. Note that the same word in the dictionary may be reused multiple times in the segmentation.

**Example:**
Input: `s = "leetcode"`, `wordDict = ["leet","code"]`
Output: `true`
Explanation: Return `true` because "leetcode" can be segmented as "leet code".

**Approach:**
Define `dp[i]` as `true` if `s[0...i-1]` can be segmented, and `false` otherwise. Initialize `dp[0] = true` (empty string can be segmented). For each `i` from 1 to `n` (length of `s`), iterate `j` from 0 to `i-1`. If `dp[j]` is `true` and the substring `s[j...i-1]` is in `wordDict`, then `dp[i]` is `true`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict) {
    int n = s.length();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true; // Base case: empty string can be segmented

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break; // Found a way to segment up to i
            }
        }
    }
    return dp[n];
}

int main() {
    std::unordered_set<std::string> wordDict1 = {"leet", "code"};
    std::cout << "\"leetcode\" can be segmented: " << (wordBreak("leetcode", wordDict1) ? "True" : "False") << "\n"; // Expected: True

    std::unordered_set<std::string> wordDict2 = {"apple", "pen"};
    std::cout << "\"applepenapple\" can be segmented: " << (wordBreak("applepenapple", wordDict2) ? "True" : "False") << "\n"; // Expected: True

    std::unordered_set<std::string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    std::cout << "\"catsandog\" can be segmented: " << (wordBreak("catsandog", wordDict3) ? "True" : "False") << "\n"; // Expected: False

    return 0;
}
```

**Time Complexity:** O(N^2 * L) where N is the length of the string and L is the average length of words in the dictionary (due to `substr` and `count`). If `substr` is O(L) and `count` is O(L) for `unordered_set` in worst case, it can be O(N^2 * L).
**Space Complexity:** O(N) for the DP table and O(D*L) for the dictionary where D is number of words in dictionary.

---

### References

[1] GeeksforGeeks. "Dynamic Programming or DP." *GeeksforGeeks*, 18 Mar. 2025, www.geeksforgeeks.org/competitive-programming/dynamic-programming/.
[2] Spiceworks. "A Simplified Guide to Dynamic Programming." *Spiceworks*, 26 Oct. 2022, www.spiceworks.com/tech/devops/articles/what-is-dynamic-programming/.

---



### 4.3 Recursion

Recursion is a programming technique where a function calls itself directly or indirectly to solve a problem. It breaks down a complex problem into smaller, simpler instances of the same problem until a base case is reached, which can be solved directly [1, 2].

**Analogy:** Imagine you have to find a specific book in a very large library. Instead of searching the entire library yourself, you ask a friend to search a specific section, and if they don't find it, they ask another friend to search a smaller section within their area, and so on, until someone finds the book or confirms it's not there. Each friend is performing the same task (searching a section) but on a smaller scale.

**Key Components of a Recursive Function:**
1.  **Base Case:** The condition that stops the recursion. Without a base case, the function would call itself indefinitely, leading to a stack overflow.
2.  **Recursive Step:** The part of the function that calls itself with a modified (usually smaller or simpler) input, moving towards the base case.

**When to use Recursion?**
Recursion is often used when:
-   The problem can be naturally broken down into smaller, identical subproblems.
-   The problem involves tree or graph traversals.
-   The problem definition is recursive (e.g., Fibonacci sequence, factorials).

**Common Techniques/Patterns:**
-   **Direct Recursion:** A function calls itself directly.
-   **Indirect Recursion:** A function calls another function, which in turn calls the first function.
-   **Tail Recursion:** A special form of recursion where the recursive call is the last operation in the function. Some compilers can optimize tail recursion into iteration, avoiding stack overflow issues.
-   **Divide and Conquer:** Problems are broken into smaller subproblems, solved independently, and then combined (e.g., Merge Sort, Quick Sort).
-   **Backtracking:** Explores all possible solutions by trying to build a solution incrementally and abandoning paths that cannot lead to a valid solution.

### 4.3.1 Practice Problems (Recursion)

Here are 10 handpicked important problems related to Recursion, along with their solutions in C++ and complexity analysis.

#### Problem 1: Factorial of a Number

**Description:** Given a non-negative integer `n`, calculate its factorial. The factorial of `n` (denoted as `n!`) is the product of all positive integers less than or equal to `n`. `0! = 1`.

**Example:**
Input: `n = 5`
Output: `120` (5 * 4 * 3 * 2 * 1)

**Approach:**
-   **Base Case:** If `n` is 0 or 1, return 1.
-   **Recursive Step:** Return `n * factorial(n-1)`.

**Solution (C++):**

```cpp
#include <iostream>

long long factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive step
    return n * factorial(n - 1);
}

int main() {
    std::cout << "Factorial of 0: " << factorial(0) << "\n"; // Expected: 1
    std::cout << "Factorial of 1: " << factorial(1) << "\n"; // Expected: 1
    std::cout << "Factorial of 5: " << factorial(5) << "\n"; // Expected: 120
    std::cout << "Factorial of 10: " << factorial(10) << "\n"; // Expected: 3628800
    return 0;
}
```

**Time Complexity:** O(N) as the function is called N times.
**Space Complexity:** O(N) for the recursion stack.

#### Problem 2: Sum of Digits of a Number

**Description:** Given a non-negative integer `n`, find the sum of its digits.

**Example:**
Input: `n = 123`
Output: `6` (1 + 2 + 3)

**Approach:**
-   **Base Case:** If `n` is 0, return 0.
-   **Recursive Step:** Return `(n % 10) + sumOfDigits(n / 10)`.

**Solution (C++):**

```cpp
#include <iostream>

int sumOfDigits(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    // Recursive step
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    std::cout << "Sum of digits of 123: " << sumOfDigits(123) << "\n"; // Expected: 6
    std::cout << "Sum of digits of 4567: " << sumOfDigits(4567) << "\n"; // Expected: 22
    std::cout << "Sum of digits of 0: " << sumOfDigits(0) << "\n"; // Expected: 0
    return 0;
}
```

**Time Complexity:** O(log N) where N is the number, as the number of recursive calls is proportional to the number of digits.
**Space Complexity:** O(log N) for the recursion stack.

#### Problem 3: Print N to 1 and 1 to N

**Description:** Given a positive integer `n`, print numbers from `n` down to 1, and then from 1 up to `n`.

**Example:**
Input: `n = 5`
Output:
5 4 3 2 1
1 2 3 4 5

**Approach (N to 1):**
-   **Base Case:** If `n` is 0, return.
-   **Recursive Step:** Print `n`, then call `printNto1(n-1)`.

**Approach (1 to N):**
-   **Base Case:** If `n` is 0, return.
-   **Recursive Step:** Call `print1toN(n-1)`, then print `n`.

**Solution (C++):**

```cpp
#include <iostream>

void printNto1(int n) {
    if (n == 0) {
        return;
    }
    std::cout << n << " ";
    printNto1(n - 1);
}

void print1toN(int n) {
    if (n == 0) {
        return;
    }
    print1toN(n - 1);
    std::cout << n << " ";
}

int main() {
    std::cout << "Printing N to 1 for N=5: ";
    printNto1(5);
    std::cout << "\n";

    std::cout << "Printing 1 to N for N=5: ";
    print1toN(5);
    std::cout << "\n";

    return 0;
}
```

**Time Complexity:** O(N) for both functions.
**Space Complexity:** O(N) for the recursion stack.

#### Problem 4: Tower of Hanoi

**Description:** The Tower of Hanoi is a mathematical puzzle. It consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

**Rules:**
1.  Only one disk can be moved at a time.
2.  Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3.  No disk may be placed on top of a smaller disk.

**Goal:** Move the entire stack from the source rod to the destination rod, using the auxiliary rod.

**Approach:**
-   **Base Case:** If there is only one disk, move it directly from source to destination.
-   **Recursive Step:**
    1.  Move `n-1` disks from source to auxiliary rod, using destination as auxiliary.
    2.  Move the `n`-th disk from source to destination.
    3.  Move `n-1` disks from auxiliary rod to destination, using source as auxiliary.

**Solution (C++):**

```cpp
#include <iostream>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << source << " to rod " << destination << "\n";
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move nth disk from source to destination
    std::cout << "Move disk " << n << " from rod " << source << " to rod " << destination << "\n";

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int num_disks = 3;
    std::cout << "Tower of Hanoi for " << num_disks << " disks:\n";
    towerOfHanoi(num_disks, 'A', 'B', 'C'); // A: Source, B: Auxiliary, C: Destination
    return 0;
}
```

**Time Complexity:** O(2^N) as for N disks, it takes `2^N - 1` moves.
**Space Complexity:** O(N) for the recursion stack.

#### Problem 5: Power (x^n)

**Description:** Implement `pow(x, n)`, which calculates `x` raised to the power `n` (`x^n`).

**Example:**
Input: `x = 2.0, n = 10`
Output: `1024.00000`

**Approach:**
-   **Base Case:** If `n` is 0, return 1. If `x` is 0, return 0.
-   **Recursive Step (Divide and Conquer):**
    -   If `n` is even, `x^n = (x^(n/2)) * (x^(n/2))`.
    -   If `n` is odd, `x^n = x * (x^(n/2)) * (x^(n/2))`.
    -   Handle negative `n` by calculating `1 / x^(-n)`.

**Solution (C++):**

```cpp
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;

    // Handle negative exponent
    if (n < 0) {
        x = 1 / x;
        // Use long long for n to avoid overflow when n is INT_MIN
        // abs(INT_MIN) is not representable as INT_MAX + 1
        // So, handle it carefully or cast to long long
        long long N = n;
        N = -N;
        return myPow(x, N);
    }

    double half_pow = myPow(x, n / 2);
    if (n % 2 == 0) {
        return half_pow * half_pow;
    } else {
        return x * half_pow * half_pow;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "2.0^10: " << myPow(2.0, 10) << "\n"; // Expected: 1024.00000
    std::cout << "2.1^3: " << myPow(2.1, 3) << "\n";   // Expected: 9.26100
    std::cout << "2.0^-2: " << myPow(2.0, -2) << "\n"; // Expected: 0.25000
    std::cout << "0.0^5: " << myPow(0.0, 5) << "\n";   // Expected: 0.00000
    std::cout << "5.0^0: " << myPow(5.0, 0) << "\n";   // Expected: 1.00000
    return 0;
}
```

**Time Complexity:** O(log N) due to dividing `n` by 2 in each recursive call.
**Space Complexity:** O(log N) for the recursion stack.

#### Problem 6: Reverse a String

**Description:** Write a function that reverses a string. The input string is given as an array of characters `char[]`.

**Example:**
Input: `s = ["h","e","l","l","o"]`
Output: `["o","l","l","e","h"]`

**Approach (Recursive):**
Use two pointers, `left` and `right`, initially pointing to the beginning and end of the string. Swap the characters at `left` and `right`, then recursively call the function with `left + 1` and `right - 1` until `left >= right`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void reverseStringRecursive(std::vector<char>& s, int left, int right) {
    // Base case
    if (left >= right) {
        return;
    }
    // Swap characters
    std::swap(s[left], s[right]);
    // Recursive step
    reverseStringRecursive(s, left + 1, right - 1);
}

void reverseString(std::vector<char>& s) {
    reverseStringRecursive(s, 0, s.size() - 1);
}

int main() {
    std::vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "Original: ";
    for (char c : s1) std::cout << c;
    std::cout << "\n";
    reverseString(s1);
    std::cout << "Reversed: ";
    for (char c : s1) std::cout << c;
    std::cout << "\n";

    std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    std::cout << "Original: ";
    for (char c : s2) std::cout << c;
    std::cout << "\n";
    reverseString(s2);
    std::cout << "Reversed: ";
    for (char c : s2) std::cout << c;
    std::cout << "\n";

    return 0;
}
```

**Time Complexity:** O(N) where N is the length of the string, as each character is swapped once.
**Space Complexity:** O(N) for the recursion stack.

#### Problem 7: Generate Parentheses

**Description:** Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

**Example:**
Input: `n = 3`
Output: `["((()))","(()())","(())()","()(())","()()()"]`

**Approach (Backtracking with Recursion):**
Use a recursive helper function that keeps track of the number of open and close parentheses used so far, and the current string. At each step, decide whether to add an open parenthesis or a close parenthesis. Ensure that:
1.  The number of open parentheses never exceeds `n`.
2.  The number of close parentheses never exceeds the number of open parentheses.
3.  The base case is when both open and close parentheses count reach `n`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>

void generateParenthesisRecursive(std::vector<std::string>& result, std::string current_string, int open_count, int close_count, int n) {
    // Base case
    if (current_string.length() == 2 * n) {
        result.push_back(current_string);
        return;
    }

    // Add open parenthesis if possible
    if (open_count < n) {
        generateParenthesisRecursive(result, current_string + '(', open_count + 1, close_count, n);
    }

    // Add close parenthesis if possible
    if (close_count < open_count) {
        generateParenthesisRecursive(result, current_string + ')', open_count, close_count + 1, n);
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    generateParenthesisRecursive(result, "", 0, 0, n);
    return result;
}

int main() {
    int n = 3;
    std::vector<std::string> combinations = generateParenthesis(n);
    std::cout << "Well-formed parentheses for n = " << n << ":\n";
    for (const std::string& s : combinations) {
        std::cout << s << "\n";
    }
    return 0;
}
```

**Time Complexity:** The number of valid parenthesis sequences is given by the Nth Catalan number, which is approximately O(4^N / (N^(3/2))). Each sequence takes O(N) to build. So, overall complexity is roughly O(N * 4^N / (N^(3/2))).
**Space Complexity:** O(N) for the recursion stack and current string, plus O(Catalan(N)) for storing results.

#### Problem 8: Permutations of a String/Array

**Description:** Given a collection of distinct numbers, return all possible permutations.

**Example:**
Input: `nums = [1,2,3]`
Output: `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

**Approach (Backtracking with Recursion):**
Use a recursive function that takes the current permutation being built and a boolean array to keep track of used elements. For each position in the permutation, try placing each unused element. If an element is placed, mark it as used and recurse. After the recursive call returns, backtrack by unmarking the element.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void permuteRecursive(std::vector<int>& nums, std::vector<std::vector<int>>& result, int start_index) {
    // Base case: If start_index reaches the end, a permutation is complete
    if (start_index == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start_index; i < nums.size(); ++i) {
        // Swap current element with element at start_index
        std::swap(nums[start_index], nums[i]);
        // Recurse for the next position
        permuteRecursive(nums, result, start_index + 1);
        // Backtrack: Swap back to restore original order for next iteration
        std::swap(nums[start_index], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    permuteRecursive(nums, result, 0);
    return result;
}

void printPermutations(const std::vector<std::vector<int>>& perms) {
    for (const auto& p : perms) {
        std::cout << "[";
        for (size_t i = 0; i < p.size(); ++i) {
            std::cout << p[i];
            if (i < p.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<std::vector<int>> result1 = permute(nums1);
    std::cout << "Permutations for [1,2,3]:\n";
    printPermutations(result1);

    std::vector<int> nums2 = {0, 1};
    std::vector<std::vector<int>> result2 = permute(nums2);
    std::cout << "\nPermutations for [0,1]:\n";
    printPermutations(result2);

    return 0;
}
```

**Time Complexity:** O(N * N!) because there are N! permutations, and each permutation takes O(N) time to print/copy.
**Space Complexity:** O(N) for the recursion stack.

#### Problem 9: Combination Sum

**Description:** Given a set of candidate numbers `candidates` (without duplicates) and a target number `target`, find all unique combinations in `candidates` where the candidate numbers sum to `target`. The same repeated number may be chosen from `candidates` unlimited number of times.

**Example:**
Input: `candidates = [2,3,6,7]`, `target = 7`
Output: `[[2,2,3],[7]]`

**Approach (Backtracking with Recursion):**
Use a recursive function that explores combinations. At each step, either include the current candidate number or exclude it. If included, subtract it from the target and recurse with the same candidate (since numbers can be reused). If excluded, move to the next candidate. Ensure to handle the base cases (target reached or target becomes negative).

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void combinationSumRecursive(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current_combination, int start_index) {
    // Base case 1: Target reached
    if (target == 0) {
        result.push_back(current_combination);
        return;
    }

    // Base case 2: Target becomes negative or no more candidates to consider
    if (target < 0 || start_index == candidates.size()) {
        return;
    }

    // Option 1: Include the current candidate (and can include it again)
    current_combination.push_back(candidates[start_index]);
    combinationSumRecursive(candidates, target - candidates[start_index], result, current_combination, start_index);
    current_combination.pop_back(); // Backtrack

    // Option 2: Exclude the current candidate (move to the next one)
    combinationSumRecursive(candidates, target, result, current_combination, start_index + 1);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_combination;
    // Sort candidates to handle duplicates if they were allowed, and for better pruning
    // std::sort(candidates.begin(), candidates.end()); // Not strictly necessary if candidates are distinct
    combinationSumRecursive(candidates, target, result, current_combination, 0);
    return result;
}

void printCombinations(const std::vector<std::vector<int>>& combinations) {
    for (const auto& combo : combinations) {
        std::cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            std::cout << combo[i];
            if (i < combo.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    std::vector<std::vector<int>> result1 = combinationSum(candidates1, target1);
    std::cout << "Combinations for target 7 with [2,3,6,7]:\n";
    printCombinations(result1);

    std::vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    std::vector<std::vector<int>> result2 = combinationSum(candidates2, target2);
    std::cout << "\nCombinations for target 8 with [2,3,5]:\n";
    printCombinations(result2);

    return 0;
}
```

**Time Complexity:** Exponential, roughly O(2^T * N) where T is the target and N is the number of candidates. More precisely, it depends on the number of valid combinations.
**Space Complexity:** O(T) for the recursion stack and current combination.

#### Problem 10: N-Queens Problem

**Description:** The N-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other. Given an integer `n`, return all distinct solutions to the N-queens puzzle.

**Example:**
Input: `n = 4`
Output: `[[.Q..,...Q,Q...,..Q.],[..Q.,Q...,...Q,.Q..]]` (Visual representation of two solutions)

**Approach (Backtracking with Recursion):**
Use a recursive function to place queens row by row. For each row, try placing a queen in each column. Before placing, check if the position is safe (no other queen attacks it horizontally, vertically, or diagonally). If safe, place the queen and recurse for the next row. If not safe, or if the recursive call doesn't lead to a solution, backtrack by removing the queen and trying the next column.

**Solution (C++ - Conceptual, as full implementation is lengthy):**

```cpp
#include <iostream>
#include <vector>
#include <string>

class NQueensSolver {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.'));
        solve(0, n, board, result);
        return result;
    }

private:
    bool isSafe(int row, int col, int n, const std::vector<std::string>& board) {
        // Check row
        for (int j = 0; j < col; ++j) {
            if (board[row][j] == 'Q') return false;
        }

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(int col, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result) {
        // Base case: All queens are placed
        if (col == n) {
            result.push_back(board);
            return;
        }

        // Try placing queen in each row of the current column
        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q'; // Place queen
                solve(col + 1, n, board, result); // Recurse for next column
                board[row][col] = '.'; // Backtrack: remove queen
            }
        }
    }
};

void printSolutions(const std::vector<std::vector<std::string>>& solutions) {
    for (const auto& solution : solutions) {
        for (const std::string& row : solution) {
            std::cout << row << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    NQueensSolver solver;
    int n = 4;
    std::vector<std::vector<std::string>> solutions = solver.solveNQueens(n);
    std::cout << "Solutions for " << n << "-Queens problem:\n";
    printSolutions(solutions);

    return 0;
}
```

**Time Complexity:** The exact time complexity is hard to determine precisely but is roughly O(N!) because in the worst case, it explores all N! permutations. More accurately, it's closer to O(N^N) without pruning, but with pruning, it's much better.
**Space Complexity:** O(N^2) for the chessboard and O(N) for the recursion stack.

---

### References

[1] GeeksforGeeks. "Introduction to Recursion." *GeeksforGeeks*, 20 May 2025, www.geeksforgeeks.org/dsa/introduction-to-recursion-2/.
[2] Medium. "Understanding Recursion Through Practical Examples." *Medium*, 7 Dec. 2022, medium.com/@teamtechsis/understanding-recursion-through-practical-examples-a3c586011f9d.

---



### 4.4 Backtracking

Backtracking is a general algorithmic technique for finding all (or some) solutions to some computational problems, notably constraint-satisfaction problems, that incrementally builds candidates to the solutions. It explores all possible solutions by trying to build a solution incrementally and abandoning a candidate as soon as it determines that the candidate cannot possibly be completed to a valid solution [1, 2].

**Analogy:** Imagine you are in a maze and need to find a way out. You walk down a path until you hit a dead end. At that point, you "backtrack" to the last junction where you had other choices, and then you try a different path. You continue this process until you find the exit or determine that no exit exists.

**Key Characteristics:**
-   **Incremental Construction:** Solutions are built step-by-step.
-   **Pruning/Abandonment:** If a partial solution cannot lead to a complete valid solution, the algorithm prunes that path and backtracks.
-   **Depth-First Search (DFS) like exploration:** It explores one path completely before trying another.

**When to use Backtracking?**
Backtracking is typically used for problems where you need to find:
-   All possible solutions (e.g., permutations, combinations, subsets).
-   A specific solution that satisfies certain constraints (e.g., N-Queens, Sudoku Solver).

**Common Techniques/Patterns:**
-   **Decision Tree:** Visualize the problem as a decision tree where each node represents a choice, and paths from the root to leaves represent potential solutions.
-   **State Management:** Maintain the current state of the solution being built (e.g., current permutation, current board configuration).
-   **`choose` / `explore` / `unchoose` (or `make_choice` / `recurse` / `undo_choice`):**
    -   `make_choice`: Make a decision (e.g., place a queen, add an element to a subset).
    -   `recurse`: Recursively call the function to explore further choices.
    -   `undo_choice`: Backtrack by undoing the last decision to explore other paths.
-   **Pruning:** Implement checks to cut off branches of the search tree that cannot lead to a valid solution, significantly improving efficiency.

### 4.4.1 Practice Problems (Backtracking)

Here are 10 handpicked important problems related to Backtracking, along with their solutions in C++ and complexity analysis.

#### Problem 1: Permutations

**Description:** Given a collection of distinct numbers, return all possible permutations.

**Example:**
Input: `nums = [1,2,3]`
Output: `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

**Approach:** (Already covered in Recursion section, but a classic backtracking example)
Use a recursive function that takes the current permutation being built and a boolean array to keep track of used elements. For each position in the permutation, try placing each unused element. If an element is placed, mark it as used and recurse. After the recursive call returns, backtrack by unmarking the element.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void permuteRecursive(std::vector<int>& nums, std::vector<std::vector<int>>& result, int start_index) {
    if (start_index == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start_index; i < nums.size(); ++i) {
        std::swap(nums[start_index], nums[i]);
        permuteRecursive(nums, result, start_index + 1);
        std::swap(nums[start_index], nums[i]); // Backtrack
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    permuteRecursive(nums, result, 0);
    return result;
}

void printPermutations(const std::vector<std::vector<int>>& perms) {
    for (const auto& p : perms) {
        std::cout << "[";
        for (size_t i = 0; i < p.size(); ++i) {
            std::cout << p[i];
            if (i < p.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<std::vector<int>> result1 = permute(nums1);
    std::cout << "Permutations for [1,2,3]:\n";
    printPermutations(result1);
    return 0;
}
```

**Time Complexity:** O(N * N!) where N is the number of elements. There are N! permutations, and each takes O(N) to build/copy.
**Space Complexity:** O(N) for the recursion stack.

#### Problem 2: Subsets

**Description:** Given an integer array `nums` of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.

**Example:**
Input: `nums = [1,2,3]`
Output: `[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]`

**Approach:**
Use a recursive backtracking function. At each element, we have two choices: either include the element in the current subset or exclude it. Recursively explore both paths.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void subsetsRecursive(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& current_subset, int start_index) {
    // Add the current subset to the result list
    result.push_back(current_subset);

    // Explore further elements
    for (int i = start_index; i < nums.size(); ++i) {
        current_subset.push_back(nums[i]); // Include current element
        subsetsRecursive(nums, result, current_subset, i + 1); // Recurse with next element
        current_subset.pop_back(); // Backtrack: remove current element
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_subset;
    subsetsRecursive(nums, result, current_subset, 0);
    return result;
}

void printSubsets(const std::vector<std::vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i];
            if (i < subset.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<std::vector<int>> result1 = subsets(nums1);
    std::cout << "Subsets for [1,2,3]:\n";
    printSubsets(result1);

    return 0;
}
```

**Time Complexity:** O(N * 2^N) because there are 2^N subsets, and each subset can take up to O(N) time to copy to the result list.
**Space Complexity:** O(N) for the recursion stack and current subset.

#### Problem 3: Combination Sum

**Description:** Given a set of candidate numbers `candidates` (without duplicates) and a target number `target`, find all unique combinations in `candidates` where the candidate numbers sum to `target`. The same repeated number may be chosen from `candidates` unlimited number of times.

**Example:**
Input: `candidates = [2,3,6,7]`, `target = 7`
Output: `[[2,2,3],[7]]`

**Approach:** (Already covered in Recursion section, but a classic backtracking example)
Use a recursive function that explores combinations. At each step, either include the current candidate number or exclude it. If included, subtract it from the target and recurse with the same candidate (since numbers can be reused). If excluded, move to the next candidate. Ensure to handle the base cases (target reached or target becomes negative).

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void combinationSumRecursive(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current_combination, int start_index) {
    if (target == 0) {
        result.push_back(current_combination);
        return;
    }

    if (target < 0 || start_index == candidates.size()) {
        return;
    }

    // Option 1: Include the current candidate
    current_combination.push_back(candidates[start_index]);
    combinationSumRecursive(candidates, target - candidates[start_index], result, current_combination, start_index);
    current_combination.pop_back(); // Backtrack

    // Option 2: Exclude the current candidate
    combinationSumRecursive(candidates, target, result, current_combination, start_index + 1);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_combination;
    combinationSumRecursive(candidates, target, result, current_combination, 0);
    return result;
}

void printCombinations(const std::vector<std::vector<int>>& combinations) {
    for (const auto& combo : combinations) {
        std::cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            std::cout << combo[i];
            if (i < combo.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    std::vector<std::vector<int>> result1 = combinationSum(candidates1, target1);
    std::cout << "Combinations for target 7 with [2,3,6,7]:\n";
    printCombinations(result1);
    return 0;
}
```

**Time Complexity:** Exponential, depends on the number of valid combinations. Roughly O(2^T * N) where T is the target and N is the number of candidates.
**Space Complexity:** O(T) for the recursion stack and current combination.

#### Problem 4: N-Queens Problem

**Description:** The N-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other. Given an integer `n`, return all distinct solutions to the N-queens puzzle.

**Example:**
Input: `n = 4`
Output: `[[.Q..,...Q,Q...,..Q.],[..Q.,Q...,...Q,.Q..]]` (Visual representation of two solutions)

**Approach:** (Already covered in Recursion section, but a classic backtracking example)
Use a recursive function to place queens row by row. For each row, try placing a queen in each column. Before placing, check if the position is safe (no other queen attacks it horizontally, vertically, or diagonally). If safe, place the queen and recurse for the next row. If not safe, or if the recursive call doesn't lead to a solution, backtrack by removing the queen and trying the next column.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>

class NQueensSolver {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, "."));
        solve(0, n, board, result);
        return result;
    }

private:
    bool isSafe(int row, int col, int n, const std::vector<std::string>& board) {
        // Check row
        for (int j = 0; j < col; ++j) {
            if (board[row][j] == 'Q') return false;
        }

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(int col, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board, result);
                board[row][col] = '.'; // Backtrack
            }
        }
    }
};

void printSolutions(const std::vector<std::vector<std::string>>& solutions) {
    for (const auto& solution : solutions) {
        for (const std::string& row : solution) {
            std::cout << row << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    NQueensSolver solver;
    int n = 4;
    std::vector<std::vector<std::string>> solutions = solver.solveNQueens(n);
    std::cout << "Solutions for " << n << "-Queens problem:\n";
    printSolutions(solutions);
    return 0;
}
```

**Time Complexity:** Roughly O(N!) in practice due to pruning. Worst case is O(N^N).
**Space Complexity:** O(N^2) for the board and O(N) for the recursion stack.

#### Problem 5: Sudoku Solver

**Description:** Write a program to solve a Sudoku puzzle by filling the empty cells. A Sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must appear exactly once in each row.
2. Each of the digits 1-9 must appear exactly once in each column.
3. Each of the digits 1-9 must appear exactly once in each of the nine 3x3 sub-boxes of the grid.

The `.` character indicates empty cells.

**Example:**
Input (partial): `board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]`
Output (solved board):
`5 3 4 6 7 8 9 1 2`
`6 7 2 1 9 5 3 4 8`
`1 9 8 3 4 2 5 6 7`
`8 5 9 7 6 1 4 2 3`
`4 2 6 8 5 3 7 9 1`
`7 1 3 9 2 4 8 5 6`
`9 6 1 5 3 7 2 8 4`
`2 8 7 4 1 9 6 3 5`
`3 4 5 2 8 6 1 7 9`

**Approach:**
Use a recursive backtracking function. Find an empty cell. Try placing digits from 1 to 9 in that cell. For each digit, check if it's valid according to Sudoku rules. If valid, place the digit and recursively call the function for the next empty cell. If the recursive call returns `true` (meaning a solution was found), return `true`. If no digit works for the current cell, backtrack by resetting the cell to `.` and return `false`.

**Solution (C++ - Conceptual):**

```cpp
#include <vector>
#include <string>
#include <iostream>

class SudokuSolver {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, r, c, num)) {
                            board[r][c] = num;
                            if (solve(board)) {
                                return true;
                            }
                            board[r][c] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number for this cell
                }
            }
        }
        return true; // All cells filled
    }

    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char num) {
        // Check row
        for (int x = 0; x < 9; ++x) {
            if (board[row][x] == num) return false;
        }

        // Check column
        for (int x = 0; x < 9; ++x) {
            if (board[x][col] == num) return false;
        }

        // Check 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i + startRow][j + startCol] == num) return false;
            }
        }
        return true;
    }
};

void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    SudokuSolver solver;
    solver.solveSudoku(board);

    std::cout << "Solved Sudoku:\n";
    printBoard(board);

    return 0;
}
```

**Time Complexity:** The worst-case time complexity is exponential, but with effective pruning, it performs much better. Roughly O(9^(N*N)) without pruning, where N is the side length of the grid. In practice, it's much faster.
**Space Complexity:** O(N^2) for the board and O(N^2) for the recursion stack in the worst case.

#### Problem 6: Combination Sum II

**Description:** Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`. Each number in `candidates` may only be used once in the combination. The solution set must not contain duplicate combinations.

**Example:**
Input: `candidates = [10,1,2,7,6,1,5]`, `target = 8`
Output: `[[1,1,6],[1,2,5],[1,7],[2,6]]`

**Approach:**
This is similar to Combination Sum, but with two key differences: each number can be used only once, and the result must not contain duplicate combinations. To handle duplicates, sort the `candidates` array and skip duplicate elements during recursion.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void combinationSum2Recursive(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current_combination, int start_index) {
    if (target == 0) {
        result.push_back(current_combination);
        return;
    }

    if (target < 0) {
        return;
    }

    for (int i = start_index; i < candidates.size(); ++i) {
        // Skip duplicates
        if (i > start_index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        current_combination.push_back(candidates[i]);
        combinationSum2Recursive(candidates, target - candidates[i], result, current_combination, i + 1); // i + 1 because each number can be used once
        current_combination.pop_back(); // Backtrack
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_combination;
    std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    combinationSum2Recursive(candidates, target, result, current_combination, 0);
    return result;
}

void printCombinations(const std::vector<std::vector<int>>& combinations) {
    for (const auto& combo : combinations) {
        std::cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            std::cout << combo[i];
            if (i < combo.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    std::vector<std::vector<int>> result1 = combinationSum2(candidates1, target1);
    std::cout << "Combinations for target 8 with [10,1,2,7,6,1,5]:\n";
    printCombinations(result1);

    std::vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    std::vector<std::vector<int>> result2 = combinationSum2(candidates2, target2);
    std::cout << "\nCombinations for target 5 with [2,5,2,1,2]:\n";
    printCombinations(result2);

    return 0;
}
```

**Time Complexity:** Exponential, roughly O(2^N) in the worst case, where N is the number of candidates. Sorting takes O(N log N).
**Space Complexity:** O(N) for the recursion stack and current combination.

#### Problem 7: Palindrome Partitioning

**Description:** Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`.

**Example:**
Input: `s = "aab"`
Output: `[["a","a","b"],["aa","b"]]`

**Approach:**
Use a recursive backtracking function. Iterate through all possible prefixes of the string. If a prefix is a palindrome, add it to the current partition and recursively call the function for the remaining suffix of the string. After the recursive call, backtrack by removing the prefix.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class PalindromePartitioning {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current_partition;
        backtrack(s, 0, current_partition, result);
        return result;
    }

private:
    bool isPalindrome(const std::string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }

    void backtrack(const std::string& s, int start, std::vector<std::string>& current_partition, std::vector<std::vector<std::string>>& result) {
        if (start == s.length()) {
            result.push_back(current_partition);
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                current_partition.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, current_partition, result);
                current_partition.pop_back(); // Backtrack
            }
        }
    }
};

void printPartitions(const std::vector<std::vector<std::string>>& partitions) {
    for (const auto& partition : partitions) {
        std::cout << "[";
        for (size_t i = 0; i < partition.size(); ++i) {
            std::cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

int main() {
    PalindromePartitioning solver;
    std::string s1 = "aab";
    std::vector<std::vector<std::string>> result1 = solver.partition(s1);
    std::cout << "Partitions for \"aab\":\n";
    printPartitions(result1);

    std::string s2 = "a";
    std::vector<std::vector<std::string>> result2 = solver.partition(s2);
    std::cout << "\nPartitions for \"a\":\n";
    printPartitions(result2);

    return 0;
}
```

**Time Complexity:** Exponential. In the worst case, it can be O(N * 2^N) where N is the length of the string, as there are 2^(N-1) ways to partition a string, and checking palindrome takes O(N).
**Space Complexity:** O(N) for recursion stack and current partition.

#### Problem 8: Rat in a Maze

**Description:** Consider a maze represented by an `N x N` matrix where each cell can either be blocked (0) or open (1). A rat starts at `(0,0)` and needs to reach `(N-1, N-1)`. The rat can move only in `Up`, `Down`, `Left`, and `Right` directions. Find all possible paths that the rat can take to reach the destination.

**Example:**
Input: `maze = [[1, 0, 0, 0],[1, 1, 0, 1],[1, 1, 0, 0],[0, 1, 1, 1]]`
Output: `DDRDRR DRDDRR` (Paths represented by directions)

**Approach:**
Use a recursive backtracking function. Start at `(0,0)`. Mark the current cell as visited. Explore all four possible directions. If a move is valid (within bounds, not blocked, not visited), make the move, append the direction to the current path, and recursively call the function for the new cell. After the recursive call, backtrack by unmarking the cell and removing the direction from the path.

**Solution (C++ - Conceptual):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class RatInMazeSolver {
public:
    std::vector<std::string> findPath(std::vector<std::vector<int>>& m, int n) {
        std::vector<std::string> result;
        std::string current_path = "";
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        if (m[0][0] == 0) return {}; // Start is blocked

        solve(0, 0, m, n, result, current_path, visited);
        std::sort(result.begin(), result.end()); // Sort paths lexicographically
        return result;
    }

private:
    void solve(int r, int c, std::vector<std::vector<int>>& m, int n, 
               std::vector<std::string>& result, std::string& current_path, 
               std::vector<std::vector<bool>>& visited) {
        
        // Base case: Reached destination
        if (r == n - 1 && c == n - 1) {
            result.push_back(current_path);
            return;
        }

        // Mark current cell as visited
        visited[r][c] = true;

        // Try all 4 directions (Down, Left, Right, Up)
        // Down
        if (r + 1 < n && m[r + 1][c] == 1 && !visited[r + 1][c]) {
            current_path.push_back('D');
            solve(r + 1, c, m, n, result, current_path, visited);
            current_path.pop_back(); // Backtrack
        }
        // Left
        if (c - 1 >= 0 && m[r][c - 1] == 1 && !visited[r][c - 1]) {
            current_path.push_back('L');
            solve(r, c - 1, m, n, result, current_path, visited);
            current_path.pop_back(); // Backtrack
        }
        // Right
        if (c + 1 < n && m[r][c + 1] == 1 && !visited[r][c + 1]) {
            current_path.push_back('R');
            solve(r, c + 1, m, n, result, current_path, visited);
            current_path.pop_back(); // Backtrack
        }
        // Up
        if (r - 1 >= 0 && m[r - 1][c] == 1 && !visited[r - 1][c]) {
            current_path.push_back('U');
            solve(r - 1, c, m, n, result, current_path, visited);
            current_path.pop_back(); // Backtrack
        }

        // Unmark current cell as visited (backtrack)
        visited[r][c] = false;
    }
};

void printPaths(const std::vector<std::string>& paths) {
    for (const std::string& path : paths) {
        std::cout << path << " ";
    }
    std::cout << "\n";
}

int main() {
    RatInMazeSolver solver;
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;

    std::vector<std::string> paths = solver.findPath(maze, n);
    std::cout << "Paths for Rat in a Maze:\n";
    printPaths(paths);

    return 0;
}
```

**Time Complexity:** Exponential, roughly O(4^(N*N)) in the worst case (exploring all paths), but significantly reduced by pruning.
**Space Complexity:** O(N^2) for the visited array and recursion stack.

#### Problem 9: M-Coloring Problem

**Description:** Given an undirected graph and an integer `M`, determine if the graph can be colored with at most `M` colors such that no two adjacent vertices have the same color.

**Example:**
Input: `graph = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}}`, `M = 3`
Output: `true` (A valid coloring exists)

**Approach:**
Use a recursive backtracking function. Assign colors to vertices one by one. For each vertex, try assigning a color from 1 to `M`. Before assigning, check if the color is safe (i.e., not used by any adjacent vertex). If safe, assign the color and recursively call the function for the next vertex. If the recursive call returns `true`, return `true`. If no color works for the current vertex, backtrack by unassigning the color and return `false`.

**Solution (C++ - Conceptual):**

```cpp
#include <iostream>
#include <vector>

class MColoringSolver {
public:
    bool graphColoring(std::vector<std::vector<int>>& graph, int m, int n) {
        std::vector<int> colors(n, 0); // 0 means no color assigned
        return solve(0, graph, m, n, colors);
    }

private:
    bool isSafe(int v, const std::vector<std::vector<int>>& graph, const std::vector<int>& colors, int c, int n) {
        for (int i = 0; i < n; ++i) {
            if (graph[v][i] == 1 && colors[i] == c) {
                return false; // Adjacent vertex has same color
            }
        }
        return true;
    }

    bool solve(int v, const std::vector<std::vector<int>>& graph, int m, int n, std::vector<int>& colors) {
        // Base case: All vertices are colored
        if (v == n) {
            return true;
        }

        // Try different colors for vertex v
        for (int c = 1; c <= m; ++c) {
            if (isSafe(v, graph, colors, c, n)) {
                colors[v] = c; // Assign color
                if (solve(v + 1, graph, m, n, colors)) {
                    return true;
                }
                colors[v] = 0; // Backtrack: remove color
            }
        }
        return false; // No valid color for this vertex
    }
};

int main() {
    MColoringSolver solver;
    int n = 4; // Number of vertices
    int m = 3; // Number of colors
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (solver.graphColoring(graph, m, n)) {
        std::cout << "Graph can be colored with " << m << " colors.\n";
    } else {
        std::cout << "Graph cannot be colored with " << m << " colors.\n";
    }

    return 0;
}
```

**Time Complexity:** Exponential, roughly O(M^N) in the worst case, where N is the number of vertices and M is the number of colors. Pruning significantly reduces this.
**Space Complexity:** O(N) for the colors array and recursion stack.

#### Problem 10: Word Search

**Description:** Given an `m x n` grid of characters and a string `word`, return `true` if `word` exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example:**
Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]`, `word = "ABCCED"`
Output: `true`

**Approach:**
Use a recursive backtracking (DFS) function. Iterate through each cell in the grid. If a cell matches the first character of the `word`, start a DFS from that cell. In the DFS, mark the current cell as visited. Explore all four adjacent cells. If an adjacent cell matches the next character in the `word`, recursively call DFS for that cell. If the word is fully matched, return `true`. If no path leads to a solution from the current cell, backtrack by unmarking the cell.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>

class WordSearchSolver {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, 
             int r, int c, int word_idx, int m, int n) {
        
        // Base case: Word found
        if (word_idx == word.length()) {
            return true;
        }

        // Boundary conditions or mismatch
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[word_idx]) {
            return false;
        }

        char original_char = board[r][c];
        board[r][c] = '#'; // Mark as visited

        // Explore 4 directions
        bool found = dfs(board, word, r + 1, c, word_idx + 1, m, n) ||
                     dfs(board, word, r - 1, c, word_idx + 1, m, n) ||
                     dfs(board, word, r, c + 1, word_idx + 1, m, n) ||
                     dfs(board, word, r, c - 1, word_idx + 1, m, n);

        board[r][c] = original_char; // Backtrack
        return found;
    }
};

int main() {
    WordSearchSolver solver;
    std::vector<std::vector<char>> board1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::string word1 = "ABCCED";
    std::cout << "Word \"ABCCED\" exists: " << (solver.exist(board1, word1) ? "True" : "False") << "\n"; // Expected: True

    std::vector<std::vector<char>> board2 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::string word2 = "SEE";
    std::cout << "Word \"SEE\" exists: " << (solver.exist(board2, word2) ? "True" : "False") << "\n"; // Expected: True

    std::vector<std::vector<char>> board3 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::string word3 = "ABCB";
    std::cout << "Word \"ABCB\" exists: " << (solver.exist(board3, word3) ? "True" : "False") << "\n"; // Expected: False

    return 0;
}
```

**Time Complexity:** O(M * N * 4^L) where M is rows, N is columns, and L is word length. In the worst case, for each cell, we might explore all 4 directions for the length of the word.
**Space Complexity:** O(L) for the recursion stack.

---

### References

[1] GeeksforGeeks. "Introduction to Backtracking." *GeeksforGeeks*, 24 Jun. 2024, www.geeksforgeeks.org/introduction-to-backtracking-2/.
[2] Medium. "Backtracking explained." *Medium*, 7 Oct. 2017, medium.com/@andreaiacono/backtracking-explained-7450d6ef9e1a.

---



### 4.5 String Algorithms (Z-algorithm, KMP, Rabin-Karp)

String matching algorithms are a fundamental part of computer science, used to find the occurrences of a "pattern" string within a larger "text" string. Here, we will cover three important linear-time string matching algorithms: Z-algorithm, Knuth-Morris-Pratt (KMP), and Rabin-Karp.

#### 4.5.1 Z-Algorithm

**Concept:**
The Z-algorithm computes a "Z-array" for a given string `S`. The Z-array `Z` is of the same length as `S`, where `Z[i]` is the length of the longest substring starting from `S[i]` which is also a prefix of `S`. `Z[0]` is conventionally set to 0 [1, 2].

**Analogy:** Imagine you have a long ribbon with a repeating pattern at the beginning. To find all occurrences of this initial pattern throughout the ribbon, you can, for each position, measure how long the pattern starting from that position matches the initial pattern. The Z-array stores these measurements.

**How it works for Pattern Matching:**
To find a pattern `P` in a text `T`, we create a new string `S = P + "$" + T`, where `$` is a character that does not appear in `P` or `T`. We then compute the Z-array for `S`. If `Z[i]` is equal to the length of `P` for some `i`, it means that the substring of `S` starting at `i` is equal to `P`. Since `i` is in the part of `S` corresponding to `T`, this indicates an occurrence of `P` in `T`.

**Solution (C++ - Z-array computation):**

```cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<int> calculateZArray(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n, 0);
    int l = 0, r = 0; // [l, r] is the current Z-box (prefix-substring)

    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void searchWithZAlgorithm(const std::string& text, const std::string& pattern) {
    std::string combined = pattern + "$" + text;
    std::vector<int> z = calculateZArray(combined);
    int pattern_len = pattern.length();

    std::cout << "Pattern found at indices: ";
    for (int i = 0; i < combined.length(); ++i) {
        if (z[i] == pattern_len) {
            std::cout << (i - pattern_len - 1) << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::string text = "ababaabcababa";
    std::string pattern = "aba";
    searchWithZAlgorithm(text, pattern);

    text = "aaaaa";
    pattern = "aa";
    searchWithZAlgorithm(text, pattern);

    return 0;
}
```

**Time Complexity:** O(N + M) where N is the length of the text and M is the length of the pattern.
**Space Complexity:** O(N + M) for the combined string and Z-array.

#### 4.5.2 Knuth-Morris-Pratt (KMP) Algorithm

**Concept:**
The KMP algorithm improves upon the naive string matching approach by using information from previous matches to avoid redundant comparisons. It preprocesses the pattern to create a Longest Proper Prefix Suffix (LPS) array, also known as a failure function. The LPS array `lps` for a pattern `P` stores, for each position `i`, the length of the longest proper prefix of `P[0...i]` that is also a suffix of `P[0...i]` [3, 4].

**Analogy:** Imagine you are looking for a specific word in a book. When you find a partial match that then fails, instead of starting your search from the next character, you use your knowledge of the word's structure to jump ahead. For example, if you are looking for "abracadabra" and you've matched "abracadab" and the next character is not 'r', you know you don't have to re-check the 'a' at the beginning of your pattern because the 'ab' at the end of your partial match can align with the 'ab' at the start of the pattern.

**How it works:**
1.  **Preprocessing (LPS array):** Compute the `lps` array for the pattern.
2.  **Matching:** Use two pointers, one for the text (`i`) and one for the pattern (`j`).
    -   If `text[i] == pattern[j]`, increment both `i` and `j`.
    -   If a mismatch occurs (`text[i] != pattern[j]`):
        -   If `j != 0`, it means there was a partial match. We can skip some comparisons by moving `j` to `lps[j-1]`. We don't move `i`.
        -   If `j == 0`, there was no partial match, so just increment `i`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>

// Function to compute LPS array
std::vector<int> computeLPSArray(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void searchWithKMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeLPSArray(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern

    std::cout << "Pattern found at indices: ";
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            std::cout << (i - j) << " ";
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    std::cout << "\n";
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    searchWithKMP(text, pattern);

    text = "AAAAABAAABA";
    pattern = "AAAA";
    searchWithKMP(text, pattern);

    return 0;
}
```

**Time Complexity:** O(N + M) where N is the length of the text and M is the length of the pattern.
**Space Complexity:** O(M) for the LPS array.

#### 4.5.3 Rabin-Karp Algorithm

**Concept:**
The Rabin-Karp algorithm uses hashing to find occurrences of a pattern in a text. It calculates a hash value for the pattern and for each substring of the text of the same length as the pattern. If the hash values match, it then performs a character-by-character comparison to confirm the match (to handle hash collisions) [5, 6].

**Analogy:** Imagine you want to find if a specific book is in a library. Instead of comparing the entire book content, you first compare a unique identifier (like an ISBN number) of your book with the ISBNs of all books in the library. If the ISBNs match, you then verify the book's title and author to be sure. The hash value is like the ISBN.

**How it works (Rolling Hash):**
1.  Calculate the hash of the pattern and the first window of the text.
2.  Slide the window one position at a time in the text.
3.  Instead of re-calculating the hash for each new window from scratch, use a "rolling hash" function to efficiently update the hash in O(1) time. This involves removing the contribution of the character leaving the window and adding the contribution of the character entering the window.
4.  If the hash of the current window matches the pattern's hash, perform a direct comparison to check for a true match.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>

void searchWithRabinKarp(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int d = 256; // Number of characters in the input alphabet
    int q = 101; // A prime number
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    std::cout << "Pattern found at indices: ";
    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                std::cout << i << " ";
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + q);
        }
    }
    std::cout << "\n";
}

int main() {
    std::string text = "GEEKS FOR GEEKS";
    std::string pattern = "GEEK";
    searchWithRabinKarp(text, pattern);

    text = "AABAACAADAABAABA";
    pattern = "AABA";
    searchWithRabinKarp(text, pattern);

    return 0;
}
```

**Time Complexity:**
-   **Average and Best Case:** O(N + M)
-   **Worst Case:** O(N * M) (occurs when there are many hash collisions, e.g., text="AAAAA" and pattern="AAA").
**Space Complexity:** O(1).

### 4.5.4 Practice Problems (String Algorithms)

Here are 10 handpicked important problems related to String Algorithms, along with their solutions in C++ and complexity analysis.

#### Problem 1: Find the Index of the First Occurrence in a String (LeetCode 28)

**Description:** Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or -1 if `needle` is not part of `haystack`.

**Approach:** This is a direct application of KMP or Rabin-Karp. KMP is generally preferred for its guaranteed linear time complexity.

**Solution (C++ - KMP):**

```cpp
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) return 0;

        std::vector<int> lps = computeLPS(needle);
        int i = 0, j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j;
            }
            if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }

private:
    std::vector<int> computeLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int length = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution sol;
    std::cout << "Index of \"sad\" in \"sadbutsad\": " << sol.strStr("sadbutsad", "sad") << "\n"; // Expected: 0
    std::cout << "Index of \"leeto\" in \"leetcode\": " << sol.strStr("leetcode", "leeto") << "\n"; // Expected: -1
    return 0;
}
```

**Time Complexity:** O(N + M)
**Space Complexity:** O(M)

#### Problem 2: Shortest Palindrome (LeetCode 214)

**Description:** You are given a string `s`. You can convert `s` to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

**Approach:**
1.  Find the longest palindromic prefix of `s`. Let this be `s[0...i]`.
2.  The remaining part of the string, `s[i+1...n-1]`, needs to be reversed and prepended to the original string `s`.
3.  To find the longest palindromic prefix efficiently, we can use KMP. Create a new string `temp = s + "#" + reverse(s)`. The length of the longest palindromic prefix of `s` is given by the last value in the LPS array of `temp`.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        std::string rev_s = s;
        std::reverse(rev_s.begin(), rev_s.end());
        std::string temp = s + "#" + rev_s;
        std::vector<int> lps = computeLPS(temp);
        int palindrome_len = lps.back();
        std::string to_add = s.substr(palindrome_len);
        std::reverse(to_add.begin(), to_add.end());
        return to_add + s;
    }

private:
    std::vector<int> computeLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int length = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution sol;
    std::cout << "Shortest palindrome for \"aacecaaa\": " << sol.shortestPalindrome("aacecaaa") << "\n"; // Expected: "aaacecaaa"
    std::cout << "Shortest palindrome for \"abcd\": " << sol.shortestPalindrome("abcd") << "\n"; // Expected: "dcbabcd"
    return 0;
}
```

**Time Complexity:** O(N) where N is the length of the string.
**Space Complexity:** O(N) for the temporary string and LPS array.

#### Problem 3: Repeated Substring Pattern (LeetCode 459)

**Description:** Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

**Approach:**
1.  A string `s` of length `n` has a repeating substring pattern if and only if `s` is a proper prefix of `s + s` (i.e., `(s+s).substr(1, 2*n - 2)` contains `s`).
2.  Another approach using KMP: Compute the LPS array for `s`. If `lps.back() > 0` and `n % (n - lps.back()) == 0`, then the string has a repeating pattern. The length of the repeating substring is `n - lps.back()`.

**Solution (C++ - KMP):**

```cpp
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        int n = s.length();
        std::vector<int> lps = computeLPS(s);
        int len = lps.back();
        return (len > 0 && n % (n - len) == 0);
    }

private:
    std::vector<int> computeLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int length = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution sol;
    std::cout << "\"abab\" has repeated pattern: " << (sol.repeatedSubstringPattern("abab") ? "True" : "False") << "\n"; // Expected: True
    std::cout << "\"aba\" has repeated pattern: " << (sol.repeatedSubstringPattern("aba") ? "True" : "False") << "\n"; // Expected: False
    std::cout << "\"abcabcabcabc\" has repeated pattern: " << (sol.repeatedSubstringPattern("abcabcabcabc") ? "True" : "False") << "\n"; // Expected: True
    return 0;
}
```

**Time Complexity:** O(N)
**Space Complexity:** O(N)

#### Problem 4: Longest Happy Prefix (LeetCode 1392)

**Description:** A string is called a "happy prefix" if it is a non-empty prefix of the string which is also a suffix of the string (excluding the string itself). Given a string `s`, return its longest happy prefix.

**Approach:** This is a direct application of the KMP's LPS array. The length of the longest happy prefix is `lps.back()`. We just need to return the substring of that length.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestPrefix(std::string s) {
        int n = s.length();
        std::vector<int> lps = computeLPS(s);
        int len = lps.back();
        return s.substr(0, len);
    }

private:
    std::vector<int> computeLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int length = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution sol;
    std::cout << "Longest happy prefix of \"level\": " << sol.longestPrefix("level") << "\n"; // Expected: "l"
    std::cout << "Longest happy prefix of \"ababab\": " << sol.longestPrefix("ababab") << "\n"; // Expected: "abab"
    std::cout << "Longest happy prefix of \"leetcodeleet\": " << sol.longestPrefix("leetcodeleet") << "\n"; // Expected: "leet"
    return 0;
}
```

**Time Complexity:** O(N)
**Space Complexity:** O(N)

#### Problem 5: String Matching in an Array (LeetCode 1408)

**Description:** Given an array of string `words`, return all strings in `words` that are a substring of another word. You can return the answer in any order.

**Approach:**
For each word `word1` in the array, iterate through all other words `word2`. If `word1` is a substring of `word2` (and `word1` is not the same as `word2`), add `word1` to the result set. Using a set avoids duplicate entries.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> stringMatching(std::vector<std::string>& words) {
        std::unordered_set<std::string> result_set;
        for (const std::string& word1 : words) {
            for (const std::string& word2 : words) {
                if (word1 == word2) continue;
                if (word2.find(word1) != std::string::npos) {
                    result_set.insert(word1);
                }
            }
        }
        return std::vector<std::string>(result_set.begin(), result_set.end());
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words1 = {"mass","as","hero","superhero"};
    std::vector<std::string> result1 = sol.stringMatching(words1);
    std::cout << "Matching strings in [mass,as,hero,superhero]: ";
    for(const auto& s : result1) std::cout << s << " "; // Expected: as hero
    std::cout << "\n";

    std::vector<std::string> words2 = {"leetcode","et","code"};
    std::vector<std::string> result2 = sol.stringMatching(words2);
    std::cout << "Matching strings in [leetcode,et,code]: ";
    for(const auto& s : result2) std::cout << s << " "; // Expected: et code
    std::cout << "\n";

    return 0;
}
```

**Time Complexity:** O(N^2 * L) where N is the number of words and L is the average length of words.
**Space Complexity:** O(N * L) for the result set.

#### Problem 6: Minimum Characters to be Added at Front to Make String Palindrome (GeeksForGeeks)

**Description:** Given a string `str`, find the minimum number of characters to be added at the front of the string to make it a palindrome.

**Approach:** This is the same problem as LeetCode's "Shortest Palindrome". We find the longest palindromic prefix of the string. The number of characters to add is `n - length_of_longest_palindromic_prefix`.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCharsForPalindrome(std::string str) {
        std::string rev_str = str;
        std::reverse(rev_str.begin(), rev_str.end());
        std::string temp = str + "$" + rev_str;
        std::vector<int> lps = computeLPS(temp);
        return str.length() - lps.back();
    }

private:
    std::vector<int> computeLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int length = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution sol;
    std::cout << "Min chars for \"AACECAAAA\": " << sol.minCharsForPalindrome("AACECAAAA") << "\n"; // Expected: 2
    std::cout << "Min chars for \"ABC\": " << sol.minCharsForPalindrome("ABC") << "\n"; // Expected: 2
    std::cout << "Min chars for \"BABABAA\": " << sol.minCharsForPalindrome("BABABAA") << "\n"; // Expected: 2
    return 0;
}
```

**Time Complexity:** O(N)
**Space Complexity:** O(N)

#### Problem 7: Check if a string is a rotated palindrome (GeeksForGeeks)

**Description:** Given a string, check if any of its rotations is a palindrome.

**Approach:**
1.  A simple approach is to generate all rotations of the string and check if any of them is a palindrome. This is O(N^2).
2.  A more efficient approach: Create a new string `temp = s + s`. Now, check if the reverse of `s` is a substring of `temp`. If it is, then a rotation of `s` is a palindrome.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isRotatedPalindrome(std::string s) {
        if (s.length() <= 1) return true;
        std::string temp = s + s;
        std::string rev_s = s;
        std::reverse(rev_s.begin(), rev_s.end());
        return temp.find(rev_s) != std::string::npos;
    }
};

int main() {
    Solution sol;
    std::cout << "Is \"aab\" a rotated palindrome? " << (sol.isRotatedPalindrome("aab") ? "Yes" : "No") << "\n"; // Expected: Yes (aba)
    std::cout << "Is \"abcde\" a rotated palindrome? " << (sol.isRotatedPalindrome("abcde") ? "Yes" : "No") << "\n"; // Expected: No
    std::cout << "Is \"aaaad\" a rotated palindrome? " << (sol.isRotatedPalindrome("aaaad") ? "Yes" : "No") << "\n"; // Expected: Yes (daaaa)
    return 0;
}
```

**Time Complexity:** O(N) for string concatenation and `find` (assuming efficient `find` implementation, which can be done with KMP).
**Space Complexity:** O(N) for the temporary strings.

#### Problem 8: Longest Common Substring (GeeksForGeeks)

**Description:** Given two strings, find the length of the longest common substring.

**Approach:** This is a classic dynamic programming problem. Define `dp[i][j]` as the length of the longest common substring ending at `text1[i-1]` and `text2[j-1]`. The recurrence is:
- If `text1[i-1] == text2[j-1]`, `dp[i][j] = dp[i-1][j-1] + 1`.
- Else, `dp[i][j] = 0`.
Keep track of the maximum value in the `dp` table.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestCommonSubstring(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int max_len = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_len = std::max(max_len, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return max_len;
}

int main() {
    std::cout << "LCS for \"GeeksforGeeks\" and \"GeeksQuiz\": " << longestCommonSubstring("GeeksforGeeks", "GeeksQuiz") << "\n"; // Expected: 5 (Geeks)
    std::cout << "LCS for \"abcdxyz\" and \"xyzabcd\": " << longestCommonSubstring("abcdxyz", "xyzabcd") << "\n"; // Expected: 4 (abcd)
    return 0;
}
```

**Time Complexity:** O(M * N)
**Space Complexity:** O(M * N)

#### Problem 9: Count of distinct substrings of a string (GeeksForGeeks)

**Description:** Given a string, count the number of distinct substrings.

**Approach:**
1.  Generate all substrings of the string.
2.  Insert them into a `std::unordered_set` to store only the unique ones.
3.  The size of the set is the answer.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <unordered_set>

int countDistinctSubstrings(const std::string& s) {
    std::unordered_set<std::string> distinct_substrings;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            distinct_substrings.insert(s.substr(i, j));
        }
    }
    return distinct_substrings.size();
}

int main() {
    std::cout << "Distinct substrings of \"ababa\": " << countDistinctSubstrings("ababa") << "\n"; // Expected: 9
    std::cout << "Distinct substrings of \"aaaa\": " << countDistinctSubstrings("aaaa") << "\n"; // Expected: 4
    return 0;
}
```

**Time Complexity:** O(N^3) in the worst case due to nested loops and `substr`. Can be optimized to O(N^2) with better data structures like Trie or Suffix Automaton.
**Space Complexity:** O(N^2) for the set.

#### Problem 10: Anagrams (GeeksForGeeks)

**Description:** Given two strings, check whether they are anagrams of each other.

**Approach:**
1.  **Sorting:** Sort both strings and check if they are equal. Time: O(N log N).
2.  **Counting:** Use a frequency array (or hash map) to count characters in the first string. Then, iterate through the second string, decrementing the counts. If all counts are zero at the end, they are anagrams. Time: O(N).

**Solution (C++ - Counting):**

```cpp
#include <iostream>
#include <string>
#include <vector>

bool areAnagrams(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    std::vector<int> count(256, 0);
    for (char c : s1) {
        count[c]++;
    }
    for (char c : s2) {
        count[c]--;
        if (count[c] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Are \"listen\" and \"silent\" anagrams? " << (areAnagrams("listen", "silent") ? "Yes" : "No") << "\n"; // Expected: Yes
    std::cout << "Are \"geeksforgeeks\" and \"forgeeksgeeks\" anagrams? " << (areAnagrams("geeksforgeeks", "forgeeksgeeks") ? "Yes" : "No") << "\n"; // Expected: Yes
    std::cout << "Are \"hello\" and \"world\" anagrams? " << (areAnagrams("hello", "world") ? "Yes" : "No") << "\n"; // Expected: No
    return 0;
}
```

**Time Complexity:** O(N) where N is the length of the strings.
**Space Complexity:** O(1) (or O(K) where K is the number of possible characters, which is constant).

---

### References

[1] GeeksforGeeks. "Z algorithm (Linear time pattern searching Algorithm)." *GeeksforGeeks*, 25 Feb. 2025, www.geeksforgeeks.org/dsa/z-algorithm-linear-time-pattern-searching-algorithm/.
[2] CP-Algorithms. "Z-function." *CP-Algorithms*, 14 May 2023, cp-algorithms.com/string/z-function.html.
[3] GeeksforGeeks. "KMP Algorithm for Pattern Searching." *GeeksforGeeks*, 25 Feb. 2025, www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/.
[4] Scaler. "KMP Algorithm | Knuth Morris Pratt Algorithm." *Scaler*, 12 Apr. 2024, www.scaler.com/topics/data-structures/kmp-algorithm/.
[5] GeeksforGeeks. "Rabin-Karp Algorithm for Pattern Searching." *GeeksforGeeks*, 3 Jun. 2025, www.geeksforgeeks.org/dsa/rabin-karp-algorithm-for-pattern-searching/.
[6] Brilliant. "Rabin-Karp Algorithm." *Brilliant*, brilliant.org/wiki/rabin-karp-algorithm/.

---



### 4.6 Subarrays & Prefix Sums

#### 4.6.1 Subarrays

A **subarray** is a contiguous part of an array. For an array `arr` of size `N`, a subarray is defined by a starting index `i` and an ending index `j` (where `0 <= i <= j < N`). It includes all elements `arr[i], arr[i+1], ..., arr[j]` [7].

**Example:** For `arr = [1, 2, 3, 4]`, some subarrays are:
- `[1]`
- `[2, 3]`
- `[1, 2, 3, 4]`

There are `N * (N + 1) / 2` possible subarrays in an array of size `N`.

#### 4.6.2 Prefix Sums

A **prefix sum array** (also known as a cumulative sum array or partial sum array) is a data structure that stores the cumulative sum of elements from the beginning of an array up to each index [1, 3]. It is primarily used to efficiently calculate the sum of any subarray in constant time after an initial linear-time setup [4, 16].

**Concept:**
Given an array `arr = [a0, a1, a2, ..., aN-1]`, its prefix sum array `prefixSum` is defined as:
- `prefixSum[0] = arr[0]`
- `prefixSum[i] = arr[0] + arr[1] + ... + arr[i]` for `i > 0`
   or equivalently, `prefixSum[i] = prefixSum[i-1] + arr[i]`

**Example:** For `arr = [1, 2, 3, 4]`:
- `prefixSum[0] = 1`
- `prefixSum[1] = 1 + 2 = 3`
- `prefixSum[2] = 1 + 2 + 3 = 6`
- `prefixSum[3] = 1 + 2 + 3 + 4 = 10`
So, `prefixSum = [1, 3, 6, 10]`

**Calculating Subarray Sum using Prefix Sums:**
The sum of a subarray from index `i` to `j` (inclusive) can be calculated as:
`sum(arr[i...j]) = prefixSum[j] - prefixSum[i-1]`
(If `i = 0`, then `sum(arr[0...j]) = prefixSum[j]`)

**Advantages:**
-   **O(1) query time:** Once the prefix sum array is built (which takes O(N) time), any subarray sum can be queried in constant time.
-   **Optimization:** It helps optimize problems involving range queries, subarray sums, and balance conditions [6].

**Common Techniques/Patterns:**
-   **1D Prefix Sum:** For one-dimensional arrays.
-   **2D Prefix Sum:** For two-dimensional arrays (matrices) to calculate submatrix sums.
-   **Prefix Sum with Hash Map:** Used to find subarrays with a specific sum, or problems involving counts of sums.

### 4.6.3 Practice Problems (Subarrays & Prefix Sums)

Here are 10 handpicked important problems related to Subarrays & Prefix Sums, along with their solutions in C++ and complexity analysis.

#### Problem 1: Running Sum of 1d Array (LeetCode 1480)

**Description:** Given an array `nums`, return the running sum of `nums`. The running sum of an array is defined as `runningSum[i] = sum(nums[0]…nums[i])`.

**Example:**
Input: `nums = [1,2,3,4]`
Output: `[1,3,6,10]`

**Approach:** This is a direct application of the prefix sum concept. Iterate through the array and accumulate the sum.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::partial_sum (though not strictly necessary for this problem)

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> result(nums.size());
        if (nums.empty()) return result;

        result[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result[i] = result[i - 1] + nums[i];
        }
        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::cout << "Running sum of [1,2,3,4]: ";
    printVector(sol.runningSum(nums1)); // Expected: [1,3,6,10]

    std::vector<int> nums2 = {1, 1, 1, 1, 1};
    std::cout << "Running sum of [1,1,1,1,1]: ";
    printVector(sol.runningSum(nums2)); // Expected: [1,2,3,4,5]

    return 0;
}
```

**Time Complexity:** O(N) where N is the size of the array.
**Space Complexity:** O(N) for the result array (can be O(1) if modifying in-place).

#### Problem 2: Find Pivot Index (LeetCode 724)

**Description:** Given an array of integers `nums`, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the right of the index. If no such index exists, return -1.

**Example:**
Input: `nums = [1,7,3,6,5,6]`
Output: `3`
Explanation: The pivot index is 3. Left sum = `1 + 7 + 3 = 11`. Right sum = `5 + 6 = 11`.

**Approach:**
1.  Calculate the total sum of the array.
2.  Iterate through the array, maintaining a `left_sum`. The `right_sum` can be calculated as `total_sum - left_sum - nums[i]`.
3.  If `left_sum == right_sum`, then `i` is the pivot index.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    std::cout << "Pivot index for [1,7,3,6,5,6]: " << sol.pivotIndex(nums1) << "\n"; // Expected: 3

    std::vector<int> nums2 = {1, 2, 3};
    std::cout << "Pivot index for [1,2,3]: " << sol.pivotIndex(nums2) << "\n"; // Expected: -1

    std::vector<int> nums3 = {2, 1, -1};
    std::cout << "Pivot index for [2,1,-1]: " << sol.pivotIndex(nums3) << "\n"; // Expected: 0

    return 0;
}
```

**Time Complexity:** O(N) for calculating total sum and O(N) for iterating and checking, so O(N).
**Space Complexity:** O(1).

#### Problem 3: Subarray Sum Equals K (LeetCode 560)

**Description:** Given an array of integers `nums` and an integer `k`, return the total number of continuous subarrays whose sum equals `k`.

**Example:**
Input: `nums = [1,1,1]`, `k = 2`
Output: `2` (Subarrays are `[1,1]` from index 0 and `[1,1]` from index 1)

**Approach (Prefix Sum with Hash Map):**
1.  Maintain a running `current_sum`.
2.  Use a hash map (`std::unordered_map`) to store the frequency of prefix sums encountered so far. Initialize `map[0] = 1` to handle cases where the subarray itself starts from index 0 and sums to `k`.
3.  For each element, update `current_sum`. Check if `current_sum - k` exists in the map. If it does, add its frequency to the `count` of subarrays.
4.  Increment the frequency of `current_sum` in the map.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        int current_sum = 0;
        std::unordered_map<int, int> prefix_sum_freq;
        prefix_sum_freq[0] = 1; // To handle subarrays starting from index 0

        for (int num : nums) {
            current_sum += num;
            if (prefix_sum_freq.count(current_sum - k)) {
                count += prefix_sum_freq[current_sum - k];
            }
            prefix_sum_freq[current_sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    std::cout << "Subarrays summing to " << k1 << " in [1,1,1]: " << sol.subarraySum(nums1, k1) << "\n"; // Expected: 2

    std::vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    std::cout << "Subarrays summing to " << k2 << " in [1,2,3]: " << sol.subarraySum(nums2, k2) << "\n"; // Expected: 2 ([1,2] and [3])

    std::vector<int> nums3 = {1, -1, 0};
    int k3 = 0;
    std::cout << "Subarrays summing to " << k3 << " in [1,-1,0]: " << sol.subarraySum(nums3, k3) << "\n"; // Expected: 3 ([1,-1], [0], [1,-1,0])

    return 0;
}
```

**Time Complexity:** O(N) on average, as hash map operations take O(1) on average.
**Space Complexity:** O(N) for the hash map in the worst case.

#### Problem 4: Maximum Subarray (Kadane's Algorithm) (LeetCode 53)

**Description:** Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

**Example:**
Input: `nums = [-2,1,-3,4,-1,2,1,-5,4]`
Output: `6` (Subarray `[4,-1,2,1]` has the largest sum = 6)

**Approach (Kadane's Algorithm):**
This is a classic dynamic programming problem that can be solved efficiently. Maintain two variables:
1.  `current_max`: The maximum sum of a subarray ending at the current position.
2.  `global_max`: The overall maximum sum found so far.

Iterate through the array. For each element, `current_max = max(num, current_max + num)`. Update `global_max = max(global_max, current_max)`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For std::numeric_limits

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int current_max = nums[0];
        int global_max = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            current_max = std::max(nums[i], current_max + nums[i]);
            global_max = std::max(global_max, current_max);
        }
        return global_max;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Max subarray sum for [-2,1,-3,4,-1,2,1,-5,4]: " << sol.maxSubArray(nums1) << "\n"; // Expected: 6

    std::vector<int> nums2 = {1};
    std::cout << "Max subarray sum for [1]: " << sol.maxSubArray(nums2) << "\n"; // Expected: 1

    std::vector<int> nums3 = {5, 4, -1, 7, 8};
    std::cout << "Max subarray sum for [5,4,-1,7,8]: " << sol.maxSubArray(nums3) << "\n"; // Expected: 23

    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(1).

#### Problem 5: Product of Array Except Self (LeetCode 238)

**Description:** Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`. You must write an algorithm that runs in `O(n)` time and without using the division operation.

**Example:**
Input: `nums = [1,2,3,4]`
Output: `[24,12,8,6]`

**Approach (Prefix/Suffix Products):**
1.  Create two arrays: `prefix_products` and `suffix_products`.
2.  `prefix_products[i]` stores the product of all elements to the left of `i` (exclusive).
3.  `suffix_products[i]` stores the product of all elements to the right of `i` (exclusive).
4.  `answer[i] = prefix_products[i] * suffix_products[i]`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);

        // Calculate prefix products
        std::vector<int> prefix_products(n);
        prefix_products[0] = 1;
        for (int i = 1; i < n; ++i) {
            prefix_products[i] = prefix_products[i - 1] * nums[i - 1];
        }

        // Calculate suffix products and final answer
        std::vector<int> suffix_products(n);
        suffix_products[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            suffix_products[i] = suffix_products[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            answer[i] = prefix_products[i] * suffix_products[i];
        }
        return answer;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::cout << "Product except self for [1,2,3,4]: ";
    printVector(sol.productExceptSelf(nums1)); // Expected: [24,12,8,6]

    std::vector<int> nums2 = {-1, 1, 0, -3, 3};
    std::cout << "Product except self for [-1,1,0,-3,3]: ";
    printVector(sol.productExceptSelf(nums2)); // Expected: [0,0,9,0,0]

    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(N) for `prefix_products` and `suffix_products` arrays. Can be optimized to O(1) by using the `answer` array itself for one of the passes.

#### Problem 6: Range Sum Query - Immutable (LeetCode 303)

**Description:** Given an integer array `nums`, handle multiple queries of the following type:
Calculate the sum of the elements of `nums` between indices `left` and `right` inclusive (`nums[left]` to `nums[right]`).

Implement the `NumArray` class:
- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `int sumRange(int left, int right)` Returns the sum of the elements of `nums` between indices `left` and `right` inclusive.

**Example:**
Input:
`["NumArray", "sumRange", "sumRange", "sumRange"]`
`[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]`
Output:
`[null, 1, -1, -3]`

**Approach:** Precompute the prefix sums. Then, each `sumRange` query becomes an O(1) operation.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <numeric>

class NumArray {
public:
    std::vector<int> prefix_sum;

    NumArray(std::vector<int>& nums) {
        prefix_sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }
};

int main() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    std::cout << "Sum range (0,2): " << obj->sumRange(0, 2) << "\n"; // Expected: 1
    std::cout << "Sum range (2,5): " << obj->sumRange(2, 5) << "\n"; // Expected: -1
    std::cout << "Sum range (0,5): " << obj->sumRange(0, 5) << "\n"; // Expected: -3
    delete obj;
    return 0;
}
```

**Time Complexity:** O(N) for constructor, O(1) for `sumRange`.
**Space Complexity:** O(N) for the prefix sum array.

#### Problem 7: Subarray Product Less Than K (LeetCode 713)

**Description:** Given an array of integers `nums` and an integer `k`, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than `k`.

**Example:**
Input: `nums = [10,5,2,6]`, `k = 100`
Output: `8`
Explanation: The 8 subarrays that have product less than 100 are: `[10]`, `[5]`, `[2]`, `[6]`, `[10,5]`, `[5,2]`, `[2,6]`, `[5,2,6]`.

**Approach (Sliding Window with Product):**
Use a sliding window approach. Maintain a `product` of elements within the current window. Expand the window by including new elements. If the `product` becomes `k` or greater, shrink the window from the left until the `product` is less than `k` again. The number of subarrays ending at the current right pointer is `right - left + 1`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k <= 1) return 0; // Product must be strictly less than k

        int count = 0;
        int product = 1;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    std::cout << "Subarrays with product < " << k1 << " in [10,5,2,6]: " << sol.numSubarrayProductLessThanK(nums1, k1) << "\n"; // Expected: 8

    std::vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    std::cout << "Subarrays with product < " << k2 << " in [1,2,3]: " << sol.numSubarrayProductLessThanK(nums2, k2) << "\n"; // Expected: 0

    return 0;
}
```

**Time Complexity:** O(N) as each element is visited by `left` and `right` pointers at most once.
**Space Complexity:** O(1).

#### Problem 8: Subarrays with K Different Integers (LeetCode 992)

**Description:** Given an integer array `nums` and an integer `k`, return the number of good subarrays of `nums`. A good subarray is a subarray where the number of different integers in that subarray is exactly `k`.

**Approach:**
This problem can be solved by observing that the number of subarrays with exactly `k` distinct integers is equal to (number of subarrays with at most `k` distinct integers) - (number of subarrays with at most `k-1` distinct integers).

Implement a helper function `atMostK(nums, k)` that counts subarrays with at most `k` distinct integers using a sliding window and a frequency map.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(std::vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        std::unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    std::cout << "Subarrays with exactly " << k1 << " distinct integers in [1,2,1,2,3]: " << sol.subarraysWithKDistinct(nums1, k1) << "\n"; // Expected: 7

    std::vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    std::cout << "Subarrays with exactly " << k2 << " distinct integers in [1,2,1,3,4]: " << sol.subarraysWithKDistinct(nums2, k2) << "\n"; // Expected: 3

    return 0;
}
```

**Time Complexity:** O(N) as each element is processed by the sliding window pointers and hash map operations take O(1) on average.
**Space Complexity:** O(K) for the frequency map.

#### Problem 9: Binary Subarrays With Sum (LeetCode 930)

**Description:** Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays that have a sum `goal`.

**Example:**
Input: `nums = [1,0,1,0,1]`, `goal = 2`
Output: `4`
Explanation: The 4 subarrays are `[1,0,1]`, `[0,1,0,1]`, `[1,0,1]`, `[1,0,1]`.

**Approach (Prefix Sum with Hash Map):**
This is a variation of "Subarray Sum Equals K". Use a hash map to store the frequency of prefix sums. For each `current_sum`, check if `current_sum - goal` exists in the map. If it does, add its frequency to the count.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        int count = 0;
        int current_sum = 0;
        std::unordered_map<int, int> prefix_sum_freq;
        prefix_sum_freq[0] = 1; // To handle subarrays starting from index 0

        for (int num : nums) {
            current_sum += num;
            if (prefix_sum_freq.count(current_sum - goal)) {
                count += prefix_sum_freq[current_sum - goal];
            }
            prefix_sum_freq[current_sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    std::cout << "Subarrays with sum " << goal1 << " in [1,0,1,0,1]: " << sol.numSubarraysWithSum(nums1, goal1) << "\n"; // Expected: 4

    std::vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    std::cout << "Subarrays with sum " << goal2 << " in [0,0,0,0,0]: " << sol.numSubarraysWithSum(nums2, goal2) << "\n"; // Expected: 15

    return 0;
}
```

**Time Complexity:** O(N) on average.
**Space Complexity:** O(N) in the worst case.

#### Problem 10: Find the Longest Subarray With Sum K (GeeksForGeeks)

**Description:** Given an array `A` of `N` integers and an integer `K`, find the length of the longest subarray whose sum is equal to `K`.

**Approach (Prefix Sum with Hash Map):**
1.  Maintain a `current_sum`.
2.  Use a hash map to store the first occurrence of each prefix sum (`prefix_sum -> index`).
3.  If `current_sum == K`, update `max_len` to `i + 1`.
4.  If `current_sum - K` exists in the map, it means a subarray with sum `K` exists. The length of this subarray is `i - map[current_sum - K]`. Update `max_len`.
5.  If `current_sum` is not in the map, add it.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int longestSubarraySumK(std::vector<int>& nums, int k) {
        int max_len = 0;
        int current_sum = 0;
        std::unordered_map<int, int> prefix_sum_map;
        prefix_sum_map[0] = -1; // To handle subarrays starting from index 0

        for (int i = 0; i < nums.size(); ++i) {
            current_sum += nums[i];

            if (prefix_sum_map.count(current_sum - k)) {
                max_len = std::max(max_len, i - prefix_sum_map[current_sum - k]);
            }

            if (prefix_sum_map.find(current_sum) == prefix_sum_map.end()) {
                prefix_sum_map[current_sum] = i;
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    std::cout << "Longest subarray with sum " << k1 << " in [10,5,2,7,1,9]: " << sol.longestSubarraySumK(nums1, k1) << "\n"; // Expected: 4 ([10,5,2,7])

    std::vector<int> nums2 = {-1, 2, 3};
    int k2 = 6;
    std::cout << "Longest subarray with sum " << k2 << " in [-1,2,3]: " << sol.longestSubarraySumK(nums2, k2) << "\n"; // Expected: 0

    return 0;
}
```

**Time Complexity:** O(N) on average.
**Space Complexity:** O(N) in the worst case.

---

### References

[1] Medium. "Prefix Sums Demystified: From LeetCode Challenges to Real-World Solutions." *Medium*, 26 Nov. 2024, medium.com/@hanxuyang0826/prefix-sums-demystified-from-leetcode-challenges-to-real-world-solutions-ce740081cc7b.
[2] GeeksforGeeks. "Prefix Sum Array - Implementation." *GeeksforGeeks*, 13 Jul. 2025, www.geeksforgeeks.org/dsa/prefix-sum-array-implementation-applications-competitive-programming/.
[3] USACO Guide. "Introduction to Prefix Sums." *USACO Guide*, usaco.guide/silver/prefix-sums.
[4] Hello Interview. "Prefix Sum." *Hello Interview*, www.hellointerview.com/learn/code/prefix-sum/overview.
[5] Java Newsletter. "Understanding Leetcode Prefix Sum Pattern." *Java Newsletter*, 28 Jan. 2025, javabulletin.substack.com/p/understanding-leetcode-prefix-sum.
[6] HackMD. "Arrays - Prefix sum, carry forward & Subarrays (Quick revision)." *HackMD*, 21 Oct. 2023, hackmd.io/@topics/SJU9OER-p.
[7] Reddit. "A Visual Guide to Prefix Sums." *Reddit*, 20 Aug. 2024, www.reddit.com/r/leetcode/comments/1ewxiqt/a_visual_guide_to_prefix_sums/.

---



### 4.7 Sliding Window Technique

**Concept:**
The Sliding Window Technique is an algorithmic approach used to solve problems that involve finding a subarray or substring in a given array or string that satisfies certain conditions. It works by maintaining a "window" (a contiguous subsegment) of elements and sliding this window over the data. This technique often reduces the time complexity from O(N^2) (for brute-force checking all subarrays/substrings) to O(N) [1, 2].

**Analogy:** Imagine you are looking at a long train through a small window. You can only see a few carriages at a time. To see all parts of the train, you slide your window along the train, one carriage at a time. The window always maintains a certain size (fixed or dynamic) and you perform some operation on the carriages currently visible through the window.

**Types of Sliding Window:**
1.  **Fixed-Size Sliding Window:** The window size `k` is constant. You slide the window one element at a time, performing calculations on the current window.
2.  **Dynamic-Size Sliding Window:** The window size changes based on certain conditions. You expand the window (move the right pointer) until a condition is met, then shrink the window (move the left pointer) until the condition is no longer violated or a new condition is met.

**Common Techniques/Patterns:**
-   **Two Pointers:** Typically involves a `left` and `right` pointer defining the window boundaries.
-   **Frequency Maps/Sets:** Used to keep track of elements within the current window, especially for problems involving distinct elements or character counts.
-   **Sum/Product Tracking:** Maintaining the sum or product of elements within the window.

### 4.7.1 Practice Problems (Sliding Window Technique)

Here are 10 handpicked important problems related to the Sliding Window Technique, along with their solutions in C++ and complexity analysis.

#### Problem 1: Maximum Sum Subarray of Size K (Fixed Window)

**Description:** Given an array of integers and a number `k`, find the maximum sum of a subarray of size `k`.

**Example:**
Input: `arr = [100, 200, 300, 400]`, `k = 2`
Output: `700` (Subarray `[300, 400]`)

**Approach:**
1.  Calculate the sum of the first `k` elements to get the initial window sum.
2.  Initialize `max_sum` with this initial sum.
3.  Slide the window: For each subsequent element, subtract the element leaving the window from the sum and add the new element entering the window. Update `max_sum` if the current window sum is greater.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSumSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0; // Invalid input

        int current_window_sum = 0;
        // Calculate sum of first window
        for (int i = 0; i < k; ++i) {
            current_window_sum += nums[i];
        }

        int max_sum = current_window_sum;

        // Slide the window
        for (int i = k; i < n; ++i) {
            current_window_sum += nums[i] - nums[i - k]; // Add new element, remove old element
            max_sum = std::max(max_sum, current_window_sum);
        }
        return max_sum;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {100, 200, 300, 400};
    int k1 = 2;
    std::cout << "Max sum subarray of size " << k1 << " in [100,200,300,400]: " << sol.maxSumSubarray(nums1, k1) << "\n"; // Expected: 700

    std::vector<int> nums2 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k2 = 4;
    std::cout << "Max sum subarray of size " << k2 << " in [1,4,2,10,2,3,1,0,20]: " << sol.maxSumSubarray(nums2, k2) << "\n"; // Expected: 24

    return 0;
}
```

**Time Complexity:** O(N) where N is the size of the array.
**Space Complexity:** O(1).

#### Problem 2: Longest Substring Without Repeating Characters (LeetCode 3)

**Description:** Given a string `s`, find the length of the longest substring without repeating characters.

**Example:**
Input: `s = "abcabcbb"`
Output: `3` (The answer is "abc", with the length of 3.)

**Approach (Dynamic Window with Frequency Map):**
Use a sliding window. Maintain a `left` and `right` pointer. Use a frequency map (e.g., `std::unordered_map<char, int>`) to store the count of characters in the current window. Expand the window by moving `right`. If a character at `right` is already in the map and its count is greater than 0, shrink the window by moving `left` until the repeating character is removed. Update the `max_length` at each step.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        if (n == 0) return 0;

        std::unordered_map<char, int> char_count;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            char_count[s[right]]++;
            while (char_count[s[right]] > 1) {
                char_count[s[left]]--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    std::cout << "Longest substring without repeating chars for \"abcabcbb\": " << sol.lengthOfLongestSubstring("abcabcbb") << "\n"; // Expected: 3
    std::cout << "Longest substring without repeating chars for \"bbbbb\": " << sol.lengthOfLongestSubstring("bbbbb") << "\n"; // Expected: 1
    std::cout << "Longest substring without repeating chars for \"pwwkew\": " << sol.lengthOfLongestSubstring("pwwkew") << "\n"; // Expected: 3
    return 0;
}
```

**Time Complexity:** O(N) as each character is visited by `left` and `right` pointers at most once.
**Space Complexity:** O(K) where K is the size of the character set (e.g., 256 for ASCII, or 26 for lowercase English letters).

#### Problem 3: Permutation in String (LeetCode 567)

**Description:** Given two strings `s1` and `s2`, return `true` if `s2` contains one of the permutations of `s1`, or `false` otherwise. In other words, return `true` if `s1`'s permutation is a substring of `s2`.

**Example:**
Input: `s1 = "ab"`, `s2 = "eidbaooo"`
Output: `true` (Explanation: `s2` contains "ba" which is a permutation of `s1`.)

**Approach (Fixed Window with Frequency Map):**
1.  Create frequency maps for `s1` and the initial window of `s2` (of size `s1.length()`).
2.  Compare the two frequency maps. If they are identical, return `true`.
3.  Slide the window: For each step, decrement the count of the character leaving the window and increment the count of the character entering the window. Compare maps again.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len1 > len2) return false;

        std::vector<int> s1_freq(26, 0);
        std::vector<int> window_freq(26, 0);

        // Populate frequency for s1 and initial window of s2
        for (int i = 0; i < len1; ++i) {
            s1_freq[s1[i] - 'a']++;
            window_freq[s2[i] - 'a']++;
        }

        if (s1_freq == window_freq) return true;

        // Slide the window
        for (int i = len1; i < len2; ++i) {
            window_freq[s2[i] - 'a']++; // Add new char
            window_freq[s2[i - len1] - 'a']--; // Remove old char
            if (s1_freq == window_freq) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::cout << "\"ab\" permutation in \"eidbaooo\": " << (sol.checkInclusion("ab", "eidbaooo") ? "True" : "False") << "\n"; // Expected: True
    std::cout << "\"ab\" permutation in \"eidboaoo\": " << (sol.checkInclusion("ab", "eidboaoo") ? "True" : "False") << "\n"; // Expected: False
    return 0;
}
```

**Time Complexity:** O(N + M) where N is `s2.length()` and M is `s1.length()`.
**Space Complexity:** O(1) (since character set size is constant, 26).

#### Problem 4: Find All Anagrams in a String (LeetCode 438)

**Description:** Given two strings `s` and `p`, return an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in any order.

**Example:**
Input: `s = "cbaebabacd"`, `p = "abc"`
Output: `[0,6]` (The substring with start index 0 is "cba", which is an anagram of "abc". The substring with start index 6 is "bac", which is an anagram of "abc".)

**Approach:** This is very similar to "Permutation in String". Use a fixed-size sliding window and frequency maps. Instead of returning `true`/`false`, store the starting index of the window when the frequency maps match.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        int len_s = s.length();
        int len_p = p.length();

        if (len_s < len_p) return result;

        std::vector<int> p_freq(26, 0);
        std::vector<int> window_freq(26, 0);

        // Populate frequency for p and initial window of s
        for (int i = 0; i < len_p; ++i) {
            p_freq[p[i] - 'a']++;
            window_freq[s[i] - 'a']++;
        }

        if (p_freq == window_freq) {
            result.push_back(0);
        }

        // Slide the window
        for (int i = len_p; i < len_s; ++i) {
            window_freq[s[i] - 'a']++; // Add new char
            window_freq[s[i - len_p] - 'a']--; // Remove old char
            if (p_freq == window_freq) {
                result.push_back(i - len_p + 1);
            }
        }
        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;
    std::vector<int> result1 = sol.findAnagrams("cbaebabacd", "abc");
    std::cout << "Anagram start indices for \"cbaebabacd\" and \"abc\": ";
    printVector(result1); // Expected: [0,6]

    std::vector<int> result2 = sol.findAnagrams("abab", "ab");
    std::cout << "Anagram start indices for \"abab\" and \"ab\": ";
    printVector(result2); // Expected: [0,1,2]

    return 0;
}
```

**Time Complexity:** O(N + M) where N is `s.length()` and M is `p.length()`.
**Space Complexity:** O(1) (for frequency arrays).

#### Problem 5: Minimum Window Substring (LeetCode 76)

**Description:** Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return an empty string.

**Example:**
Input: `s = "ADOBECODEBANC"`, `t = "ABC"`
Output: `"BANC"`

**Approach (Dynamic Window with Two Frequency Maps):**
1.  Create a frequency map for `t` (`t_freq`).
2.  Create another frequency map for the current window in `s` (`window_freq`).
3.  Use `left` and `right` pointers. Expand the window by moving `right`. Update `window_freq`. Keep track of `matched_chars` (number of characters from `t` that are currently matched in the window).
4.  When all characters in `t` are matched (`matched_chars == t.length()`), try to shrink the window from the `left` to find the minimum valid window. Update `min_len` and `min_start_index`.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.empty()) return "";

        std::unordered_map<char, int> t_freq;
        for (char c : t) {
            t_freq[c]++;
        }

        int left = 0;
        int matched_chars = 0;
        int min_len = std::numeric_limits<int>::max();
        int min_start_index = 0;

        for (int right = 0; right < s.length(); ++right) {
            char r_char = s[right];
            if (t_freq.count(r_char)) {
                t_freq[r_char]--;
                if (t_freq[r_char] >= 0) { // Character needed and matched
                    matched_chars++;
                }
            }

            while (matched_chars == t.length()) {
                // Update minimum window
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start_index = left;
                }

                char l_char = s[left];
                left++;
                if (t_freq.count(l_char)) {
                    t_freq[l_char]++;
                    if (t_freq[l_char] > 0) { // Character was needed, now unmatched
                        matched_chars--;
                    }
                }
            }
        }

        if (min_len == std::numeric_limits<int>::max()) {
            return "";
        } else {
            return s.substr(min_start_index, min_len);
        }
    }
};

int main() {
    Solution sol;
    std::cout << "Min window for \"ADOBECODEBANC\" and \"ABC\": " << sol.minWindow("ADOBECODEBANC", "ABC") << "\n"; // Expected: BANC
    std::cout << "Min window for \"a\" and \"a\": " << sol.minWindow("a", "a") << "\n"; // Expected: a
    std::cout << "Min window for \"a\" and \"aa\": " << sol.minWindow("a", "aa") << "\n"; // Expected: ""
    return 0;
}
```

**Time Complexity:** O(N + M) where N is `s.length()` and M is `t.length()`. Each character is visited by `left` and `right` pointers at most once.
**Space Complexity:** O(K) where K is the size of the character set.

#### Problem 6: Longest Repeating Character Replacement (LeetCode 424)

**Description:** You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times. Return the length of the longest substring containing the same letter you can get after performing the above operations.

**Example:**
Input: `s = "ABAB"`, `k = 2`
Output: `4` (Replace the two 'A's with 'B's or vice versa.)

**Approach (Dynamic Window with Frequency Map):**
Use a sliding window. Maintain `left` and `right` pointers. Keep track of the frequency of characters in the current window. Also, keep track of the `max_freq` (frequency of the most frequent character) in the current window. The number of characters to change in the current window is `window_length - max_freq`. If this count is less than or equal to `k`, we can potentially form a valid substring. Otherwise, shrink the window from the `left`.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int n = s.length();
        std::vector<int> char_counts(26, 0);
        int left = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            char_counts[s[right] - 'A']++;
            max_freq = std::max(max_freq, char_counts[s[right] - 'A']);

            // If characters to change > k, shrink window
            if ((right - left + 1) - max_freq > k) {
                char_counts[s[left] - 'A']--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    std::cout << "Longest repeating char replacement for \"ABAB\" with k=2: " << sol.characterReplacement("ABAB", 2) << "\n"; // Expected: 4
    std::cout << "Longest repeating char replacement for \"AABABBA\" with k=1: " << sol.characterReplacement("AABABBA", 1) << "\n"; // Expected: 4
    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(1) (for `char_counts` array).

#### Problem 7: Longest Substring with At Most K Distinct Characters (LeetCode 340 - Premium)

**Description:** Given a string `s` and an integer `k`, return the length of the longest substring of `s` that contains at most `k` distinct characters.

**Example:**
Input: `s = "eceba"`, `k = 2`
Output: `3` (The longest substring is "ece".)

**Approach (Dynamic Window with Frequency Map):**
Use a sliding window. Maintain `left` and `right` pointers. Use a frequency map (`std::unordered_map<char, int>`) to store character counts. Expand the window by moving `right`. If the number of distinct characters in the window (`freq.size()`) exceeds `k`, shrink the window from the `left` until the condition is met again. Update `max_len` at each step.

**Solution (C++):**

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k) {
        int n = s.length();
        if (k == 0 || n == 0) return 0;

        std::unordered_map<char, int> char_counts;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            char_counts[s[right]]++;
            while (char_counts.size() > k) {
                char_counts[s[left]]--;
                if (char_counts[s[left]] == 0) {
                    char_counts.erase(s[left]);
                }
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    std::cout << "Longest substring with at most 2 distinct chars for \"eceba\": " << sol.lengthOfLongestSubstringKDistinct("eceba", 2) << "\n"; // Expected: 3
    std::cout << "Longest substring with at most 1 distinct char for \"aa\": " << sol.lengthOfLongestSubstringKDistinct("aa", 1) << "\n"; // Expected: 2
    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(K) (for the frequency map).

#### Problem 8: Max Consecutive Ones III (LeetCode 1004)

**Description:** Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`s in the array if you can flip at most `k` `0`s.

**Example:**
Input: `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`
Output: `6` (Flip the two 0s at index 3 and 4 to 1s. The longest subarray is `[1,1,1,1,1,1]` with length 6.)

**Approach (Dynamic Window):**
Use a sliding window. Maintain `left` and `right` pointers. Keep track of the count of `0`s in the current window. Expand the window by moving `right`. If the count of `0`s exceeds `k`, shrink the window from the `left` until the count of `0`s is `k` or less. Update `max_len` at each step.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zero_count = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) {
                zero_count++;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    std::cout << "Max consecutive ones for [1,1,1,0,0,0,1,1,1,1,0] with k=2: " << sol.longestOnes(nums1, k1) << "\n"; // Expected: 6

    std::vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    std::cout << "Max consecutive ones for [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] with k=3: " << sol.longestOnes(nums2, k2) << "\n"; // Expected: 10

    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(1).

#### Problem 9: Longest Subarray of 1s After Deleting One Element (LeetCode 1493)

**Description:** Given a binary array `nums`, you should delete one element from it. Return the size of the longest subarray containing only `1`s in the resulting array.

**Example:**
Input: `nums = [1,1,0,1]`
Output: `3` (Delete the 0 at index 2. The longest subarray of 1s is `[1,1,1]`.)

**Approach (Dynamic Window):**
This is a variation of the previous problem where `k=1` (we can flip at most one `0` by deleting it). The problem asks for the length of the subarray of `1`s, so if the final length is `L`, the answer is `L-1` (because one element was deleted). If the array contains all `1`s, we still have to delete one, so the answer is `N-1`.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zero_count = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) {
                zero_count++;
            }

            while (zero_count > 1) { // Allow at most one zero (which will be deleted)
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        // If the original array contains all 1s, we still need to delete one element.
        // So, the length of the subarray of 1s will be n-1.
        // If max_len is n (all 1s), return n-1. Otherwise, max_len already accounts for the deleted 0.
        return max_len - 1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 1, 0, 1};
    std::cout << "Longest subarray of 1s after deleting one element for [1,1,0,1]: " << sol.longestSubarray(nums1) << "\n"; // Expected: 3

    std::vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    std::cout << "Longest subarray of 1s after deleting one element for [0,1,1,1,0,1,1,0,1]: " << sol.longestSubarray(nums2) << "\n"; // Expected: 5

    std::vector<int> nums3 = {1, 1, 1};
    std::cout << "Longest subarray of 1s after deleting one element for [1,1,1]: " << sol.longestSubarray(nums3) << "\n"; // Expected: 2

    return 0;
}
```

**Time Complexity:** O(N).
**Space Complexity:** O(1).

#### Problem 10: Sliding Window Maximum (LeetCode 239)

**Description:** You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position. Return the maximum sliding window.

**Example:**
Input: `nums = [1,3,-1,-3,5,3,6,7]`, `k = 3`
Output: `[3,3,5,5,6,7]`

**Approach (Deque - Double-Ended Queue):**
Use a deque to store indices of elements in the current window. The deque will maintain elements in decreasing order of their values. This way, the front of the deque always stores the index of the maximum element in the current window.

1.  Initialize an empty deque and an empty result vector.
2.  Iterate with `right` pointer:
    -   Remove elements from the back of the deque whose values are less than `nums[right]` (they can't be maximum).
    -   Add `right` to the back of the deque.
    -   Remove elements from the front of the deque whose indices are outside the current window (`left`).
    -   If `right` is `k-1` or greater, the window is fully formed, and `nums[deque.front()]` is the maximum. Add it to the result.

**Solution (C++):**

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // Stores indices

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements from back of deque that are smaller than current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // Remove elements from front of deque that are out of window
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // Add max to result once window is formed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    std::cout << "Max sliding window for [1,3,-1,-3,5,3,6,7] with k=3: ";
    printVector(sol.maxSlidingWindow(nums1, k1)); // Expected: [3,3,5,5,6,7]

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::cout << "Max sliding window for [1] with k=1: ";
    printVector(sol.maxSlidingWindow(nums2, k2)); // Expected: [1]

    return 0;
}
```

**Time Complexity:** O(N) as each element is added and removed from the deque at most once.
**Space Complexity:** O(K) for the deque.

---

### References

[1] GeeksforGeeks. "Sliding Window Technique." *GeeksforGeeks*, 20 May 2025, www.geeksforgeeks.org/dsa/window-sliding-technique/.
[2] Built In. "Sliding Window Algorithm Explained." *Built In*, builtin.com/data-science/sliding-window-algorithm.
[3] Medium. "Mastering Sliding Window Techniques." *Medium*, 8 Aug. 2023, medium.com/@rishu__2701/mastering-sliding-window-techniques-48f819194fd7.
[4] freeCodeCamp.org. "How to Use the Sliding Window Technique – Algorithm Example." *freeCodeCamp.org*, 11 Jan. 2024, www.freecodecamp.org/news/sliding-window-technique/.
[5] Medium. "10 Sliding Window Leetcode Problems that make you understand it better." *Medium*, 5 Sep. 2023, medium.com/@yourstudybuddy/10-sliding-window-leetcode-problems-that-make-you-understand-better-341c5ca3fbd.

---



## 5. Advanced Topics

This section covers advanced topics that are frequently encountered in coding interviews. While they might not be as fundamental as data structures and algorithms, a solid understanding of these concepts can significantly improve your problem-solving capabilities and impress interviewers.

### 5.1 Bit Manipulation Tricks

**Concept:**
Bit manipulation involves performing operations on individual bits of a number. This technique is powerful because bitwise operations are extremely fast at the hardware level. Understanding bit manipulation can lead to highly optimized solutions for certain problems, especially those involving flags, sets, or numerical properties [1, 2].

**Bitwise Operators in C++:**
C++ provides several bitwise operators that work directly on the binary representation of numbers:

| Operator | Name           | Description                                                                                             | Example (for `a=5 (0101)`, `b=3 (0011)`) | Result   |
|----------|----------------|---------------------------------------------------------------------------------------------------------|------------------------------------------|----------|
| `&`      | Bitwise AND    | Sets each bit to 1 if both corresponding bits are 1.                                                    | `a & b` (0101 & 0011)                    | `0001` (1) |
| `|`      | Bitwise OR     | Sets each bit to 1 if at least one of the corresponding bits is 1.                                      | `a | b` (0101 | 0011)                    | `0111` (7) |
| `^`      | Bitwise XOR    | Sets each bit to 1 if only one of the corresponding bits is 1 (i.e., bits are different).               | `a ^ b` (0101 ^ 0011)                    | `0110` (6) |
| `~`      | Bitwise NOT    | Inverts all bits (unary operator).                                                                      | `~a` (~0101)                             | `1010` (-6 for signed int) |
| `<<`     | Left Shift     | Shifts bits to the left, filling new bits with zeros. Equivalent to multiplying by powers of 2.         | `a << 1` (0101 << 1)                     | `1010` (10)|
| `>>`     | Right Shift    | Shifts bits to the right. For unsigned integers, fills new bits with zeros. For signed integers, behavior is implementation-defined (arithmetic or logical shift). Equivalent to dividing by powers of 2. | `a >> 1` (0101 >> 1)                     | `0010` (2) |

**Common Tricks and Patterns:**

1.  **Check if a number is Even or Odd:**
    A number is odd if its least significant bit (LSB) is 1. An even number has its LSB as 0.
    `if (num & 1) { // num is odd } else { // num is even }`

2.  **Set a Bit:**
    To set the `k`-th bit (0-indexed) of a number `num` to 1:
    `num = num | (1 << k);`
    Example: `num = 4 (0100)`, set 0th bit: `4 | (1 << 0)` = `0100 | 0001` = `0101` (5)

3.  **Clear a Bit:**
    To clear the `k`-th bit of a number `num` to 0:
    `num = num & ~(1 << k);`
    Example: `num = 5 (0101)`, clear 0th bit: `5 & ~(1 << 0)` = `0101 & ~0001` = `0101 & 1110` = `0100` (4)

4.  **Toggle a Bit:**
    To toggle the `k`-th bit of a number `num` (flip 0 to 1, or 1 to 0):
    `num = num ^ (1 << k);`
    Example: `num = 4 (0100)`, toggle 0th bit: `4 ^ (1 << 0)` = `0100 ^ 0001` = `0101` (5)

5.  **Check if a Bit is Set:**
    To check if the `k`-th bit of a number `num` is 1:
    `if ((num >> k) & 1) { // k-th bit is set }`
    or `if (num & (1 << k)) { // k-th bit is set }`

6.  **Clear the Lowest Set Bit:**
    `num = num & (num - 1);`
    This operation effectively removes the rightmost `1` bit from the number. Useful for counting set bits (Brian Kernighan's algorithm).
    Example: `num = 12 (1100)`, `num - 1 = 11 (1011)`. `1100 & 1011 = 1000` (8)

7.  **Extract the Lowest Set Bit:**
    `lowest_set_bit = num & (-num);` (for two's complement representation)
    or `lowest_set_bit = num & (~num + 1);`
    Example: `num = 12 (1100)`. `-12` in 2's complement is `0100`. `1100 & 0100 = 0100` (4)

8.  **Check if a number is a Power of 2:**
    A positive number `num` is a power of 2 if and only if `(num > 0) && ((num & (num - 1)) == 0)`. This is because powers of 2 have only one bit set (e.g., 4 is `0100`, 8 is `1000`). Subtracting 1 from a power of 2 flips all bits from the rightmost 1 to the end, and `AND`ing them results in 0.

9.  **Swap Two Numbers Without a Temporary Variable:**
    Using XOR:
    `a = a ^ b;`
    `b = a ^ b;`
    `a = a ^ b;`

10. **Counting Set Bits (Population Count):**
    The number of set bits (1s) in a binary representation of a number.
    -   **Brian Kernighan's Algorithm:** Repeatedly clear the lowest set bit until the number becomes 0, counting how many times this operation is performed.
        ```cpp
        int countSetBits(int n) {
            int count = 0;
            while (n > 0) {
                n &= (n - 1);
                count++;
            }
            return count;
        }
        ```
    -   Many compilers provide built-in functions like `__builtin_popcount` (GCC/Clang) for efficiency.

**Applications:**
-   **Flags and Permissions:** Representing a set of boolean flags efficiently.
-   **Bitmasks:** Selecting specific bits or groups of bits.
-   **Optimizing Algorithms:** Faster arithmetic operations (multiplication/division by powers of 2), set operations, and certain data structures.
-   **Hashing:** Creating hash functions.
-   **Competitive Programming:** Solving problems that require manipulating individual bits or dealing with binary representations.

---

### References

[1] CP-Algorithms. "Bit manipulation." *CP-Algorithms*, 20 Dec. 2024, cp-algorithms.com/algebra/bit-manipulation.html.
[2] GeeksforGeeks. "All about Bit Manipulation." *GeeksforGeeks*, 18 Apr. 2023, www.geeksforgeeks.org/all-about-bit-manipulation/.
[3] Medium. "10 Bitwise Tricks You Should Know (with examples in C++)." *Medium*, 7 Mar. 2025, medium.com/@r.siddhesh96/10-bitwise-tricks-you-should-know-with-examples-in-c-4b04820dfbc0.
[4] GeeksforGeeks. "Bit Tricks for Competitive Programming." *GeeksforGeeks*, 24 Nov. 2023, www.geeksforgeeks.org/competitive-programming/bit-tricks-competitive-programming/.

---



### 5.2 Binary Search on Answers

**Concept:**
Binary Search is typically used to find an element in a sorted array. However, a powerful extension of this technique, known as "Binary Search on Answers" (or "Binary Search on the Result"), is used when the answer to a problem lies within a certain range, and we can define a monotonic `check` function that determines if a given candidate answer is feasible [1, 3].

**When to Use:**
This technique is applicable when:
1.  The problem asks for a minimum possible value or a maximum possible value (e.g., "minimum maximum", "maximum minimum").
2.  The range of possible answers is known or can be determined.
3.  There exists a `check(X)` function that can efficiently determine if `X` is a feasible answer. This `check` function must be monotonic: if `X` is a valid answer, then all answers greater (or smaller, depending on monotonicity) than `X` are also valid. This property allows us to eliminate half of the search space in each step.

**How it Works:**
1.  **Define Search Space:** Determine the lower bound (`low`) and upper bound (`high`) for the possible answer. This range is where your binary search will operate.
2.  **Monotonic `check` Function:** Implement a function `check(mid)` that takes a candidate answer `mid` (usually `(low + high) / 2`) and returns `true` if `mid` is a valid answer, and `false` otherwise. The crucial part is that this function must be monotonic.
3.  **Binary Search Loop:**
    -   Initialize `ans` (the best answer found so far) to an appropriate default value.
    -   While `low <= high`:
        -   Calculate `mid = low + (high - low) / 2`.
        -   If `check(mid)` is `true`:
            -   This `mid` is a possible answer. Store it (`ans = mid`).
            -   Try to find a better (smaller/larger) answer by searching in the appropriate half (e.g., `high = mid - 1` for minimum problems, `low = mid + 1` for maximum problems).
        -   Else (`check(mid)` is `false`):
            -   `mid` is not a valid answer. Adjust the search space to exclude `mid` (e.g., `low = mid + 1` for minimum problems, `high = mid - 1` for maximum problems).

**Example Scenario:**
Consider a problem like "Minimize the maximum value of an array after performing some operations." Here, the answer (the minimum possible maximum value) can be binary searched. The `check(X)` function would be: "Is it possible to make all elements in the array less than or equal to `X` by performing the allowed operations?" If `check(X)` is true, then `X` might be our answer, and we try a smaller `X`. If `check(X)` is false, then `X` is too small, and we need a larger `X`.

**Key Takeaway:**
Binary search on answers transforms a problem that might seem complex into a simpler decision problem (`check` function) that can be solved efficiently. The `check` function itself might involve greedy algorithms, dynamic programming, or other techniques.

---

### References

[1] GeeksforGeeks. "Binary Search on Answer Tutorial with Problems." *GeeksforGeeks*, 20 Jun. 2024, www.geeksforgeeks.org/binary-search-on-answer-tutorial-with-problems/.
[2] Medium. "Binary Search on Answer." *Medium*, 25 Aug. 2023, medium.com/@smrutiranjanrout2019/binary-search-on-answer-a406089e8e17.
[3] USACO Guide. "Binary Search." *USACO Guide*, usaco.guide/silver/binary-search.
[4] Codeforces. "Binary Search on the Answer — A Simple Trick That Wins Many." *Codeforces*, codeforces.com/blog/entry/143038.

---



### 5.3 Trie Data Structure

**Concept:**
A **Trie** (pronounced "try", from retrieval), also known as a **prefix tree** or **digital tree**, is a specialized tree-like data structure used to store and efficiently retrieve a dynamic set of strings or associative arrays where keys are strings [1, 5]. Unlike binary search trees, where nodes store the entire key, nodes in a Trie store only a single character (or a part of a key), and the path from the root to a node represents a prefix or a complete key.

**Structure:**
-   Each node in a Trie typically has an array or a hash map of pointers (or references) to its children, where each index (or key) corresponds to a character in the alphabet (e.g., 26 for lowercase English letters, or 256 for ASCII characters) [2].
-   The root node usually represents an empty string.
-   Each edge from a node to its child represents a character.
-   A node can also have a boolean flag (e.g., `isEndOfWord`) to indicate if the path to that node forms a complete word.

**Advantages:**
-   **Efficient Prefix Matching:** Tries are extremely efficient for prefix-based searches, auto-completion, and spell-checking. Searching for a key takes O(L) time, where L is the length of the key, regardless of the number of keys in the Trie [1].
-   **Alphabetical Ordering:** All children of a node are sorted alphabetically by character, which can be useful for certain applications.
-   **Space Efficiency (for common prefixes):** When many strings share common prefixes, Tries can be more space-efficient than hash tables because common prefixes are stored only once.

**Disadvantages:**
-   **Space Consumption (for sparse data):** If the alphabet is large and strings do not share many common prefixes, a Trie can consume a lot of memory due to the large number of pointers in each node.

**Operations:**
1.  **Insertion:** To insert a string, traverse the Trie character by character. If a path for a character doesn't exist, create a new node. Mark the last node of the inserted string as `isEndOfWord = true`.
2.  **Search:** To search for a string, traverse the Trie character by character. If at any point a character's path doesn't exist, the string is not in the Trie. If the traversal completes, check if the `isEndOfWord` flag of the last node is `true`.
3.  **`startsWith` (Prefix Search):** Similar to search, but you only need to check if the path for the prefix exists. The `isEndOfWord` flag is not relevant for this operation.

**Basic C++ Implementation:**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>

const int ALPHABET_SIZE = 26; // For lowercase English letters

// Trie node structure
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord; // True if this node represents the end of a word

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
};

// Trie class
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Returns true if the word is in the trie
    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return current != nullptr && current->isEndOfWord;
    }

    // Returns true if there is any word in the trie that starts with the given prefix
    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return current != nullptr;
    }

    // Destructor to free memory (important for preventing memory leaks)
    ~Trie() {
        clear(root);
    }

private:
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            clear(node->children[i]);
        }
        delete node;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");

    std::cout << "Search 'apple': " << (trie.search("apple") ? "True" : "False") << "\n"; // True
    std::cout << "Search 'app': " << (trie.search("app") ? "True" : "False") << "\n";     // True
    std::cout << "Search 'ap': " << (trie.search("ap") ? "True" : "False") << "\n";       // False (not a full word)
    std::cout << "Search 'banana': " << (trie.search("banana") ? "True" : "False") << "\n"; // False

    std::cout << "Starts with 'app': " << (trie.startsWith("app") ? "True" : "False") << "\n"; // True
    std::cout << "Starts with 'ap': " << (trie.startsWith("ap") ? "True" : "False") << "\n";   // True
    std::cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "True" : "False") << "\n"; // False

    return 0;
}
```

**Time Complexity:**
-   **Insertion:** O(L) where L is the length of the word.
-   **Search:** O(L) where L is the length of the word.
-   **`startsWith`:** O(L) where L is the length of the prefix.

**Space Complexity:** O(N * M) in the worst case, where N is the number of words and M is the average length of words. More accurately, it's proportional to the total number of characters in all inserted words, considering shared prefixes.

**Applications:**
-   **Autocomplete and Predictive Text:** Suggesting words as a user types.
-   **Spell Checkers:** Identifying misspelled words and suggesting corrections.
-   **Dictionary Implementations:** Storing and searching for words efficiently.
-   **IP Routing:** Storing IP addresses and performing longest prefix matching.
-   **Browser History:** Efficiently searching for URLs based on prefixes.

---

### References

[1] GeeksforGeeks. "Trie Data Structure in C++." *GeeksforGeeks*, 28 Jun. 2024, www.geeksforgeeks.org/cpp/trie-data-structure-in-cpp/.
[2] DigitalOcean. "Trie Data Structure in C/C++." *DigitalOcean*, 3 Aug. 2022, www.digitalocean.com/community/tutorials/trie-data-structure-in-c-plus-plus.
[3] Medium. "Understanding and Implementing a Trie in C++." *Medium*, 29 Jul. 2024, medium.com/@sagar.sahil.nitp98/understanding-and-implementing-a-trie-in-c-51648d401cda.
[4] LeetCode. "Implement Trie (Prefix Tree)." *LeetCode*, leetcode.com/problems/implement-trie-prefix-tree/.
[5] Wikipedia. "Trie." *Wikipedia*, en.wikipedia.org/wiki/Trie.

---



### 5.4 Segment Tree / Fenwick Tree (Binary Indexed Tree)

Both Segment Trees and Fenwick Trees (also known as Binary Indexed Trees or BITs) are powerful data structures used for efficiently handling range queries and point updates on an array. They are particularly useful in competitive programming and scenarios where you need to frequently query sums, minimums, maximums, or other aggregate values over a range, and also update individual elements [1, 2].

#### 5.4.1 Segment Tree

**Concept:**
A **Segment Tree** is a binary tree used for storing information about intervals or segments. Each node in the Segment Tree represents an interval (a segment) of the original array. The root node represents the entire array, and its children represent the two halves of the array. This recursive division continues until the leaf nodes, which represent individual elements of the array [1, 2].

**Structure:**
-   It's typically implemented as an array, where `tree[node]` stores the aggregate value for the segment represented by `node`.
-   For a node `i`, its left child is `2*i` and its right child is `2*i + 1`.
-   The size of the segment tree array is usually `2 * 2^ceil(log2(N))` or `4*N` for an array of size `N`.

**Operations:**
1.  **Build:** Constructing the segment tree from the original array. This takes O(N) time.
2.  **Query:** Retrieving the aggregate value (e.g., sum, min, max) for a given range `[L, R]`. This takes O(log N) time.
3.  **Update:** Changing the value of an element in the original array and updating the segment tree accordingly. This also takes O(log N) time.

**Advantages:**
-   **Versatility:** Can handle a wide variety of range queries (sum, min, max, GCD, etc.) and point updates.
-   **Lazy Propagation:** Can be extended to handle range updates (e.g., add a value to all elements in a range) efficiently using lazy propagation, which also takes O(log N) time.

**Disadvantages:**
-   **More Complex Implementation:** Generally more complex to implement compared to Fenwick Trees.
-   **Higher Memory Usage:** Requires more memory (typically 4N) than Fenwick Trees.

**Example (Sum Segment Tree - Build and Query):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to build the segment tree
// tree_idx: current node index in the tree array
// low, high: range of the current segment in the original array
// arr: original array
// tree: segment tree array
void build(int tree_idx, int low, int high, const std::vector<int>& arr, std::vector<int>& tree) {
    if (low == high) {
        tree[tree_idx] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * tree_idx + 1, low, mid, arr, tree); // Left child
    build(2 * tree_idx + 2, mid + 1, high, arr, tree); // Right child
    tree[tree_idx] = tree[2 * tree_idx + 1] + tree[2 * tree_idx + 2]; // Sum of children
}

// Function to query sum in a given range
// tree_idx: current node index
// low, high: range of the current segment
// query_low, query_high: query range
int query(int tree_idx, int low, int high, int query_low, int query_high, const std::vector<int>& tree) {
    // No overlap
    if (query_low > high || query_high < low) {
        return 0;
    }
    // Complete overlap
    if (query_low <= low && high <= query_high) {
        return tree[tree_idx];
    }
    // Partial overlap
    int mid = low + (high - low) / 2;
    int left_sum = query(2 * tree_idx + 1, low, mid, query_low, query_high, tree);
    int right_sum = query(2 * tree_idx + 2, mid + 1, high, query_low, query_high, tree);
    return left_sum + right_sum;
}

// Function to update a value at a specific index
// tree_idx: current node index
// low, high: range of the current segment
// arr_idx: index to update in original array
// val: new value
void update(int tree_idx, int low, int high, int arr_idx, int val, std::vector<int>& tree) {
    if (low == high) {
        tree[tree_idx] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if (arr_idx <= mid) {
        update(2 * tree_idx + 1, low, mid, arr_idx, val, tree);
    } else {
        update(2 * tree_idx + 2, mid + 1, high, arr_idx, val, tree);
    }
    tree[tree_idx] = tree[2 * tree_idx + 1] + tree[2 * tree_idx + 2];
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    std::vector<int> tree(4 * n); // Max size for segment tree

    build(0, 0, n - 1, arr, tree);

    std::cout << "Sum of range (1, 3): " << query(0, 0, n - 1, 1, 3, tree) << "\n"; // Expected: 3 + 5 + 7 = 15

    update(0, 0, n - 1, 2, 10, tree); // Update arr[2] from 5 to 10
    std::cout << "Sum of range (1, 3) after update: " << query(0, 0, n - 1, 1, 3, tree) << "\n"; // Expected: 3 + 10 + 7 = 20

    return 0;
}
```

#### 5.4.2 Fenwick Tree (Binary Indexed Tree - BIT)

**Concept:**
A **Fenwick Tree**, or **Binary Indexed Tree (BIT)**, is a data structure that provides an efficient way to calculate prefix sums and update elements in an array. It is simpler to implement and uses less memory than a Segment Tree for certain operations [3, 5].

**Structure:**
-   A BIT is represented as an array, say `BITree[]`, of the same size as the original array (or `N+1` if 1-indexed). Each node in `BITree` stores the sum of some elements of the input array [1, 4].
-   The key idea is that each index `i` in the BITree stores the sum of a range of elements in the original array, and this range is determined by the binary representation of `i`.
-   Specifically, `BITree[i]` stores the sum of elements from `(i - (i & -i) + 1)` to `i` in the original array. `(i & -i)` gives the value of the rightmost set bit of `i`.

**Operations:**
1.  **Update (Point Update):** Adding a value to an element at a specific index and updating the BIT accordingly. This takes O(log N) time.
2.  **Query (Prefix Sum):** Calculating the sum of elements from index 1 to `i` (prefix sum). This takes O(log N) time.
3.  **Range Sum Query:** The sum of a range `[L, R]` can be found by `query(R) - query(L-1)`. This also takes O(log N) time.

**Advantages:**
-   **Simpler Implementation:** Generally easier to implement than Segment Trees.
-   **Memory Efficient:** Requires less memory (typically N) than Segment Trees.
-   **Faster Constant Factor:** Often faster in practice due to simpler operations and better cache performance.

**Disadvantages:**
-   **Limited Operations:** Primarily designed for prefix sum queries and point updates. More complex operations (like range minimum query or range updates without lazy propagation) are not directly supported or are more difficult to implement.

**Example (Fenwick Tree - Update and Query):**

```cpp
#include <iostream>
#include <vector>

// Function to update a value in Fenwick Tree
// idx: 1-based index in original array
// val: value to add to arr[idx]
void update(std::vector<int>& bit, int n, int idx, int val) {
    idx = idx + 1; // Convert to 1-based indexing for BIT
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & (-idx); // Move to parent node
    }
}

// Function to get prefix sum up to idx
// idx: 0-based index in original array
int query(const std::vector<int>& bit, int idx) {
    idx = idx + 1; // Convert to 1-based indexing for BIT
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx); // Move to parent node
    }
    return sum;
}

// Function to build Fenwick Tree from an array
std::vector<int> buildFenwickTree(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> bit(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        update(bit, n, i, arr[i]);
    }
    return bit;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    std::vector<int> bit = buildFenwickTree(arr);

    std::cout << "Sum of elements up to index 3 (0-based): " << query(bit, 3) << "\n"; // Expected: 1 + 3 + 5 + 7 = 16

    // Update arr[2] from 5 to 10 (add 5 to it)
    update(bit, n, 2, 5); // Original value was 5, new value is 10. So add 5.
    std::cout << "Sum of elements up to index 3 after update: " << query(bit, 3) << "\n"; // Expected: 1 + 3 + 10 + 7 = 21

    // Range sum query: sum of arr[1] to arr[3]
    std::cout << "Sum of range (1, 3): " << query(bit, 3) - query(bit, 0) << "\n"; // Expected: 21 - 1 = 20

    return 0;
}
```

#### 5.4.3 Segment Tree vs. Fenwick Tree

| Feature             | Segment Tree                                   | Fenwick Tree (BIT)                               |
|---------------------|------------------------------------------------|--------------------------------------------------|
| **Memory**          | O(4N) or O(2 * 2^ceil(log2(N)))                | O(N)                                             |
| **Implementation**  | More complex                                   | Simpler                                          |
| **Build Time**      | O(N)                                           | O(N log N) (N updates, each log N)               |
| **Query Time**      | O(log N)                                       | O(log N)                                         |
| **Update Time**     | O(log N)                                       | O(log N)                                         |
| **Range Updates**   | Supports with Lazy Propagation (O(log N))      | Not directly supported (can be simulated with two BITs for certain cases) |
| **Types of Queries**| Sum, Min, Max, GCD, etc.                       | Primarily prefix sums                              |
| **Flexibility**     | More versatile, handles wider range of problems| Less versatile, specialized for prefix sums       |

**When to use which:**
-   Use **Fenwick Tree** when you need point updates and prefix/range sum queries, and simplicity/memory efficiency is a priority.
-   Use **Segment Tree** when you need more complex range queries (e.g., range min/max), or range updates (with lazy propagation), or when the operation is not easily invertible (like XOR sum). Segment Trees are generally more powerful and flexible.

---

### References

[1] GeeksforGeeks. "Segment Tree in C++." *GeeksforGeeks*, 30 Jul. 2024, www.geeksforgeeks.org/cpp/segment-tree-in-cpp/.
[2] CP-Algorithms. "Segment Tree." *CP-Algorithms*, 20 Dec. 2023, cp-algorithms.com/data_structures/segment_tree.html.
[3] GeeksforGeeks. "Binary Indexed Tree or Fenwick Tree." *GeeksforGeeks*, 19 Dec. 2024, www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/.
[4] CP-Algorithms. "Fenwick Tree." *CP-Algorithms*, 15 Apr. 2025, cp-algorithms.com/data_structures/fenwick.html.
[5] GeeksforGeeks. "Comparison between Fenwick Tree vs Segment Tree." *GeeksforGeeks*, 15 Sep. 2023, www.geeksforgeeks.org/dsa/fenwick-tree-vs-segment-tree/.

---



### 5.5 Disjoint Set Union (DSU)

**Concept:**
A **Disjoint Set Union (DSU)** data structure, also known as **Union-Find**, is a data structure that maintains a collection of disjoint (non-overlapping) sets and supports two primary operations [1, 5]:

1.  **`find(element)`:** Determines which set an element belongs to. It returns a representative (usually the root) of the set containing the element.
2.  **`union(element1, element2)`:** Merges two sets into a single set. If `element1` and `element2` are in different sets, their sets are merged.

DSU is particularly useful for problems involving connected components in graphs, network connectivity, and clustering [2, 7].

**How it Works (Basic Idea):**
Each set is represented as a tree. The root of each tree is the representative of its set. Initially, each element is in its own set, so each element is a root of a single-node tree.

**Optimizations for Efficiency:**
Without optimizations, DSU operations can be slow (O(N) in worst case). Two key optimizations make DSU operations almost constant time (amortized O(α(N)), where α is the inverse Ackermann function, which grows extremely slowly and is practically constant for all realistic N) [1, 4]:

1.  **Path Compression (for `find` operation):** When `find` is called on an element, it traverses up the tree to find the root. During this traversal, it makes all visited nodes directly point to the root. This flattens the tree, making future `find` operations faster for these nodes and their descendants.
2.  **Union by Rank or Union by Size (for `union` operation):**
    -   **Union by Rank:** Attaches the root of the smaller rank tree under the root of the larger rank tree. Rank typically represents the height of the tree (or an upper bound on it).
    -   **Union by Size:** Attaches the root of the smaller size tree under the root of the larger size tree. Size represents the number of nodes in the tree.
    Both strategies aim to keep the trees as flat as possible, minimizing their height and thus the path length for `find` operations.

**Basic C++ Implementation (with Path Compression and Union by Size):**

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::iota

class DSU {
public:
    std::vector<int> parent; // parent[i] stores the parent of element i
    std::vector<int> sz;     // sz[i] stores the size of the set if i is a root

    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Each element is its own parent initially
        sz.assign(n, 1); // Each set initially has size 1
    }

    // Find operation with Path Compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); // Path compression
    }

    // Union operation with Union by Size
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Attach smaller tree under root of larger tree
            if (sz[root_i] < sz[root_j]) {
                std::swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }

    // Check if two elements are in the same set
    bool are_connected(int i, int j) {
        return find(i) == find(j);
    }
};

int main() {
    DSU dsu(5); // Create DSU for 5 elements (0, 1, 2, 3, 4)

    std::cout << "Are 0 and 1 connected? " << (dsu.are_connected(0, 1) ? "Yes" : "No") << "\n"; // No

    dsu.unite(0, 1);
    std::cout << "Uniting 0 and 1.\n";
    std::cout << "Are 0 and 1 connected? " << (dsu.are_connected(0, 1) ? "Yes" : "No") << "\n"; // Yes

    dsu.unite(2, 3);
    std::cout << "Uniting 2 and 3.\n";
    dsu.unite(1, 2);
    std::cout << "Uniting 1 and 2.\n";

    std::cout << "Are 0 and 3 connected? " << (dsu.are_connected(0, 3) ? "Yes" : "No") << "\n"; // Yes
    std::cout << "Are 0 and 4 connected? " << (dsu.are_connected(0, 4) ? "Yes" : "No") << "\n"; // No

    return 0;
}
```

**Time Complexity:**
-   **`find` and `unite` operations:** Amortized O(α(N)), where α is the inverse Ackermann function. This is practically constant time for all reasonable input sizes.

**Space Complexity:** O(N) for storing parent and size/rank arrays.

**Applications:**
-   **Connected Components:** Finding and managing connected components in a graph (e.g., Kruskal's algorithm for Minimum Spanning Tree).
-   **Cycle Detection:** Detecting cycles in an undirected graph.
-   **Network Connectivity:** Determining if two nodes are connected in a network.
-   **Grid Problems:** Solving problems on grids where cells can be connected.
-   **Disjoint Set Problems:** Any problem that involves partitioning a set of elements into disjoint subsets and performing union/find operations.

---

### References

[1] CP-Algorithms. "Disjoint Set Union." *CP-Algorithms*, 12 Oct. 2024, cp-algorithms.com/data_structures/disjoint_set_union.html.
[2] GeeksforGeeks. "Introduction to Disjoint Set (Union-Find Algorithm)." *GeeksforGeeks*, 26 Feb. 2025, www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/.
[3] takeUforward. "Disjoint Set | Union by Rank | Union by Size | Path Compression: G-46." *takeUforward*, takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/.
[4] Wikipedia. "Disjoint-set data structure." *Wikipedia*, en.wikipedia.org/wiki/Disjoint-set_data_structure.
[5] HackerEarth. "Disjoint Set Union (Union Find)." *HackerEarth*, www.hackerearth.com/practice/notes/disjoint-set-union-union-find/.

---



### 5.6 Monotonic Stack / Queue

**Concept:**
A **Monotonic Stack** and a **Monotonic Queue** are specialized data structures that maintain their elements in a specific order—either strictly increasing or strictly decreasing. They are not new data structures themselves, but rather a technique applied to standard stack and queue (often implemented with a deque) to optimize certain problems, typically those involving finding the next greater/smaller element or maximum/minimum in a sliding window [1, 2].

#### 5.6.1 Monotonic Stack

**Concept:**
A Monotonic Stack is a stack where the elements are always kept in either strictly increasing or strictly decreasing order. When a new element is to be pushed onto the stack, elements that violate the monotonicity are popped until the property is restored. This ensures that the stack always maintains its ordered property [1, 7].

**How it Works:**
-   When pushing a new element `x`:
    -   If the stack is empty or `x` maintains the monotonicity (e.g., `x` is greater than the top for an increasing stack), push `x`.
    -   Otherwise, pop elements from the top of the stack until `x` can be pushed while maintaining the monotonicity. Then push `x`.

**Applications:**
Monotonic stacks are particularly useful for problems that require finding the "next greater element", "next smaller element", "previous greater element", or "previous smaller element" for each element in an array. They can solve these problems in O(N) time, whereas a naive approach might take O(N^2) [8].

**Example (Next Greater Element):**
Given an array `nums`, find the next greater element for each element. The next greater element of some element `x` is the first element to its right that is strictly greater than `x`.

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> nextGreaterElement(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1); // Initialize with -1 (no greater element)
    std::stack<int> st; // Stores indices of elements

    for (int i = 0; i < n; ++i) {
        // While stack is not empty and current element is greater than element at stack top
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i]; // Current element is the next greater for stack top
            st.pop();
        }
        st.push(i); // Push current element's index onto stack
    }
    return result;
}

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> nums1 = {4, 5, 2, 25};
    std::cout << "Next greater elements for [4,5,2,25]: ";
    printVector(nextGreaterElement(nums1)); // Expected: [5,25,25,-1]

    std::vector<int> nums2 = {13, 7, 6, 12};
    std::cout << "Next greater elements for [13,7,6,12]: ";
    printVector(nextGreaterElement(nums2)); // Expected: [-1,12,12,-1]

    return 0;
}
```

**Time Complexity:** O(N) because each element is pushed and popped from the stack at most once.
**Space Complexity:** O(N) in the worst case (e.g., for a decreasing array, all elements might be in the stack).

#### 5.6.2 Monotonic Queue

**Concept:**
A Monotonic Queue is a queue (often implemented using `std::deque` in C++) where the elements are maintained in either strictly increasing or strictly decreasing order. It is primarily used to find the maximum or minimum element within a sliding window in O(1) time per window, after an initial O(N) setup [11, 14].

**How it Works:**
-   When adding a new element `x` to the back of the queue:
    -   Pop elements from the back of the queue that violate the monotonicity (e.g., if `x` is greater than the back element for a decreasing queue, pop the back element).
    -   Then push `x` to the back.
-   When removing an element from the front of the window:
    -   If the element at the front of the queue is the one leaving the window, pop it from the front of the queue.

**Applications:**
Monotonic queues are most commonly used to solve problems like "Sliding Window Maximum" or "Sliding Window Minimum", where you need to efficiently query the extreme value within a moving window [9, 18].

**Example (Sliding Window Maximum):**
This problem was covered in the "Sliding Window Technique" section (Problem 10). The solution provided there uses a `std::deque` to implement a monotonic queue, demonstrating its application.

**Key Differences and Use Cases:**

| Feature             | Monotonic Stack                                | Monotonic Queue (Deque)                               |
|---------------------|------------------------------------------------|-------------------------------------------------------|
| **Primary Use**     | Finding Next/Previous Greater/Smaller Elements | Finding Max/Min in Sliding Window                     |
| **Data Structure**  | `std::stack`                                   | `std::deque`                                          |
| **Operations**      | Push, Pop, Top                                 | Push Front/Back, Pop Front/Back, Front/Back         |
| **Complexity**      | O(N) for processing array                      | O(N) for processing array                             |

Both monotonic stacks and queues are powerful tools for optimizing problems that involve sequences and ranges, often reducing the time complexity from quadratic to linear. They are a common pattern in competitive programming and technical interviews.

---

### References

[1] GeeksforGeeks. "Introduction to Monotonic Stack." *GeeksforGeeks*, 27 Feb. 2025, www.geeksforgeeks.org/dsa/introduction-to-monotonic-stack-2/.
[2] Medium. "Mastering Monotonic Stacks: Optimizing Algorithmic Efficiency in Array and Sequence Problems." *Medium*, 9 Dec. 2024, medium.com/@hanxuyang0826/mastering-monotonic-stacks-optimizing-algorithmic-efficiency-in-array-and-sequence-problems-28d2a16eeccc.
[3] GitBook. "Monotonic Stack | Algorithm." *GitBook*, 29 Jan. 2022, liuzhenglaichn.gitbook.io/algorithm/monotonic-stack.
[4] GeeksforGeeks. "How to Identify and Solve Monotonic Stack Problems." *GeeksforGeeks*, 27 Aug. 2024, www.geeksforgeeks.org/dsa/how-to-identify-and-solve-monotonic-stack-problems/.
[5] Medium. "Monotonic Stack for Efficient Problem Solving: Next Greater, Next Smaller, Previous Greater, and." *Medium*, 20 Jan. 2025, medium.com/@manuchaitanya/monotonic-stack-for-efficient-problem-solving-next-greater-next-smaller-previous-greater-and-6c63d0572644.
[6] GeeksforGeeks. "Introduction to Monotonic Queues." *GeeksforGeeks*, 5 May 2023, www.geeksforgeeks.org/dsa/introduction-to-monotonic-queues/.
[7] Medium. "Monotonic Queue Explained with LeetCode Problems." *Medium*, 1 Nov. 2018, medium.com/algorithms-and-leetcode/monotonic-queue-explained-with-leetcode-problems-7db7c530c1d6.
[8] Labuladong. "Monotonic Queue to Solve Sliding Window Problems." *Labuladong*, labuladong.online/algo/en/data-structure/monotonic-queue/.
[9] Labuladong. "Special Data Structure: Monotonic Stack." *Labuladong*, labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack.
[10] CP-Algorithms. "Minimum Stack / Minimum Queue." *CP-Algorithms*, 31 May 2025, cp-algorithms.com/data_structures/stack_queue_modification.html.
[11] Design Gurus. "Introduction to Monotonic Queue Pattern." *Design Gurus*, www.designgurus.io/course-play/grokking-advanced-coding-patterns-for-interviews/doc/introduction-to-monotonic-queue-pattern.
[12] Medium. "Monotonic Stacks/Queues: The Secret Weapon for Efficient Algorithms." *Medium*, 5 Apr. 2025, medium.com/@mishrasatyam3456/monotonic-stacks-queues-the-secret-weapon-for-efficient-algorithms-bd35a985dd72.
[13] Medium. "The Ultimate Guide to Monotonic Queue." *Number Analytics*, 13 Jun. 2025, www.numberanalytics.com/blog/ultimate-guide-monotonic-queue.
[14] YouTube. "Monotonic Stack Data Structure Explained." *YouTube*, 16 Jan. 2023, www.youtube.com/watch?v=Dq_ObZwTY_Q.

---



### 5.7 Top Interview Patterns

This section covers some of the most frequently encountered algorithmic patterns in coding interviews. Understanding these patterns can help you identify the underlying structure of a problem and apply a suitable solution efficiently.

#### 5.7.1 Two Pointers

**Concept:**
The **Two Pointers** technique is a powerful and efficient algorithmic pattern used to solve problems that involve traversing or manipulating sequential data structures like arrays, strings, or linked lists. It typically involves using two pointers (indices or references) that move through the data structure based on certain conditions, often to find pairs, triplets, or subarrays that satisfy specific criteria [1, 3].

**Common Scenarios and Techniques:**
1.  **Pointers Moving Towards Each Other (from ends):**
    -   Used when the input array is sorted (or can be sorted). One pointer starts at the beginning, and the other at the end. They move inwards until they meet or cross.
    -   **Applications:** Finding a pair with a given sum in a sorted array, checking for palindromes, reversing an array/string, finding triplets/quadruplets with a given sum.

2.  **Pointers Moving in the Same Direction (Fast and Slow Pointers):**
    -   Both pointers start at the beginning (or with a fixed offset) and move in the same direction, but at different speeds.
    -   **Applications:** Cycle detection in linked lists (Floyd's Cycle-Finding Algorithm), finding the middle of a linked list, removing duplicates from a sorted array/linked list, finding the Nth node from the end of a linked list.

3.  **Pointers for Sliding Window:**
    -   Two pointers define a 


window (a subarray or substring) that slides over the input. One pointer (start) marks the beginning of the window, and the other (end) expands the window. The window size might be fixed or variable.
    -   **Applications:** Finding maximum/minimum subarray sum of a fixed size, finding the longest substring with K distinct characters, finding the minimum window substring.

**Example (Two Pointers - Pointers Moving Towards Each Other):**

**Problem:** Given a sorted array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. Assume that each input would have exactly one solution, and you may not use the same element twice.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> twoSumSorted(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int currentSum = nums[left] + nums[right];
        if (currentSum == target) {
            return {left, right};
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {}; // Should not reach here based on problem statement
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSumSorted(nums, target);
    if (!result.empty()) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n"; // Expected: [0, 1]
    }

    nums = {3, 2, 4};
    target = 6;
    // Note: For unsorted arrays, a hash map approach is typically used.
    // If sorting is allowed, sort and then use two pointers.
    // std::sort(nums.begin(), nums.end()); // If not already sorted
    result = twoSumSorted(nums, target);
    if (!result.empty()) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n"; // Expected: [1, 2] after sorting and using original indices
    }

    return 0;
}
```

**Time Complexity:** O(N) for traversal (after sorting, if needed, which is O(N log N)).
**Space Complexity:** O(1) if input is sorted, or O(log N) to O(N) for sorting depending on algorithm.

---

#### 5.7.2 Recursion Tree

**Concept:**
A **Recursion Tree** is a visual method for solving recurrence relations, particularly useful for analyzing the time complexity of recursive algorithms. It diagrams the tree of recursive calls, and the amount of work done at each level of the recursion [1, 8]. By summing the work done at each level, and then summing across all levels, one can determine the total time complexity.

**How it Works:**
-   Each node in the tree represents the cost of a single subproblem in the recursion.
-   The children of a node represent the recursive calls made by that subproblem.
-   The sum of costs at each level gives the total work done at that level.
-   The total cost of the algorithm is the sum of costs of all levels.

**Example (Merge Sort Recurrence):**
Consider the recurrence relation for Merge Sort: `T(n) = 2T(n/2) + O(n)`.

-   **Level 0:** `T(n)` (cost `cn`)
-   **Level 1:** `2 * T(n/2)` (cost `2 * c(n/2) = cn`)
-   **Level 2:** `4 * T(n/4)` (cost `4 * c(n/4) = cn`)
-   ... (This continues until the subproblem size is 1)
-   **Last Level (leaves):** `n * T(1)` (cost `n * c(1) = O(n)`)

The height of the tree is `log n`. Since each level costs `cn`, and there are `log n` levels, the total cost is `cn * log n = O(n log n)`.

**Applications:**
-   Analyzing the time complexity of divide-and-conquer algorithms (e.g., Merge Sort, Quick Sort).
-   Understanding the breakdown of work in recursive functions.

---

#### 5.7.3 Memoization

**Concept:**
**Memoization** is an optimization technique used primarily to speed up computer programs by storing the results of expensive function calls and returning the cached result when the same inputs occur again [1, 4]. It's a top-down approach to Dynamic Programming, where you write a recursive solution and then add a caching mechanism.

**How it Works:**
1.  **Identify Overlapping Subproblems:** The problem must have overlapping subproblems, meaning the same subproblems are solved multiple times during the recursion.
2.  **Store Results:** Use a data structure (e.g., an array, hash map, or `std::map` in C++) to store the results of function calls. The input parameters of the function serve as the key, and the computed result as the value.
3.  **Check Cache Before Computation:** Before computing a result for a given set of inputs, check if the result is already in the cache. If it is, return the cached value. Otherwise, compute the result, store it in the cache, and then return it.

**Example (Fibonacci Sequence with Memoization):**

```cpp
#include <iostream>
#include <vector>
#include <map>

// Using a vector for memoization (suitable for non-negative integer inputs)
std::vector<long long> memo_fib;

long long fibonacci_memo(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo_fib[n] != -1) { // Check if already computed
        return memo_fib[n];
    }
    // Compute and store
    memo_fib[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
    return memo_fib[n];
}

// Using std::map for memoization (more general, handles sparse inputs)
std::map<int, long long> memo_fib_map;

long long fibonacci_memo_map(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo_fib_map.count(n)) { // Check if already computed
        return memo_fib_map[n];
    }
    // Compute and store
    memo_fib_map[n] = fibonacci_memo_map(n - 1) + fibonacci_memo_map(n - 2);
    return memo_fib_map[n];
}

int main() {
    int n = 40;

    // Using vector memoization
    memo_fib.assign(n + 1, -1); // Initialize with -1 (or some indicator for uncomputed)
    std::cout << "Fibonacci(" << n << ") with vector memoization: " << fibonacci_memo(n) << "\n";

    // Using map memoization
    std::cout << "Fibonacci(" << n << ") with map memoization: " << fibonacci_memo_map(n) << "\n";

    return 0;
}
```

**Time Complexity:** O(N) because each subproblem is computed only once.
**Space Complexity:** O(N) for the memoization table (plus O(N) for recursion stack depth).

**Relationship with Dynamic Programming:**
Memoization is a top-down approach to Dynamic Programming. Dynamic Programming itself can be implemented using two main approaches:
1.  **Memoization (Top-Down):** Recursive solution with caching.
2.  **Tabulation (Bottom-Up):** Iterative solution that builds up the solution from base cases.

Both achieve the same optimal time complexity for problems with overlapping subproblems and optimal substructure.

---

### References

[1] GeeksforGeeks. "Top Problems on Two Pointers Technique for Interviews." *GeeksforGeeks*, 16 May 2025, www.geeksforgeeks.org/top-problems-on-two-pointers-technique-for-interviews/.
[2] Medium. "Mastering the Two Pointer Technique for Technical Interviews." *Medium*, 17 Sep. 2023, medium.com/@vidyasagarr7/mastering-the-two-pointer-technique-for-technical-interviews-fcce04128c0a.
[3] ByteByteGo. "Introduction to Two Pointers." *ByteByteGo*, bytebytego.com/courses/coding-patterns/two-pointers/introduction-to-two-pointers?fpr=javarevisited.
[4] GeeksforGeeks. "How to solve time complexity Recurrence Relations using Recursion Tree Method." *GeeksforGeeks*, 5 Jul. 2024, www.geeksforgeeks.org/dsa/how-to-solve-time-complexity-recurrence-relations-using-recursion-tree-method/.
[5] Scaler Topics. "Recursion Tree Method." *Scaler Topics*, 29 Jun. 2024, www.scaler.com/topics/data-structures/recursion-tree-method/.
[6] GeeksforGeeks. "What is Memoization? A Complete Tutorial." *GeeksforGeeks*, 29 Nov. 2024, www.geeksforgeeks.org/dsa/what-is-memoization-a-complete-tutorial/.
[7] Studyplan.dev. "Recursion and Memoization in C++ | A Practical Guide." *Studyplan.dev*, 20 May 2024, www.studyplan.dev/pro-cpp/recursion.
[8] Number Analytics. "Mastering Recursion Trees in Recurrence Relations." *Number Analytics*, 13 Jun. 2025, www.numberanalytics.com/blog/mastering-recursion-trees-in-recurrence-relations.

---

