#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/Event.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/event.hxx"
#include "mrb_event.hxx"

static struct RClass *event_class;
static mrb_data_free_func event_free = cxx_mrb_data_free<sf::Event>;
extern "C" const struct mrb_data_type mrb_sfml_event_type = { "sf::Event", event_free };

extern "C" void
mrb_sfml_event_init_bind(mrb_state *mrb, struct RClass *mod)
{
  event_class = mrb_define_class_under(mrb, mod, "Event", mrb->object_class);
  MRB_SET_INSTANCE_TT(event_class, MRB_TT_DATA);
}
