#ifndef __PORTS_H__
#define __PORTS_H__

#include "hal_arduino_esp32.h"

// Change this to your port assignment.
// If you use a HAT or one or more Breakout Bricklets
// you have to connect and list all chip select
// signals, to make sure the signals are separated
// correctly.
TF_Port ports[5] = {{
    .chip_select_pin=26,
    .spi=VSPI,
    .port_name='E'
}, {
    .chip_select_pin=25,
    .spi=VSPI,
    .port_name='D'
}, {
    .chip_select_pin=17,
    .spi=VSPI,
    .port_name='C'
}, {
    .chip_select_pin=33,
    .spi=VSPI,
    .port_name='B'
}, {
    .chip_select_pin=16,
    .spi=VSPI,
    .port_name='A'
}};

#endif // __PORTS_H__