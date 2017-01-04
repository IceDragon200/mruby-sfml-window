#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Touch.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/vector2.hxx"
#include "mrb_touch.hxx"

/* @!class SFML::Touch
 * @!class-method is_down(finger)
 *   @param [Integer] finger
 *   @return [Boolean]
 */
static mrb_value
touch_is_down(mrb_state *mrb, mrb_value self)
{
  mrb_int finger;
  mrb_get_args(mrb, "i", &finger);
  return mrb_bool_value(sf::Touch::isDown(finger));
}

/* @!class SFML::Touch
 * @!class-method get_position(finger)
 *   @param [Integer] finger
 *   @return [SFML::Vector2i]
 */
static mrb_value
touch_get_position(mrb_state *mrb, mrb_value self)
{
  mrb_int finger;
  mrb_get_args(mrb, "i", &finger);
  return mrb_sfml_vector2i_value(mrb, sf::Touch::getPosition(finger));
}

/* @!class SFML::Touch
 */
MRB_SFML_EXTERN void
mrb_sfml_touch_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *touch_module = mrb_define_module_under(mrb, mod, "Touch");

  mrb_define_class_method(mrb, touch_module, "is_down",      touch_is_down,      MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, touch_module, "get_position", touch_get_position, MRB_ARGS_REQ(1));
}
