#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Sensor.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/vector3.hxx"
#include "mrb_sensor.hxx"

/* @!class SFML::Sensor
 * @!class-method is_available(sensor)
 *   @param [SFML::Sensor::Type] sensor
 *   @return [Boolean]
 */
static mrb_value
sensor_is_available(mrb_state *mrb, mrb_value self)
{
  mrb_int sensor;
  mrb_get_args(mrb, "i", &sensor);
  return mrb_bool_value(sf::Sensor::isAvailable((sf::Sensor::Type)sensor));
}

/* @!class SFML::Sensor
 * @!class-method set_enabled(sensor, enabled)
 *   @param [SFML::Sensor::Type] sensor
 *   @param [Boolean] enabled
 *   @return [self]
 */
static mrb_value
sensor_set_enabled(mrb_state *mrb, mrb_value self)
{
  mrb_int sensor;
  mrb_bool enabled;
  mrb_get_args(mrb, "ib", &sensor, &enabled);
  sf::Sensor::setEnabled((sf::Sensor::Type)sensor, enabled);
  return self;
}

/* @!class SFML::Sensor
 * @!class-method get_value(sensor)
 *   @param [SFML::Sensor::Type] sensor
 *   @return [SFML::Vector3f]
 */
static mrb_value
sensor_get_value(mrb_state *mrb, mrb_value self)
{
  mrb_int sensor;
  mrb_get_args(mrb, "i", &sensor);
  return mrb_sfml_vector3f_value(mrb, sf::Sensor::getValue((sf::Sensor::Type)sensor));
}

/* @!class SFML::Sensor
 */
extern "C" void
mrb_sfml_sensor_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *sensor_mod = mrb_define_module_under(mrb, mod, "Sensor");
  struct RClass *sensor_type_mod = mrb_define_module_under(mrb, sensor_mod, "Type");

  mrb_define_class_method(mrb, sensor_mod, "is_available", sensor_is_available, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, sensor_mod, "set_enabled",  sensor_set_enabled,  MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, sensor_mod, "get_value",    sensor_get_value,    MRB_ARGS_REQ(1));

  mrb_define_const(mrb, sensor_type_mod, "Accelerometer",    mrb_fixnum_value(sf::Sensor::Type::Accelerometer));
  mrb_define_const(mrb, sensor_type_mod, "Gyroscope",        mrb_fixnum_value(sf::Sensor::Type::Gyroscope));
  mrb_define_const(mrb, sensor_type_mod, "Magnetometer",     mrb_fixnum_value(sf::Sensor::Type::Magnetometer));
  mrb_define_const(mrb, sensor_type_mod, "Gravity",          mrb_fixnum_value(sf::Sensor::Type::Gravity));
  mrb_define_const(mrb, sensor_type_mod, "UserAcceleration", mrb_fixnum_value(sf::Sensor::Type::UserAcceleration));
  mrb_define_const(mrb, sensor_type_mod, "Orientation",      mrb_fixnum_value(sf::Sensor::Type::Orientation));
  mrb_define_const(mrb, sensor_type_mod, "Count",            mrb_fixnum_value(sf::Sensor::Type::Count));
}
