// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    DRGSCRL = QK_KB_0, // Set drag scroll mode
    DRG_ROT,
    ROTRIG,
    ROTLFT,
};

enum keymap_layers {
    _BASE0,
    _BASE90,
    _BASE180,
    _BASE270,
    _FN0,
    _FN90,
    _FN180,
    _FN270,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE0] = LAYOUT(
        MS_BTN3, DRG_ROT,
        MS_BTN1, MS_BTN2
    ),
    [_BASE90] = LAYOUT(
        DRG_ROT, MS_BTN2,
        MS_BTN3, MS_BTN1
    ),
    [_BASE180] = LAYOUT(
        MS_BTN2, MS_BTN1,
        DRG_ROT, MS_BTN3
    ),
    [_BASE270] = LAYOUT(
        MS_BTN1, MS_BTN3,
        MS_BTN2, DRG_ROT
    ),

    [_FN0] = LAYOUT(
        ROTLFT , _______,
        _______, ROTRIG
    ),
    [_FN90] = LAYOUT(
        _______, ROTRIG,
        ROTLFT , _______
    ),
    [_FN180] = LAYOUT(
        ROTRIG, _______,
        _______, ROTLFT
    ),
    [_FN270] = LAYOUT(
        _______, ROTLFT,
        ROTRIG, _______
    ),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#if CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
#endif
}

static uint16_t rotation = 0;

#define SCROLL_DEVISOR 20.0
static float scroll_accumulated_h = 0;
static float scroll_accumulated_v = 0;

static bool drag_scrolling = false;

#define PROCESS_OVERRIDE_BEHAVIOR false
#define PROCESS_USUAL_BEHAVIOR    true
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  layer_state_t defaultlayer[] = {_BASE0, _BASE90, _BASE180, _BASE270};
  layer_state_t fnlayer[] = {_FN0, _FN90, _FN180, _FN270};

  switch (keycode) {
  case DRGSCRL:
    drag_scrolling = record->event.pressed? true: false;
    break;
  case DRG_ROT:
    if (record->event.pressed) {
      drag_scrolling = true;
      layer_move(fnlayer[rotation / 90]);
    } else {
      drag_scrolling = false;
      layer_move(defaultlayer[rotation / 90]);
    }
    return PROCESS_OVERRIDE_BEHAVIOR;
  case ROTRIG:
    if (record->event.pressed) {
      rotation = (rotation % 90 == 0)? (rotation + 90) % 360: 0;
      default_layer_set(defaultlayer[rotation / 90]);
    }
    return PROCESS_OVERRIDE_BEHAVIOR;
  case ROTLFT:
    if (record->event.pressed) {
      rotation = (rotation % 90 == 0)? (rotation + 270) % 360: 0;
      default_layer_set(defaultlayer[rotation / 90]);
    }
    return PROCESS_OVERRIDE_BEHAVIOR;
  default:
    break;
  }

  return PROCESS_USUAL_BEHAVIOR;
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
  int16_t cur_x = mouse_report.x;
  int16_t cur_y = mouse_report.y;
  int16_t cur_h = mouse_report.h;
  int16_t cur_v = mouse_report.v;
  if (rotation == 90) {
    int16_t temp = cur_x;
    cur_x = -cur_y;
    cur_y = temp;

    temp = cur_h;
    cur_h = -cur_v;
    cur_v = temp;
  } else if (rotation == 180) {
    cur_x *= -1;
    cur_y *= -1;
    cur_h *= -1;
    cur_v *= -1;
  } else if (rotation == 270) {
    int16_t temp = cur_x;
    cur_x = cur_y;
    cur_y = -temp;

    temp = cur_h;
    cur_h = cur_v;
    cur_v = -temp;
  }

  if (drag_scrolling) {
    scroll_accumulated_h += (float)cur_x / SCROLL_DEVISOR;
    scroll_accumulated_v += (float)cur_y / SCROLL_DEVISOR;
    cur_x = 0;
    cur_y = 0;
  } else {
    scroll_accumulated_h += (float)cur_h / SCROLL_DEVISOR;
    scroll_accumulated_v += (float)cur_v / SCROLL_DEVISOR;
  }

  mouse_report.x = cur_x;
  mouse_report.y = cur_y;
  mouse_report.h = (int8_t)scroll_accumulated_h;
  mouse_report.v = (int8_t)scroll_accumulated_v;

  scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
  scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
  
  return mouse_report;
}