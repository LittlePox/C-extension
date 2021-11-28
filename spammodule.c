#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *SpamError;

PyMODINIT_FUNC PyInit_spam(void) {
    PyObject *m = PyModule_Create(&spammodule);
    if (m == NULL) {
        return NULL;
    }

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_XINCERF(SpamError);
    if (PyModule_AddObject(m, "error", SpamError) < 0) {
        Py_XDECERF(SpamError);
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}

static PyObject *spam_system(PyObject *self, PyObject *args) {
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command)) {
        return NULL;
    }

    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}
