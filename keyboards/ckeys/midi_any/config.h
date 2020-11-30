/* Copyright 2019 Branden Byers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0006
#define MANUFACTURER    midi_any
#define PRODUCT         midi_any
#define DESCRIPTION     The anything MIDI controller

/* key matrix size */
#define MATRIX_ROWS 26
#define MATRIX_COLS 1

// Only go to A2 for Pro Micro
#define MATRIX_ROW_PINS { A10, B7, B6, B5, B4, B3, B2, B1, B0, B9, B15, B14, B13, B8, A0, A1, A2, A6, A7, A8, A15, A13, A14, B12, B11, B10 }
#define MATRIX_COL_PINS { A9 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 6

#define MUSIC_MAP
#define MIDI_ADVANCED

// Music Mode Polyphony
// NOTE: Must change polyphony_rate to a number higher than 0 in voices.c
#define AUDIO_VOICES
#define PITCH_STANDARD_A 880.0f

// For use on older iOS devices
#define USB_MAX_POWER_CONSUMPTION 100