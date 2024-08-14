#include <iostream>
#include <memory>
using namespace std;

class Grade {
private:
    int math;
    int eng;
    int sum;

public:
    Grade() = default;
    Grade(int m, int e): math(m), eng(e) {};
    ~Grade() { cout << "Destructor of 'grade' works here " << endl; };
    void sumUp() { sum = math + eng; }
    int showSum() { return sum; }
};

int main() {
    auto ptr = make_shared<Grade>(100, 90);
    ptr -> sumUp();
    cout << "The total grades: " << ptr -> showSum() << endl;

    return 0;
}
