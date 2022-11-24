#include <ctime>
#include <vector>
#include <utils.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <typedef.h>

std::vector<T> getRandomVector(int size) {
  std::srand(unsigned(std::time(nullptr)));
  std::vector<T> v(size);
  std::generate(v.begin(), v.end(), std::rand);

  return v;
}

void printVector(std::vector<T> &vec) {
  for (auto it : vec) {
    std::cout << it << ' ';
  }
  std::cout << "\n";
}
