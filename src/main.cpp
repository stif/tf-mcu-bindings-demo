#include <Arduino.h>

#include "hal_arduino_esp32.h"
#include "tf_ports.h"
#include "tf_utils.h"

#include "tf_hat_zero.h"
#include "tf_thermocouple.h"
#include "tf_ind_ptc.h"
#include "tf_ind_analog_in_v2.h"
#include "tf_ind_analog_out_v2.h"
#include "tf_ind_relais_dual.h"
#include "tf_ind_relais_dual_ac.h"

TF_HalContext hal;

unsigned long loopTimeDelay = 0;

float thermo_temp = -1;
float ptc_temp = -1;
float analog_in_voltage = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  check(tf_hal_create(&hal, ports, sizeof(ports)/sizeof(ports[0])), "hal create");

  //setup bricklets
  //hat_zero_setup(&hal);
  thermocouple_setup(&hal);
  ptc_setup(&hal);
  analog_in_setup(&hal);
  //analog_out_setup(&hal); //bricklet not shipped until now..
  //relais_dual_setup(&hal);
  relais_dual_ac_setup(&hal);

  delay(1000);
  getDeviceInfo();
}

void loop() {
  static bool state;
  // put your main code here, to run repeatedly:
  //createTraffic();

  // Poll for callbacks
	tf_hal_callback_tick(&hal, 100);

  if((millis() - loopTimeDelay) > 1000) {  // Only process counters once per 1 second
    loopTimeDelay = millis();
    Serial.printf("Temperature Thermocoupler: %.2f\n", thermo_temp);
    Serial.printf("Temperature PTC: %.2f\n", ptc_temp);
    Serial.printf("Voltage: %f\n", analog_in_voltage);
    state = !state;
    //relais_dual_switch(state, false); //cannel1, channel2
    relais_dual_ac_switch(state, false); //cannel1, channel2
  }
}