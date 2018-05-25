#include <D:/Qt/Qt5.5.1/Tools/mingw492_32/opt/include/python2.7/Python.h> //默认包含目录为D:\Qt\Qt5.5.1\Tools\mingw492_32\i686-w64-mingw32\include

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return Py_BuildValue("i", sts);
}
