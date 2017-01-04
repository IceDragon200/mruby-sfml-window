#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Mouse.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/vector2.hxx"
#include "mrb_mouse.hxx"

/* @!module SFML::Mouse
 * @!class-method is_button_pressed(button)
 *   @param [SFML::Mouse::Button] button
 *   @return [Boolean]
 */
static mrb_value
mouse_is_button_pressed(mrb_state *mrb, mrb_value self)
{
  mrb_int button;
  mrb_get_args(mrb, "i", &button);
  return mrb_bool_value(sf::Mouse::isButtonPressed((sf::Mouse::Button)button));
}

/* @!module SFML::Mouse
 * @!class-method get_position
 *   @return [SFML::Vector2i]
 */
static mrb_value
mouse_get_position(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector2i_value(mrb, sf::Mouse::getPosition());
}

/* @!module SFML::Mouse
 * @!class-method set_position(position)
 *   @param [SFML::Vector2i] position
 *   @return [self]
 */
static mrb_value
mouse_set_position(mrb_state *mrb, mrb_value self)
{
  sf::Vector2i *pos;
  mrb_get_args(mrb, "d", &pos, &mrb_sfml_vector2i_type);
  sf::Mouse::setPosition(*pos);
  return self;
}

/* @!module SFML::Mouse
 */
MRB_SFML_EXTERN void
mrb_sfml_mouse_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *mouse_module = mrb_define_module_under(mrb, mod, "Mouse");
  struct RClass *mouse_button_module = mrb_define_module_under(mrb, mouse_module, "Button");
  struct RClass *mouse_wheel_module = mrb_define_module_under(mrb, mouse_module, "Wheel");

  mrb_define_class_method(mrb, mouse_module, "is_button_pressed", mouse_is_button_pressed, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, mouse_module, "get_position", mouse_get_position, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, mouse_module, "set_position", mouse_set_position, MRB_ARGS_REQ(1));

  mrb_define_const(mrb, mouse_button_module, "Left", mrb_fixnum_value(sf::Mouse::Button::Left));
  mrb_define_const(mrb, mouse_button_module, "Right", mrb_fixnum_value(sf::Mouse::Button::Right));
  mrb_define_const(mrb, mouse_button_module, "Middle", mrb_fixnum_value(sf::Mouse::Button::Middle));
  mrb_define_const(mrb, mouse_button_module, "XButton1", mrb_fixnum_value(sf::Mouse::Button::XButton1));
  mrb_define_const(mrb, mouse_button_module, "XButton2", mrb_fixnum_value(sf::Mouse::Button::XButton2));
  mrb_define_const(mrb, mouse_button_module, "ButtonCount", mrb_fixnum_value(sf::Mouse::Button::ButtonCount));

  mrb_define_const(mrb, mouse_wheel_module, "VerticalWheel", mrb_fixnum_value(sf::Mouse::Wheel::VerticalWheel));
  mrb_define_const(mrb, mouse_wheel_module, "HorizontalWheel", mrb_fixnum_value(sf::Mouse::Wheel::HorizontalWheel));
}
