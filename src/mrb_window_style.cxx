#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/WindowStyle.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_mouse.hxx"

MRB_SFML_EXTERN void
mrb_sfml_window_style_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *window_style_module = mrb_define_module_under(mrb, mod, "Style");

  mrb_define_const(mrb, window_style_module, "None",       mrb_fixnum_value(sf::Style::None));
  mrb_define_const(mrb, window_style_module, "Titlebar",   mrb_fixnum_value(sf::Style::Titlebar));
  mrb_define_const(mrb, window_style_module, "Resize",     mrb_fixnum_value(sf::Style::Resize));
  mrb_define_const(mrb, window_style_module, "Close",      mrb_fixnum_value(sf::Style::Close));
  mrb_define_const(mrb, window_style_module, "Fullscreen", mrb_fixnum_value(sf::Style::Fullscreen));
  mrb_define_const(mrb, window_style_module, "Default",    mrb_fixnum_value(sf::Style::Default));
}
