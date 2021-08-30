#include "tf_ind_ptc.h"

// Callback function for temperature callback
static void ptc_temperature_handler(TF_IndustrialPTC *device, int32_t temperature, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("Temperature: %d 1/%d °C\n", temperature, 100.0);
}


static TF_IndustrialPTC ptc;

void ptc_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_industrial_ptc_create(&ptc, UID_PTC, hal), "create device object");
	
	// Register temperature callback to function temperature_handler
	tf_industrial_ptc_register_temperature_callback(&ptc,
	                                        ptc_temperature_handler,
	                                        NULL);
	
	// Set period for temperature callback to 1s (1000ms) without a threshold
	tf_industrial_ptc_set_temperature_callback_configuration(&ptc, 1000, false, 'x', 0, 0);
}

void ptc_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}