#include <iostream>
#include <vector>

class MyString {
public:
  // Method to report groups
  static std::vector<int>
  getReportedGroups(const std::vector<int> &inputGroups,
                    const std::vector<int> &reportedGroups) {
    std::vector<int> result;
    for (int group : reportedGroups) {
      // find(start, end, value)
      if (std::find(inputGroups.begin(), inputGroups.end(), group) !=
          inputGroups.end()) {
        result.push_back(group);
      }
    }
    return result;
  }

  // Method to get unreported groups
  static std::vector<int>
  getUnreportedGroups(const std::vector<int> &allGroups,
                      const std::vector<int> &reportedGroups) {
    std::vector<int> result;
    for (int group : allGroups) {
      if (std::find(reportedGroups.begin(), reportedGroups.end(), group) ==
          reportedGroups.end()) {
        result.push_back(group);
      }
    }
    return result;
  }
};

int main() {
  // Input groups
  std::vector<int> inputGroups = {1, 2, 4, 5, 9, 11};
  std::vector<int> allGroups = {1, 2,  3,  4,  5,  6,  7,  8,
                                9, 10, 11, 12, 13, 14, 15, 16};

  // Reported groups
  std::vector<int> reportedGroups =
      MyString::getReportedGroups(inputGroups, allGroups);
  std::cout << "Reported groups: ";
  for (int group : reportedGroups) {
    std::cout << group << " ";
  }
  std::cout << std::endl;

  // Unreported groups
  std::vector<int> unreportedGroups =
      MyString::getUnreportedGroups(allGroups, inputGroups);
  std::cout << "Unreported groups: ";
  for (int group : unreportedGroups) {
    std::cout << group << " ";
  }
  std::cout << std::endl;

  return 0;
}
