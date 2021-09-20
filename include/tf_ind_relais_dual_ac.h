#ifndef __TF_IND_RELAIS_DUAL_AC_H__
#define __TF_IND_RELAIS_DUAL_AC_H__


// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "hal_common.h"
#include "bricklet_industrial_dual_ac_relay.h"
#include "tf_utils.h"

#define UID_RELAIS_DUAL_AC "UnG" // Change XYZ to the UID of your Industrial Dual Relay Bricklet

void relais_dual_ac_switch(bool channel1, bool channel2);
void relais_dual_ac_setup(TF_HalContext *hal);
void relais_dual_ac_loop(TF_HalContext *hal);

#endif // __TF_IND_RELAIS_DUAL_AC_H__