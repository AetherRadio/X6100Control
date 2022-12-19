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
#include <aether_radio/x6100_control/low/gpio.h>
#include <aether_radio/x6100_control/low/flow.h>

int main() {
    if (!x6100_control_init())
        return 1;

    if (!x6100_gpio_init())
        return 1;

    if (!x6100_flow_init())
        return 1;

    x6100_control_rxvol_set(20);

    x6100_control_vfo_mode_set(X6100_VFO_A, x6100_mode_usb_dig);
    x6100_control_vfo_agc_set(X6100_VFO_A, x6100_agc_fast);

    int count = 0;
    int band = 0;

    while (true) {
        x6100_flow_t *pack = x6100_flow_read();

        if (!pack) {
            usleep(25000);
            continue;
        }
        
        printf("[%i] tx=%d "
               "txpwr=%.1f swr=%.1f alc=%.1f vext=%.1f vbat=%.1f bat=%d CRC=%08X\n",
               count,
               pack->flag.tx, pack->tx_power * 0.1, pack->vswr * 0.1f, pack->alc_level * 0.1,
               pack->vext * 0.1f, pack->vbat * 0.1f, pack->batcap, pack->crc);
        
        if (count > 0) {
            count--;
        } else {
            switch (band) {
                case 0:
                    printf("--- Freq 7.074 MHz ---\n");
                    x6100_control_vfo_freq_set(X6100_VFO_A, 7074000);
                    break;
                
                case 1:
                    printf("--- Freq 10.100 MHz ---\n");
                    x6100_control_vfo_freq_set(X6100_VFO_A, 10100000);
                    break;
                
                case 2:
                    printf("--- Freq 14.074 MHz ---\n");
                    x6100_control_vfo_freq_set(X6100_VFO_A, 14074000);
                    break;
            }

            count = 200;
            band = (band + 1) % 3;
        }
    }
}
