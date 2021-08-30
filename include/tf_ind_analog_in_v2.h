#ifndef __TF_IND_ANALOG_IN_V2_H__
#define __TF_IND_ANALOG_IN_V2_H__

// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "hal_common.h"
#include "bricklet_industrial_dual_analog_in_v2.h"

#define UID_ANALOG_IN "Sfw" // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

extern void check(int rc, const char* msg);
/*
void analog_in_setup(TF_HalContext *hal);
void analog_in_loop(TF_HalContext *hal);
*/
static void voltage_handler(TF_IndustrialDualAnalogInV2 *device, uint8_t channel,
                            int32_t voltage, void *user_data);

#endif // __TF_IND_ANALOG_IN_V2_H__