// onlinejudge uva 10931
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  long long int num, parity;
  string str;

  while(cin >> num) {
    if (num == 0) break;

    str = "";
    while (num > 0) {
      cout << "1 num: " << num << endl;
      cout << "2 str: " << str << endl; 
      str += to_string(num % 2);
      cout << "3 str: " << str << endl;
      cout << "4 num: " << num << endl;
      num /= 2;
      cout << "5 num: " << num << endl;
      cout << "6 str: " << str << endl;
    }
    parity = count(str.begin(), str.end(), '1');
    cout << "7 parity: " << parity << endl;
    reverse(str.begin(), str.end());

    cout << "The parity of " << str << " is " << parity << " (mod 2)." << endl;
  }
  
  return 0;
}