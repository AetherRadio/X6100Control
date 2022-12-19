/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Rui Oliveira aka CT7ALW
 */

#pragma once

#ifdef __cplusplus
    #include <complex>

    #define AETHER_X6100CTLR_FCOMPLEX std::complex<float>
#else
    #include <complex.h>

    #define AETHER_X6100CTLR_FCOMPLEX complex float
#endif
