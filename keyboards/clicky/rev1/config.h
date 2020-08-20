/*
Copyright 2020 (c) Sergej Kravcenko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    codewaves
#define PRODUCT         Clicky Keyboard
#define DESCRIPTION     Split 40 percent ergonomic keyboard

/* Key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 0

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2

#define RGB_DI_PIN D3
#define RGBLED_SPLIT { 27, 27 }
#define RGBLED_NUM 54

// 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
#define RGBLIGHT_LED_MAP {  42,43,44,45,46,47,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0, \
                            48,49,50,51,52,53,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
