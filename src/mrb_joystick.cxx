#include <mruby.h>
#include <mruby/array.h>
#include <mruby/class.h>
#include <SFML/Window/Joystick.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_joystick.hxx"

static sf::Joystick::Axis
joystick_index_to_axis(mrb_state* mrb, mrb_int index)
{
  switch (index) {
    case 0: return sf::Joystick::X;
    case 1: return sf::Joystick::Y;
    case 2: return sf::Joystick::Z;
    case 3: return sf::Joystick::R;
    case 4: return sf::Joystick::U;
    case 5: return sf::Joystick::V;
    case 6: return sf::Joystick::PovX;
    case 7: return sf::Joystick::PovY;
  }
  mrb_raisef(mrb, E_ARGUMENT_ERROR, "invalid axis id!");
  return sf::Joystick::Axis::X;
}

static mrb_value
joystick_is_connected(mrb_state* mrb, mrb_value self)
{
  mrb_int index;
  mrb_get_args(mrb, "i", &index);
  return mrb_bool_value(sf::Joystick::isConnected(index));
}

static mrb_value
joystick_get_button_count(mrb_state* mrb, mrb_value self)
{
  mrb_int index;
  mrb_get_args(mrb, "i", &index);
  return mrb_fixnum_value(sf::Joystick::getButtonCount(index));
}

static mrb_value
joystick_has_axis(mrb_state* mrb, mrb_value self)
{
  mrb_int index;
  mrb_int axis;
  mrb_get_args(mrb, "ii", &index, &axis);
  return mrb_bool_value(sf::Joystick::hasAxis(index, joystick_index_to_axis(mrb, axis)));
}

static mrb_value
joystick_is_button_pressed(mrb_state* mrb, mrb_value self)
{
  mrb_int index;
  mrb_int button;
  mrb_get_args(mrb, "ii", &index, &button);
  return mrb_bool_value(sf::Joystick::isButtonPressed(index, button));
}

static mrb_value
joystick_get_axis_position(mrb_state* mrb, mrb_value self)
{
  mrb_int index;
  mrb_int axis;
  mrb_get_args(mrb, "ii", &index, &axis);
  return mrb_float_value(mrb, sf::Joystick::getAxisPosition(index, joystick_index_to_axis(mrb, axis)));
}

static mrb_value
joystick_identification_data(mrb_state* mrb, mrb_value self)
{
  mrb_int index;
  mrb_value result;
  sf::Joystick::Identification ident;
  mrb_get_args(mrb, "i", &index);
  result = mrb_ary_new_capa(mrb, 3);
  ident = sf::Joystick::getIdentification(index);
  mrb_ary_set(mrb, result, 0, mrb_str_new_cstr(mrb, ident.name.toAnsiString().c_str()));
  mrb_ary_set(mrb, result, 1, mrb_fixnum_value(ident.vendorId));
  mrb_ary_set(mrb, result, 2, mrb_fixnum_value(ident.productId));
  return result;
}

static mrb_value
joystick_update(mrb_state* mrb, mrb_value self)
{
  sf::Joystick::update();
  return self;
}

extern "C" void
mrb_sfml_joystick_init_bind(mrb_state* mrb, struct RClass* mod)
{
  struct RClass* joystick_module = mrb_define_module_under(mrb, mod, "Joystick");
  struct RClass* axis_module = mrb_define_module_under(mrb, joystick_module, "Axis");
  mrb_define_const(mrb, joystick_module, "Count", mrb_fixnum_value(sf::Joystick::Count));
  mrb_define_const(mrb, joystick_module, "ButtonCount", mrb_fixnum_value(sf::Joystick::ButtonCount));
  mrb_define_const(mrb, joystick_module, "AxisCount", mrb_fixnum_value(sf::Joystick::AxisCount));
  mrb_define_const(mrb, axis_module, "X", mrb_fixnum_value(sf::Joystick::X));
  mrb_define_const(mrb, axis_module, "Y", mrb_fixnum_value(sf::Joystick::Y));
  mrb_define_const(mrb, axis_module, "Z", mrb_fixnum_value(sf::Joystick::Z));
  mrb_define_const(mrb, axis_module, "R", mrb_fixnum_value(sf::Joystick::R));
  mrb_define_const(mrb, axis_module, "U", mrb_fixnum_value(sf::Joystick::U));
  mrb_define_const(mrb, axis_module, "V", mrb_fixnum_value(sf::Joystick::V));
  mrb_define_const(mrb, axis_module, "PovX", mrb_fixnum_value(sf::Joystick::PovX));
  mrb_define_const(mrb, axis_module, "PovY", mrb_fixnum_value(sf::Joystick::PovY));

  mrb_define_class_method(mrb, joystick_module, "is_connected?", joystick_is_connected, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, joystick_module, "button_count", joystick_get_button_count, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, joystick_module, "has_axis?", joystick_has_axis, MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, joystick_module, "is_button_pressed?", joystick_is_button_pressed, MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, joystick_module, "axis_position", joystick_get_axis_position, MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, joystick_module, "identification_data", joystick_identification_data, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, joystick_module, "update", joystick_update, MRB_ARGS_NONE());
}
