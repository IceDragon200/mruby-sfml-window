#ifndef MRB_SFML_CONTEXT_SETTINGS_PRIV_H
#define MRB_SFML_CONTEXT_SETTINGS_PRIV_H

#include <mruby.h>
#include <mruby/class.h>

extern "C" void mrb_sfml_context_settings_init_bind(mrb_state *mrb, struct RClass *mod);

#endif