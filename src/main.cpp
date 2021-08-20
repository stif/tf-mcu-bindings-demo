#include <Arduino.h>

#include "hal_arduino_esp32.h"
#include "errors.h"
#include "ports.h"

#include "bricklet_unknown.h"
//#include "tf_hat_zero.h"
//#include "tf_thermocouple.h"


void check(int e_code, const char *c) {
  if (e_code == TF_E_OK) {
      return;
  }

  tf_hal_printf("Failed to %s: %s (error code %d)\n", c, tf_hal_strerror(e_code), e_code);
}

TF_HalContext hal;

void getDeviceInfo() {
  String result = "{\"devices\": [";
  size_t i = 0;
  char uid[7] = {0};
  char pos = 0;
  uint16_t did = 0;
  while(tf_hal_get_device_info(&hal, i, uid, &pos, &did) == TF_E_OK) {
      char buf[100] = {0};
      snprintf(buf, sizeof(buf), "%c{\"UID\":\"%s\", \"DID\":%u, \"port\":\"%c\"}", i == 0 ? ' ': ',', uid, did, pos);
      result += buf;
      ++i;
  }
  result += "]}";
  tf_hal_printf("Get Device Info:\n %s\n", result.c_str());
}

void createTraffic() {
  TF_Unknown unknown;

  for(int i = 0; i < sizeof(ports)/sizeof(ports[0]); ++i) {
    tf_unknown_create(&unknown, "1", &hal, (uint8_t)i, 0);

    int rc = tf_unknown_get_identity(&unknown, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    tf_hal_printf("RC %d: %d\n",i,rc);
    tf_unknown_destroy(&unknown);
  }
}
// Forward declare the brick/bricklets setup and loop functions.
// TODO: Why i cannot forward declare these functions in tf_hat_zero.h / tf_thermocouple.h ?
/*
extern "C" void hat_zero_setup(TF_HalContext *hal);
extern "C" void hat_zero_loop(TF_HalContext *hal);
extern "C" void thermocouple_setup(TF_HalContext *hal);
extern "C" void thermocouple_loop(TF_HalContext *hal);
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);
  Serial.println("Hello World!");
  check(tf_hal_create(&hal, ports, sizeof(ports)/sizeof(ports[0])), "hal create");
  //hat_zero_setup(&hal);
  //thermocouple_setup(&hal);
}

void loop() {
  // put your main code here, to run repeatedly:
  getDeviceInfo();
  delay(3000);
  createTraffic();
  delay(3000);
  // Poll for callbacks
	tf_hal_callback_tick(&hal, 0);
  delay(3000);
  
  /*
  hat_zero_loop(&hal);
  thermocouple_loop(&hal);
  */
}