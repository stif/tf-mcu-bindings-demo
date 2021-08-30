#include "tf_ind_analog_out_v2.h"

static TF_IndustrialAnalogOutV2 iao;

void analog_out_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_industrial_analog_out_v2_create(&iao, UID_ANALOG_OUT, hal), "create device object");

	// Set output current to 4.5mA
	check(tf_industrial_analog_out_v2_set_current(&iao, 4500), "call set_current");
	check(tf_industrial_analog_out_v2_set_enabled(&iao, true), "call set_enabled");
}

void analog_out_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
