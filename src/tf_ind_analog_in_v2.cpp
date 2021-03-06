#include "tf_ind_analog_in_v2.h"

// Callback function for voltage callback
static void voltage_handler(TF_IndustrialDualAnalogInV2 *device, uint8_t channel,
                            int32_t voltage, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	/*
	tf_hal_printf("Channel: %I8u\n", channel);
	tf_hal_printf("Voltage: %d 1/%d V\n", voltage, 1000.0);
	tf_hal_printf("\n");
	*/
	analog_in_voltage = voltage / 1000;
}
static TF_IndustrialDualAnalogInV2 idai;

void analog_in_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_industrial_dual_analog_in_v2_create(&idai, UID_ANALOG_IN, hal), "create device object");

	// Register voltage callback to function voltage_handler
	tf_industrial_dual_analog_in_v2_register_voltage_callback(&idai,
	                                                          voltage_handler,
	                                                          NULL);

	// Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
	tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration(&idai, 0, 1000, false, 'x', 0, 0);
}

void analog_in_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
