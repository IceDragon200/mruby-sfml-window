#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Sensor.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_sensor.hxx"

static struct RClass *sensor_module;

extern "C" void
mrb_sfml_sensor_init_bind(mrb_state *mrb, struct RClass *mod)
{
  sensor_module = mrb_define_module_under(mrb, mod, "Sensor");
}
