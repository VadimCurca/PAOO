#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <utils.h>
#include <Operation.h>
#include <OperationList.h>
#include <ops.h>
#include <typedef.h>

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

  cout << "c name - " << c.name << "\n";
  cout << "a name - " << a.name << "\n";
}
