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

/* Sound settings */

AETHER_X6100CTRL_API void x6100_control_rxvol_set(uint8_t vol);
