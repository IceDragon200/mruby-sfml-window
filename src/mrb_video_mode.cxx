#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/VideoMode.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/video_mode.hxx"
#include "mrb_video_mode.hxx"

static struct RClass *video_mode_class;
static mrb_data_free_func video_mode_free = cxx_mrb_data_free<sf::VideoMode>;
extern "C" const struct mrb_data_type mrb_sfml_video_mode_type = { "sf::VideoMode", video_mode_free };

extern "C" void
mrb_sfml_video_mode_init_bind(mrb_state *mrb, struct RClass *mod)
{
  video_mode_class = mrb_define_class_under(mrb, mod, "VideoMode", mrb->object_class);
  MRB_SET_INSTANCE_TT(video_mode_class, MRB_TT_DATA);
}
