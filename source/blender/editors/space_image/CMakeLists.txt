# SPDX-FileCopyrightText: 2023 Blender Authors
#
# SPDX-License-Identifier: GPL-2.0-or-later

set(INC
  ../asset
  ../include
  ../../makesrna

  # RNA_prototypes.hh
  ${CMAKE_BINARY_DIR}/source/blender/makesrna
)

set(INC_SYS
)

set(SRC
  image_buttons.cc
  image_draw.cc
  image_edit.cc
  image_ops.cc
  image_sequence.cc
  image_undo.cc
  space_image.cc

  image_intern.hh
)

set(LIB
  PRIVATE bf::blenfont
  PRIVATE bf::blenkernel
  PRIVATE bf::blenlib
  PRIVATE bf::blenloader
  PRIVATE bf::blentranslation
  PRIVATE bf::bmesh
  PRIVATE bf::depsgraph
  PRIVATE bf::dna
  PRIVATE bf::draw
  bf_editor_uvedit
  PRIVATE bf::gpu
  PRIVATE bf::imbuf
  PRIVATE bf::imbuf::movie
  PRIVATE bf::intern::clog
  PRIVATE bf::intern::guardedalloc
  PRIVATE bf::nodes
  PRIVATE bf::render
  PRIVATE bf::windowmanager
)

if(WITH_IMAGE_OPENJPEG)
  add_definitions(-DWITH_IMAGE_OPENJPEG)
endif()

if(WITH_IMAGE_OPENEXR)
  add_definitions(-DWITH_IMAGE_OPENEXR)
endif()

if(WITH_IMAGE_CINEON)
  add_definitions(-DWITH_IMAGE_CINEON)
endif()

if(WITH_IMAGE_WEBP)
  add_definitions(-DWITH_IMAGE_WEBP)
endif()


blender_add_lib(bf_editor_space_image "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")

# RNA_prototypes.hh dna_type_offsets.h
add_dependencies(bf_editor_space_image bf_rna)
