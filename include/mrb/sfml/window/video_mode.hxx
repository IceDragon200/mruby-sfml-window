#ifndef MRB_SFML_VIDEO_MODE_H
#define MRB_SFML_VIDEO_MODE_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/VideoMode.hpp>
#include "mrb/sfml/helpers.hxx"

MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_video_mode_type;

static inline sf::VideoMode*
mrb_sfml_video_mode_ptr(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::VideoMode*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_video_mode_type));
}

#endif
