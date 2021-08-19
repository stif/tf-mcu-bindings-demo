#ifndef __PORTS_H__
#define __PORTS_H__

#include "hal_arduino_esp32.h"

// Change this to your port assignment.
// If you use a HAT or one or more Breakout Bricklets
// you have to connect and list all chip select
// signals, to make sure the signals are separated
// correctly.
TF_Port ports[3] = {{
    .chip_select_pin=32,
    .spi=HSPI,
    .port_name='A'
}, {
    .chip_select_pin=33,
    .spi=HSPI,
    .port_name='B'
}, {
    .chip_select_pin=15,
    .spi=HSPI,
    .port_name='E'
}};

#endif // __PORTS_H__