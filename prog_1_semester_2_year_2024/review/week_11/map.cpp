#include <iostream>
#include <map>
#include <typeinfo> // Required for typeid
using namespace std;

void show(map<int, float> &m) {
  // Iterator to traverse the map
  map<int, float>::iterator it = m.begin();

  // Iterate through all key-value pairs in the map
  while (it != m.end()) {
    // Print the type of the key and value using typeid
    cout << typeid(it->first).name() << ", " << typeid(it->second).name()
         << endl;
    it++; // Move to the next element
  }
}

int main() {
  // Declare a map where keys are integers and values are floats
  map<int, float> mp;

  // Insert key-value pairs into the map
  mp.insert({9, 90}); // Adds key 9 with value 90
  mp.insert({2, 85}); // Adds key 2 with value 85
  mp.insert({7, 99}); // Adds key 7 with value 99

  // Remove the key-value pair with key 2
  mp.erase(2);

  // Access and print the value associated with key 9
  // Using `mp[9]` fetches the value for key 9 (90 in this case)
  cout << mp[9] << endl;

  // Call the `show` function to display the types of the keys and values
  show(mp);

  // Output:
  // 90         // Value associated with key 9
  // i, f       // 'i' for integer (key type), 'f' for float (value type)
  // i, f

  return 0;
}
