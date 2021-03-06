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

#ifndef __MCU_PLIC_H_
#define __MCU_PLIC_H_

//  BL602 doesn't have a PLIC like FE310. We stub out the functions.
#define PLIC_REG(x)          unused_plic_reg
#define PLIC_PRIORITY_OFFSET 0
#define PLIC_ENABLE_OFFSET   0

#ifdef __cplusplus
extern "C" {
#endif

extern int unused_plic_reg;

typedef void (* interrupt_handler_t)(int num);
/*
 * External interrupt table
 */
extern interrupt_handler_t plic_interrupts[];

/*
 * Set handler for extern interrupt
 */
void plic_set_handler(int int_num, interrupt_handler_t handler, int priority);

/* Enable exteral interrupt at PLIC */
void plic_enable_interrupt(int int_num);

/* Disable exteral interrupt at PLIC */
void plic_disable_interrupt(int int_num);

#ifdef __cplusplus
}
#endif

#endif /* __MCU_PLIC_H_ */
