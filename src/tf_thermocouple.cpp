#include "tf_thermocouple.h"

// Callback function for temperature callback
static void temperature_handler(TF_ThermocoupleV2 *device, int32_t temperature,
//void temperature_handler(TF_ThermocoupleV2 *device, int32_t temperature,
                                void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	//tf_hal_printf("Temperature: %d 1/%d °C\n", temperature, 100.0);
	thermo_temp = (float) temperature / 100;
}

static TF_ThermocoupleV2 t;

void thermocouple_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_thermocouple_v2_create(&t, UID_THERMOCOUPLE, hal), "create device object");

	// Register temperature callback to function temperature_handler
	tf_thermocouple_v2_register_temperature_callback(&t,
	                                                 temperature_handler,
	                                                 NULL);

	// Set period for temperature callback to 1s (1000ms) without a threshold
	tf_thermocouple_v2_set_temperature_callback_configuration(&t, 1000, false, 'x', 0, 0);
}

void thermocouple_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
