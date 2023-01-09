/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Aether Xiegu X6100 Control
 *
 * SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#include "aether_radio/x6100_control/api.h"
#include "aether_radio/x6100_control/low_level/baseband_stream.h"

namespace aether_radio::x6100ctrl::low_level
{

using bb_frame_t = aether_x6100ctrl_bb_frame_t;
using bb_frame_flags_t = aether_x6100ctrl_bb_frame_flags_t;

/**
 * @brief Class that controls the serial stream from the BB STM chip.
 *
 * Making this a singleton as the control over the serial stream should be a global thing. It makes
 * no sense for there to be multiple instances of this class.
 */
class AETHER_X6100CTRL_API baseband_stream
{
  public:
    static baseband_stream &instance()
    {
        static baseband_stream instance;
        return instance;
    };

    AETHER_X6100CTRL_DISABLE_COPY_MOVE(baseband_stream)

    void start();
    void stop();

    // TODO(ruilvo): add member functions to register and unregister callbacks

  private:
    ~baseband_stream()
    {
        stop();
    }

    baseband_stream() = default;

    bool started_;
};

} // namespace aether_radio::x6100ctrl::low_level
