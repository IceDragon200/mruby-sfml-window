#ifndef MRB_SFML_CONTEXT_SETTINGS_H
#define MRB_SFML_CONTEXT_SETTINGS_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/ContextSettings.hpp>
#include "mrb/sfml/helpers.hxx"

MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_context_settings_type;
MRB_SFML_EXTERN mrb_value mrb_sfml_context_settings_value(mrb_state*, const sf::ContextSettings&);

#endif
