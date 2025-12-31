// Copyright 2024 JoyLee (@itarze)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "bts_lib.h"

#ifdef GPIO_UART_ENABLE
#    include "iprint.h"
#endif

// #define GPIO_UART_ENABLE          // log打印使能 // Enable log printing
// #define MM_SLEEP_DISABLE          // 休眠禁用 // Disable sleep
// #define MM_USB_DISABLE            // 无线模式不关闭USB // Do not disable USB in wireless mode

// #define SHUTDOWN_TRIGGER_ON_KEYUP // 按键关机时抬起有效; 默认不定义，按键按下并满足条件时有效 // Shutdown on key release; by default, shutdown is triggered when key is pressed and conditions are met
// #define MM_USB_EN_PIN             // USB DP 上拉电阻电源控制引脚 // USB DP pull-up resistor power control pin
// #define MM_MODE_SW_PIN            // 两档模式切换引脚 // Two-position mode switch pin
// #define MM_BT_DEF_PIN             // 三挡模式切换蓝牙引脚 // Three-position mode switch Bluetooth pin
// #define MM_2G4_DEF_PIN            // 三挡模式切换2.4G引脚 // Three-position mode switch 2.4G pin
// #define MM_BAT_CABLE_PIN          // USB插入引脚，电池充电引脚 // USB insertion pin, battery charging pin
// #define MM_SLEEP_TIMEOUT          // 键盘无操作超时时间 // Keyboard inactivity timeout
// #define MM_STOP_DELAY             // 休眠模式切换到进入STOP模式时之间的间隔 // Interval between switching to sleep mode and entering STOP mode

// #define MM_CLEAR_KEY_DELAY        // 清除按键后的delay时间 // Delay time after clearing keys
// #define MM_MODEIO_DETECTION_TIME  // 模式切换IO检测间隔 // Mode switch IO detection interval

enum modeio_mode {
    mio_none = 0,
    mio_usb,
    mio_bt,
    mio_2g4,
    mio_wireless
};

typedef enum {
    mm_state_normal = 0, // 正常运行阶段 // Normal operation stage
    mm_state_presleep,   // 预休眠阶段，处理RGB与一些灯相关的操作 // Pre-sleep stage, handle RGB and some light-related operations
    mm_state_stop,       // 满足条件MCU进入STOP模式 // MCU enters STOP mode when conditions are met
    mm_state_wakeup,     // 唤醒阶段,恢复sleep之前的处理后修改为normal阶段 // Wakeup stage, restore pre-sleep processing then switch to normal stage
} mm_sleep_status_t;

typedef enum {
    mm_sleep_level_timeout = 0, // 键盘超时无操作休眠 // Sleep due to keyboard inactivity timeout
    mm_sleep_level_shutdown,    // 关机休眠 // Shutdown sleep
    mm_sleep_level_lowpower,    // 低电量休眠 // Low power sleep
} mm_sleep_level_t;

typedef enum {
    mm_wakeup_none = 0, // 无唤醒方式 // No wakeup method
    mm_wakeup_matrix,   // 正常矩阵唤醒 // Normal matrix wakeup
    mm_wakeup_uart,     // UART唤醒 // UART wakeup
    mm_wakeup_cable,    // USB接口插入唤醒 // Wakeup by USB cable insertion
    mm_wakeup_usb,      // USB唤醒 // USB wakeup
    mm_wakeup_onekey,   // 开关机按键唤醒 // Power key wakeup
    mm_wakeup_encoder,  // 旋钮唤醒 // Encoder wakeup
    mm_wakeup_switch,   // 波动开关唤醒 // Toggle switch wakeup
} mm_wakeupcd_t;

enum mm_sleep_timeout {
    mm_sleep_timeout_none = 0,
    mm_sleep_timeout_1min,
    mm_sleep_timeout_3min,
    mm_sleep_timeout_5min,
    mm_sleep_timeout_10min,
    mm_sleep_timeout_20min,
    mm_sleep_timeout_30min,
    mm_sleep_timeout_vendor, // Max. 7
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t devs;
        uint8_t last_devs;
        uint8_t last_btdevs;
        uint8_t charging : 1;
        uint8_t sleep_timeout : 3;
    };
} mm_eeconfig_t;

extern mm_eeconfig_t mm_eeconfig;
extern bts_info_t bts_info;

void mm_init(void);
void mm_task(void);

void mm_init_kb(void);
void mm_init_user(void);

void mm_bts_task_kb(uint8_t devs);
void mm_bts_task_user(uint8_t devs);

bool mm_mode_scan(bool update);
bool mm_switch_mode(uint8_t last_mode, uint8_t now_mode, uint8_t reset);

void mm_set_rgb_enable(bool state);
bool mm_get_rgb_enable(void);

void mm_set_to_sleep(void);
bool mm_is_to_sleep(void);

void mm_set_sleep_state(mm_sleep_status_t state);
mm_sleep_status_t mm_get_sleep_status(void);
mm_sleep_status_t mm_get_sleep_laststatus(void);
void mm_set_sleep_level(mm_sleep_level_t level);
mm_sleep_level_t mm_get_sleep_level(void);
void mm_set_sleep_wakeupcd(mm_wakeupcd_t wakeupcd);
mm_wakeupcd_t mm_get_sleep_wakeupcd(void);
void mm_reset_matrix_with_presleep(void);
bool mm_is_allow_timeout_user(void);
bool mm_is_allow_timeout(void);
bool mm_is_allow_lowpower(void);
void mm_set_lowpower(bool state);
void mm_set_shutdown(bool state);
bool mm_is_allow_shutdown(void);
bool mm_is_allow_presleep(void);
bool mm_is_allow_stop(void);
bool mm_is_allow_wakeup(void);

// 从STOP模式退出后的执行函数 timeout 休眠等级 // Function executed after exiting STOP mode, timeout sleep level
bool mm_stop_process_timeout(void);
// 从STOP模式退出后的执行函数 lowpower 休眠等级 // Function executed after exiting STOP mode, low power sleep level
bool mm_stop_process_lowpower(void);
// 从STOP模式退出后的执行函数 shutdown 休眠等级 // Function executed after exiting STOP mode, shutdown sleep level
bool mm_stop_process_shutdown(void);

void mm_update_key_press_time(void);
uint32_t mm_get_key_press_time(void);

bool mm_modeio_detection(bool update, uint8_t* mode);

bool mm_switch_mode_kb(uint8_t last_mode, uint8_t now_mode, uint8_t reset);
bool mm_switch_mode_user(uint8_t last_mode, uint8_t now_mode, uint8_t reset);

void mm_clear_all_keys(void);
bool process_record_multimode(uint16_t keycode, keyrecord_t* record);
bool process_record_multimode_kb(uint16_t keycode, keyrecord_t* record);
bool process_record_multimode_user(uint16_t keycode, keyrecord_t* record);

void eeconfig_update_multimode_default(void);

void mm_print_version(void);

void mm_pcstate_cb(uint8_t state);

void lp_system_sleep(mm_sleep_level_t sleep_level);
bool lp_isr_code_kb(uint8_t channel);
bool lp_isr_code_user(uint8_t channel);

bool process_record_usb_suspend(uint16_t keycode, keyrecord_t* record);
