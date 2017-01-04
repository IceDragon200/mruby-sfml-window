#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Event.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/event.hxx"
#include "mrb_event.hxx"

static mrb_data_free_func event_free = cxx_mrb_data_free<sf::Event>;
static mrb_data_free_func size_event_free = cxx_mrb_data_free<sf::Event::SizeEvent>;
static mrb_data_free_func key_event_free = cxx_mrb_data_free<sf::Event::KeyEvent>;
static mrb_data_free_func text_event_free = cxx_mrb_data_free<sf::Event::TextEvent>;
static mrb_data_free_func mouse_move_event_free = cxx_mrb_data_free<sf::Event::MouseMoveEvent>;
static mrb_data_free_func mouse_button_event_free = cxx_mrb_data_free<sf::Event::MouseButtonEvent>;
static mrb_data_free_func mouse_wheel_event_free = cxx_mrb_data_free<sf::Event::MouseWheelEvent>;
static mrb_data_free_func joystick_move_event_free = cxx_mrb_data_free<sf::Event::JoystickMoveEvent>;
static mrb_data_free_func joystick_button_event_free = cxx_mrb_data_free<sf::Event::JoystickButtonEvent>;
static mrb_data_free_func joystick_connect_event_free = cxx_mrb_data_free<sf::Event::JoystickConnectEvent>;
static mrb_data_free_func touch_event_free = cxx_mrb_data_free<sf::Event::TouchEvent>;
static mrb_data_free_func sensor_event_free = cxx_mrb_data_free<sf::Event::SensorEvent>;

MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_event_type = { "sf::Event", event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_size_event_type = { "sf::Event::SizeEvent", size_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_key_event_type = { "sf::Event::KeyEvent", key_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_text_event_type = { "sf::Event::TextEvent", text_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_mouse_move_event_type = { "sf::Event::MoveMoveEvent", mouse_move_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_mouse_button_event_type = { "sf::Event::MouseButtonEvent", mouse_button_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_mouse_wheel_event_type = { "sf::Event::MouseWheelEvent", mouse_wheel_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_joystick_move_event_type = { "sf::Event::JoystickMoveEvent", joystick_move_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_joystick_button_event_type = { "sf::Event::JoystickButtonEvent", joystick_button_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_joystick_connect_event_type = { "sf::Event::JoystickConnectEvent", joystick_connect_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_touch_event_type = { "sf::Event::TouchEvent", touch_event_free };
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_sensor_event_type = { "sf::Event::SensorEvent", sensor_event_free };

static inline sf::Event*
get_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_event_type));
}

static inline sf::Event::SizeEvent*
get_size_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::SizeEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_size_event_type));
}

static inline sf::Event::KeyEvent*
get_key_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::KeyEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_key_event_type));
}

static inline sf::Event::TextEvent*
get_text_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::TextEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_text_event_type));
}

static inline sf::Event::MouseMoveEvent*
get_mouse_move_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::MouseMoveEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_mouse_move_event_type));
}

static inline sf::Event::MouseButtonEvent*
get_mouse_button_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::MouseButtonEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_mouse_button_event_type));
}

static inline sf::Event::MouseWheelEvent*
get_mouse_wheel_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::MouseWheelEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_mouse_wheel_event_type));
}

static inline sf::Event::JoystickMoveEvent*
get_joystick_move_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::JoystickMoveEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_joystick_move_event_type));
}

static inline sf::Event::JoystickButtonEvent*
get_joystick_button_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::JoystickButtonEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_joystick_button_event_type));
}

static inline sf::Event::JoystickConnectEvent*
get_joystick_connect_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::JoystickConnectEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_joystick_connect_event_type));
}

static inline sf::Event::TouchEvent*
get_touch_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::TouchEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_touch_event_type));
}

static inline sf::Event::SensorEvent*
get_sensor_event(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Event::SensorEvent*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_sensor_event_type));
}

static inline struct RClass*
mrb_sfml_event_class_get(mrb_state *mrb)
{
  return mrb_class_get_under(mrb, mrb_module_get(mrb, "SFML"), "Event");
}

static inline struct RClass*
mrb_sfml_event_sub_class_get(mrb_state *mrb, const char *classname)
{
  return mrb_class_get_under(mrb, mrb_sfml_event_class_get(mrb), classname);
}

MRB_SFML_EXTERN mrb_value
mrb_sfml_event_value(mrb_state *mrb, const sf::Event &event)
{
  mrb_value result = mrb_obj_new(mrb, mrb_sfml_event_class_get(mrb), 0, NULL);
  sf::Event *target = get_event(mrb, result);
  *target = event;
  return result;
}

template <class T>
static inline mrb_value
mrb_sfml_event_sub_event_value(mrb_state *mrb, const char *classname, const T &event)
{
  mrb_value result = mrb_obj_new(mrb, mrb_sfml_event_sub_class_get(mrb, classname), 0, NULL);
  T *target = cxx_mrb_data_get_ptr<T>(mrb, result);
  *target = event;
  return result;
}

static mrb_value
event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event *event = new sf::Event();
  event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_event_type);
  return self;
}

static mrb_value
event_type(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_event(mrb, self)->type);
}

static mrb_value
event_size(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::SizeEvent>(mrb, "SizeEvent", get_event(mrb, self)->size);
}

static mrb_value
event_key(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::KeyEvent>(mrb, "KeyEvent", get_event(mrb, self)->key);
}

static mrb_value
event_text(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::TextEvent>(mrb, "TextEvent", get_event(mrb, self)->text);
}

static mrb_value
event_mouse_move(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::MouseMoveEvent>(mrb, "MouseMoveEvent", get_event(mrb, self)->mouseMove);
}

static mrb_value
event_mouse_button(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::MouseButtonEvent>(mrb, "MouseButtonEvent", get_event(mrb, self)->mouseButton);
}

static mrb_value
event_mouse_wheel(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::MouseWheelEvent>(mrb, "MouseWheelEvent", get_event(mrb, self)->mouseWheel);
}

static mrb_value
event_joystick_move(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::JoystickMoveEvent>(mrb, "JoystickMoveEvent", get_event(mrb, self)->joystickMove);
}

static mrb_value
event_joystick_button(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::JoystickButtonEvent>(mrb, "JoystickButtonEvent", get_event(mrb, self)->joystickButton);
}

static mrb_value
event_joystick_connect(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::JoystickConnectEvent>(mrb, "JoystickConnectEvent", get_event(mrb, self)->joystickConnect);
}

static mrb_value
event_touch(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::TouchEvent>(mrb, "TouchEvent", get_event(mrb, self)->touch);
}

static mrb_value
event_sensor(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_event_sub_event_value<sf::Event::SensorEvent>(mrb, "SensorEvent", get_event(mrb, self)->sensor);
}

static mrb_value
size_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::SizeEvent *event = new sf::Event::SizeEvent();
  size_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_size_event_type);
  return self;
}

static mrb_value
size_event_get_width(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_size_event(mrb, self)->width);
}

static mrb_value
size_event_get_height(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_size_event(mrb, self)->height);
}


static mrb_value
key_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::KeyEvent *event = new sf::Event::KeyEvent();
  key_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_key_event_type);
  return self;
}

static mrb_value
key_event_get_code(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_key_event(mrb, self)->code);
}

static mrb_value
key_event_get_alt(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_key_event(mrb, self)->alt);
}

static mrb_value
key_event_get_control(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_key_event(mrb, self)->control);
}

static mrb_value
key_event_get_shift(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_key_event(mrb, self)->shift);
}

static mrb_value
key_event_get_system(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_key_event(mrb, self)->system);
}

static mrb_value
text_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::TextEvent *event = new sf::Event::TextEvent();
  text_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_text_event_type);
  return self;
}

static mrb_value
text_event_get_unicode(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_text_event(mrb, self)->unicode);
}

static mrb_value
mouse_move_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::MouseMoveEvent *event = new sf::Event::MouseMoveEvent();
  mouse_move_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_mouse_move_event_type);
  return self;
}

static mrb_value
mouse_move_event_get_x(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_move_event(mrb, self)->x);
}

static mrb_value
mouse_move_event_get_y(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_move_event(mrb, self)->y);
}


static mrb_value
mouse_button_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::MouseButtonEvent *event = new sf::Event::MouseButtonEvent();
  mouse_button_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_mouse_button_event_type);
  return self;
}

static mrb_value
mouse_button_event_get_button(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_button_event(mrb, self)->button);
}

static mrb_value
mouse_button_event_get_x(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_button_event(mrb, self)->x);
}

static mrb_value
mouse_button_event_get_y(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_button_event(mrb, self)->y);
}


static mrb_value
mouse_wheel_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::MouseWheelEvent *event = new sf::Event::MouseWheelEvent();
  mouse_wheel_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_mouse_wheel_event_type);
  return self;
}

static mrb_value
mouse_wheel_event_get_delta(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_wheel_event(mrb, self)->delta);
}

static mrb_value
mouse_wheel_event_get_x(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_wheel_event(mrb, self)->x);
}

static mrb_value
mouse_wheel_event_get_y(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_mouse_wheel_event(mrb, self)->y);
}


static mrb_value
joystick_move_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::JoystickMoveEvent *event = new sf::Event::JoystickMoveEvent();
  joystick_move_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_joystick_move_event_type);
  return self;
}

static mrb_value
joystick_move_event_get_joystick_id(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_joystick_move_event(mrb, self)->joystickId);
}

static mrb_value
joystick_move_event_get_axis(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_joystick_move_event(mrb, self)->axis);
}

static mrb_value
joystick_move_event_get_position(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_joystick_move_event(mrb, self)->position);
}


static mrb_value
joystick_button_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::JoystickButtonEvent *event = new sf::Event::JoystickButtonEvent();
  joystick_button_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_joystick_button_event_type);
  return self;
}

static mrb_value
joystick_button_event_get_joystick_id(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_joystick_button_event(mrb, self)->joystickId);
}

static mrb_value
joystick_button_event_get_button(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_joystick_button_event(mrb, self)->button);
}


static mrb_value
joystick_connect_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::JoystickConnectEvent *event = new sf::Event::JoystickConnectEvent();
  joystick_connect_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_joystick_connect_event_type);
  return self;
}

static mrb_value
joystick_connect_event_get_joystick_id(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_joystick_connect_event(mrb, self)->joystickId);
}


static mrb_value
touch_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::TouchEvent *event = new sf::Event::TouchEvent();
  touch_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_touch_event_type);
  return self;
}

static mrb_value
touch_event_get_finger(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_touch_event(mrb, self)->finger);
}

static mrb_value
touch_event_get_x(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_touch_event(mrb, self)->x);
}

static mrb_value
touch_event_get_y(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_touch_event(mrb, self)->y);
}


static mrb_value
sensor_event_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Event::SensorEvent *event = new sf::Event::SensorEvent();
  sensor_event_free(mrb, DATA_PTR(self));
  mrb_data_init(self, event, &mrb_sfml_sensor_event_type);
  return self;
}

static mrb_value
sensor_event_get_type(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_sensor_event(mrb, self)->type);
}

static mrb_value
sensor_event_get_x(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sensor_event(mrb, self)->x);
}

static mrb_value
sensor_event_get_y(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sensor_event(mrb, self)->y);
}

static mrb_value
sensor_event_get_z(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sensor_event(mrb, self)->z);
}

MRB_SFML_EXTERN void
mrb_sfml_event_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *event_cls = mrb_define_class_under(mrb, mod, "Event", mrb->object_class);
  struct RClass *size_event_cls = mrb_define_class_under(mrb, event_cls, "SizeEvent", mrb->object_class);
  struct RClass *key_event_cls = mrb_define_class_under(mrb, event_cls, "KeyEvent", mrb->object_class);
  struct RClass *text_event_cls = mrb_define_class_under(mrb, event_cls, "TextEvent", mrb->object_class);
  struct RClass *mouse_move_event_cls = mrb_define_class_under(mrb, event_cls, "MouseMoveEvent", mrb->object_class);
  struct RClass *mouse_button_event_cls = mrb_define_class_under(mrb, event_cls, "MouseButtonEvent", mrb->object_class);
  struct RClass *mouse_wheel_event_cls = mrb_define_class_under(mrb, event_cls, "MouseWheelEvent", mrb->object_class);
  struct RClass *joystick_move_event_cls = mrb_define_class_under(mrb, event_cls, "JoystickMoveEvent", mrb->object_class);
  struct RClass *joystick_button_event_cls = mrb_define_class_under(mrb, event_cls, "JoystickButtonEvent", mrb->object_class);
  struct RClass *joystick_connect_event_cls = mrb_define_class_under(mrb, event_cls, "JoystickConnectEvent", mrb->object_class);
  struct RClass *touch_event_cls = mrb_define_class_under(mrb, event_cls, "TouchEvent", mrb->object_class);
  struct RClass *sensor_event_cls = mrb_define_class_under(mrb, event_cls, "SensorEvent", mrb->object_class);
  struct RClass *event_type_mod = mrb_define_module_under(mrb, event_cls, "EventType");

  MRB_SET_INSTANCE_TT(event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, event_cls, "initialize",       event_initialize,       MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "type",             event_type,             MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "size",             event_size,             MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "key",              event_key,              MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "text",             event_text,             MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "mouse_move",       event_mouse_move,       MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "mouse_button",     event_mouse_button,     MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "mouse_wheel",      event_mouse_wheel,      MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "joystick_move",    event_joystick_move,    MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "joystick_button",  event_joystick_button,  MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "joystick_connect", event_joystick_connect, MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "touch",            event_touch,            MRB_ARGS_NONE());
  mrb_define_method(mrb, event_cls, "sensor",           event_sensor,           MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(size_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, size_event_cls, "initialize",       size_event_initialize,       MRB_ARGS_NONE());
  mrb_define_method(mrb, size_event_cls, "width",            size_event_get_width,       MRB_ARGS_NONE());
  mrb_define_method(mrb, size_event_cls, "height",           size_event_get_height,       MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(key_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, key_event_cls, "initialize", key_event_initialize,  MRB_ARGS_NONE());
  mrb_define_method(mrb, key_event_cls, "code",       key_event_get_code,    MRB_ARGS_NONE());
  mrb_define_method(mrb, key_event_cls, "alt",        key_event_get_alt,     MRB_ARGS_NONE());
  mrb_define_method(mrb, key_event_cls, "control",    key_event_get_control, MRB_ARGS_NONE());
  mrb_define_method(mrb, key_event_cls, "shift",      key_event_get_shift,   MRB_ARGS_NONE());
  mrb_define_method(mrb, key_event_cls, "system",     key_event_get_system,  MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(text_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, text_event_cls, "initialize", text_event_initialize,  MRB_ARGS_NONE());
  mrb_define_method(mrb, text_event_cls, "unicode",    text_event_get_unicode, MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(mouse_move_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, mouse_move_event_cls, "initialize", mouse_move_event_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_move_event_cls, "x",          mouse_move_event_get_x,      MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_move_event_cls, "y",          mouse_move_event_get_y,      MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(mouse_button_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, mouse_button_event_cls, "initialize", mouse_button_event_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_button_event_cls, "button",     mouse_button_event_get_button, MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_button_event_cls, "x",          mouse_button_event_get_x,      MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_button_event_cls, "y",          mouse_button_event_get_y,      MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(mouse_wheel_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, mouse_wheel_event_cls, "initialize", mouse_wheel_event_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_wheel_event_cls, "delta",      mouse_wheel_event_get_delta,  MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_wheel_event_cls, "x",          mouse_wheel_event_get_x,      MRB_ARGS_NONE());
  mrb_define_method(mrb, mouse_wheel_event_cls, "y",          mouse_wheel_event_get_y,      MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(joystick_move_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, joystick_move_event_cls, "initialize",  joystick_move_event_initialize,      MRB_ARGS_NONE());
  mrb_define_method(mrb, joystick_move_event_cls, "joystick_id", joystick_move_event_get_joystick_id, MRB_ARGS_NONE());
  mrb_define_method(mrb, joystick_move_event_cls, "axis",        joystick_move_event_get_axis,        MRB_ARGS_NONE());
  mrb_define_method(mrb, joystick_move_event_cls, "position",    joystick_move_event_get_position,    MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(joystick_button_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, joystick_button_event_cls, "initialize",  joystick_button_event_initialize,       MRB_ARGS_NONE());
  mrb_define_method(mrb, joystick_button_event_cls, "joystick_id", joystick_button_event_get_joystick_id, MRB_ARGS_NONE());
  mrb_define_method(mrb, joystick_button_event_cls, "button",      joystick_button_event_get_button, MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(joystick_connect_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, joystick_connect_event_cls, "initialize",  joystick_connect_event_initialize,       MRB_ARGS_NONE());
  mrb_define_method(mrb, joystick_connect_event_cls, "joystick_id", joystick_connect_event_get_joystick_id, MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(touch_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, touch_event_cls, "initialize", touch_event_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, touch_event_cls, "finger",     touch_event_get_finger, MRB_ARGS_NONE());
  mrb_define_method(mrb, touch_event_cls, "x",          touch_event_get_x,      MRB_ARGS_NONE());
  mrb_define_method(mrb, touch_event_cls, "y",          touch_event_get_y,      MRB_ARGS_NONE());

  MRB_SET_INSTANCE_TT(sensor_event_cls, MRB_TT_DATA);
  mrb_define_method(mrb, sensor_event_cls, "initialize", sensor_event_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, sensor_event_cls, "type",       sensor_event_get_type,   MRB_ARGS_NONE());
  mrb_define_method(mrb, sensor_event_cls, "x",          sensor_event_get_x,      MRB_ARGS_NONE());
  mrb_define_method(mrb, sensor_event_cls, "y",          sensor_event_get_y,      MRB_ARGS_NONE());
  mrb_define_method(mrb, sensor_event_cls, "z",          sensor_event_get_z,      MRB_ARGS_NONE());

  mrb_define_const(mrb, event_type_mod, "Closed",                 mrb_fixnum_value(sf::Event::EventType::Closed));
  mrb_define_const(mrb, event_type_mod, "Resized",                mrb_fixnum_value(sf::Event::EventType::Resized));
  mrb_define_const(mrb, event_type_mod, "LostFocus",              mrb_fixnum_value(sf::Event::EventType::LostFocus));
  mrb_define_const(mrb, event_type_mod, "GainedFocus",            mrb_fixnum_value(sf::Event::EventType::GainedFocus));
  mrb_define_const(mrb, event_type_mod, "TextEntered",            mrb_fixnum_value(sf::Event::EventType::TextEntered));
  mrb_define_const(mrb, event_type_mod, "KeyPressed",             mrb_fixnum_value(sf::Event::EventType::KeyPressed));
  mrb_define_const(mrb, event_type_mod, "KeyReleased",            mrb_fixnum_value(sf::Event::EventType::KeyReleased));
  mrb_define_const(mrb, event_type_mod, "MouseWheelMoved",        mrb_fixnum_value(sf::Event::EventType::MouseWheelMoved));
  mrb_define_const(mrb, event_type_mod, "MouseButtonPressed",     mrb_fixnum_value(sf::Event::EventType::MouseButtonPressed));
  mrb_define_const(mrb, event_type_mod, "MouseButtonReleased",    mrb_fixnum_value(sf::Event::EventType::MouseButtonReleased));
  mrb_define_const(mrb, event_type_mod, "MouseMoved",             mrb_fixnum_value(sf::Event::EventType::MouseMoved));
  mrb_define_const(mrb, event_type_mod, "MouseEntered",           mrb_fixnum_value(sf::Event::EventType::MouseEntered));
  mrb_define_const(mrb, event_type_mod, "MouseLeft",              mrb_fixnum_value(sf::Event::EventType::MouseLeft));
  mrb_define_const(mrb, event_type_mod, "JoystickButtonPressed",  mrb_fixnum_value(sf::Event::EventType::JoystickButtonPressed));
  mrb_define_const(mrb, event_type_mod, "JoystickButtonReleased", mrb_fixnum_value(sf::Event::EventType::JoystickButtonReleased));
  mrb_define_const(mrb, event_type_mod, "JoystickMoved",          mrb_fixnum_value(sf::Event::EventType::JoystickMoved));
  mrb_define_const(mrb, event_type_mod, "JoystickConnected",      mrb_fixnum_value(sf::Event::EventType::JoystickConnected));
  mrb_define_const(mrb, event_type_mod, "JoystickDisconnected",   mrb_fixnum_value(sf::Event::EventType::JoystickDisconnected));
  mrb_define_const(mrb, event_type_mod, "TouchBegan",             mrb_fixnum_value(sf::Event::EventType::TouchBegan));
  mrb_define_const(mrb, event_type_mod, "TouchMoved",             mrb_fixnum_value(sf::Event::EventType::TouchMoved));
  mrb_define_const(mrb, event_type_mod, "TouchEnded",             mrb_fixnum_value(sf::Event::EventType::TouchEnded));
  mrb_define_const(mrb, event_type_mod, "SensorChanged",          mrb_fixnum_value(sf::Event::EventType::SensorChanged));
  mrb_define_const(mrb, event_type_mod, "Count",                  mrb_fixnum_value(sf::Event::EventType::Count));
}
