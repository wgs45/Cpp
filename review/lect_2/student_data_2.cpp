#include <iostream>
#include <cstring>

class Student {
private:
    int Student_ID;
    char Name[20];
    float English, Math, Physics, Total, Avg_grade;

    void calculate_total() {
        Total = English + Math + Physics;
    }

    void calculate_average() {
        Avg_grade = Total / 3;
    }

public:
    void takedata() {
        std::cout << "Enter Student ID: ";
        std::cin >> Student_ID;
        std::cout << "Enter Name: ";
        std::cin.ignore(); // ignore the newline char left in the buffer by std::cin 
        std::cin.getline(Name, 20);
        std::cout << "Enter English marks: ";
        std::cin >> English;
        std::cout << "Enter Math marks: ";
        std::cin >> Math;
        std::cout << "Enter Physics marks: ";
        std::cin >> Physics;
        calculate_total();
        calculate_average();
    }

    void showdata() {
        std::cout << "Student ID: " << Student_ID << std::endl;
        std::cout << "Name: " << Name << std::endl;
        std::cout << "English: " << English << std::endl;
        std::cout << "Math: " << Math << std::endl;
        std::cout << "Physics: " << Physics << std::endl;
        std::cout << "Total Marks: " << Total << std::endl;
        std::cout << "Average Marks: " << Avg_grade<< std::endl;
    }

    void check_status() const {
        if (Avg_grade >= 60) {
            std::cout << "Pass" << std::endl;
        } else {
            std::cout << "Failed" << std::endl;
        }
    }
};

int main() {
    Student s1;
    s1.takedata();
    s1.showdata();
    s1.check_status();

    return 0;
}
