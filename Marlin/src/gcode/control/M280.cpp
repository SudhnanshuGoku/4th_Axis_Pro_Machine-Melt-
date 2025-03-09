///**
// * Marlin 3D Printer Firmware
// * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
// *
// * Based on Sprinter and grbl.
// * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program.  If not, see <https://www.gnu.org/licenses/>.
// *
// */
//
//#include "../../inc/MarlinConfig.h"
//
//#if HAS_SERVOS
//
//#include "../gcode.h"
//#include "../../module/servo.h"
//#include "../../module/planner.h"
//
///**
// * M280: Get or set servo position.
// *  P<index> - Servo index
// *  S<angle> - Angle to set, omit to read current angle, or use -1 to detach
// *
// * With POLARGRAPH:
// *  T<ms>    - Duration of servo move
// */
//void GcodeSuite::M280() {
//
//    if (!parser.seenval('P')) return;  // Servo index required
//
//#if ENABLED(POLARGRAPH)
//    planner.synchronize();
//#endif
//
//    const int servo_index = parser.value_int();  // Get the servo index
//    if (WITHIN(servo_index, 0, NUM_SERVOS - 1)) {
//        if (parser.seenval('S')) {
//            int anew = parser.value_int();  // Target angle
//
//            if (anew >= 0 && anew <= 180) {  // Valid angle range [0, 180]
//                // Read the direction (D parameter), default to 0 if not provided
//                const int direction = parser.intval('D', 0); // D0 = clockwise, D1 = anticlockwise
//
//                if (direction == 1) {
//                    // Anticlockwise: Reverse the angle
//                    anew = 180 - anew;
//                }
//
//#if ENABLED(POLARGRAPH)
//                    if (parser.seenval('T')) { // (ms) Total duration of servo move
//            const int16_t t = constrain(parser.value_int(), 0, 10000);
//            const int aold = servo[servo_index].read();
//            millis_t now = millis();
//            const millis_t start = now, end = start + t;
//            while (PENDING(now, end)) {
//              safe_delay(50);
//              now = _MIN(millis(), end);
//              MOVE_SERVO(servo_index, LROUND(aold + (anew - aold) * (float(now - start) / t)));
//            }
//          }
//#endif // POLARGRAPH
//
//                // Move servo to the calculated angle (normal or reversed based on direction)
//                MOVE_SERVO(servo_index, anew);
//            }
//            else {
//                // Invalid angle input, do nothing or handle error
//                SERIAL_ECHO_MSG(" Invalid angle: ", anew, " (must be between 0 and 180)");
//            }
//        }
//        else {
//            // If no 'S' value is provided, just read the current servo position
//            SERIAL_ECHO_MSG(" Servo ", servo_index, ": ", servo[servo_index].read());
//        }
//    }
//    else {
//        // Error if servo index is out of range
//        SERIAL_ERROR_MSG("Servo ", servo_index, " out of range");
//    }
//}
//
//#endif // HAS_SERVOS

#include "../../inc/MarlinConfig.h"

#if HAS_SERVOS

#include "../gcode.h"
#include "../../module/servo.h"
#include "../../module/planner.h"

/**
 * M280: Get or set servo position.
 *  P<index> - Servo index
 *  S<angle> - Angle to set, omit to read current angle, or use -1 to detach
 *
 * With POLARGRAPH:
 *  T<ms>    - Duration of servo move
 */
void GcodeSuite::M280() {

    if (!parser.seenval('P')) return;

    TERN_(POLARGRAPH, planner.synchronize());

    const int servo_index = parser.value_int();
    if (WITHIN(servo_index, 0, NUM_SERVOS - 1)) {
        if (parser.seenval('S')) {
            const int anew = parser.value_int();
            if (anew >= 0) {
#if ENABLED(POLARGRAPH)
                if (parser.seenval('T')) { // (ms) Total duration of servo move
            const int16_t t = constrain(parser.value_int(), 0, 10000);
            const int aold = servo[servo_index].read();
            millis_t now = millis();
            const millis_t start = now, end = start + t;
            while (PENDING(now, end)) {
              safe_delay(50);
              now = _MIN(millis(), end);
              MOVE_SERVO(servo_index, LROUND(aold + (anew - aold) * (float(now - start) / t)));
            }
          }
#endif // POLARGRAPH
                MOVE_SERVO(servo_index, anew);
            }
            else
                DETACH_SERVO(servo_index);
        }
        else
            SERIAL_ECHO_MSG(" Servo ", servo_index, ": ", servo[servo_index].read());
    }
    else
        SERIAL_ERROR_MSG("Servo ", servo_index, " out of range");

}

#endif // HAS_SERVOS