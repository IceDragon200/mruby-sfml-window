#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Config.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/context_settings.hxx"
#include "mrb_context_settings.hxx"

static mrb_data_free_func context_settings_free = cxx_mrb_data_free<sf::ContextSettings>;
extern "C" const struct mrb_data_type mrb_sfml_context_settings_type = { "sf::ContextSettings", context_settings_free };

static inline sf::ContextSettings*
get_context_settings(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::ContextSettings*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_context_settings_type));
}

static inline struct RClass*
mrb_sfml_context_settings_class_get(mrb_state *mrb)
{
  return mrb_class_get_under(mrb, mrb_module_get(mrb, "SFML"), "ContextSettings");
}

extern "C" mrb_value
mrb_sfml_context_settings_value(mrb_state *mrb, const sf::ContextSettings &settings)
{
  mrb_value result = mrb_obj_new(mrb, mrb_sfml_context_settings_class_get(mrb), 0, NULL);
  sf::ContextSettings *ctx = get_context_settings(mrb, result);
  *ctx = settings;
  return result;
}

extern "C" void
mrb_sfml_context_settings_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *ctx_settings_cls = mrb_define_class_under(mrb, mod, "ContextSettings", mrb->object_class);
  struct RClass *ctx_settings_attr_mod = mrb_define_module_under(mrb, ctx_settings_cls, "Attribute");
  MRB_SET_INSTANCE_TT(ctx_settings_cls, MRB_TT_DATA);

  /* Present in SFML HEAD */
  /*mrb_define_const(mrb, ctx_settings_attr_mod, "Default", mrb_fixnum_value(sf::ContextSettings::Attribute::Default));
  mrb_define_const(mrb, ctx_settings_attr_mod, "Core",    mrb_fixnum_value(sf::ContextSettings::Attribute::Core));
  mrb_define_const(mrb, ctx_settings_attr_mod, "Debug",   mrb_fixnum_value(sf::ContextSettings::Attribute::Debug));*/
}
