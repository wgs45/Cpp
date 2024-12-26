#include <iostream>
#include <vector>

class MyString {
public:
  static std::vector<int>
  getReportedGroups(const std::vector<int> &inputGroups,
                    const std::vector<int> &reportedGroups) {
    std::vector<int> result;

    for (int group : reportedGroups) {
      if (std::find(inputGroups.begin(), inputGroups.end(), group) !=
          inputGroups.end()) {
        result.push_back(group);
      }
    }
    return result;
  }

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
  std::vector<int> inputGroups = {1, 2, 4, 5, 9, 11};
  std::vector<int> allGroups = {1, 2,  3,  4,  5,  6,  7,  8,
                                9, 10, 11, 12, 13, 14, 15, 16};

  std::vector<int> reportedGroups =
      MyString::getReportedGroups(inputGroups, allGroups);
  std::cout << "Reported groups: ";

  for (int group : reportedGroups) {
    std::cout << group << " ";
  }
  std::cout << std::endl;

  std::vector<int> unreportedGroups =
      MyString::getReportedGroups(allGroups, inputGroups);
  std::cout << "Unreported groups: ";
  for (int group : unreportedGroups) {
    std::cout << group << " ";
  }
  std::cout << std::endl;

  return 0;
}
