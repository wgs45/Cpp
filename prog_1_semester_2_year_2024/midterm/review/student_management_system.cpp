#include <iostream>
using namespace std;

class Student {
private:
  string name, student_id;

public:
  Student(const string &name, const string &id) : name(name), student_id(id) {}

  const string &get_name() const { return name; }

  const string *get_id() const { return &student_id; }
};

class Classroom {
private:
  Student *student_1[100];
  int student_count = 0;

public:
  void add_student(Student *student) {
    if (student_count < 100) {
      student_1[student_count++] = student;
    }
  }

  Student *find_by_id(const string &id) const {
    int i;
    for (i = 0; i < student_count; i++) {
      if (*student_1[i]->get_id() == id) {
        return student_1[i];
      }
    }
    return nullptr;
  }
};

int main() {
  // Dynamically allocate student to ensure presistence
  Student *student_1 = new Student("Alpha", "12345");
  Student *student_2 = new Student("Beta", "67890");

  Classroom classroom_1;
  classroom_1.add_student(student_1);
  classroom_1.add_student(student_2);

  Student *found_student = classroom_1.find_by_id("67890");
  if (found_student) {
    cout << "Found student: " << found_student->get_name() << endl;
  } else {
    cout << "Student not found!" << endl;
  }

  return 0;
}
