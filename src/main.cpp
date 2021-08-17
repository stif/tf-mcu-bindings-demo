#include <Arduino.h>

#include "hal_arduino_esp32.h"
#include "errors.h"
#include "ports.h"

#include "tf_hat_zero.h"
#include "tf_thermocouple.h"


void check(int e_code, const char *c) {
  if (e_code == TF_E_OK) {
      return;
  }

  tf_hal_printf("Failed to %s: %s (error code %d)\n", c, tf_hal_strerror(e_code), e_code);
}

TF_HalContext hal;

// Forward declare the brick/bricklets setup and loop functions.
// TODO: Why i cannot forward declare these functions in tf_hat_zero.h / tf_thermocouple.h ?
extern "C" void hat_zero_setup(TF_HalContext *hal);
extern "C" void hat_zero_loop(TF_HalContext *hal);
extern "C" void thermocouple_setup(TF_HalContext *hal);
extern "C" void thermocouple_loop(TF_HalContext *hal);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  Serial.println("Hello World!");
  check(tf_hal_create(&hal, ports, sizeof(ports)/sizeof(ports[0])), "hal create");
  hat_zero_setup(&hal);
  thermocouple_setup(&hal);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Poll for callbacks
	tf_hal_callback_tick(&hal, 0);
  /*
  hat_zero_loop(&hal);
  thermocouple_loop(&hal);
  */
}