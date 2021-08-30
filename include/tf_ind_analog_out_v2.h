#ifndef __TF_IND_ANALOG_OUT_V2_H__
#define __TF_IND_ANALOG_OUT_V2_H__

// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "hal_common.h"
#include "bricklet_industrial_analog_out_v2.h"
#include "tf_utils.h"

#define UID_ANALOG_OUT "XYZ" // Change XYZ to the UID of your Industrial Analog Out Bricklet 2.0

void analog_out_setup(TF_HalContext *hal);
void analog_out_loop(TF_HalContext *hal);

#endif // __TF_IND_ANALOG_OUT_V2_H__