/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg aka R1CBU
 *  Copyright (c) 2022 Rui Oliveira aka CT7ALW
 */

#include "aether_radio/x6100_control/low/control.h"

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define REFRASH_TIMEOUT (1 * 1000)

typedef struct __attribute__((__packed__))
{
    uint16_t addr;
    uint32_t arg;
} cmd_struct_t;

typedef struct __attribute__((__packed__))
{
    uint16_t addr;
    uint32_t arg[x6100_last + 1];
} all_cmd_struct_t;

static int i2c_fd = 0;
static int i2c_addr = 0x72;
static all_cmd_struct_t all_cmd;
static uint8_t cur_band = 0;

/* * */

static uint64_t get_time()
{
    struct timeval now;
    
    gettimeofday(&now, NULL);
    uint64_t usec = (uint64_t) now.tv_sec * 1000000L + now.tv_usec;

    return  usec / 1000;
}

static bool send_regs(void *regs, size_t size)
{
    int res = write(i2c_fd, regs, size);

    return (res == size);
}

bool x6100_control_init()
{
    i2c_fd = open("/dev/i2c-0", O_RDWR);

    if (i2c_fd < 0)
        return false;

    if (ioctl(i2c_fd, I2C_SLAVE, i2c_addr) < 0)
        return false;

    memset(&all_cmd, 0, sizeof(all_cmd));

    all_cmd.arg[x6100_vfoa_ham_band] = 1;
    all_cmd.arg[x6100_vfoa_freq] = 14074000;
    all_cmd.arg[x6100_vfoa_mode] = x6100_mode_usb;
    all_cmd.arg[x6100_vfoa_agc] = x6100_agc_auto;

    all_cmd.arg[x6100_vfob_ham_band] = 1;
    all_cmd.arg[x6100_vfob_freq] = 14074000;
    all_cmd.arg[x6100_vfob_mode] = x6100_mode_usb;
    all_cmd.arg[x6100_vfob_agc] = x6100_agc_auto;

    all_cmd.arg[x6100_vi_vm] = 0x00000100;
    all_cmd.arg[x6100_rxvol] = 0;
    all_cmd.arg[x6100_rfg_txpwr] = (10 << 8) | 64;
    
    all_cmd.arg[x6100_agcknee_agcslope_agchang] = 0x000006C4;
    all_cmd.arg[x6100_agctime] = 500;
    
    all_cmd.arg[x6100_filter1_low] = (uint32_t) 50.0f;
    all_cmd.arg[x6100_filter1_high] = (uint32_t) 2950.0;
    all_cmd.arg[x6100_filter2_low] = (uint32_t) 50.0f;
    all_cmd.arg[x6100_filter2_high] = (uint32_t) 2950.0f;

    all_cmd.arg[x6100_pwrsync] = 2000000;
    all_cmd.arg[x6100_last] = 0x100001;

    return send_regs(&all_cmd, sizeof(all_cmd));
}

bool x6100_control_cmd(x6100_cmd_enum_t cmd, uint32_t arg)
{
    uint64_t now = get_time();

    all_cmd.arg[cmd] = arg;

    cmd_struct_t command;
    uint16_t addr = cmd * 4;

    command.addr = (addr & 0xFF) << 8 | (addr >> 8);
    command.arg = arg;

    return send_regs(&command, sizeof(command));
}

uint32_t x6100_control_get(x6100_cmd_enum_t cmd)
{
    return all_cmd.arg[cmd];
}

void x6100_control_idle()
{
    send_regs(&all_cmd, sizeof(all_cmd));
}

// TODO: This is a reversed code. Need to translate from Chinese to normal

static uint8_t band_index(int freq)
{
    if (freq < 1800000) {
        return 0;
    } else if (freq <= 2000000) {
        return 1;
    } else if (freq < 3500000) {
        return 2;
    } else if (freq <= 4000000) {
        return 3;
    } else if (freq < 5330500) {
        return 4;
    } else if (freq <= 5405000) {
        return 5;
    } else if (freq < 7000000) {
        return 6;
    } else if (freq <= 7300000) {
        return 7;
    } else if (freq < 10100000) {
        return 8;
    } else if (freq <= 10150000) {
        return 9;
    } else if (freq < 14000000) {
        return 10;
    } else if (freq <= 14350000) {
        return 11;
    } else if (freq < 18068000) {
        return 12;
    } else if (freq <= 18168000) {
        return 13;
    } else if (freq < 21000000) {
        return 14;
    } else if (21450000 < freq) {
        if (freq < 24890000) {
            return 16;
        } else if (freq <= 24990000) {
            return 17;
        } else if (freq < 28000000) {
            return 18;
        } else if (freq > 29700000) {
            if (freq > 50000000) {
                if (freq > 54000000) {
                    return 22;
                }
                return 21;
            }
            return 20;
        }
        return 19;
    }

  return 15;
}

void x6100_control_set_band(uint32_t freq)
{
    uint8_t band = band_index(freq);

    if (band != cur_band)
    {
        cur_band = band;

        x6100_control_cmd(x6100_vi_vm, cur_band << 8);
   }
}
