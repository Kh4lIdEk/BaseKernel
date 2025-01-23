/****************************************************************
* Copyright (C) 2015-2019 The University of Notre Dame
* This software is distributed under the GNU General Public License.
* See the file LICENSE for details.
*****************************************************************/
/**
 * @file keyboard.c
 * @brief Keyboard input handling module
 *
 * This module provides functions to initialize and manage keyboard input 
 * in a kernel environment. It handles keypress events, processes keycodes, 
 * and manages special modes such as shift, control, and caps lock. 
 * Additionally, it maps keypresses to ASCII characters and posts 
 * corresponding events to the event queue.
 * 
 * Core features:
 * - Keyboard interrupt handling
 * - Processing of special keys and modifier states
 * - Event posting for keypresses and releases
 * - Support for directional keys and numeric keypad modes
 * 
 * This module ensures reliable and efficient processing of keyboard input
 * for kernel-level applications.
 *
 * @author Khalid ElKoussami, Hamza Aarab, Abdelali Chattaoui, Anas Azouane, ElHassan Labyad
 * @date 23/01/2025
 *
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "console.h"
#include "ioports.h"
#include "interrupt.h"
#include "kernel/ascii.h"
#include "kernelcore.h"
#include "event_queue.h"
#include "keymap.h"

/**
 * @brief Initializes the keyboard input system
 *
 * The keyboard_init() function sets up the keyboard driver by registering
 * the keyboard interrupt handler and enabling keyboard interrupts.
 */
void keyboard_init();

/**
 * @brief Handles keyboard interrupts
 *
 * The keyboard_interrupt() function is triggered by a keyboard interrupt. 
 * It processes keycodes received from the keyboard, manages modifier states, 
 * and posts appropriate events to the event queue.
 *
 * @param i The interrupt number (unused)
 * @param intr_code Optional interrupt code (unused)
 */
static void keyboard_interrupt(int i, int intr_code);

/**
 * @brief Processes keycodes and posts events
 *
 * The keyboard_interrupt_l2() function is a helper function for handling
 * specific keycodes, managing modifier states, and posting events for 
 * keypresses or releases.
 *
 * @param code The keycode received from the keyboard
 */
static void keyboard_interrupt_l2(uint8_t code);

#endif // KEYBOARD_H
