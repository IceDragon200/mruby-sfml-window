#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/WindowStyle.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_mouse.hxx"

static struct RClass *window_style_module;

extern "C" void
mrb_sfml_window_style_init_bind(mrb_state *mrb, struct RClass *mod)
{
  window_style_module = mrb_define_module_under(mrb, mod, "Style");
}
