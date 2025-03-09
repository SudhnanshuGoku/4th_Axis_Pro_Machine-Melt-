/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once
// temperature table for Abu Dhabi Printer  with Custom function add in this
// relation Eqution for the Value
#define REVERSE_TEMP_SENSOR_RANGE_201 1

// Pt100 with LMV324 amp on Overlord v1.1 electronics
constexpr temp_entry_t temptable_201[] PROGMEM = {
        { OV(  23), 369 },
        { OV(  25), 363 },
        { OV(  27), 357 },
        { OV(  28), 351 },
        { OV(  31), 344 },
        { OV(  33), 338 },
        { OV(  35), 332 },
        { OV(  38), 326 },
        { OV(  41), 319 },
        { OV(  44), 313 },
        { OV(  48), 307 },
        { OV(  52), 301 },
        { OV(  56), 294 },
        { OV(  61), 288 },
        { OV(  66), 282 },
        { OV(  71), 275 },
        { OV(  78), 269 },
        { OV(  84), 263 },
        { OV(  92), 257 },
        { OV( 100), 250 },
        { OV( 109), 244 },
        { OV( 120), 238 },
        { OV( 131), 232 },
        { OV( 143), 225 },
        { OV( 156), 219 },
        { OV( 171), 213 },
        { OV( 187), 207 },
        { OV( 205), 200 },
        { OV( 224), 194 },
        { OV( 245), 188 },
        { OV( 268), 181 },
        { OV( 293), 175 },
        { OV( 320), 169 },
        { OV( 348), 163 },
        { OV( 379), 156 },
        { OV( 411), 150 },
        { OV( 445), 144 },
        { OV( 480), 138 },
        { OV( 516), 131 },
        { OV( 553), 125 },
        { OV( 591), 119 },
        { OV( 628), 113 },
        { OV( 665), 106 },
        { OV( 702), 100 },
        { OV( 737), 94 },
        { OV( 770), 88 },
        { OV( 801), 81 },
        { OV( 830), 75 },
        { OV( 857), 69 },
        { OV( 881), 62 },
        { OV( 903), 56 },
        { OV( 922), 50 },
        { OV( 939), 44 },
        { OV( 954), 37 },
        { OV( 966), 31 },
        { OV( 977), 25 },
        { OV( 985), 19 },
        { OV( 993), 14 },  // 15°C computed as 12).33, +1.2 adjustment = 13.53 → 14
        { OV( 995), 7  },  // 10°C computed as 6.07,  +1.2 adjustment = 7.27 → 7
        { OV(999), 1  },  // 5°C computed as -0.20,  +1.2 adjustment = 0.997 → 1
        { OV(1006), -5 },  // 0°C computed as -6.46,  +1.2 adjustment = -5.26 → -5
        { OV(1012), -12},  // -5°C computed as -12.73, +1.2 adjustment = -11.53 → -12
        { OV(1016), -18},  // -10°C computed as -18.99, +1.2 adjustment = -17.79 → -18
        { OV(1020), -24}   // -15°C computed as -25.26, +1.2 adjustment = -24.06 → -24


};
