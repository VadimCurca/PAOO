#pragma once

#include <Operation.h>
#include <iostream>
#include <typedef.h>
#include <vector>
#include <memory>

using namespace std;

class Increment : public Operation {
private:
  T incrementVal;

public:
  // Constructor
  Increment(T val = 1) {
    cout << "Called Increment constructor - " + name + "\n";
    this->incrementVal = val;
  }

  // Copy constructor
  Increment(Increment const &other) {
    cout << "Called Increment copy constructor\n";
    this->incrementVal = other.incrementVal;
  }

  // Move constructor
  Increment &operator=(const Increment &other) {
    cout << "Called Increment move constructor\n";

    if (this == &other)
      return *this;

    this->name = other.name;
    this->incrementVal = other.incrementVal;
    return *this;
  }

  // Destructor
  ~Increment() { cout << "Called Increment destructor - " + name + "\n"; }

  std::vector<T> forward(std::vector<T> input) override;
};

class ReLU : public Operation {
public:
  ReLU() { cout << "Called ReLU constructor - " + name + "\n"; }
  ReLU(ReLU const &) = delete;
  ReLU &operator=(ReLU &&) = delete;
  // Destructor
  ~ReLU() { cout << "Called ReLU destructor - " + name + "\n"; }

  std::vector<T> forward(std::vector<T> input) override;
};

class Normalize : public Operation {
public:
  Normalize() { cout << "Called Normalize constructor - " + name + "\n"; }
  Normalize(ReLU const &) = delete;
  Normalize &operator=(Normalize &&) = delete;
  ~Normalize() { cout << "Called Normalize destructor - " + name + "\n"; }

  std::vector<T> forward(std::vector<T> input) override;
};

std::shared_ptr<Operation> getIncrementOp(T val = 1);
std::shared_ptr<Operation> getReLUOp();
std::shared_ptr<Operation> getNormalizeOp();
