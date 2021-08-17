#ifndef __TF_HAT_ZERO_H__
#define __TF_HAT_ZERO_H__

#include "hal_common.h"
#include "brick_hat_zero.h"

#define UID "XXYYZZ" // Change XXYYZZ to the UID of your HAT Zero Brick

//TODO: why i cannot forward declare these functions here (they need to be in main.cpp!)
//void hat_zero_setup(TF_HalContext *hal);
//void hat_zero_loop(TF_HalContext *hal);

extern void check(int rc, const char* msg);

#endif // __TF_HAT_ZERO_H__