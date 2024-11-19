#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<char> st;

  st.push('a');
  st.push('b');
  st.push('c');

  stack<char> t = st;
  while (!t.empty()) {
    cout << t.top() << " ";
    t.pop();
  }

  return 0;
}
