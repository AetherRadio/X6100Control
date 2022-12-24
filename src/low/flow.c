/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Aether Xiegu X6100 Control
 *
 *  Copyright (c) 2022 Belousov Oleg aka R1CBU
 *  Copyright (c) 2022 Rui Oliveira aka CT7ALW
 */

#include "aether_radio/x6100_control/low/flow.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define BUF_SIZE (sizeof(x6100_flow_t) * 3)

static int flow_fd;

static uint8_t *buf = NULL;
static uint8_t *buf_read = NULL;
static uint16_t buf_size = 0;

static const uint32_t magic = 0xAA5555AA;

bool x6100_flow_init()
{
    flow_fd = open("/dev/ttyS1", O_RDWR);

    if (flow_fd < 0)
        return false;

    struct termios attr;

    tcgetattr(flow_fd, &attr);

    cfsetispeed(&attr, B1152000);
    cfsetospeed(&attr, B1152000);

#if 1
    cfmakeraw(&attr);
#else
    attr.c_cflag = attr.c_cflag & 0xfffffe8f | 0x30;
    attr.c_iflag = attr.c_iflag & 0xfffffa14;
    attr.c_oflag = attr.c_oflag & 0xfffffffa;
    attr.c_lflag = attr.c_lflag & 0xffff7fb4;
#endif

    if (tcsetattr(flow_fd, 0, &attr) < 0)
    {
        close(flow_fd);
        return false;
    }

    buf = malloc(BUF_SIZE);
    buf_read = buf;
    buf_size = 0;

    return true;
}

AETHER_X6100CTRL_API bool x6100_flow_restart() {
    close(flow_fd);
    
    return x6100_flow_init();
}

static bool flow_check(x6100_flow_t *pack)
{
    uint8_t *begin = memmem(buf, buf_size, &magic, sizeof(magic));

    if (begin)
    {
        uint32_t len = buf + buf_size - begin;

        if (len >= sizeof(x6100_flow_t))
        {
            uint8_t *tail_ptr = begin + sizeof(x6100_flow_t);
            uint16_t tail_len = len - sizeof(x6100_flow_t);
            
            memcpy((void *) pack, (void *) begin, sizeof(x6100_flow_t));

            // TODO: check crc32

            memmove(buf, tail_ptr, tail_len);

            buf_read = buf + tail_len;
            buf_size = tail_len;

            return true;
        }
    }

    return false;
}

bool x6100_flow_read(x6100_flow_t *pack)
{
    if (buf_size >= BUF_SIZE)
    {
        buf_size = 0;
        buf_read = buf;
    }

    int res = read(flow_fd, buf_read, BUF_SIZE - buf_size);

    if (res > 0)
    {
        buf_size += res;
        buf_read += res;

        if (buf_size > sizeof(x6100_flow_t))
        {
            return flow_check(pack);
        }
    }

    return false;
}
