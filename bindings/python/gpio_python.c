#include <Python.h>

#include "libsoc_gpio.h"

static PyObject *
gpio_fd(PyObject *self, PyObject *args)
{
  unsigned long gpio_addr;
  int fd;

  if (PyArg_ParseTuple(args, "k", &gpio_addr))
    {
      return Py_BuildValue("i", ((gpio*)gpio_addr)->value_fd);
    }
  return NULL;
}

static PyMethodDef functions[] = {
    {"gpio_fd", gpio_fd, METH_VARARGS,
     "Runs the OS level file descriptor in the struct gpio"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
init_libsoc(void)
{
  PyObject *m;
  m = Py_InitModule ("_libsoc", functions);

  PyModule_AddIntConstant(m, "DIRECTION_ERROR", DIRECTION_ERROR);
  PyModule_AddIntConstant(m, "DIRECTION_INPUT", INPUT);
  PyModule_AddIntConstant(m, "DIRECTION_OUTPUT", OUTPUT);

  PyModule_AddIntConstant(m, "LEVEL_ERROR", LEVEL_ERROR);
  PyModule_AddIntConstant(m, "LEVEL_LOW", LOW);
  PyModule_AddIntConstant(m, "LEVEL_HIGH", HIGH);

  PyModule_AddIntConstant(m, "EDGE_ERROR", EDGE_ERROR);
  PyModule_AddIntConstant(m, "EDGE_RISING", RISING);
  PyModule_AddIntConstant(m, "EDGE_FALLING", FALLING);
  PyModule_AddIntConstant(m, "EDGE_NONE", NONE);
  PyModule_AddIntConstant(m, "EDGE_BOTH", BOTH);

  PyModule_AddIntConstant(m, "LS_SHARED", LS_SHARED);
  PyModule_AddIntConstant(m, "LS_GREEDY", LS_GREEDY);
  PyModule_AddIntConstant(m, "LS_WEAK", LS_WEAK);
}
