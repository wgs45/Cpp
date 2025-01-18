#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Bark() { cout << "Animal sound" << endl;}
};

class Mammal : public Animal {
public:
    void Bark() override {
        cout << "Mammal sound" << endl;
    }
};

class Fish : public Animal {
public:
    void Bark() override {
        cout << "Fish sound" << endl;
    }
};

int main() {
    // Animal *animal1 = new Animal();
    Mammal *mammal1 = new Mammal();
    Fish *fish1 = new Fish();

    // animal1 -> Bark();
    mammal1 -> Bark();
    fish1 -> Bark();

    // delete animal1;
    delete mammal1;
    delete fish1;

    return 0;
}
