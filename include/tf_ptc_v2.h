#ifndef __TF_PTC_V2_H__
#define __TF_PTC_V2_H__

// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "hal_common.h"
#include "bricklet_ptc_v2.h"

#define UID "TMC" // Change XYZ to the UID of your PTC Bricklet 2.0

extern void check(int rc, const char* msg);
/*
void ptc_setup(TF_HalContext *hal);
void ptc_loop(TF_HalContext *hal);
*/

static void ptc_temperature_handler(TF_PTCV2 *device, int32_t temperature, void *user_data);

#endif // __TF_PTC_V2_H__