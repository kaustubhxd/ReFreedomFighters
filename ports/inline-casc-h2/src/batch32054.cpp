#include "ff.h"

// 0x5df790: thiscall(this, arg0, arg1, arg2, arg3) ret 16 - 4-param constructor with duplicate
// Stores arg0 at [ecx+4] and [ecx+14h], args 1-3 at [ecx+8-10h], vtable at [ecx]
int* __thiscall sub_5df790(int* ecx, int arg0, int arg1, int arg2, int arg3) {
    ecx[1] = arg0;      // [ecx+4]
    ecx[2] = arg1;      // [ecx+8]
    ecx[3] = arg2;      // [ecx+0xc]
    ecx[4] = arg3;      // [ecx+0x10]
    ecx[0] = 0x6b73b0;  // [ecx] = vtable
    ecx[5] = arg0;      // [ecx+0x14] - arg0 stored again
    return ecx;
}
PCREG(5df790, sub_5df790);
