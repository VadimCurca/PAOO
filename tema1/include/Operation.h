#pragma once

#include <vector>
#include <iostream>
#include <typedef.h>
#include <string>

class Operation {
public:
  static int classInstncesCount;
  std::string name;

public:
  Operation() {
    std::cout << "Called Operation constructor\n";
    name = "default name no." + std::to_string(classInstncesCount);
    classInstncesCount++;
  }
  Operation(Operation const &) = default;
  Operation &operator=(Operation &&) = default;
  ~Operation() { std::cout << "Called Operation destructor\n"; }

  // This makes the Operation class pure virtual
  virtual std::vector<T> forward(std::vector<T>) = 0;
};
