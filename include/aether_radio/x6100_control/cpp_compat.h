/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Aether Xiegu X6100 Control
 *
 * SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#ifdef __cplusplus
    #include <complex>

using aether_x6100ctrl_fcomplex_t = std::complex<float>;

#else
    #include <complex.h>

typedef float complex aether_x6100ctrl_fcomplex_t;

#endif
