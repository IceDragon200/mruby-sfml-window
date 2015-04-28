#ifndef MRB_SFML_WINDOW_BIND_H
#define MRB_SFML_WINDOW_BIND_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Window.hpp>
#include "mrb/sfml/window/window.hxx"
#include "mrb/sfml/window/video_mode.hxx"
#include "mrb/sfml/window/context_settings.hxx"

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

template <class T>
static inline void
mrb_sfml_window_bind_class(mrb_state *mrb, struct RClass *cls)
{
  mrb_define_method(mrb, cls, "initialize", window_initialize<T>, MRB_ARGS_ANY());
}
#endif
