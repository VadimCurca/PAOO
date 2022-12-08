#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <utils.h>
#include <Operation.h>
#include <OperationList.h>
#include <ops.h>
#include <typedef.h>
#include <FileManager.h>

void fileManagerExperiments() {
  FILE *f, *f2;

  FileManager fMng(&f, "test.txt", "r");

  if (f == NULL) {
    cout << "The file could not be opened";
    exit(1);
  }

  int num = 0;
  fscanf(f, "%d", &num);
  cout << "num = " << num << endl;

  // should generate a segmentation fault
  // fMng.~FileManager();
  // fscanf(f, "%d", &num);

  // should generate compile errors
  // FileManager fMng2(fMng);
}

int main() {
  OperationList net{
      getNormalizeOp(), getReLUOp(), getIncrementOp()
  };

  net.push_back(getNormalizeOp());

  vector<T> vec = getRandomVector(10);
  vector<T> out;

  out = net.forward(vec);

  printVector(vec);
  printVector(out);

  fileManagerExperiments();

  cout << "----------------------------------------\n";
  cout << "----------End of main function----------\n";
  cout << "----------------------------------------\n";
}
