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
#include <gurmukhi.hpp>

static PyObject* gp_letters(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::letters(str));
}

static PyObject* gp_accents(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::accents(str));
}

static PyObject* gp_puncs(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::puncs(str));
}

static PyObject* gp_digits(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::digits(str));
}

static PyObject* gp_symbols(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::symbols(str));
}

static PyObject* gp_comp(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::comp(str));
}

static PyObject* gp_clobber(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::clobber(str));
}

static PyObject* gp_unclobber(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	return PyUnicode_FromString(gur::unclobber(str));
}

static PyObject* gp_is_letter(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	if (gur::is_letter(str))
	{
		Py_RETURN_TRUE;
	}

	else
	{
		Py_RETURN_FALSE;
	}
}

static PyObject* gp_is_accent(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	if (gur::is_accent(str))
	{
		Py_RETURN_TRUE;
	}

	else
	{
		Py_RETURN_FALSE;
	}
}

static PyObject* gp_is_punc(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	if (gur::is_punc(str))
	{
		Py_RETURN_TRUE;
	}

	else
	{
		Py_RETURN_FALSE;
	}
}

static PyObject* gp_is_digit(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	if (gur::is_digit(str))
	{
		Py_RETURN_TRUE;
	}

	else
	{
		Py_RETURN_FALSE;
	}
}

static PyObject* gp_is_symbol(PyObject *self, PyObject *args)
{
	const char* str;
	if (!PyArg_ParseTuple(args, "s", &str))
	{
		return NULL;
	}

	if (gur::is_symbol(str))
	{
		Py_RETURN_TRUE;
	}

	else
	{
		Py_RETURN_FALSE;
	}
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
	{"is_letter", gp_is_letter, METH_VARARGS, "Is string a letter?"},
	{"is_accent", gp_is_accent, METH_VARARGS, "Is string a accent?"},
	{"is_punc", gp_is_punc, METH_VARARGS, "Is string a punctuation?"},
	{"is_digit", gp_is_digit, METH_VARARGS, "Is string a digit?"},
	{"is_symbol", gp_is_symbol, METH_VARARGS, "Is string a symbol?"},
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
	PyObject *mod = PyModule_Create(&gp_module);

	PyObject_SetAttrString(mod, "a1", PyUnicode_FromString(gur::A1));
	PyObject_SetAttrString(mod, "a2", PyUnicode_FromString(gur::A2));
	PyObject_SetAttrString(mod, "a3", PyUnicode_FromString(gur::A3));
	PyObject_SetAttrString(mod, "a4", PyUnicode_FromString(gur::A4));
	PyObject_SetAttrString(mod, "a5", PyUnicode_FromString(gur::A5));

	PyObject_SetAttrString(mod, "b1", PyUnicode_FromString(gur::B1));
	PyObject_SetAttrString(mod, "b2", PyUnicode_FromString(gur::B2));
	PyObject_SetAttrString(mod, "b3", PyUnicode_FromString(gur::B3));
	PyObject_SetAttrString(mod, "b4", PyUnicode_FromString(gur::B4));
	PyObject_SetAttrString(mod, "b5", PyUnicode_FromString(gur::B5));

	PyObject_SetAttrString(mod, "c1", PyUnicode_FromString(gur::C1));
	PyObject_SetAttrString(mod, "c2", PyUnicode_FromString(gur::C2));
	PyObject_SetAttrString(mod, "c3", PyUnicode_FromString(gur::C3));
	PyObject_SetAttrString(mod, "c4", PyUnicode_FromString(gur::C4));
	PyObject_SetAttrString(mod, "c5", PyUnicode_FromString(gur::C5));

	PyObject_SetAttrString(mod, "d1", PyUnicode_FromString(gur::D1));
	PyObject_SetAttrString(mod, "d2", PyUnicode_FromString(gur::D2));
	PyObject_SetAttrString(mod, "d3", PyUnicode_FromString(gur::D3));
	PyObject_SetAttrString(mod, "d4", PyUnicode_FromString(gur::D4));
	PyObject_SetAttrString(mod, "d5", PyUnicode_FromString(gur::D5));

	PyObject_SetAttrString(mod, "e1", PyUnicode_FromString(gur::E1));
	PyObject_SetAttrString(mod, "e2", PyUnicode_FromString(gur::E2));
	PyObject_SetAttrString(mod, "e3", PyUnicode_FromString(gur::E3));
	PyObject_SetAttrString(mod, "e4", PyUnicode_FromString(gur::E4));
	PyObject_SetAttrString(mod, "e5", PyUnicode_FromString(gur::E5));

	PyObject_SetAttrString(mod, "f1", PyUnicode_FromString(gur::F1));
	PyObject_SetAttrString(mod, "f2", PyUnicode_FromString(gur::F2));
	PyObject_SetAttrString(mod, "f3", PyUnicode_FromString(gur::F3));
	PyObject_SetAttrString(mod, "f4", PyUnicode_FromString(gur::F4));
	PyObject_SetAttrString(mod, "f5", PyUnicode_FromString(gur::F5));

	PyObject_SetAttrString(mod, "g1", PyUnicode_FromString(gur::G1));
	PyObject_SetAttrString(mod, "g2", PyUnicode_FromString(gur::G2));
	PyObject_SetAttrString(mod, "g3", PyUnicode_FromString(gur::G3));
	PyObject_SetAttrString(mod, "g4", PyUnicode_FromString(gur::G4));
	PyObject_SetAttrString(mod, "g5", PyUnicode_FromString(gur::G5));

	PyObject_SetAttrString(mod, "h1", PyUnicode_FromString(gur::H1));
	PyObject_SetAttrString(mod, "h2", PyUnicode_FromString(gur::H2));
	PyObject_SetAttrString(mod, "h3", PyUnicode_FromString(gur::H3));
	PyObject_SetAttrString(mod, "h4", PyUnicode_FromString(gur::H4));
	PyObject_SetAttrString(mod, "h5", PyUnicode_FromString(gur::H5));

	PyObject_SetAttrString(mod, "i1", PyUnicode_FromString(gur::I1));
	PyObject_SetAttrString(mod, "i2", PyUnicode_FromString(gur::I2));
	PyObject_SetAttrString(mod, "i3", PyUnicode_FromString(gur::I3));
	PyObject_SetAttrString(mod, "i4", PyUnicode_FromString(gur::I4));
	PyObject_SetAttrString(mod, "i5", PyUnicode_FromString(gur::I5));

	PyObject_SetAttrString(mod, "j1", PyUnicode_FromString(gur::J1));
	PyObject_SetAttrString(mod, "j2", PyUnicode_FromString(gur::J2));
	PyObject_SetAttrString(mod, "j3", PyUnicode_FromString(gur::J3));
	PyObject_SetAttrString(mod, "j4", PyUnicode_FromString(gur::J4));
	PyObject_SetAttrString(mod, "j5", PyUnicode_FromString(gur::J5));

	PyObject_SetAttrString(mod, "k1", PyUnicode_FromString(gur::K1));
	PyObject_SetAttrString(mod, "k2", PyUnicode_FromString(gur::K2));
	PyObject_SetAttrString(mod, "k3", PyUnicode_FromString(gur::K3));
	PyObject_SetAttrString(mod, "k4", PyUnicode_FromString(gur::K4));
	PyObject_SetAttrString(mod, "k5", PyUnicode_FromString(gur::K5));

	PyObject_SetAttrString(mod, "l1", PyUnicode_FromString(gur::L1));
	PyObject_SetAttrString(mod, "l2", PyUnicode_FromString(gur::L2));
	PyObject_SetAttrString(mod, "l3", PyUnicode_FromString(gur::L3));
	PyObject_SetAttrString(mod, "l4", PyUnicode_FromString(gur::L4));
	PyObject_SetAttrString(mod, "l5", PyUnicode_FromString(gur::L5));

	PyObject_SetAttrString(mod, "m1", PyUnicode_FromString(gur::M1));
	PyObject_SetAttrString(mod, "m2", PyUnicode_FromString(gur::M2));
	PyObject_SetAttrString(mod, "m3", PyUnicode_FromString(gur::M3));
	PyObject_SetAttrString(mod, "m4", PyUnicode_FromString(gur::M4));
	PyObject_SetAttrString(mod, "m5", PyUnicode_FromString(gur::M5));

	PyObject_SetAttrString(mod, "n1", PyUnicode_FromString(gur::N1));
	PyObject_SetAttrString(mod, "n2", PyUnicode_FromString(gur::N2));
	PyObject_SetAttrString(mod, "n3", PyUnicode_FromString(gur::N3));
	PyObject_SetAttrString(mod, "n4", PyUnicode_FromString(gur::N4));
	PyObject_SetAttrString(mod, "n5", PyUnicode_FromString(gur::N5));

	PyObject_SetAttrString(mod, "o1", PyUnicode_FromString(gur::O1));
	PyObject_SetAttrString(mod, "o2", PyUnicode_FromString(gur::O2));
	PyObject_SetAttrString(mod, "o3", PyUnicode_FromString(gur::O3));
	PyObject_SetAttrString(mod, "o4", PyUnicode_FromString(gur::O4));
	PyObject_SetAttrString(mod, "o5", PyUnicode_FromString(gur::O5));

	PyObject_SetAttrString(mod, "p1", PyUnicode_FromString(gur::P1));
	PyObject_SetAttrString(mod, "p2", PyUnicode_FromString(gur::P2));
	PyObject_SetAttrString(mod, "p3", PyUnicode_FromString(gur::P3));
	PyObject_SetAttrString(mod, "p4", PyUnicode_FromString(gur::P4));
	PyObject_SetAttrString(mod, "p5", PyUnicode_FromString(gur::P5));

	PyObject_SetAttrString(mod, "q1", PyUnicode_FromString(gur::Q1));
	PyObject_SetAttrString(mod, "q2", PyUnicode_FromString(gur::Q2));

	return mod;
}
