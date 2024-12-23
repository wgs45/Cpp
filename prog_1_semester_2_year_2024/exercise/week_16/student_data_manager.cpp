#include <iostream>
#include <list>
#include <string>

// Struct to store student information
struct Student {
  int id;
  std::string name;
  float grade;

  Student(int id, const std::string &name, float grade)
      : id(id), name(name), grade(grade) {}
};

// Function to add a student to the list
void addStudent(std::list<Student *> &students, int id, const std::string &name,
                float grade) {
  Student *newStudent = new Student(id, name, grade);
  students.push_back(newStudent);
}

// Function to delete a student by ID
void deleteStudent(std::list<Student *> &students, int id) {
  for (auto it = students.begin(); it != students.end(); ++it) {
    if ((*it)->id == id) {
      delete *it;         // Free memory
      students.erase(it); // Remove from the list
      return;
    }
  }
  std::cout << "Student with ID: " << id << " not found" << std::endl;
}

// Function to output data
void printStudent(const std::list<Student *> &students) {
  for (const auto &student : students) {
    std::cout << "ID: " << student->id << ", Name: " << student->name
              << ", Grade: " << student->grade << std::endl;
  }
}

int main() {
  std::list<Student *> students;

  addStudent(students, 1, "Alpha", 85.5);
  addStudent(students, 2, "Beta", 90.0);
  addStudent(students, 3, "Charlie", 70.0);

  std::cout << "All students: " << std::endl;
  printStudent(students);

  std::cout << "\nDeleting students with ID 2..." << std::endl;
  deleteStudent(students, 2);

  std::cout << "All students: " << std::endl;
  printStudent(students);

  // Clean up the reamining students
  for (auto &student : students) {
    delete student;
  }

  students.clear();

  return 0;
}
