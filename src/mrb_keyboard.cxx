#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Keyboard.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_keyboard.hxx"

/* @!module SFML::Keyboard
 * @!class-method is_key_pressed(key)
 *   @param [SFML::Keyboard::Key] key
 *   @return [Boolean]
 */
static mrb_value
keyboard_is_key_pressed(mrb_state *mrb, mrb_value self)
{
  mrb_int key;
  mrb_get_args(mrb, "i", &key);
  return mrb_bool_value(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key));
}

/* @!module SFML::Keyboard
 * @!class-method set_virtual_keyboard_visible(visible)
 *   @param [Boolean] visible
 *   @return [self]
 */
static mrb_value
keyboard_set_virtual_keyboard_visible(mrb_state *mrb, mrb_value self)
{
  mrb_bool visible;
  mrb_get_args(mrb, "b", &visible);
  sf::Keyboard::setVirtualKeyboardVisible(visible);
  return self;
}

extern "C" void
mrb_sfml_keyboard_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *keyboard_module = mrb_define_module_under(mrb, mod, "Keyboard");
  struct RClass *keyboard_key_module = mrb_define_module_under(mrb, keyboard_module, "Key");

  mrb_define_class_method(mrb, keyboard_module, "is_key_pressed", keyboard_is_key_pressed, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, keyboard_module, "set_virtual_keyboard_visible", keyboard_set_virtual_keyboard_visible, MRB_ARGS_REQ(1));

  mrb_define_const(mrb, keyboard_key_module, "Unknown",   mrb_fixnum_value(sf::Keyboard::Key::Unknown));
  mrb_define_const(mrb, keyboard_key_module, "A",         mrb_fixnum_value(sf::Keyboard::Key::A));
  mrb_define_const(mrb, keyboard_key_module, "B",         mrb_fixnum_value(sf::Keyboard::Key::B));
  mrb_define_const(mrb, keyboard_key_module, "C",         mrb_fixnum_value(sf::Keyboard::Key::C));
  mrb_define_const(mrb, keyboard_key_module, "D",         mrb_fixnum_value(sf::Keyboard::Key::D));
  mrb_define_const(mrb, keyboard_key_module, "E",         mrb_fixnum_value(sf::Keyboard::Key::E));
  mrb_define_const(mrb, keyboard_key_module, "F",         mrb_fixnum_value(sf::Keyboard::Key::F));
  mrb_define_const(mrb, keyboard_key_module, "G",         mrb_fixnum_value(sf::Keyboard::Key::G));
  mrb_define_const(mrb, keyboard_key_module, "H",         mrb_fixnum_value(sf::Keyboard::Key::H));
  mrb_define_const(mrb, keyboard_key_module, "I",         mrb_fixnum_value(sf::Keyboard::Key::I));
  mrb_define_const(mrb, keyboard_key_module, "J",         mrb_fixnum_value(sf::Keyboard::Key::J));
  mrb_define_const(mrb, keyboard_key_module, "K",         mrb_fixnum_value(sf::Keyboard::Key::K));
  mrb_define_const(mrb, keyboard_key_module, "L",         mrb_fixnum_value(sf::Keyboard::Key::L));
  mrb_define_const(mrb, keyboard_key_module, "M",         mrb_fixnum_value(sf::Keyboard::Key::M));
  mrb_define_const(mrb, keyboard_key_module, "N",         mrb_fixnum_value(sf::Keyboard::Key::N));
  mrb_define_const(mrb, keyboard_key_module, "O",         mrb_fixnum_value(sf::Keyboard::Key::O));
  mrb_define_const(mrb, keyboard_key_module, "P",         mrb_fixnum_value(sf::Keyboard::Key::P));
  mrb_define_const(mrb, keyboard_key_module, "Q",         mrb_fixnum_value(sf::Keyboard::Key::Q));
  mrb_define_const(mrb, keyboard_key_module, "R",         mrb_fixnum_value(sf::Keyboard::Key::R));
  mrb_define_const(mrb, keyboard_key_module, "S",         mrb_fixnum_value(sf::Keyboard::Key::S));
  mrb_define_const(mrb, keyboard_key_module, "T",         mrb_fixnum_value(sf::Keyboard::Key::T));
  mrb_define_const(mrb, keyboard_key_module, "U",         mrb_fixnum_value(sf::Keyboard::Key::U));
  mrb_define_const(mrb, keyboard_key_module, "V",         mrb_fixnum_value(sf::Keyboard::Key::V));
  mrb_define_const(mrb, keyboard_key_module, "W",         mrb_fixnum_value(sf::Keyboard::Key::W));
  mrb_define_const(mrb, keyboard_key_module, "X",         mrb_fixnum_value(sf::Keyboard::Key::X));
  mrb_define_const(mrb, keyboard_key_module, "Y",         mrb_fixnum_value(sf::Keyboard::Key::Y));
  mrb_define_const(mrb, keyboard_key_module, "Z",         mrb_fixnum_value(sf::Keyboard::Key::Z));
  mrb_define_const(mrb, keyboard_key_module, "Num0",      mrb_fixnum_value(sf::Keyboard::Key::Num0));
  mrb_define_const(mrb, keyboard_key_module, "Num1",      mrb_fixnum_value(sf::Keyboard::Key::Num1));
  mrb_define_const(mrb, keyboard_key_module, "Num2",      mrb_fixnum_value(sf::Keyboard::Key::Num2));
  mrb_define_const(mrb, keyboard_key_module, "Num3",      mrb_fixnum_value(sf::Keyboard::Key::Num3));
  mrb_define_const(mrb, keyboard_key_module, "Num4",      mrb_fixnum_value(sf::Keyboard::Key::Num4));
  mrb_define_const(mrb, keyboard_key_module, "Num5",      mrb_fixnum_value(sf::Keyboard::Key::Num5));
  mrb_define_const(mrb, keyboard_key_module, "Num6",      mrb_fixnum_value(sf::Keyboard::Key::Num6));
  mrb_define_const(mrb, keyboard_key_module, "Num7",      mrb_fixnum_value(sf::Keyboard::Key::Num7));
  mrb_define_const(mrb, keyboard_key_module, "Num8",      mrb_fixnum_value(sf::Keyboard::Key::Num8));
  mrb_define_const(mrb, keyboard_key_module, "Num9",      mrb_fixnum_value(sf::Keyboard::Key::Num9));
  mrb_define_const(mrb, keyboard_key_module, "Escape",    mrb_fixnum_value(sf::Keyboard::Key::Escape));
  mrb_define_const(mrb, keyboard_key_module, "LControl",  mrb_fixnum_value(sf::Keyboard::Key::LControl));
  mrb_define_const(mrb, keyboard_key_module, "LShift",    mrb_fixnum_value(sf::Keyboard::Key::LShift));
  mrb_define_const(mrb, keyboard_key_module, "LAlt",      mrb_fixnum_value(sf::Keyboard::Key::LAlt));
  mrb_define_const(mrb, keyboard_key_module, "LSystem",   mrb_fixnum_value(sf::Keyboard::Key::LSystem));
  mrb_define_const(mrb, keyboard_key_module, "RControl",  mrb_fixnum_value(sf::Keyboard::Key::RControl));
  mrb_define_const(mrb, keyboard_key_module, "RShift",    mrb_fixnum_value(sf::Keyboard::Key::RShift));
  mrb_define_const(mrb, keyboard_key_module, "RAlt",      mrb_fixnum_value(sf::Keyboard::Key::RAlt));
  mrb_define_const(mrb, keyboard_key_module, "RSystem",   mrb_fixnum_value(sf::Keyboard::Key::RSystem));
  mrb_define_const(mrb, keyboard_key_module, "Menu",      mrb_fixnum_value(sf::Keyboard::Key::Menu));
  mrb_define_const(mrb, keyboard_key_module, "LBracket",  mrb_fixnum_value(sf::Keyboard::Key::LBracket));
  mrb_define_const(mrb, keyboard_key_module, "RBracket",  mrb_fixnum_value(sf::Keyboard::Key::RBracket));
  mrb_define_const(mrb, keyboard_key_module, "SemiColon", mrb_fixnum_value(sf::Keyboard::Key::SemiColon));
  mrb_define_const(mrb, keyboard_key_module, "Comma",     mrb_fixnum_value(sf::Keyboard::Key::Comma));
  mrb_define_const(mrb, keyboard_key_module, "Period",    mrb_fixnum_value(sf::Keyboard::Key::Period));
  mrb_define_const(mrb, keyboard_key_module, "Quote",     mrb_fixnum_value(sf::Keyboard::Key::Quote));
  mrb_define_const(mrb, keyboard_key_module, "Slash",     mrb_fixnum_value(sf::Keyboard::Key::Slash));
  mrb_define_const(mrb, keyboard_key_module, "BackSlash", mrb_fixnum_value(sf::Keyboard::Key::BackSlash));
  mrb_define_const(mrb, keyboard_key_module, "Tilde",     mrb_fixnum_value(sf::Keyboard::Key::Tilde));
  mrb_define_const(mrb, keyboard_key_module, "Equal",     mrb_fixnum_value(sf::Keyboard::Key::Equal));
  mrb_define_const(mrb, keyboard_key_module, "Dash",      mrb_fixnum_value(sf::Keyboard::Key::Dash));
  mrb_define_const(mrb, keyboard_key_module, "Space",     mrb_fixnum_value(sf::Keyboard::Key::Space));
  mrb_define_const(mrb, keyboard_key_module, "Return",    mrb_fixnum_value(sf::Keyboard::Key::Return));
  mrb_define_const(mrb, keyboard_key_module, "BackSpace", mrb_fixnum_value(sf::Keyboard::Key::BackSpace));
  mrb_define_const(mrb, keyboard_key_module, "Tab",       mrb_fixnum_value(sf::Keyboard::Key::Tab));
  mrb_define_const(mrb, keyboard_key_module, "PageUp",    mrb_fixnum_value(sf::Keyboard::Key::PageUp));
  mrb_define_const(mrb, keyboard_key_module, "PageDown",  mrb_fixnum_value(sf::Keyboard::Key::PageDown));
  mrb_define_const(mrb, keyboard_key_module, "End",       mrb_fixnum_value(sf::Keyboard::Key::End));
  mrb_define_const(mrb, keyboard_key_module, "Home",      mrb_fixnum_value(sf::Keyboard::Key::Home));
  mrb_define_const(mrb, keyboard_key_module, "Insert",    mrb_fixnum_value(sf::Keyboard::Key::Insert));
  mrb_define_const(mrb, keyboard_key_module, "Delete",    mrb_fixnum_value(sf::Keyboard::Key::Delete));
  mrb_define_const(mrb, keyboard_key_module, "Add",       mrb_fixnum_value(sf::Keyboard::Key::Add));
  mrb_define_const(mrb, keyboard_key_module, "Subtract",  mrb_fixnum_value(sf::Keyboard::Key::Subtract));
  mrb_define_const(mrb, keyboard_key_module, "Multiply",  mrb_fixnum_value(sf::Keyboard::Key::Multiply));
  mrb_define_const(mrb, keyboard_key_module, "Divide",    mrb_fixnum_value(sf::Keyboard::Key::Divide));
  mrb_define_const(mrb, keyboard_key_module, "Left",      mrb_fixnum_value(sf::Keyboard::Key::Left));
  mrb_define_const(mrb, keyboard_key_module, "Right",     mrb_fixnum_value(sf::Keyboard::Key::Right));
  mrb_define_const(mrb, keyboard_key_module, "Up",        mrb_fixnum_value(sf::Keyboard::Key::Up));
  mrb_define_const(mrb, keyboard_key_module, "Down",      mrb_fixnum_value(sf::Keyboard::Key::Down));
  mrb_define_const(mrb, keyboard_key_module, "Numpad0",   mrb_fixnum_value(sf::Keyboard::Key::Numpad0));
  mrb_define_const(mrb, keyboard_key_module, "Numpad1",   mrb_fixnum_value(sf::Keyboard::Key::Numpad1));
  mrb_define_const(mrb, keyboard_key_module, "Numpad2",   mrb_fixnum_value(sf::Keyboard::Key::Numpad2));
  mrb_define_const(mrb, keyboard_key_module, "Numpad3",   mrb_fixnum_value(sf::Keyboard::Key::Numpad3));
  mrb_define_const(mrb, keyboard_key_module, "Numpad4",   mrb_fixnum_value(sf::Keyboard::Key::Numpad4));
  mrb_define_const(mrb, keyboard_key_module, "Numpad5",   mrb_fixnum_value(sf::Keyboard::Key::Numpad5));
  mrb_define_const(mrb, keyboard_key_module, "Numpad6",   mrb_fixnum_value(sf::Keyboard::Key::Numpad6));
  mrb_define_const(mrb, keyboard_key_module, "Numpad7",   mrb_fixnum_value(sf::Keyboard::Key::Numpad7));
  mrb_define_const(mrb, keyboard_key_module, "Numpad8",   mrb_fixnum_value(sf::Keyboard::Key::Numpad8));
  mrb_define_const(mrb, keyboard_key_module, "Numpad9",   mrb_fixnum_value(sf::Keyboard::Key::Numpad9));
  mrb_define_const(mrb, keyboard_key_module, "F1",        mrb_fixnum_value(sf::Keyboard::Key::F1));
  mrb_define_const(mrb, keyboard_key_module, "F2",        mrb_fixnum_value(sf::Keyboard::Key::F2));
  mrb_define_const(mrb, keyboard_key_module, "F3",        mrb_fixnum_value(sf::Keyboard::Key::F3));
  mrb_define_const(mrb, keyboard_key_module, "F4",        mrb_fixnum_value(sf::Keyboard::Key::F4));
  mrb_define_const(mrb, keyboard_key_module, "F5",        mrb_fixnum_value(sf::Keyboard::Key::F5));
  mrb_define_const(mrb, keyboard_key_module, "F6",        mrb_fixnum_value(sf::Keyboard::Key::F6));
  mrb_define_const(mrb, keyboard_key_module, "F7",        mrb_fixnum_value(sf::Keyboard::Key::F7));
  mrb_define_const(mrb, keyboard_key_module, "F8",        mrb_fixnum_value(sf::Keyboard::Key::F8));
  mrb_define_const(mrb, keyboard_key_module, "F9",        mrb_fixnum_value(sf::Keyboard::Key::F9));
  mrb_define_const(mrb, keyboard_key_module, "F10",       mrb_fixnum_value(sf::Keyboard::Key::F10));
  mrb_define_const(mrb, keyboard_key_module, "F11",       mrb_fixnum_value(sf::Keyboard::Key::F11));
  mrb_define_const(mrb, keyboard_key_module, "F12",       mrb_fixnum_value(sf::Keyboard::Key::F12));
  mrb_define_const(mrb, keyboard_key_module, "F13",       mrb_fixnum_value(sf::Keyboard::Key::F13));
  mrb_define_const(mrb, keyboard_key_module, "F14",       mrb_fixnum_value(sf::Keyboard::Key::F14));
  mrb_define_const(mrb, keyboard_key_module, "F15",       mrb_fixnum_value(sf::Keyboard::Key::F15));
  mrb_define_const(mrb, keyboard_key_module, "Pause",     mrb_fixnum_value(sf::Keyboard::Key::Pause));

  mrb_define_const(mrb, keyboard_key_module, "KeyCount",  mrb_fixnum_value(sf::Keyboard::Key::KeyCount));
}
