#include "tf_hat_zero.h"

static TF_HATZero hz;

void hat_zero_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_hat_zero_create(&hz, UID_ZERO, hal), "create device object");

	// Get current voltage
	uint16_t voltage;
	check(tf_hat_zero_get_usb_voltage(&hz, &voltage), "get voltage");

	tf_hal_printf("Voltage: %d 1/%d V\n", voltage, 1000.0);
}

void hat_zero_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}