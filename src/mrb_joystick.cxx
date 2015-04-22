#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Joystick.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_joystick.hxx"

static struct RClass *joystick_module;

extern "C" void
mrb_sfml_joystick_init_bind(mrb_state *mrb, struct RClass *mod)
{
  joystick_module = mrb_define_module_under(mrb, mod, "Joystick");
}
