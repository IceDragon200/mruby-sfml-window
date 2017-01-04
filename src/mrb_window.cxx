#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Window.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/window.hxx"
#include "mrb/sfml/window/window_bind.hxx"
#include "mrb_window.hxx"

static mrb_data_free_func window_free = cxx_mrb_data_free<sf::Window>;
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_window_type = { "sf::Window", window_free };

MRB_SFML_EXTERN void
mrb_sfml_window_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass * window_class = mrb_define_class_under(mrb, mod, "Window", mrb->object_class);
  MRB_SET_INSTANCE_TT(window_class, MRB_TT_DATA);
  mrb_sfml_window_bind_class<sf::Window>(mrb, window_class);
}
