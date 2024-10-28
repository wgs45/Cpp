#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  string name;
  string student_id;

public:
  // Constructor to initialize student name and student_id
  Student(const string &name, const string &id) : name(name), student_id(id) {}

  // Function to return student name
  const string &get_name() const { return name; }

  // Function to return student_id
  const string *get_id() const { return &student_id; }
};

class Classroom {
private:
  Student *students[100];
  int student_count = 0;

public:
  void add_student(Student *student) {
    if (student_count < 100) {
      students[student_count++] = student;
    }
  }

  Student *find_student_by_id(const string &id) const {
    int i;
    for (i = 0; i < student_count; ++i) {
      cout << "Checking ID in DB: " << id << " against "
           << *students[i]->get_id() << endl;
      if (*students[i]->get_id() == id) {
        return students[i];
      }
    }
    return nullptr;
  }
};

int main() {
  // Dynamically allocate student objects to ensure presistence
  Student *student_1 = new Student("Alice", "12345");
  Student *student_2 = new Student("Bob", "67890");

  Classroom classroom_1;
  classroom_1.add_student(student_1);
  classroom_1.add_student(student_2);

  Student *foundStudent = classroom_1.find_student_by_id("67890");
  if (foundStudent) {
    std::cout << "Found student: " << foundStudent->get_name() << std::endl;
  } else {
    std::cout << "Student not found." << std::endl;
  }

  // Free allocated memory
  delete student_1;
  delete student_2;

  return 0;
}
