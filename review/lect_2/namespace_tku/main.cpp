#include "tku.h"
#include "uq.h"
#include <iostream>

using namespace Tku;
using namespace Uq;
using namespace std;

int main() {
  Tku::Student s1;

  s1.age = 20;
  s1.name = "Betty";
  s1.play();
  s1.study();

  return 0;
}
