#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Sensor.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_sensor.hxx"


extern "C" void
mrb_sfml_sensor_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *sensor_mod = mrb_define_module_under(mrb, mod, "Sensor");
}
