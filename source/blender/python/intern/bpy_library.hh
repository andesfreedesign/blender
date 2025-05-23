/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup pythonintern
 */

#pragma once

#include <Python.h>

int BPY_library_load_type_ready();

extern PyMethodDef BPY_library_load_method_def;
extern PyMethodDef BPY_library_write_method_def;
