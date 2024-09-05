#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define KC_LMON SGUI(KC_LEFT)
#define KC_RMON SGUI(KC_RGHT)
#define KC_CPUP LCTL(KC_PGUP)
#define KC_CPDN RCTL(KC_PGDN)
#define KC_SDEL LSFT(KC_DEL)
#define KC_ALFT LALT(KC_LEFT)
#define KC_ARGH LALT(KC_RGHT)

#define KC_KPEX HYPR(KC_F23)
#define KC_KPCP HYPR(KC_F24)

#define MT_RSFT RSFT_T(KC_UP)
#define MT_RALT RALT_T(KC_LEFT)
#define MT_RCTL RCTL_T(KC_RIGHT)
#define MT_RGUI KC_DOWN
#define LT_NUBS  LT(4, KC_LGUI)
#define MT_NUBS  LGUI_T(KC_NUBS)

#ifndef KEEBPASS_BUFFER_SIZE
#define KEEBPASS_BUFFER_SIZE 128
#endif

enum
{
  SL_FIRST = SAFE_RANGE,
  SL_GRV, SL_1, SL_2, SL_3, SL_4, SL_5, SL_6, SL_7, SL_8, SL_9, SL_0, SL_MINS, SL_EQL,
  SL_LBRC, SL_RBRC,
  SL_SCLN, SL_QUOT, SL_NUHS,
  SL_NUBS, SL_COMM, SL_DOT, SL_SLSH,

  SL_LAST,

  KP_PAST, // paste
  KP_PACL, // paste and clear buffer
};

bool secondary_layout_process_record(uint16_t keycode, keyrecord_t* record);

bool keebpass_process_record(uint16_t keycode, keyrecord_t* record);
void keebpass_process_hid(uint8_t* data, uint8_t length);

bool dmatx1_process_record(uint16_t keycode, keyrecord_t* record);
bool dmatx1_process_numpad_record(uint16_t keycode, keyrecord_t* record);

#endif
