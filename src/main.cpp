#include <Arduino.h>

#include "hal_arduino_esp32.h"
#include "tf_ports.h"
//#include "tf_utils.h"
#include "errors.h"

#include "tf_hat_zero.h"
#include "tf_thermocouple.h"
#include "tf_ptc_v2.h"
#include "tf_ind_analog_in_v2.h"
#include "tf_ind_analog_out_v2.h"

TF_HalContext hal;

void check(int e_code, const char *c) {
  if (e_code == TF_E_OK) {
      return;
  }

  tf_hal_printf("Failed to %s: %s (error code %d)\n", c, tf_hal_strerror(e_code), e_code);
}

// Forward declare the brick/bricklets setup and loop functions.
// TODO: Why i cannot forward declare these functions in tf_hat_zero.h / tf_thermocouple.h ?

extern "C" void hat_zero_setup(TF_HalContext *hal);
extern "C" void hat_zero_loop(TF_HalContext *hal);

extern "C" void thermocouple_setup(TF_HalContext *hal);
extern "C" void thermocouple_loop(TF_HalContext *hal);

extern "C" void ptc_setup(TF_HalContext *hal);
extern "C" void ptc_loop(TF_HalContext *hal);

extern "C" void analog_in_setup(TF_HalContext *hal);
extern "C" void analog_in_loop(TF_HalContext *hal);

extern "C" void analog_out_setup(TF_HalContext *hal);
extern "C" void analog_out_loop(TF_HalContext *hal);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  Serial.println("Hello World!");
  check(tf_hal_create(&hal, ports, sizeof(ports)/sizeof(ports[0])), "hal create");

  //setup bricklets
  hat_zero_setup(&hal);
  thermocouple_setup(&hal);
  ptc_setup(&hal);
  analog_in_setup(&hal);
  //analog_out_setup(&hal); //bricklet not shipped until now..
}

void loop() {
  // put your main code here, to run repeatedly:
  hat_zero_loop(&hal);
  thermocouple_loop(&hal);
  ptc_loop(&hal);
  analog_in_loop(&hal);
  //analog_out_loop(&hal); //bricklet not shipped until now..

  //getDeviceInfo();
  //createTraffic();

  // Poll for callbacks
	//tf_hal_callback_tick(&hal, 0);
}