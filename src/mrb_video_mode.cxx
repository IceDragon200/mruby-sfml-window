#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Window/VideoMode.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/window/video_mode.hxx"
#include "mrb_video_mode.hxx"

static mrb_data_free_func video_mode_free = cxx_mrb_data_free<sf::VideoMode>;
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_video_mode_type = { "sf::VideoMode", video_mode_free };

static mrb_value
video_mode_initialize(mrb_state *mrb, mrb_value self)
{
  mrb_int width;
  mrb_int height;
  mrb_int bits_per_pixel;
  sf::VideoMode *video_mode = NULL;
  mrb_int argc = mrb_get_args(mrb, "|iii", &width, &height, &bits_per_pixel);
  video_mode_free(mrb, DATA_PTR(self));

  if (argc == 0) {
    video_mode = new sf::VideoMode();
  } else if (argc == 2) {
    video_mode = new sf::VideoMode(width, height);
  } else if (argc == 3) {
    video_mode = new sf::VideoMode(width, bits_per_pixel);
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "expected 0, 2, or 3 arguments");
  }

  mrb_data_init(self, video_mode, &mrb_sfml_video_mode_type);
}

static mrb_value
video_mode_get_width(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_video_mode_ptr(mrb, self)->width);
}

static mrb_value
video_mode_get_height(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_video_mode_ptr(mrb, self)->height);
}

static mrb_value
video_mode_get_bits_per_pixel(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_video_mode_ptr(mrb, self)->bitsPerPixel);
}

MRB_SFML_EXTERN void
mrb_sfml_video_mode_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *video_mode_class = mrb_define_class_under(mrb, mod, "VideoMode", mrb->object_class);
  MRB_SET_INSTANCE_TT(video_mode_class, MRB_TT_DATA);

  mrb_define_method(mrb, video_mode_class, "initialize",     video_mode_initialize,         MRB_ARGS_ARG(0,3));
  mrb_define_method(mrb, video_mode_class, "width",          video_mode_get_width,          MRB_ARGS_NONE());
  mrb_define_method(mrb, video_mode_class, "height",         video_mode_get_height,         MRB_ARGS_NONE());
  mrb_define_method(mrb, video_mode_class, "bits_per_pixel", video_mode_get_bits_per_pixel, MRB_ARGS_NONE());
}
