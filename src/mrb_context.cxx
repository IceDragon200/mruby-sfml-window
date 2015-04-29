#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Context.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/context.hxx"
#include "mrb_context.hxx"

static mrb_data_free_func context_free = cxx_mrb_data_free<sf::Context>;
extern "C" const struct mrb_data_type mrb_sfml_context_type = { "sf::Context", context_free };

extern "C" void
mrb_sfml_context_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *context_class = mrb_define_class_under(mrb, mod, "Context", mrb->object_class);
  MRB_SET_INSTANCE_TT(context_class, MRB_TT_DATA);
}
