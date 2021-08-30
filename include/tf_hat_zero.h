#ifndef __TF_HAT_ZERO_H__
#define __TF_HAT_ZERO_H__

#include "hal_common.h"
#include "brick_hat_zero.h"
#include "errors.h"

#define UID_ZERO "V7o" // Change XXYYZZ to the UID of your HAT Zero Brick

extern void check(int rc, const char* msg);

//TODO: why i cannot forward declare these functions here (they need to be in main.cpp!)
//void hat_zero_setup(TF_HalContext *hal);
//void hat_zero_loop(TF_HalContext *hal);


#endif // __TF_HAT_ZERO_H__