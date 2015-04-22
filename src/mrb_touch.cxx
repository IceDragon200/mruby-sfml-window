#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Touch.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_touch.hxx"

static struct RClass *touch_module;

extern "C" void
mrb_sfml_touch_init_bind(mrb_state *mrb, struct RClass *mod)
{
  touch_module = mrb_define_module_under(mrb, mod, "Touch");
}
