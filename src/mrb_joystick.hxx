#ifndef MRB_SFML_JOYSTICK_PRIV_H
#define MRB_SFML_JOYSTICK_PRIV_H

#include <mruby.h>
#include <mruby/class.h>

extern "C" void mrb_sfml_joystick_init_bind(mrb_state *mrb, struct RClass *mod);

#endif