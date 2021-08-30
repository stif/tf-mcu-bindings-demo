#include "tf_hat_zero.h"

//extern TF_HalContext hal;

static TF_HATZero hz;


//TODO: why do i need this? there is a forward declaration in tf_thermocouple.h and check() is implemented in main.cpp
void check(int e_code, const char *c) {
  if (e_code == TF_E_OK) {
    return;
  }
  tf_hal_printf("Failed to %s: %s (error code %d)\n", c, tf_hal_strerror(e_code), e_code);

}


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
