#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Keyboard.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_keyboard.hxx"

static struct RClass *keyboard_module;

extern "C" void
mrb_sfml_keyboard_init_bind(mrb_state *mrb, struct RClass *mod)
{
  keyboard_module = mrb_define_module_under(mrb, mod, "Keyboard");
}
