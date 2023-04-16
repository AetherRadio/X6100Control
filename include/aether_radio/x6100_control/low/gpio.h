/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg aka R1CBU
 *  Copyright (c) 2022 Rui Oliveira aka CT7ALW
 */

#pragma once

#include "aether_radio/x6100_control/api.h"

#include <stdbool.h>
#include <stdint.h>

AETHER_X6100CTRL_API extern int x6100_pin_wifi;
AETHER_X6100CTRL_API extern int x6100_pin_usb;
AETHER_X6100CTRL_API extern int x6100_pin_light;
AETHER_X6100CTRL_API extern int x6100_pin_morse_key;
AETHER_X6100CTRL_API extern int x6100_pin_bb_reset;

AETHER_X6100CTRL_API bool x6100_gpio_init();
AETHER_X6100CTRL_API void x6100_gpio_set(int pin, int value);
