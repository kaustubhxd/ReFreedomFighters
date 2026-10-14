#include "ff.h"

// 0x5df6f0: thiscall(this, arg0, arg1, arg2, arg3) ret 16 - 4-param constructor
// Stores 4 args at [ecx+4-10h] and vtable at [ecx]
int* __thiscall sub_5df6f0(int* ecx, int arg0, int arg1, int arg2, int arg3) {
    ecx[1] = arg0;      // [ecx+4]
    ecx[2] = arg1;      // [ecx+8]
    ecx[3] = arg2;      // [ecx+0xc]
    ecx[4] = arg3;      // [ecx+0x10]
    ecx[0] = 0x6b73d8;  // [ecx] = vtable
    return ecx;
}
PCREG(5df6f0, sub_5df6f0);
