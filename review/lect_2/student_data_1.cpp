#include <iostream>
#include <cstring>

class Student {
private:
    int Student_ID;
    char Name[20];
    float English, Math, Physics, Total;

    float grades() {
        return English + Math + Physics;
    }

public:
    void Takedata() {
        std::cout << "Enter Student ID: ";
        std::cin >> Student_ID;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::cin.getline(Name, 20);
        std::cout << "Enter English marks: ";
        std::cin >> English;
        std::cout << "Enter Math marks: ";
        std::cin >> Math;
        std::cout << "Enter Physics marks: ";
        std::cin >> Physics;
        Total = grades();
    }
    void Showdata() const {
        std::cout << "Student ID: " << Student_ID << std::endl;
        std::cout << "Name: " << Name << std::endl;
        std::cout << "English marks: " << English << std::endl;
        std::cout << "Math marks: " << Math << std::endl;
        std::cout << "Physics marks: " << English << std::endl;
        std::cout << "Total marks: " << Total << std::endl;
    }
};

int main() {
    Student s1;
    s1.Takedata();
    s1.Showdata();

    return 0;
}
