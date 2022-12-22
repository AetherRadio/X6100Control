/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg a.k.a. R1CBU
 *  Copyright (c) 2022 Rui Oliveira a.k.a. CT7ALW
 */

#include <unistd.h>
#include <stdio.h>

#include <aether_radio/x6100_control/control.h>
#include <aether_radio/x6100_control/low/flow.h>
#include <aether_radio/x6100_control/low/gpio.h>

#include <liquid/liquid.h>

static          x6100_flow_t pack;
unsigned int    nfft    = 100;
unsigned int    buf_len = 512;

int main() {
    if (!x6100_flow_init())
        return 1;

    asgramcf q = asgramcf_create(nfft);
    
    asgramcf_set_scale  (q, -80.0f, 5.0f);
    asgramcf_set_display(q, "...++++###");

    while (true) {
        if (x6100_flow_read(&pack))
        {
            asgramcf_write(q, pack.samples, buf_len);
            asgramcf_print(q);
        }
    }
}
