/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg a.k.a. R1CBU
 *  Copyright (c) 2022 Rui Oliveira a.k.a. CT7ALW
 */

#pragma once

#include <stdint.h>
#include "aether_radio/x6100_control/low/control.h"

typedef enum {
    X6100_VFO_A = 0,
    X6100_VFO_B
} x6100_vfo_t;

/* VFO Settings */

AETHER_X6100CTRL_API void x6100_control_vfo_mode_set(x6100_vfo_t vfo, x6100_mode_t mode);
AETHER_X6100CTRL_API void x6100_control_vfo_agc_set(x6100_vfo_t vfo, x6100_agc_t agc);
AETHER_X6100CTRL_API void x6100_control_vfo_freq_set(x6100_vfo_t vfo, uint32_t freq);
AETHER_X6100CTRL_API void x6100_control_vfo_att_set(x6100_vfo_t vfo, x6100_att_t att);
AETHER_X6100CTRL_API void x6100_control_vfo_pre_set(x6100_vfo_t vfo, x6100_pre_t pre);

/* Radio */

AETHER_X6100CTRL_API void x6100_control_rfg_set(uint8_t rfg);       /* RF gain 0 - 100 */
AETHER_X6100CTRL_API void x6100_control_txpwr_set(float pwr);       /* TX power 0 - 10.0 */

/* Sound settings */

AETHER_X6100CTRL_API void x6100_control_rxvol_set(uint8_t vol);     /* Speaker volume */
AETHER_X6100CTRL_API void x6100_control_record_set(bool on);        /* Toggle audio stream mic/speaker or RX/TX audio */

/* Operation */

AETHER_X6100CTRL_API void x6100_control_ptt_set(bool on);           /* Toggle PTT signal */
AETHER_X6100CTRL_API void x6100_control_atu_tune(bool on);          /* Toggle ATU tuning process */
AETHER_X6100CTRL_API void x6100_control_poweroff();                 /* Poweroff the device */
AETHER_X6100CTRL_API void x6100_control_split_set(bool on);         /* Toggle split */
AETHER_X6100CTRL_API void x6100_control_atu_set(bool on);           /* Toggle using ATU */
AETHER_X6100CTRL_API void x6100_control_modem_set(bool on);         /* Toggle serial port for SMT32 firmware update */
AETHER_X6100CTRL_API void x6100_control_swrscan_set(bool on);       /* Toggle SWR scan process */
AETHER_X6100CTRL_API void x6100_control_calibration_set(bool on);   /* Toggle calibration process after update STM32 firmware */
