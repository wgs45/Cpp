#include <algorithm> // For std::find
#include <iostream>
#include <vector>

class MyString {
public:
  // Function to get reported groups (intersection of inputGroups and
  // reportedGroups)
  static std::vector<int>
  getReportedGroups(const std::vector<int> &inputGroups,
                    const std::vector<int> &reportedGroups) {
    std::vector<int> result;

    // Iterate through each group in reportedGroups
    for (int group : reportedGroups) {
      // Check if the group exists in inputGroups
      if (std::find(inputGroups.begin(), inputGroups.end(), group) !=
          inputGroups.end()) {
        result.push_back(group); // Add to result if found
      }
    }

    return result;
  }

  // Function to get unreported groups (elements in allGroups not in
  // reportedGroups)
  static std::vector<int>
  getUnreportedGroups(const std::vector<int> &allGroups,
                      const std::vector<int> &reportedGroups) {
    std::vector<int> result;

    // Iterate through each group in allGroups
    for (int group : allGroups) {
      // Check if the group is NOT in reportedGroups
      if (std::find(reportedGroups.begin(), reportedGroups.end(), group) ==
          reportedGroups.end()) {
        result.push_back(group); // Add to result if not found
      }
    }

    return result;
  }
};

int main() {
  // Define the groups
  std::vector<int> inputGroups = {1, 2, 4, 5, 9, 11};
  std::vector<int> allGroups = {1, 2,  3,  4,  5,  6,  7,  8,
                                9, 10, 11, 12, 13, 14, 15, 16};

  // Get reported groups (intersection of inputGroups and allGroups)
  std::vector<int> reportedGroups =
      MyString::getReportedGroups(inputGroups, allGroups);
  std::cout << "Reported groups: ";

  // Output reported groups
  for (int group : reportedGroups) {
    std::cout << group << " ";
  }
  std::cout << std::endl;

  // Get unreported groups (elements in allGroups not in inputGroups)
  std::vector<int> unreportedGroups =
      MyString::getUnreportedGroups(allGroups, inputGroups);
  std::cout << "Unreported groups: ";

  // Output unreported groups
  for (int group : unreportedGroups) {
    std::cout << group << " ";
  }
  std::cout << std::endl;

  return 0;
}
