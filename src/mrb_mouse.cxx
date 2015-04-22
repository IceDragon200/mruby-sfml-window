#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Mouse.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_mouse.hxx"

static struct RClass *mouse_module;

extern "C" void
mrb_sfml_mouse_init_bind(mrb_state *mrb, struct RClass *mod)
{
  mouse_module = mrb_define_module_under(mrb, mod, "Mouse");
}
