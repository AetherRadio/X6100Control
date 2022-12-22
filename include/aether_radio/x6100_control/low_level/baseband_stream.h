/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg aka R1CBU
 *  Copyright (c) 2022 Rui Oliveira aka CT7ALW
 */

#pragma once

#include "aether_radio/x6100_control/cpp_compat.h"
#include "aether_radio/x6100_control/macros.h"

#include <stdbool.h>
#include <stdint.h>

#define AETHER_X6100CTRL_BB_FRAME_IQ_SAMPLES_COUNT 512
#define AETHER_X6100CTRL_BB_FRAME_MAGIC 0xAA5555AA

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        bool resync : 1;
        bool tx : 1;
        bool chg : 1;
        bool vext : 1;
        uint32_t reserved : 28;
    } aether_x6100ctrl_bb_frame_flags_t;

    typedef struct AETHER_X6100CTRL_PACKED
    {
        uint32_t magic; /*!< Every frame starts with AETHER_X6100CTRL_BB_FRAME_MAGIC */

        aether_x6100ctrl_fcomplex_t bb_iq_samples[AETHER_X6100CTRL_BB_FRAME_IQ_SAMPLES_COUNT];

        aether_x6100ctrl_bb_frame_flags_t flags;

        uint8_t reserved_1;

        uint8_t tx_power;
        uint8_t vswr;
        uint8_t alc_level;
        uint8_t vext;
        uint8_t vbat;
        uint8_t batcap;

        uint8_t reserved_2;

        uint32_t atu_params;

        uint32_t reserved_3;
        uint32_t reserved_4;
        uint32_t reserved_5;
        uint32_t reserved_6;

        uint32_t crc;
    } aether_x6100ctrl_bb_frame_t;

#ifdef __cplusplus
}
#endif
