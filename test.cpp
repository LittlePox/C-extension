#include<iostream>
#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>
using namespace std;

namespace py = pybind11;

void foo(py::list& l) {}

int main() {
  cout << "Hello world!" << endl;
  return 0;
}
