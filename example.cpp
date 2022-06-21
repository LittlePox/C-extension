#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "bar_data.h"

#include <numeric>
#include <functional>

using namespace pybind11::literals;
namespace py = pybind11;

#define _def(func) m.def(#func, &func, #func)

using namespace std;

vector<vector<double>> storage;

int add_int(int a, int b) {
    return a + b;
}

double add_double(double a, double b) {
    return a + b;
}

bool and_bool(bool a, bool b) {
    return a && b;
}

int64_t add_int64_t(int64_t a, int64_t b) {
    return a + b;
}

string test_string(const string &a) {
    return a + a;
}

string test_const_char(const char * a) {
    return test_string(string(a));
}

double sum(const py::list &a) {
    double res = 0;
    for (auto &i : a) {
        res += i.cast<double>();
    }
    cout << a.size() << endl;
    return res;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    storage.reserve(16);

    m.def("add_int", &add_int, "add_int");
    m.def("add_double", &add_double, "add_double");
    _def(and_bool);
    _def(add_int64_t);
    _def(test_string);
    _def(test_const_char);
    _def(sum);

    py::class_<BarData>(m, "BarData")
    .def(py::init<>())
    .def_readonly("size", &BarData::size)
    .def("set_size", &BarData::set_size, "size"_a);
}