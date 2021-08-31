#ifndef __TF_IND_PTC_H__
#define __TF_IND_PTC_H__

// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "hal_common.h"
#include "bricklet_industrial_ptc.h"
#include "tf_utils.h"

#define UID_PTC "TMC" // Change XYZ to the UID of your PTC Bricklet 2.0

extern float ptc_temp;

void ptc_setup(TF_HalContext *hal);
void ptc_loop(TF_HalContext *hal);

//static void ptc_temperature_handler(TF_IndustrialPTC *device, int32_t temperature, void *user_data);

#endif // __TF_IND_PTC_H__