/******************************************************************************
 * Copyright (C) 2015 Sahil Kang <sahil.kang@asilaycomputing.com>
 *
 * This file is part of gurpy.
 *
 * gurpy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * gurpy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with gurpy.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <Python.h>
#include <gur.hpp>
#include <sstream>

template<typename T>
PyObject* tuple_of_word(PyObject *args, T method)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	gur::Word word = (gur::Word(str).*method)();
	PyObject *py_word = PyTuple_New(word.size());

	for (std::size_t i = 0; i != word.size(); ++i)
	{
		PyTuple_SetItem(py_word, i, PyUnicode_FromString(
			word[i].str().c_str()));
	}

	return py_word;
}

static PyObject* gp_letters(PyObject *self, PyObject *args)
{
	return tuple_of_word(args, &gur::Word::letters);
}

static PyObject* gp_accents(PyObject *self, PyObject *args)
{
	return tuple_of_word(args, &gur::Word::accents);
}

static PyObject* gp_puncs(PyObject *self, PyObject *args)
{
	return tuple_of_word(args, &gur::Word::punctuations);
}

static PyObject* gp_digits(PyObject *self, PyObject *args)
{
	return tuple_of_word(args, &gur::Word::digits);
}

static PyObject* gp_symbols(PyObject *self, PyObject *args)
{
	return tuple_of_word(args, &gur::Word::symbols);
}

static PyObject* gp_comp(PyObject *self, PyObject *args)
{
	return tuple_of_word(args, &gur::Word::composition);
}

static PyObject* gp_clobber(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	gur::Word word(str);
	std::ostringstream oss;
	oss << word;

	return PyUnicode_FromString(oss.str().c_str());
}

static PyObject* gp_unclobber(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	gur::Word word(str);
	std::ostringstream oss(std::ostringstream::ate);

	for (auto &c : word)
	{
		oss << c;
	}

	return PyUnicode_FromString(oss.str().c_str());
}

static PyMethodDef gp_methods[] =
{
	{"letters", gp_letters, METH_VARARGS, "Get the letters in a word."},
	{"accents", gp_accents, METH_VARARGS, "Get the accents in a word."},
	{"puncs", gp_puncs, METH_VARARGS, "Get the punctuations in a word."},
	{"digits", gp_digits, METH_VARARGS, "Get the digits in a word."},
	{"symbols", gp_symbols, METH_VARARGS, "Get the symbols in a word."},
	{"comp", gp_comp, METH_VARARGS, "Get a word's composition."},
	{"clobber", gp_clobber, METH_VARARGS, "Combine diacritics."},
	{"unclobber", gp_unclobber, METH_VARARGS, "Separate diacritics."},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef gp_module =
{	
	PyModuleDef_HEAD_INIT,
	"gurpy", //name of the module
	"Python extension for libgur", //module doc
	-1,
	gp_methods
};

PyMODINIT_FUNC PyInit_gurpy(void)
{
	return PyModule_Create(&gp_module);
}
