#pragma once

#include <vector>
#include <Operation.h>
#include <typedef.h>

class OperationList {
private:
  // Pointer of base class points to an object of a derived class.
  std::vector<Operation*> list;

public:
  OperationList(std::initializer_list<Operation*> list) { this->list = list; }

  std::vector<T> forward(std::vector<T> input);

  void push_back(Operation *op) { list.push_back(op); }
};
