#include "tku.h"
using namespace std;

void Tku::Student::play() {
  cout << this->name << " is playing in TKU!" << endl;
}

void Tku::Student::study() {
  cout << this->name << " is studying hard in TKu!" << endl;
}

void Tku::Professor::teach() {
  cout << this->name << " is teaching in TKU!" << endl;
}

void Tku::Professor::research() {
  cout << this->name << " is doing research in TKU!" << endl;
}
