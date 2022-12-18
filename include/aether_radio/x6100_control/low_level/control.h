/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg a.k.a. R1CBU
 *  Copyright (c) 2022 Rui Oliveira a.k.a. CT7ALW
 */

#pragma once

#include "aether_radio/x6100_control/api.h"

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Xiegu X6100 Control Commands
 *
 * This enum contains all the commands that can be sent to the Xiegu X6100 that have been discovered
 * so far.
 *
 */
typedef enum
{
    aether_x6100ctrl_vfoa_ham_band = 0, /*!< VFO-A band. */
    aether_x6100ctrl_vfoa_freq, /*!< VFO-A frequency (integer Hz). */
    aether_x6100ctrl_vfoa_att, /*!< VFO-A ATT (attenuator). */
    aether_x6100ctrl_vfoa_pre, /*!< VFO-A pre-amp. */
    aether_x6100ctrl_vfoa_mode, /*!< VFO-A mode (modem). */
    aether_x6100ctrl_vfoa_agc, /*!< VFO-A AGC mode. */

    aether_x6100ctrl_vfob_ham_band = 6, /*!< VFO-B band. */
    aether_x6100ctrl_vfob_freq, /*!< VFO-B frequency (integer Hz). */
    aether_x6100ctrl_vfob_att, /*!< VFO-B ATT (attenuator). */
    aether_x6100ctrl_vfob_pre, /*!< VFO-B pre-amp. */
    aether_x6100ctrl_vfob_mode, /*!< VFO-B mode (modem). */
    aether_x6100ctrl_vfob_agc, /*!< VFO-B AGC mode. */

    aether_x6100ctrl_sple_atue_trx = 12,
    aether_x6100ctrl_vi_vm,
    aether_x6100ctrl_rxvol,
    aether_x6100ctrl_rfg_txpwr,

    aether_x6100ctrl_atu_network = 17,

    aether_x6100ctrl_ling_loutg_imicg_hmicg = 20,
    aether_x6100ctrl_micsel_pttmode_chge_spmode_auxiqgen_sqlthr,
    aether_x6100ctrl_voxg_voxag_voxdly_voxe,
    aether_x6100ctrl_nrthr_nbw_nbthr_nre_nbe,
    aether_x6100ctrl_dnfcnt_dnfwidth_dnfe,
    aether_x6100ctrl_cmplevel_cmpe,

    aether_x6100ctrl_agcknee_agcslope_agchang = 27,
    aether_x6100ctrl_mode,
    aether_x6100ctrl_monilevel,

    aether_x6100ctrl_ks_km_kimb_cwtone_cwvol_cwtrain = 33,
    aether_x6100ctrl_qsktime_kr,

    aether_x6100ctrl_biasdrive_biasfinal = 41,
    aether_x6100ctrl_rit,
    aether_x6100ctrl_xit,
    aether_x6100ctrl_filter1_low,
    aether_x6100ctrl_filter1_high,
    aether_x6100ctrl_filter2_low,
    aether_x6100ctrl_filter2_high,

    aether_x6100ctrl_rphscmp = 48,
    aether_x6100ctrl_rmagcmp,
    aether_x6100ctrl_txiofs,
    aether_x6100ctrl_txqofs,

    aether_x6100ctrl_pwrsync = 53,
    aether_x6100ctrl_last = 55
} aether_x6100ctr_cmds_t;

enum
{
    aether_x6100ctrl_agc_off = 0,
    aether_x6100ctrl_agc_slow = 1,
    aether_x6100ctrl_agc_fast = 2,
    aether_x6100ctrl_agc_auto = 3
};

enum
{
    aether_x6100ctrl_att_off = 0,
    aether_x6100ctrl_att_on = 1
};

enum
{
    aether_x6100ctrl_mode_lsb = 0,
    aether_x6100ctrl_mode_lsb_dig = 1,
    aether_x6100ctrl_mode_usb = 2,
    aether_x6100ctrl_mode_usb_dig = 3,
    aether_x6100ctrl_mode_cw = 4,
    aether_x6100ctrl_mode_cwr = 5,
    aether_x6100ctrl_mode_am = 6,
    aether_x6100ctrl_mode_nfm = 7
};

enum
{
    aether_x6100ctrl_pre_off = 0,
    aether_x6100ctrl_pre_on = 1
};

enum
{
    aether_x6100ctrl_sple = 0x00002,
    aether_x6100ctrl_voice_rec = 0x00008,
    aether_x6100ctrl_swrscan_trx = 0x00010,
    aether_x6100ctrl_atue = 0x01000,
    aether_x6100ctrl_atu_tune = 0x02000,
    aether_x6100ctrl_trx = 0x04000,
    aether_x6100ctrl_calibration_trx = 0x08000,
    aether_x6100ctrl_power_off = 0x10000,
    aether_x6100ctrl_iptt = 0x40000
};

/* Functions */

AETHER_X6100CTRL_API bool aether_x6100ctrl_control_init();
AETHER_X6100CTRL_API bool aether_x6100ctrl_control_cmd(aether_x6100ctr_cmds_t cmd, uint32_t arg);
AETHER_X6100CTRL_API void aether_x6100ctrl_control_idle();
AETHER_X6100CTRL_API void aether_x6100ctrl_control_set_band(uint32_t freq);
