#pragma once

#include <vector>
#include <Operation.h>
#include <typedef.h>
#include <memory>

class OperationList {
private:
  // Pointer of base class points to an object of a derived class.
  std::vector<std::shared_ptr<Operation>> list;

public:
  OperationList(std::initializer_list<std::shared_ptr<Operation>> list) { this->list = list; }

  std::vector<T> forward(std::vector<T> input);

  void push_back(std::shared_ptr<Operation> op) { list.push_back(op); }
};
