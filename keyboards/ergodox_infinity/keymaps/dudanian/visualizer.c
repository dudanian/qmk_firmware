
#define SIMPLE_VISUALIZER_IMMEDIATE_TRANSITION
#define SIMPLE_VISUALIZER_BACKLIGHT_BRIGHTNESS 64

#include "rgblight_list.h"
#include "simple_visualizer.h"
#include "util.h"

#include "layers.h"

#define HSV_COLOR(...) LCD_COLOR(__VA_ARGS__)

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {

  state->target_lcd_color = HSV_COLOR(HSV_WHITE);

  switch(biton32(state->status.layer)) {
    case DVORAK:
      state->layer_text = "DVORAK";
      break;
    case QWERTY:
      state->layer_text = "QWERTY";
      state->target_lcd_color = HSV_COLOR(HSV_TEAL);
      break;
    case GAMING:
      state->layer_text = "GAMING";
      state->target_lcd_color = HSV_COLOR(HSV_GREEN);
      break;
    case NUMPAD:
      state->layer_text = "NUMPAD";
      state->target_lcd_color = HSV_COLOR(HSV_ORANGE);
      break;
    case SYMBOL:
      state->layer_text = "SYMBOL";
      break;
    case ARROW:
      state->layer_text = "ARROW";
      break;
    case LOCK:
      state->layer_text = "LOCK";
      state->target_lcd_color = HSV_COLOR(HSV_RED);
      break;
    default:
      state->layer_text = "NONE?";
      break;
  }
}
