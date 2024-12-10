#include <iostream>
#include <map>
using namespace std;

int main() {
  // Declare a map with int keys and double values
  map<int, double> dataMap;
  int key, i;
  double value;

  cout << "Enter 3 sets of data (key int, value double): " << endl;
  for (i = 0; i < 3; i++) {
    cout << "Set " << i + 1 << ": ";
    cin >> key >> value;
    dataMap[key] = value;
  }

  // Display current map
  cout << "Initial map contents: " << endl;
  for (const auto& pair : dataMap) {
    cout << "Key: " << pair.first << ", value: " << pair.second << endl;
  }

  // Delete key
  cout << "Enter an integer key to delete: ";
  cin >> key;

  // Check if key is exist
  if (dataMap.find(key) != dataMap.end()) {
    dataMap.erase(key);
    cout << "Key " << key << " deleted." << endl;
  } else {
    cout << "Key " << key << " is not found." << endl;
  }

  // Display the updated map
  cout << "\nUpdated map contents: " << endl;
  for (const auto& pair : dataMap) {
    cout << "Key: " << pair.first << ", value: " << pair.second << endl;
  }

  return 0;
}