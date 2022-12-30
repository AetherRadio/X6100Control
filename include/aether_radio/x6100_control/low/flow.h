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

#define X6100_HKEY_SPCH     0xC1
#define X6100_HKEY_TUNER    0xC2
#define X6100_HKEY_XFC      0xC4
#define X6100_HKEY_UP       0x84
#define X6100_HKEY_DOWN     0x04
#define X6100_HKEY_VM       0x81
#define X6100_HKEY_NW       0x82
#define X6100_HKEY_F1       0x48
#define X6100_HKEY_F2       0x44
#define X6100_HKEY_1        0xE1
#define X6100_HKEY_2        0xE2
#define X6100_HKEY_3        0xE4
#define X6100_HKEY_4        0x61
#define X6100_HKEY_5        0x62
#define X6100_HKEY_6        0x64
#define X6100_HKEY_7        0xA1
#define X6100_HKEY_8        0xA2
#define X6100_HKEY_9        0xA4
#define X6100_HKEY_DOT      0x21
#define X6100_HKEY_0        0x22
#define X6100_HKEY_CE       0x24
#define X6100_HKEY_MODE     0xE8
#define X6100_HKEY_FIL      0x68
#define X6100_HKEY_GENE     0xA8
#define X6100_HKEY_FINP     0x28

typedef struct
{
    bool resync : 1;
    bool tx : 1;
    bool chg : 1;
    bool vext : 1;
    uint32_t : 28;
} x6100_flow_flags_t;

typedef struct __attribute__((__packed__))
{
    uint32_t magic;
    _Complex float samples[512];

    x6100_flow_flags_t flag;
    uint8_t reserved_1;
    uint8_t tx_power;
    uint8_t vswr;
    uint8_t alc_level;
    uint8_t vext;
    uint8_t vbat;
    uint8_t batcap;
    uint8_t reserved_2;
    uint32_t atu_params;
    uint32_t reserved_3[3];
    uint32_t hkey;

    uint32_t crc;
} x6100_flow_t;

/* Functions */

AETHER_X6100CTRL_API bool x6100_flow_init();

/* Usually a packet arrives every 35ms, sometimes the serial port dies. And then you have to reset it. */

AETHER_X6100CTRL_API bool x6100_flow_restart();
AETHER_X6100CTRL_API bool x6100_flow_read(x6100_flow_t *pack);
