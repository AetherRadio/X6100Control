/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg a.k.a. R1CBU
 *  Copyright (c) 2022 Rui Oliveira a.k.a. CT7ALW
 */

#include <unistd.h>

#include <aether_radio/x6100_control/control.h>
#include <aether_radio/x6100_control/low/flow.h>
#include <aether_radio/x6100_control/low/gpio.h>

int main() {
    if (!x6100_control_init())
        return 1;

    x6100_control_ptt_set(true);
    sleep(1);
    x6100_control_ptt_set(false);
}
