// Copyright 2023 JoyLee (@itarze)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "immobile.h"
#include "color.h"

// uint8_t Shift_key_press = 0;
// uint8_t KC_GRV_key_Release_flag = 0;
enum layers {
    _LAYOUT_DEFAULT = 0,
    _LAYOUT_1,
    _LAYOUT_2,
    _LAYOUT_3,
    _LAYOUT_4,
    _LAYOUT_5,
    _LAYOUT_6,
    _LAYOUT_7,
    _LAYOUT_8,
    _LAYOUT_FUNCTION,
};

#define RGB_HSV_MAX 7
static uint8_t rgb_hsvs[7][3] = {
    {HSV_RED},
    {HSV_YELLOW},
    {HSV_GREEN},
    {HSV_CYAN},
    {HSV_BLUE},
    {HSV_PINK},
    {HSV_WHITE},
};

void rgb_matrix_indicators_val_user(void);
void rgb_matrix_decrease_val_user(void);
void rgb_matrix_disable_user(void);
void rgb_matrix_enable_user(void);
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYOUT_DEFAULT] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,    KC_GRV,KC_MUTE,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,                KC_HOME,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,               KC_UP,      KC_END,
        KC_LCTL,   KC_LGUI, KC_LALT,                            KC_SPC,KC_SPC,KC_SPC,                        MO(_LAYOUT_FUNCTION), KC_RCTL,    KC_LEFT,   KC_DOWN,    KC_RGHT),

    [_LAYOUT_1] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_2] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_3] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_4] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_5] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_6] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_7] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_8] = LAYOUT(
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,   _______,  _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,   _______, _______,                            _______,_______,_______,                            _______, _______, _______, _______, _______),

    [_LAYOUT_FUNCTION] = LAYOUT(
        EE_CLR,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_RGB_MATRIX_TOGGLE, KC_NO,KC_MUTE,
        KC_NO,     IM_BT1,  IM_BT2,  IM_BT3,  IM_2G4,  IM_USB, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_NO,   KC_NO,   QK_RGB_MATRIX_MODE_NEXT, KC_NO,
        KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SCRL, KC_PAUS, KC_HOME, KC_END,  KC_NO,   KC_NO,   QK_RGB_MATRIX_HUE_UP,          KC_NO,
        KC_NO,     KC_NO,   KC_NO,    KC_NO,    KC_NO,   QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          QK_RGB_MATRIX_VALUE_UP, KC_NO,
        KC_NO,     KC_NO,   KC_NO,                              IM_BATQ,IM_BATQ,IM_BATQ,              KC_NO,   KC_NO,   QK_RGB_MATRIX_SPEED_UP, QK_RGB_MATRIX_SPEED_DOWN, QK_RGB_MATRIX_FLAG_NEXT),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [1] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [3] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [4] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [5] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [6] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [7] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [8] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [9] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
};
#endif

// clang-format on
#ifdef RGB_MATRIX_BLINK_ENABLE
void bat_indicators_hook(uint8_t index);

blink_rgb_t blink_rgbs[RGB_MATRIX_BLINK_COUNT] = {
    {.index = IM_MM_RGB_BLINK_INDEX_BT1, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT2, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT3, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_2G4, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = RGB_MATRIX_BLINK_INDEX_BAT, .interval = 250, .times = 3, .color = {.r = 0x00, .g = 0x00, .b = 0x00}, .blink_cb = bat_indicators_hook},
    {.index = RGB_MATRIX_BLINK_INDEX_ALL, .interval = 500, .times = 5, .color = {.r = 100, .g = 100, .b = 100}, .blink_cb = NULL},
};
#endif

typedef enum {
    BAT_NORMAL,
    BAT_LOW,
    BAT_CHARGING,
    BAT_FULL,
} bat_state_t;
bat_state_t bat_state = BAT_NORMAL;

static bool bat_blink = false; // used in low battery indication
static uint16_t bat_blink_timeout = 0; // used in low battery indication

#ifdef RGB_MATRIX_BLINK_INDEX_BAT

void bat_indicators_hook(uint8_t index) {

    if (mm_eeconfig.devs != DEVS_USB) {
        if (bat_blink) {
            bat_blink_timeout = timer_read();
        }
        if (bat_state == BAT_LOW && timer_elapsed(bat_blink_timeout) > 10000) {
            rgb_matrix_blink_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_RED);
            rgb_matrix_blink_set_interval_times(index, 500, 0x3);
            bat_blink = true;
        }
        else {
            bat_blink = false;
        }

        // if ((bts_info.bt_info.pvol < 1U) && (!mm_eeconfig.charging)) {
        //     if (bat_blink_timeout == 0) bat_blink_timeout = timer_read();
        //     if (timer_elapsed(bat_blink_timeout) > 10000) {
        //         bat_blink_timeout = 0;
        //         im_set_power_off();
        //     }
        // }
        // else {
        //     bat_blink_timeout = 0;
        // }
    }
    else {
        bat_blink = false;
    }

    rgb_matrix_blink_set(index);
}

bool rgb_matrix_blink_user(blink_rgb_t* blink_rgb) {
    if (blink_rgb->index == RGB_MATRIX_BLINK_INDEX_BAT) {
        if (bat_blink != true) {
            return false;
        }
    }
    return true;
}

#endif
typedef union {
    uint32_t raw;
    struct {
        uint8_t rgb_enable : 1;
        uint8_t rgb_status : 1;
        uint8_t rgb_hsv_index : 3;
        uint8_t rgb_brightness;

    };
} confinfo_t;
confinfo_t confinfo;

#ifdef RGB_MATRIX_ENABLE

// 此函数不需要改动
// This function does not need to be modified
bool mm_get_rgb_enable(void) {
    #    ifdef RGBLIGHT_ENABLE
    return confinfo.rgb_enable;
    #    else
    return rgb_matrix_config.enable;
    #    endif
}

// 此函数不需要改动
// This function does not need to be modified
void mm_set_rgb_enable(bool state) {
    #    ifdef RGBLIGHT_ENABLE
    confinfo.rgb_enable = state;
    eeconfig_update_user(confinfo.raw);
    #    else
    rgb_matrix_config.enable = state;
    #    endif
}
#endif

void eeconfig_confinfo_default(void) {
    confinfo.rgb_enable = true;
    confinfo.rgb_status = 0;
    confinfo.rgb_hsv_index = 0;
    confinfo.rgb_brightness = RGB_MATRIX_DEFAULT_VAL;
    eeconfig_update_user(confinfo.raw);
}
bool im_led_deinit_user(void) {

    writePin(RGB_DRIVER_EN_PIN, 0);
    writePin(POWER_DCDC_EN_PIN, 0);

    return true;
}

bool im_led_init_user() {

    writePin(POWER_DCDC_EN_PIN, 1);
    writePin(RGB_DRIVER_EN_PIN, 1);
    return true;
}

// 初始化一些GPIO PIN 相关的操作
// Initialize some GPIO PIN related operations
bool im_pre_init_user(void) {
    setPinInputHigh(CHRG_PIN);
    setPinOutput(RGB_DRIVER_EN_PIN);

    setPinOutput(POWER_DCDC_EN_PIN);
    writePin(POWER_DCDC_EN_PIN, 1);

    return true;
}

static uint32_t readbatTimer = 0x00;
// 初始化和参数相关的操作，在恢复出厂设置时此函数会被调用
// Initialize and parameter related operations, this function will be called when restoring factory settings
bool im_init_user(void) {
    setPinOutput(RGB_DRIVER_EN_PIN);
    writePin(RGB_DRIVER_EN_PIN, 1);
    setPinInputHigh(CHRG_PIN);
    setPinInputHigh(FULL_PIN);

    confinfo.raw = eeconfig_read_user();
    if (!confinfo.raw) {
        eeconfig_confinfo_default();
    }
    readbatTimer = timer_read32();
    #ifdef RGB_MATRIX_BLINK_INDEX_BAT
    rgb_matrix_blink_set(RGB_MATRIX_BLINK_INDEX_BAT);
    #endif

    return true;
}

// 恢复出厂设置回调函数
// Restore factory settings callback function
bool im_reset_settings_user(void) {

    rgb_matrix_blink_set_color(RGB_MATRIX_BLINK_INDEX_ALL, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x0, 0x0);
    rgb_matrix_blink_set_interval_times(RGB_MATRIX_BLINK_INDEX_ALL, 500, 3);
    rgb_matrix_blink_set(RGB_MATRIX_BLINK_INDEX_ALL);

    return true;
}
// 无限循环
// Infinite loop

bool im_loop_user(void) {

    bool isBatteryCharging = false;
    bool isBatteryFull = false;

    if (timer_elapsed32(readbatTimer) >= 3000) {
        readbatTimer = timer_read32();
        isBatteryCharging = !readPin(CHRG_PIN) || mm_eeconfig.charging;
        isBatteryFull = !readPin(FULL_PIN);
    }
    else {
        return true;
    }

    switch (bat_state) {
    case BAT_NORMAL: {
        if (bts_info.bt_info.pvol <= BATTERY_CAPACITY_LOW) {
            bat_state = BAT_LOW;
        }
        if (isBatteryCharging) {
            bat_state = BAT_CHARGING;
            bts_send_vendor(v_bat_charging);
        }
    } break;
    case BAT_CHARGING: {
        if (isBatteryFull) {
            bat_state = BAT_FULL;
            bts_send_vendor(v_bat_full);
        }
        if (!isBatteryCharging) {
            bat_state = bts_info.bt_info.pvol <= BATTERY_CAPACITY_LOW ? BAT_LOW : BAT_NORMAL;
        }
    } break;
    case BAT_FULL: {
        if (!isBatteryFull && isBatteryCharging) {
            bat_state = BAT_CHARGING;
            bts_send_vendor(v_bat_charging);
        }
        if (!isBatteryCharging) {
            bat_state = BAT_NORMAL;
            bts_send_vendor(v_bat_stop_charging);
        }
    } break;
    case BAT_LOW: {
        if (isBatteryCharging) {
            bat_state = BAT_CHARGING;
        }
        if (!isBatteryCharging && bts_info.bt_info.pvol > BATTERY_CAPACITY_LOW) {
            bat_state = BAT_NORMAL;
        }
    } break;
    }

    return true;
}

void rgb_matrix_disable_user(void) {
    confinfo.rgb_status = 1;
    confinfo.rgb_brightness = rgb_matrix_get_val();
    eeconfig_update_user(confinfo.raw);
    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), 0);
}

void rgb_matrix_enable_user(void) {
    confinfo.rgb_status = 0;
    eeconfig_update_user(confinfo.raw);
    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), confinfo.rgb_brightness);
}

bool im_mm_rgb_blink_hook_user(uint8_t index, mm_linker_rgb_t state) {

    #if defined(RGB_MATRIX_BLINK_ENABLE) && defined(MULTIMODE_ENABLE)
    switch (state) {
    case mlrs_lback_succeed:
    case mlrs_pair_succeed: {
        im_mm_rgb_blink_set_state(mlrs_none);
        return true;
    } break;

    default:
        break;
    }
    #endif

    return true;
}

bool im_process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case QK_RGB_MATRIX_HUE_UP:
        if (record->event.pressed) {
            uint8_t now_mode_one = rgb_matrix_get_mode();
            if ((now_mode_one == 6) || (now_mode_one == 13) || (now_mode_one == 15) || (now_mode_one == 16) || (now_mode_one == 25) || (now_mode_one == 26) || (now_mode_one == 34)) {
                confinfo.rgb_hsv_index = (confinfo.rgb_hsv_index + 1) % 6;
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                    rgb_matrix_get_val());
            }
            else {
                confinfo.rgb_hsv_index = (confinfo.rgb_hsv_index + 1) % 7;
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                    rgb_matrix_get_val());
            }
            eeconfig_update_user(confinfo.raw);
        }
        return false;
        break;
    case QK_RGB_MATRIX_HUE_DOWN:
        if (record->event.pressed) {
            uint8_t now_mode_one = rgb_matrix_get_mode();
            if ((now_mode_one == 6) || (now_mode_one == 13) || (now_mode_one == 15) || (now_mode_one == 16) || (now_mode_one == 25) || (now_mode_one == 26) || (now_mode_one == 34)) {
                (confinfo.rgb_hsv_index == 0) ? (confinfo.rgb_hsv_index = 5) : (confinfo.rgb_hsv_index = confinfo.rgb_hsv_index - 1);
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                    rgb_matrix_get_val());
            }
            else {
                (confinfo.rgb_hsv_index == 0) ? (confinfo.rgb_hsv_index = 6) : (confinfo.rgb_hsv_index = confinfo.rgb_hsv_index - 1);
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                    rgb_matrix_get_val());

            }
            eeconfig_update_user(confinfo.raw);
        }
        return false;
        break;
    case QK_RGB_MATRIX_MODE_NEXT: {
        if (record->event.pressed) {
            if (rgb_matrix_get_mode() == 31) {
                rgb_matrix_mode(33);
                return false;
            }
        }
        return true;
    }break;
    case QK_RGB_MATRIX_MODE_PREVIOUS: {
        if (record->event.pressed) {
            if (rgb_matrix_get_mode() == 33) {
                rgb_matrix_mode(31);
                return false;
            }
        }
        return true;
    }break;

    case IM_BATQ: {
        return (mm_eeconfig.devs != DEVS_USB);
    }break;

    case US_TS1: { // 低频
        // Low frequency
        if (record->event.pressed) {
            bts_send_vendor(0x60);
            bts_rf_send_carrier(0, 5, 0x01);
        } break;
        return false;
    } break;
    case US_TS2: { // 中频
        // Middle frequency
        if (record->event.pressed) {
            bts_send_vendor(0x60);
            bts_rf_send_carrier(19, 5, 0x01);
        } break;
        return false;
    } break;
    case US_TS3: { // 高频
        // High frequency
        if (record->event.pressed) {
            bts_send_vendor(0x60);
            bts_rf_send_carrier(38, 5, 0x01);
        } break;
        return false;
    } break;
    case US_STOP: { // 停止
        // Stop
        if (record->event.pressed) {
            bts_rf_send_stop();
        } break;
        return false;
    } break;
    default:
        break;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE

#ifndef RGB_MATRIX_BAT_VAL
#    define RGB_MATRIX_BAT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(36, 0xff, 0xff, 0xff);
    }

    if (bat_state == BAT_CHARGING) {
        if (bts_info.bt_info.pvol < 40) {
            rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_RED);
        }
        else if (bts_info.bt_info.pvol < 90) {
            rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_ORANGE);
        }
        else {
            rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_GREEN);
        }
    }
    else if (bat_state == BAT_FULL) {
        rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_BLUE);
    }

    return true;
}
#endif
//
