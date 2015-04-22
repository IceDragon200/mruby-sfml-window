#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/ContextSettings.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/context_settings.hxx"
#include "mrb_context_settings.hxx"

static struct RClass *context_settings_class;
static mrb_data_free_func context_settings_free = cxx_mrb_data_free<sf::ContextSettings>;
extern "C" const struct mrb_data_type mrb_sfml_context_settings_type = { "sf::ContextSettings", context_settings_free };

extern "C" void
mrb_sfml_context_settings_init_bind(mrb_state *mrb, struct RClass *mod)
{
  context_settings_class = mrb_define_class_under(mrb, mod, "ContextSettings", mrb->object_class);
  MRB_SET_INSTANCE_TT(context_settings_class, MRB_TT_DATA);
}
