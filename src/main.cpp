#include <Arduino.h>

#include "hal_arduino_esp32.h"
#include "tf_ports.h"
#include "tf_utils.h"

#include "tf_thermocouple.h"
#include "tf_hat_zero.h"
#include "tf_ind_ptc.h"
#include "tf_ind_analog_in_v2.h"
#include "tf_ind_analog_out_v2.h"

TF_HalContext hal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  check(tf_hal_create(&hal, ports, sizeof(ports)/sizeof(ports[0])), "hal create");

  //setup bricklets
  hat_zero_setup(&hal);
  thermocouple_setup(&hal);
  ptc_setup(&hal);
  analog_in_setup(&hal);
  //analog_out_setup(&hal); //bricklet not shipped until now..

  delay(1000);
  getDeviceInfo();
}

void loop() {
  // put your main code here, to run repeatedly:
  //createTraffic();

  // Poll for callbacks
	tf_hal_callback_tick(&hal, 0);
}