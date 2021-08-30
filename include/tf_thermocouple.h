#ifndef __TF_THERMOCOUPLE_H__
#define __TF_THERMOCOUPLE_H__

// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "hal_common.h"
#include "bricklet_thermocouple_v2.h"

#define UID "RJH" // Change XYZ to the UID of your Thermocouple Bricklet 2.0

extern void check(int rc, const char* msg);

//TODO: why i cannot forward declare these functions here (they need to be in main.cpp!)
//void thermocouple_setup(TF_HalContext *hal);
//void thermocouple_loop(TF_HalContext *hal);

static void temperature_handler(TF_ThermocoupleV2 *device, int32_t temperature,
                                void *user_data);

#endif // __TF_THERMOCOUPLE_H__