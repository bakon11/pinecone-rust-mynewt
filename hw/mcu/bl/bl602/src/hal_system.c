/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "os/mynewt.h"
#include "hal/hal_system.h"
#include "env/platform.h"

void
hal_system_reset(void)
{
    extern void _reset_handler(void);
#if MYNEWT_VAL(HAL_SYSTEM_RESET_CB)
    hal_system_reset_cb();
#endif

    while (1) {
        HAL_DEBUG_BREAK();
        if (MYNEWT_VAL(HAL_SYSTEM_RESET_FULL)) {
            ((void (*)(void))SPI0_MEM_ADDR)();
        } else {
            _reset_handler();
        }
    }
}

int
hal_debugger_connected(void)
{
    /*
     * This always on domain register is now used to detect debugger
     * connection. openocd scripts sets magic value 0x5151A2BC when connected.
     */
    return true;  ////  TODO
    //// TODO: return AON_REG(AON_BACKUP15) == 0x5151A2BC;
}
