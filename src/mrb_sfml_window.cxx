#include <mruby.h>
#include <mruby/class.h>
#include <SFML/Window.hpp>
#include "mrb_context.hxx"
#include "mrb_context_settings.hxx"
#include "mrb_event.hxx"
#include "mrb_joystick.hxx"
#include "mrb_keyboard.hxx"
#include "mrb_mouse.hxx"
#include "mrb_sensor.hxx"
#include "mrb_touch.hxx"
#include "mrb_video_mode.hxx"
#include "mrb_window.hxx"
#include "mrb_window_style.hxx"

static struct RClass *sfml_module;

MRB_SFML_EXTERN void
mrb_mruby_sfml_window_gem_init(mrb_state *mrb)
{
  sfml_module = mrb_define_module(mrb, "SFML");
  mrb_sfml_video_mode_init_bind(mrb, sfml_module);
  mrb_sfml_context_settings_init_bind(mrb, sfml_module);
  mrb_sfml_context_init_bind(mrb, sfml_module);
  mrb_sfml_window_style_init_bind(mrb, sfml_module);
  mrb_sfml_event_init_bind(mrb, sfml_module);
  mrb_sfml_window_init_bind(mrb, sfml_module);
  /* Input Devices */
  mrb_sfml_joystick_init_bind(mrb, sfml_module);
  mrb_sfml_keyboard_init_bind(mrb, sfml_module);
  mrb_sfml_mouse_init_bind(mrb, sfml_module);
  mrb_sfml_sensor_init_bind(mrb, sfml_module);
  mrb_sfml_touch_init_bind(mrb, sfml_module);
}

MRB_SFML_EXTERN void
mrb_mruby_sfml_window_gem_final(mrb_state *mrb)
{
}
