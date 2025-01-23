/****************************************************************
* Copyright (C) 2015-2019 The University of Notre Dame
* This software is distributed under the GNU General Public License.
* See the file LICENSE for details.
*****************************************************************/
/**
 * @file interrupt.c
 * @brief Interrupt handling and initialization module
 *
 * This module provides functions to initialize, register, and manage 
 * interrupts in a kernel environment. It includes exception handling,
 * hardware interrupt handling, and debugging tools to monitor interrupt
 * activity.
 * 
 * Core features:
 * - Initialization of the interrupt system
 * - Dynamic registration of interrupt handlers
 * - Management of spurious and hardware interrupts
 * - Exception handling with memory and stack checks
 * 
 * This module ensures proper interrupt handling, which is critical
 * for system responsiveness and stability.
 *
 * @author Khalid ElKoussami, Hamza Aarab, Abdelali Chattaoui, Anas Azouane, ElHassan Labyad
 * @date 23/01/2025
 *
 */

#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "interrupt.h"
#include "console.h"
#include "pic.h"
#include "process.h"
#include "kernelcore.h"
#include "x86.h"

/**
 * @brief Initializes the interrupt system
 *
 * The interrupt_init() function sets up the interrupt descriptor table (IDT),
 * initializes the programmable interrupt controller (PIC), and configures
 * handlers for hardware and exception interrupts.
 */
void interrupt_init();

/**
 * @brief Handles registered interrupts
 *
 * The interrupt_handler() function is called when an interrupt is triggered.
 * It executes the appropriate handler function for the given interrupt.
 *
 * @param i The interrupt number
 * @param code Optional error code associated with the interrupt
 */
void interrupt_handler(int i, int code);

/**
 * @brief Enables a specific interrupt
 *
 * The interrupt_enable() function enables the specified interrupt in the
 * PIC or other hardware interrupt controller.
 *
 * @param i The interrupt number to enable
 */
void interrupt_enable(int i);

/**
 * @brief Disables a specific interrupt
 *
 * The interrupt_disable() function disables the specified interrupt in the
 * PIC or other hardware interrupt controller.
 *
 * @param i The interrupt number to disable
 */
void interrupt_disable(int i);

/**
 * @brief Blocks all interrupts
 *
 * The interrupt_block() function disables interrupts globally, ensuring no
 * further interrupts are processed until re-enabled.
 */
void interrupt_block();

/**
 * @brief Unblocks all interrupts
 *
 * The interrupt_unblock() function enables interrupts globally, allowing
 * the processing of pending or new interrupts.
 */
void interrupt_unblock();

/**
 * @brief Waits for an interrupt
 *
 * The interrupt_wait() function enables interrupts and halts the processor
 * until the next interrupt occurs.
 */
void interrupt_wait();




/*
PC Interrupts:
IRQ	Interrupt
0	32	System Timer
1	33	Keyboard
2	34	Cascade
3	35	Serial Port 2
4	36	Serial Port 1
5	37	Parallel Port 2 or Sound Card
6	38	Floppy
7	39	Parallel Port 1
8	40	Real Time Clock
9	41	Network (or ATA 3)
10	42	Network/Sound/SCSI
11	43	SCSI Other (or ATA 2)
12	44	PS/2 Mouse
13	45	FPU
14	46	ATA 0
15	47	ATA 1
*/

#endif /* INTERRUPT_H */
