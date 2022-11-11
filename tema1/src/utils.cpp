#include <ctime>
#include <vector>
#include <utils.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>

typedef int Type;

std::vector<Type> getRandomVector(int size) {
  std::srand(unsigned(std::time(nullptr)));
  std::vector<Type> v(size);
  std::generate(v.begin(), v.end(), std::rand);

  return v;
}

void printVector(std::vector<Type> &vec) {
  for (auto it : vec) {
    std::cout << it << ' ';
  }
  std::cout << "\n";
}
