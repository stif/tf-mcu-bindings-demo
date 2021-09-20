#include "tf_ind_relais_dual_ac.h"

static TF_IndustrialDualACRelay idr;

void relais_dual_ac_switch(bool channel1, bool channel2) {
    check(tf_industrial_dual_ac_relay_set_value(&idr, channel1, channel2), "call set_value");
}

void relais_dual_ac_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_industrial_dual_ac_relay_create(&idr, UID_RELAIS_DUAL_AC, hal), "create device object");
    
    /*
	// Turn relays alternating on/off 10 times with 1 second delay
	int i;
	for(i = 0; i < 5; ++i) {
		tf_hal_sleep_us(hal, 1000 * 1000);
		check(tf_industrial_dual_ac_relay_set_value(&idr, true, false), "call set_value");
		tf_hal_sleep_us(hal, 1000 * 1000);
		check(tf_industrial_dual_ac_relay_set_value(&idr, false, true), "call set_value");
	}
    */
}

void relais_dual_ac_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
