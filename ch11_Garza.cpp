// ============================================================
// COSC 1437 - Chapter 11: Inheritance and Composition
// Animal Shelter System
//
// Name: Adan Garza
// Date:06/24/2026
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Address
{
public:
    void setAddress(string street, string city, string state);
    void printAddress() const;
    Address(string street = "", string city = "", string state = "");

private:
    string street;
    string city;
    string state;
};

void Address::setAddress(string s, string c, string st)
{
    street = s;
    city   = c;
    state  = st;
}

void Address::printAddress() const
{
    cout << street << ", " << city << ", " << state;
}

Address::Address(string s, string c, string st)
{
    street = s;
    city   = c;
    state  = st;
}


// ============================================================
// CLASS: Animal  (BASE CLASS)
// ============================================================
//
// You must implement:
//   setInfo()    - sets name, age, animalType
//   getName()    - returns name
//   getAge()     - returns age
//   getType()    - returns animalType
//   print()      - prints: Name: <name>  Age: <age>  Type: <animalType>
//   Constructor  - Animal(string n, int a, string t)
//   Default ctor - initializes to "", 0, ""

class Animal
{
public:
    void   setInfo(string n, int a, string t);
    string getName() const;
    int    getAge()  const;
    string getType() const;
    void   print() const;

    Animal(string n = "", int a = 0, string t = "");

protected:
    string name;
    int    age;
    string animalType;
};

// TODO: Write Animal member function definitions here.

Animal::Animal(string n, int a, string t)
{
    name = n;
    age = a;
    animalType = t;
}

void Animal::setInfo(string n, int a, string t)
{
    name = n;
    age = a;
    animalType = t;
}

string Animal::getName() const
{
    return name;
}

int Animal::getAge() const
{
    return age;
}

string Animal::getType() const
{
    return animalType;
}

void Animal::print() const
{
    cout << "Name: " << name
         << "  Age: " << age
         << "  Type: " << animalType << endl;
}


// ============================================================
// CLASS: Dog  (DERIVED from Animal)
// ============================================================
//
// You must implement:
//   setBreed() / getBreed()
//   print()  - call Animal::print() first, then print breed
//   Dog(string name, int age, string breed)
//     -- use initializer list: : Animal(name, age, "Dog")

class Dog : public Animal
{
public:
    void   setBreed(string b);
    string getBreed() const;
    void   print() const;

    Dog(string name = "", int age = 0, string breed = "");

private:
    string breed;
};

// TODO: Write Dog member function definitions here.


Dog::Dog(string name, int age, string breed)
    : Animal(name, age, "Dog")
{
    this->breed = breed;
}

void Dog::setBreed(string b)
{
    breed = b;
}

string Dog::getBreed() const
{
    return breed;
}

void Dog::print() const
{
    Animal::print();
    cout << "Breed: " << breed << endl;
}


// ============================================================
// CLASS: Cat  (DERIVED from Animal)
// ============================================================
// You must implement:
//   setIndoor() / getIndoor()
//   print()  - call Animal::print() first, then print Indoor: Yes/No
//   Cat(string name, int age, bool indoor)
//     -- use initializer list: : Animal(name, age, "Cat")

class Cat : public Animal
{
public:
    void setIndoor(bool i);
    bool getIndoor() const;
    void print() const;

    Cat(string name = "", int age = 0, bool indoor = true);

private:
    bool isIndoor;
};

// TODO: Write Cat member function definitions here.

Cat::Cat(string name, int age, bool indoor)
    : Animal(name, age, "Cat")
{
    isIndoor = indoor;
}

void Cat::setIndoor(bool i)
{
    isIndoor = i;
}

bool Cat::getIndoor() const
{
    return isIndoor;
}

void Cat::print() const
{
    Animal::print();
    cout << "Indoor: " << (isIndoor ? "Yes" : "No") << endl;
}


// ============================================================
// CLASS: Shelter  (COMPOSITION demo - provided, mostly)
// ============================================================
// Shelter HAS-A Address. The constructor is yours to implement.
// Initialize 'location' in the initializer list.

class Shelter
{
public:
    void printInfo() const;
    Shelter(string name, string street, string city,
            string state, int cap);

private:
    string  shelterName;
    Address location;      // composition: Shelter HAS-A Address
    int     capacity;
};

void Shelter::printInfo() const
{
    cout << "Shelter: " << shelterName << endl;
    cout << "Address: ";
    location.printAddress();
    cout << endl;
    cout << "Capacity: " << capacity << " animals" << endl;
}

// TODO: Write the Shelter constructor here.
// Hint: Shelter::Shelter(string name, string street, string city,
//                        string state, int cap)
//            : location(street, city, state)
//       { shelterName = name; capacity = cap; }

Shelter::Shelter(string name, string street, string city,
                 string state, int cap)
    : location(street, city, state)
{
    shelterName = name;
    capacity = cap;
}


// ============================================================
// MAIN  (do not modify)
// ============================================================
int main()
{
    cout << "=== Animal Shelter System ===" << endl << endl;

    // PART 1: Shelter (composition)
    cout << "--- Shelter Info ---" << endl;
    Shelter happyPaws("Happy Paws Shelter",
                      "123 Main St", "Humble", "TX", 50);
    happyPaws.printInfo();
    cout << endl;

    // PART 2: Base class
    cout << "--- Base Class Animals ---" << endl;
    Animal a1("Generic", 4, "Unknown");
    a1.print();
    cout << endl;

    Animal a2;
    a2.setInfo("Another", 2, "Mystery");
    a2.print();
    cout << endl;

    // PART 3: Dogs (inheritance + override)
    cout << "--- Dogs ---" << endl;
    Dog d1("Buddy", 3, "Labrador");
    d1.print();
    cout << endl;

    Dog d2;
    d2.setInfo("Max", 5, "Dog");
    d2.setBreed("Beagle");
    d2.print();
    cout << endl;

    // PART 4: Cats (inheritance + override)
    cout << "--- Cats ---" << endl;
    Cat c1("Whiskers", 5, true);
    c1.print();
    cout << endl;

    Cat c2("Shadow", 2, false);
    c2.print();
    cout << endl;

    // PART 5: IS-A demo using Animal array
    cout << "--- All Animals in Shelter ---" << endl;
    Animal* roster[4];
    roster[0] = &a1;
    roster[1] = &d1;
    roster[2] = &c1;
    roster[3] = &c2;

    for (int i = 0; i < 4; i++)
    {
        cout << "Animal " << i + 1 << ": "
             << roster[i]->getName()
             << " (" << roster[i]->getType() << ")"
             << " - Age: " << roster[i]->getAge() << endl;
    }

    cout << endl << "Program complete." << endl;
    return 0;
}
