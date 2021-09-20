#ifndef __TF_PORTS_H__
#define __TF_PORTS_H__

#include "hal_arduino_esp32.h"

// Change this to your port assignment.
// If you use a HAT or one or more Breakout Bricklets
// you have to connect and list all chip select
// signals, to make sure the signals are separated
// correctly.
TF_Port ports[4] = {{
    .chip_select_pin=32,
    .spi=HSPI,
    .port_name='A'
}, {
    .chip_select_pin=33,
    .spi=HSPI,
    .port_name='B'
}, {
    .chip_select_pin=13,
    .spi=HSPI,
    .port_name='C'
}, {
    .chip_select_pin=16,
    .spi=HSPI,
    .port_name='D'
}/*, { // only enable if Touchscreen is not used (CS Pin 5 via UEXT)
    .chip_select_pin=5,
    .spi=HSPI,
    .port_name='E'
}*/};

#endif // __TF_PORTS_H__