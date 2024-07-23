#include <iostream>
using namespace std;

namespace Uq {
class Student {
public:
  string name;
  int age;
  double height;
  double weight;
  string department;
  void play();
  void study();
};
class Professor {
public:
  string name;
  int age;
  double height;
  double weight;
  string department;
  void teach();
  void research();
  void meeting();
};
} // namespace Uq
