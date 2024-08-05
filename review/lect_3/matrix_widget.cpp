#include <iostream>

class Matrix_widget {
private:
  int mat[3][3];

public:
  Matrix_widget() {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        mat[i][j] = 0; // Initialize matrix with zeros
  }

  Matrix_widget(int v) {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        mat[i][j] = v; // Initialize matrix with the value v
  }

  void modify(int i, int j, int value) {
    if (i >= 0 && i < 3 && j >= 0 && j < 3) {
      mat[i][j] = value;
    } else {
      std::cerr << "Index out of bounds" << std::endl;
    }
  }

  void showMatrix() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        std::cout << mat[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  ~Matrix_widget() { std::cout << "obj deleted" << std::endl; }
};

int main() {
  Matrix_widget obj, obj2(1);
  obj.showMatrix();
  std::cout << std::endl;
  obj2.showMatrix();
  std::cout << std::endl;
  obj.modify(2, 1, 7);
  obj.showMatrix();
  std::cout << std::endl;

  Matrix_widget obj3(obj); // Copy constructor
  obj3.showMatrix();

  return 0;
}
