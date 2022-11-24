#pragma once

#include <vector>
#include <iostream>
#include <typedef.h>

class Operation {
public:
  Operation() { std::cout << "Called Operation constructor\n"; }
  Operation(Operation const &) = default;
  Operation &operator=(Operation &&) = default;
  ~Operation() { std::cout << "Called Operation destructor\n"; }

  // This makes the Operation class pure virtual
  virtual std::vector<T> forward(std::vector<T>) = 0;
};
