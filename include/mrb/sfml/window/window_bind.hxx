#ifndef MRB_SFML_WINDOW_BIND_H
#define MRB_SFML_WINDOW_BIND_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/System/String.hpp>
#include <SFML/Window/Window.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/window.hxx"
#include "mrb/sfml/window/context_settings.hxx"
#include "mrb/sfml/window/event.hxx"
#include "mrb/sfml/window/video_mode.hxx"
#include "mrb/sfml/system/vector2.hxx"
#include "mrb/sfml/helpers.hxx"

template <class T> static inline const mrb_data_type* mrb_get_sfml_window_type();
template <> inline const mrb_data_type* mrb_get_sfml_window_type<sf::Window>() { return &mrb_sfml_window_type; }

template <class T>
static inline T*
get_window(mrb_state *mrb, mrb_value self)
{
  return cxx_mrb_data_get_ptr<T>(mrb, self);
}

/* @!class SFML::Window
 * @!method initialize
 *   @overload initialize
 *   @overload initialize(video_mode, title, style = SFML::Style::Default, context_settings = SFML::ContextSettings.new)
 *     @param [SFML::VideoMode] video_mode
 *     @param [String] title
 *     @param [SFML::Style] style
 *     @param [SFML::ContextSettings] context_settings
 */
template <class T>
static mrb_value
window_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Window *window;
  sf::VideoMode *video_mode;
  char *title;
  mrb_int style;
  sf::ContextSettings *context_settings;
  mrb_int argc = mrb_get_args(mrb, "|dzid", &video_mode, &mrb_sfml_video_mode_type,
                                            &title, &style,
                                            &context_settings, &mrb_sfml_context_settings_type);
  if (argc == 0) {
    window = new sf::Window();
  } else if (argc == 2) {
    window = new sf::Window(*video_mode, sf::String(title));
  } else if (argc == 3) {
    window = new sf::Window(*video_mode, sf::String(title), style);
  } else if (argc == 4) {
    window = new sf::Window(*video_mode, sf::String(title), style, *context_settings);
  } else {
    mrb_raise(mrb, E_RUNTIME_ERROR, "Expected 0, 2, 3, or 4 arguments.");
    return mrb_nil_value();
  }
  cxx_mrb_data_free<sf::Window>(mrb, DATA_PTR(self));
  mrb_data_init(self, window, mrb_get_sfml_window_type<T>());
  return self;
}

/* @!class SFML::Window
 * @!method create(video_mode, title, style = SFML::Style::Default, context_settings = SFML::ContextSettings.new)
 *     @param [SFML::VideoMode] video_mode
 *     @param [String] title
 *     @param [SFML::Style] style
 *     @param [SFML::ContextSettings] context_settings
 */
template <class T>
static mrb_value
window_create(mrb_state *mrb, mrb_value self)
{
  sf::VideoMode *video_mode;
  char *title;
  mrb_int style;
  sf::ContextSettings *context_settings;
  mrb_int argc = mrb_get_args(mrb, "|dzid", &video_mode, &mrb_sfml_video_mode_type,
                                            &title, &style,
                                            &context_settings, &mrb_sfml_context_settings_type);
  if (argc == 2) {
    get_window<T>(mrb, self)->create(*video_mode, sf::String(title));
  } else if (argc == 3) {
    get_window<T>(mrb, self)->create(*video_mode, sf::String(title), style);
  } else if (argc == 4) {
    get_window<T>(mrb, self)->create(*video_mode, sf::String(title), style, *context_settings);
  } else {
    mrb_raise(mrb, E_RUNTIME_ERROR, "Expected 2, 3, or 4 arguments.");
    return mrb_nil_value();
  }
  return self;
}

template <class T>
static mrb_value
window_close(mrb_state *mrb, mrb_value self)
{
  get_window<T>(mrb, self)->close();
  return self;
}

template <class T>
static mrb_value
window_is_open(mrb_state *mrb, mrb_value self)
{
  get_window<T>(mrb, self)->isOpen();
  return self;
}

template <class T>
static mrb_value
window_get_settings(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_context_settings_value(mrb, get_window<T>(mrb, self)->getSettings());
}

template <class T>
static mrb_value
window_poll_event(mrb_state *mrb, mrb_value self)
{
  sf::Event *event;
  mrb_get_args(mrb, "d", &event, &mrb_sfml_event_type);
  return mrb_bool_value(get_window<T>(mrb, self)->pollEvent(*event));
}

template <class T>
static mrb_value
window_wait_event(mrb_state *mrb, mrb_value self)
{
  sf::Event *event;
  mrb_get_args(mrb, "d", &event, &mrb_sfml_event_type);
  return mrb_bool_value(get_window<T>(mrb, self)->waitEvent(*event));
}

template <class T>
static mrb_value
window_get_position(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector2i_value(mrb, get_window<T>(mrb, self)->getPosition());
}

template <class T>
static mrb_value
window_set_position(mrb_state *mrb, mrb_value self)
{
  sf::Vector2i *vec;
  mrb_get_args(mrb, "d", &vec, &mrb_sfml_vector2i_type);
  get_window<T>(mrb, self)->setPosition(*vec);
  return self;
}

template <class T>
static mrb_value
window_get_size(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector2u_value(mrb, get_window<T>(mrb, self)->getSize());
}

template <class T>
static mrb_value
window_set_size(mrb_state *mrb, mrb_value self)
{
  sf::Vector2u *vec;
  mrb_get_args(mrb, "d", &vec, &mrb_sfml_vector2u_type);
  get_window<T>(mrb, self)->setSize(*vec);
  return self;
}

template <class T>
static mrb_value
window_set_title(mrb_state *mrb, mrb_value self)
{
  char *title;
  mrb_get_args(mrb, "z", &title);
  get_window<T>(mrb, self)->setTitle(sf::String(title));
  return self;
}

template <class T>
static mrb_value
window_set_visible(mrb_state *mrb, mrb_value self)
{
  mrb_bool visible;
  mrb_get_args(mrb, "b", &visible);
  get_window<T>(mrb, self)->setVisible(visible);
  return self;
}

template <class T>
static mrb_value
window_set_vertical_sync_enabled(mrb_state *mrb, mrb_value self)
{
  mrb_bool enabled;
  mrb_get_args(mrb, "b", &enabled);
  get_window<T>(mrb, self)->setVerticalSyncEnabled(enabled);
  return self;
}

template <class T>
static mrb_value
window_set_mouse_cursor_visible(mrb_state *mrb, mrb_value self)
{
  mrb_bool visible;
  mrb_get_args(mrb, "b", &visible);
  get_window<T>(mrb, self)->setMouseCursorVisible(visible);
  return self;
}

template <class T>
static mrb_value
window_set_key_repeat_enabled(mrb_state *mrb, mrb_value self)
{
  mrb_bool enabled;
  mrb_get_args(mrb, "b", &enabled);
  get_window<T>(mrb, self)->setKeyRepeatEnabled(enabled);
  return self;
}

template <class T>
static mrb_value
window_set_framerate_limit(mrb_state *mrb, mrb_value self)
{
  mrb_int limit;
  mrb_get_args(mrb, "i", &limit);
  get_window<T>(mrb, self)->setFramerateLimit(limit);
  return self;
}

template <class T>
static mrb_value
window_set_joystick_threshold(mrb_state *mrb, mrb_value self)
{
  mrb_float limit;
  mrb_get_args(mrb, "f", &limit);
  get_window<T>(mrb, self)->setJoystickThreshold(limit);
  return self;
}

template <class T>
static mrb_value
window_set_active(mrb_state *mrb, mrb_value self)
{
  mrb_bool enabled = true;
  mrb_get_args(mrb, "|b", &enabled);
  get_window<T>(mrb, self)->setActive(enabled);
  return self;
}

template <class T>
static mrb_value
window_request_focus(mrb_state *mrb, mrb_value self)
{
  get_window<T>(mrb, self)->requestFocus();
  return self;
}

template <class T>
static mrb_value
window_has_focus(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_window<T>(mrb, self)->hasFocus());
}

template <class T>
static mrb_value
window_display(mrb_state *mrb, mrb_value self)
{
  get_window<T>(mrb, self)->display();
  return self;
}

template <class T>
static inline void
mrb_sfml_window_bind_class(mrb_state *mrb, struct RClass *cls)
{
  mrb_define_method(mrb, cls, "initialize",                window_initialize<T>,                 MRB_ARGS_ANY());
  mrb_define_method(mrb, cls, "create",                    window_create<T>,                     MRB_ARGS_ARG(2,2));
  mrb_define_method(mrb, cls, "close",                     window_close<T>,                      MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "is_open",                   window_is_open<T>,                    MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_settings",              window_get_settings<T>,               MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "poll_event",                window_poll_event<T>,                 MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "wait_event",                window_wait_event<T>,                 MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "get_position",              window_get_position<T>,               MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "set_position",              window_set_position<T>,               MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "get_size",                  window_get_size<T>,                   MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "set_size",                  window_set_size<T>,                   MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_title",                 window_set_title<T>,                  MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_visible",               window_set_visible<T>,                MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_vertical_sync_enabled", window_set_vertical_sync_enabled<T>,  MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_mouse_cursor_visible",  window_set_mouse_cursor_visible<T>,   MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_key_repeat_enabled",    window_set_key_repeat_enabled<T>,     MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_framerate_limit",       window_set_framerate_limit<T>,        MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_joystick_threshold",    window_set_joystick_threshold<T>,     MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_active",                window_set_active<T>,                 MRB_ARGS_OPT(1));
  mrb_define_method(mrb, cls, "request_focus",             window_request_focus<T>,              MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "has_focus",                 window_has_focus<T>,                  MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "display",                   window_display<T>,                    MRB_ARGS_NONE());

  mrb_define_alias(mrb, cls, "open?", "is_open");
  mrb_define_alias(mrb, cls, "settings", "get_settings");
  mrb_define_alias(mrb, cls, "position", "get_position");
  mrb_define_alias(mrb, cls, "position=", "set_position");
  mrb_define_alias(mrb, cls, "size", "get_size");
  mrb_define_alias(mrb, cls, "size=", "set_size");
  mrb_define_alias(mrb, cls, "title=", "set_title");
  mrb_define_alias(mrb, cls, "visible=", "set_visible");
  mrb_define_alias(mrb, cls, "vertical_sync_enabled=", "set_vertical_sync_enabled");
  mrb_define_alias(mrb, cls, "mouse_cursor_visible=", "set_mouse_cursor_visible");
  mrb_define_alias(mrb, cls, "key_repeat_enabled=", "set_key_repeat_enabled");
  mrb_define_alias(mrb, cls, "framerate_limit=", "set_framerate_limit");
  mrb_define_alias(mrb, cls, "joystick_threshold=", "set_joystick_threshold");
  mrb_define_alias(mrb, cls, "active=", "set_active");
}
#endif
