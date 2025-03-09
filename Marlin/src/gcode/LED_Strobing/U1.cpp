#include "../gcode.h"

// A flag to track whether we're in rotational mode (A-axis mode)
bool use_A_instead_of_Y = false;

void GcodeSuite::U1() {
  if (parser.seenval('S')) {
    // Set the flag to the value of S
    use_A_instead_of_Y = parser.value_bool();
    SERIAL_ECHO_START();
    SERIAL_ECHOLN(use_A_instead_of_Y ? "Switching to A-axis for Y movements" : "Using Y-axis normally");
  } else {
    SERIAL_ERROR_START();
    SERIAL_ECHOLN("Missing parameter 'S' in U1 command");
  }
}