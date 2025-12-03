#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {

    // initial faces
    int top = 1, bottom = 6;
    int north = 2, south = 5;
    int east = 4, west = 3;

    while (n--) {
      string cmd;
      cin >> cmd;

      if (cmd == "north") {
        int temp = top;
        top = south;
        south = bottom;
        bottom = north;
        north = temp;
      } else if (cmd == "south") {
        int temp = top;
        top = north;
        north = bottom;
        bottom = south;
        south = temp;
      } else if (cmd == "east") {
        int temp = top;
        top = west;
        west = bottom;
        bottom = east;
        east = temp;
      } else if (cmd == "west") {
        int temp = top;
        top = east;
        east = bottom;
        bottom = west;
        west = temp;
      }
    }

    cout << top << "\n";
  }
}
