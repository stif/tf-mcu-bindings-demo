#include "tf_utils.h"

extern TF_HalContext hal;
extern TF_Port ports[5];

void check(int e_code, const char *c) {
  if (e_code != TF_E_OK) {
      tf_hal_printf("Failed to %s: %s (error code %d)\n", c, tf_hal_strerror(e_code), e_code);
  }
}

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
