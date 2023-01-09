/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Aether Xiegu X6100 Control
 *
 * SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#define AETHER_X6100CTRL_PACKED __attribute__((__packed__))

#ifdef __cplusplus

    #define AETHER_X6100CTRL_DISABLE_COPY(some_class) \
        some_class(const some_class &) = delete;      \
        some_class &operator=(const some_class &) = delete;
    #define AETHER_X6100CTRL_DISABLE_MOVE(some_class) \
        some_class(some_class &&) = delete;           \
        some_class &operator=(some_class &&) = delete;

    #define AETHER_X6100CTRL_DISABLE_COPY_MOVE(some_class) \
        AETHER_X6100CTRL_DISABLE_COPY(some_class)          \
        AETHER_X6100CTRL_DISABLE_MOVE(some_class)

#endif
