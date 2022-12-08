#include <Operation.h>
#include <OperationList.h>
#include <vector>
#include <typedef.h>

std::vector<T> OperationList::forward(std::vector<T> input) {
  std::vector<T> x = input;
  for (auto it : list)
    x = it->forward(x);
  return x;
}
