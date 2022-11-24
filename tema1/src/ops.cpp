#include <Operation.h>
#include <iostream>
#include <ops.h>
#include <typedef.h>
#include <vector>

std::vector<T> Increment::forward(std::vector<T> input) {
  std::cout << "Called Increment forward function\n";

  std::vector<T> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = input[i] + this->incrementVal;
  }

  return output;
}

std::vector<T> ReLU::forward(std::vector<T> input) {
  std::cout << "Called ReLU forward function\n";

  std::vector<T> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = input[i] > 0 ? input[i] : 0;
  }
  return output;
}

std::vector<T> Normalize::forward(std::vector<T> input) {
  long long sum = 0;
  for (auto it : input)
    sum += it;

  int med = sum / input.size();

  std::vector<T> out(input.size());
  for (int i = 0; i < input.size(); i++)
    out[i] = input[i] - med;

  return out;
}
