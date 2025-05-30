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

/**
 * module/servo.cpp
 */

#include "../inc/MarlinConfig.h"

#if HAS_SERVOS

#include "servo.h"

hal_servo_t servo[NUM_SERVOS];

#if ENABLED(EDITABLE_SERVO_ANGLES)
  uint16_t servo_angles[NUM_SERVOS][2];
#endif

void servo_init() {
  #if NUM_SERVOS >= 1 && HAS_SERVO_0
    servo[0].attach(SERVO0_PIN);
//    servo[0].move(180);
    DETACH_SERVO(0); // Just set up the pin. We don't have a position yet. Don't move to a random position.
  #endif
  #if NUM_SERVOS >= 2 && HAS_SERVO_1
    servo[1].attach(SERVO1_PIN);
    DETACH_SERVO(1);
  #endif
  #if NUM_SERVOS >= 3 && HAS_SERVO_2
    servo[2].attach(SERVO2_PIN);
    DETACH_SERVO(2);
  #endif
  #if NUM_SERVOS >= 4 && HAS_SERVO_3
    servo[3].attach(SERVO3_PIN);
    DETACH_SERVO(3);
  #endif
  #if NUM_SERVOS >= 5 && HAS_SERVO_4
    servo[4].attach(SERVO4_PIN);
    DETACH_SERVO(4);
  #endif
  #if NUM_SERVOS >= 6 && HAS_SERVO_5
    servo[5].attach(SERVO5_PIN);
    DETACH_SERVO(5);
  #endif
  #if NUM_SERVOS >= 7 && HAS_SERVO_6
    servo[6].attach(SERVO6_PIN);
    DETACH_SERVO(6);
  #endif
}

#endif // HAS_SERVOS
