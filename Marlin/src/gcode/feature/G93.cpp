#include "../gcode.h"
#include "../../module/motion.h"


#if ENABLED(I2C_POSITION_ENCODERS)
  #include "../../feature/encoder_i2c.h"
#endif


void GcodeSuite::G93() {

  int count = 0;
  SERIAL_ECHO_START();
  {
    SERIAL_ECHOPGM("PINS:{");
    #ifdef CUSTOM_LED_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("LED:P",CUSTOM_LED_PIN);
    #endif
    #ifdef CUSTOM_UV_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("UV:P",CUSTOM_UV_PIN);
    #endif
    #ifdef CUSTOM_HEPA_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("HEPA:P",CUSTOM_HEPA_PIN);
    #endif
    #ifdef CUSTOM_FAN_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("FAN:P",CUSTOM_FAN_PIN);
    #endif
    #ifdef CUSTOM_CLE0_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE0:P",CUSTOM_CLE0_PIN);
    #endif
    #ifdef CUSTOM_CLE1_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE1:P",CUSTOM_CLE1_PIN);
    #endif
    #ifdef CUSTOM_CLE2_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE2:P",CUSTOM_CLE2_PIN);
    #endif
    #ifdef CUSTOM_CLE3_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE3:P",CUSTOM_CLE3_PIN);
    #endif
    #ifdef CUSTOM_CLE4_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE4:P",CUSTOM_CLE4_PIN);
    #endif
    #ifdef CUSTOM_CLE5_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE5:P",CUSTOM_CLE5_PIN);
    #endif
    #ifdef CUSTOM_HEATBED
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("BED:P",CUSTOM_HEATBED);
    #endif
    #ifdef CUSTOM_HEATE0
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E0:P",CUSTOM_HEATE0);
    #endif
    #ifdef CUSTOM_HEATE1
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E1:P",CUSTOM_HEATE1);
    #endif
    #ifdef CUSTOM_HEATE2
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E2:P",CUSTOM_HEATE2);
    #endif
    #ifdef CUSTOM_HEATE3
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E3:P",CUSTOM_HEATE3);
    #endif
    #ifdef CUSTOM_HEATE4
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E4:P",CUSTOM_HEATE4);
    #endif
    #ifdef CUSTOM_HEATE5
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E5:P",CUSTOM_HEATE5);
    #endif
    SERIAL_ECHOLNPGM("}");
  }

  count = 0;

  {
    SERIAL_ECHOPGM("ON/OFF:{");
    #ifdef CUSTOM_LED_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("LED:",CUSTOM_LED_STATE);
    #endif
    #ifdef CUSTOM_UV_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("UV:",CUSTOM_UV_STATE);
    #endif
    #ifdef CUSTOM_HEPA_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("HEPA:",CUSTOM_HEPA_STATE);
    #endif
    #ifdef CUSTOM_FAN_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("FAN:",CUSTOM_FAN_STATE);
    #endif
    #ifdef CUSTOM_CLE0_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE0:",CUSTOM_CLE0_STATE);
    #endif
    #ifdef CUSTOM_CLE1_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE1:",CUSTOM_CLE1_STATE);
    #endif
    #ifdef CUSTOM_CLE2_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE2:",CUSTOM_CLE2_STATE);
    #endif
    #ifdef CUSTOM_CLE3_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE3:",CUSTOM_CLE3_STATE);
    #endif
    #ifdef CUSTOM_CLE4_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE4:",CUSTOM_CLE4_STATE);
    #endif
    #ifdef CUSTOM_CLE5_PIN
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("CLE5:",CUSTOM_CLE5_STATE);
    #endif
    #ifdef CUSTOM_HEATBED
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("BED:",CUSTOM_BED_STATE);
    #endif
    #ifdef CUSTOM_HEATE0
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E0:",CUSTOM_E0_STATE);
    #endif
    #ifdef CUSTOM_HEATE1
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E1:",CUSTOM_E1_STATE);
    #endif
    #ifdef CUSTOM_HEATE2
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E2:",CUSTOM_E2_STATE);
    #endif
    #ifdef CUSTOM_HEATE3
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E3:",CUSTOM_E3_STATE);
    #endif
    #ifdef CUSTOM_HEATE4
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E4:",CUSTOM_E4_STATE);
    #endif
    #ifdef CUSTOM_HEATE5
      if (count > 0) SERIAL_ECHOPGM(",");
      count ++;
      SERIAL_ECHOPGM("E5:",CUSTOM_E5_STATE);
    #endif
    SERIAL_ECHOLNPGM("}");
  }

}
