#include "dmatx1.h"
#include "raw_hid.h"
#include <string.h>

static bool secondary_layout_left_shift_down = false;

const uint16_t secondary_layout_keycodes[] =
{
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
  KC_LBRC, KC_RBRC,
  KC_SCLN, KC_QUOT, KC_NUHS,
  KC_NUBS, KC_COMM, KC_DOT, KC_SLSH,
};

uint16_t secondary_layout_map_keycode(uint16_t keycode)
{
    return secondary_layout_keycodes[keycode - SL_FIRST - 1];
}

void secondary_layout_register_code(uint16_t keycode)
{
    keycode = secondary_layout_map_keycode(keycode);

    if (secondary_layout_left_shift_down)
        unregister_code(KC_LSFT);

    register_code(KC_LALT);
    register_code(KC_LSFT);
    unregister_code(KC_LALT);
    unregister_code(KC_LSFT);

    if (secondary_layout_left_shift_down)
        register_code(KC_LSFT);

    register_code(keycode);
}

void secondary_layout_unregister_code(uint16_t keycode)
{
    keycode = secondary_layout_map_keycode(keycode);

    unregister_code(keycode);

    if (secondary_layout_left_shift_down)
        unregister_code(KC_LSFT);

    register_code(KC_LALT);
    register_code(KC_LSFT);
    unregister_code(KC_LALT);
    unregister_code(KC_LSFT);

    if (secondary_layout_left_shift_down)
        register_code(KC_LSFT);
}

bool secondary_layout_process_record(uint16_t keycode, keyrecord_t* record)
{
    if (keycode == KC_LSFT)
    {
        secondary_layout_left_shift_down = record->event.pressed;
    }
    else if (keycode > SL_FIRST && keycode < SL_LAST)
    {
        if (record->event.pressed)
            secondary_layout_register_code(keycode);
        else
            secondary_layout_unregister_code(keycode);
        return false;
    }
    return true;
}

static char keebpass_buffer[KEEBPASS_BUFFER_SIZE] = { 0 };
static uint8_t keebpass_buffer_length = 0;

void keebpass_process_hid(uint8_t* data, uint8_t length)
{
    if (length > 0 && data[0] == 0xfd)
    {
        length -= 2;
        int length1 = KEEBPASS_BUFFER_SIZE - keebpass_buffer_length - 1;
        if (length1 > length)
            length1 = length;
        memcpy(keebpass_buffer + keebpass_buffer_length, data + 1, length1);
        keebpass_buffer_length += length1;
    }
}

// support VIA
__attribute__((weak)) void raw_hid_receive(uint8_t *data, uint8_t length)
{
    keebpass_process_hid(data, length);
}

// support using custom HID handler
__attribute__((weak)) void raw_hid_receive_kb(uint8_t *data, uint8_t length)
{
    keebpass_process_hid(data, length);
}

bool keebpass_process_record(uint16_t keycode, keyrecord_t* record)
{
    if ((keycode == KP_PAST || keycode == KP_PACL) && record->event.pressed)
    {
        send_string_with_delay(keebpass_buffer, 250);
        if (keycode == KP_PACL)
        {
            keebpass_buffer_length = 0;
            memset(keebpass_buffer, 0, sizeof(keebpass_buffer));
        }

        return false;
    }

    return true;
}

bool dmatx1_process_record(uint16_t keycode, keyrecord_t* record)
{
    if (!secondary_layout_process_record(keycode, record))
        return false;

    if (!keebpass_process_record(keycode, record))
        return false;

    return true;
}

bool dmatx1_process_numpad_record(uint16_t keycode, keyrecord_t* record)
{
    switch (keycode)
    {
        case KC_P1: keycode = KC_END; break;
        case KC_P2: keycode = KC_DOWN; break;
        case KC_P3: keycode = KC_PGDN; break;
        case KC_P4: keycode = KC_LEFT; break;
        case KC_P6: keycode = KC_RGHT; break;
        case KC_P7: keycode = KC_HOME; break;
        case KC_P8: keycode = KC_UP; break;
        case KC_P9: keycode = KC_PGUP; break;
        case KC_P0: keycode = KC_INS; break;
        case KC_PDOT: keycode = KC_DEL; break;

        default:
            return true;
    }

    if (host_keyboard_led_state().num_lock)
        return true;

    if (record->event.pressed)
        register_code(keycode);
    else
        unregister_code(keycode);
    return false;
}
