#ifndef __TF_UTILS_H__
#define __TF_UTILS_H__

#include <Arduino.h>
#include "hal_common.h"
//#include "hal_arduino_esp32.h"
//#include "tf_ports.h"
//#include "bricklet_unknown.h" // for create Traffic function - tf_unknown_create()
//#include "config.h"
#include "errors.h"

void check(int e_code, const char *c);
//void getDeviceInfo();
//void createTraffic();

#endif // __TF_UTILS_H__