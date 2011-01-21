// ASE gui library
// Copyright (C) 2001-2011  David Capello
//
// This source file is ditributed under a BSD-like license, please
// read LICENSE.txt for more information.

#include "config.h"

#include "gui/jbase.h"
#include "gui/jclipboard.h"
#include "gui/theme.h"

#ifdef MEMLEAK
void _jmemleak_init();
void _jmemleak_exit();
#endif

int _ji_widgets_init();
void _ji_widgets_exit();

int _ji_system_init();
void _ji_system_exit();

int _ji_font_init();
void _ji_font_exit();

/**
 * Initializes the Jinete library.
 */
Jinete::Jinete()
{
#ifdef MEMLEAK
  _jmemleak_init();
#endif

  // initialize system
  _ji_system_init();
  _ji_font_init();
  _ji_widgets_init();
}

Jinete::~Jinete()
{
  // finish theme
  CurrentTheme::set(NULL);

  // destroy clipboard
  jclipboard_set_text(NULL);

  // shutdown system
  _ji_widgets_exit();
  _ji_font_exit();
  _ji_system_exit();

#ifdef MEMLEAK
  _jmemleak_exit();
#endif
}

