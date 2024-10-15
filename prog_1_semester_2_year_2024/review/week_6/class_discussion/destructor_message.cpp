#include <iostream>
using namespace std;

class Sample {
public:
  // Constructor
  Sample() { cout << "I am a sample" << endl; }

  // Destructor
  ~Sample() { cout << "The sample is deleted" << endl; }
};

int main() {
  Sample *s1 = new Sample[2];

  delete[] s1;

  return 0;
}
