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

namespace aether_radio::x6100ctrl::types
{
using fcomplex_t = aether_x6100ctrl_fcomplex_t;
} // namespace aether_radio::x6100ctrl::types

#else
    #include <complex.h>

typedef float complex aether_x6100ctrl_fcomplex_t;

#endif
