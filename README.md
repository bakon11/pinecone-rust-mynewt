<!--
#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#  KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#
-->

# Mynewt + Rust for PineCone BL602 RISC-V Board

Read the articles...

1.  [Porting Mynewt to PineCone BL602](https://lupyuen.github.io/articles/mynewt)

1.  ["Debug Rust on PineCone BL602 with VSCode and GDB"](https://lupyuen.github.io/articles/debug)

1.  ["Connect PineCone BL602 to OpenOCD"](https://lupyuen.github.io/articles/openocd)

1.  ["Quick Peek of PineCone BL602 RISC-V Evaluation Board"](https://lupyuen.github.io/articles/pinecone)

1.  ["Porting Mynewt to BL602"](https://twitter.com/MisterTechBlog/status/1338759961526951937?s=20)

# Building the Firmware

```bash
#  Download the source files
git clone --recursive https://github.com/lupyuen/pinecone-rust-mynewt
cd pinecone-rust-mynewt
newt install
#  TODO: Download xpack-riscv-none-embed-gcc here

#  Build the firmware
export PATH="$PWD/xpack-riscv-none-embed-gcc/bin:$PATH"
newt build pinecone_app
```

#  TODO

1.  BL602 MCU Definition: [`hw/mcu/bl/bl602/pkg.yml`](hw/mcu/bl/bl602/pkg.yml)

1.  PineCone Board Support Package: [`hw/bsp/pinecone/bsp.yml`](hw/bsp/pinecone/bsp.yml)

1.  Compile with `riscv-none-embed-gcc` instead of `riscv64-unknown-elf-gcc`

    See [`compiler/riscv-none-embed/compiler.yml`](compiler/riscv-none-embed/compiler.yml)

1.  Mynewt Firmware should look similar to this disassembled Hello World firmware...

    https://github.com/lupyuen/bl_iot_sdk/releases/download/v0.0.4/sdk_app_helloworld.S

1.  Mynewt Firmware should use this Start Code...

    https://github.com/lupyuen/bl_iot_sdk/blob/master/components/bl602/bl602/evb/src/boot/gcc/start.S

1.  Memory map should be...

    ```
    Name             Origin             Length             Attributes
    rom              0x0000000021015000 0x000000000000b000 axrl !w
    flash            0x0000000023000000 0x0000000000400000 axrl !w
    ram_tcm          0x000000004200c000 0x0000000000036000 axw
    ram_wifi         0x0000000042042000 0x000000000000a000 axw
    *default*        0x0000000000000000 0xffffffffffffffff
    ```

    Based on...
    
    https://github.com/lupyuen/bl_iot_sdk/releases/download/v0.0.4/sdk_app_helloworld.map

    https://github.com/lupyuen/bl_iot_sdk/blob/master/components/bl602/bl602/evb/ld/flash_rom.ld#L7-L13

1.  Fix dependency of rv32imac on fe310...

    ```
    Error: In file included from repos/apache-mynewt-core/kernel/os/include/os/os_fault.h:24,
                 from repos/apache-mynewt-core/libc/baselibc/include/assert.h:24,
                 from repos/apache-mynewt-core/hw/hal/src/hal_flash.c:21:
    repos/apache-mynewt-core/kernel/os/include/os/arch/rv32imac/os/os_arch.h:24:10: fatal error: mcu/fe310.h: No such file or directory
    #include "mcu/fe310.h"
    ```
