#include <pybind11/pybind11.h>

#define _def(func) m.def(#func, &func, #func)

using namespace std;

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

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add_int", &add_int, "add_int");
    m.def("add_double", &add_double, "add_double");
    _def(and_bool);
    _def(add_int64_t);
    _def(test_string);
    _def(test_const_char);

}