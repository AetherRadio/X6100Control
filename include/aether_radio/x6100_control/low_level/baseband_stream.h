/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Aether Xiegu X6100 Control
 *
 * SPDX-FileCopyrightText: 2022 Belousov Oleg <www.strijar.ru>
 * SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#include "aether_radio/x6100_control/cpp_compat.h"

#ifndef __cplusplus
    #include <assert.h>
    #include <stdbool.h>
    #include <stdint.h>
#else
    #include <cstdint>
#endif

#define AETHER_X6100CTRL_BB_FRAME_IQ_SAMPLES_COUNT 512
#define AETHER_X6100CTRL_BB_FRAME_MAGIC 0xAA5555AA
#define AETHER_X6100CTRL_BB_FRAME_SIZE 4136

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

    /**
     * @brief De-serializing class from the baseband STM chip serial stream.
     *
     * I can't use the packed attribute for C++ compatibility here because:
     * https://stackoverflow.com/q/75042880/5168563
     * and https://gcc.gnu.org/bugzilla/show_bug.cgi?id=108342
     */
    typedef struct
    {
        /** Every frame starts with AETHER_X6100CTRL_BB_FRAME_MAGIC. */
        uint32_t magic;

        /** Baseband IQ samples. */
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

        /** The ATU params are useless to look at. */
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

// Asserts the size of `aether_x6100ctrl_bb_frame_t` is correct, i.e, corresponds to the packed
// size.
// Single liner in case the compiler doesn't have the non-macro version of static_assert.
static_assert(sizeof(aether_x6100ctrl_bb_frame_t) == AETHER_X6100CTRL_BB_FRAME_SIZE);
