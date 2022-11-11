#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

typedef int T;
class Operation {
public:
  Operation() { cout << "Called Operation constructor\n"; }
  Operation(Operation const &) = default;
  Operation &operator=(Operation &&) = default;
  ~Operation() { cout << "Called Operation destructor\n"; }

  // This makes the Operation class pure virtual
  virtual std::vector<T> forward(std::vector<T>) = 0;
};

class OperationList {
private:
  // Pointer of base class points to an object of a derived class.
  vector<Operation *> list;

public:
  OperationList(initializer_list<Operation *> list) { this->list = list; }

  vector<T> forward(vector<T> input) {
    vector<T> x = input;
    for (auto &it : list)
      x = it->forward(x);
    return x;
  }

  void push_back(Operation *op) { list.push_back(op); }
};

class Increment : public Operation {
private:
  T incrementVal;

public:
  // Constructor
  Increment(T val = 1) {
    cout << "Called Increment constructor\n";
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

    this->incrementVal = other.incrementVal;
    return *this;
  }

  // Destructor
  ~Increment() { cout << "Called Increment destructor\n"; }

  std::vector<T> forward(std::vector<T> input) override {
    cout << "Called Increment forward function\n";

    std::vector<T> output(input.size());
    for (int i = 0; i < input.size(); i++) {
      output[i] = input[i] + this->incrementVal;
    }

    return output;
  }
};

class ReLU : public Operation {
public:
  ReLU() { cout << "Called ReLU constructor\n"; }
  ReLU(ReLU const &) = delete;
  ReLU &operator=(ReLU &&) = delete;
  ~ReLU() = default;

  std::vector<T> forward(std::vector<T> input) override {
    cout << "Called ReLU forward function\n";

    std::vector<T> output(input.size());
    for (int i = 0; i < input.size(); i++) {
      output[i] = input[i] > 0 ? input[i] : 0;
    }
    return output;
  }
};

class Normalize : public Operation {
public:
  Normalize() { cout << "Called Normalize constructor\n"; }
  Normalize(ReLU const &) = delete;
  Normalize &operator=(Normalize &&) = delete;
  ~Normalize() = default;

  std::vector<T> forward(std::vector<T> input) override {
    long long sum = 0;
    for (auto it : input)
      sum += it;

    int med = sum / input.size();

    std::vector<T> out(input.size());
    for (int i = 0; i < input.size(); i++)
      out[i] = input[i] - med;

    return out;
  }
};

vector<T> getRandomVector(int size = 0) {
  std::srand(unsigned(std::time(nullptr)));
  std::vector<T> v(size);
  std::generate(v.begin(), v.end(), std::rand);

  return v;
}

void printVector(vector<T> &vec) {
  for (auto it : vec) {
    cout << it << ' ';
  }
  cout << "\n";
}

int main() {
  OperationList net{
      new Normalize(), new ReLU(), new Increment(),
      new Normalize(), new ReLU(), new Increment(42),
  };

  net.push_back(new Increment(1));

  vector<T> vec = getRandomVector(10);
  vector<T> out;

  out = net.forward(vec);

  printVector(vec);
  printVector(out);

  Increment a(5);

  Increment b(a);
  Increment c;
  c = a;
}
