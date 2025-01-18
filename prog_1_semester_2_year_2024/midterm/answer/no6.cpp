#include <iostream>
using namespace std;

class Employee {
public:
    virtual void doWork() = 0;
    virtual ~Employee() {};
};

class Manager : public Employee {
public:
    void doWork() override {
        cout << "Planning" << endl;
    }
};

class Engineer : public Employee {
public:
    void doWork() override {
        cout << "Coding" << endl;
    }
};

int main() {
    Manager *manager1 = new Manager();
    Engineer *engineer1 = new Engineer();

    manager1 -> doWork();
    engineer1 -> doWork();

    delete manager1;
    delete engineer1;

    return 0;
}
